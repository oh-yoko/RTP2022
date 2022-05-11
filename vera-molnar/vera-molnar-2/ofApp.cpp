#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int w = 25;
   
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(1.5);
    ofSeedRandom(mouseX*1000);
    ofSetBackgroundColor(235, 235, 235);
    ofSetLineWidth(0.5);
    int w = 25;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            float s1 = exp(i)/12; //  scale factor (0.something-6) for increasing i 1-->6
            float cj = ofMap(i, 0, 5, 350, 650); // Traversing columns
            float ci = ofMap(j, 0, 5, 250, 550); // Traversing rows

            for (int k = 0; k <15; k++){
                ofNoFill();
                ofPushMatrix();
                ofSetColor(190*ofRandom(0.1,1),
                           125*ofRandom(0.1,1),
                           190*ofRandom(0.1,1));
                float offset = ofRandom(-s1, s1);
                ofTranslate(cj-(10*offset), ci-5*offset);
                ofRotateDeg(ofRandom(s1/4));
                ofBeginShape();
                float vF = s1;
                float v = ofRandom(-vF, vF);
                ofVertex(0+v,0+v);
                v = ofRandom(-vF, vF);
                ofVertex(0+v,45+v);
                v = ofRandom(-vF, vF);
                ofVertex(45+v, 45+v);
                v = ofRandom(-vF, vF);
                ofVertex(45+v,0+v);
                ofEndShape(true);
                ofPopMatrix();
            }
            
            //int frenzy = 0;
            //int offset = 0;
           // float c_offset = ofMap(i, 0, 5, exp(-6)/36, exp(6)/36); //centre offset
           // float c_offset = exp(i)/12;
//            for(int k = 0; k < 15; k++){
//                ofSetColor(190*ofRandom(0.1,1), 122*ofRandom(0.1,1), 190*ofRandom(0.1,1));
//                ofBeginShape();
//                ofNoFill();
//                float offset = ofRandom(0, c_offset);
//                ofVertex(cj-w-offset-ofRandom(0, frenzy/10), ci-w-ofRandom(-frenzy/10, frenzy/10)-offset/5);
//                offset = ofRandom(0, c_offset);
//                ofVertex(cj+w+offset+ofRandom(0, frenzy/10), ci-w-ofRandom(-frenzy/10, frenzy/10)-offset/5);
//                offset = ofRandom(0, c_offset);
//                ofVertex(cj+w+offset+ofRandom(0, frenzy/10), ci+w+ofRandom(-frenzy/10, frenzy/10)+offset/5);
//                offset = ofRandom(0, c_offset);
//                ofVertex(cj-w-offset-ofRandom(0, frenzy/10), ci+w+ofRandom(-frenzy/10, frenzy/10)+offset/5);
//                ofEndShape(true);
//
//
//            }
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
