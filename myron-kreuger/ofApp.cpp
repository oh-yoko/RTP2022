#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.setup(640, 480);
    
    threshold.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_COLOR);
    
    for (int i = 0; i < 20; i ++){
        float y = ofMap(i, 0, 20, 0, grabber.getHeight());
        float x = 0;
        ofPoint pt;
        pt.set(x, y);
        points.push_back(pt);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    // Detecting jellyfish
    
    if(grabber.isFrameNew()){
    for (int i = 0; i < grabber.getWidth(); i++){
        for (int j = 0; j < grabber.getHeight(); j++){
            ofColor color = grabber.getPixels().getColor(i, j);
            if(color.r > 210 && color.g < 100 && color.b < 100){
                threshold.setColor(i, j, ofColor(255, 0, 0));
        }
            else {
                threshold.setColor(i, j, ofColor(0));
            }
        }
    }
    }
    
    // Running centres of fish/bubbles across the screen
    
    for (int i = 0; i < 20; i ++){
        points[i].x += 1;
        if (points[i].x >= 640){
            points[i].x = 0;
        }
    }
    
    // Mapping physics of fishes when they touch the jellyfish
    
    for (int i = 0; i < 20; i ++){
        ofColor stop = threshold.getColor(points[i].x, points[i].y);

        if (stop.r == 255){
            points[i].x += 1;
        }
            else {
            for (int j = points[i].x; j>0; j--){
                ofColor bounce = threshold.getColor(j, points[i].y);
                if (bounce.r == 255){
                    points[i].x = j;
                    break;
                }
            }
        }
        if (points[i].x >= 640){
                   points[i].x = 0;
        }
    }
    
    threshold.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    threshold.draw(0, 0);
    grabber.draw(grabber.getWidth(),0);
    
    ofSeedRandom(mouseX);
    
    // Drawing fishes
    ofSetLineWidth(2);
    for (int i = 0; i < 20; i ++){
        // Time-tinted fishies
        ofSetColor(255*(sin(5*ofGetElapsedTimef())), 127*(cos(5*ofGetElapsedTimef())), 127);
        ofPushMatrix();
        ofNoFill();
        ofTranslate(points[i].x, points[i].y);
        ofRotateZDeg(90*ofRandom(100));
        ofBeginShape();
        ofVertex(0, 0);
        ofVertex(10, 10);
        ofVertex(20, 0);
        ofVertex(40, 15);
        ofVertex(20, 30);
        ofVertex(10, 20);
        ofVertex(0, 30);
        ofVertex(5, 15);
        ofVertex(0,0);
        ofEndShape();
        ofPopMatrix();

       // ofDrawCircle(points[i].x, points[i].y, 4);
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
