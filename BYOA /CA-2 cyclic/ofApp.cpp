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
    colors[0] = ofColor(0, 0, 0);
    colors[1] = ofColor(0, 0, 0);
    //colors[1] = ofColor(230, 159, 0);
    colors[2] = ofColor(255, 50, 0);
    colors[3] = ofColor(215, 52, 2);
    colors[4] = ofColor(252, 100, 0);
    colors[5] = ofColor(255, 117, 0);
    colors[6] = ofColor(250, 192, 0);
    colors[7] = ofColor(213, 94, 0);

    // Palette 3: Mehul's Lower Sitting Room
//    colors[0] = ofColor(63, 67, 68); // Coal
//    colors[1] = ofColor(60, 97, 167); // Dark dodgerblue
//    colors[2] = ofColor(187, 70, 66);  // Dull Red
//    colors[3] = ofColor(223, 193, 69); // River gold
//    colors[4] = ofColor(199, 157, 161); // Flesh
//    colors[5] = ofColor(135, 191, 218); // Baby blue
//    colors[6] = ofColor(76, 166, 113); // Pastel green
//    colors[7] = ofColor(114, 48, 97); // Magneta
    


    
    for (int i = 0;i < w; i ++){
        for (int j = 0; j < h; j++){
            tempgrid[i][j] = ofRandom(c);
            grid[i][j] = tempgrid[i][j];
        }
    }
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i <= w-1; i ++){
        for (int j = 0; j <= h-1; j++){
            int nextVal = (grid[i][j]+1)%c;
            int sum = 0;
            for (int l = -1; l <=1; l++){
                for (int m = -1; m <=1; m++){
                    if ((l == 0 && m == 0) || (abs(l)+abs(m) == 2) ){
                    //if ((l == 0 && m == 0)){
                    }
                    else {
                    if(grid[(i+l)%w][(j+m)%h] == nextVal){
                        tempgrid[i][j] = nextVal;
//                        sum+=1;
                    }
                    }
                }
            }
//            if (sum >= threshold){
//            tempgrid[i][j] = nextVal;
//            }
//            else {
//            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < w; i ++){
        for (int j = 0; j < h; j++){
            ofSetColor(colors[tempgrid[i][j]]);
            ofDrawRectangle(i*3, j*3, 3, 3);
        }
    }

    //Update grid
    for (int i = 0; i < w; i ++){
        for (int j = 0; j < h; j++){
            grid[i][j] = tempgrid[i][j];
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
