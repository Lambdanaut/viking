#include "vikingroot.h"

namespace vik
{

VikingRoot::VikingRoot():
running(false),
objectEngine(*this),
eventSystem(*this)
{
}

void VikingRoot::MainLoop()
{
	running = true;

	gameTime.Start();

	while(true)
	{
		gameTime.Update();
		u32 dt = gameTime.msDeltaTime();

		objectEngine.Update(dt);

		eventSystem.DispatchEvents();
		// check if received event which ended the main loop
		if(!running) break;
	}
}

void VikingRoot::EndLoop()
{
	running = false;
}

} // end namespace vik
