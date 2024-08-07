#include "colorCloud.h"

//--------------------------------------------------------------
colorCloud::colorCloud() {
    
    six.resize(6);
    six[0] = ofColor(255, 0, 0);
    six[1] = ofColor(255, 255, 0);
    six[2] = ofColor(0, 255, 0);
    six[3] = ofColor(0, 255, 255);
    six[4] = ofColor(0, 0, 255);
    six[5] = ofColor(255, 0, 255);
    
    mono.resize(2);
    mono[0] = ofColor(0);
    mono[1] = ofColor(255);
    
    rgb.resize(3);
    rgb[0] = ofColor(255, 0, 0);
    rgb[1] = ofColor(0, 255, 0);
    rgb[2] = ofColor(0, 0, 255);
    
    sakamoto = load("Palette/sakamoto.png");
    
    ikko = load("Palette/ikko.png");
}

//--------------------------------------------------------------
vector<ofColor> colorCloud::load(string path_) {
    
    vector<ofColor> result;
    
    ofImage image;
    if (image.load(path_)) {
        result.resize(image.getWidth());
        for (int i = 0; i < image.getWidth(); i++) {
            result[i] = image.getColor(i, 0);
        }
    }
    else {
        result = six;
    }
    
    return result;
}
