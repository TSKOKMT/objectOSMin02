#include "keepDistance.h"

//--------------------------------------------------------------
void keepDistance::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    count_ = round(ofLerp(0, 12, ofNoise(time_)));
    position_ = ofNormalize(sin(time_ * PI), -1, 1);
    
    float interval = frame_.width / count_;
    
    //DRAW
    
    ofPushStyle();
    
    for (int i = 0; i < count_; i++) {
        float ratio = ofLerp(ofNormalize(i, 0, count_ - 1), ofNormalize(i, count_ - 1, 0), position_);
        float width = frame_.width / (float)count_ * ratio;
        
        ofSetColor(myColorCloud.six[i % 6]);
        
        ofDrawRectangle(frame_.x + interval * (i + .5) - width / 2., frame_.y, width, frame_.height);
    }
    
    ofPopStyle();
}
