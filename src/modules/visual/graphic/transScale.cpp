#include "transScale.h"

//--------------------------------------------------------------
void transScale::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
        
    int countH = round(frame_.width / (side * unit));
    int countV = round(frame_.height / (side * unit));
    
    balancesX.resize(countH);
    balancesY.resize(countV);
    
    ofPoint point;
    point.x = ofSignedNoise(time_ / 3., 0);
    point.y = ofSignedNoise(time_ / 3., PI);
    
    float sum = 0;
    for (int i = 0; i < balancesX.size(); i++) {
        //balancesX[i] = ofNoise(time / PI + i);
        balancesX[i] = pow(i / (float)balancesX.size() * point.x + 1, 16);
        sum += balancesX[i];
    }
    for (int i = 0; i < balancesX.size(); i++) {
        balancesX[i] /= sum;
    }
    
    sum = 0;
    for (int i = 0; i < balancesY.size(); i++) {
        //balancesY[i] = ofNoise(time / PI - i);
        //balancesY[i] = pow(i / (float)balancesY.size(), 2);
        balancesY[i] = pow(i / (float)balancesY.size() * point.y + 1, 16);
        sum += balancesY[i];
    }
    for (int i = 0; i < balancesY.size(); i++) {
        balancesY[i] /= sum;
    }
    
    //DRAW
    
    ofPushMatrix();
    ofTranslate(frame_.position);
    /*ofTranslate(frame.width / 3., frame.height / 3.);
    ofScale(frame.width / 3., frame.height / 3.);*/
    //ofScale(frame.width, frame.height);
    
    ofPushStyle();
    //ofNoFill();
    
    int i = 0;
    float yy = 0;
    for (int y = 0; y < balancesY.size(); y++) {
        float xx = 0;
        for (int x = 0; x < balancesX.size(); x++) {
            //if (x % 2 == y % 2) ofDrawRectangle(xx, yy, balancesX[x], balancesY[y]);
            
            if (x % 2 == y % 2) {
                ofSetColor(myColorCloud.six[i % 6]);
                ofDrawCircle((xx + balancesX[x] / 2.) * frame_.width, (yy + balancesY[y] / 2.) * frame_.height, pow(balancesX[x] * frame_.width * balancesY[y] * frame_.height, .75) / 18.);
                
                i++;
            }
            
            /*ofDrawLine(xx, yy, xx + balancesX[x], yy + balancesY[y]);
            ofDrawLine(xx, yy + balancesY[y], xx + balancesX[x], yy);*/
            
            /*ofBeginShape();
            ofVertex(xx, yy);
            ofVertex(xx + balancesX[x], yy + balancesY[y]);
            ofVertex(xx, yy + balancesY[y]);
            ofVertex(xx + balancesX[x], yy);*
            ofEndShape(true);*/
            
            xx += balancesX[x];
        }
        yy += balancesY[y];
    }
    
    /*float yy = 0;
    for (int y = 0; y < balancesY.size() + 1; y++) {
        ofDrawLine(-10000, yy, 10000, yy);
        yy += balancesY[y];
    }
    float xx = 0;
    for (int x = 0; x < balancesX.size() + 1; x++) {
        ofDrawLine(xx, -10000, xx, 10000);
        xx += balancesX[x];
    }*/
    
    ofPopStyle();
    
    ofPopMatrix();
}
