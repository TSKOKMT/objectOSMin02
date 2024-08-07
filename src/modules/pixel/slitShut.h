#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class slitShut {

public:
    slitShut();
    
    void draw(ofTexture texture_, float time_);
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform float value;
        uniform float sizeH;
        uniform float sizeV;

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            coordinate.x += fract(pow(coordinate.y / sizeH, value)) * 360.;
            coordinate.y += fract(pow(coordinate.x / sizeV, value)) * 360.;

            vec4 color = texture2DRect(texture, coordinate);

            gl_FragColor = color;
        }
    );
};
