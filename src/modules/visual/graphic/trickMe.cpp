#include "trickMe.h"

//--------------------------------------------------------------
void trickMe::draw(ofRectangle frame_, float time_) {
    
    if (trickPs.size() != count) trickPs.resize(count);
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    //UPDATE
        
    //ofPoint target = ofPoint(ofGetMouseX(), ofGetMouseY());
    ofPoint target = ofPoint(ofNoise(time_ * speed), ofNoise(time_ * speed, PI));
    target.x = ofNormalize(cos(target.x * PI), 1, -1);
    target.y = ofNormalize(cos(target.y * PI), 1, -1);
    target.x *= frame_.width;
    target.y *= frame_.height;
    
    //DRAW
    
    ofPushMatrix();
    ofTranslate(frame_.position);
    
    ofPushStyle();
    ofNoFill();
    
    //ofBeginShape();
    //ofVertex(target);
    vector<ofPoint> targetMemory;
    for (int i = 0; i < trickPs.size(); i++) {
        ofSetColor(myColorCloud.six[i % 6]);
        
        targetMemory.push_back(target);
        if (targetMemory.size() >= 20) targetMemory.erase(targetMemory.begin());
        target = trickPs[i].process(target, time_);
        //ofDrawCircle(target, unit);
        //ofVertex(target);
        ofDrawLine(targetMemory.front(), target);
    }
    //ofEndShape();
    
    ofPopStyle();
    
    ofPopMatrix();
}
