#pragma once

#include "ofMain.h"

class flashCover {

public:
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<ofColor> color = ofColor(255);
    ofParameter<float> term = .1;
        
private:
};
