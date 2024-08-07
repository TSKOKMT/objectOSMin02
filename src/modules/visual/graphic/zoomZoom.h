#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

#include "colorCloud.h"

class zoomZoom {

public:
    void draw(ofRectangle frame_, float time_);
    
    float zoomSpeed = 3;
    float maxSide_ = 2;
        
private:
    float time;
    float previousTime;
    
    vector<ofRectangle> frames;
    vector<int> indexes;
    
    vector<ofRectangle> devide(ofRectangle frame_);
    
    bool b = false;
    
    int previousFrameNum = 0;
    
    colorCloud myColorCloud;
};
