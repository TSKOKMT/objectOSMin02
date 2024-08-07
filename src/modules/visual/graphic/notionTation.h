#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

#include "colorCloud.h"

class notionTation {

public:
    void draw(ofRectangle frame_, float time_);
    
    int count_ = 12;
    bool bVertical_ = true;
    float interval_ = 1;
    float term_ = .1;
    int bDrawLine_ = true;
        
private:
    float previousTime;
    
    vector<float> previousPositions;
    vector<float> nextPositions;
    
    colorCloud myColorCloud;
};
