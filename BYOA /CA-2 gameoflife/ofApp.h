#pragma once

#include "ofMain.h"
#include "Cell.hpp"

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
    
    static const int grid_x = 200;
    static const int grid_y = 100;
    int grid_xc = grid_x/2;
    int grid_yc = grid_y/2;
    Cell grid[grid_x][grid_y];


		
};
