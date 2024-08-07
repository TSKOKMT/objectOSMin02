#include "fragScreen.h"

//--------------------------------------------------------------
vector<ofRectangle> fragScreen::get(ofRectangle frame_, float time_) {
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float margin = margin_ * unit;
    
    ofRectangle frameM = marginBand::get(frame_, margin);
    
    //Regenerate
    if (count_ != (int)frames.size()) {
        frames.resize(count_);
        ids.resize(count_);
        for (int i = 0; i < count_; i++) {
            int id;
            
            bool bOk;
            int loopCount = 0;
            int maxLoopCount = 10000;
            do {
                if (i == 0) {
                    id = ofRandom(4);
                    frames[i] = insideFrame(frameM, id, 3 * margin);
                }
                else {
                    int targetIndex = (int)ofRandom(i);
                    //int targetIndex = i - 1;
                    do {
                        id = ofRandom(4);
                    } while (abs(id - ids[targetIndex]) == 2);
                    ofRectangle frameC = marginBand::get(frames[targetIndex], -margin);
                    frames[i] = outsideFrame(frameC, frameM, id, 3 * margin);
                }
                
                bOk = true;
                if (frames[i].width < 0 || frames[i].height < 0) bOk = false;
                for (int j = 0; j < i; j++) {
                    auto frameJ = marginBand::get(frames[j], -margin * .99);
                    if (ofxTskokmtMath::isOverlapRectangles(frames[i], frameJ)) bOk = false;
                }
                
                loopCount++;
            } while (!bOk && loopCount < maxLoopCount);
            
            cout << i << " : " << loopCount << endl;
            
            ids[i] = id;
        }
    }
    
    return frames;
}

//--------------------------------------------------------------
ofRectangle fragScreen::insideFrame(ofRectangle frame_, int side_, float min_) {
    
    ofRectangle theFrame;
    //From Right
    if (side_ == 0) {
        float theY = ofRandom(frame_.getTop(), frame_.getBottom());
        float theWidth = ofRandom(min_, frame_.width);
        theFrame = ofRectangle(frame_.getRight() - theWidth, theY, theWidth, ofRandom(min_, frame_.getBottom() - theY));
    }
    //From Bottom
    else if (side_ == 1) {
        float theX = ofRandom(frame_.getLeft(), frame_.getRight());
        float theHeight = ofRandom(min_, frame_.height);
        theFrame = ofRectangle(theX, frame_.getBottom() - theHeight, ofRandom(min_, frame_.getRight() - theX), theHeight);
    }
    //From Left
    else if (side_ == 2) {
        float theY = ofRandom(frame_.getTop(), frame_.getBottom());
        theFrame = ofRectangle(frame_.getLeft(), theY, ofRandom(min_, frame_.width), ofRandom(min_, frame_.getBottom() - theY));
    }
    //From Top
    else {
        float theX = ofRandom(frame_.getLeft(), frame_.getRight());
        theFrame = ofRectangle(theX, frame_.getTop(), ofRandom(min_, frame_.getRight() - theX), ofRandom(min_, frame_.height));
    }
    return theFrame;
}

//--------------------------------------------------------------
ofRectangle fragScreen::outsideFrame(ofRectangle frameC_, ofRectangle frameP_, int side_, float min_) {
    
    ofRectangle theFrame;
    //From Right
    if (side_ == 0) {
        float theHeight = ofRandom(min_, frameP_.height);
        float theY = ofLerp(max(frameP_.getTop(), frameC_.getTop() - theHeight), min(frameP_.getBottom() - theHeight, frameC_.getBottom()), ofRandom(1));
        float theWidth = ofRandom(min_, frameC_.getLeft() - frameP_.getLeft());
        if (frameC_.getLeft() - frameP_.getLeft() < min_) theWidth = -1;
        theFrame = ofRectangle(frameC_.getLeft() - theWidth, theY, theWidth, theHeight);
    }
    //From Bottom
    else if (side_ == 1) {
        float theWidth = ofRandom(min_, frameP_.width);
        float theX = ofLerp(max(frameP_.getLeft(), frameC_.getLeft() - theWidth), min(frameP_.getRight() - theWidth, frameC_.getRight()), ofRandom(1));
        float theHeight = ofRandom(min_, frameC_.getTop() - frameP_.getTop());
        if (frameC_.getTop() - frameP_.getTop() < min_) theHeight = -1;
        theFrame = ofRectangle(theX, frameC_.getTop() - theHeight, theWidth, theHeight);
    }
    //From Left
    else if (side_ == 2) {
        float theHeight = ofRandom(min_, frameP_.height);
        float theY = ofLerp(max(frameP_.getTop(), frameC_.getTop() - theHeight), min(frameP_.getBottom() - theHeight, frameC_.getBottom()), ofRandom(1));
        float theWidth = ofRandom(min_, frameP_.getRight() - frameC_.getRight());
        if (frameP_.getRight() - frameC_.getRight() < min_) theWidth = -1;
        theFrame = ofRectangle(frameC_.getRight(), theY, theWidth, theHeight);
    }
    //From Top
    else {
        float theWidth = ofRandom(min_, frameP_.width);
        float theX = ofLerp(max(frameP_.getLeft(), frameC_.getLeft() - theWidth), min(frameP_.getRight() - theWidth, frameC_.getRight()), ofRandom(1));
        float theHeight = ofRandom(min_, frameP_.getBottom() - frameC_.getBottom());
        if (frameP_.getBottom() - frameC_.getBottom() < min_) theHeight = -1;
        theFrame = ofRectangle(theX, frameC_.getBottom(), theWidth, theHeight);
    }
    return theFrame;
}
