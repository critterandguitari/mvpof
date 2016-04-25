#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // setup mvp environment
    mvp.setup(this);

	ofSetVerticalSync(true);
	ofSetCircleResolution(80);
	ofBackground(0);
    fill = 0;
    fbo.allocate(ofGetWidth(), ofGetHeight() );
}

//--------------------------------------------------------------
void ofApp::update(){
    mvp.update();
}


//--------------------------------------------------------------
void ofApp::draw(){
//	fbo.begin();
	    ofBackground(220,255,200);	
	ofSetColor(225);
	if (mvp.key1){
		mvp.key1 = 0;
        fill++;
        fill &= 1;
	}


    // Fill or noFill will make it filled in or just a line 
	if(fill) ofFill();
    else ofNoFill();

    ofSetLineWidth(2);	
    ofSetColor(mvp.knob6*255,mvp.knob7*255,mvp.knob8*255);    

     ofBeginShape();
        float x0,y0;
        float R = 800 * mvp.knob2;
        for (unsigned int i = 0; i < mvp.left.size() ; i++){

            R = R + mvp.left[i] * mvp.knob1 * 800;
            float x = R*cos(((float)i /  mvp.left.size()) * TWO_PI) + ofGetWidth() / 2;
            float y = R*sin(((float)i /  mvp.left.size()) * TWO_PI) + ofGetHeight() / 2;
            ofVertex(x, y);
            if (i==0){   // store first
                x0 = x;
                y0 = y;
            }
        }
        ofVertex(x0,y0);  // connect last to first
     ofEndShape(false);


     ofSetColor(255-mvp.knob6*255,255-mvp.knob7*255,255-mvp.knob8*255);    

     ofBeginShape();
        R = 1000 * mvp.knob3;
        for (unsigned int i = 0; i < mvp.left.size() ; i++){

            R = R + mvp.left[i] * mvp.knob1 * 200;
            float x = R*cos(((float)i /  mvp.left.size()) * TWO_PI) + ofGetWidth() / 2;
            float y = R*sin(((float)i /  mvp.left.size()) * TWO_PI) + ofGetHeight() / 2;
            ofVertex(x, y);
            if (i==0){   // store first
                x0 = x;
                y0 = y;
            }
        }
        ofVertex(x0,y0);  // connect last to first
     ofEndShape(false);

    ofSetColor(50);    
	ofDrawBitmapString("fps:" + ofToString(ofGetFrameRate(),0),ofGetWidth()-80,20);
	

    mvp.draw();
	
//	fbo.end();
//	fbo.draw(0,0);

}



//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){	

    // just pass it to mvp for conditioning
    mvp.audioIn(input, bufferSize, nChannels);

	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
/*	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;

	}*/
	
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
