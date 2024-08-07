#include "criticalWindow.h"

//--------------------------------------------------------------
criticalWindow::criticalWindow() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void criticalWindow::draw(ofTexture texture_, float time_) {
    
    ofRectangle videoFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
 
    float unit = sqrt(videoFrame.width * videoFrame.height) / 120.;
    
    ofPoint center = videoFrame.getCenter()/* + ofPoint(ofSignedNoise(time / 12.), ofSignedNoise(time / 12., PI)) * 30 * unit*/;
    float side = 12 * unit;
    float length = ofNormalize(sin(time_ / 3.), -1, 1) * videoFrame.width;
    
    ofFbo fbo;
    fbo.allocate(videoFrame.width, videoFrame.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform2f("center", center.x, center.y);
    shader.setUniform1f("side", side);
    shader.setUniform1f("length", length);
    shader.setUniform1i("b", (int)(time_ / interval) % 2);
    ofDrawRectangle(videoFrame);
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
}
