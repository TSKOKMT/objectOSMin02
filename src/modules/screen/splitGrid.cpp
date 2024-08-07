#include "splitGrid.h"

//--------------------------------------------------------------
void splitGrid::begin(int term_) {
    
    if (level == 12) {
        level = 0;
        rects.clear();
    }
    
    beginTime = ofGetElapsedTimef();
    term = term_ / 1000.;
    
    bVertical = !bVertical;
    
    previousRects = rects;
    for (int i = 0; i < previousRects.size(); i++) {
        rects.push_back(rects[i]);
    }
    ratios.resize(previousRects.size());
    for (int i = 0; i < ratios.size(); i++) {
        ratios[i] = ofRandom(.2, .8);
    }
    
    level++;
}

//--------------------------------------------------------------
vector<ofRectangle> splitGrid::get(ofRectangle frame_) {
    
    if (rects.size() == 0) rects.push_back(frame_);
    
    float ratio = (ofGetElapsedTimef() - beginTime) / term;
    ratio = ofClamp(ratio, 0, 1);
    ratio = ofxTskokmtMath::cubicBezierByX(ofPoint(1, 0), ofPoint(.25, 1), ratio);
    
    for (int i = 0; i < previousRects.size(); i++) {
        if (bVertical) {
            rects[i].height = previousRects[i].height * ofMap(ratio, 0, 1, 0, ratios[i]);
            rects[i + previousRects.size()].y = previousRects[i].y + rects[i].height;
            rects[i + previousRects.size()].height = previousRects[i].height * ofMap(ratio, 0, 1, 1, 1 - ratios[i]);
        }
        else {
            rects[i].width = previousRects[i].width * ofMap(ratio, 0, 1, 0, ratios[i]);
            rects[i + previousRects.size()].x = previousRects[i].x + rects[i].width;
            rects[i + previousRects.size()].width = previousRects[i].width * ofMap(ratio, 0, 1, 1, 1 - ratios[i]);
        }
    }
 
    return rects;
}
