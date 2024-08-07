#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

#include "colorCloud.h"

class nuWit {

public:
    void draw(ofRectangle frame_, float time_);
    void drawOne(ofPoint pointFrom_, ofPoint pointTo_, float time_);
    
    int count = 9;
    float interval_ = 1;
    float term_;
    float stroke = 10;
        
private:
    float unit;
    
    float previousTime;
    
    vector<ofPoint> pointsFrom;
    vector<ofPoint> pointsTo;
    
    colorCloud myColorCloud;
};
