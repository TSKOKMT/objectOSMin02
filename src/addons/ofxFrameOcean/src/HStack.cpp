#include "HStack.h"

//--------------------------------------------------------------
vector<ofRectangle> HStack::get(ofRectangle frame_, float width_, float spacing_, float position_) {
    
    vector<ofRectangle> frames;
    
    for (float x = frame_.getLeft() + ofWrap(position_, -width_, spacing_); x < frame_.getRight(); x += width_ + spacing_) {
        frames.push_back(ofRectangle(x, frame_.y, width_, frame_.height));
    }
    
    return frames;
}

//--------------------------------------------------------------
vector<ofRectangle> HStack::get(ofRectangle frame_, int count_, float spacing_, float position_) {
    
    vector<ofRectangle> frames;
    
    float width = (frame_.width - (spacing_ * (count_ - 1))) / (float)count_;
    float x = frame_.x + ((position_ == spacing_) ? spacing_ : ofWrap(position_, -width, spacing_));
    for (int i = 0; i < count_; i++) {
        frames.push_back(ofRectangle(x, frame_.y, width, frame_.height));
        x += width + spacing_;
    }
    
    return frames;
}

//--------------------------------------------------------------
vector<ofRectangle> HStack::get(ofRectangle frame_, vector<float> weights_, float spacing_) {
 
    vector<ofRectangle> frames;
    
    int count = (int)weights_.size();
    
    float x = frame_.x;
    for (int i = 0; i < count; i++) {
        float width = (frame_.width - (spacing_ * (count - 1))) * (weights_[i] / ofxTskokmtMath::sum(weights_));
        if (width < 0) width = 0;
        frames.push_back(ofRectangle(x, frame_.y, width, frame_.height));
        x += width + spacing_;
    }
    
    return frames;
}
