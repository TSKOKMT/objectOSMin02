#include "rollingRoll.h"

//--------------------------------------------------------------
rollingRoll::rollingRoll() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void rollingRoll::draw(ofTexture texture_, float time_) {
    
    ofRectangle videoFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
 
    float unit = sqrt(videoFrame.width * videoFrame.height) / 120.;
    
    float interval = 12 * unit;
    ofPoint center = videoFrame.getCenter()/* + ofPoint(ofSignedNoise(time_ / 9.), ofSignedNoise(time_ / 9., PI)) * 12 * interval*/;
    float rotation0 = ofSignedNoise(time_ / 30.) * PI;
    float rotation1 = ofSignedNoise(time_ / 30., PI * 100) * TWO_PI;
    float rotation2 = ofSignedNoise(time_ / 30., PI * 200) * PI;
    
    if (rotation0 < 0) rotation0 = 0;
    if (rotation1 > 0) rotation1 = 0;
    if (rotation2 < 0) rotation2 = 0;

    ofFbo fbo;
    fbo.allocate(videoFrame.width, videoFrame.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform2f("center", center.x, center.y);
    shader.setUniform1f("interval", interval);
    shader.setUniform1f("rotation0", rotation0);
    shader.setUniform1f("rotation1", rotation1);
    shader.setUniform1f("rotation2", rotation2);
    ofDrawRectangle(videoFrame);
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
}
