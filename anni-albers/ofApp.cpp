#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    int arr_r1[8][6];
//    int grid = 4;
//    int rows = 8;
//    int cols = 6;
//
//    ofColor navy;
//    navy.r = 10;
//    navy.g = 20;
//    navy.b = 80;
//
//    ofColor coal;
//    navy.r = 10;
//    navy.g = 0;
//    navy.b = 10;
//
//    int dir;
//
//    for(int l = 0; l < rows; l ++){
//        for(int m = 0; m < cols; m ++){
//            if (l == 0 || m == 0){
//                arr_r1[l][m] = ofRandom(0,1);
//            }
//            else{
//            }
//            }
//
//    for(int l = 1; l < rows; l ++){
//        for(int m = 1; m < cols; m ++){
//
//                if(l%2 == 0){
//                    arr_r1[l][m] = arr_r1[0][abs(m-l)];
//                }
//                else {
//                    arr_r1[l][m] = 1-arr_r1[0][abs(m-l)];
//                }
//        }
//    }
//
//}
    

    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofSetBackgroundColor(255, 253, 248);
//    ofSeedRandom(mouseX);
    
//    int map[8][6];
//    for (int i = 0; i<8; i ++){
//        map[i][1] = ofRandom(0, 1);
//            }
//
//    for (int i = 1; i <8; i ++){
//        for (int j = 1; j< 8; j ++){
//            map[i][j] = map[abs(i-j)][abs(i-j)
//
//        }
//    }
//
//    int w = 12;
//    int h = 16;
//    ofPushMatrix();
//    ofTranslate(100, 100);
//    //vector <int> seedrow = ofRandom(0, 1)
//
//    for (int k = 0; k < 4; k ++){
//        for (int l = 0; l < 4; l++){
//            int c;
//        ofColor color;
//        if((k+l) % 2 == 0){
//            color.r = 0;
//            color.g = 0;
//            color.b = 0;
//        }
//        else {
//              color.r = 10;
//              color.g = 20;
//              color.b = 80;
//              }
//            ofSetColor(color);
//    for (int i = 0; i < 6; i ++){
//        for (int j = 0; j < 8; j ++){
//            ofPushMatrix();
//            ofTranslate((k*6*w)+(i+1)*w, (l*8*h)+(j+1)*h);
//            if(i == 0){
//                c = ofRandom(0,1);
//            }
//
//            if((k+l) % 2 == 0){
//                if( c == 1){
//                //Triangle Top Left
//                ofBeginShape();
//                ofVertex(w, 0);
//                ofVertex(0, h);
//                ofVertex(w, h);
//                ofEndShape(true);
//                }
//                else {
//                //Trianle Bottom Right
//                    ofBeginShape();
//                    ofVertex(0, 0);
//                    ofVertex(w, 0);
//                    ofVertex(0, h);
//                    ofEndShape(true);
//                }
//            }
//            else{
//                if( c == 1){
//                //Triangle Top Right
//                ofBeginShape();
//                ofVertex(0, 0);
//                ofVertex(w, h);
//                ofVertex(0, h);
//                ofEndShape(true);
//                }
//                else {
//                //Triangle Bottom Left
//                ofBeginShape();
//                ofVertex(0, 0);
//                ofVertex(w, 0);
//                ofVertex(w, h);
//                ofEndShape(true);
//                }
//            }
//            ofPopMatrix();
//            }
//    }
//
//    }
//    }
//    ofPopMatrix();
    
    //
        //cream background
        ofSetBackgroundColor(255, 253, 248);
        ofSetColor(0);
        ofSeedRandom(mouseX);
    
    int arr_r1[8][6];
    int grid = 4;
    int rows = 6;
    int cols = 8;
    
    ofColor navy;
    navy.r = 10;
    navy.g = 10;
    navy.b = 95;
   
    ofColor coal;
    coal.r = 10;
    coal.g = 0;
    coal.b = 10;
    
    int dir;
    
    
    
    //Seed first row of each 6x8 cell with a random binary pattern
    
    for(int l = 0; l < rows; l ++){
        for(int m = 0; m < cols; m ++){
            if (l == 0 || m == 0){
                arr_r1[l][m] = ofRandom(0,2);
                //                std::cout << "value: " << arr_r1[l][m] << endl;
                //                ofDrawCircle(100+((m+1)*20)+arr_r1[l][m]*100, 100+(10*(l+1))+arr_r1[l][m]*100, 10);
            }
            else{
            }
            }
        
        
    // Propogating the pattern across the diagonal
        // Here we assign which side of the rect cell to paint in
        //by relating to the state of the back-propogated cell
        //along the main 4x4 grid cell diagonal back to the 0th row
    for(int l = 1; l < rows; l ++){
        for(int m = 1; m < cols; m ++){

                if(l%2 == 0){
                    arr_r1[l][m] = arr_r1[0][abs(m-l)];
                }
                else {
                    arr_r1[l][m] = 1-arr_r1[0][abs(m-l)];
                }
        }
    }

}


    // Here we draw the business by defining a tri shape
    //within a push-translate-pop matrix

    for(int i = 0; i<grid; i++){
        for (int l = 0; l < grid; l++){
        if((i+l)%2 == 0 ){
            ofSetColor(navy);
            dir = 2;
        }
        else{
            ofSetColor(coal);
            dir = 1;
        }
            std::cout << "dir" << dir << endl;
        for (int j = 0; j < rows; j ++){
            for (int k = 0; k < cols; k ++){
                ofPushMatrix();
                ofTranslate(150+(i*72+j*w), 100+(l*96+k*w));
                if(dir == 1){
                    if (arr_r1[j][k] == 0){
                                        //Triangle Top Left
                                        ofBeginShape();
                                        ofVertex(w, 0);
                                        ofVertex(0, h);
                                        ofVertex(w, h);
                                        ofEndShape(true);
                                     }
                    else {
                                        //Trianle Bottom Right
                                            ofBeginShape();
                                            ofVertex(0, 0);
                                            ofVertex(w, 0);
                                            ofVertex(0, h);
                                            ofEndShape(true);
                                        }
                }
                else {
                    if(arr_r1[j][k] == 0){
                                        //Triangle Top Right
                                        ofBeginShape();
                                        ofVertex(0, 0);
                                        ofVertex(w, h);
                                        ofVertex(0, h);
                                        ofEndShape(true);
                                        }
                    else {
                                        //Triangle Bottom Left
                                        ofBeginShape();
                                        ofVertex(0, 0);
                                        ofVertex(w, 0);
                                        ofVertex(w, h);
                                        ofEndShape(true);
                                        }
                    }
                ofPopMatrix();
                    }

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
