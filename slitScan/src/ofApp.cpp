#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // set up the webcam with width and height we want to use:
    cam.setup(1280, 720);
    
    // allocate memory for our images!
    
    // the current camera frame
    currentFrame.allocate(1280, 720);
    
    // the result slit-scan image
    resultImage.allocate(1280, 720, GL_RGB);
    
    // clear the data in our fbo:
    resultImage.begin();
    ofClear(0,0,0);
    resultImage.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    // whenever we work with video, we need to call update()
    // (that way, we can receive the new frame from the webcam)
    cam.update();
    
    if(xpos == 0) {
        ofSaveFrame();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // copy the current frame from our webcam
    currentFrame.setFromPixels(cam.getPixels());
    
    // set ROI (region of interest) to a vertical line at the center of the image
    currentFrame.setROI(ofGetWidth()/2, 0, 10, ofGetHeight());
    
    // calculating the horizontal position (xpos) where we want to draw our ROI
    // we are using the modulo operator (%) so that we can start
    // drawing at the beginning whenever we reach the right border
    xpos = ofGetFrameNum() % ofGetWidth();
    
    // now let's draw this ROI onto out slit-scan result image:
    resultImage.begin();
    currentFrame.drawROI(xpos, 0);
    resultImage.end();
    
    // finally, we can draw the result image onto the screen!
    resultImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    // draw what the camera sees in the bottom right corner)
    cam.draw(ofGetWidth() - 200, ofGetHeight() - 140, 200, 140);
    
    // let's draw a little rectangle to highlight out ROI:
    ofNoFill();
    ofDrawRectangle(ofGetWidth() - 100, ofGetHeight() - 140, 3, 140);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
