#pragma once

#include "ofMain.h"

#include "colorCloud.h"

class pointShoot {

public:
    void draw(ofRectangle frame_, float time_);
    void drawCircles(ofPoint a_, ofPoint b_, ofPoint c_);
    
    float term = 3;
        
private:
    colorCloud myColorCloud;
};
