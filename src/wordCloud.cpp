#include "wordCloud.h"

//--------------------------------------------------------------
wordCloud::wordCloud() {
    
    //Set japanese
    ofDirectory dir;
    dir.open("Japanese");
    dir.sort();
    japanesePathes.resize(dir.size());
    for (int i = 0; i < japanesePathes.size(); i++) {
        japanesePathes[i] = dir.getPath(i);
    }
    
    //Set english
    ofBuffer buffer = ofBufferFromFile("english.txt");
    for (auto word : buffer.getLines()) {
        englishes.push_back(word);
    }
}
