/*
=====
NOTES
=====
 
in xml file, store:
    - file names
    - number of times the decay loop has run on an image
    - the timestamp for the last time an image was decayed
 
<image>
    <filename>someimage.png</filename>
    <numdecays>2</numdecays>
    <lastdecayed>timestamp</lastdecayed>
</image>
 
in every update, check:
    for each image in the xml file
        if (the difference between the current time and lastdecayed > updateinterval)
            1. decay the image once
            2. increment its numdecay
            3. update lastdecayed 
 
if i get a new image:
    add it to the xml file:
        - file name
        - 0 decay times
        - current timestamp
 
questions:
    how to ensure that decay loop only runs once per decay?
 
remember:
    callibrate once, don't change marker positions. 
    make sure images always fit in rectangle defined by the four markers
*/

#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxARToolkitPlus.h"
#include "ofxXmlSettings.h"

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
    
        void checkForNewImages();
        int CHECK_INTERVAL;
        int camW; int camH;
        int w, h;
    
        ofxXmlSettings settings;
};
