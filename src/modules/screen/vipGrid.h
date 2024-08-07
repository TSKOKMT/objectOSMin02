#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"
#include "ofxFrameOcean.h"

class vipGrid {
    
public:
    vector<ofRectangle> get(ofRectangle frame_, float time_);
    
    int countH = 3;
    float margin = 1;
    float speed = -12;
    
private:
};
