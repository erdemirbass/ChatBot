 /*
 * gCanvas.h
 *
 *  Created on: Nov 2, 2023
 *      Author: erdemirbass
 */

#ifndef GCANVAS_H_
#define GCANVAS_H_

#include "gBaseCanvas.h"
#include "gApp.h"
#include "gImage.h"
#include "gipOpenAI.h"
#include "gGUIFrame.h"
#include "gGUISizer.h"
#include "gGUIText.h"
#include "gGUIButton.h"
#include "gGUITextbox.h"
#include "gGUIPanel.h"
#include "gGUINumberBox.h"



class gCanvas : public gBaseCanvas {
public:
	gCanvas(gApp* root);
	virtual ~gCanvas();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void charPressed(unsigned int codepoint);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseScrolled(int x, int y);
	void mouseEntered();
	void mouseExited();
	void windowResized(int w, int h);

	void showNotify();
	void hideNotify();
	void onGuiEvent(int guiObjectId, int eventType, std::string value1 = "", std::string value2 = "");

private:
	gApp* root;
	gImage logo;
	gipOpenAI oai;
	gGUIFrame frame;
	gGUISizer sizer;
	gGUIText text;
	gGUIButton button;
	gGUITextbox textbox;
	gGUIPanel panel, panel1, panel2;
	gGUISizer panelsizer;
	gGUISizer panel1sizer;
	gGUISizer panel2sizer;
	gGUINumberBox numberbox;
	gGUIText text1;
	bool questionasked;
	std::string question;
	int qcounter, qcounterlimit;
};

#endif /* GCANVAS_H_ */
