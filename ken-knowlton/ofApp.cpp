#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("wheatstack.jpg");
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetLineWidth(2);
    for (int i = 0; i < img.getWidth(); i+=5){
        for (int j = 0; j < img.getHeight(); j+=10){
            ofColor color = img.getColor(i, j);
            
            if (color.r > color.g && color.r > color.b) {
                color.r = 40;
            }
            if (color.g > color.r && color.g > color. b) {
                color.g = 40;
            }
            if (color.b > color.r && color.g > color.b){
                color.b =125;
            }
            ofSetColor(color);
            ofPushMatrix();
            ofTranslate(100+i, 100+j);
            float deg = ofMap(color.r, 0, 255, 0, 90);
            ofRotateDeg(deg);
            ofDrawLine(-5, -7, 5, 7);
            //ofDrawCircle(100+i, 100+j, 5);
            ofPopMatrix();
            
        }
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
