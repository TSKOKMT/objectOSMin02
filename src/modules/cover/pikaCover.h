#pragma once

#include "ofMain.h"

class pikaCover {

public:
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<int> term = 1;
    ofParameter<bool> bAfter = false;
    ofParameter<float> ratio = 1;
    ofParameter<ofColor> color = ofColor(255);
        
private:
};
