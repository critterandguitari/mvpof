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
	fbo.begin();
    if (mvp.newSound){
	    ofBackground(220,255,200);	
        mvp.newSound = false;
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
/*                
        ofBeginShape();
        for (unsigned int i = 0; i < mvp.left.size(); i++){
            ofVertex(i*5, 360 - mvp.left[i]*500.0f* (mvp.knob1*5 +1));
        }
        ofEndShape(false);
  */

     ofBeginShape();
        for (unsigned int i = 0; i < mvp.left.size() ; i++){
            float R = 200;

            R = R + mvp.left[i] * (mvp.knob1*R +1) * 10;
            float x = R*cos(((float)i /  mvp.left.size()) * TWO_PI) + ofGetWidth() / 2;
            float y = R*sin(((float)i /  mvp.left.size()) * TWO_PI) + ofGetHeight() / 2;
            ofVertex(x, y);
        }
     ofEndShape(false);
	
    ofSetColor(190);    
	ofDrawBitmapString("fps:" + ofToString(ofGetFrameRate(),0),ofGetWidth()-80,20);
	

    mvp.draw();
    }
	
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
