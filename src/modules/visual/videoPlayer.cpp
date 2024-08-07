#include "videoPlayer.h"

//--------------------------------------------------------------
videoPlayer::videoPlayer() {
    
    video.setLoopState(OF_LOOP_NORMAL);
}

//--------------------------------------------------------------
void videoPlayer::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    video.setSpeed(speed);
    video.update();
    
    //DRAW
    
    ofPushMatrix();
    translator.smartFit(ofRectangle(0, 0, video.getWidth(), video.getHeight()), frame_);
    
    video.draw(0, 0);
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void videoPlayer::load(string path_) {
    
    if (path_ == path) return;
    path = path_;
    
    video.load(path_);
    video.play();
}
