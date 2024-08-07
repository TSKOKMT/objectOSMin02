#include "superFlat.h"

//--------------------------------------------------------------
superFlat::superFlat() {

}

//--------------------------------------------------------------
void superFlat::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    auto unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float side = 30 * unit;
    
    float rotation = ofNormalize(sin(time_ / 9. * TWO_PI), -1, 1);
    rotation = ofNormalize(sin(ofLerp(-HALF_PI, HALF_PI, rotation)), -1, 1);
    rotation *= TWO_PI;
    
    ofCamera camera;
    camera.enableOrtho();
    camera.setPosition(0, 0, 1000);
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    camera.begin();
    
    ofPushStyle();

    //ofNoFill();
    drawBoxes(ofPoint(0, 0), -time_ / 12. * TWO_PI, ofPoint(rotation, rotation, rotation), side);
    
    ofPopStyle();
    
    camera.end();
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
}

//--------------------------------------------------------------
void superFlat::drawBoxes(ofPoint center_, float clock_, ofPoint rotation_, float side_) {
    
    ofPushMatrix();
    ofTranslate(center_);
    ofRotateXRad(clock_);
    ofRotateYRad(clock_);
    ofRotateZRad(clock_);
    
    ofSetColor(myColorCloud.six[0]);
    ofPushMatrix();
    ofTranslate(ofPoint(-side_, 0));
    ofRotateXRad(-rotation_.x);
    ofRotateYRad(rotation_.y);
    ofRotateZRad(rotation_.z);
    ofDrawBox(side_);
    ofPopMatrix();
    
    ofSetColor(myColorCloud.six[1]);
    ofPushMatrix();
    ofTranslate(ofPoint(0, -side_));
    ofRotateXRad(rotation_.x);
    ofRotateYRad(-rotation_.y);
    ofRotateZRad(rotation_.z);
    ofDrawBox(side_);
    ofPopMatrix();
    
    ofSetColor(myColorCloud.six[2]);
    ofPushMatrix();
    ofTranslate(ofPoint(0, 0, -side_));
    ofRotateXRad(rotation_.x);
    ofRotateYRad(rotation_.y);
    ofRotateZRad(-rotation_.z);
    ofDrawBox(side_);
    ofPopMatrix();
    
    ofSetColor(myColorCloud.six[3]);
    ofPushMatrix();
    ofTranslate(ofPoint(side_, 0));
    ofRotateXRad(-rotation_.x);
    ofRotateYRad(rotation_.y);
    ofRotateZRad(rotation_.z);
    ofDrawBox(side_);
    ofPopMatrix();
    
    ofSetColor(myColorCloud.six[4]);
    ofPushMatrix();
    ofTranslate(ofPoint(0, side_));
    ofRotateXRad(rotation_.x);
    ofRotateYRad(-rotation_.y);
    ofRotateZRad(rotation_.z);
    ofDrawBox(side_);
    ofPopMatrix();
    
    ofSetColor(myColorCloud.six[5]);
    ofPushMatrix();
    ofTranslate(ofPoint(0, 0, side_));
    ofRotateXRad(rotation_.x);
    ofRotateYRad(rotation_.y);
    ofRotateZRad(-rotation_.z);
    ofDrawBox(side_);
    ofPopMatrix();
    
    ofPopMatrix();
}
