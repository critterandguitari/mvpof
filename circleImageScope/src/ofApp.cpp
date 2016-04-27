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


    // read the directory for the images
    // we know that they are named in seq
    ofDirectory dir;
    
    int nFiles = dir.listDir("/media/pi/ORGANELLE/images"); 
    numImages = 0;
    imageIndex = 0;
    if(nFiles) {
        
        for(int i=0; i<dir.size(); i++) { 
            
            // add the image to the vector
            string filePath = dir.getPath(i);
            images.push_back(ofImage());
            images.back().load(filePath);
            images.back().getTexture().setTextureWrap( GL_REPEAT, GL_REPEAT );
            numImages++;
        }
        
    } 
    else ofLog(OF_LOG_WARNING) << "Could not find folder";
    // images


    density = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    mvp.update();
    fill = 0;
}

//--------------------------------------------------------------
void ofApp::draw(){

	fbo.begin();

		if (mvp.key1){
			ofBackground( (int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255)  );	
			mvp.key1 = 0;
		}

    if (mvp.key2) {
        imageIndex++;
        imageIndex %= numImages;

        mvp.key1 = 0;
    }
    
    ofEnableDepthTest();
    
    // Begin BG
    /*float w, h;
    ofFill();
  */
  // End BG


    // Begin circle Scope

    ofNoFill();
    ofSetLineWidth(2);	
    ofSetColor(mvp.knob6*255,mvp.knob7*255,mvp.knob8*255);    

    images[imageIndex].getTexture().bind();
    plane.set(mvp.knob3 * 500, mvp.knob4 * 500);
        float x0,y0;
        for (unsigned int i = 0; i < mvp.left.size() ; i++){
            float R = 1000 * mvp.knob2;

            //R = R + mvp.left[i] * mvp.knob1 * 500;  // for regular effect
            R = R + mvp.left[i] * mvp.knob1 * R * 100; // for cool effect
            float x = R*cos(((float)i /  mvp.left.size()) * TWO_PI) + ofGetWidth() / 2;
            float y = R*sin(((float)i /  mvp.left.size()) * TWO_PI) + ofGetHeight() / 2;
            
            density++;
            if (density > (mvp.knob5 * mvp.left.size() + 3)){
                plane.setPosition(x, y, 0);
                plane.draw();
                density = 0;
            }
               
            if (i==0){   // store first
                x0 = x;
                y0 = y;
            }
        }
    images[imageIndex].getTexture().unbind();
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
