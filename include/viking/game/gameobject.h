#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include "viking/core/types.h"
#include "viking/core/string.h"

namespace vik
{

class Event;

class GameObject
{
public:
	virtual void Update(u32 dt){}
	virtual void OnEvent(Event& e){}
};

} // end namespace vik

#endif // GAMEOBJECT_H_INCLUDED
