#pragma once

#include "ofMain.h"

#include "colorCloud.h"

class badMode {

public:
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<float> interval_ = 2;
    ofParameter<float> term_ = 2;
        
private:
    colorCloud myColorCloud;
};
