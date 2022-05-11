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
    
    const static int cell = 3;
    const static int x = 21;
    const static int N = 15;
    int step = 1;
    
    const static int box_x = cell*x;
    const static int box_y = cell*N;
    
    int gap_x = (ofGetWidth() - (16*box_x))/15 ;
    int gap_y = (ofGetHeight() - (16*box_y))/15 ;
    
    int state[x][N][256] ;
    int RULE_BIN[8][256];
    
    
    
    
    
    

    
		
};
