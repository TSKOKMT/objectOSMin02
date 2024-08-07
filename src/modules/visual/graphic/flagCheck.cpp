#include "flagCheck.h"

//--------------------------------------------------------------
void flagCheck::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float side = side_ * unit;
    
    int countH_ = round(frame_.width / side);
    int countV_ = round(frame_.height / side);
    
    bool bPositive_ = (int)(time_ / interval_) % 2;
    
    float width = frame_.width / countH_;
    float height = frame_.height / countV_;
    
    //DRAW
    
    ofPushStyle();
    
    ofSetColor(myColorCloud.six[0]);
    
    for (int v = 0; v < countV_; v++) {
        for (int h = 0; h < countH_; h++) {
            if ((v + h) % 2 != bPositive_) ofDrawRectangle(frame_.x + h * width, frame_.y + v * height, width, height);
        }
    }
    
    ofPopStyle();
}
