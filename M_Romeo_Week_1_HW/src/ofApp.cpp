#include "ofApp.h"
#define TWOPI (2 * PI)

//--------------------------------------------------------------
void ofApp::setup(){

    /// #Exploration 1 ///

    cirPosX = ofGetWidth() / 2;
    cirPosY = ofGetHeight() / 2;
    radius = 5;
    cirResolution = 100;
 
    rectW = 50;
    rectH = rectW;
    
    w = ofGetWidth();
    h = ofGetHeight();
    
    cout << "TWOPI: " << TWOPI << endl;
    //////
    
    /// #Exploration 2 ///

    colorRectPosX = w / 2;
    colorRectPosY = h / 2;
    colorRectSize = 100;
    //////
    
    /// #Exploration 3 ///

    img.allocate(w, h, OF_IMAGE_COLOR);
    
    for (int x = 0; x < w; x+=2) {
		for (int y = 0; y < h; y+=3) {
            
            ofVec2f point1, center1;
            point1.set(x, y);
            center1.set(w * 0.50, h * 0.50); // put center of orb at 10 percent x and y
            float dist1 = point1.distance(center1);
            int redVal = ofMap(dist1, 0, w, 0, 255, true);
			
            val1 = redVal;

            
            ofVec2f point2, center2;
            point2.set(x, y);
            center2.set(w * 0.50, h * 0.50); // put center of orb at 10 percent x and y
            float dist2 = point2.distance(center2);
            int greenVal = ofMap(dist2, 0, 100, 175, 0, true);
			
            val2 = greenVal;
            
            ofVec2f point3, center3;
            point3.set(x, y);
            center3.set(w * 0.50, h * 0.50); // put center of orb at 10 percent x and y
            float dist3 = point3.distance(center3);
            int blueVal = ofMap(dist3, 0, 450, 255, 0, true);
            
			val3 = blueVal ;
    
            ofColor pixCol;
            pixCol.set(val1, val2, val3);
            
            img.setColor(x, y, pixCol);
		}
	}
    
    img.update();
    /////
    
    
    /// #Exploration 4 ///
    
    ///Animation: in computer programming, change of parameter over time
    
    circX = ofGetWidth() * 0.50;
    circY = 0;
    circRadius = 10;
    circColor = ofColor::black;
}

//--------------------------------------------------------------
void ofApp::update(){


    if (circX < ofGetMouseX()) {
        
        circX = circX + ofMap(ofGetMouseX(), 0, w, 0, 10);
    } else {
        
        circX = circX - ofMap(ofGetMouseX(), 0, w, 10, 0);
    }
    
    circY += 0.10;
    
    circSin = 75 * sin(circY);

    alpha = ofMap(circSin, -75, 75, 10, 200);
    
    circRadius = circRadius + 1.0;

    if (circRadius > 100) {
        circRadius = 10;
    }
    
    circColor.b = circColor.b + 1;
    
    if (circColor.b > 200) {
        circColor.b = 15;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    /// #Exploration 1 ///

    if (exploration1) {
        
    ofPushStyle();
    ofSetCircleResolution(cirResolution);
    ofNoFill();
    
    for (int i = 0; i < 50; i++) {
        ofCircle(cirPosX + i, cirPosY + i, radius * i);

    }
    
    for (int i = 0; i < 200; i += 50) {
    ofSetColor(ofColor::white, i);
    ofFill();
    float inc = TWOPI / 3;

    ofBeginShape();
    for (float radians = 0; radians < TWOPI; radians += inc){
        float x = ofMap(cirPosX, 0, ofGetWidth() / 2, 0, 300) + sin( radians + PI ) * 200;
        float y = ofMap(cirPosY, 0, ofGetHeight() / 2, 0, 200) + cos( radians + PI - i ) * 200;
        ofVertex(x, y);
    }
    ofEndShape();
        
    int rectOffsetX = 75;
    int rectOffsetY = 50;
    ofRect(cirPosX + rectOffsetX, cirPosY + rectOffsetY, i + rectW, i + rectH );
        
        }
        ///       END         ///
        ofPopStyle();

    }
    
    
    /// #Exploration 2 ///

    if (exploration2) {
        ofPushStyle();
        ofSetCircleResolution(8);
    for (int i = 0; i < 20; i++){ //draw 20 boxes
        
        int hue, saturation, brightness;
        
                hue = ofMap(mouseX, 0, ofGetWidth(), 0, 255, true);
                saturation = ofMap(i, 0, 19, 0, 255);
                brightness = ofMap(mouseX, 0, ofGetWidth(), 0, 255, true);
        
        ofColor col;
        col.setHsb(hue, saturation, brightness);
        ofSetColor(col, ofMap(i, 0, 20, 0, 200, true));
        ofFill();
        ofCircle(ofGetWidth() / 2, ofMap(i, 0, 20, 0, ofGetHeight()), ofMap(i, 0, 20, 10, 100));
        
        }
        
        ofPopStyle();
    }
    
    ///         END         ///
    
    
    /// #Exploration 3 ///
    
    if (exploration3) {
        
    img.draw(0,0);
        
    }
    
    
    /// #Exploration 4 ///
    
    if (exploration4) {
        
        ofPushStyle();
        ofSetCircleResolution(35);
        ofSetColor(255);
        ofNoFill();
        ofCircle(circX, ofGetHeight() * 0.50 + circSin, 100);
        ofSetColor(ofColor::crimson, alpha);
        ofFill();
        ofCircle(circX, ofGetHeight() * 0.50 + circSin, 100);
        ofSetColor(ofColor::whiteSmoke);
        ofCircle(ofGetWidth() * 0.50, ofGetHeight() * 0.50, circRadius);
        ofSetColor(circColor);
        ofCircle(ofGetWidth() * 0.50, ofGetHeight() * 0.20, 50);
        
        ofPopStyle();
        
    }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case '1':
            exploration1 = !exploration1;
            break;
        case '2':
            exploration2 = !exploration2;
            break;
        case '3':
            exploration3 = !exploration3;
            break;
        case '4':
            exploration4 = !exploration4;
            break;
            
        default:
            break;
    }
    
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
