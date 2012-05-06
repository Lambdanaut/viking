#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include "viktypes.h"

namespace vik
{

class Event;

class GameObject
{
public:
	virtual ~GameObject();

	virtual void Update(u32 dt);
	virtual bool OnEvent(Event& e);
};

} // end namespace vik

#endif // GAMEOBJECT_H_INCLUDED
