#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"
#include "ofxFrameOcean.h"

#include "colorCloud.h"

class fragMent {

public:
    fragMent();
    
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<int> count_ = 5;
    ofParameter<float> margin_ = 2;
        
    vector<ofRectangle> frames;
    vector<int> ids;
    
    bool bShuffle = true;
    
    int selectedIndex = -1;
    float beginTime;
    float term = .1;
    
private:
    ofRectangle frame;
    
    ofRectangle insideFrame(ofRectangle frame_, int side_);
    ofRectangle outsideFrame(ofRectangle frameC_, ofRectangle frameP_, int side_);
    
    float minSide;
    
    int count = 0;
    
    colorCloud myColorCloud;
};
