#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetCircleResolution(60);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofSeedRandom(39);

	ofSetColor(0);

	for (int radius = 160; radius <= 300; radius += 20) {

		ofPushMatrix();
		ofTranslate(ofRandom(-30, 30), ofRandom(-30, 30));

		ofRotateZ(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0005), 0, 1, -180, 180));
		ofRotateY(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0005), 0, 1, -180, 180));
		ofRotateX(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0005), 0, 1, -180, 180));

		ofNoFill();
		ofSetColor(39);
		ofDrawCircle(glm::vec3(), radius);

		auto deg = ofRandom(360);
		auto speed = ofRandom(3, 8);

		ofFill();
		ofSetColor(0);
		ofDrawSphere(
			glm::vec3(radius * cos((deg + ofGetFrameNum() * speed) * DEG_TO_RAD), radius * sin((deg + ofGetFrameNum() * speed) * DEG_TO_RAD), 0), 5);

		ofPopMatrix();
	}

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}