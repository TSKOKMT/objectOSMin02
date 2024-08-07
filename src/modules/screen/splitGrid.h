#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

class splitGrid {
    
public:
    void begin(int term_);
    vector<ofRectangle> get(ofRectangle frame_);
    
private:
    float margin;
    int level = 0;
    float ratio;
    vector<float> ratios;
    bool bVertical;
    vector<ofRectangle> previousRects;
    vector<ofRectangle> rects;
    vector<float> generateRatios(int size_);
    
    float beginTime;
    float term;
};
