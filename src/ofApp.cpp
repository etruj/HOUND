#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

 ofBackground(0,0,0);

    w = 320;
    h = 240;

    movie.initGrabber(w, h, true);

    //reserve memory for cv images
    rgb.allocate(w, h);
    hsb.allocate(w, h);
    hue.allocate(w, h);
    sat.allocate(w, h);
    bri.allocate(w, h);
    filtered.allocate(w, h);
    hfilter.allocate(w, h);
    sfilter.allocate(w, h);
    bfilter.allocate(w, h);
    blufilter.allocate(w, h);
}

//--------------------------------------------------------------
void ofApp::update(){
movie.update();

    if (movie.isFrameNew()) {

        //copy webcam pixels to rgb image
        rgb.setFromPixels(movie.getPixels(), w, h);

        //mirror horizontal
        rgb.mirror(false, true);

        //duplicate rgb
        hsb = rgb;

        //convert to hsb
        hsb.convertRgbToHsv();

        //store the three channels as grayscale images
        hsb.convertToGrayscalePlanarImages(hue, sat, bri);

	

        //filter image based on the hue value were looking for
        for (int i=0; i<w*h; i++) {


            hfilter.getPixels()[i] = ofInRange(hue.getPixels()[i], 30, 40) ? 255 : 0;
           // sfilter.getPixels()[i] = ofInRange(sat.getPixels()[i],60, 90) ? 255 : 0;
            //bfilter.getPixels()[i] = ofInRange(bri.getPixels()[i],50, 90) ? 255 : 0;
	 // filtered.getPixels()[i] = ofInRange(hue.getPixels()[i],50, 55) ? 255 : 0;

	}

	//hfilter%= sfilter;
	//sfilter &= hfilter;
	//blufilter.set(0,0, 255);
        //blufilter.convertRgbToHsv();
	//blufilter.convertToGrayscalePlanarImages(bfilter,sfilter, bri);
	//hfilter &= bfilter;


	filtered= hfilter;

        filtered.flagImageChanged();
        //run the contour finder on the filtered image to find blobs with a certain hue


	  filtered.erode();
	 // filtered.dilate();

        contours.findContours(filtered, 80, w*h/2, 1, false);
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(255,255,255);

    //draw all cv images
    rgb.draw(0,0);
    hsb.draw(640,0);
    hue.draw(0,240);
    sat.draw(320,240);
    bri.draw(640,240);
    filtered.draw(0,480);
    contours.draw(0,480);

    ofSetColor(0, 255, 0);
    ofFill();

    //draw green circles for found blobs
    for (int i=0; i<contours.nBlobs; i++) {
        ofCircle(contours.blobs[i].centroid.x, contours.blobs[i].centroid.y, 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
/*
cout << “mouseMoved: ” << x << “, ” << y << endl;
circleX = x;
circleY = y;
*/

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    //calculate local mouse x,y in image
    //int mx = x % w;
    //int my = y % h;

    //get hue value on mouse position
    //findHue = hue.getPixels()[300];

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
