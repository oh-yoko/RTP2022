#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    
    ofSeedRandom(mouseX);
    float offset = mouseY*0.1;
    
  
    for (int i = 1; i < 26; i ++){
        float w = ofMap(i, 0, 24, 5, 100);
        float inv_scale = (1/(1+exp(i)));
      float inv_scale2 = (25-i)/25;  // Declaring an inverse scale factor (0-1) with increasing i
        //float  c = ofRandom(350*inv_scale, 450*inv_scale);  // Displacing centre within 50 pixels of centr
        float c = inv_scale2*ofRandom(100, 200);
        ofNoFill();
        ofBeginShape();

        float y_1 = ofRandom(-offset, offset);
        float y_2 = ofRandom(-offset, offset);
        ofVertex((400-w+inv_scale*ofRandom(-offset,offset)),400+c+w+y_1);
        ofVertex((400+w+inv_scale*ofRandom(-offset,offset)),400+c+w+y_1);
        ofVertex((400+w+inv_scale*ofRandom(-offset,offset)),400-c-w+y_2);
        ofVertex((400-w+inv_scale*ofRandom(-offset,offset)),400-c-w+y_2);
        ofEndShape(true);
    }

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
