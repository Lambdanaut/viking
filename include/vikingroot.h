#ifndef VIKINGROOT_H_INCLUDED
#define VIKINGROOT_H_INCLUDED

#include "coreapp.h"
#include "renderingengine.h"
#include "gametime.h"
#include "gameobjectengine.h"
#include "eventsystem.h"

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

	CoreApp coreApp;
	RenderingEngine renderingEngine;
	GameTime gameTime;
	GameObjectEngine gameObjectEngine;
	EventSystem eventSystem;
private:
	bool running;
};

} // end namespace vik

#endif // VIKINGROOT_H_INCLUDED
