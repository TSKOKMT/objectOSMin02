#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class zigZig {

public:
    zigZig();
    
    void draw(ofTexture texture_, float time_);
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform float side;
        uniform float slant;

        vec2 rotate(vec2 v, float a, vec2 center_) {
            v -= center_;
            float s = sin(a);
            float c = cos(a);
            mat2 m = mat2(c, s, -s, c);
            return m * v + center_;
        }

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            if (mod(coordinate.x / side, 2.) < 1.) coordinate.y += (mod(coordinate.x, side) - side / 2.) * slant;
            else coordinate.y -= (mod(coordinate.x, side) - side / 2.) * slant;

            vec4 color = texture2DRect(texture, coordinate);

            gl_FragColor = color;
        }
    );
};
