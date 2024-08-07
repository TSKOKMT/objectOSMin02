#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

#include "colorCloud.h"

class reCenter {

public:
    void draw(ofRectangle frame_, float time_);
    
    int count_ = 5;
    float radius = 10;
    float term_ = 1;
    float interval_ = 3.5;
    float delay_ = .15;
    float bRToL_ = true;
    
    //int seed = 1;
    
private:
    void drawApp(ofPoint position_, float radius_, float rotation_, int id_);
    
    colorCloud myColorCloud;
};
