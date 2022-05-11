#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //font.load("framd.ttf", 200, true, true, true);
    font.load("ChessType.ttf", 100, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    //ofEnableDepthTest();
    cam.begin();
    //cam.enableOrtho();
    
    vector < ofPath > paths = font.getStringAsPoints("22 : 2 : 22");
    ofSetColor(255);
    ofTranslate(-200,-200);
    ofScale(1, -1);

    for (int i = 0; i < paths.size(); i++){
        paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector < ofPolyline > lines = paths[i].getOutline();
        for (int j = 0; j < lines.size(); j++){

            lines[j].setClosed(true);
            lines[j] = lines[j].getResampledBySpacing(0);


            for (int k = 0; k < 30; k ++){
            ofPushMatrix();
            ofRotateYDeg(45);
                ofTranslate(40*k, -20*k);
                ofSetColor(255, 255-(k*15*sin(ofGetElapsedTimef())), 255-(50*k*sin(ofGetElapsedTimef())));
            //for (int k = 0; k < lines[j].size(); k++){
                //lines[j][k].x += mouseX * sin(lines[j][k].y * 0.04 + ofGetElapsedTimef() + i);
            //}
                if (k < 1){
                    ofFill();
                }
            lines[j].draw();
            ofPopMatrix();
        }
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
