#include "bluBlu.h"

//--------------------------------------------------------------
void bluBlu::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    ofPoint center_ = frame_.getCenter();
    
    float radius_ = radius * unit;
    
    //DRAW
    
    ofPushMatrix();
    ofTranslate(center_);
    
    ofPushStyle();
    ofSetColor(myColorCloud.six[0]);
    
    ofBeginShape();
    for (int i = count_ - 1; i >= 0; i--) {
        float theTime = time_ - delay_ * i;
        theTime /= term;
        
        float theRadius = ofMap(i, -count_ / 1.2, count_ - 1, 0, radius_);
        float theRadiusNext = ofMap(i - 1, -count_ / 1.2, count_ - 1, 0, radius_);
        float theX = 1 - ofWrap(time_, 0, 1);
        theX = pow(theX, 3);
        theX *= radius_ / 5.;
        
        float theRotation = theTime * 9 * TWO_PI;
        
        for (int j = 0; j < 128; j++) {
            float theAngle = ofMap(j, 0, 128, 0, TWO_PI);
            ofVertex(cos(theRotation) * theX + cos(theAngle) * theRadius, sin(theRotation) * theX + sin(theAngle) * theRadius);
        }
        
        ofNextContour();
    }
    ofEndShape(true);
    
    ofPopStyle();
    
    ofPopMatrix();
}
