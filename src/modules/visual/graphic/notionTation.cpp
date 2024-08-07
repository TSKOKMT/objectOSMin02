#include "notionTation.h"

//--------------------------------------------------------------
void notionTation::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    previousPositions.resize(count_);
    nextPositions.resize(count_);
    
    float previousTime = floor(time_ / interval_) * interval_;
    float nextTime = ceil(time_ / interval_) * interval_;
    
    for (int i = 0; i < nextPositions.size(); i++) {
        previousPositions[i] = floor(ofWrap(pow(previousTime + i / (float)nextPositions.size() * 100, PI), 0, 9)) / 8.;
        nextPositions[i] = floor(ofWrap(pow(nextTime + i / (float)nextPositions.size() * 100, PI), 0, 9)) / 8.;
    }
    
    float motion = ofClamp(ofWrap(time_, 0, interval_) / term_, 0, 1);
    
    vector<float> positions = ofxTskokmtMath::lerp(previousPositions, nextPositions, motion);
    
    //DRAW
    
    ofPushStyle();
    
    if (bVertical_) {
        auto framesV = HStack::get(frame_, count_);
        
        for (int i = 0; i < count_; i++) {
            auto frameV = framesV[i];
            float side = frameV.width;
            
            ofSetColor(myColorCloud.six[i % 6]);
            
            ofDrawRectangle(frameV.x, ofLerp(frameV.getTop(), frameV.getBottom() - side, positions[i]), side, side);
        }
        
        if (bDrawLine_) {
            ofSetColor(255);
            
            float interval = frame_.width / count_;
            for (int i = 0; i < count_ + 1; i++) {
                ofDrawLine(frame_.x + interval * i, frame_.getTop(), frame_.x + interval * i, frame_.getBottom());
            }
        }
    }
    else {
        auto framesH = VStack::get(frame_, count_);
        
        for (int i = 0; i < count_; i++) {
            auto frameH = framesH[i];
            float side = frameH.height;
            
            ofSetColor(myColorCloud.six[i % 6]);
            
            ofDrawRectangle(ofLerp(frameH.getLeft(), frameH.getRight() - side, positions[i]), frameH.y, side, side);
        }
        
        if (bDrawLine_) {
            ofSetColor(255);
            
            float interval = frame_.height / count_;
            for (int i = 0; i < count_ + 1; i++) {
                ofDrawLine(frame_.getLeft(), frame_.y + interval * i, frame_.getRight(), frame_.y + interval * i);
            }
        }
    }
    
    ofPopStyle();
    
    previousTime = time_;
}
