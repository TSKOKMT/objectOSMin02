#pragma once

#include "ofMain.h"

class colorCloud {

public:
    colorCloud();
    
    vector<ofColor> six;
    vector<ofColor> mono;
    vector<ofColor> rgb;
    vector<ofColor> sakamoto;
    vector<ofColor> ikko;
        
private:
    vector<ofColor> load(string path_);
};
