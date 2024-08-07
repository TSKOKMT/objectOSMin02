#include "videoCloud.h"

//--------------------------------------------------------------
videoCloud::videoCloud() {
    
    //Set japanese
    ofDirectory dir;
    dir.open("Video");
    dir.sort();
    pathes.resize(dir.size());
    for (int i = 0; i < pathes.size(); i++) {
        pathes[i] = dir.getPath(i);
    }
}
