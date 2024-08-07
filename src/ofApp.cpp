#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    //ofSetWindowShape(ofGetScreenWidth() * (16 / 18.), ofGetScreenWidth() / 2.);
    ofSetWindowShape(640, 360);
    ofSetWindowPosition((ofGetScreenWidth() - ofGetWidth()) / 2., (ofGetScreenHeight() - ofGetHeight()) / 2.);
    ofBackground(0);
    ofSetCircleResolution(60);
    ofSetLineWidth(4);
    ofSetCylinderResolution(30, 1);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetWindowTitle("OBJECT OS | FPS " + ofToString(round(ofGetFrameRate())));
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    auto frame = ofGetWindowRect();
    
    auto time = ofGetElapsedTimef();
    
    auto unit = sqrt(frame.width * frame.height) / 120.;
    
    myObjectOS.draw(frame, time);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == OF_KEY_RIGHT) myObjectOS.nextGraphic();
    if (key == OF_KEY_LEFT) myObjectOS.previousGraphic();
    
    if (key == OF_KEY_UP) myObjectOS.screenIndex = ofWrap(myObjectOS.screenIndex + 1, 0, 5);
    if (key == OF_KEY_DOWN) myObjectOS.screenIndex = ofWrap(myObjectOS.screenIndex - 1, 0, 5);
    
    if (key == 'x') myObjectOS.pixelIndex = ofWrap(myObjectOS.pixelIndex + 1, 0, 11);
    if (key == 'z') myObjectOS.pixelIndex = ofWrap(myObjectOS.pixelIndex - 1, 0, 11);
    
    if (key == 'p') myObjectOS.nextVideo();
    if (key == 'o') myObjectOS.previousVideo();
    
    if (key == 'm') myObjectOS.coverIndex = ofWrap(myObjectOS.coverIndex + 1, 0, 4);
    if (key == 'n') myObjectOS.coverIndex = ofWrap(myObjectOS.coverIndex - 1, 0, 4);
    
    if (key == '1') myObjectOS.setColorMono();
    if (key == '2') myObjectOS.setColorRGBTwo();
    if (key == '3') myObjectOS.setColorRGBWorld();
    if (key == '4') myObjectOS.setColorSakamotoTwo();
    if (key == '5') myObjectOS.setColorSakamotoWorld();
    if (key == '6') myObjectOS.setColorIkkoTwo();
    if (key == '7') myObjectOS.setColorIkkoWorld();
    if (key == '8') myObjectOS.paletteShift++;
    if (key == '9') myObjectOS.paletteShiftTerm = 1;
    if (key == '0') myObjectOS.paletteShiftTerm = -1;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
