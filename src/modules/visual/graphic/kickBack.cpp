#include "kickBack.h"

//--------------------------------------------------------------
void kickBack::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    auto framesH = HStack::get(frame_, countH_);
    
    //DRAW
    
    ofPushStyle();
    
    int i = 0;
    
    for (int h = 0; h < framesH.size(); h++) {
        auto theFrameH = framesH[h];
        
        float theTime = time_ - (delay_ * h) * (bRToL_ ? -1 : 1);
        
        theTime = ofWrap(theTime, 0, interval_);
        if (theTime >= term_ * 2) continue;
        
        float theMotion = ofWrap(theTime / term_, 0, 1);
        if (ofWrap(theTime / term_, 0, 2) < 1) theMotion = 1 - theMotion;
        theMotion = ofxTskokmtMath::cubicBezierByX(ofPoint(1, 0), ofPoint(1, 0), theMotion);
        
        float theHeight = theFrameH.height / countV_;
        float y = theFrameH.getTop() - theMotion * theFrameH.height;
        int v = 0;
        while (y < theFrameH.getBottom()) {
            if (h % 2 == v % 2) {
                ofRectangle theRect = ofRectangle(theFrameH.x, y, theFrameH.width, theHeight);
                theRect = ofxTskokmtMath::cropped(theRect, theFrameH);
                
                ofSetColor(myColorCloud.six[i % 6]);
                
                ofDrawRectangle(theRect);
                
                i++;
            }
            y += theHeight;
            v++;
        }
    }
    
    ofPopStyle();
}
