#pragma once

#include "ofMain.h"

class ofxTskokmtTranslator {
public:
    void translate(float x_, float y_);
    void translate(ofPoint p_);
    
    void scale(float x_, float y_);
    void scale(ofPoint p_);
    
    void mirrorX(float center_);
    void mirrorX();
    void mirrorY(float center_);
    void mirrorY();
    
    void fit(ofRectangle sourceRect, ofRectangle targetRect);
    void disFit(ofRectangle sourceRect, ofRectangle targetRect);
    
    void smartFit(ofRectangle sourceRect, ofRectangle targetRect);
    ofRectangle getSmartFittedRectangle();
    static ofRectangle getSmartFittedRectangle(ofRectangle sourceRec_t, ofRectangle targetRect_);
    
    void disSmartFit(ofRectangle sourceRect_, ofRectangle targetRect_);
    
    void smartFill(ofRectangle sourceRect, ofRectangle targetRect);
    ofRectangle getSmartFilledRectangle();
    static ofRectangle getSmartFilledRectangle(ofRectangle sourceRect_, ofRectangle targetRect_);
    
    void disSmartFill(ofRectangle sourceRect_, ofRectangle targetRect_);
    
    void smartisticFit(ofRectangle sourceRect, ofRectangle targetRect);
    
    ofPoint getTranslatedPosition(float valueX_, float valueY_);
    ofPoint getTranslatedPosition(ofPoint value_);
    ofPoint getDisTranslatedPosition(float valueX_, float valueY_);
    ofPoint getDisTranslatedPosition(ofPoint value_);
    static ofPoint getTranslatedPosition(float valueX, float valueY, ofRectangle sourceRect, ofRectangle targetRect);
    static ofPoint getTranslatedPosition(ofPoint valueP, ofRectangle sourceRect, ofRectangle targetRect);
    
    void reset();
    
    float translatingX = 0, translatingY = 0;
    float scalingX = 1, scalingY = 1;
    bool isMirroringX = false, isMirroringY = false;
    
private:
    float centerX, centerY;
    ofRectangle smartFittedRectangle;
    ofRectangle smartFilledRectangle;
    ofRectangle smartisticFittedRectangle;
};
