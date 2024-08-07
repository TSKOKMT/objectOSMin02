#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

class slideGrid {
    
public:
    vector<ofRectangle> get(ofRectangle frame_, float time_);
    
    float speed = -12;
    
private:
    float previousTime = 0;
    
    float position = 0;
    
    bool bFirst = true;
};
