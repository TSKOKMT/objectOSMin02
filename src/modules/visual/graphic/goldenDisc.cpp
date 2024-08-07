#include "goldenDisc.h"

//--------------------------------------------------------------
void goldenDisc::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    ofCamera camera;
    camera.setPosition(0, 0, 60 * unit);
    camera.setFov(atan2(frame_.height / 2., camera.getPosition().z) * 2 * RAD_TO_DEG);
    camera.setFarClip(100000);
    camera.setNearClip(.01);
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    ofPushStyle();
    
    camera.begin();
    
    for (int i = 0; i < 100; i++) {
        ofSetColor(i % 2 ? ofColor(0) : myColorCloud.six[i % 6]);
        drawOne(frame_, time_ + .2 * i, 16, 1, (600 - 6 * i) * unit);
    }
    
    camera.end();
    
    ofPopStyle();
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
}

//--------------------------------------------------------------
void goldenDisc::drawOne(ofRectangle frame_, float time_, float interval_, float term_, float side_) {
    
    //UPDATE
    
    previousRotation.x = ofWrap(ofNoise(floor(time_ / interval_ - 1) * PI * 100) * 100, 0, TWO_PI);
    previousRotation.y = ofWrap(ofNoise(floor(time_ / interval_ - 1) * PI * 100, PI * 100) * 100, 0, TWO_PI);
    previousRotation.z = ofWrap(ofNoise(floor(time_ / interval_ - 1) * PI * 100, PI * 200) * 100, 0, TWO_PI);
    
    nextRotation.x = ofWrap(ofNoise(floor(time_ / interval_) * PI * 100) * 100, 0, TWO_PI);
    nextRotation.y = ofWrap(ofNoise(floor(time_ / interval_) * PI * 100, PI * 100) * 100, 0, TWO_PI);
    nextRotation.z = ofWrap(ofNoise(floor(time_ / interval_) * PI * 100, PI * 200) * 100, 0, TWO_PI);
    
    float motion = ofClamp(ofWrap(time_, 0, interval_) / term_, 0, 1);
    motion = ofxTskokmtMath::cubicBezierByX(ofPoint(1, 0), ofPoint(0, 1), motion);
    
    ofPoint rotation = ofPoint(ofNoise(time_ / interval_ / 4.), ofNoise(time_ / interval_ / 4., PI * 100), ofNoise(time_ / interval_ / 4., PI * 200)) * TWO_PI * 4;
    //ofPoint rotation = previousRotation * (1 - motion) + nextRotation * motion;
    
    //DRAW
    
    ofPushMatrix();
    //ofTranslate(frame_.getCenter());
    ofRotateXRad(rotation.x);
    ofRotateYRad(rotation.y);
    ofRotateZRad(rotation.z);
    //ofDrawRectangle(-side_ / 2., -side_ / 2., side_, side_);
    /*ofTranslate(-side_ / 2., -side_ / 2.);
    for (int v = 0; v < 5; v++) {
        for (int h = 0; h < 5; h++) {
            if (v % 2 == h % 2) ofDrawRectangle(side_ / 5. * h, side_ / 5. * v, side_ / 5., side_ / 5.);
        }
    }*/
    ofDrawCircle(0, 0, side_ / 2.);
    /*ofScale(1, 1, .1);
    ofDrawSphere(0, 0, 0, side_ / 2.);*/
    //ofDrawCylinder(0, 0, 0, side_ / 2., side_);
    //ofDrawCone(0, 0, 0, side_ / 2., side_);
    ofPopMatrix();
}
