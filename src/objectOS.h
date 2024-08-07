#pragma once

#include "ofMain.h"

//screen
#include "vipGrid.h"
#include "slideGrid.h"
#include "pushGrid.h"
#include "emergeScreen.h"

//visual
#include "andThen.h"
#include "badMode.h"
#include "bigDot.h"
#include "bigThree.h"
#include "bluBar.h"
#include "bluBlu.h"
#include "darlingApp.h"
#include "emergeMulti.h"
#include "fallFree.h"
#include "flagCheck.h"
#include "fragMent.h"
#include "goldenDisc.h"
#include "huntRabbit.h"
#include "icoIcon.h"
#include "keenPublic.h"
#include "keepDistance.h"
#include "kickBack.h"
#include "longDistance.h"
#include "moonShot.h"
#include "notionTation.h"
#include "nuWit.h"
#include "pointShoot.h"
#include "polyPoli.h"
#include "reCenter.h"
#include "shiftCycle.h"
#include "shopBot.h"
#include "spanningCole.h"
#include "superFlat.h"
#include "theyMove.h"
#include "togeToge.h"
#include "transScale.h"
#include "trickMe.h"
#include "tryAngle.h"
#include "twoBall.h"
#include "unbalanceLance.h"
#include "yoGreek.h"
#include "zoomZoom.h"

#include "videoPlayer.h"

//video
#include "videoCloud.h"

//word
#include "wordCloud.h"

//pixel
#include "boredomWindow.h"
#include "criticalWindow.h"
#include "fromDip.h"
#include "radioWindow.h"
#include "noizArc.h"
#include "rapFlee.h"
#include "rollingRoll.h"
#include "slitShut.h"
#include "synMeme.h"
#include "zigZig.h"

//palette
#include "colorCloud.h"

//chrome
#include "twoTone.h"
#include "colorWorld.h"

//cover
#include "flashCover.h"
#include "oddCover.h"
#include "pikaCover.h"
#include "blackCover.h"

class objectOS {

public:
    objectOS();
    
    void draw(ofRectangle frame_, float time_);
    
    float newTime_ = 0;
    
    int screenIndex = 0;
    int videoIndex = 0;
    int moduleIndex = 0;
    int paletteIndex = 0;
    int chromeIndex = 0;
    int pixelIndex = 0;
    int coverIndex = 0;
    
    int frameRate = -1;
    int paletteShift = 0;
    float screenDelay = 0;
    float paletteShiftTerm = -1;
    
    //visual
    void previousGraphic();
    void nextGraphic();
    void previousVideo();
    void nextVideo();
    
    //color
    void setColorNothing();
    void setColorMono();
    void setColorRGBTwo();
    void setColorRGBWorld();
    void setColorSakamotoTwo();
    void setColorSakamotoWorld();
    void setColorIkkoTwo();
    void setColorIkkoWorld();
    
    //pixel
    void previousPixel();
    void nextPixel();
    
private:
    float previousTime = 0;
    
    //screen
    vipGrid myVipGrid;
    slideGrid mySlideGrid;
    pushGrid myPushGrid;
    emergeScreen myEmergeScreen;
    
    //module
    andThen myAndThen;
    badMode myBadMode;
    bigDot myBigDot;
    bigThree myBigThree;
    bluBar myBluBar;
    bluBlu myBluBlu;
    darlingApp myDarlingApp;
    emergeMulti myEmergeMulti;
    fallFree myFallFree;
    flagCheck myFlagCheck;
    fragMent myFragMent;
    goldenDisc myGoldenDisc;
    huntRabbit myHuntRabbit;
    icoIcon myIcoIcon;
    keenPublic myKeenPublic;
    keepDistance myKeepDistance;
    kickBack myKickBack;
    longDistance myLongDistance;
    moonShot myMoonShot;
    notionTation myNotionTation;
    nuWit myNuWit;
    pointShoot myPointShoot;
    polyPoli myPolyPoli;
    reCenter myReCenter;
    shiftCycle myShiftCycle;
    shopBot myShopBot;
    spanningCole mySpanningCole;
    superFlat mySuperFlat;
    theyMove myTheyMove;
    togeToge myTogeToge;
    transScale myTransScale;
    trickMe myTrickMe;
    tryAngle myTryAngle;
    twoBall myTwoBall;
    unbalanceLance myUnbalanceLance;
    yoGreek myYoGreek;
    zoomZoom myZoomZoom;
    
    //videoPlayer
    videoPlayer myVideoPlayer;
    
    //video
    videoCloud myVideoCloud;
    
    //palette
    colorCloud myColorCloud;
    
    //chrome
    twoTone myTwoTone;
    colorWorld myColorWorld;
    
    //pixel
    boredomWindow myBoredomWindow;
    criticalWindow myCriticalWindow;
    fromDip myFromDip;
    radioWindow myRadioWindow;
    noizArc myNoizArc;
    rapFlee myRapFlee;
    rollingRoll myRollingRoll;
    slitShut mySlitShut;
    synMeme mySynMeme;
    zigZig myZigZig;
    
    //cover
    flashCover myFlashCover;
    oddCover myOddCover;
    pikaCover myPikaCover;
    blackCover myBlackCover;
};
