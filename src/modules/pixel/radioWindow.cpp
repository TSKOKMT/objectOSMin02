#include "radioWindow.h"

//--------------------------------------------------------------
radioWindow::radioWindow() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void radioWindow::draw(ofTexture texture_, float time_) {
    
    ofRectangle videoFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
 
    float unit = sqrt(videoFrame.width * videoFrame.height) / 120.;
    
    ofPoint center = videoFrame.getCenter();
    float amount = 60 * unit * pow(ofNoise(time_ * speed), 4);
    float length = 10 * unit;
    float phase = 21 * unit * time_ * speed2;

    ofFbo fbo;
    fbo.allocate(videoFrame.width, videoFrame.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform2f("center", center.x, center.y);
    shader.setUniform1f("amount", amount);
    shader.setUniform1f("length", length);
    shader.setUniform1f("phase", phase);
    ofDrawRectangle(videoFrame);
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
}
