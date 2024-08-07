#include "rapFlee.h"

//--------------------------------------------------------------
rapFlee::rapFlee() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void rapFlee::draw(ofTexture texture_, float time_) {
    
    ofRectangle videoFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
 
    float unit = sqrt(videoFrame.width * videoFrame.height) / 120.;
    
    float motion = sin(time_ / term * TWO_PI);
    motion = sin(motion * HALF_PI);
    
    ofPoint position = videoFrame.getCenter() + ofPoint(ofSignedNoise(time_ / 2.), ofSignedNoise(time_ / 2., PI)) * 60 * unit;
    ofPoint length = ofPoint(ofClamp(motion, 0, 1), ofClamp(-motion, 0, 1)) * 60 * unit;

    ofFbo fbo;
    fbo.allocate(videoFrame.width, videoFrame.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform2f("position", position.x, position.y);
    shader.setUniform2f("length", length.x, length.y);
    ofDrawRectangle(videoFrame);
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
}
