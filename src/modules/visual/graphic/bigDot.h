#pragma once

#include "ofMain.h"

#include "ofxBox2d.h"
#include "ofxTskokmtMath.h"

#include "colorCloud.h"

class bigDot {

public:
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<int> num_ = 10;
    ofParameter<float> radius = 12;
    ofParameter<float> hour_ = 12;
    ofParameter<float> intensity_ = 4;
    ofParameter<float> mode_ = 0;
        
private:
    ofRectangle previousFrame;
    float previousRadius;
    
    ofxBox2d box2d;
    vector<ofPtr<ofxBox2dCircle>> circles;
    
    int previousFrameNum = 0;
    
    colorCloud myColorCloud;
};
