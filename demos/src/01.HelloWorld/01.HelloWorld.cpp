#include "viking/viking.h"

using namespace vik;

int main(int argc, char* argv[])
{
	VikingRoot& root = VikingRoot::Get();

	RenderingEngine& renderEngine = root.renderingEngine;

	WindowCreationParams window_params(640, 480);

	renderEngine.CreateWindow(window_params);

	renderEngine.SetWindowTitle("Hello, world!");

	root.MainLoop();
}
