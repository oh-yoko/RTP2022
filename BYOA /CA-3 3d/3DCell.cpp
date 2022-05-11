//
//  3DCell.cpp
//  Cellular Automaton 3_1
//
//  Created by Aastha Shah on 4/29/22.
//

#include "3DCell.hpp"
#include <math.h>


DCell::DCell(){
};
    
    void DCell::setup(int _x, int _y, int _z, int _prev){
        x = _x;
        y = _y;
        z = _z;
        state = 0;
        age = 4;
        previous = _prev;
        neigh = 0;
        w = 3;
        r = (int)floor(pow((pow(x, 2)+pow(y, 2)+pow(z, 2)), 0.5))%5;
        
    }
    
    void DCell::update_neigh(int _n){ // Update # of living cells in neighborhood
        neigh = _n;
    }
    
    void DCell::update_state(){ // Update state of cell based on rule
        if (previous == 1){
            if (bool rulec = std::find(std::begin(rule), std::end(rule), neigh) != std::end(rule)){ // Life
                state = 1;
                age = n;
            }
            else {
                state = 0;
                age = n;
            }
        }
            else {
                if (bool rulec2 = std::find(std::begin(rule2), std::end(rule2), neigh) != std::end(rule2)){ // Birth
                    state = 1;
                    age = n;
                }
                else {
                }
            }
    }
    
    void DCell::update_prev(){ // Update previous state of cell for next generation
        previous = state;
        if (state == 0){
            if (age >= 1){
            age-=1;
            }
            else {
            }
        }
        state = 0;
    }
    
    void DCell::draw(){ // Draw box, assign color  based on location
        
        ofDrawBox(x, y, z, w, w, w);
        
//        if (previous == 1){
//            //ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), 100);
//            //ofSetColor(125-(x/grid_xc*125), y/grid_yc*42, z/grid_zc*108);
//            //ofSetColor(colors[r%4]);
//            ofDrawBox(x, y, z, w, w, w);
//
//        }
//        else{
//        }

    }
    
