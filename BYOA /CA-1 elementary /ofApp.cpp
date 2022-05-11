#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Initialize all CA boxes
    for (int c = 0; c < 256; c++){
        for (int i = 0; i < x; i++){
            for (int j = 0; j < N; j++){
                if ((i == (x+1)/2) && (j==0)){
                state[i][j][c] = 1;
                }
                else {
                    state[i][j][c] = 0;
                }
            }
        }
    }
    
    // Compute binary rule for each CA box (0-255)
    for (int c = 0; c < 256; c++){
        int TEMP = c;
        for (int i = 0; i < 8; i++){
            RULE_BIN[i][c] = TEMP % 2;
            TEMP = (int)floor(TEMP/2);
        }
    }
     
    int step = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (step <= 15){
    for (int j=step; j<step+1; j++){
        for (int c = 0; c < 256; c++){
        state[0][j][c] = state[0][j-1][c];
        state[x-1][j][c] = state[x-1][j-1][c];
        for(int i = 1; i < x-2; i++){
            int NUM = 4*state[i-1][j-1][c] + 2*state[i][j-1][c] + state[i+1][j-1][c];
            state[i][j][c] = RULE_BIN[NUM][c]; // Assign the state of current cell
            //cout << "ROW"<<j<<"COL"<<i<<"VAL"<<ROW_CURR[j][i]<<endl;
            }
        }
    }
    }
    else {
    }
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int c = 0; c < 256; c ++){
        for (int j=0; j<N; j++){
            for (int i = 0; i<x; i++){
                if(state[i][j][c] == 1){
                    ofSetColor(0);
                }
                else {
                    ofSetColor(255);
                }
                int cx = ((c%16)*(box_x+gap_x)) + i*cell;
                int cy = (((int)floor(c/16))*(box_y+gap_y)) + j*cell;
                cout << "Coordinates for" << i <<"-"<< j << "-"<< cx << "-" << cy<< endl;
                ofDrawRectangle(cx, cy, cell, cell);
            }
        }
    }
    
    
    if (step <=15){
        step+=1;
    }
    else {
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
