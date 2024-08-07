#include "twoTone.h"

//--------------------------------------------------------------
twoTone::twoTone() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void twoTone::draw(ofTexture texture_) {
    
    ofRectangle textureFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
    
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform3f("color0", color0.r / 255., color0.g / 255., color0.b / 255.);
    shader.setUniform3f("color1", color1.r / 255., color1.g / 255., color1.b / 255.);
    ofDrawRectangle(textureFrame);
    shader.end();
}
