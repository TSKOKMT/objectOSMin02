#pragma once

#include "ofMain.h"

#include "colorCloud.h"

class darlingApp {

public:
    void draw(ofRectangle frame_, float time_);
    void align(int countH_, int countV_, float spacing_);
    
    void shuffle();
    void bigger();
    void smaller();

private:
    void drawApp(ofPoint position_, float radius_, float rotation_, int id_);
    
    int resolution = 30;
    
    vector<int> ids;
    vector<ofPoint> points;
    vector<float> terms;
    vector<float> radiuses;
    
    int countH;
    int countV;
    
    float spacing = 6;
    
    colorCloud myColorCloud;
};
