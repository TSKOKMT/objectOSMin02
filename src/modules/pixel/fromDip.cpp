#include "fromDip.h"

//--------------------------------------------------------------
fromDip::fromDip() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void fromDip::draw(ofTexture texture_, float time_) {
    
    ofRectangle videoFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
 
    float unit = sqrt(videoFrame.width * videoFrame.height) / 120.;
    
    ofPoint center = videoFrame.getCenter();
    float amount = ofSignedNoise(time_ * speed) * 3;
    float amount2 = ofSignedNoise(time_ * speed, PI) * 3;

    ofFbo fbo;
    fbo.allocate(videoFrame.width, videoFrame.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform2f("center", center.x, center.y);
    shader.setUniform1f("amount", amount);
    shader.setUniform1f("amount2", amount2);
    ofDrawRectangle(videoFrame);
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
}
