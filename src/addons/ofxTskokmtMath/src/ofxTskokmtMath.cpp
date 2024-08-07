#include "ofxTskokmtMath.h"

//--------------------------------------------------------------
int ofxTskokmtMath::min(vector<int> values) {
    
    int min = INT_MAX;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}

//--------------------------------------------------------------
int ofxTskokmtMath::max(vector<int> values) {
    
    int max = INT_MIN;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    return max;
}

//--------------------------------------------------------------
float ofxTskokmtMath::sum(vector<float> values_) {
 
    float sum = 0;
    for (int i = 0; i < values_.size(); i++) {
        sum += values_[i];
    }
    return sum;
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::randomPointInRectangle(ofRectangle rectangle_) {
    
    return ofPoint(ofRandom(rectangle_.getLeft(), rectangle_.getRight()), ofRandom(rectangle_.getTop(), rectangle_.getBottom()));
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::randomPointInBox(ofPoint center, float width, float height, float depth) {
    
    return ofPoint(ofRandom(-width / 2., width / 2.), ofRandom(-height / 2., height / 2.), ofRandom(-depth / 2., depth / 2.)) + center;
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::randomPointInBox(ofBoxPrimitive box_) {
    
    return randomPointInBox(box_.getPosition(), box_.getWidth(), box_.getHeight(), box_.getDepth());
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::randomPointInSphere(ofPoint center, float radius) {
    
    ofPoint p;
    do {
        p = ofPoint(ofRandom(-radius, radius), ofRandom(-radius, radius), ofRandom(-radius, radius)) + center;
    } while (ofDist(center.x, center.y, p.x, p.y) > radius);
    
    return p;
}

//--------------------------------------------------------------
ofRectangle ofxTskokmtMath::randomRectangleInRectangle(ofRectangle rectangle_, float minWidth_, float minHeight_) {
    
    ofRectangle rectangle;
    rectangle.position = randomPointInRectangle(ofRectangle(rectangle_.position, rectangle_.width - minWidth_, rectangle_.height - minHeight_));
    rectangle.width = ofRandom(minWidth_, rectangle_.getRight() - rectangle.x);
    rectangle.height = ofRandom(minHeight_, rectangle_.getBottom() - rectangle.y);
    
    return rectangle;
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::randomPointOnLine(ofPolyline line_) {
    
    return line_.getPointAtPercent(ofRandom(1));
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::randomPointOnRectangle(ofRectangle rectangle_) {
    
    ofPolyline line;
    line.addVertex(rectangle_.getTopLeft());
    line.addVertex(rectangle_.getTopRight());
    line.addVertex(rectangle_.getBottomRight());
    line.addVertex(rectangle_.getBottomLeft());
    line.addVertex(rectangle_.getTopLeft());
    
    return randomPointOnLine(line);
}

//--------------------------------------------------------------
bool ofxTskokmtMath::isOverlapRectangles(ofRectangle rect1, ofRectangle rect2) {
    
    return !(rect1.getRight() < rect2.getLeft() || rect1.getLeft() > rect2.getRight() || rect1.getBottom() < rect2.getTop() || rect1.getTop() > rect2.getBottom());
}

//--------------------------------------------------------------
bool ofxTskokmtMath::isOverlapCircles(ofPoint center01, float radius01, ofPoint center02, float radius02) {
    
    return ofDist(center01.x, center01.y, center02.x, center02.y) < radius01 + radius02;
}

//--------------------------------------------------------------
bool ofxTskokmtMath::isOverlapBoxes(ofBoxPrimitive &box01, ofBoxPrimitive &box02) {
    
    return abs(box01.getX() - box02.getX()) < (box01.getWidth() + box02.getWidth()) / 2 && abs(box01.getY() - box02.getY()) < (box01.getHeight() + box02.getHeight()) / 2 && abs(box01.getZ() - box02.getZ()) < (box01.getDepth() + box02.getDepth()) / 2;
}

//--------------------------------------------------------------
bool ofxTskokmtMath::isOverlapPolylines(ofPolyline polyline01_, ofPolyline polyline02_) {
    
    ofPoint trash;
    for (int i = 0; i < polyline01_.getVertices().size(); i++) {
        for (int j = 0; j < polyline02_.getVertices().size(); j++) {
            ofPoint line01S = polyline01_.getVertices()[i];
            ofPoint line01E = polyline01_.getVertices()[ofWrap(i + 1, 0, (int)polyline01_.getVertices().size())];
            ofPoint line02S = polyline02_.getVertices()[j];
            ofPoint line02E = polyline02_.getVertices()[ofWrap(j + 1, 0, (int)polyline02_.getVertices().size())];
            
            if (isCrossLineSegments(line01S, line01E, line02S, line02E)) return true;
        }
    }
    
    if (polyline01_.inside(polyline02_.getCentroid2D()) || polyline02_.inside(polyline01_.getCentroid2D())) return true;
    
    return false;
}

//--------------------------------------------------------------
bool ofxTskokmtMath::isCrossLineSegments(ofPoint p01, ofPoint p02, ofPoint p03, ofPoint p04) {
    
    return signbit(crossProduct(p02 - p01, p03 - p01)) != signbit(crossProduct(p02 - p01, p04 - p01)) && signbit(crossProduct(p04 - p03, p02 - p03)) != signbit(crossProduct(p04 - p03, p01 - p03));
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::map(float value_, float inputMin_, float inputMax_, ofPoint outputMin_, ofPoint outputMax_) {
    
    return ofPoint(ofMap(value_, inputMin_, inputMax_, outputMin_.x, outputMax_.x), ofMap(value_, inputMin_, inputMax_, outputMin_.y, outputMax_.y), ofMap(value_, inputMin_, inputMax_, outputMin_.z, outputMax_.z));
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::map(ofPoint point_, ofPoint inputMin_, ofPoint inputMax_, ofPoint outputMin_, ofPoint outputMax_) {
    
    return ofPoint(ofMap(point_.x, inputMin_.x, inputMax_.x, outputMin_.x, outputMax_.x), ofMap(point_.y, inputMin_.y, inputMax_.y, outputMin_.y, outputMax_.y), ofMap(point_.z, inputMin_.z, inputMax_.z, outputMin_.z, outputMax_.z));
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::map(ofPoint point_, ofRectangle inputFrame_, ofRectangle outputFrame_) {
    
    return map(point_, inputFrame_.getTopLeft(), inputFrame_.getBottomRight(), outputFrame_.getTopLeft(), outputFrame_.getBottomRight());
}

//--------------------------------------------------------------
ofRectangle ofxTskokmtMath::map(float value_, float inputMin_, float inputMax_, ofRectangle outputMin_, ofRectangle outputMax_) {
    
    return ofRectangle(ofMap(value_, inputMin_, inputMax_, outputMin_.x, outputMax_.x), ofMap(value_, inputMin_, inputMax_, outputMin_.y, outputMax_.y), ofMap(value_, inputMin_, inputMax_, outputMin_.width, outputMax_.width), ofMap(value_, inputMin_, inputMax_, outputMin_.height, outputMax_.height));
}

//--------------------------------------------------------------
vector<float> ofxTskokmtMath::lerp(vector<float> from_, vector<float> to_, float progress_) {
    
    int count = from_.size() < to_.size() ? from_.size() : to_.size();
    
    vector<float> result;
    result.resize(count);
    for (int i = 0; i < count; i++) {
        result[i] = ofLerp(from_[i], to_[i], progress_);
    }
    
    return result;
}

//--------------------------------------------------------------
int ofxTskokmtMath::factorial(int i_) {
    
    if (i_ > 0) return i_ * factorial(i_ - 1);
    else return 1;
}

//--------------------------------------------------------------
int ofxTskokmtMath::binomialCoef(int n_, int k_) {
    
    return factorial(n_) / (factorial(k_) * factorial(n_ - k_));
}

//--------------------------------------------------------------
vector<float> ofxTskokmtMath::getRealRootsOfCubicEquation(float a_, float b_, float c_, float d_) {
    
    vector<float> roots;
    
    b_ /= a_;
    c_ /= a_;
    d_ /= a_;
    
    float disc, q, r, dum1, s, t, term1, r13;
    q = (3 * c_ - (b_ * b_)) / 9.;
    r = -(27 * d_) + b_ * (9 * c_ - 2 * (b_ * b_));
    r /= 54;
    disc = q * q * q + r * r;
    term1 = (b_ / 3.);
    
    if (disc > 0) { // One is real, two are complex.
        s = r + sqrt(disc);
        s = s < 0 ? -cbrt(-s) : cbrt(s);
        t = r - sqrt(disc);
        t = t < 0 ? -cbrt(-t) : cbrt(t);
        roots.push_back(-term1 + s + t);
    } else if (disc == 0) { // All are real, at least two are equal.
        r13 = r < 0 ? -cbrt(-r) : cbrt(r);
        roots.push_back(-term1 + 2 * r13);
        roots.push_back(-(r13 + term1));
    } else { // All are real, unequal.
        q = -q;
        dum1 = q * q * q;
        dum1 = acos(r / sqrt(dum1));
        r13 = 2 * sqrt(q);
        roots.push_back(-term1 + r13 * cos(dum1 / 3.));
        roots.push_back(-term1 + r13 * cos((dum1 + 2 * M_PI) / 3.));
        roots.push_back(-term1 + r13 * cos((dum1 + 4 * M_PI) / 3.));
    }
    
    return roots;
}

//--------------------------------------------------------------
float ofxTskokmtMath::bezier(vector<float> vs_, float t_) {
    
    float value = 0;
    for (int i = 0; i < vs_.size(); i++) {
        value += vs_[i] * binomialCoef(vs_.size() - 1, i) * pow(t_, i) * pow(1 - t_, (vs_.size() - 1) - i);
    }
    return value;
}
//--------------------------------------------------------------
float ofxTskokmtMath::cubicBezier(float v1_, float v2_, float t_) {
 
    vector<float> vs;
    vs.push_back(0);
    vs.push_back(v1_);
    vs.push_back(v2_);
    vs.push_back(1);
    return bezier(vs, t_);
}

//--------------------------------------------------------------
float ofxTskokmtMath::cubicBezierByX(ofPoint point0_, ofPoint point1_, float x_) {
    
    if (x_ == 1) return x_;
 
    float t = 0;
    vector<float> ts = getRealRootsOfCubicEquation(3 * point0_.x - 3 * point1_.x + 1, -6 * point0_.x + 3 * point1_.x, 3 * point0_.x, -x_);
    for (int i = 0; i < ts.size(); i++) {
        if (0 <= ts[i] && ts[i] <= 1) t = ts[i];
    }
    return cubicBezier(point0_.y, point1_.y, t);
}

//--------------------------------------------------------------
float ofxTskokmtMath::mean(vector<float> values) {
    
    float sum = 0.;
    for (int i = 0; i < values.size(); i++) sum += values[i];
    return sum / (float)values.size();
}

//--------------------------------------------------------------
int ofxTskokmtMath::mean(vector<int> values) {
    
    int sum = 0;
    for (int i = 0; i < values.size(); i++) sum += values[i];
    return sum / (int)values.size();
}

//--------------------------------------------------------------
float ofxTskokmtMath::easeFilter(float value_, float amount_) {
    
    if (bFistTime) {
        previousValue = value_;
        bFistTime = false;
    }
    value_ = previousValue + (value_ - previousValue) * amount_;
    previousValue = value_;
    
    return value_;
}

//--------------------------------------------------------------
vector<float> ofxTskokmtMath::easeFilter(vector<float> values_, float amount_) {
    
    if (previousValues.size() != values_.size()) previousValues = values_;
    
    for (int i = 0; i < values_.size(); i++) {
        values_[i] = previousValues[i] + (values_[i] - previousValues[i]) * amount_;
    }
    previousValues = values_;
    
    return values_;
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::easeFilter(ofPoint point_, float amount_) {
    
    if (bFistTime) {
        previousPoint = point_;
        bFistTime = false;
    }
    point_ = previousPoint + (point_ - previousPoint) * amount_;
    previousPoint = point_;
    
    return point_;
}

//--------------------------------------------------------------
vector<ofPoint> ofxTskokmtMath::easeFilter(vector<ofPoint> points_, float amount_) {
    
    if (previousPoints.size() != points_.size()) {
        previousPoints = points_;
    }
    
    for (int i = 0; i < points_.size(); i++) {
        points_[i] = previousPoints[i] + (points_[i] - previousPoints[i]) * amount_;
    }
    previousPoints = points_;
    
    return points_;
}

//--------------------------------------------------------------
float ofxTskokmtMath::meanFilter(float value_,  int numOfSample_) {
 
    if (stackedValues.size() != numOfSample_) stackedValues = vector<float>(numOfSample_, value_);
    
    float mean = 0;
    for (int i = 0; i < numOfSample_; i++) {
        mean += stackedValues[i];
    }
    mean += value_;
    mean /= float(numOfSample_ + 1);
    
    for (int i = numOfSample_ - 1; i >= 1; i--) {
        stackedValues[i] = stackedValues[i - 1];
    }
    stackedValues[0] = value_;
    
    return mean;
}

//--------------------------------------------------------------
ofPoint ofxTskokmtMath::meanFilter(ofPoint point_, int numOfSample_) {
    
    if (stackedPoints.size() != numOfSample_) stackedPoints = vector<ofPoint>(numOfSample_, point_);
    
    ofPoint mean = ofPoint(0, 0);
    for (int i = 0; i < numOfSample_; i++) {
        mean += stackedPoints[i];
    }
    mean += point_;
    mean /= float(numOfSample_ + 1);
    
    for (int i = numOfSample_ - 1; i >= 1; i--) {
        stackedPoints[i] = stackedPoints[i - 1];
    }
    stackedPoints[0] = point_;
    
    return mean;
}

//--------------------------------------------------------------
vector<ofPoint> ofxTskokmtMath::meanFilter(vector<ofPoint> points_, int numOfSample_) {
    
    if (stackedPointss.size() != points_.size()) {
        int previousSize = stackedPointss.size();
        stackedPointss.resize(points_.size());
        for (int i = previousSize; i < stackedPointss.size(); i++) {
            stackedPointss[i] = vector<ofPoint>(numOfSample_, points_[i]);
        }
    }
    for (int i = 0; i < stackedPointss.size(); i++) {
        if (stackedPointss[i].size() != numOfSample_) stackedPointss[i] = vector<ofPoint>(numOfSample_, points_[i]);
    }
    
    vector<ofPoint> means;
    means.resize(points_.size());
    for (int i = 0; i < points_.size(); i++) {
        for (int j = 0; j < numOfSample_; j++) {
            means[i] += stackedPointss[i][j];
        }
        means[i] += points_[i];
        means[i] /= float(numOfSample_ + 1);
        
        for (int j = numOfSample_ - 1; j >= 1; j--) {
            stackedPointss[i][j] = stackedPointss[i][j - 1];
        }
        stackedPointss[i][0] = points_[i];
    }
    
    return means;
}

//--------------------------------------------------------------
float ofxTskokmtMath::dotProduct(ofPoint v1_, ofPoint v2_) {
    
    return v1_.x * v2_.x + v1_.y * v2_.y;
}

//--------------------------------------------------------------
float ofxTskokmtMath::crossProduct(ofPoint v1_, ofPoint v2_) {
    
    return v1_.x * v2_.y - v1_.y * v2_.x;
}

//--------------------------------------------------------------
ofRectangle ofxTskokmtMath::cropped(ofRectangle source_, ofRectangle target_) {
    
    if (source_.getLeft() < target_.getLeft()) {
        source_.width -= target_.getLeft() - source_.getLeft();
        source_.x = target_.x;
    }
    if (source_.getTop() < target_.getTop()) {
        source_.height -= target_.getTop() - source_.getTop();
        source_.y = target_.y;
    }
    if (source_.getRight() > target_.getRight()) {
        source_.width -= source_.getRight() - target_.getRight();
    }
    if (source_.getBottom() > target_.getBottom()) {
        source_.height -= source_.getBottom() - target_.getBottom();
    }
    
    return source_;
}

//--------------------------------------------------------------
float ofxTskokmtMath::snap(float value_, float step_) {
    
    return round(value_ / step_) * step_;
}
