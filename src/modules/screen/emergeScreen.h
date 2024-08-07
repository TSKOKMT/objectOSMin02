#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

class emergeScreen {
    
public:
    vector<ofRectangle> get(ofRectangle frame_, float time_);
    
    ofParameter<int> count_ = 4;
    ofParameter<float> margin_ = 1;
    ofParameter<float> term_ = 12;
    ofParameter<float> delay_ = PI;
    ofParameter<float> strength_ = .9;
    ofParameter<float> motionStrength_ = .9;
    
private:
};
