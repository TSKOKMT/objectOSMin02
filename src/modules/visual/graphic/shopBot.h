#pragma once

#define STRINGIFY(A) #A

#include "ofMain.h"

#include "colorCloud.h"

class shopBot {

public:
    shopBot();
    void draw(ofRectangle frame_, float time_);
        
private:
    ofShader shader;
    string shaderText = STRINGIFY
    (
        uniform float time;
        uniform float unit;
        uniform vec2 center;
        uniform vec3 color;
     
        float random (in vec2 st) {
            return fract(sin(dot(st.xy,
                vec2(12.9898,78.233)))
                * 43758.5453123);
        }

        float noise(vec2 st) {
            vec2 i = floor(st);
            vec2 f = fract(st);
            vec2 u = f*f*(3.0-2.0*f);
            return mix( mix( random( i + vec2(0.0,0.0) ),
                random( i + vec2(1.0,0.0) ), u.x),
                mix( random( i + vec2(0.0,1.0) ),
                random( i + vec2(1.0,1.0) ), u.x), u.y);
        }
     
        mat2 rotate2d(float angle){
            return mat2(cos(angle),-sin(angle),
                sin(angle),cos(angle));
        }

        float lines(in vec2 pos, float b){
            float scale = 5.;
            pos *= scale;
            return smoothstep(.49,
                .51,
                abs((sin(pos.x*3.1415)+b*2.0))*.5);
        }
     
        void main() {
            vec2 coordinate = gl_FragCoord.xy;
            
            vec2 st = (coordinate - center) / (30. * unit);
            st = rotate2d(-time * .5) * st;
            
            vec2 pos = rotate2d(noise(st) + time * 2.) * st;

            float lines = lines(pos, .5);
            
            vec4 color = vec4(color * lines, 1.0);

            gl_FragColor = color;
        }
    );
    
    colorCloud myColorCloud;
};
