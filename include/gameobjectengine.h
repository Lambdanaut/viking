#ifndef GAMEOBJECTENGINE_H_INCLUDED
#define GAMEOBJECTENGINE_H_INCLUDED

#include "viktypes.h"

#include <vector>

namespace vik
{

class VikingRoot;
class GameObject;

/*
Allocates GOs (Game Objects).
Updates GO states.
Distributes events to GOs.
Fulfills general GO queries.
*/
class GameObjectEngine
{
public:
	void Update(u32 dt);
private:
	std::vector<GameObject*> children;
};

}

#endif // GAMEOBJECTENGINE_H_INCLUDED
