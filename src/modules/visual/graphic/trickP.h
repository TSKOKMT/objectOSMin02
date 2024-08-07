#pragma once

#include "ofMain.h"

class trickP {

public:
    ofPoint process(ofPoint point_, float time_);
    
    float stiffness = .5;
    float friction = .5;
    float mass = 1;
        
private:
    ofPoint point;
    
    bool bSetup = true;
    
    float time;
    float previousTime;
    
    ofPoint velocity;
};
