#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    cell.allocate(round(7500/24.0), round(3850/6.0), OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    if(module.isAllocated()) {
        ofSetColor(255);
        module.draw(0, 0, 750*2, 375*2);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    int xx=0;
    int yy=0;
    if(key=='s' or key=='S') {
        for(int x=0; x<23; x++){
            for(int y=0; y<6; y++){
                cell.clear();
                xx= x*round(7500/24.0);
                yy= y*round(3750/6.0);
                cell.cropFrom(module, xx, yy, floor(7500/24.0), floor(3750/6.0));
                string filename = "/Users/kerbal/Desktop/"+ofGetTimestampString()+".jpg";
                cell.save(filename);
            }
        }
        ofSetWindowTitle("144-Cell images Saved OK.");
    }
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

    if( dragInfo.files.size() > 0 ){
        module.load(dragInfo.files[0]);
        module.setImageType(OF_IMAGE_COLOR);
    }
    
    ofSetWindowShape(750*2, 375*2);
    ofSetWindowTitle("Module Image Loaded..");
}
