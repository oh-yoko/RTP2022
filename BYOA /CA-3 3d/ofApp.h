#pragma once

#include "ofMain.h"
#include "3DCell.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        static const int grid_x = 110; // Grid limits for x, y, and z
        static const int grid_y = 110;
        static const int grid_z = 110;
        int grid_xc = grid_x/2;
        int grid_yc = grid_y/2;
        int grid_zc = grid_z/2;
        DCell grid[grid_x][grid_y][grid_z]; // Declare 3D grid
        int w = 3;
        ofColor colors[5];
    
        int step;
    

        ofEasyCam camera;
        //ofShader shader;
            
};
