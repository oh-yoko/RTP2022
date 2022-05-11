#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    average.allocate(640, 480, OF_IMAGE_COLOR);
    ofDirectory dir;
    dir.listDir("bellpeppers");
    for (int i = 0; i < dir.size(); i++){
        ofImage img;
        candles.push_back(img);
        candles.back().load(dir.getPath(i));
        cout << "loaded" << i << "of" << dir.size() << endl;
        ofRectangle targetDim(0, 0, 640, 480);
        ofRectangle imgDim(0, 0, candles.back().getWidth(), candles.back().getHeight());
        targetDim.scaleTo(imgDim);
        candles.back().crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
        candles.back().resize(640, 480);
    }

    
    for (int i = 0; i < 640; i ++){
        for (int j = 0; j < 480; j ++){
            float sumr;
            float sumg;
            float sumb;
            for (int k = 0; k < candles.size(); k ++){
                ofColor color = candles[k].getColor(i,j);
                sumr += color.r;
                sumg += color.g;
                sumb += color.b;
            }
            sumr = sumr/candles.size();
            sumg = sumg/candles.size();
            sumb = sumb/candles.size();
            average.setColor(i, j, ofColor(sumr, sumg, sumb));
        }
    }
    
    average.update();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //candles[19].draw(0,0);
    //candles[ max(0, mouseX) % candles.size()].draw(0,0);
    average.draw(0,0);

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
