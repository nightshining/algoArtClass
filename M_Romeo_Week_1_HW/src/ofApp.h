
#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

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

    
    ///KEYS 1 - 4 for each exploration
    bool exploration1, exploration2, exploration3, exploration4;

    
    /// #Exploration 1 ///

    int cirPosX, cirPosY, radius, cirResolution;
    int rectW, rectH;
    int w, h;
    
    /// #Exploration 2 ///
    
    int colorRectPosX, colorRectPosY, colorRectSize;
    
    /// #Exploration 3 ///
    
    ofImage img;
    int val1, val2, val3;
    
    /// #Exploration 4 ///
    float circX, circY, circSin;
    float circRadius;
    ofColor circColor;
    int alpha;
    
};
