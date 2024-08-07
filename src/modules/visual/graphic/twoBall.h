#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

#include "colorCloud.h"

class twoBall {

public:
    void draw(ofRectangle frame_, float time_);
    
    float term_ = 1;
        
private:
    colorCloud myColorCloud;
};
