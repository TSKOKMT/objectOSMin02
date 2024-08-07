#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class noizArc {

public:
    noizArc();
    
    void draw(ofTexture texture_, float time_);
    
    int count = 9;
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform float side;
        uniform vec2 size;

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            coordinate.x += (mod(floor(coordinate.y / side), 2.) * 2. - 1.) * size.x / 2.;

            vec4 color = texture2DRect(texture, coordinate);

            gl_FragColor = color;
        }
    );
};
