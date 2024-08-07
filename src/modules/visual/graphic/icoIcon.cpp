#include "icoIcon.h"

//--------------------------------------------------------------
icoIcon::icoIcon() {

}

//--------------------------------------------------------------
void icoIcon::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    //Create camera;
    /*ofCamera camera;
    camera.setNearClip(.01);
    camera.setFarClip(10000);
    camera.setFov(60);
    camera.setPosition(0, 0, 2);*/
    
    if (previousFrameNum != ofGetFrameNum()) {
        previousFrameNum = ofGetFrameNum();
        colorOffset = 0;
    }
    
    //DRAW
    
    //camera.begin();
    
    ofPushStyle();
    ofSetColor(myColorCloud.six[colorOffset % 6]);
    
    ofPushMatrix();
    ofTranslate(frame_.getCenter());
    ofScale(side * unit);
    
    float rotation = time_ / term * TWO_PI;
    ofRotateXRad(rotation);
    ofRotateYRad(rotation);
    ofRotateZRad(rotation);
    //ofDrawIcoSphere(0, 0, 0, 1);
    //ofDrawBox(0, 0, 0, 2 / sqrt(3));
    vector<ofPoint> points;
    points.push_back(ofPoint(-1, -1, -1) / sqrt(3));
    points.push_back(ofPoint(-1, 1, 1) / sqrt(3));
    points.push_back(ofPoint(1, -1, 1) / sqrt(3));
    points.push_back(ofPoint(1, 1, -1) / sqrt(3));
    for (int i = 0; i < points.size(); i++) {
        ofBeginShape();
        for (int j = 0; j < points.size(); j++) {
            if (i == j) continue;
            ofVertex(points[j]);
        }
        ofEndShape(true);
    }
    
    ofPopMatrix();
    
    ofPopStyle();
    
    //camera.end();
    
    colorOffset++;
}
