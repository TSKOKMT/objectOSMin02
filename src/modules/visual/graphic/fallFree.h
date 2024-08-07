#pragma once

#include "ofMain.h"

#include "ofxBox2d.h"

#include "colorCloud.h"

class fallFree {

public:
    fallFree();
    
    void draw(ofRectangle frame_, float time_);
    
    void change();
      
private:
    ofRectangle frame;
    
    float previousTime;
    
    ofxBox2d box2d;
    vector<ofPtr<ofxBox2dCircle>> circles;
    vector<ofPtr<ofxBox2dRect>> rects;
    
    ofPoint translate;
    
    float scale;
    float trueScale;
    
    int colorMode = 0;
    
    int previousFrameNum = 0;
    
    int countMultiples(float a, float b, float multiple) {
        if (a > b) swap(a, b);

        int startMultiple = ceil(a / multiple);
        float startValue = startMultiple * multiple;

        int endMultiple = floor(b / multiple);
        float endValue = endMultiple * multiple;

        if (startValue > b || endValue < a) return 0;
        else return endMultiple - startMultiple + 1;
    }
    
    colorCloud myColorCloud;
};
