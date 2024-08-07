#include "slitShut.h"

//--------------------------------------------------------------
slitShut::slitShut() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void slitShut::draw(ofTexture texture_, float time_) {
    
    ofRectangle videoFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
 
    float unit = sqrt(videoFrame.width * videoFrame.height) / 120.;
    
    float value = ofSignedNoise(time_ / 2.) * 10;
    float sizeH = videoFrame.height / 2. + ofSignedNoise(time_ / 4.) * 60 * unit;
    float sizeV = videoFrame.width / 2. + ofSignedNoise(time_ / 6.) * 60 * unit;

    ofFbo fbo;
    fbo.allocate(videoFrame.width, videoFrame.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform1f("value", value);
    shader.setUniform1f("sizeH", sizeH);
    shader.setUniform1f("sizeV", sizeV);
    ofDrawRectangle(videoFrame);
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
}
