#include "twoBall.h"

//--------------------------------------------------------------
void twoBall::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
 
    float theMotion;
    
    float baseMotion = ofWrap(time_ / term_, 0, 1);
    baseMotion = ofxTskokmtMath::cubicBezierByX(ofPoint(0, 1), ofPoint(0, 1), baseMotion);
    
    float springMotion = sin(time_ / term_ * TWO_PI * 4 + ofNoise(time_ / 12.) * 2);
    springMotion *= 1 - baseMotion;
    
    theMotion = baseMotion + springMotion;
    
    if (ofWrap(time_ / term_, 0, 2) >= 1) theMotion = 1 - theMotion;
    
    //DRAW
    
    ofPushStyle();
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    ofSetColor(myColorCloud.six[0]);
    ofDrawCircle(frame_.getLeft(), frame_.getCenter().y, ofLerp(.05, .9, theMotion) * frame_.width);
    
    ofSetColor(myColorCloud.six[1]);
    ofDrawCircle(frame_.getRight(), frame_.getCenter().y, ofLerp(.05, .9, 1 - theMotion) * frame_.width);
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
    
    ofPopStyle();
}
