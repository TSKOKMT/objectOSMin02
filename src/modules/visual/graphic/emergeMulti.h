#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

#include "colorCloud.h"

class emergeMulti {

public:
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<int> count_ = 11;
    ofParameter<float> margin_ = 1;
    ofParameter<float> term_ = 2;
    ofParameter<float> delay_ = PI;
    ofParameter<float> strength_ = .9;
    ofParameter<float> motionStrength_ = .9;
    
    float grandBeginTime = 0;
    float grandEndTime = 0;
    float grandTerm = .25;
    
    int drawMode = 0;
        
private:
    vector<ofRectangle> generateGrids(ofRectangle frame_, float time_, int count_, float margin_, float term_, float delay_, float strength_, float motionStrength_);
    
    colorCloud myColorCloud;
};
