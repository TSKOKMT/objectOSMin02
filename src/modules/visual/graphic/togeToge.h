#pragma once

#include "ofMain.h"

#include "colorCloud.h"

class togeToge {

public:
    void draw(ofRectangle frame_, float time_);
    
    void drawOne(ofRectangle frame_, float time_, int count_, bool bLeft_);
    
    int count = 13;
        
private:
    colorCloud myColorCloud;
};
