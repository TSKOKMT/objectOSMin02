#include "yoGreek.h"

//--------------------------------------------------------------
yoGreek::yoGreek() {
    
    positions.resize(3);
    rotations0.resize(3);
    rotations1.resize(3);
}

//--------------------------------------------------------------
void yoGreek::draw(ofRectangle frame_, float time_) {
    
    if (ofGetFrameNum() % 120 == 0) createCircle();
    if (ofGetFrameNum() % 120 == 30) createSquare();
    if (ofGetFrameNum() % 120 == 60) createTriangle();
    if (ofGetFrameNum() % 120 == 90) vanish();
    
    time = time_;
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float side = 60 * unit;
    
    float term = 1;
    float termV = 1;
    
    if (time_ - vanishedTime > termV) {
        circleBeginTime = FLT_MAX;
        squareBeginTime = FLT_MAX;
        triangleBeginTime = FLT_MAX;
    }
    
    auto frameM = marginBand::get(frame_, 2 * unit);
    
    auto framesH = HStack::get(frameM, 3, 2 * unit);
    
    float motionPower = .5;
    
    float vanishMotion = (time_ - vanishedTime) / termV;
    vanishMotion = ofClamp(vanishMotion, 0, 1);
    vanishMotion = 1 - vanishMotion;
    vanishMotion = ofxTskokmtMath::cubicBezierByX(ofPoint(0, 1), ofPoint(0, 1), vanishMotion);
    
    float circleMotion = (time_ - circleBeginTime) / term;
    circleMotion = ofClamp(circleMotion, 0, 1);
    circleMotion = ofxTskokmtMath::cubicBezierByX(ofPoint(0, 1), ofPoint(0, 1), circleMotion);
    
    float squareMotion = (time_ - squareBeginTime) / term;
    squareMotion = ofClamp(squareMotion, 0, 1);
    squareMotion = ofxTskokmtMath::cubicBezierByX(ofPoint(0, 1), ofPoint(0, 1), squareMotion);

    float triangleMotion = (time_ - triangleBeginTime) / term;
    triangleMotion = ofClamp(triangleMotion, 0, 1);
    triangleMotion = ofxTskokmtMath::cubicBezierByX(ofPoint(0, 1), ofPoint(0, 1), triangleMotion);
    
    //DRAW
    
    ofPushStyle();
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofSetColor(myColorCloud.six[0]);
    ofPushMatrix();
    //ofTranslate(framesH[0].getCenter());
    //ofTranslate(ofLerp(frame_.getLeft() + side / 2., frame_.getRight() - side / 2., positions[0].x), ofLerp(frame_.getTop() + side / 2., frame_.getBottom() - side / 2., positions[0].y));
    ofTranslate(frame_.getCenter().x - frame_.width / 4., frame_.getCenter().y);
    //ofTranslate(frame_.getCenter());
    ofScale(circleMotion);
    ofScale(vanishMotion);
    ofRotateRad(ofLerp(rotations0[0], rotations1[0], circleMotion));
    ofDrawCircle(0, 0, sqrt(pow(side, 2) / PI));
    /*ofTranslate(-framesH[0].getCenter());
    ofDrawEllipse(framesH[0].getCenter(), framesH[0].width, framesH[0].height);*/
    ofPopMatrix();
    
    ofSetColor(myColorCloud.six[1]);
    ofPushMatrix();
    //ofTranslate(framesH[1].getCenter());
    //ofTranslate(ofLerp(frame_.getLeft() + side / 2., frame_.getRight() - side / 2., positions[1].x), ofLerp(frame_.getTop() + side / 2., frame_.getBottom() - side / 2., positions[1].y));
    ofTranslate(frame_.getCenter().x, frame_.getCenter().y);
    //ofTranslate(frame_.getCenter());
    ofScale(squareMotion);
    ofScale(vanishMotion);
    ofRotateRad(ofLerp(rotations0[1], rotations1[1], squareMotion));
    ofDrawRectangle(-side / 2., -side / 2., side, side);
    /*ofTranslate(-framesH[1].getCenter());
    ofDrawRectangle(framesH[1]);*/
    ofPopMatrix();
    
    ofSetColor(myColorCloud.six[2]);
    ofPushMatrix();
    //ofTranslate(framesH[2].getCenter());
    //ofTranslate(ofLerp(frame_.getLeft() + side / 2., frame_.getRight() - side / 2., positions[2].x), ofLerp(frame_.getTop() + side / 2., frame_.getBottom() - side / 2., positions[2].y));
    ofTranslate(frame_.getCenter().x + frame_.width / 4., frame_.getCenter().y);
    //ofTranslate(frame_.getCenter());
    ofScale(triangleMotion);
    ofScale(vanishMotion);
    ofRotateRad((1 - vanishMotion) * (rotations1[2] - rotations0[2]) / 4.);
    ofRotateRad(ofLerp(rotations0[2], rotations1[2], triangleMotion));
    ofBeginShape();
    float theRadius = sqrt(pow(side, 2) * 2 * (sqrt(3) / 2.)) * (2 / 3.);
    for (int i = 0; i < 3; i++) {
        float theAngle = i * TWO_PI / 3. - HALF_PI;
        ofVertex(cos(theAngle) * theRadius, sin(theAngle) * theRadius);
    }
    ofEndShape();
    /*ofTranslate(-framesH[2].getCenter());
    ofDrawTriangle(ofPoint(framesH[2].getCenter().x, framesH[2].getTop()), framesH[2].getBottomRight(), framesH[2].getBottomLeft());*/
    ofPopMatrix();
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    ofPopStyle();
}

//--------------------------------------------------------------
void yoGreek::createCircle() {
    
    circleBeginTime = time;
    
    positions[0] = ofPoint(ofRandom(1), ofRandom(1));
    rotations0[0] = ofRandom(TWO_PI * 2);
    rotations1[0] = ofRandom(TWO_PI * 2);
    
    squareBeginTime = FLT_MAX;
    triangleBeginTime = FLT_MAX;
    vanishedTime = FLT_MAX;
}

//--------------------------------------------------------------
void yoGreek::createSquare() {
    
    squareBeginTime = time;
    
    positions[1] = ofPoint(ofRandom(1), ofRandom(1));
    rotations0[1] = ofRandom(TWO_PI * 2);
    rotations1[1] = ofRandom(TWO_PI * 2);
    
    circleBeginTime = FLT_MAX;
    triangleBeginTime = FLT_MAX;
    vanishedTime = FLT_MAX;
}

//--------------------------------------------------------------
void yoGreek::createTriangle() {
    
    triangleBeginTime = time;
    
    positions[2] = ofPoint(ofRandom(1), ofRandom(1));
    rotations0[2] = ofRandom(TWO_PI * 2);
    rotations1[2] = ofRandom(TWO_PI * 2);
    
    circleBeginTime = FLT_MAX;
    squareBeginTime = FLT_MAX;
    vanishedTime = FLT_MAX;
}

//--------------------------------------------------------------
void yoGreek::vanish() {
    
    vanishedTime = time;
}
