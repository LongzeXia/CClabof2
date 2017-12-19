//
//  Particle.hpp
//  CClabof2
//
//  Created by Longze Xia on 2017/12/18.
//

#include "ofMain.h"
#include <math.h>

class Particle {
    
public:
    void reset();
    void update();
    void draw();
    
    void toggleMode();
    
    ofPoint position;
    ofPoint velocity;
    ofPoint force;
    float drag;
    int rotateDegree;
    
    bool isAttracting = true;
};


