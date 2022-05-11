//
//  Cell.cpp
//  Cellular Automaton 2_1
//
//  Created by Aastha Shah on 4/29/22.
//

#include "Cell.hpp"

Cell::Cell(){
};
    
    void Cell::setup(int _x, int _y, int _prev){
        x = _x;
        y = _y;
        state = 0;
        previous = _prev;
        neigh = 0;
        w = 8;
    }
    
    void Cell::update_neigh(int _n){
        neigh = _n;
    }
    
    void Cell::update_state(){
        if ((previous == 1) && (neigh < 2 || neigh > 4)){
            state = 0;
        }

        else if (previous == 1 && (neigh == 2 || neigh == 3 )) {
            state = 1;
        }
                 else if (previous == 0 && neigh == 3){
            state = 2;
        }
                 else {
            state = 0;
        }
    }
    
    void Cell::update_prev(){
        previous = state;
        state = 0;
    }
    
    void Cell::draw(){
        ofSetColor(0);
        if (state == 1){
            ofSetColor(29, 143, 177);
        }
        else if (state == 2) {
            ofSetColor(87, 8, 147);
            state = 1;
        }
        else{
            ofSetColor(0);
        }
        ofDrawRectangle(x*2, y*2, w, w);
    }
    
    

