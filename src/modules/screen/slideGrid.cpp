#include "slideGrid.h"

//--------------------------------------------------------------
vector<ofRectangle> slideGrid::get(ofRectangle frame_, float time_) {
    
    vector<ofRectangle> frames;
    
    if (bFirst) {
        previousTime = time_;
        bFirst = false;
    }
    
    auto unit = sqrt(frame_.width * frame_.height) / 120.;
    
    position += speed * unit * (time_ - previousTime);
    
    previousTime = time_;
    
    frames = HStack::get(frame_, frame_.width, 0, position);
    
    return frames;
}
