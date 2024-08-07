#include "darlingApp.h"

//--------------------------------------------------------------
void darlingApp::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float theSpacing = spacing * unit;
    
    countH = floor(frame_.width / theSpacing);
    countH = ofClamp(countH, 1, INT_MAX);
    countV = floor(frame_.height / theSpacing);
    countV = ofClamp(countV, 1, INT_MAX);
    
    int count = countH * countV;
    if (ids.size() != count) {
        ids.resize(count);
        points.resize(count);
        terms.resize(count);
        radiuses.resize(count);
        shuffle();
    }
    
    align(countH, countV, theSpacing * sqrt(2));
    
    float speedT = .1;
    float speedR = .1;
    float speedS = .1;
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    ofPushMatrix();
    ofTranslate(frame_.getCenter());
    ofScale(ofMap(ofNoise(time_ * speedS), 0, 1, 0, 10));
    ofRotateRad(ofSignedNoise(time_ * speedR, PI) * TWO_PI / 2.);
    ofTranslate(ofSignedNoise(time_ * speedT, pow(PI, 2)) * frame_.width / 2., ofSignedNoise(time_ * speedT, pow(PI, 3)) * frame_.height / 2.);
    
    ofPushStyle();
    
    for (int i = 0; i < ids.size(); i++) {
        ofSetColor(myColorCloud.six[i % 6]);
        drawApp(points[i], theSpacing / 3/* * radiuses[i]*/, time_ / terms[i] * TWO_PI, ids[i]);
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
}

//--------------------------------------------------------------
void darlingApp::drawApp(ofPoint position_, float radius_, float rotation_, int id_) {
    
    /*ofPushMatrix();
    ofTranslate(position_);
    ofRotateRad(rotation_);
    ofScale(radius_);
    
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
    
    ofPopMatrix();*/
    
    ofDrawCircle(position_, radius_);
}

//--------------------------------------------------------------
void darlingApp::shuffle() {
    
    for (int i = 0; i < ids.size(); i++) {
        ids[i] = ofRandom(20);
        points[i] = ofPoint(ofRandom(1), ofRandom(1));
        terms[i] = ofRandom(-3, 3);
        radiuses[i] = pow(sqrt(2), ofRandom(-1, 1));
    }
}

//--------------------------------------------------------------
void darlingApp::align(int countH_, int countV_, float spacing_) {
    
    float spacingH = spacing_ * (2 / sqrt(3));
    
    int i = 0;
    for (int v = 0; v < countV_; v++) {
        int y = (v - (countV_ - 1) / 2.) * spacing_;
        for (int h = 0; h < countH_; h++) {
            int x = (h - (countH_ - 1) / 2.) * spacingH;
            x += v % 2 * spacingH / 2.;
            points[i] = ofPoint(x, y);
            i++;
        }
    }
}

//--------------------------------------------------------------
void darlingApp::bigger() {
    
    spacing *= sqrt(2);
    spacing = ofClamp(spacing, 3, 96);
}

//--------------------------------------------------------------
void darlingApp::smaller() {
    
    spacing /= sqrt(2);
    spacing = ofClamp(spacing, 3, 96);
}
