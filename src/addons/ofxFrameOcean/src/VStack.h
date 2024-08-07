#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

class VStack {

public:
    static vector<ofRectangle> get(ofRectangle frame_, float height_, float spacing_ = 0, float position_ = 0);
    static vector<ofRectangle> get(ofRectangle frame_, int count_, float margin_ = 0, float position_ = 0);
    static vector<ofRectangle> get(ofRectangle frame_, vector<float> weights_, float spacing_ = 0);
    
private:
};
