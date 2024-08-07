#include "boredomWindow.h"

//--------------------------------------------------------------
boredomWindow::boredomWindow() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void boredomWindow::draw(ofTexture texture_, float time_) {
    
    ofRectangle videoFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
 
    float unit = sqrt(videoFrame.width * videoFrame.height) / 120.;
    
    ofPoint center = videoFrame.getCenter()/* + ofPoint(ofSignedNoise(time / 12.), ofSignedNoise(time / 12., PI)) * 30 * unit*/;
    float side = 12 * unit;
    float rotation = ofMap(cos(ofWrap(time_ / 9., 0, 1) * PI), 1, -1, 0, TWO_PI);
    
    ofFbo fbo;
    fbo.allocate(videoFrame.width, videoFrame.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform2f("center", center.x, center.y);
    shader.setUniform1f("side", side);
    shader.setUniform1f("rotation", rotation);
    ofDrawRectangle(videoFrame);
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
}
