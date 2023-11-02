/*
* gCanvas.cpp
*
*  Created on: May 6, 2020
*      Author: noyan
*/


#include "gCanvas.h"


gCanvas::gCanvas(gApp* root) : gBaseCanvas(root) {
	this->root = root;
}

gCanvas::~gCanvas() {
}

void gCanvas::setup() {
	/*
	logo.loadImage("glistengine_logo.png");
	oai.initialize("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");

	try {
		std::string reply = oai.getChatCompletion("Is C++ a good language for AI programming", 2000);
		gLogi("gCanvas") << "reply:" << reply;
	} catch(std::exception& e) {
		gLoge("gCanvas") << "error:" << e.what();
	}
*/
	questionasked = false;
	question = "";
	qcounterlimit = 2;
	qcounter = 0;

	oai.initialize("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");

	root->getAppManager()->getGUIManager()->setCurrentFrame(&frame);
	root->getAppManager()->getGUIManager()->setTheme(gGUIManager::GUITHEME_DARK);
	frame.setSizer(&sizer);
	sizer.setSize(2, 1);
	sizer.enableBorders(true);
	float prs[2] = {0.9f, 0.1f};
	sizer.setLineProportions(prs);
	//sizer.setControl(0, 0, &text);
	//text.setText("deneme");
	sizer.setControl(1, 0, &panel);
	panel.setTitle("Ask your question");
	panel.setSizer(&panelsizer);
	panelsizer.setSize(1, 3);
	//panelsizer.enableBorders(true);
	float pnl[3] = {0.02f, 0.88f, 0.1f};
	panelsizer.setColumnProportions(pnl);
	panelsizer.setControl(0, 1, &textbox);
	panelsizer.setControl(0, 2, &button);
	button.setTitle("Send");
	sizer.setControl(0, 0, &panel1);
	panel1.setTitle("OpenAI Chat");
	panel1.setSizer(&panel1sizer);
	panel1sizer.setSize(1, 2);
	panel1sizer.enableBorders(true);
	float txt[2] = {0.8f, 0.2f};
	panel1sizer.setColumnProportions(txt);
	panel1sizer.setControl(0, 1, &panel2);
	panel1sizer.setControl(0, 0, &text);
	panel2.setSizer(&panel2sizer);
	panel2.setTitle("Settings");
	panel2sizer.setSize(2, 1);
	float pnl2[2] = {0.05f, 0.95f};
	panel2sizer.setLineProportions(pnl2);
	panel2sizer.setControl(1, 0, &numberbox);
	panel2sizer.setControl(0, 0, &text1);
	text1.setText("Max Tokens:");
	numberbox.setInteger(2000);
}

void gCanvas::update() {
	if(questionasked) {
		qcounter++;
		if(qcounter >= qcounterlimit) {
			try {
				std::string reply = oai.getChatCompletion(question, numberbox.getInteger());
				text.setText(text.getText() + "\n" + reply + "\n");
			} catch(std::exception& e) {
				gLoge("gCanvas") << "error:" << e.what();
			}
			questionasked = false;
			question = "";
			qcounter = 0;
		}
	}
}

void gCanvas::draw() {
	//logo.draw((getWidth() - logo.getWidth()) / 2, (getHeight() - logo.getHeight()) / 2);
}

void gCanvas::keyPressed(int key) {
//	gLogi("gCanvas") << "keyPressed:" << key;
}

void gCanvas::keyReleased(int key) {
//	gLogi("gCanvas") << "keyReleased:" << key;
}

void gCanvas::charPressed(unsigned int codepoint) {
//	gLogi("gCanvas") << "charPressed:" << gCodepointToStr(codepoint);
}

void gCanvas::mouseMoved(int x, int y) {
//	gLogi("gCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseDragged(int x, int y, int button) {
//	gLogi("gCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void gCanvas::mousePressed(int x, int y, int button) {
//	gLogi("gCanvas") << "mousePressed" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void gCanvas::mouseReleased(int x, int y, int button) {
//	gLogi("gCanvas") << "mouseReleased" << ", button:" << button;
}

void gCanvas::mouseScrolled(int x, int y) {
//	gLogi("gCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseEntered() {

}

void gCanvas::mouseExited() {

}

void gCanvas::windowResized(int w, int h) {

}

void gCanvas::showNotify() {

}

void gCanvas::hideNotify() {

}

void gCanvas::onGuiEvent(int guiObjectId, int eventType, std::string value1, std::string value2) {
	if(button.getId() == guiObjectId && eventType == G_GUIEVENT_BUTTONRELEASED && textbox.getText() != "") {
		question = textbox.getText();
		text.setText(text.getText() + "\n" + question + "\n");
		questionasked = true;
		textbox.cleanText();
	}
}
