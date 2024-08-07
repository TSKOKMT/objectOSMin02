#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

class fragScreen {
    
public:
    vector<ofRectangle> get(ofRectangle frame_, float time_);
    
    ofParameter<int> count_ = 5;
    ofParameter<float> margin_ = 2;
    
private:
    vector<ofRectangle> frames;
    vector<int> ids;
    
    ofRectangle insideFrame(ofRectangle frame_, int side_, float min_);
    ofRectangle outsideFrame(ofRectangle frameC_, ofRectangle frameP_, int side_, float min_);
};
