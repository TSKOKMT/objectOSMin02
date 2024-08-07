#include "unbalanceLance.h"

//--------------------------------------------------------------
void unbalanceLance::draw(ofRectangle frame_, float time_) {
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    int countH_ = round(frame_.width / (side * unit));
    int countV_ = round(frame_.height / (side * unit));
    
    ofPushStyle();
    
    int i = 0;
    for (int h = 0; h < countH_; h++) {
        for (int v = 0; v < countV_; v++) {
            auto theFrame = ofRectangle(frame_.x + h * frame_.width / (float)countH_, frame_.y + v * frame_.height / (float)countV_, frame_.width / (float)countH_, frame_.height / (float)countV_);
            
            float seed0 = v * 50 * PI + PI;
            float seed1 = h * 50 * PI * PI;
            float seed2 = (v + 1) * 50 * PI + PI;
            float seed3 = (h + 1) * 50 * PI * PI;
            
            float value0 = ofNoise(time_ / 2., seed0);
            float value1 = ofNoise(time_ / 2., seed1);
            float value2 = ofNoise(time_ / 2., seed2);
            float value3 = ofNoise(time_ / 2., seed3);
            /*float value0 = ofNormalize(sin(time_ * 2 + seed0 * 12), -1.2, 1.2);
            float value1 = ofNormalize(sin(time_ * 2 + seed1 * 12), -1.2, 1.2);
            float value2 = ofNormalize(sin(time_ * 2 + seed2 * 12), -1.2, 1.2);
            float value3 = ofNormalize(sin(time_ * 2 + seed3 * 12), -1.2, 1.2);*/
            
            ofSetColor(myColorCloud.six[ofWrap(i * 2, 0, 6)]);
            ofBeginShape();
            ofVertex(theFrame.getTopLeft() + ofPoint(value0 * theFrame.width, 0));
            ofVertex(theFrame.getTopLeft() + ofPoint(0, value1 * theFrame.height));
            ofVertex(theFrame.getBottomLeft() + ofPoint(value2 * theFrame.width, 0));
            ofEndShape(true);
            
            ofSetColor(myColorCloud.six[ofWrap(i * 2 + 1, 0, 6)]);
            ofBeginShape();
            ofVertex(theFrame.getTopRight() + ofPoint(0, value3 * theFrame.height));
            ofVertex(theFrame.getTopLeft() + ofPoint(value0 * theFrame.width, 0));
            ofVertex(theFrame.getTopRight());
            ofEndShape(true);
            
            ofSetColor(myColorCloud.six[ofWrap((i + 1) * 2 + 1, 0, 6)]);
            ofBeginShape();
            ofVertex(theFrame.getBottomRight());
            ofVertex(theFrame.getBottomLeft() + ofPoint(value2 * theFrame.width, 0));
            ofVertex(theFrame.getTopRight() + ofPoint(0, value3 * theFrame.height));
            ofEndShape(true);
                
            /*ofDrawLine(theFrame.getTopLeft() + ofPoint(value0 * theFrame.width, 0), theFrame.getBottomLeft() + ofPoint(value2 * theFrame.width, 0));
            ofDrawLine(theFrame.getTopLeft() + ofPoint(0, value1 * theFrame.height), theFrame.getTopRight() + ofPoint(0, value3 * theFrame.height));*/
            
            i++;
        }
    }
    
    ofPopStyle();
}
