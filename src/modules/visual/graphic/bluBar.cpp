#include "bluBar.h"

//--------------------------------------------------------------
void bluBar::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;

    float ratio = ofWrap(time_, 0, 1);
    ratio = 1 - ratio;
    ratio = pow(ratio, 4);
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    ofPushStyle();
    ofSetColor(myColorCloud.six[0]);
    
    for (int i = 0; i < count; i++) {
        drawOne(ofPoint(ofMap(i, -.5, count - .5, frame_.getLeft(), frame_.getRight()), frame_.getCenter().y), 3 * unit, ratio);
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
}

//--------------------------------------------------------------
void bluBar::drawOne(ofPoint position_, float width_, float ratio_, int count_) {
    
    ofPushMatrix();
    ofTranslate(position_);
    //ofRotateRad(HALF_PI);
    
    for (int i = 0; i < count_; i++) {
        ofPushMatrix();
        ofTranslate(ofRandom(-1, 1) * ratio_ * width_, ofRandom(-1, 1) * ratio_ * width_ * 120);
        ofRotateRad(ofRandom(-1, 1) * ratio_ * PI / 8.);
        
        ofDrawRectangle(-width_ / 2., -10000, width_, 20000);
        
        ofPopMatrix();
    }
    
    ofPopMatrix();
}
