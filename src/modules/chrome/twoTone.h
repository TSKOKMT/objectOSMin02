#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class twoTone {

public:
    twoTone();
    
    void draw(ofTexture texture_);
    
    ofColor color0 = ofColor(0, 0, 255);
    ofColor color1 = ofColor(255, 0, 0);
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform vec3 color0;
        uniform vec3 color1;
     
        vec3 RGBtoHSV(vec3 rgb) {
            float r = rgb.r;
            float g = rgb.g;
            float b = rgb.b;

            float maxC = max(max(r, g), b);
            float minC = min(min(r, g), b);
            float delta = maxC - minC;

            float h = 0.0;
            if (delta != 0.0) {
            if (maxC == r) {
            h = mod(((g - b) / delta), 6.0);
            } else if (maxC == g) {
            h = ((b - r) / delta) + 2.0;
            } else {
            h = ((r - g) / delta) + 4.0;
            }
            h /= 6.0;
            if (h < 0.0) h += 1.0;
            }

            float s = (maxC == 0.0) ? 0.0 : delta / maxC;
            float v = maxC;

            return vec3(h, s, v);
        }

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            vec4 color = texture2DRect(texture, coordinate);

            float v = RGBtoHSV(color.rgb).z;
            
            vec3 newColor = mix(color0, color1, v);
            
            gl_FragColor = vec4(newColor, color.a);
        }
    );
};
