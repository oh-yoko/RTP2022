#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSeedRandom(mouseX);

    // Palette 1: Lame Lambs and Sheep
//    colors[0] = ofColor(0, 0, 0);
//    colors[1] = ofColor(230, 159, 0);
//    colors[2] = ofColor(86, 180, 233);
//    colors[3] = ofColor(0, 158, 115);
//    colors[4] = ofColor(240, 228, 66);
//    colors[5] = ofColor(0, 114, 178);
//    colors[6] = ofColor(213, 94, 0);
//    colors[7] = ofColor(224, 121, 167);
    
    // Palette 2: Mordor
//    colors[0] = ofColor(0, 0, 0);
//    colors[1] = ofColor(0, 0, 0);
//    //colors[1] = ofColor(230, 159, 0);
//    colors[2] = ofColor(255, 50, 0);
//    colors[3] = ofColor(215, 52, 2);
//    colors[4] = ofColor(252, 100, 0);
//    colors[5] = ofColor(255, 117, 0);
//    colors[6] = ofColor(250, 192, 0);
//    colors[7] = ofColor(213, 94, 0);

    // Palette 3: Mehul's Lower Sitting Room
    colors[0] = ofColor(63, 67, 68); // Coal
    colors[1] = ofColor(60, 97, 167); // Dark dodgerblue
    colors[2] = ofColor(187, 70, 66);  // Dull Red
    colors[3] = ofColor(223, 193, 69); // River gold
    colors[4] = ofColor(199, 157, 161); // Flesh
    colors[5] = ofColor(135, 191, 218); // Baby blue
    colors[6] = ofColor(76, 166, 113); // Pastel green
    colors[7] = ofColor(114, 48, 97); // Magneta
    


    
    for (int i = 0;i < w; i ++){
        for (int j = 0; j < h; j++){
            int p = ofRandom(10000);
            if (p == 1){
                grid[i][j] = 7;
            }
            else {
                grid[i][j] = 0;
            }
            //tempgrid[i][j] = grid[i][j];
        }
    }
    
    //cout << "Val" << pow(72, 0.5) << endl;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 6; i <= w-6; i ++){
        for (int j = 6; j <= h-6; j++){
            //int nextVal = (grid[i][j]+1)%c;
            int sum = 0;
            int p = ofRandom(10000);
            if (p == 1){
                tempgrid[i][j] = 7;
            }
            else {}
            for (int l = -6; l <=6; l++){
                for (int m = -6; m <=6; m++){
                    //if ((l == 0 && m == 0)){
                    if ((l == 0 && m == 0) || (pow(pow(l, 2)+pow(m, 2), 0.5) > 6.5)){ // if outside radius 6
                        //cout << pow(pow(l, 2)+pow(m, 2), 0.5) << endl;
                    }
                    else {
                    if(grid[(i+l)][(j+m)] == 7){ // if any cells within radius 6 are active
                        //tempgrid[i][j] = 7;
                        sum+=1;
                    }
                    else {
                    }
                    }
                }
            }
            if (sum >= threshold){
            tempgrid[i][j] = 7;
            }
            else {
            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < w; i ++){
        for (int j = 0; j < h; j++){
            ofSetColor(colors[grid[i][j]]);
            ofDrawRectangle(i, j, 1, 1);
        }
    }
    
    

    //Update grid
    for (int i = 0; i < w; i ++){
        for (int j = 0; j < h; j++){
            if (grid[i][j] >= 1){
                tempgrid[i][j] = grid[i][j]-1; // Age cell
            }
            else {
            }
            grid[i][j] = tempgrid[i][j];
        }
    }
    
//    int r = 0;
//    while (r < 100000){
//        r++;
//    }
    


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
