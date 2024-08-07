#include "theyMove.h"

//--------------------------------------------------------------
void theyMove::draw(ofRectangle frame_, float time_) {
    
    vector<ofRectangle> frames;
    
    if (bVertical_) frames = VStack::get(frame_, count_);
    else frames = HStack::get(frame_, count_);
    
    int index = floor(time_ / term_);
    
    ofPushStyle();
    ofSetColor(myColorCloud.six[index % 6]);
    ofDrawRectangle(frames[index % count_]);
    ofPopStyle();
}
