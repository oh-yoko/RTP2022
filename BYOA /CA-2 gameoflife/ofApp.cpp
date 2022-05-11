#include "ofApp.h"
#include "Cell.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    

    
    //Setup 2D Array grid of Cell objects
    for (int i = 0; i < grid_x; i++){
        for (int j = 0; j < grid_y; j++){
            int prev = 0;
            prev = ofRandom(2);
//            if (i > grid_xc-2 && i < grid_xc+2  && (j == i)){ // Setup diagonal
//                prev = 1;
//            }
//            else {
//            }
        grid[i][j].setup(i*2, j*2, prev); // Setup each cell
        }
    }
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    for (int r = 1; r < grid_xc; r++){  // Move radially outwards
        for (int i = grid_xc-r; i<=grid_xc+r; i++){ // At a given r, sweep all (r+1)^2 squares
            for (int j = grid_yc-r; j<=grid_yc+r; j++){
                int neigh_sum = 0;
                for (int l = -1; l<=1; l++){
                    for (int m = -1; m<=1; m++){
                        neigh_sum += grid[i+l][j+m].previous; //Count state of 9 neighbours + self
                    }
                }
                neigh_sum -= grid[i][j].previous; // Subtract state of self
                grid[i][j].update_neigh(neigh_sum); // Update # of neighbours for each cell in that sweep
            }
        } // Finish updating all neighbours for that r
        for (int i = grid_xc-r; i<=grid_xc+r; i++){ // Now update cell state
            for (int j = grid_yc-r; j<=grid_yc+r; j++){
                grid[i][j].update_state();
            }
        }
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    for (int i = 0; i < grid_x; i++){ // Now draw cells
        for (int j = 0; j < grid_y; j++){
            grid[i][j].draw();
            }
        }
    
    for (int i = 0; i < grid_x; i++){ // Now update Cell.previous
        for (int j = 0; j < grid_y; j++){
            grid[i][j].update_prev();
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
