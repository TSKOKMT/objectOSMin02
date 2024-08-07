#include "moonModule.h"

//--------------------------------------------------------------
void moonModule::draw(ofPoint position_, float innerRadius_, float outerRadius_, float rotation_, float beginAngle_, float endAngle_) {
    
    if (innerRadius_ <= 0) innerRadius_ = 0;
    if (outerRadius_ <= 0) outerRadius_ = 0;
    
    if (innerRadius_ >= outerRadius_) return;
    
    int resolution = 60;
        
    ofPushMatrix();
    ofTranslate(position_);
    ofRotateRad(rotation_);
    ofBeginShape();
    for (int j = 0; j <= resolution; j++) {
        float theAngle = ofMap(j, 0, resolution, beginAngle_, endAngle_);
        ofVertex(cos(theAngle) * innerRadius_, sin(theAngle) * innerRadius_);
    }
    for (int j = 0; j <= resolution; j++) {
        float theAngle = ofMap(j, 0, resolution, endAngle_, beginAngle_);
        ofVertex(cos(theAngle) * outerRadius_, sin(theAngle) * outerRadius_);
    }
    ofEndShape(true);
    ofPopMatrix();
}
