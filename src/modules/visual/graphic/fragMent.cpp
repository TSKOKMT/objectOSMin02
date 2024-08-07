#include "fragMent.h"

//--------------------------------------------------------------
fragMent::fragMent() {
    
}

//--------------------------------------------------------------
void fragMent::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    if (frame_ != frame) {
        frame = frame_;
        bShuffle = true;
    }
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float margin = margin_ * unit;
    
    minSide = margin * 3;
    
    ofRectangle frameM = marginBand::get(frame_, margin);
    if (frameM.width <= 0 || frameM.height <= 0) return;
    
    int id;
    int previousId;
    
    if (count != count_ || bShuffle) {
        frames.resize(count_);
        ids.resize(count_);
        for (int i = 0; i < count_; i++) {
            bool bOk;
            int loopCount = 0;
            int maxLoopCount = 10000;
            do {
                if (i == 0) {
                    id = ofRandom(4);
                    frames[i] = insideFrame(frameM, id);
                }
                else {
                    int targetIndex = (int)ofRandom(i);
                    //int targetIndex = i - 1;
                    do {
                        id = ofRandom(4);
                    } while (abs(id - ids[targetIndex]) == 2);
                    ofRectangle frameC = marginBand::get(frames[targetIndex], -margin);
                    frames[i] = outsideFrame(frameC, frameM, id);
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
            
            previousId = id;
            ids[i] = id;
        }
        
        count = count_;
        
        bShuffle = false;
    }
    
    /*
    for (int i = 0; i < count_; i++) {
        bool bOk;
        int loopCount = 0;
        int maxLoopCount = 10000;
        do {
            //float theWidth = ofRandom(4, 60) * unit;
            //float theHeight = ofRandom(4, 60) * unit;
            float theWidth = 9 * unit;
            float theHeight = 16 * unit;
            float theX = ofLerp(frame_.getLeft(), frame_.getRight() - theWidth, ofRandom(1));
            float theY = ofLerp(frame_.getTop(), frame_.getBottom() - theHeight, ofRandom(1));
            frames[i] = ofRectangle(theX, theY, theWidth, theHeight);
            bOk = true;
            for (int j = 0; j < i; j++) {
                if (ofxTskokmtMath::isOverlapRectangles(frames[i], frames[j])) bOk = false;
            }
            loopCount++;
            if (loopCount >= maxLoopCount) break;
        } while (!bOk);
    }
    */
    
    //DRAW
    
    ofPushStyle();
    
    //ofNoFill();
    for (int i = 0; i < frames.size(); i++) {
        ofColor color;
        color.setHsb(i / (float)frames.size() * 256, 255, 255);
        //ofSetColor(color);
        
        //ofDrawRectangle(frames[i]);
        //ofDrawEllipse(frames[i].getCenter(), frames[i].width, frames[i].height);
        
        //auto nextFrame = frames[(i + 1) % (int)frames.size()];
        
        /*auto frameI = marginBand::get(frames[i], margin);
        ofBeginShape();
        ofVertex(frames[i].getTopLeft());
        ofVertex(frames[i].getTopRight());
        ofVertex(frames[i].getBottomRight());
        ofVertex(frames[i].getBottomLeft());
        ofNextContour(true);
        ofVertex(frameI.getTopLeft());
        ofVertex(frameI.getTopRight());
        ofVertex(frameI.getBottomRight());
        ofVertex(frameI.getBottomLeft());
        ofEndShape(true);*/
        
        if (selectedIndex >= 0) {
            if (selectedIndex != i/* || time_ - beginTime > term*/) continue;
        }
        
        ofSetColor(myColorCloud.six[i % 6]);
        
        ofDrawRectangle(frames[i]);
        
        //ofDrawBitmapString(ofToString(ids[i]), frames[i].x + 8, frames[i].y + 16);
    }
    
    ofPopStyle();
}

//--------------------------------------------------------------
ofRectangle fragMent::insideFrame(ofRectangle frame_, int side_) {
    
    ofRectangle theFrame;
    //From Right
    if (side_ == 0) {
        float theY = ofRandom(frame_.getTop(), frame_.getBottom());
        float theWidth = ofRandom(minSide, frame_.width);
        theFrame = ofRectangle(frame_.getRight() - theWidth, theY, theWidth, ofRandom(minSide, frame_.getBottom() - theY));
    }
    //From Bottom
    else if (side_ == 1) {
        float theX = ofRandom(frame_.getLeft(), frame_.getRight());
        float theHeight = ofRandom(minSide, frame_.height);
        theFrame = ofRectangle(theX, frame_.getBottom() - theHeight, ofRandom(minSide, frame_.getRight() - theX), theHeight);
    }
    //From Left
    else if (side_ == 2) {
        float theY = ofRandom(frame_.getTop(), frame_.getBottom());
        theFrame = ofRectangle(frame_.getLeft(), theY, ofRandom(minSide, frame_.width), ofRandom(minSide, frame_.getBottom() - theY));
    }
    //From Top
    else {
        float theX = ofRandom(frame_.getLeft(), frame_.getRight());
        theFrame = ofRectangle(theX, frame_.getTop(), ofRandom(minSide, frame_.getRight() - theX), ofRandom(minSide, frame_.height));
    }
    return theFrame;
}

//--------------------------------------------------------------
ofRectangle fragMent::outsideFrame(ofRectangle frameC_, ofRectangle frameP_, int side_) {
    
    ofRectangle theFrame;
    //From Right
    if (side_ == 0) {
        float theHeight = ofRandom(minSide, frameP_.height);
        float theY = ofLerp(max(frameP_.getTop(), frameC_.getTop() - theHeight), min(frameP_.getBottom() - theHeight, frameC_.getBottom()), ofRandom(1));
        float theWidth = ofRandom(minSide, frameC_.getLeft() - frameP_.getLeft());
        if (frameC_.getLeft() - frameP_.getLeft() < minSide) theWidth = -1;
        theFrame = ofRectangle(frameC_.getLeft() - theWidth, theY, theWidth, theHeight);
    }
    //From Bottom
    else if (side_ == 1) {
        float theWidth = ofRandom(minSide, frameP_.width);
        float theX = ofLerp(max(frameP_.getLeft(), frameC_.getLeft() - theWidth), min(frameP_.getRight() - theWidth, frameC_.getRight()), ofRandom(1));
        float theHeight = ofRandom(minSide, frameC_.getTop() - frameP_.getTop());
        if (frameC_.getTop() - frameP_.getTop() < minSide) theHeight = -1;
        theFrame = ofRectangle(theX, frameC_.getTop() - theHeight, theWidth, theHeight);
    }
    //From Left
    else if (side_ == 2) {
        float theHeight = ofRandom(minSide, frameP_.height);
        float theY = ofLerp(max(frameP_.getTop(), frameC_.getTop() - theHeight), min(frameP_.getBottom() - theHeight, frameC_.getBottom()), ofRandom(1));
        float theWidth = ofRandom(minSide, frameP_.getRight() - frameC_.getRight());
        if (frameP_.getRight() - frameC_.getRight() < minSide) theWidth = -1;
        theFrame = ofRectangle(frameC_.getRight(), theY, theWidth, theHeight);
    }
    //From Top
    else {
        float theWidth = ofRandom(minSide, frameP_.width);
        float theX = ofLerp(max(frameP_.getLeft(), frameC_.getLeft() - theWidth), min(frameP_.getRight() - theWidth, frameC_.getRight()), ofRandom(1));
        float theHeight = ofRandom(minSide, frameP_.getBottom() - frameC_.getBottom());
        if (frameP_.getBottom() - frameC_.getBottom() < minSide) theHeight = -1;
        theFrame = ofRectangle(theX, frameC_.getBottom(), theWidth, theHeight);
    }
    return theFrame;
}
