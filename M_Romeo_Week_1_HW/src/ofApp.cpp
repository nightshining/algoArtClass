#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    cirPosX = ofGetWidth() / 2;
    cirPosY = ofGetHeight() / 2;
    radius = 5;
    cirResolution = 100;
    
    triPos1.set(0,0);
    triPos2.set(1,0);
    triPos3.set(0.50, 0.50);
    
    w = ofGetWidth();
    h = ofGetHeight();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetCircleResolution(cirResolution);
    ofSetColor(ofColor::whiteSmoke);
    ofNoFill();
    for (int i = 0; i < 50; i++) {
        
        ofCircle(cirPosX + i, cirPosY + i, radius * i);
    }
    
    
    ofSetColor(ofColor::black);
    ofNoFill();
    ofTranslate(w / 2, h / 2);
    for (int i = 0; i < 500; i += 10) {
        
        ofTriangle(triPos1 * i, triPos2 * i, triPos3 * i);

    }
    
    
    ofSetColor(ofColor::crimson);
    ofNoFill();
    
    
    ofBeginShape();
    for (float i = 0; i < 500; i += 5){
        float x = sin(i);
        ofVertex(x, h / 2);
    }
    ofEndShape();
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
