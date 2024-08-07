#pragma once

#include "ofMain.h"

#define STRINGIFY(A) #A

class colorWorld {

public:
    colorWorld();
    
    void draw(ofTexture texture_);
    
    vector<ofColor> palette;
        
private:
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform vec3 color0;
        uniform vec3 color0_5;
        uniform vec3 color1;
        uniform vec3 color1_5;
        uniform vec3 color2;
        uniform vec3 color2_5;
     
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

            float hue = RGBtoHSV(color.rgb).x;
            
            vec3 newColor;
            if (color.rgb == vec3(0.0)) {
                newColor = vec3(0.0);
            } else if (color.rgb == vec3(1.0)) {
                newColor = vec3(1.0);
            } else if (hue < 1.0 / 6.0) {
                newColor = mix(color0, color0_5, hue * 6.0);
            } else if (hue < 2.0 / 6.0) {
                newColor = mix(color0_5, color1, (hue - 1.0 / 6.0) * 6.0);
            } else if (hue < 3.0 / 6.0) {
                newColor = mix(color1, color1_5, (hue - 2.0 / 6.0) * 6.0);
            } else if (hue < 4.0 / 6.0) {
                newColor = mix(color1_5, color2, (hue - 3.0 / 6.0) * 6.0);
            } else if (hue < 5.0 / 6.0) {
                newColor = mix(color2, color2_5, (hue - 4.0 / 6.0) * 6.0);
            } else {
                newColor = mix(color2_5, color0, (hue - 5.0 / 6.0) * 6.0);
            }
            
            gl_FragColor = vec4(newColor, color.a);
        }
    );
};
