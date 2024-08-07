#include "synMeme.h"

//--------------------------------------------------------------
synMeme::synMeme() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void synMeme::draw(ofTexture texture_, float time_) {
    
    ofRectangle videoFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
 
    float unit = sqrt(videoFrame.width * videoFrame.height) / 120.;
    
    ofPoint center = videoFrame.getCenter();
    float amount = ofSignedNoise(time_ / 5.) * 3;
    float amount2 = ofSignedNoise(time_ / 5., PI) * 3;

    ofFbo fbo;
    fbo.allocate(videoFrame.width, videoFrame.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform2f("center", center.x, center.y);
    shader.setUniform1f("count", count);
    shader.setUniform1f("rotation", time_ / -12. * TWO_PI);
    shader.setUniform1f("innerRotation", time_ / 24. * TWO_PI);
    shader.setUniform1f("scale0", 1);
    shader.setUniform1f("scale1", ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 2));
    ofDrawRectangle(videoFrame);
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
}
