#pragma once

#include "ofMain.h"

#include "ofxBox2d.h"

#include "colorCloud.h"

class bigThree {

public:
    void draw(ofRectangle frame_, float time_);
    
    void create(float side_);
        
private:
    ofRectangle frame;
    
    float unit;
    
    bool bSetup = true;
    
    ofxBox2d box2d;
    
    vector<ofPtr<ofxBox2dCircle>> circles;
    vector<ofPtr<ofxBox2dRect>> squares;
    vector<ofPtr<ofxBox2dPolygon>> triangles;
    
    int previousFrameNum = 0;
    
    colorCloud myColorCloud;
};
