#ifndef VIKINGROOT_H_INCLUDED
#define VIKINGROOT_H_INCLUDED

#include "gametime.h"
#include "gameobjectengine.h"
#include "eventsystem.h"

namespace vik
{

class Event;

/*
The core of the Viking engine.
Probably only one instance should exist at a time.
*/
class VikingRoot
{
public:
	VikingRoot();
	void MainLoop();
	void EndLoop();
private:
	bool running;
	GameTime gameTime;
	GameObjectEngine objectEngine;
	EventSystem eventSystem;
};

} // end namespace vik

#endif // VIKINGROOT_H_INCLUDED
