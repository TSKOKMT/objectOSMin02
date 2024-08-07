#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

#include "colorCloud.h"

class shiftCycle {

public:
    void draw(ofRectangle frame_, float time_);
    
    int count_ = 8;
    float margin = 2;
    float interval_ = 1;
    float term_ = .666;
        
private:
    float time = .1;
    float previousTime;
    
    vector<float> previousRatios;
    vector<float> nextRatios;
    
    colorCloud myColorCloud;
};
