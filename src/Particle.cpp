//
//  Particle.cpp
//  CClabof2
//
//  Created by Longze Xia on 2017/12/18.
//

#include "Particle.hpp"

void Particle::reset() {
    position.x = ofRandomWidth();
    position.y = ofRandomHeight();
    
    velocity.x = sin(rotateDegree)*ofRandom(0.8, 1.2);
    velocity.y = cos(rotateDegree)*ofRandom(0.8, 1.2);
    
    drag = ofRandom(0.95, 0.998);
    
    force   = ofPoint(0,0,0);
}

void Particle::update() {
    if (isAttracting) {
        ofSetColor(140 + sin(rotateDegree)*30, 63, 180);
        position += velocity;
        
        ofPoint attractPoint = ofPoint(ofGetMouseX(), ofGetMouseY());
        
        force = attractPoint - position;
        force.normalize();
        
        velocity *= drag;
        velocity += force *.6;
        
        position += velocity;
        
    } else {
        int xx = 1;
        int yy = 1;
        
        if ( position.x < 0 || position.x > ofGetWidth()){
            xx = -xx;
            position.x = ofGetMouseX();
            
        }
        if ( position.y < 0 || position.y > ofGetHeight()){
            yy = -yy;
            position.y = ofGetMouseY();
        }
        
        position += velocity;
        
        ofPoint attractPoint = ofPoint(ofGetMouseX(), ofGetMouseY());
        
        force = attractPoint - position;
        force.normalize();
        
        ofSetColor(140 + sin(rotateDegree)*30, 63, 180);
        
        velocity *= -0.999;
        velocity += -force *4;
        
        position.x += xx * velocity.x;
        position.y += yy * velocity.y;
        
        
    }
    
    
    
}

void Particle::draw() {
    rotateDegree++;
    
    ofDrawCircle(position.x, position.y, 1.5);

}

void Particle::toggleMode() {
    isAttracting = !isAttracting;
    reset();
}
