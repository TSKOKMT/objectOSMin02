#include "tryAngle.h"

//--------------------------------------------------------------
void tryAngle::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    vector<ofPoint> points;
    points.resize(3);
    for (int i = 0; i < points.size(); i++) {
        points[i].x = ofNoise(time_ / 8., i, 0);
        points[i].x = ofLerp(frame_.getLeft(), frame_.getRight(), points[i].x);
        
        points[i].y = ofNoise(time_ / 8., i, PI);
        points[i].y = ofLerp(frame_.getTop(), frame_.getBottom(), points[i].y);
    }
    
    /*points[1] = ofPoint(ofGetMouseX(), ofGetMouseY());
    
    points[0] = frame_.getCenter() - ofPoint(30, 0) * unit;
    points[2] = frame_.getCenter() + ofPoint(30, 0) * unit;*/
    
    //DRAW
    
    ofPushStyle();
    
    ofSetColor(myColorCloud.six[0]);
    drawTape(points[0], points[1], points[2], 60 * unit);
    
    ofPopStyle();
    
    /*ofSetColor(255, 225, 0);
    for (int i = 0; i < points.size(); i++) {
        ofDrawCircle(points[i], unit);
    }*/
}

//--------------------------------------------------------------
void tryAngle::drawTape(ofPoint a_, ofPoint b_, ofPoint c_, float weight_) {
    
    ofPoint center = getCenter(a_, b_, c_);
    float radius = center.distance(c_);
    
    float angle = atan2(c_.y - a_.y, c_.x - a_.x);
    
    float beginAngle = atan2(a_.y - center.y, a_.x - center.x);
    float endAngle = atan2(c_.y - center.y, c_.x - center.x);
    if (abs(atan2(a_.y - b_.y, a_.x - b_.x) - atan2(c_.y - b_.y, c_.x - b_.x) + angle) < HALF_PI) beginAngle = ofWrap(beginAngle, endAngle, endAngle + TWO_PI * ((beginAngle - angle) > 0 ? -1 : 1));
    
    moonModule::draw(center, radius - weight_ / 2., radius + weight_ / 2., 0, beginAngle, endAngle);
}

//--------------------------------------------------------------
ofPoint tryAngle::getCenter(ofPoint a_, ofPoint b_, ofPoint c_) {
    
    float d = 2 * (a_.x * (b_.y - c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y));
        
    float x = ((a_.x * a_.x + a_.y * a_.y) * (b_.y - c_.y) + (b_.x * b_.x + b_.y * b_.y) * (c_.y - a_.y) + (c_.x * c_.x + c_.y * c_.y) * (a_.y - b_.y)) / d;
    float y = ((a_.x * a_.x + a_.y * a_.y) * (c_.x - b_.x) + (b_.x * b_.x + b_.y * b_.y) * (a_.x - c_.x) + (c_.x * c_.x + c_.y * c_.y) * (b_.x - a_.x)) / d;
    
    return ofVec2f(x, y);
}
