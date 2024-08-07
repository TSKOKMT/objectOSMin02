#include "moonShot.h"

//--------------------------------------------------------------
moonShot::moonShot() {

}

//--------------------------------------------------------------
void moonShot::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float radius_ = radius * unit;
    
    //Create camera
    /*ofCamera camera;
    camera.enableOrtho();
    camera.setFarClip(10000);
    camera.setNearClip(.01);*/
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    //camera.begin();
    
    ofDisableArbTex();
    ofEnableDepthTest();
    
    for (int i = 0; i < count_; i++) {
        float theTime = time_ - i * delay_ * (bRToL_ ? -1 : 1);
        
        ofPoint thePosition = ofPoint(ofMap(i, -.5, count_ - .5, frame_.getLeft(), frame_.getRight()), frame_.getCenter().y);
        
        float theMotion;
        
        float baseMotion = ofWrap(theTime / term_, 0, 1);
        baseMotion = ofxTskokmtMath::cubicBezierByX(ofPoint(0, .75), ofPoint(.25, 1), baseMotion);
        
        float springMotion = sin(theTime / term_ * TWO_PI * 4);
        springMotion *= 1 - baseMotion;
        
        theMotion = baseMotion + springMotion;
        
        if (ofWrap(theTime / term_, 0, 4) < 1) {
        }
        else if (ofWrap(theTime / term_, 0, 4) < 2) {
            theMotion = 1;
        }
        else if (ofWrap(theTime / term_, 0, 4) < 3) {
            theMotion += 1;
        }
        else {
            theMotion = 0;
        }
        
        ofFbo texFbo;
        texFbo.allocate(512, 256, GL_RGB);
        texFbo.begin();
        ofPushStyle();
        ofSetColor(myColorCloud.six[i % 6]);
        ofDrawRectangle(128, 0, 256, 256);
        ofPopStyle();
        texFbo.end();
        
        ofPushMatrix();
        ofTranslate(thePosition);
        ofRotateYRad(theMotion * PI);
        
        texFbo.getTexture().bind();
        ofDrawSphere(0, 0, 0, radius_);
        texFbo.getTexture().unbind();
        
        ofPopMatrix();
    }
    
    ofDisableDepthTest();
    ofEnableArbTex();
    
    //camera.end();
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
}
