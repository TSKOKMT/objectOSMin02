#include "bigThree.h"

//--------------------------------------------------------------
void bigThree::draw(ofRectangle frame_, float time_) {
    
    frame = frame_;
    
    unit = sqrt(frame_.width * frame_.height) / 120.;
    
    //SETUP
    
    if (bSetup) {
        box2d.init();
        box2d.setGravity(10, 0);
        
        circles.clear();
        squares.clear();
        triangles.clear();
        
        create(12 * unit);
        
        bSetup = false;
    }
    
    //UPDATE
    
    if (previousFrameNum != ofGetFrameNum()) {
        //Create
        if (ofGetFrameNum() % 120 == 0) {
            create(ofRandom(1, 60) * unit);
        }
        
        //Erase
        int i = 0;
        while (i < circles.size()) {
            if (circles[i]->getPosition().x > frame.width * 2) circles.erase(circles.begin() + i);
            else i++;
        }
        i = 0;
        while (i < squares.size()) {
            if (squares[i]->getPosition().x > frame.width * 2) squares.erase(squares.begin() + i);
            else i++;
        }
        i = 0;
        while (i < triangles.size()) {
            if (triangles[i]->getPosition().x > frame.width * 2) triangles.erase(triangles.begin() + i);
            else i++;
        }
        
        box2d.createBounds(ofRectangle(-frame.width * 2, -frame.height / 2., frame.width * 5, frame.height * 2));
        box2d.setFPS(ofGetFrameRate());

        box2d.update();
        
        previousFrameNum = ofGetFrameNum();
    }
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    //ofTranslate(-frame_.position);
    
    ofSetColor(myColorCloud.six[0]);
    for (int i = 0; i < circles.size(); i++) {
        ofDrawCircle(circles[i]->getPosition(), circles[i]->getRadius());
    }
    ofSetColor(myColorCloud.six[1]);
    for (int i = 0; i < squares.size(); i++) {
        squares[i]->draw();
    }
    ofSetColor(myColorCloud.six[2]);
    for (int i = 0; i < triangles.size(); i++) {
        triangles[i]->draw();
    }
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
}

//--------------------------------------------------------------
void bigThree::create(float side_) {
    
    float bounce = 1;
    
    int count = frame.height / side_;
    count = ofClamp(count, 1, INT_MAX);
    
    for (int i = 0; i < count; i++) {
        //Circle
        float radius = sqrt(pow(side_, 2) / PI);
        circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back()->setPhysics(1, bounce, 1);
        circles.back()->setup(box2d.getWorld(), -ofRandom(frame.width) - side_, ofRandom(frame.height), radius);
        circles.back()->setVelocity(ofRandom(-1, 1) * 10, ofRandom(-1, 1) * 10);

        //Square
        squares.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
        squares.back()->setPhysics(1, bounce, 1);
        squares.back()->setup(box2d.getWorld(), -ofRandom(frame.width) - side_, ofRandom(frame.height), side_, side_);
        squares.back()->setRotation(ofRandom(360));
        squares.back()->setVelocity(ofRandom(-1, 1) * 10, ofRandom(-1, 1) * 10);
        
        //Triabgle
        float width = sqrt(pow(side_, 2) * 2 / (2 / sqrt(3)));
        float hegiht = width * (sqrt(3) / 2.);
        triangles.push_back(ofPtr<ofxBox2dPolygon>(new ofxBox2dPolygon));
        triangles.back()->setPhysics(1, bounce, 1);
        triangles.back()->addVertex(0, -hegiht / 2.);
        triangles.back()->addVertex(-width / 2., hegiht / 2.);
        triangles.back()->addVertex(width / 2., hegiht / 2.);
        triangles.back()->close();
        triangles.back()->create(box2d.getWorld());
        triangles.back()->setPosition(-ofRandom(frame.width) - side_, ofRandom(frame.height));
        triangles.back()->setRotation(ofRandom(360));
        triangles.back()->setVelocity(ofRandom(-1, 1) * 10, ofRandom(-1, 1) * 10);
    }
}
