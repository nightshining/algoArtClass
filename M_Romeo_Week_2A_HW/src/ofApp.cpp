#include "ofApp.h"
#define TWOPI (PI * 2)

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(ofColor::whiteSmoke);
    ofSetLineWidth(2.0);
    radius = 100;
    circRes = 60;
    scale = radius * 0.5;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    circRes = 30 + 6 * frequency;
    inc = TWOPI / circRes;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    shape(ofColor::salmon, 2.0);
    shape(ofColor::teal, 1.5);
    shape(ofColor::black, 1.0);
    
}

//--------------------------------------------------------------
float ofApp::wave(float x){
    
    float wave = sin(x * frequency) * amplitude;
    float wave2 = sin(x * frequency + wave) * amplitude;

    return wave2;
    
}

void ofApp::shape(ofColor shapeColor, float scale) {
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() * .5, ofGetHeight() * .5);
    ofScale(scale, scale);
    ofBeginShape();
    
    for (float radians = 0; radians < 15.0; radians += inc){
        
        float x = sin(radians) * radius + sin(wave(ofGetElapsedTimef()));
        float y = sin(radians * wave(ofGetElapsedTimef()) * radius) * radius;
        
        ofSetColor(shapeColor, ofMap(radians, 0.0, 15.0, 10.0, 100.0));
        ofNoFill();
        ofVertex(x, y);
        
    }
    ofEndShape();
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    frequency = (int)ofMap(x, 0, ofGetWidth(), 1, 5, true);
    amplitude = ofMap(y, 0, ofGetHeight(), 0.0, .10, true);
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
