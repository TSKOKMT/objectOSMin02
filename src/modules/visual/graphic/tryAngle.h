#pragma once

#include "ofMain.h"

#include "moonModule.h"

#include "colorCloud.h"

class tryAngle {

public:
    void draw(ofRectangle frame_, float time_);
    
private:
    void drawTape(ofPoint a_, ofPoint b_, ofPoint c_, float weight_);
    ofPoint getCenter(ofPoint a_, ofPoint b_, ofPoint c_);
    
    colorCloud myColorCloud;
};
