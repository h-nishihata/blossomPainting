//https://junkiyoshi.com/insta20180612/
//https://junkiyoshi.com/openframeworks20220204/
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	fbo.allocate(ofGetWidth(), ofGetHeight());
	fbo.begin();
	image.load("blossom.jpg");
	image.draw(0, 0);
	fbo.end();
	fbo.readToPixels(pixels);

	mesh.setMode(OF_PRIMITIVE_LINE_STRIP);

	for (int i = 0; i < numPoints; i++)
	{
		do
		{
			points[i].x = ofRandom(0, ofGetWidth());
			points[i].y = ofRandom(0, ofGetHeight());
		} while ((pixels.getColor(points[i].x, points[i].y).r < 50));
	}

	for (int i = 0; i < numPoints * 0.5; i++)
	{
		for (int j = 0; j < numPoints * 0.5; j++)
		{
			if (i == j)
				continue;

			auto distX = glm::distance(points[i].x, points[j].x);
			auto distY = glm::distance(points[i].y, points[j].y);
			if (distX < 64 && distY < 64)
			{
				mesh.addVertex((ofPoint)points[i]);
				//mesh.addColor(ofColor(255, 0, 0));
				mesh.addColor(pixels.getColor(points[i].x, points[i].y));
				mesh.addVertex((ofPoint)points[j]);
				//mesh.addColor(ofColor(0, 0, 255));
				mesh.addColor(pixels.getColor(points[j].x, points[j].y));
				mesh.addIndex(mesh.getNumVertices() - 1);
				mesh.addIndex(mesh.getNumVertices() - 2);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	fbo.draw(0, 0);
	mesh.draw();

	//for (int i = 0; i < numPoints; i++)
		//ofDrawCircle(points[i].x, points[i].y, 3);
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
