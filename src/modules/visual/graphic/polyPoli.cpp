#include "polyPoli.h"

//--------------------------------------------------------------
void polyPoli::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    ofPoint center = frame_.getCenter();
    
    float radius_ = radius * unit;
    
    auto previousVertexes = get(floor(time_ / interval) * 2);
    auto nextVertexes = get(ceil(time_ / interval) * 2);
    
    float motion = ofWrap(time_ / interval, 0, 1);
    motion = sin(motion * HALF_PI);
    motion = sin(motion * HALF_PI);
    
    auto vertexes = lerp(previousVertexes, nextVertexes, motion);
    
    //DRAW
    
    ofPushMatrix();
    ofTranslate(center);
    ofScale(radius_);
    
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(unit / 4.);
    
    for (int i = 0; i < vertexes.size(); i++) {
        //if (i != vertexes.size() - 1) continue;
        //ofSetColor(i % 2 == 0 ? 255 : 0);
        ofSetColor(myColorCloud.six[i % 6]);
        
        ofBeginShape();
        for (int j = 0; j < vertexes[i].size(); j++) {
            //ofDrawCircle(vertexes[i][j], 10);
            ofVertex(vertexes[i][j]);
        }
        ofEndShape(true);
    }

    /*ofNoFill();
    ofBeginShape();
    for (int i = 0; i < traces.size(); i++) {
        ofVertex(traces[i]);
    }
    ofEndShape(false);*/

    ofPopStyle();
    
    ofPopMatrix();
}

//--------------------------------------------------------------
vector<vector<ofPoint>> polyPoli::get(int shift_) {
    
    vector<vector<ofPoint>> vertexes;
    
    ofPoint vertex0, vertex1;
    bool bFirst = true;
    int i = 0;
    for (int theNumber = count_ + 2; theNumber >= 3; theNumber--) {
        ofPoint theCenter;
        float theRadius;
        float theStartAngle;
        if (bFirst) {
            theCenter = ofPoint(0, 0);
            theRadius = 1;
            theStartAngle = 0;
            bFirst = false;
        }
        else {
            float innerAngle = TWO_PI / (float)theNumber;
            theRadius = (vertex0.distance(vertex1) / 2.) / sin(innerAngle / 2.);
            float theTilt = atan2(vertex1.y - vertex0.y, vertex1.x - vertex0.x) + HALF_PI;
            float theLength = (vertex0.distance(vertex1) / 2.) / tan(innerAngle / 2.);
            theCenter = (vertex0 + vertex1) / 2. + ofPoint(cos(theTilt), sin(theTilt)) * theLength;
            theStartAngle = atan2(vertex0.y - theCenter.y, vertex0.x - theCenter.x);
        }
        
        vertexes.push_back(vector<ofPoint>());
        
        //ofSetColor(i % 2 == 0 ? 255 : 0);
        //ofBeginShape();
        for (int j = 0; j < theNumber; j++) {
            ofPoint theVertex;
            float theAngle = theStartAngle + ofMap(j, 0, theNumber, 0, TWO_PI);
            theVertex.x = cos(theAngle);
            theVertex.y = sin(theAngle);
            theVertex *= theRadius;
            theVertex += theCenter;
            
            //ofVertex(theVertex);
            //ofDrawCircle(theVertex, 12);
            vertexes.back().push_back(theVertex);
            
            if ((j + (i + 1) * shift_) % theNumber == 0) vertex0 = theVertex;
            if ((j + (i + 1) * shift_) % theNumber == 1) vertex1 = theVertex;
        }
        //ofEndShape(true);
        
        i++;
    }
    
    return vertexes;
}

//--------------------------------------------------------------
vector<vector<ofPoint>> polyPoli::lerp(vector<vector<ofPoint>> from_, vector<vector<ofPoint>> to_, float t_) {
    
    vector<vector<ofPoint>> result;
    
    result.resize(min((int)from_.size(), (int)to_.size()));
    for (int i = 0; i < result.size(); i++) {
        result[i].resize(min((int)from_[i].size(), (int)to_[i].size()));
        for (int j = 0; j < result[i].size(); j++) {
            result[i][j].x = ofLerp(from_[i][j].x, to_[i][j].x, t_);
            result[i][j].y = ofLerp(from_[i][j].y, to_[i][j].y, t_);
        }
    }
    
    return result;
}
