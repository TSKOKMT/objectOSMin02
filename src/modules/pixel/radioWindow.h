#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class radioWindow {

public:
    radioWindow();
    
    void draw(ofTexture texture_, float time_);
    
    float speed = .1;
    float speed2 = .5;
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform vec2 center;
        uniform float amount;
        uniform float length;
        uniform float phase;

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            coordinate += (center - coordinate) / distance(center, coordinate) * fract((distance(center, coordinate) - phase) / length) * amount;

            vec4 color = texture2DRect(texture, coordinate);

            gl_FragColor = color;
        }
    );
};
