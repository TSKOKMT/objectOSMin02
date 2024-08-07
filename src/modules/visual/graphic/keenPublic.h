#pragma once

#include "ofMain.h"

#include "colorCloud.h"

class keenPublic {

public:
    void draw(ofRectangle frame_, float time_);
    
    int count_ = 7;
    float rotation_ = 0;
    float radius = 30;
    float length = 45;
    float weight = 4;
    float clock_ = 0;
    
private:
    colorCloud myColorCloud;
    int colorOffset = 0;
    
    int previousFrameNum;
};
