#include "ofApp.h"
#include "ofxBlur.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
//    blur.setup();
//    blur.setScale(0.01);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    float t1 = ofGetElapsedTimef()*0.1;
    float t = 2*sin(t1)*sin(t1);
 //   float t = 0;
    ofSetBackgroundColor(0, 0, 0);
    ofNoFill();
        // Hot Pink Triangles

        for (int i = 0; i <16; i++){
        float side = ofMap(i, 1, 16, 20, 180);
        //float phase = ofMap(i, 0, 13, 0, 2.7*pi);
            float rad = ofMap(i, 1, 16, 100, 250);
            ofSetColor(255, 200, 200, 255);
            ofSetLineWidth(3);

            // Define movement of centre
            float x_loc = 412 - rad*cos(i*t);
            float y_loc = 400 + rad/2*sin(i*t);
            ofBeginShape(); //Begin drawing one triangle centered at (x_loc, y_loc)
            for (int j = 0; j < 3; j++) {
              float angle_hex = ofMap(j, 0, 3, 0, TWO_PI);
              ofPoint pos;
              pos.x = x_loc + side * cos(angle_hex + 7*PI/6);
              pos.y = y_loc + side * sin(angle_hex + 7*PI/6);
              ofVertex(pos);
            }
            ofEndShape(true);
            // Glow
            ofSetColor(255, 200, 200, 120);
            ofSetLineWidth(10);

            // Define movement of centre
            ofBeginShape(); //Begin drawing one triangle centered at (x_loc, y_loc)
            for (int j = 0; j < 3; j++) {
              float angle_hex = ofMap(j, 0, 3, 0, TWO_PI);
              ofPoint pos;
              pos.x = x_loc + side * cos(angle_hex + 7*PI/6);
              pos.y = y_loc + side * sin(angle_hex + 7*PI/6);
              ofVertex(pos);
            }
            ofEndShape(true);
        }
    
    
    // Red Background Triangles

    for (int i = 0; i <16; i++){
    float side = ofMap(i, 1, 16, 20, 180);
    //float phase = ofMap(i, 0, 13, 0, 2.7*pi);
        float rad = ofMap(i, 1, 16, 100, 250);
        ofSetColor(150, 0, 0, 75);
        ofSetLineWidth(5);
        // Define movement of centre
        float x_loc = 612 - rad*cos(i*t + PI);
        float y_loc = 375 - rad/2*sin(i*t + PI);
        ofBeginShape(); //Begin drawing one triangle centered at (x_loc, y_loc)
        for (int j = 0; j < 3; j++) {
          float angle_hex = ofMap(j, 0, 3, 0, TWO_PI);
          ofPoint pos;
          pos.x = x_loc + side * cos(angle_hex + 7*PI/6);
          pos.y = y_loc + side * sin(angle_hex + 7*PI/6);
          ofVertex(pos);
        }
        ofEndShape(true);
        // Glow
        ofSetColor(150, 0, 0, 30);
        ofSetLineWidth(10);
        ofBeginShape(); //Begin drawing one triangle centered at (x_loc, y_loc)
        for (int j = 0; j < 3; j++) {
          float angle_hex = ofMap(j, 0, 3, 0, TWO_PI);
          ofPoint pos;
          pos.x = x_loc + side * cos(angle_hex + 7*PI/6);
          pos.y = y_loc + side * sin(angle_hex + 7*PI/6);
          ofVertex(pos);
        }
        
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
