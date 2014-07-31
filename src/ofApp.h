
#pragma once

#include "ofMain.h"
#include <ofxOpenCv.h>


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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		///added
		ofVideoGrabber movie;                          // movie object for capturing Video from Cam
		ofxCvColorImage rgb, hsb, blufilter;                           //rgb object for storing color image data
        ofxCvGrayscaleImage hue,sat,bri,hfilter,sfilter,bfilter,filtered;   //objects for storing grayscale image data
        ofxCvContourFinder contours;                         //object to store contours of the filtered image
        int w,h;
        int findHue;

};
