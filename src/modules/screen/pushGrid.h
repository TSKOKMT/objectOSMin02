#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

class pushGrid {
    
public:
    vector<ofRectangle> get(ofRectangle frame_, float time_);
    
    int countH = 4;
    int countV = 4;
    float term = 4;
    float margin_ = .25;
    
private:
    
    vector<float> generateRatios(int size_, float seed_);
    
    vector<float> lerp(vector<float> from_, vector<float> to_, float t_);
};
