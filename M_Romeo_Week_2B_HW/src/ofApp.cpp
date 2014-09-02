#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(15);
    ofBackground(ofColor::black);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    chancePercentage = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.0, 1.0);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
        for (int i = 0; i < ofGetWidth(); i += 25) {
        
        for (int j = 0; j < ofGetHeight(); j += 25) {
            
            if (ofRandomf() > chancePercentage) {
                ofSetColor(ofColor::whiteSmoke);
                radius = ofRandom(10);
            } else {
                ofSetColor(ofColor::aquamarine, 150);
                radius = ofRandom(8, 10);

            }
            
            ofFill();
            ofCircle(i, j, radius);
            
            ofSetColor(ofColor::whiteSmoke);
            ofNoFill();
            ofCircle(i, j, radius);
        }
    }

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
