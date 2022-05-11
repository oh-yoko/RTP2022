#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Initial condition
    for (int i = 0; i < N_Y; i++){
        for(int j = 0; j < N_X; j++){
            if(i == 0 && j == N_X/2){
                ROW_CURR[i][j] = 1;
            }
            else{
            ROW_CURR[i][j] = 0;
            }
           // cout << ROW_CURR[i][j] << endl;
        }
    }
 
    // Store ternary rule
    for(int i = 7; i > 0; i--){
        int div = pow(3,i-1);
        int quo = floor(TEMP/div);
        RULE_TERN[i-1] = quo;
        TEMP = TEMP - (div*quo);
        //cout << "Rule Ternary #" << i-1 << RULE_TERN[i-1] << endl;
    }
   





}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int j=step; j<step+1; j++){
        ROW_CURR[j][0] = ROW_CURR[j-1][0];
        ROW_CURR[j][N_X-1] = ROW_CURR[j-1][N_X-1];
        for(int i = 1; i < N_X-1; i ++){
            int NUM = ROW_CURR[j-1][i-1] + ROW_CURR[j-1][i] + ROW_CURR[j-1][i+1];
            ROW_CURR[j][i] = RULE_TERN[NUM]; // Assign the state of current cell
            //cout << "ROW"<<j<<"COL"<<i<<"VAL"<<ROW_CURR[j][i]<<endl;
            }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int j = 0; j < PIX_Y; j+=CELL){
        for (int i = 0; i < PIX_X; i+=CELL){
            if(ROW_CURR[j/CELL][i/CELL] == 2){
                ofSetColor(255, 255, 255);
            }
            else if(ROW_CURR[j/CELL][i/CELL] == 1) {
                ofSetColor(180, 207, 217);
            }
            else {
                ofSetColor(0, 29, 62);
            }
            ofDrawRectangle(i, j, 2, 2);
        }
    }
    
    if(step<= N_Y){
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
