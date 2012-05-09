#ifndef VIKINGROOT_H_INCLUDED
#define VIKINGROOT_H_INCLUDED

#include "viking/system/app.h"
#include "viking/gfx/renderingengine.h"
#include "viking/time/gametime.h"
#include "viking/game/gameobjectengine.h"
#include "viking/event/eventsystem.h"

namespace vik
{

/*
The core of the Viking engine. Is a singleton.
*/
class VikingRoot
{
private:
    VikingRoot();
public:
	static VikingRoot& Get();

	void MainLoop();
	void EndLoop();

	App app;
	RenderingEngine renderingEngine;
	GameTime gameTime;
	GameObjectEngine gameObjectEngine;
	EventSystem eventSystem;
private:
	bool running;
};

} // end namespace vik

#endif // VIKINGROOT_H_INCLUDED
