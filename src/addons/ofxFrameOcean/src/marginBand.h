#pragma once

#include "ofMain.h"

class marginBand {

public:
    static ofRectangle get(ofRectangle frame_, ofPoint margin_);
    static ofRectangle get(ofRectangle frame_, float margin_);
    
private:
};
