#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

#include "colorCloud.h"

class kickBack {

public:
    void draw(ofRectangle frame_, float time_);
    
    int countH_ = 7;
    int countV_ = 2;
    float term_ = .4;
    float delay_ = .05;
    float interval_ = 2;
    bool bRToL_ = true;
        
private:
    colorCloud myColorCloud;
};
