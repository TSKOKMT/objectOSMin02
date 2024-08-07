#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

#include "colorCloud.h"

class moonShot {

public:
    moonShot();
    
    void draw(ofRectangle frame_, float time_);
    
    int count_ = 6;
    float radius = 10;
    float term_ = 1;
    float interval_ = 3.5;
    float delay_ = .1;
    float bRToL_ = true;
    
private:
    colorCloud myColorCloud;
};
