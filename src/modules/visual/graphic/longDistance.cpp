#include "longDistance.h"

//--------------------------------------------------------------
longDistance::longDistance() {
    
}

//--------------------------------------------------------------
void longDistance::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    auto unit = sqrt(frame_.width * frame_.height) / 120.;
    
    //Init count
    if (count != nextPositions.size()) {
        previousPositions.resize(count);
        nextPositions.resize(count);
        previousAngles.resize(count);
        nextAngles.resize(count);
        previousWidths.resize(count);
        nextWidths.resize(count);
    }
    
    //Create next
    for (int i = 0; i < nextPositions.size(); i++) {
        if (ofWrap(time_ - delay * i, 0, interval) < ofWrap(previousTime - delay * i, 0, interval)) {
            previousPositions[i] = nextPositions[i];
            previousAngles[i] = nextAngles[i];
            previousWidths[i] = nextWidths[i];
        
            if ((int)((time_ - delay * i) / interval) % 3 == 0) {
                nextPositions[i] = ofPoint((i + .5) * (frame_.width / (float)nextPositions.size()), frame_.getCenter().y) + ofRandom(-1, 1) * frame_.width / (float)nextPositions.size() * 12;
                nextAngles[i] = ofRandom(-PI / 4., PI / 4.);
                nextWidths[i] = .5 * unit;
            }
            else if ((int)((time_ - delay * i) / interval) % 3 == 1) {
                nextPositions[i] = ofPoint((i + .5) * (frame_.width / (float)nextPositions.size()), frame_.getCenter().y) + ofRandom(-1, 1) * frame_.width / (float)nextPositions.size();
                nextAngles[i] = ofRandom(-PI / 8., PI / 8.);
                nextWidths[i] = 4 * unit;
            }
            else {
                nextPositions[i] = ofPoint((i + .5) * (frame_.width / (float)nextPositions.size()), frame_.getCenter().y);
                nextAngles[i] = 0;
                nextWidths[i] = frame_.width / (float)nextPositions.size();
            }
        }
    }
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    ofPushMatrix();
    ofTranslate(frame_.position);
    
    ofPushStyle();
    
    for (int i = 0; i < previousPositions.size(); i++) {
        float motion = ofClamp(ofWrap(time_ - delay * i, 0, interval) / .666, 0, 1);
        motion = ofxTskokmtMath::cubicBezierByX(ofPoint(.666, 0), ofPoint(0, 1), motion);
        
        ofPoint thePosition = ofPoint(ofLerp(previousPositions[i].x, nextPositions[i].x, motion), ofLerp(previousPositions[i].y, nextPositions[i].y, motion));
        float theAngle = ofLerp(previousAngles[i], nextAngles[i], motion);
        float theWidth = ofLerp(previousWidths[i], nextWidths[i], motion);
        
        ofSetColor(myColorCloud.six[i % 6]);
        
        drawOne(thePosition, theAngle, theWidth);
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
    
    previousTime = time_;
}

//--------------------------------------------------------------
void longDistance::drawOne(ofPoint center_, float angle_, float width_) {
    
    ofPushMatrix();
    ofTranslate(center_);
    ofRotateRad(angle_);
    
    ofDrawRectangle(-width_ / 2., -10000, width_, 20000);
    
    ofPopMatrix();
}
