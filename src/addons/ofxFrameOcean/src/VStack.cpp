#include "VStack.h"

//--------------------------------------------------------------
vector<ofRectangle> VStack::get(ofRectangle frame_, float height_, float spacing_, float position_) {
    
    vector<ofRectangle> frames;
    
    for (float y = frame_.getTop() + ofWrap(position_, -height_, spacing_); y < frame_.getBottom(); y += height_ + spacing_) {
        frames.push_back(ofRectangle(frame_.x, y, frame_.width, height_));
    }
    
    return frames;
}

//--------------------------------------------------------------
vector<ofRectangle> VStack::get(ofRectangle frame_, int count_, float margin_, float position_) {
 
    vector<ofRectangle> frames;
    
    float height = (frame_.height - (margin_ * (count_ - 1))) / (float)count_;
    float y = frame_.y + ((position_ == margin_) ? position_ : ofWrap(position_, -height, margin_));
    for (int i = 0; i < count_; i++) {
        frames.push_back(ofRectangle(frame_.x, y, frame_.width, height));
        y += height + margin_;
    }
    
    return frames;
}

//--------------------------------------------------------------
vector<ofRectangle> VStack::get(ofRectangle frame_, vector<float> weights_, float spacing_) {
 
    vector<ofRectangle> frames;
    
    int count = (int)weights_.size();
    
    float y = frame_.y;
    for (int i = 0; i < count; i++) {
        float height = (frame_.height - (spacing_ * (count - 1))) * (weights_[i] / ofxTskokmtMath::sum(weights_));
        if (height < 0) height = 0;
        frames.push_back(ofRectangle(frame_.x, y, frame_.width, height));
        y += height + spacing_;
    }
    
    return frames;
}
