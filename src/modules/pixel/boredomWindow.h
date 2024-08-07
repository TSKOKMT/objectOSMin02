#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class boredomWindow {

public:
    boredomWindow();
    
    void draw(ofTexture texture_, float time_);
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform vec2 center;
        uniform float side;
        uniform float rotation;

        vec2 rotate(vec2 v, float a, vec2 center_) {
            v -= center_;
            float s = sin(a);
            float c = cos(a);
            mat2 m = mat2(c, s, -s, c);
            return m * v + center_;
        }

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            float newX = center.x + (floor((coordinate.x - center.x) / side) + .5) * side;
            float newY = center.y + (floor((coordinate.y - center.y) / side) + .5) * side;

            coordinate = rotate(coordinate, rotation, vec2(newX, newY));

            vec4 color = texture2DRect(texture, coordinate);

            gl_FragColor = color;
        }
    );
};
