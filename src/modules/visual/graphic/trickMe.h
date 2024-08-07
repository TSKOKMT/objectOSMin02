#pragma once

#include "ofMain.h"

#include "trickP.h"

#include "colorCloud.h"

class trickMe {

public:
    void draw(ofRectangle frame_, float time_);
    
    int count = 60;
    float speed = .5;
        
private:
    vector<trickP> trickPs;
    
    colorCloud myColorCloud;
};
