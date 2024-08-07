#include "pointShoot.h"

//--------------------------------------------------------------
void pointShoot::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    ofPoint a = ofPoint(ofNoise(time_ / term), ofNoise(time_ / term, PI));
    ofPoint b = ofPoint(ofNoise(time_ / term, 2 * PI), ofNoise(time_ / term, 3 * PI));
    ofPoint c = ofPoint(ofNoise(time_ / term, 4 * PI), ofNoise(time_ / term, 5 * PI));
    
    a.x = ofLerp(frame_.getLeft(), frame_.getRight(), a.x);
    a.y = ofLerp(frame_.getTop(), frame_.getBottom(), a.y);
    b.x = ofLerp(frame_.getLeft(), frame_.getRight(), b.x);
    b.y = ofLerp(frame_.getTop(), frame_.getBottom(), b.y);
    c.x = ofLerp(frame_.getLeft(), frame_.getRight(), c.x);
    c.y = ofLerp(frame_.getTop(), frame_.getBottom(), c.y);
    
    //DRAW
    
    ofPushStyle();
    
    drawCircles(a, b, c);
    
    ofPopStyle();
}

//--------------------------------------------------------------
void pointShoot::drawCircles(ofPoint a_, ofPoint b_, ofPoint c_) {
    
    float A = b_.distance(c_);
    float B = c_.distance(a_);
    float C = a_.distance(b_);
    
    float radiusA = (-A + B + C) / 2.;
    float radiusB = C - radiusA;
    float radiusC = B - radiusA;
    
    ofSetColor(myColorCloud.six[0]);
    ofDrawCircle(a_, radiusA);
    ofSetColor(myColorCloud.six[1]);
    ofDrawCircle(b_, radiusB);
    ofSetColor(myColorCloud.six[2]);
    ofDrawCircle(c_, radiusC);
}
