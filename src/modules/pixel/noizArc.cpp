#include "noizArc.h"

//--------------------------------------------------------------
noizArc::noizArc() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void noizArc::draw(ofTexture texture_, float time_) {
    
    ofRectangle videoFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
 
    float unit = sqrt(videoFrame.width * videoFrame.height) / 120.;
    
    float side_ = videoFrame.height / (float)count;

    ofFbo fbo;
    fbo.allocate(videoFrame.width, videoFrame.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform2f("size", videoFrame.width, videoFrame.height);
    shader.setUniform1f("side", side_);
    ofDrawRectangle(videoFrame);
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
    
}
