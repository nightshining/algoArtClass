#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //variables that effect the circle
    ofPoint circPos; //coordinates of the center of the circle
    float radius; //radius of the circle
    float circRes; //"circle resolution" = how many points in the circle
    
    float complexity; //complexity is analogous to frequency... but in NOT frequency
    float scale; // scale is analogous to amplitude (0.0, 1.0)
    
    ofImage img;
    int imgWidth, imgHeight;
    int alpha;
    float complexityImg, scaleImg;
   
    //ofSignedNoise: Returns -1.0 to 1.0
    //ofNoise: Returns 0.0 to 1.0
};
