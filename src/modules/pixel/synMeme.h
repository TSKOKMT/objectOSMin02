#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class synMeme {

public:
    synMeme();
    
    void draw(ofTexture texture_, float time_);
    
    int count = 3;
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform vec2 center;
        uniform float count;
        uniform float innerRotation;
        uniform float rotation;
        uniform float scale0;
        uniform float scale1;

        float PI = 3.1415926535897932384626433832795;

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            float angle = atan(coordinate.y - center.y, coordinate.x - center.x);
            angle += rotation;

            float angleU = PI * 2. / count;

            if (mod(angle / angleU, 2.) < 1.) angle = mod(angle, angleU);
            else angle = angleU - mod(angle, angleU);

            angle += innerRotation;

            float dist = distance(coordinate, center);

            //coordinate += (center - coordinate) * sin((distance(center, coordinate) + amount2 * 1080.) / 120.) * amount * 2.;
            coordinate = center + vec2(cos(angle), sin(angle)) * dist;

            vec4 color = texture2DRect(texture, coordinate);

            gl_FragColor = color;
        }
    );
};
