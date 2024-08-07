#pragma once

#include "ofMain.h"

#include "ofxTskokmtTranslator.h"

class videoPlayer {

public:
    videoPlayer();
    
    void load(string path_);
    
    void draw(ofRectangle frame_, float time_);
    
    float speed = 1;
        
private:
    string path;
    
    ofVideoPlayer video;
    
    ofxTskokmtTranslator translator;
};
