#include "fallFree.h"

//--------------------------------------------------------------
fallFree::fallFree() {
    
    box2d.init();
    for (int i = 0; i < 50; i++) {
        ofPoint thePosition = ofPoint(ofRandom(1440), ofRandom(1440));
        bool bCircle = (int)ofRandom(2);
        float angle = ofRandom(TWO_PI);
        if (bCircle) {
            circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
            circles.back()->setPhysics(1, 1, 1);
            circles.back()->setup(box2d.getWorld(), thePosition.x, thePosition.y, ofRandom(1, 12) * 12);
        }
        else {
            rects.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
            rects.back()->setPhysics(1, 1, 1);
            rects.back()->setup(box2d.getWorld(), thePosition.x, thePosition.y, ofRandom(2, 24) * 12, ofRandom(2, 24) * 12);
            rects.back()->setRotation(ofRandom(TWO_PI));
        }
    }
}

//--------------------------------------------------------------
void fallFree::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    if (previousFrameNum != ofGetFrameNum()) {
        box2d.createBounds(ofRectangle(0, 0, 1440, 1440));
        box2d.setFPS(ofGetFrameRate());
        ofPoint gravity = ofPoint(ofSignedNoise(time_ / 2.) * 20, ofSignedNoise(time_ / 2., PI) * 20);
        box2d.setGravity(gravity);
        box2d.update();
        
        previousFrameNum = ofGetFrameNum();
    }
    
    scale = 4;
    trueScale = sqrt(frame_.width * frame_.height) / 1440. * scale;
    
    float interval = 1;
    if (countMultiples(previousTime, time_, interval) > 0) change();
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
        
    ofPushMatrix();
    ofScale(trueScale);
    ofTranslate(translate);
    
    ofPushStyle();

    //Draw objects
    ofSetColor(myColorCloud.six[colorMode]);
               
    for (int c = 0; c < circles.size(); c++) {
        ofDrawCircle(circles[c]->getPosition(), circles[c]->getRadius());
    }
    for (int r = 0; r < rects.size(); r++) {
        rects[r]->draw();
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
    
    
    
    previousTime = time_;
}

//--------------------------------------------------------------
void fallFree::change() {
    
    translate.x = -(floor(ofRandom(scale + 1)) / scale) * (1440 - frame.width / trueScale);
    translate.y = -(floor(ofRandom(scale + 1)) / scale) * (1440 - frame.height / trueScale);
    
    colorMode = (colorMode + 1) % 3;
}
