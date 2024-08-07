#include "colorWorld.h"

//--------------------------------------------------------------
colorWorld::colorWorld() {
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
    
    palette.resize(6);
    palette[0] = ofColor(255, 0, 0);
    palette[1] = ofColor(255, 255, 0);
    palette[2] = ofColor(0, 255, 0);
    palette[3] = ofColor(0, 255, 255);
    palette[4] = ofColor(0, 0, 255);
    palette[5] = ofColor(255, 0, 255);
}

//--------------------------------------------------------------
void colorWorld::draw(ofTexture texture_) {
    
    ofRectangle textureFrame = ofRectangle(0, 0, texture_.getWidth(), texture_.getHeight());
    
    vector<ofColor> sixColors;
    sixColors.resize(6);
    for (int i = 0; i < sixColors.size(); i++) {
        sixColors[i] = palette[i % (int)palette.size()];
    }
    
    shader.begin();
    shader.setUniformTexture("texture", texture_, 0);
    shader.setUniform3f("color0", sixColors[0].r / 255., sixColors[0].g / 255., sixColors[0].b / 255.);
    shader.setUniform3f("color0_5", sixColors[1].r / 255., sixColors[1].g / 255., sixColors[1].b / 255.);
    shader.setUniform3f("color1", sixColors[2].r / 255., sixColors[2].g / 255., sixColors[2].b / 255.);
    shader.setUniform3f("color1_5", sixColors[3].r / 255., sixColors[3].g / 255., sixColors[3].b / 255.);
    shader.setUniform3f("color2", sixColors[4].r / 255., sixColors[4].g / 255., sixColors[4].b / 255.);
    shader.setUniform3f("color2_5", sixColors[5].r / 255., sixColors[5].g / 255., sixColors[5].b / 255.);
    ofDrawRectangle(textureFrame);
    shader.end();
}
