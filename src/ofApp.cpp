#include "ofApp.h"

#include "ParticleUpdater.h"
#include "ParticleData.h"
#include "WindForce.h"
#include <random>

void ofApp::setup()
{
    sphere.setRadius(radius);
    glm::vec3 initialPos = ofVec3f(ofGetWidth() , ofGetHeight() * 0.5, 500);
    light.setPosition(initialPos.x, initialPos.y, initialPos.z);
    light.setDiffuseColor(ofColor(255, 255, 255));
    light.setSpecularColor(ofColor(255, 255, 255));
    light.enable();
    size_t maxParticles = 5000;
    particles.generate(maxParticles);
}
//--------------------------------------------------------------
void ofApp::update(){
    float dt = ofGetLastFrameTime(); 
    updater.update(dt, &particles, radius, windforce.isWindActive);
}

void ofApp::draw()
{
    cam.begin();
    light.enable();
    sphere.setPosition(0,0,0);
    for (const auto& particle : particles.particles) {
        if (!particles.particles.empty()) {
            ofSetColor(particle.m_col.x, particle.m_col.y, particle.m_col.z);
            float radius = 3.0f;
            ofDrawSphere(particle.m_pos.x, particle.m_pos.y, particle.m_pos.z, radius);
        }
    }
    ofDrawBitmapStringHighlight("\n [w]: Add/remove wind force ",-400,300);

    sphere.draw();
    light.disable();
    cam.end();
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'w')
        windforce.isWindActive = !windforce.isWindActive;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}