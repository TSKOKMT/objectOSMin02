#include "spanningCole.h"

//--------------------------------------------------------------
void spanningCole::draw(ofRectangle frame_, float time_) {
    
    time = time_;
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
 
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
    
    ofPushStyle();
    
    ofSetColor(myColorCloud.six[0]);
    drawOne(frame_.getCenter() + ofPoint(60 * unit, 0), 1200 * unit, 6, ofNoise(time_ / 24.) * TWO_PI * 6);
    
    ofSetColor(myColorCloud.six[1]);
    drawOne(frame_.getCenter() - ofPoint(60 * unit, 0), 1200 * unit, 6, ofNoise(time_ / 24., PI) * TWO_PI * 6);
    
    ofPopStyle();
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
}

//--------------------------------------------------------------
void spanningCole::drawOne(ofPoint center_, float radius_, int count_, float rotation_) {
    
    for (int i = 0; i < count_; i++) {
        float theAngle = ofMap(i, 0, count_, 0, TWO_PI);
        float theWidth = 15;
        
        float theRatio = pow(ofNormalize(sin((time / 6. - (i / (float)count_)) * TWO_PI), -1, 1), 1.7);
         
        float ratio0 = pow(ofNormalize(sin((time / 6.) * TWO_PI), -1, 1), 1.7);
        float ratio1 = pow(ofNormalize(sin((time / 6. - 1 / 3.) * TWO_PI), -1, 1), 1.7);
        float ratio2 = pow(ofNormalize(sin((time / 6. - 2 / 3.) * TWO_PI), -1, 1), 1.7);
        
        ofPushMatrix();
        //ofRotateRad(theAngle);
        
        /*ofPushMatrix();
        ofScale(1, ratio0);
        ofDrawRectangle(0, -theWidth / 2., radius_ / 3., theWidth);
        ofPopMatrix();
        
        ofPushMatrix();
        ofScale(1, ratio1);
        ofDrawRectangle(radius_ / 3., -theWidth * 3 / 2., radius_ / 3., theWidth * 3);
        ofPopMatrix();
        
        ofPushMatrix();
        ofScale(1, ratio2);
        ofDrawRectangle(radius_ / 3. * 2, -theWidth * 9 / 2., radius_ / 3., theWidth * 9);
        ofPopMatrix();*/
        
        //ofDrawRectangle(0, -theWidth / 2., radius_, theWidth);
        
        int slice = 1;
        for (int r = 0; r < slice; r++) {
            ofPushMatrix();
            ofTranslate(center_);
            //ofRotateRad(time * (TWO_PI / (5 + r)));
            //ofRotateRad(ofNoise(time / (5 + r), r * PI) * TWO_PI);
            //ofRotateRad(TWO_PI / (float)count_ / 2. * (r % 2));
            ofRotateRad(rotation_);
            //ofRotateRad(time / (pow(r + 1, 2) / 2.) * TWO_PI * (r % 2 ? 1 : -1));
            
            float radius0 = radius_ / (float)slice * r;
            ofBeginShape();
            for (int a = 12; a >= 0; a--) {
                float theA = theAngle + ofMap(a, 0, 12, 0, TWO_PI / (float)count_ / 2.);
                ofVertex(cos(theA) * radius0, sin(theA) * radius0);
            }
            float radius1 = radius_ / (float)slice * (r + 1);
            for (int a = 0; a <= 12; a++) {
                float theA = theAngle + ofMap(a, 0, 12, 0, TWO_PI / (float)count_ / 2.);
                ofVertex(cos(theA) * radius1, sin(theA) * radius1);
            }
            ofEndShape(true);
            
            ofPopMatrix();
        }
        
        ofPopMatrix();
    }
}
