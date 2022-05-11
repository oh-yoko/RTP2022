//
//  Cell.hpp
//  Cellular Automaton 2_1
//
//  Created by Aastha Shah on 4/29/22.
//

#ifndef _CELL
#define _CELL

#include <stdio.h>

#include "ofMain.h"

class Cell {
    
public:
    
    void setup(int _x, int _y, int prev);    // setup method, use this to setup your object's initial state
    void update_neigh(int _n);  // update method, used to refresh your objects properties
    void update_state();
    void update_prev();
    void draw();    // draw method, this where you'll do the object's drawing
    int x, y;
    int w;
    int state;
    int previous;
    int neigh;
    
    Cell();
};

#endif 
