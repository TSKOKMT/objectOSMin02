#include "nuWit.h"

//--------------------------------------------------------------
void nuWit::draw(ofRectangle frame_, float time_) {
    
    //SETUP
    
    if (count != pointsFrom.size()) {
        pointsFrom.resize(count);
        pointsTo.resize(count);
    }
    
    //UPDATE
    
    unit = sqrt(frame_.width * frame_.height) / 120.;
    
    term_ = interval_ * (9 / 14.);
    
    //DRAW
    
    ofPushStyle();
    
    for (int i = 0; i < pointsFrom.size(); i++) {
        float delay = i * .001;
        
        int gridCount = 9;
        
        if (ofWrap(time_ - delay, 0, interval_) < ofWrap(previousTime - delay, 0, interval_)) {
            bool bOk;
            do {
                pointsFrom[i] = ofPoint((floor(ofRandom(1) * (gridCount - 1)) + 1) / (float)gridCount, (floor(ofRandom(1) * (gridCount - 1)) + 1) / (float)gridCount);
                pointsTo[i] = ofPoint((floor(ofRandom(1) * (gridCount - 1)) + 1) / (float)gridCount, (floor(ofRandom(1) * (gridCount - 1)) + 1) / (float)gridCount);
                bOk = pointsFrom[i].distance(pointsTo[i]) > .5;
            } while (!bOk);
        }
        
        ofPoint pointFrom = pointsFrom[i];
        ofPoint pointTo = pointsTo[i];
        pointFrom.x *= frame_.width;
        pointFrom.x += frame_.x;
        pointFrom.y *= frame_.height;
        pointFrom.y += frame_.y;
        pointTo.y *= frame_.height;
        pointTo.y += frame_.y;
        pointTo.x *= frame_.width;
        pointTo.x += frame_.x;
        
        ofSetColor(myColorCloud.six[i % 6]);
        
        drawOne(pointFrom, pointTo, time_ - delay);
    }
    
    ofPopStyle();
    
    previousTime = time_;
}

//--------------------------------------------------------------
void nuWit::drawOne(ofPoint pointFrom_, ofPoint pointTo_, float time_) {
    
    float stroke_ = stroke * unit;
    
    float motionHead = ofClamp(ofMap(ofWrap(time_, 0, interval_), 0, term_, 0, 1), 0, 1);
    float motionTail = ofClamp(ofMap(ofWrap(time_, 0, interval_), interval_ - term_, interval_, 0, 1), 0, 1);
    
    motionHead = ofxTskokmtMath::cubicBezierByX(ofPoint(.15, 0), ofPoint(0, 1), motionHead);
    motionTail = ofxTskokmtMath::cubicBezierByX(ofPoint(1, 0), ofPoint(.85, 1), motionTail);
    
    float dist = pointFrom_.distance(pointTo_);
    
    //ofDrawLine(pointFrom_ * (1 - motionHead) + pointTo_ * (motionHead), pointFrom_ * (1 - motionTail) + pointTo_ * (motionTail));
    ofPushMatrix();
    ofTranslate(pointFrom_);
    ofRotateRad(atan2(pointTo_.y - pointFrom_.y, pointTo_.x - pointFrom_.x));
    ofDrawRectangle(motionTail * dist, -stroke_ / 2., (motionHead - motionTail) * dist, stroke_);
    ofPopMatrix();
}
