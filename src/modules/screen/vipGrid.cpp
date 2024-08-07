#include "vipGrid.h"

//--------------------------------------------------------------
vector<ofRectangle> vipGrid::get(ofRectangle frame_, float time_) {
    
    vector<ofRectangle> frames;
    
    auto unit = sqrt(frame_.width * frame_.height) / 120.;
    
    auto frameM = marginBand::get(frame_, margin * unit);
    
    auto framesH = HStack::get(frameM, countH, margin * unit);
    for (int h = 0; h < framesH.size(); h++) {
        auto framesV = VStack::get(framesH[h], framesH[h].width, margin * unit, speed * unit * time_);
        for (int v = 0; v < framesV.size(); v++) {
            frames.push_back(framesV[v]);
        }
    }
    
    return frames;
}
