#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class fromDip {

public:
    fromDip();
    
    void draw(ofTexture texture_, float time_);
    
    float speed = .1;
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform vec2 center;
        uniform float amount;
        uniform float amount2;

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            coordinate += (center - coordinate) * sin((distance(center, coordinate) + amount2 * 1080.) / 120.) * amount * 2.;

            vec4 color = texture2DRect(texture, coordinate);

            gl_FragColor = color;
        }
    );
};
