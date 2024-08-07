#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class rollingRoll {

public:
    rollingRoll();
    
    void draw(ofTexture texture_, float time_);
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform vec2 center;
        uniform float interval;
        uniform float rotation0;
        uniform float rotation1;
        uniform float rotation2;

        vec2 rotate(vec2 v, float a, vec2 center_) {
            v -= center_;
            float s = sin(a);
            float c = cos(a);
            mat2 m = mat2(c, s, -s, c);
            return m * v + center_;
        }

        void main() {
        vec2 coordinate = gl_FragCoord.xy;

        for (float i = 1.; i <= 16.; i += 1.) {
            if (distance(coordinate, center) < interval * i) {
                if (mod(i, 3.) < 1.) coordinate = rotate(coordinate, rotation0, center);
                else if (mod(i, 3.) < 2.) coordinate = rotate(coordinate, rotation1, center);
                else coordinate = rotate(coordinate, rotation2, center);
            }
        }

        vec4 color = texture2DRect(texture, coordinate);

        gl_FragColor = color;
        }
    );
};
