#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    float radius; //radius of the circle
    float circRes; //"circle resolution" = how many points in the circle
    float inc; //increment in radians
    float scale;
    
    //sine
    float wave(float x);
    float frequency, amplitude;
    
    //shape
    void shape(ofColor shapeColor, float scale);
};
