#include "reCenter.h"

//--------------------------------------------------------------
void reCenter::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float radius_ = radius * unit;
    
    //DRAW
    
    ofPushStyle();
    
    for (int i = 0; i < count_; i++) {
        float theTime = time_ - i * delay_ * (bRToL_ ? -1 : 1);
        theTime = ofWrap(theTime, 0, interval_);
        
        ofPoint thePosition = ofPoint(ofMap(i, -.5, count_ - .5, frame_.getLeft(), frame_.getRight()), frame_.getCenter().y);
        
        float theMotion;
        
        if (ofWrap(theTime / term_, 0, 4) < 1) {
            float baseMotion = ofWrap(theTime / term_, 0, 1);
            baseMotion = ofxTskokmtMath::cubicBezierByX(ofPoint(0, .75), ofPoint(.25, 1), baseMotion);
            
            float springMotion = sin(theTime / term_ * TWO_PI * 2);
            springMotion *= 1 - baseMotion;
            
            theMotion = baseMotion + springMotion;
        }
        else if (ofWrap(theTime / term_, 0, 4) < 2) {
            theMotion = ofWrap(theTime / term_, 0, 1);
            theMotion = ofClamp(theMotion * 2, 0, 1);
            theMotion = ofxTskokmtMath::cubicBezierByX(ofPoint(1, 0), ofPoint(1, .1), theMotion);
            theMotion = 1 - theMotion;
        }
        
        ofSetColor(myColorCloud.six[i % 6]);
        
        ofDrawCircle(thePosition, radius_ * theMotion);
        //drawApp(thePosition, radius_ * theMotion, time_ / ofWrap(ofNoise((i + seed) * PI * 100, PI) * PI * 100000, -4, 4), ofWrap(ofNoise((i + 1) * PI * 200 * seed, PI * 2) * PI * 567000, 0, 20));
    }
    
    ofPopStyle();
}

//--------------------------------------------------------------
void reCenter::drawApp(ofPoint position_, float radius_, float rotation_, int id_) {
    
    ofPushMatrix();
    ofTranslate(position_);
    ofRotateRad(rotation_);
    ofScale(radius_);
    
    int resolution = 60;
    
    if (id_ == 0) {
        ofBeginShape();
        for (int i = 0; i <= round(resolution / 2.); i++) {
            float theAngle = ofMap(i, 0, round(resolution / 2.), 0, PI);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        ofEndShape(true);
    }
    else if (id_ == 1) {
        ofBeginShape();
        for (int i = 0; i <= round(resolution / 4.); i++) {
            float theAngle = ofMap(i, 0, round(resolution / 4.), -PI / 4., PI / 4.);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        for (int i = 0; i <= round(resolution / 4.); i++) {
            float theAngle = PI + ofMap(i, 0, round(resolution / 4.), PI / 4., -PI / 4.);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        ofEndShape(true);
    }
    else if (id_ == 2) {
        ofBeginShape();
        for (int i = 0; i < resolution; i++) {
            float theAngle = ofMap(i, 0, resolution, TWO_PI / 5. / 2., TWO_PI - TWO_PI / 5. / 2.);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        ofNextContour(true);
        for (int i = 0; i < resolution; i++) {
            float theAngle = ofMap(i, 0, resolution, 0, TWO_PI);
            ofVertex(cos(theAngle) * .25, sin(theAngle) * .25);
        }
        ofEndShape(true);
    }
    else if (id_ == 3) {
        float height = .5;
        float openness = atan2(height / 2., 1);
        float width = 1.5;
        float r = .05;
        ofBeginShape();
        for (int i = 0; i <= resolution; i++) {
            float theAngle = ofMap(i, 0, resolution, openness, TWO_PI - openness);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        for (int i = 0; i <= round(resolution / 4.); i++) {
            float theAngle = ofMap(i, 0, round(resolution / 4.), PI + HALF_PI, PI);
            ofVertex(1 - width + cos(theAngle) * r + r, -height / 2. + sin(theAngle) * r + r);
        }
        for (int i = 0; i <= round(resolution / 4.); i++) {
            float theAngle = ofMap(i, 0, round(resolution / 4.), PI, HALF_PI);
            ofVertex(1 - width + cos(theAngle) * r + r, height / 2. + sin(theAngle) * r - r);
        }
        ofEndShape(true);
    }
    else if (id_ == 4) {
        ofBeginShape();
        for (int i = 0; i < resolution; i++) {
            float theAngle = ofMap(i, 0, resolution, 0, TWO_PI);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        ofNextContour(true);
        for (int i = 0; i < 3; i++) {
            float theAngle = ofMap(i, 0, 3, 0, TWO_PI);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        ofEndShape(true);
    }
    else if (id_ == 5) {
        ofBeginShape();
        for (int i = 0; i < resolution; i++) {
            float theAngle = ofMap(i, 0, resolution, 0, TWO_PI);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        ofNextContour(true);
        for (int i = 0; i < 4; i++) {
            float theAngle = ofMap(i, 0, 4, 0, TWO_PI);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        ofEndShape(true);
    }
    else if (id_ == 6) {
        for (int i = 0; i < 4; i++) {
            ofPushMatrix();
            ofRotateRad(i / 4. * TWO_PI);
            ofDrawRectangle(1/ 3., -1 / 3., 2 / 3., 2 / 3.);
            ofPopMatrix();
        }
    }
    else if (id_ == 7) {
        ofPushMatrix();
        ofScale((5 / 3.) / sqrt(2));
        for (int i = 0; i < 4; i++) {
            ofPushMatrix();
            ofRotateRad(i / 4. * TWO_PI);
            ofDrawRectangle(3 / 5., -1 / 5., 2 / 5., 2 / 5.);
            ofDrawRectangle(1 / 5., 1 / 5., 2 / 5., 2 / 5.);
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    else if (id_ == 8) {
        ofPushMatrix();
        ofScale((5 / 3.) / sqrt(2));
        for (int i = 0; i < 4; i++) {
            ofPushMatrix();
            ofRotateRad(i / 4. * TWO_PI);
            ofDrawRectangle(3 / 5., -3 / 5., 2 / 5., 2 / 5.);
            ofDrawRectangle(1 / 5., -5 / 5., 2 / 5., 2 / 5.);
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    else if (id_ == 9) {
        ofDrawEllipse(0, 0, 2, .4);
        ofDrawEllipse(0, 0, .4, 2);
    }
    else if (id_ == 10) {
        for (int i = 0; i < 4; i++) {
            ofPushMatrix();
            ofRotateRad(i * PI / 4.);
            ofDrawEllipse(0, 0, 2, .4);
            ofPopMatrix();
        }
    }
    else if (id_ == 11) {
        int ringCount = 3;
        ofBeginShape();
        for (int i = 0; i < ringCount * 2; i++) {
            float theRadius = ofMap(i, 0, ringCount * 2 - 1, 1, 1. / (ringCount * 4 - 1));
            for (int j = 0; j < resolution; j++) {
                float theAngle = ofMap(j, 0, resolution, 0, TWO_PI);
                ofVertex(cos(theAngle) * theRadius, sin(theAngle) * theRadius);
            }
            if (i < ringCount * 2 - 1) ofNextContour(true);
        }
        ofEndShape(true);
    }
    else if (id_ == 12) {
        int ringCount = 2;
        ofBeginShape();
        for (int i = 0; i < ringCount * 2 - 1; i++) {
            float theRadius = ofMap(i, 0, ringCount * 2 - 2, 1, 1. / (ringCount + 1));
            for (int j = 0; j < resolution; j++) {
                float theAngle = ofMap(j, 0, resolution, 0, TWO_PI);
                ofVertex(cos(theAngle) * theRadius, sin(theAngle) * theRadius);
            }
            if (i < ringCount * 2 - 1) ofNextContour(true);
        }
        ofEndShape(true);
    }
    else if (id_ == 13) {
        ofBeginShape();
        for (int i = 0; i < resolution; i++) {
            float theAngle = ofMap(i, 0, resolution, 0, TWO_PI);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        ofNextContour(true);
        for (int i = 0; i < resolution; i++) {
            float theAngle = ofMap(i, 0, resolution, 0, TWO_PI);
            ofVertex(cos(theAngle) / 2., sin(theAngle) / 2.);
        }
        ofEndShape(true);
    }
    else if (id_ == 14) {
        ofBeginShape();
        for (int i = 0; i < resolution; i++) {
            float theAngle = ofMap(i, 0, resolution, 0, TWO_PI);
            ofVertex(cos(theAngle), sin(theAngle));
        }
        ofNextContour(true);
        for (int i = 0; i < 6; i++) {
            float theAngle = i / 6. * TWO_PI;
            float theRadius = i % 2 ? 1 : 1 / 3.;
            ofVertex(cos(theAngle) * theRadius, sin(theAngle) * theRadius);
        }
        ofEndShape(true);
    }
    else if (id_ == 15) {
        ofBeginShape();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <= resolution; j++) {
                float theAngle = ofMap(j, 0, resolution, PI / 21., HALF_PI - PI / 21.) - i * HALF_PI;
                ofVertex(cos(theAngle), sin(theAngle));
            }
        }
        ofEndShape(true);
    }
    else if (id_ == 16) {
        ofBeginShape();
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j <= resolution; j++) {
                float theAngle = ofMap(j, 0, resolution, PI / 21., PI / 4. - PI / 21.) - i * 3 / 4. * PI;
                ofVertex(cos(theAngle), sin(theAngle));
            }
        }
        ofEndShape(true);
        ofDrawCircle(0, 0, 2 / 5.);
    }
    else if (id_ == 17) {
        ofBeginShape();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <= resolution; j++) {
                float theAngle = ofMap(j, 0, resolution, PI / 9., PI / 2. - PI / 9.) - i * HALF_PI;
                ofVertex(cos(theAngle), sin(theAngle));
            }
        }
        ofEndShape(true);
        ofDrawCircle(0, 0, 1 / 2.);
    }
    else if (id_ == 18) {
        int count = 6;
        ofBeginShape();
        for (int i = 0; i < count; i++) {
            for (int j = 0; j <= round(resolution / (float)count); j++) {
                float theAngle = ofMap(j, 0, round(resolution / (float)count), 0, TWO_PI / count / 2.) - i * (TWO_PI / count);
                ofVertex(cos(theAngle), sin(theAngle));
            }
            ofVertex(0, 0);
        }
        ofEndShape(true);
    }
    else {
        ofBeginShape();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <= round(resolution / 3.); j++) {
                float theAngle = ofMap(j, 0, round(resolution / 3.), 0, TWO_PI / 6.) - i * TWO_PI / 3.;
                ofVertex(cos(theAngle), sin(theAngle));
            }
        }
        ofNextContour(true);
        for (int i = 0; i < 2; i++) {
            float theRadius = ofMap(i, -1, 2, 0, 1);
            for (int j = 0; j < resolution; j++) {
                float theAngle = ofMap(j, 0, resolution, 0, TWO_PI);
                ofVertex(cos(theAngle) * theRadius, sin(theAngle) * theRadius);
            }
            ofNextContour(true);
        }
        ofEndShape(true);
    }
    
    ofPopMatrix();
}
