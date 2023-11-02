/*
 * gApp.cpp
 *
 *  Created on: Nov 2, 2023
 *      Author: erdemirbass
 */

#include "gApp.h"
#include "gCanvas.h"


gApp::gApp() {
}

gApp::gApp(int argc, char **argv) : gBaseApp(argc, argv) {
}

gApp::~gApp() {
}

void gApp::setup() {
	gCanvas* cnv = new gCanvas(this);
	appmanager->setCurrentCanvas(cnv);
}

void gApp::update() {
}
