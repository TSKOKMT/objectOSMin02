#include "objectOS.h"

//--------------------------------------------------------------
objectOS::objectOS() {
    
    setColorMono();
}

//--------------------------------------------------------------
void objectOS::draw(ofRectangle frame_, float time_) {
    
    newTime_ += (time_ - previousTime) * (125 / 60.);
    if (frameRate > 0) newTime_ = floor(newTime_ * frameRate) / (float)frameRate;
    
    previousTime = time_;
    
    if (paletteShiftTerm > 0) paletteShift = floor(newTime_ / paletteShiftTerm);
    
    //Set screens
    vector<ofRectangle> screens;
    if (screenIndex == 0) screens.push_back(frame_);
    else if (screenIndex == 1) screens = myVipGrid.get(frame_, newTime_);
    else if (screenIndex == 2) screens = mySlideGrid.get(frame_, newTime_);
    else if (screenIndex == 3) screens = myPushGrid.get(frame_, newTime_);
    else screens = myEmergeScreen.get(frame_, newTime_);
    
    //Set video
    if (moduleIndex == 37) myVideoPlayer.load(myVideoCloud.pathes[videoIndex]);
    
    //Create & begin fbo
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    
    //Draw module
    for (int i = 0; i < screens.size(); i++) {
        auto screen = screens[i];
        
        float newTime = newTime_ - i * screenDelay;
     
        //graphic
        if (moduleIndex == 0) myAndThen.draw(screen, newTime);
        if (moduleIndex == 1) myBadMode.draw(screen, newTime);
        if (moduleIndex == 2) myBigDot.draw(screen, newTime);
        if (moduleIndex == 3) myBigThree.draw(screen, newTime);
        if (moduleIndex == 4) myBluBar.draw(screen, newTime);
        if (moduleIndex == 5) myBluBlu.draw(screen, newTime);
        if (moduleIndex == 6) myDarlingApp.draw(screen, newTime);
        if (moduleIndex == 7) myEmergeMulti.draw(screen, newTime);
        if (moduleIndex == 8) myFallFree.draw(screen, newTime);
        if (moduleIndex == 9) myFlagCheck.draw(screen, newTime);
        if (moduleIndex == 10) myFragMent.draw(screen, newTime);
        if (moduleIndex == 11) myGoldenDisc.draw(screen, newTime);
        if (moduleIndex == 12) myHuntRabbit.draw(screen, newTime);
        if (moduleIndex == 13) myIcoIcon.draw(screen, newTime);
        if (moduleIndex == 14) myKeenPublic.draw(screen, newTime);
        if (moduleIndex == 15) myKeepDistance.draw(screen, newTime);
        if (moduleIndex == 16) myKickBack.draw(screen, newTime);
        if (moduleIndex == 17) myLongDistance.draw(screen, newTime);
        if (moduleIndex == 18) myMoonShot.draw(screen, newTime);
        if (moduleIndex == 19) myNotionTation.draw(screen, newTime);
        if (moduleIndex == 20) myNuWit.draw(screen, newTime);
        if (moduleIndex == 21) myPointShoot.draw(screen, newTime);
        if (moduleIndex == 22) myPolyPoli.draw(screen, newTime);
        if (moduleIndex == 23) myReCenter.draw(screen, newTime);
        if (moduleIndex == 24) myShiftCycle.draw(screen, newTime);
        if (moduleIndex == 25) myShopBot.draw(screen, newTime);
        if (moduleIndex == 26) mySpanningCole.draw(screen, newTime);
        if (moduleIndex == 27) mySuperFlat.draw(screen, newTime);
        if (moduleIndex == 28) myTheyMove.draw(screen, newTime);
        if (moduleIndex == 29) myTogeToge.draw(screen, newTime);
        if (moduleIndex == 30) myTransScale.draw(screen, newTime);
        if (moduleIndex == 31) myTrickMe.draw(screen, newTime);
        if (moduleIndex == 32) myTryAngle.draw(screen, newTime);
        if (moduleIndex == 33) myTwoBall.draw(screen, newTime);
        if (moduleIndex == 34) myUnbalanceLance.draw(screen, newTime);
        if (moduleIndex == 35) myYoGreek.draw(screen, newTime);
        if (moduleIndex == 36) myZoomZoom.draw(screen, newTime);
        
        //video
        if (moduleIndex == 37) myVideoPlayer.draw(screen, newTime);
    }
    
    fbo.end();
    
    //palette
    vector<ofColor> palette;
    if (paletteIndex == 0) palette = myColorCloud.mono;
    else if (paletteIndex == 1) palette = myColorCloud.rgb;
    else if (paletteIndex == 2) palette = myColorCloud.six;
    else if (paletteIndex == 3) palette = myColorCloud.sakamoto;
    else palette = myColorCloud.ikko;
    
    auto paletteShelter = palette;
    for (int i = 0; i < palette.size(); i++) {
        palette[i] = paletteShelter[ofWrap(i + paletteShift, 0, (int)palette.size())];
    }

    //chrome
    ofFbo fboC;
    fboC.allocate(frame_.width, frame_.height, GL_RGB, 4);
    fboC.begin();
    ofClear(0);
    if (chromeIndex == 0) {
        fbo.draw(0, 0);
    }
    else if (chromeIndex == 1) {
        myTwoTone.color0 = palette[0];
        myTwoTone.color1 = palette[1];
        myTwoTone.draw(fbo.getTexture());
    }
    else {
        myColorWorld.palette = palette;
        myColorWorld.draw(fbo.getTexture());
    }
    fboC.end();
    
    //pixel
    if (pixelIndex == 0) fboC.draw(0, 0);
    else if (pixelIndex == 1) myBoredomWindow.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 2) myCriticalWindow.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 3) myFromDip.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 4) myRadioWindow.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 5) myNoizArc.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 6) myRapFlee.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 7) myRollingRoll.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 8) mySlitShut.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 9) mySynMeme.draw(fboC.getTexture(), newTime_);
    else myZigZig.draw(fboC.getTexture(), newTime_);
    
    //cover
    if (coverIndex == 0) {}
    else if (coverIndex == 1) myFlashCover.draw(frame_, newTime_);
    else if (coverIndex == 2) myOddCover.draw(frame_, newTime_);
    else if (coverIndex == 3) myPikaCover.draw(frame_, newTime_);
    else if (coverIndex == 4) myBlackCover.draw(frame_, newTime_);
}

//--------------------------------------------------------------
void objectOS::previousGraphic() {
    
    if (0 <= moduleIndex && moduleIndex < 37) moduleIndex = ofWrap(moduleIndex - 1, 0, 37);
    else moduleIndex = 37;
}
//--------------------------------------------------------------
void objectOS::nextGraphic() {
    
    if (0 <= moduleIndex && moduleIndex < 37) moduleIndex = ofWrap(moduleIndex + 1, 0, 37);
    else moduleIndex = 0;
}
//--------------------------------------------------------------
void objectOS::previousVideo() {
    
    if (moduleIndex == 37) videoIndex = ofWrap(videoIndex - 1, 0, myVideoCloud.pathes.size());
    moduleIndex = 37;
}
//--------------------------------------------------------------
void objectOS::nextVideo() {
    
    if (moduleIndex == 37) videoIndex = ofWrap(videoIndex + 1, 0, myVideoCloud.pathes.size());
    moduleIndex = 37;
}

//--------------------------------------------------------------
void objectOS::setColorNothing() {
    
    paletteIndex = 0;
    chromeIndex = 0;
}
//--------------------------------------------------------------
void objectOS::setColorMono() {
    
    paletteIndex = 0;
    chromeIndex = 1;
}
//--------------------------------------------------------------
void objectOS::setColorRGBTwo() {
    
    paletteIndex = 1;
    chromeIndex = 1;
}
//--------------------------------------------------------------
void objectOS::setColorRGBWorld() {
    
    paletteIndex = 1;
    chromeIndex = 2;
}
//--------------------------------------------------------------
void objectOS::setColorSakamotoTwo() {
    
    paletteIndex = 3;
    chromeIndex = 1;
}
//--------------------------------------------------------------
void objectOS::setColorSakamotoWorld() {
    
    paletteIndex = 3;
    chromeIndex = 2;
}
//--------------------------------------------------------------
void objectOS::setColorIkkoTwo() {
    
    paletteIndex = 4;
    chromeIndex = 1;
}
//--------------------------------------------------------------
void objectOS::setColorIkkoWorld() {
    
    paletteIndex = 4;
    chromeIndex = 2;
}

//--------------------------------------------------------------
void objectOS::previousPixel() {
    
    pixelIndex = ofWrap(pixelIndex - 1, 1, 11);
}
//--------------------------------------------------------------
void objectOS::nextPixel() {
    
    pixelIndex = ofWrap(pixelIndex + 1, 1, 11);
}
