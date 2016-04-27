#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // setup mvp environment
    mvp.setup(this);

    ofHideCursor();
	ofSetVerticalSync(true);
	fbo.allocate(ofGetWidth(), ofGetHeight() );

    // Begin Plane suff
    ofSetVerticalSync(true);
    // GL_REPEAT for texture wrap only works with NON-ARB textures //
    ofDisableArbTex();
    texture.load("/media/pi/ORGANELLE/BG/1.png");
    texture.getTexture().setTextureWrap( GL_REPEAT, GL_REPEAT );
    // end Plane stuff 

}

//--------------------------------------------------------------
void ofApp::update(){
    mvp.update();
}


//--------------------------------------------------------------
void ofApp::draw(){

	fbo.begin();
	/*	if (mvp.key1){
			ofBackground( (int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255)  );	
			mvp.key1 = 0;
		}
*/
    ofSetColor((int)(mvp.smoothedVol*255*40) % 255, (int)(mvp.smoothedVol*255*20) % 255,(int)(mvp.smoothedVol*255*40) % 255);    
    //ofSetHexColor(mvp.smoothedVol * 0xFFFFFF);    
    
    ofEnableDepthTest();
    
    texture.getTexture().bind();
    // Plane //
    float w, h;
    w  = ofMap(mvp.smoothedVol, 0, 1, 1280 * mvp.knob1 * 10, 1280 * mvp.knob2 * 10);
    h  = ofMap(mvp.smoothedVol, 0, 1, 720 * mvp.knob1 * 10, 720 * mvp.knob2 * 10);
    plane.set(w,h);
    
    ofFill();
    plane.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    plane.draw();
    
    texture.getTexture().unbind();
    // End plane stuff
	
    ofSetColor(190);    
	ofDrawBitmapString("fps:" + ofToString(ofGetFrameRate(),0),ofGetWidth()-80,20);
	

	
	fbo.end();
	fbo.draw(0,0);

}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){	
    // just pass it to mvp for conditioning
    mvp.audioIn(input, bufferSize, nChannels);
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
