#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"
#include "ofxFrameOcean.h"

#include "colorCloud.h"

class huntRabbit {

public:
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<int> numV = 5;
    ofParameter<float> interval = 2;
  
private:
    colorCloud myColorCloud;
};
