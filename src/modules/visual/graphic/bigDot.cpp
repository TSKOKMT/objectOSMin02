#include "bigDot.h"

//--------------------------------------------------------------
void bigDot::draw(ofRectangle frame_, float time_) {
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    //SETUP
    
    float radius_ = radius * unit;
    
    if (circles.size() != num_) {
        box2d.init();
        box2d.setGravity(0, 0);
        for (int i = 0; i < num_; i++) {
            circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
            circles.back()->setPhysics(1, 1, 1);
            ofPoint position = ofxTskokmtMath::randomPointInRectangle(frame_);
            circles.back()->setup(box2d.getWorld(), position.x, position.y, radius_);
        }
        
        previousFrame = frame_;
        previousRadius = radius_;
    }
    
    //UPDATE
    
    //Frame Check
    if (frame_ != previousFrame) {
        for (int i = 0; i < circles.size(); i++) {
            ofPoint position = ofxTskokmtMath::map(circles[i]->getPosition(), previousFrame, frame_);
            circles[i]->setPosition(position);
        }
        previousFrame = frame_;
    }
    
    //Position Check
    /*for (int i = 0; i < circles.size(); i++) {
        if (!ofxTskokmtMath::isInRectangle(circles[i]->getPosition(), ofxTskokmtTool::offsetRectangle(frame_, radius_))) {
            ofPoint position = ofxTskokmtMath::randomPointInRectangle(frame_);
            circles[i]->setPosition(position);
        }
    }*/
    
    //Once in frame
    if (previousFrameNum != ofGetFrameNum()) {
        //Update Radius
        if (radius_ != previousRadius) {
            for (int i = 0; i < circles.size(); i++) {
                circles[i]->setRadius(radius_);
            }
            previousRadius = radius_;
        }
        
        //Add force to circle
        for (int i = 0; i < circles.size(); i++) {
            int index = (i + 1) % (int)circles.size();
            ofPoint point = circles[index]->getPosition();
            float scale = sin((time_ / hour_ + i / (float)circles.size()) * TWO_PI) * intensity_;
            circles[i].get()->addForce(point, scale);
        }
        
        box2d.setFPS(ofGetFrameRate());
        box2d.createBounds(frame_.x - radius_, frame_.y - radius_, frame_.width + radius_ * 2, frame_.height + radius_ * 2);
        box2d.update();
    
        previousFrameNum = ofGetFrameNum();
    }
    
    //DRAW
    
    ofPushStyle();
    ofSetColor(myColorCloud.six[0]);
    
    for (int i = 0; i < circles.size(); i++) {
        ofDrawCircle(circles[i]->getPosition(), circles[i]->getRadius());
    }
    
    ofPopStyle();
}
