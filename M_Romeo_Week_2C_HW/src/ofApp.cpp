
#include "ofApp.h"
#define TWOPI (2 * PI)

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetLineWidth(1.0);
    ofSetCircleResolution(35);
    circPos.set(ofGetWidth() * .5, ofGetHeight() * .5);
    radius = 50;
    circRes = 60;
    
    complexity = 5;
    
    imgWidth = 255;
    imgHeight = 255;
    img.allocate(imgWidth, imgHeight, OF_IMAGE_COLOR_ALPHA);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //circ
    complexity = ofMap(mouseX, 0, ofGetWidth(), 0.001, 1.0, true);
    scale = ofMap(mouseY, 0, ofGetHeight(), 0.0, 2.0, true);
    
    //img
    complexityImg = ofMap(mouseX, 0, ofGetWidth(), 0.001, 0.009, true);
    scaleImg = ofMap(mouseY, 0, ofGetHeight(), 0, 255, true);
    
    for (int x = 0; x < imgWidth; x++){
		for (int y = 0; y < imgHeight; y++){
            
            int red = ofNoise(x * complexityImg, y * complexityImg) * scaleImg;
            
            //int green = ofNoise(x * complexityImg, y * complexityImg, ofGetElapsedTimef()) * scaleImg;
            
            int blue = ofNoise(x * complexityImg * 0.01, ofGetElapsedTimef() * 0.3) * scaleImg;
            
            ofVec2f point, center;
            point.set(x, y);
            center.set(imgWidth * 0.5, imgHeight * 0.5);
            float dist = point.distance(center);
            

            if (dist > 70) {
                
                alpha = 0;
            
            } else {
                
                alpha = ofNoise(dist * complexityImg, ofGetElapsedTimef() * 0.2) * scaleImg;

            }
            
            img.setColor(x, y, ofColor(red, 0, blue, alpha));
            
		}
	}
    
    img.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
   
    //draw the circle vertex by vertex
    float inc = TWOPI / circRes;
    
    ofPushMatrix(); {
    
    ofTranslate(circPos.x, circPos.y);
    ofScale(2.0, 2.0);
    
    ofSetColor(ofColor::white);
    ofFill();
    ofBeginShape();
    for (float radians = 0; radians < TWOPI; radians+=inc){
        float x = sin(radians) * (radius - 15);
        float y = cos(radians) * (radius - 15);
        ofVertex(x, y + ofSignedNoise((ofGetElapsedTimef())));
    }
    ofEndShape();
    
    for (int i = 0; i < 5; i++) {
    int sparkle = ofRandom(ofMap(i, 0, 5, 150, 255));
    ofSetColor(sparkle, 0, sparkle, sparkle);
    ofNoFill();
    ofBeginShape();
    for (float radians = 0; radians < TWOPI; radians+=inc){
        float x = sin(radians) * (radius + ofSignedNoise((ofGetElapsedTimef() + radians + i) * (complexity)) * 25 );
        float y = cos(radians) * (radius + ofSignedNoise((ofGetElapsedTimef() + radians + i) * (complexity)) * 25 );
        ofVertex(x + i, y);
    }
    ofEndShape();
    
    }
    
    ofSetColor(ofColor::white, 250);
    ofFill();
    
    for (float radians = 0; radians < .1; radians+=inc){
        float x = sin(radians) * (radius + ofSignedNoise((ofGetElapsedTimef() + radians) * complexity) * 25 );
        float y = cos(radians) * (radius + ofSignedNoise((ofGetElapsedTimef() + radians) * complexity) * 25 );
            
        ofCircle(x, y, 5);
        

        }
        
    } ofPopMatrix();
    
    img.draw(ofGetWidth() * .37, ofGetHeight() * .33);


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
