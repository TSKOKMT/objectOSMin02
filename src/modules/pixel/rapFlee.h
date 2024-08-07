#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class rapFlee {

public:
    rapFlee();
    
    void draw(ofTexture texture_, float time_);
    
    float term = 4;
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform vec2 position;
        uniform vec2 length;

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            vec2 newCoordinate;
            if (coordinate.x < position.x - length.x / 2.) newCoordinate.x = coordinate.x + length.x / 2.;
            else if (coordinate.x < position.x + length.x / 2.) newCoordinate.x = position.x;
            else newCoordinate.x = coordinate.x - length.x / 2.;
            if (coordinate.y < position.y - length.y / 2.) newCoordinate.y = coordinate.y + length.y / 2.;
            else if (coordinate.y < position.y + length.y / 2.) newCoordinate.y = position.y;
            else newCoordinate.y = coordinate.y - length.y / 2.;
            coordinate = newCoordinate;

            vec4 color = texture2DRect(texture, coordinate);

            gl_FragColor = color;
        }
    );
};
