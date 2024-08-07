#pragma once

#include "ofMain.h"

#include "colorCloud.h"

class polyPoli {

public:
    void draw(ofRectangle frame_, float time_);
    
    float interval = 1;
    float radius = 75;
    int count_ = 6;
    
private:
    vector<vector<ofPoint>> get(int shift_);
    
    vector<vector<ofPoint>> lerp(vector<vector<ofPoint>> from_, vector<vector<ofPoint>> to_, float t_);
    
    //vector<ofPoint> traces;
    
    colorCloud myColorCloud;
};
