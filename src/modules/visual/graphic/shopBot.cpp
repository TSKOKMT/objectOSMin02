#include "shopBot.h"

//--------------------------------------------------------------
shopBot::shopBot() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderText);
    shader.linkProgram();
}

//--------------------------------------------------------------
void shopBot::draw(ofRectangle frame_, float time_) {
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    ofColor color = myColorCloud.six[0];
    
    shader.begin();
    shader.setUniform1f("time", time_);
    shader.setUniform1f("unit", unit);
    shader.setUniform2f("center", frame_.getCenter());
    shader.setUniform3f("color", color.r / 255., color.g / 255., color.b / 255.);
    ofDrawRectangle(frame_);
    shader.end();
}
