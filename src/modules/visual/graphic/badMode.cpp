#include "badMode.h"

//--------------------------------------------------------------
void badMode::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float radius;
    if (frame_.getAspectRatio() > 1) radius = frame_.height / (float)(2 + 1);
    else radius = frame_.width / (float)(2 + 1);
    
    //DRAW
    
    ofPushStyle();
    
    for (int i = 0; i < 4; i++) {
        float theTerm;
        ofPoint theCenter;
        float theRotation;
        
        theTerm = ofSignedNoise(i, (int)(time_ / interval_)) * term_;
        
        if (i == 0) theCenter = frame_.position + ofPoint(radius, radius);
        else if (i == 1) theCenter = frame_.position + ofPoint(radius, frame_.height - radius);
        else if (i == 2) theCenter = frame_.position + ofPoint(frame_.width - radius, radius);
        else theCenter = frame_.position + ofPoint(frame_.width - radius, frame_.height - radius);
        
        theRotation = time_ / theTerm * TWO_PI;
        
        ofPushMatrix();
        ofTranslate(theCenter);
        ofRotateRad(theRotation);
        
        ofSetColor(0);
        ofBeginShape();
        ofVertex(0, 0);
        for (int j = 0; j <= 30; j++) {
            float theAngle = ofMap(j, 0, 30, 0, PI);
            ofVertex(ofPoint(cos(theAngle), sin(theAngle)) * radius);
        }
        ofEndShape(true);
        
        ofSetColor(myColorCloud.six[i % 6]);
        ofBeginShape();
        ofVertex(0, 0);
        for (int j = 0; j <= 30; j++) {
            float theAngle = ofMap(j, 0, 30, PI, TWO_PI);
            ofVertex(ofPoint(cos(theAngle), sin(theAngle)) * radius);
        }
        ofEndShape(true);
        
        ofPopMatrix();
    }
    
    ofPopStyle();
}
