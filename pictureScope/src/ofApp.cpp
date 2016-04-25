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

    density = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    mvp.update();
}


//--------------------------------------------------------------
void ofApp::draw(){

	fbo.begin();
		/*if (mvp.key1){
			ofBackground( (int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255)  );	
			mvp.key1 = 0;
		}*/
	    ofBackground(220,255,200);	

    
    ofEnableDepthTest();
    
    texture.getTexture().bind();
    // Plane //
   // plane.rotate(mvp.knob1 * 360, 1.0, 0.0, 0.0);
   // plane.rotate(mvp.knob2 * 360, 0, 1.0, 0.0);
   // plane.rotate(mvp.knob3 * 360, 0, 0, 1.0);
    plane.set( mvp.knob2 * 200 + 1, mvp.knob3 * 200 + 1);
    
    ofFill();
    density = 0;
	for (unsigned int i = 0; i < mvp.left.size(); i++){
        plane.setPosition(i * 4, 360 - (mvp.left[i] * 400.0f * (mvp.knob1 * 5 + 1)), 0);
        density++;
        if (density > (mvp.knob4 * mvp.left.size() + 3)){
            plane.draw();
            density = 0;
        }
    }
    
    texture.getTexture().unbind();
    // End plane stuff
		
    ofSetColor(0,0,0);    
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
