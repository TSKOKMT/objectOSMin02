#include "huntRabbit.h"

//--------------------------------------------------------------
void huntRabbit::draw(ofRectangle frame_, float time_) {

    //UPDATE
    
    auto framesV = VStack::get(frame_, numV);
    
    float d = 2 * interval / (float)framesV.size();
    float term = interval - d;
    
    //DRAW
    
    ofPushStyle();
    
    for (int v = 0; v < framesV.size(); v++) {
        float progresses[2];
        for (int i = 0; i < 2; i++) {
            float delay = (i + v) * d;
            float theTime = time_ - delay;
            
            float progress = ofClamp(ofWrap(theTime, 0, interval) / term, 0, 1);
            progress = ofxTskokmtMath::cubicBezierByX(ofPoint(1, 0), ofPoint(0, 1), progress);
            if ((int)abs(floor(theTime / interval)) % 2 == 1) progress = 1 - progress;
            
            progresses[i] = progress;
        }
        
        ofPushMatrix();
        ofTranslate(framesV[v].position);
        ofScale(framesV[v].width, framesV[v].height);
        
        ofSetColor(myColorCloud.six[v % 6]);
        
        ofDrawRectangle(progresses[1], 0, progresses[0] - progresses[1], 1);
        
        ofPopMatrix();
    }
    
    ofPopStyle();
}
