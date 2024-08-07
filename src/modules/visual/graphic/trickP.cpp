#include "trickP.h"

//--------------------------------------------------------------
ofPoint trickP::process(ofPoint point_, float time_) {
    
    if (bSetup) {
        point = point_;
        
        bSetup = false;
    }
    
    previousTime = time;
    time = time_;
    
    ofPoint force = stiffness * (point_ - point) / (time - previousTime);
    ofPoint accel = force / mass;
    velocity += accel;
    velocity *= 1 - friction;
    point += velocity * (time - previousTime);
    
    return point;
}
