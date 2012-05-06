#include "vikingroot.h"

namespace vik
{

VikingRoot::VikingRoot():
running(false)
{
}

VikingRoot& VikingRoot::Get()
{
    static VikingRoot singleton;
    return singleton;
}

void VikingRoot::MainLoop()
{
	running = true;

	gameTime.Start();

	while(running)
	{
		gameTime.Update();
		u32 dt = gameTime.msDeltaTime();

		gameObjectEngine.Update(dt);

		eventSystem.DispatchEvents();

		renderingEngine.Render();

        // TODO: Implement more sophisticated timestep
        // otherwise the physics engine will go bananas on us
		if(dt < 1000/60)
		{
		    coreApp.sleep(1000/60 - dt);
		}
	}
}

void VikingRoot::EndLoop()
{
	running = false;
}

} // end namespace vik
