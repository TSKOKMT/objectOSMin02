#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class criticalWindow {

public:
    criticalWindow();
    
    void draw(ofTexture texture_, float time_);
    
    float interval = 2;
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform vec2 center;
        uniform float side;
        uniform float length;
        uniform bool b; 

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            if (b) coordinate = center + (coordinate - center) / distance(coordinate, center) * length;

            vec4 color = texture2DRect(texture, coordinate);

            gl_FragColor = color;
        }
    );
};
