#include "zoomZoom.h"

//--------------------------------------------------------------
void zoomZoom::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    previousTime = time;
    time = time_;
    
    if (frames.empty()) {
        frames.push_back(ofRectangle(-frame_.width / 2., -frame_.height / 2., frame_.width, frame_.height));
        indexes.push_back(0);
    }
    
    float maxSide = maxSide_ * unit;
    
    if (previousFrameNum != ofGetFrameNum()) {
        previousFrameNum = ofGetFrameNum();
    }
    
    //Scale
    float scale = pow(zoomSpeed, time - previousTime);
    for (int i = 0; i < frames.size(); i++) {
        frames[i].x *= scale;
        frames[i].y *= scale;
        frames[i].width *= scale;
        frames[i].height *= scale;
    }
    
    //Add
    int centerIndex = 0;
    for (int i = 0; i < frames.size(); i++) {
        if (frames[i].inside(ofPoint(0, 0))) centerIndex = i;
    }
    if (sqrt(frames[centerIndex].getArea()) > maxSide) {
        auto newFrames = devide(frames[centerIndex]);
        frames.erase(frames.begin() + centerIndex);
        indexes.erase(indexes.begin() + centerIndex);
        for (int i = 0; i < newFrames.size(); i++) {
            frames.push_back(newFrames[i]);
            indexes.push_back(indexes.back() + 1);
        }
    }
    
    //Erase
    int i = 0;
    while (i < frames.size()) {
        if (!ofxTskokmtMath::isOverlapRectangles(ofRectangle(-frame_.width / 2., -frame_.height / 2., frame_.width, frame_.height), frames[i])) {
            frames.erase(frames.begin() + i);
            indexes.erase(indexes.begin() + i);
        }
        else {
            i++;
        }
    }
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    ofPushMatrix();
    ofTranslate(frame_.getCenter());
    
    ofPushStyle();
    
    for (int i = 0; i < frames.size(); i++) {
        int theIndex = indexes[i];
        
        ofSetColor(myColorCloud.six[theIndex % (int)myColorCloud.six.size()]);
        
        if (theIndex % 3 == 0) ofDrawRectangle(frames[i]);
        else if (theIndex % 3 == 1) ofDrawCircle(frames[i].getCenter(), min(frames[i].width, frames[i].height) / 2.);
        else {
            /*if ((int)(i / 3) % 4 == 0) ofDrawTriangle(frames[i].getBottomLeft(), frames[i].getBottomRight(), ofPoint(frames[i].getCenter().x, frames[i].getTop()));*/
            /*else if ((int)(i / 3) % 4 == 1)*/ ofDrawTriangle(frames[i].getTopLeft(), frames[i].getTopRight(), ofPoint(frames[i].getCenter().x, frames[i].getBottom()));
            /*else if ((int)(i / 3) % 4 == 2) ofvDrawTriangle(ofPoint(frames[i].getLeft(), frames[i].getCenter().y), frames[i].getTopRight(), frames[i].getBottomRight());
            else ofDrawTriangle(ofPoint(frames[i].getRight(), frames[i].getCenter().y), frames[i].getTopLeft(), frames[i].getBottomLeft());*/
        }
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
}

//--------------------------------------------------------------
vector<ofRectangle> zoomZoom::devide(ofRectangle frame_) {
    
    int devideCount = 3;
    
    vector<float> weights;
    for (int i = 0; i < devideCount; i++) weights.push_back(ofRandom(1, 10));
    
    if (frame_.width > frame_.height) return HStack::get(frame_, weights);
    else return VStack::get(frame_, weights);
}
