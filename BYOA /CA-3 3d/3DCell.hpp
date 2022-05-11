//
//  3DCell.hpp
//  Cellular Automaton 3_1
//
//  Created by Aastha Shah on 4/29/22.
//

#ifndef _DCELL
#define _DCELL

#include <stdio.h>

#include "ofMain.h"
# include <math.h>

class DCell {
    
public:
    
    void setup(int _x, int _y, int _z, int prev);    // setup method, use this to setup your object's initial state
    void update_neigh(int _n);  // update method, used to refresh your objects properties
    void update_state();
    void update_prev();
    void draw();    // draw method, this where you'll do the object's drawing
    int x, y, z;
    int w;
    int state;
    int age;
    int previous;
    int neigh;
    int r;

    static const int grid_x = 110; // Grid limit for x, y, and z
    static const int grid_y = 110;
    static const int grid_z = 110;
    static const int grid_xc = grid_x/2;
    static const int grid_yc = grid_y/2;
    static const int grid_zc = grid_z/2;
    static const int n = 4;
    
    
    // 3D Cellular Automata Rule
    // Specified as LC/BC/NS/N
    //LC: Life Condition: # of active cells required for active cell to live
    //BC: Birth Condition: # of active cells required for new cell to be born
    //NS: Number of states (usually binary 0 or 1)
    //N: Neighborhood (Von Neumann (6 cells, shared face) or Moore (26 cells, shared edge))
    
//    const int rule[7] = {0, 1, 2, 3, 4, 5, 6}; // Rule 0-6/1,3/2/VN - Cyrstal Growth
//    const int rule2[2] = {1, 3};
//
    
    //13-26/13-19/2/VN - Turnip
    
    
//    const int rule[18] = {5, 6, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26}; // Rule 9-26, 5-7, 12-13, 15/5/M Amoeba
//    const int rule2[8] = {3, 4, 5, 6, 7, 12, 13, 15};
    
        const int rule[2] = {1, 2}; // Rule 0-6/1,3/2/VN - Cyrstal Growth 2
        const int rule2[2] = {1, 3};
    

    
    
    
    DCell();
    
    
};






#endif /* _DCell_hpp */
