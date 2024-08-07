#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

#include "colorCloud.h"

class longDistance {

public:
    longDistance();
    void draw(ofRectangle frame_, float time_);
    void drawOne(ofPoint center_, float angle_, float width_);
    
    int count = 7;
    float interval = 1;
    float delay = .004;
    
private:
    float previousTime;
    
    vector<ofPoint> previousPositions;
    vector<ofPoint> nextPositions;
    vector<float> previousAngles;
    vector<float> nextAngles;
    vector<float> previousWidths;
    vector<float> nextWidths;
    
    colorCloud myColorCloud;
};
