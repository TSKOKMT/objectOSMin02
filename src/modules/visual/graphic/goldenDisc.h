#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

#include "colorCloud.h"

class goldenDisc {

public:
    void draw(ofRectangle frame_, float time_);
    
    void drawOne(ofRectangle frame_, float time_, float interval_, float term_, float side_);
  
private:
    ofPoint previousRotation;
    ofPoint nextRotation;
    
    colorCloud myColorCloud;
};
