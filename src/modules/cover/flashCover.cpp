#include "flashCover.h"

//--------------------------------------------------------------
void flashCover::draw(ofRectangle frame_, float time_) {
    
    ofPushStyle();
    //ofSetColor(color);
    
    if ((int)floor(time_ / term) % 2) ofDrawRectangle(frame_);
    
    ofPopStyle();
}
