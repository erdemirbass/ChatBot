/*
 * gApp.h
 *
 *  Created on: Nov 2, 2023
 *      Author: erdemirbass
 */

#ifndef GAPP_H_
#define GAPP_H_

#include "gBaseApp.h"


class gApp : public gBaseApp {
public:
	gApp();
	gApp(int argc, char **argv);
	~gApp();

	void setup();
	void update();
};

#endif /* GAPP_H_ */
