#pragma once

#include "ofMain.h"
#include "ofxMVP.h"

class ofApp : public ofBaseApp {
	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        // mvp stuff (audio and midi / ctrl input)
        MVP mvp;
		ofFbo fbo;
		void audioIn(float * input, int bufferSize, int nChannels); 
	
        int density;	
        unsigned int fill;

        ofImage texture;
        ofPlanePrimitive plane;

        vector <ofImage> images;
		unsigned int numImages;
		unsigned int imageIndex;

};
