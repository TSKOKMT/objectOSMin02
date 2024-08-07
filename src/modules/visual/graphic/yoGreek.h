#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

#include "colorCloud.h"

class yoGreek {

public:
    yoGreek();
    
    void draw(ofRectangle frame_, float time_);
    
    void createCircle();
    void createSquare();
    void createTriangle();
    void vanish();
        
private:
    float time;
    
    float circleBeginTime = FLT_MAX;
    float squareBeginTime = FLT_MAX;
    float triangleBeginTime = FLT_MAX;
    float vanishedTime = FLT_MAX;
    
    vector<ofPoint> positions;
    vector<float> rotations0;
    vector<float> rotations1;
    
    colorCloud myColorCloud;
};
