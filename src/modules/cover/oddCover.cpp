#include "oddCover.h"

//--------------------------------------------------------------
void oddCover::draw(ofRectangle frame, float time) {
    
    float unit = sqrt(frame.width * frame.height) / 120.;
    
    ofPushStyle();
    ofSetLineWidth(unit / 2.);
    
    if (id_ == 0) {
        float side = 30 * unit;
        int count = 24;
        
        for (int i = 0; i < count; i++) {
            ofPushMatrix();
            ofTranslate(ofNoise(ofRandom(10000)) * frame.width, ofNoise(ofRandom(10000)) * frame.height);
            ofScale(side);
            ofDrawRectangle(-.5, -.5, 1, 1);
            ofPopMatrix();
        }
    }
    else if (id_ == 1) {
        float radius = 4 * unit;
        int count = 60;
        
        for (int i = 0; i < count; i++) {
            ofPushMatrix();
            ofTranslate(ofNoise(ofRandom(10000)) * frame.width, ofNoise(ofRandom(10000)) * frame.height);
            ofScale(radius);
            ofDrawCircle(0, 0, 1);
            ofPopMatrix();
        }
    }
    else if (id_ == 2) {
        float side = 12 * unit;
        int count = 30;
        
        float radius = side * (sqrt(3) / 2.) * (2 / 3.);
        
        for (int i = 0; i < count; i++) {
            ofPushMatrix();
            ofTranslate(ofNoise(ofRandom(10000)) * frame.width, ofNoise(ofRandom(10000)) * frame.height);
            ofRotateRad(ofRandom(ofRandom(TWO_PI)));
            ofScale(radius);
            ofBeginShape();
            for (int i = 0; i < 3; i++) {
                float theAngle = i / 3. * TWO_PI;
                ofVertex(cos(theAngle), sin(theAngle));
            }
            ofEndShape(true);
            ofPopMatrix();
        }
    }
    else if (id_ == 3) {
        int count = 12;
        ofBeginShape();
        for (int i = 0; i < count; i++) {
            ofCurveVertex(ofLerp(-.2, 1.2, ofNoise(ofRandom(10000))) * frame.width, ofLerp(-.2, 1.2, ofNoise(ofRandom(10000))) * frame.height);
        }
        ofEndShape(true);
    }
    else if (id_ == 4) {
        int count = 12;
        
        for (int i = 0; i < count; i++) {
            ofBeginShape();
            ofCurveVertex(ofNoise(ofRandom(10000)) * frame.width, ofNoise(ofRandom(10000)) * frame.height);
            ofCurveVertex(ofNoise(ofRandom(10000)) * frame.width, ofNoise(ofRandom(10000)) * frame.height);
            ofCurveVertex(ofNoise(ofRandom(10000)) * frame.width, ofNoise(ofRandom(10000)) * frame.height);
            ofCurveVertex(ofNoise(ofRandom(10000)) * frame.width, ofNoise(ofRandom(10000)) * frame.height);
            ofCurveVertex(ofNoise(ofRandom(10000)) * frame.width, ofNoise(ofRandom(10000)) * frame.height);
            ofEndShape(true);
        }
    }
    else if (id_ == 5) {
        float radius = 3 * unit;
        int count = 12;
        int countC = 30;
        
        vector<ofPoint> points;
        points.resize(count);
        for (int i = 0; i < count; i++) {
            points[i] = ofPoint(ofNoise(ofRandom(10000)), ofNoise(ofRandom(10000)));
            points[i].x = ofMap(points[i].x, .25, .75, 0, 1) * frame.width;
            points[i].y = ofMap(points[i].y, .25, .75, 0, 1) * frame.height;
        }
        
        for (int i = 0; i < count; i++) {
            ofPushMatrix();
            ofTranslate(points[i]);
            ofScale(radius);
            ofDrawCircle(0, 0, 1);
            ofPopMatrix();
        }
        
        for (int i = 0; i < countC; i++) {
            ofDrawLine(points[(int)ofRandom(points.size())], points[(int)ofRandom(points.size())]);
        }
    }
    else if (id_ == 6) {
        int count = 30;
        
        for (int i = 0; i < count; i++) {
            float theTerm = ofWrap(ofNoise(i * 10000 * PI) * 10000 * PI, -3, 3);
            
            ofPushMatrix();
            ofTranslate(ofNoise(i * 10000 * PI) * frame.width, ofNoise(i * 10000 * PI, 10000 * PI) * frame.height);
            ofRotateRad(time / theTerm * TWO_PI);
            ofDrawRectangle(-1200 * unit, -2 * unit, 2400 * unit, 4 * unit);
            ofPopMatrix();
        }
    }
    else if (id_ == 7) {
        int count = 12;
        int radius = 30 * unit;
        
        for (int i = 0; i < count; i++) {
            float theTerm = ofWrap(ofNoise(i * 10000 * PI) * 10000 * PI, -3, 3);
            float theAspect = pow(2, ofWrap(ofNoise(i * 20000 * PI) * 20000 * PI, -1, 1));
            float theWidth = sqrt(theAspect);
            float theHeight = 1 / sqrt(theAspect);
            
            ofPushMatrix();
            ofTranslate(ofNoise(i * 30000 * PI) * frame.width, ofNoise(i * 30000 * PI, 30000 * PI) * frame.height);
            ofRotateRad(time / theTerm * TWO_PI);
            ofScale(radius);
            ofScale(theWidth, theHeight);
            
            ofBeginShape();
            for (int j = 0; j < 5; j++) {
                float theAngle = j / 5. * TWO_PI;
                theAngle += ofRandom(-1, 1) * PI / 24.;
                float theLength = 1 + ofRandom(-1, 1) * .05;
                ofCurveVertex(cos(theAngle) * theLength, sin(theAngle) * theLength);
            }
            ofEndShape(true);
            
            ofPopMatrix();
        }
    }
    
    ofPopStyle();
}
