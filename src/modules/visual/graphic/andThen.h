#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

#include "colorCloud.h"

class andThen {

public:
    andThen();
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<int> side = 8;
    ofParameter<float> term = 1;
        
private:
    vector<ofPolyline> shapes;
    int shapeIndex;
    
    colorCloud myColorCloud;
};
