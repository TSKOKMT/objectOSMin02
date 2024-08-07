#include "pushGrid.h"

//--------------------------------------------------------------
vector<ofRectangle> pushGrid::get(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float margin = margin_ * unit;
    
    //Set motion
    float motion = ofWrap(time_ / term, 0, 1);
    motion = ofxTskokmtMath::cubicBezierByX(ofPoint(.9, 0), ofPoint(.1, 1), motion);
    
    //Prepare ratios
    float previousTime = floor(time_ / term) * term;
    float nextTime = ceil(time_ / term) * term;
    vector<float> ratiosH;
    vector<vector<float>> ratiosV;
    ratiosH = lerp(generateRatios(countH, previousTime), generateRatios(countH, nextTime), motion);
    ratiosV.resize(countH);
    for (int h = 0; h < countH; h++) {
        ratiosV[h] = lerp(generateRatios(countV, previousTime + h + 1), generateRatios(countV, nextTime + h + 1), motion);
    }
    
    //RETURN
    
    vector<ofRectangle> frames;
    
    vector<float> widthes;
    vector<vector<float>> heights;
    widthes.resize(countH);
    heights.resize(countH);
    for (int h = 0; h < countH; h++) {
        widthes[h] = (frame_.width - margin * (countH + 1)) * ratiosH[h];
        heights[h].resize(countV);
        for (int v = 0; v < countV; v++) {
            heights[h][v] = (frame_.height - margin * (countV + 1)) * ratiosV[h][v];
        }
    }
    float positionX = frame_.x + margin;
    for (int h = 0; h < countH; h++) {
        float positionY = frame_.y + margin;
        for (int v = 0; v < countV; v++) {
            frames.push_back(ofRectangle(positionX, positionY, widthes[h], heights[h][v]));
            positionY += heights[h][v];
            positionY += margin;
        }
        positionX += widthes[h];
        positionX += margin;
    }
    
    return frames;
}

//--------------------------------------------------------------
vector<float> pushGrid::generateRatios(int size_, float seed_) {
    
    vector<float> ratios;
    ratios.resize(size_);
    
    float sum = 0;
    for (int i = 0; i < size_; i++) {
        float theSeed = seed_ * pow(PI, 6) + (i + PI) * 100 * PI;
        ratios[i] = ofWrap(theSeed, 0, 1);
        ratios[i] = ofLerp(.1, 1, ratios[i]);
        ratios[i] = pow(ratios[i], sqrt(countH * countV) / 2.);
        sum += ratios[i];
    }
    for (int i = 0; i < size_; i++) {
        ratios[i] /= sum;
    }
    
    return ratios;
}

//--------------------------------------------------------------
vector<float> pushGrid::lerp(vector<float> from_, vector<float> to_, float t_) {
    
    vector<float> result;
    
    result.resize(min((int)from_.size(), (int)to_.size()));
    for (int i = 0; i < result.size(); i++) {
        result[i] = ofLerp(from_[i], to_[i], t_);
    }
    
    return result;
}
