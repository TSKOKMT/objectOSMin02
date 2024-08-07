#include "pikaCover.h"

//--------------------------------------------------------------
void pikaCover::draw(ofRectangle frame_, float time_) {
    
    float alpha = (1 - ofClamp(ofWrap(time_ / term - (bAfter ? .5 : 0), 0, 1) / ratio, 0, 1)) * 255;
    
    ofPushStyle();
    ofSetColor(color, alpha);
    
    ofDrawRectangle(frame_);
    
    ofPopStyle();
}
