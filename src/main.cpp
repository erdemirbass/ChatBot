
#include "gAppManager.h"
#include "gApp.h"


int main(int argc, char **argv) {

	gStartEngine(new gApp(argc, argv), "OpenAI Chat", G_WINDOWMODE_GUIAPP, 1280, 720);

	return 0;
}
