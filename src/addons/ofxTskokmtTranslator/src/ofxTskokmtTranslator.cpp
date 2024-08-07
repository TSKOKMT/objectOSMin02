#include "ofxTskokmtTranslator.h"

//--------------------------------------------------------------
void ofxTskokmtTranslator::translate(float x_, float y_) {
    
    ofTranslate(x_, y_);
    
    translatingX += x_ * scalingX, translatingY += y_ * scalingY;
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::translate(ofPoint p_) {
    
    translate(p_.x, p_.y);
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::scale(float x_, float y_) {
    
    ofScale(x_, y_);
    
    scalingX *= x_, scalingY *= y_;
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::scale(ofPoint p_) {
    
    scale(p_.x, p_.y);
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::mirrorX(float center_) {
    
    translate(2 * getDisTranslatedPosition(center_, 0).x, 0);
    scale(-1, 1);
    
    isMirroringX = true;
    
    centerX = center_;
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::mirrorX() {
    
    mirrorX(ofGetWidth() / 2.);
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::mirrorY(float center_) {
    
    translate(0, 2 * getDisTranslatedPosition(center_, 0).y);
    scale(1, -1);
    
    isMirroringY = true;
    
    centerY = center_;
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::mirrorY() {
    
    mirrorY(ofGetHeight() / 2.);
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::fit(ofRectangle sourceRect, ofRectangle targetRect) {
    
    translate(targetRect.x, targetRect.y);
    scale(targetRect.width / sourceRect.width, targetRect.height / sourceRect.height);
    translate(-sourceRect.x, -sourceRect.y);
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::disFit(ofRectangle sourceRect, ofRectangle targetRect) {
    
    translate(sourceRect.x, sourceRect.y);
    scale(sourceRect.width / targetRect.width, sourceRect.height / targetRect.height);
    translate(-targetRect.x, -targetRect.y);
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::smartFit(ofRectangle sourceRect, ofRectangle targetRect) {
    
    if (sourceRect.width / sourceRect.height < targetRect.width / targetRect.height) {
        smartFittedRectangle = ofRectangle(targetRect.x + (targetRect.width - targetRect.height * (sourceRect.width / sourceRect.height)) / 2., targetRect.y, targetRect.height * (sourceRect.width / sourceRect.height), targetRect.height);
    } else {
        smartFittedRectangle = ofRectangle(targetRect.x, targetRect.y + (targetRect.height - targetRect.width * (sourceRect.height / sourceRect.width)) / 2., targetRect.width, targetRect.width * (sourceRect.height / sourceRect.width));
    }
    smartFittedRectangle.x -= sourceRect.x * (smartFittedRectangle.width / sourceRect.width);
    smartFittedRectangle.y -= sourceRect.y * (smartFittedRectangle.width / sourceRect.width);
    
    translate(smartFittedRectangle.x, smartFittedRectangle.y);
    scale(smartFittedRectangle.width / sourceRect.width, smartFittedRectangle.width / sourceRect.width);
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::disSmartFit(ofRectangle sourceRect_, ofRectangle targetRect_) {

    scale(sourceRect_.getWidth() / getSmartFittedRectangle(sourceRect_, targetRect_).width, sourceRect_.getWidth() / getSmartFittedRectangle(sourceRect_, targetRect_).width);
    translate(-getSmartFittedRectangle(sourceRect_, targetRect_).position);
}

//--------------------------------------------------------------
ofRectangle ofxTskokmtTranslator::getSmartFittedRectangle() {

    return smartFittedRectangle;
}

//--------------------------------------------------------------
ofRectangle ofxTskokmtTranslator::getSmartFittedRectangle(ofRectangle sourceRect_, ofRectangle targetRect_) {
    
    ofRectangle rect;
    
    if (sourceRect_.width / sourceRect_.height < targetRect_.width / targetRect_.height) {
        rect = ofRectangle(targetRect_.x + (targetRect_.width - targetRect_.height * (sourceRect_.width / sourceRect_.height)) / 2., targetRect_.y, targetRect_.height * (sourceRect_.width / sourceRect_.height), targetRect_.height);
    } else {
        rect = ofRectangle(targetRect_.x, targetRect_.y + (targetRect_.height - targetRect_.width * (sourceRect_.height / sourceRect_.width)) / 2., targetRect_.width, targetRect_.width * (sourceRect_.height / sourceRect_.width));
    }
    
    return rect;
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::smartFill(ofRectangle sourceRect, ofRectangle targetRect) {
    
    if (sourceRect.width / sourceRect.height < targetRect.width / targetRect.height) {
        smartFilledRectangle = ofRectangle(targetRect.x, targetRect.y + (targetRect.height - targetRect.width * (sourceRect.height / sourceRect.width)) / 2., targetRect.width, targetRect.width * (sourceRect.height / sourceRect.width));
    } else {
        smartFilledRectangle = ofRectangle(targetRect.x + (targetRect.width - targetRect.height * (sourceRect.width / sourceRect.height)) / 2., targetRect.y, targetRect.height * (sourceRect.width / sourceRect.height), targetRect.height);
    }
    
    translate(smartFilledRectangle.x, smartFilledRectangle.y);
    scale(smartFilledRectangle.width / sourceRect.width, smartFilledRectangle.width / sourceRect.width);
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::disSmartFill(ofRectangle sourceRect_, ofRectangle targetRect_) {
    
    scale(sourceRect_.getWidth() / getSmartFilledRectangle(sourceRect_, targetRect_).width, sourceRect_.getWidth() / getSmartFilledRectangle(sourceRect_, targetRect_).width);
    translate(-getSmartFilledRectangle(sourceRect_, targetRect_).position);
}

//--------------------------------------------------------------
ofRectangle ofxTskokmtTranslator::getSmartFilledRectangle() {
 
    return smartFilledRectangle;
}

//--------------------------------------------------------------
ofRectangle ofxTskokmtTranslator::getSmartFilledRectangle(ofRectangle sourceRect_, ofRectangle targetRect_) {
    
    ofRectangle rect;
    
    if (sourceRect_.width / sourceRect_.height < targetRect_.width / targetRect_.height) {
        rect = ofRectangle(targetRect_.x, targetRect_.y + (targetRect_.height - targetRect_.width * (sourceRect_.height / sourceRect_.width)) / 2., targetRect_.width, targetRect_.width * (sourceRect_.height / sourceRect_.width));
    } else {
        rect = ofRectangle(targetRect_.x + (targetRect_.width - targetRect_.height * (sourceRect_.width / sourceRect_.height)) / 2., targetRect_.y, targetRect_.height * (sourceRect_.width / sourceRect_.height), targetRect_.height);
    }
    
    return rect;
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::smartisticFit(ofRectangle sourceRect, ofRectangle targetRect) {
    
    float max = 9 / 16.;
    float ratio = (sourceRect.height - sourceRect.width) / sourceRect.width;
    float beginRatio = (targetRect.height - targetRect.width * max) / (targetRect.width * max);
    float endRatio = (targetRect.height * max - targetRect.width) / targetRect.width;
    float position = ofMap(ratio, beginRatio, endRatio, 0, 1);
    if (0 <= position && position <= 1) {
        float height = ofMap(position, 0, 1, targetRect.height, targetRect.height * max);
        float width = height * (sourceRect.width / sourceRect.height);
        smartisticFittedRectangle = ofRectangle(targetRect.x + (targetRect.width - width) / 2., targetRect.y + (targetRect.height - height) / 2., width, height);
    } else {
        smartisticFittedRectangle = getSmartFittedRectangle(sourceRect, targetRect);
    }
    
    translate(smartisticFittedRectangle.x, smartisticFittedRectangle.y);
    scale(smartisticFittedRectangle.width / sourceRect.width, smartisticFittedRectangle.width / sourceRect.width);
}

//--------------------------------------------------------------
ofPoint ofxTskokmtTranslator::getTranslatedPosition(float valueX_, float valueY_) {
    
    valueX_ *= scalingX, valueY_ *= scalingY;
    
    valueX_ += translatingX, valueY_ += translatingY;
    
    return ofPoint(valueX_ ,valueY_);
}

//--------------------------------------------------------------
ofPoint ofxTskokmtTranslator::getTranslatedPosition(ofPoint value_) {
    
    return getTranslatedPosition(value_.x, value_.y);
}

//--------------------------------------------------------------
ofPoint ofxTskokmtTranslator::getDisTranslatedPosition(float valueX_, float valueY_) {
    
    valueX_ -= translatingX, valueY_ -= translatingY;
    
    valueX_ /= scalingX, valueY_ /= scalingY;
    
    return ofPoint(valueX_ ,valueY_);
}

//--------------------------------------------------------------
ofPoint ofxTskokmtTranslator::getDisTranslatedPosition(ofPoint value_) {
    
    return getDisTranslatedPosition(value_.x, value_.y);
}

//--------------------------------------------------------------
ofPoint ofxTskokmtTranslator::getTranslatedPosition(float valueX, float valueY, ofRectangle sourceRect, ofRectangle targetRect) {
    
    return ofPoint(ofMap(valueX, sourceRect.x, sourceRect.x + sourceRect.width, targetRect.x, targetRect.x + targetRect.width), ofMap(valueY, sourceRect.y, sourceRect.y + sourceRect.height, targetRect.y, targetRect.y + targetRect.height));
}

//--------------------------------------------------------------
ofPoint ofxTskokmtTranslator::getTranslatedPosition(ofPoint valueP, ofRectangle sourceRect, ofRectangle targetRect) {
    
    return getTranslatedPosition(valueP.x, valueP.y, sourceRect, targetRect);
}

//--------------------------------------------------------------
void ofxTskokmtTranslator::reset() {
    
    translatingX = 0, translatingY = 0;
    scalingX = 1, scalingY = 1;
    isMirroringX = false, isMirroringY = false;
}

