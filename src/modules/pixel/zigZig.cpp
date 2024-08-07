#include "zigZig.h"

//--------------------------------------------------------------
zigZig::zigZig() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void zigZig::draw(ofTexture texture_, float time_) {
    
    ofRectangle videoFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
 
    float unit = sqrt(videoFrame.width * videoFrame.height) / 120.;
    
    float side = videoFrame.width / 4.;
    float slant = sin(time_ / 8. * TWO_PI);
    slant = sin(slant * HALF_PI);
    slant *= 3;

    ofFbo fbo;
    fbo.allocate(videoFrame.width, videoFrame.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform1f("side", side);
    shader.setUniform1f("slant", slant);
    ofDrawRectangle(videoFrame);
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
}
