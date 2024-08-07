#include "keenPublic.h"

//--------------------------------------------------------------
void keenPublic::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    auto center_ = frame_.getCenter();
    
    rotation_ = time_ * PI / 2.;
    clock_ = time_ * PI / 2.;
    
    float radius_ = radius * unit;
    float length_ = length * unit;
    float weight_ = weight * unit;
    
    if (previousFrameNum != ofGetFrameNum()) {
        previousFrameNum = ofGetFrameNum();
        colorOffset = 0;
    }
    
    //DRAW
    
    ofPushMatrix();
    ofTranslate(center_);
    ofRotateZRad(clock_);
    
    ofPushStyle();
    
    ofSetColor(myColorCloud.six[colorOffset % 6]);
    
    for (int i = 0; i < count_; i++) {
        ofPushMatrix();
        ofRotateZRad(ofMap(i, 0, count_, 0, TWO_PI));
        ofTranslate(radius_, 0);
        ofRotateYRad(rotation_/* + ofMap(i, 0, count_, 0, TWO_PI)*/);
        //ofRotateXRad(rotation_);
        
        ofDrawBox(length_, weight_, weight_);
        //ofDrawSphere(length_ / 2., 0, 0, weight_ / 2.);
        //ofDrawSphere(-length_ / 2., 0, 0, weight_ / 2.);
        
        ofPopMatrix();
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    
    colorOffset++;
}
