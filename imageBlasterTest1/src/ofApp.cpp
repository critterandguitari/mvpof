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
    texture.load("plane.png");
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
		if (mvp.key1){
			ofBackground( (int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255)  );	
			mvp.key1 = 0;
		}

    ofSetColor(mvp.knob6*255,mvp.knob7*255,mvp.knob8*255);    
    
    ofEnableDepthTest();
    
    texture.getTexture().bind();
    // Plane //
    plane.rotate(mvp.knob1 * 360, 1.0, 0.0, 0.0);
    plane.rotate(mvp.knob2 * 360, 0, 1.0, 0.0);
    plane.rotate(mvp.knob3 * 360, 0, 0, 1.0);
    //plane.set( mouseX, mouseY );
    plane.set( mvp.knob5 * 500, mvp.knob6 * 500 );
    
//    material.begin();
    ofFill();
//    for (int i = 0; i<10; i++){
        plane.setPosition(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 0);
        plane.draw();
 //   }
 //   material.end();
    
    texture.getTexture().unbind();
    // End plane stuff

	
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
