#pragma once

#include "ofMain.h"

#include "colorCloud.h"

class icoIcon {

public:
    icoIcon();
    void draw(ofRectangle frame_, float time_);
    
    float side = 45;
    float term = 12;
        
private:
    colorCloud myColorCloud;
    int colorOffset = 0;
    
    int previousFrameNum;
};
