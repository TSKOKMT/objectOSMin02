#pragma once

#include "ofMain.h"

class ofxTskokmtMath {
    
public:
    static int min(vector<int> values);
    static int max(vector<int> values);
        
    static float sum(vector<float> values_);
    
    static ofPoint randomPointInRectangle(ofRectangle rectangle_);
    static ofPoint randomPointInBox(ofPoint center, float width, float height, float depth);
    static ofPoint randomPointInBox(ofBoxPrimitive box_);
    static ofPoint randomPointInSphere(ofPoint center, float radius);
    static ofRectangle randomRectangleInRectangle(ofRectangle rectangle_, float minWidth_ = 0, float minHeight_ = 0);
    static ofPoint randomPointOnLine(ofPolyline line_);
    static ofPoint randomPointOnRectangle(ofRectangle rectangle_);
    
    static bool isOverlapRectangles(ofRectangle rectangle01_, ofRectangle rectangle02_);
    static bool isOverlapCircles(ofPoint center01, float radius01, ofPoint center02, float radius02);
    static bool isOverlapBoxes(ofBoxPrimitive& box01, ofBoxPrimitive& box02);
    static bool isOverlapPolylines(ofPolyline polyline01_, ofPolyline polyline02_);
    static bool isCrossLineSegments(ofPoint p01, ofPoint p02, ofPoint p03, ofPoint p04);
    
    static ofPoint map(float value_, float inputMin_, float inputMax_, ofPoint outputMin_, ofPoint outputMax_);
    static ofPoint map(ofPoint point_, ofPoint inputMin_, ofPoint inputMax_, ofPoint outputMin_, ofPoint outputMax_);
    static ofPoint map(ofPoint point_, ofRectangle inputFrame_, ofRectangle outputFrame_);
    static ofRectangle map(float value_, float inputMin_, float inputMax_, ofRectangle outputMin_, ofRectangle outputMax_);
    
    static vector<float> lerp(vector<float> from_, vector<float> to_, float progress_);
    
    static int factorial(int i_);
    
    static int binomialCoef(int n_, int k_);
    
    static vector<float> getRealRootsOfCubicEquation(float a_, float b_, float c_, float d_);
    
    static float bezier(vector<float> vs_, float t_);
    static float cubicBezier(float v1_, float v2_, float t_);
    static float cubicBezierByX(ofPoint p1_, ofPoint p2_, float x_);
    
    static float mean(vector<float> values);
    static int mean(vector<int> values);
    
    float easeFilter(float value_, float amount_);
    float previousValue;
    vector<float> easeFilter(vector<float> values, float amount_);
    vector<float> previousValues;
    ofPoint easeFilter(ofPoint point_, float amount_);
    ofPoint previousPoint;
    vector<ofPoint> easeFilter(vector<ofPoint> points_, float amount_);
    vector<ofPoint> previousPoints;
    bool bFistTime = true;
    
    float meanFilter(float value_,  int numOfSample_);
    vector<float> stackedValues;
    ofPoint meanFilter(ofPoint point_, int numOfSample_);
    vector<ofPoint> stackedPoints;
    vector<ofPoint> meanFilter(vector<ofPoint> points_, int numOfSample_);
    vector<vector<ofPoint>> stackedPointss;
    
    static float dotProduct(ofPoint v1_, ofPoint v2_);
    static float crossProduct(ofPoint v1_, ofPoint v2_);
    
    static ofRectangle cropped(ofRectangle source_, ofRectangle target_);
    
    static float snap(float value_, float step_);
    
    static int countMultiples(float a, float b, float multiple) {
        if (a > b) swap(a, b);

        int startMultiple = ceil(a / multiple);
        float startValue = startMultiple * multiple;

        int endMultiple = floor(b / multiple);
        float endValue = endMultiple * multiple;

        if (startValue > b || endValue < a) return 0;
        else return endMultiple - startMultiple + 1;
    }
    
private:
};
