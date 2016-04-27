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
    fill = 0;
}

//--------------------------------------------------------------
void ofApp::draw(){

	fbo.begin();
	    ofBackground(220,255,200);	
    ofEnableDepthTest();
    
    // Begin BG
    ofSetColor((int)(mvp.smoothedVol*255*40) % 255, (int)(mvp.smoothedVol*255*20) % 255,(int)(mvp.smoothedVol*255*40) % 255);    
    texture.getTexture().bind();
    float w, h;
    w  = ofMap(mvp.smoothedVol, 0, 1, 1280 * mvp.knob1 * 10, 1280 * mvp.knob2 * 10);
    h  = ofMap(mvp.smoothedVol, 0, 1, 720 * mvp.knob1 * 10, 720 * mvp.knob2 * 10);
    plane.set(w,h);
    ofFill();
    plane.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    plane.draw();
    texture.getTexture().unbind();
    // End BG


    // Begin circle Scope
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
        for (unsigned int i = 0; i < mvp.left.size() ; i++){
            float R = 1000 * mvp.knob4;

            //R = R + mvp.left[i] * mvp.knob1 * 500;  // for regular effect
            R = R + mvp.left[i] * mvp.knob3 * R * 100; // for cool effect
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
    // end circle scope

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
