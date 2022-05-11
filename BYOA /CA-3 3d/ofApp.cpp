#include "ofApp.h"
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup(){
    

    colors[3] = ofColor(58, 36, 59, 70);
    colors[1] = ofColor(128, 17, 0, 30);
    colors[2] = ofColor(255, 117, 0, 60);
    colors[4] = ofColor(250, 192, 0, 50);
    //colors[0] = ofColor(213, 94, 0, 100);
    colors[0] = ofColor(255, 255, 255, 0);
    
    //shader.load("shadersGL3/shader");

    ofSeedRandom(mouseX);
    step = 3;
    


    //Setup 3D Array grid of Cell objects and declare initial seed state
    for (int i = 0; i < grid_x; i++){
        for (int j = 0; j < grid_y; j++){
            for (int k = 0; k < grid_z; k++){
            int prev = 0;
                
//                 //Centre seed
                if (i == grid_xc && j == grid_yc && k == grid_zc){
                    prev = 1;
                }
                
            // Random seed in central region

//            if ((i < grid_xc+1) && (i > grid_xc-1) && (j < grid_yc+1) && (j > grid_yc-1) && (k < grid_zc+1) && (k >    grid_zc-1)){ // Setup Random central seed zone
//                //prev = ofRandom(2);
//                prev = 1;
//            }
            else { // Do nothing
                }
                grid[i][j][k].setup((i-grid_xc)*w, (j-grid_yc)*w, (k-grid_zc)*w, prev);// Setup each cell
            }
        }
    }


    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Moore Neighbourhood (26 Cells)
    for (int r = 1; r < 25; r++){  // Move radially outwards from centre
        for (int i = grid_xc-r; i<=grid_xc+r; i++){ // At a given r, sweep all (r+1)^3 squares
            for (int j = grid_yc-r; j<=grid_yc+r; j++){
                for (int k = grid_zc-r; k<=grid_yc+r; k++){
                if( (abs(i-grid_xc) == r) || (abs(j-grid_yc)==r) || (abs(k-grid_zc)== r)){ // Leave all internal cells below r alone - we only want to grow outwards
                int neigh_sum = 0;
                for (int l = -1; l<=1; l++){
                    for (int m = -1; m<=1; m++){
                        for (int n = -1; n<=1; n++){
                        neigh_sum += grid[i+l][j+m][k+n].previous; //Count state of 9 neighbours + self
                        }
                    }
                }
                neigh_sum -= grid[i][j][k].previous; // Subtract state of self
                grid[i][j][k].update_neigh(neigh_sum); // Update # of neighbours for each cell in that sweep
                    }
                    else { // For cells within radius r, do nothing
                    }
                }
            }
        } // Finish updating all neighbours for that r

        // Before moving on to the next r:
        for (int i = grid_xc-r; i<=grid_xc+r; i++){ // Now update cell state
            for (int j = grid_yc-r; j<=grid_yc+r; j++){
                for (int k = grid_zc-r; k<=grid_yc+r; k++){
                grid[i][j][k].update_state();
                }
            }
        }
    }
    
    // Von-Neumann Neighbourhood (6 Cells)
//    for (int r = 1; r <= 50; r++){  // Move radially outwards
//        for (int i = grid_xc-r; i<=grid_xc+r; i++){ // At a given r, sweep all (r+1)^3 squares
//            for (int j = grid_yc-r; j<=grid_yc+r; j++){
//                for (int k = grid_zc-r; k<=grid_yc+r; k++){
//                if( (abs(i-grid_xc) == r) || (abs(j-grid_yc)==r) || (abs(k-grid_zc)== r)){ // Leave all internal cells below r alone - we only want to grow outwards
//                int neigh_sum = 0;
//                for (int l = -1; l<=1; l++){
//                    for (int m = -1; m<=1; m++){
//                        for (int n = -1; n<=1; n++){
//                            if (l == 0 || m == 0 || n == 0){
//                        neigh_sum += grid[i+l][j+m][k+n].previous; //Count state of 9 neighbours + self
//                        }
//                            else {
//                            }
//                        }
//                    }
//                }
//                neigh_sum -= grid[i][j][k].previous; // Subtract state of self
//                grid[i][j][k].update_neigh(neigh_sum); // Update # of neighbours for each cell in that sweep
//               // cout << "Calculated new state for" << (i-grid_xc) << (j-grid_yc) << (k-grid_zc) << endl;
//                    }
//                    else {
//                    }
//                }
//            }
//        } // Finish updating all neighbours for that r
//
//        // Before moving on to the next r:
//        for (int i = grid_xc-r; i<=grid_xc+r; i++){ // Update all cell states at that r
//            for (int j = grid_yc-r; j<=grid_yc+r; j++){
//                for (int k = grid_zc-r; k<=grid_yc+r; k++){
//                grid[i][j][k].update_state();
//                }
//            }
//        }
//    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundColor(255, 255, 255);
    
    camera.begin();
//    ofSetColor(125, 125, 125);
//    ofNoFill();
//    ofDrawBox(-200, -200, -200, 600, 600, 600);
    

 
    for (int i = 0; i < grid_x; i++){ // Now draw cells
        for (int j = 0; j < grid_x; j++){
            for (int k = 0; k < grid_x; k++){
                //int r = grid[i][j][k].r;
                int a = grid[i][j][k].age;
                ofSetColor(colors[a]);
            grid[i][j][k].draw();
            }
        }
    }
    camera.end();

    for (int i = 0; i < grid_x; i++){ // Now update cell.previous 
        for (int j = 0; j < grid_y; j++){
            for (int k = 0; k < grid_z; k++){
            grid[i][j][k].update_prev();
            }
        }
    }
    
//    if(step >= 50){
//        step = 1;
//    }
//    else{
//        step+=1;
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
