#include "andThen.h"

//--------------------------------------------------------------
andThen::andThen() {
    
    shapes.push_back(ofPolyline());
    shapes.back().addVertex(-2, -1);
    shapes.back().addVertex(2, -1);
    shapes.back().addVertex(2, 1);
    shapes.back().addVertex(-2, 1);
    shapes.back().rotateRad(PI / 4., ofPoint(0, 0, 1));
    shapes.back().close();
    
    shapes.push_back(ofPolyline());
    for (int i = 0; i < 6; i++) {
        float theAngle = ofMap(i, 0, 6, 0, TWO_PI);
        shapes.back().addVertex(cos(theAngle), sin(theAngle));
    }
    shapes.back().rotateRad(PI / 2., ofPoint(0, 0, 1));
    shapes.back().close();
    
    shapes.push_back(ofPolyline());
    shapes.back().addVertex(1, -2);
    for (int i = 0; i <= 60; i++) {
        float theAngle = ofMap(i, 0, 60, 0, PI);
        shapes.back().addVertex(cos(theAngle), sin(theAngle));
    }
    shapes.back().addVertex(-1, -2);
    shapes.back().close();
    
    for (auto& shape : shapes) {
        shape.translate(-shape.getCentroid2D());
        shape.scale(1 / shape.getArea(), 1 / shape.getArea());
    }
}

//--------------------------------------------------------------
void andThen::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    auto unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float factor = .3;
    
    float radius = side * unit;
    
    shapeIndex = floor(ofWrap(time_ / term, 0, shapes.size()));
    auto theShape = shapes[shapeIndex];
    
    //DRAW
    
    ofSetColor((int)ofWrap(time_ / term, 0, 2) ? myColorCloud.six[0] : ofColor(0));
    ofDrawRectangle(frame_);
    
    ofPushStyle();
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    ofSetColor(myColorCloud.six[0]);
    
    ofPushMatrix();
    ofTranslate(frame_.getCenter());
    int countH = ceil(frame_.width / (2 * radius)) + 2;
    int countV = ceil(frame_.height / (2 * radius)) + 2;
    for (int v = 0; v < countV; v++) {
        for (int h = 0; h < countH; h++) {
            float hh = h - (countH - 1) / 2.;
            float vv = v - (countV - 1) / 2.;
            
            float theTime = time_ - ofNormalize(abs(hh), 0, (countH - 1) / 2.) * factor;
            float motion = ofWrap(theTime, 0, term);
            motion = ofClamp(motion - factor, 0, 1);
            motion = ofxTskokmtMath::cubicBezierByX(ofPoint(0, 1), ofPoint(.25, 1), motion);
            motion = 1 - motion;
                                        
            float side = 2 * radius * motion;
            ofPushMatrix();
            ofTranslate(2 * radius * hh, 2 * radius * vv);
            ofScale(side * 3);
            ofBeginShape();
            for (int i = 0; i < theShape.size(); i++) ofVertex(theShape.getVertices()[i]);
            ofEndShape(true);
            ofPopMatrix();
        }
    }
    ofPopMatrix();
    
    if (ofWrap(time_, 0, term) < factor) ofDrawRectangle(frame_);
    
    ofPopMatrix();
    fbo.end();
    
    ofSetColor((1 - (int)ofWrap(time_ / term, 0, 2)) * 255);
    fbo.draw(frame_.position);
    
    ofPopStyle();
}
