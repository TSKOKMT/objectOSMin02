#include "marginBand.h"

//--------------------------------------------------------------
ofRectangle marginBand::get(ofRectangle frame_, ofPoint margin_) {
    
    frame_.position += margin_;
    frame_.width -= margin_.x * 2;
    frame_.height -= margin_.y * 2;
    
    if (frame_.width < 0) frame_.width = 0;
    if (frame_.height < 0) frame_.height = 0;
    
    return frame_;
}

//--------------------------------------------------------------
ofRectangle marginBand::get(ofRectangle frame_, float margin_) {
 
    return get(frame_, ofPoint(margin_, margin_));
}
