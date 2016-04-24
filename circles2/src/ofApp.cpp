#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // setup mvp environment
    mvp.setup(this);

	ofSetVerticalSync(true);
	ofSetCircleResolution(80);
	ofBackground(54, 54, 54);	
	fbo.allocate(ofGetWidth(), ofGetHeight() );
}

//--------------------------------------------------------------
void ofApp::update(){
    mvp.update();
}


//--------------------------------------------------------------
void ofApp::draw(){

	fbo.begin();
		if (mvp.key1){
			ofBackground( (int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255)  );	
			mvp.key1 = 0;
		}

    ofSetColor(mvp.knob1*255,mvp.knob2*255,mvp.knob3*255);
    
	ofNoFill();
    ofDrawCircle(mvp.knob1*ofGetWidth(),mvp.knob2*ofGetHeight(),mvp.knob3*ofGetHeight());
	
	
	
	fbo.end();
	fbo.draw(0,0);

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
