#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("lisas.png");
    ofRectangle targetDim(0, 0, 400, 480);
    ofRectangle imgDim(0, 0, img.getWidth(), img.getHeight());
    targetDim.scaleTo(imgDim);
    img.crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
    img.resize(400, 480);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0,0, 0);

    for (int i =  0; i < img.getHeight(); i+=3){
        for (int j = 0; j < img.getWidth(); j+=3){
            int brightness = img.getColor(j, i).getBrightness();
            ofSetColor(brightness, brightness, brightness);
            ofDrawRectangle(100+j, i+100, 5, 5);
        }
    }
    
    for (int i =  0; i < img.getHeight(); i+=5){
        ofPolyline line;
        for (int j = 0; j < img.getWidth(); j++){
            int brightness = img.getColor(j, i).getBrightness();
            line.addVertex(60+j+img.getWidth(), 120+i+ofMap(brightness, 0, 255, -30, 30));
        }
        ofSetColor(cos(i/50)*255, 40, sin(i/50)*255);
        line.draw();
    }
    
    for (int i =  0; i < img.getHeight(); i+=5){
        for (int j = 0; j < img.getWidth(); j+=5){
            int brightness = img.getColor(j, i).getBrightness();
            ofSetColor(brightness);
            ofDrawRectangle(j+2*(img.getWidth()+75), 100+i+ofMap(brightness, 0, 255, -10, 10), 5, 2);
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
