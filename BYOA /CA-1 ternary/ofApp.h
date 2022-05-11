#pragma once

#include "ofMain.h"

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
    
    // Grid Parameters
    static const int PIX_X = 800;
    static const int PIX_Y = 600;
    static const int CELL = 2;
    static const int N_X = PIX_X/CELL;
    static const int N_Y = PIX_Y/CELL;

    
    //Grid
    int ROW_CURR[N_Y][N_X];
    
    
    // Rule
    //int RULE = 912;
    //int RULE = 2040;
    int RULE = 1329;
    int TEMP = RULE;
    int RULE_TERN[7];
    int step = 1;
		
};
