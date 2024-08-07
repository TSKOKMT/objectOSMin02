#include "togeToge.h"

//--------------------------------------------------------------
void togeToge::draw(ofRectangle frame_, float time_) {
    
    ofPushMatrix();
    ofTranslate(frame_.position);
    
    drawOne(ofRectangle(0, 0, frame_.width / 2., frame_.height), time_, count, true);
    drawOne(ofRectangle(frame_.width / 2., 0, frame_.width / 2., frame_.height), time_, count, false);
    
    ofPopMatrix();
}
 
//--------------------------------------------------------------
void togeToge::drawOne(ofRectangle frame_, float time_, int count_, bool bLeft_) {
    
    float speed = 3;
    
    ofPushMatrix();
    ofTranslate(frame_.position);
    ofScale(frame_.width, frame_.height);
    
    ofPushStyle();
    
    for (int i = 0; i < count_; i++) {
        float theMotion = ofNoise(time_ * speed, PI + i * 100 * PI);
        theMotion = ofNormalize(theMotion, .25, .75);
        
        ofPushMatrix();
        if (bLeft_) ofTranslate(1, 0);
        ofScale(theMotion, 1);
        if (bLeft_) ofTranslate(-1, 0);
        
        ofSetColor(myColorCloud.six[i % 6]);
        
        ofBeginShape();
        if (bLeft_) {
            ofVertex(1, 1 / (float)count_ * i);
            ofVertex(0, 1 / (float)count_ * (i + .5));
            ofVertex(1, 1 / (float)count_ * (i + 1));
        }
        else {
            ofVertex(0, 1 / (float)count_ * i);
            ofVertex(1, 1 / (float)count_ * (i + .5));
            ofVertex(0, 1 / (float)count_ * (i + 1));
        }
        ofEndShape(true);
        
        ofPopMatrix();
    }
    
    ofPopStyle();
    
    ofPopMatrix();
}
