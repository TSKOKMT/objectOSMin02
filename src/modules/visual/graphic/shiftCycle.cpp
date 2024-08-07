#include "shiftCycle.h"

//--------------------------------------------------------------
void shiftCycle::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float margin_ = margin * unit;
    
    previousTime = time;
    time = time_;
    
    if (previousRatios.size() != count_) {
        previousRatios.resize(count_);
        nextRatios.resize(count_);
    }
    
    float motion = ofClamp(ofWrap(time_, 0, interval_) / term_, 0, 1);
    motion = ofxTskokmtMath::cubicBezierByX(ofPoint(.8, 0), ofPoint(.2, 1), motion);
    
    if (ofWrap(time, 0, interval_) < ofWrap(previousTime, 0, interval_)) {
        previousRatios = nextRatios;
        for (int r = 0; r < nextRatios.size(); r++) {
            nextRatios[r] = ofRandom(1);
        }
    }
    
    vector<float> ratios;
    ratios.resize(count_);
    for (int r = 0; r < ratios.size(); r++) {
        ratios[r] = ofLerp(previousRatios[r], nextRatios[r], motion);
    }
    
    auto frameM = marginBand::get(frame_, margin_);
    
    auto framesH = HStack::get(frameM, ratios, margin_);
    
    //DRAW
    
    ofPushStyle();
    
    for (int h = 0; h < framesH.size(); h++) {
        //ofDrawCircle(framesH[h].getCenter(), framesH[h].width / 2.);
        ofPushMatrix();
        ofTranslate(framesH[h].getCenter());
        if (h % 2 == 0) ofScale(-1, 1);
        
        ofSetColor(myColorCloud.six[h % 6]);
        ofDrawTriangle(-framesH[h].width / 2., -framesH[h].width / 2. * (2 / sqrt(3)), -framesH[h].width / 2., framesH[h].width / 2. * (2 / sqrt(3)), framesH[h].width / 2., 0);
        
        ofPopMatrix();
    }
    
    ofPopStyle();
}
