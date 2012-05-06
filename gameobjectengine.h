#ifndef GAMEOBJECTENGINE_H_INCLUDED
#define GAMEOBJECTENGINE_H_INCLUDED

#include "viktypes.h"

namespace vik
{

class VikingRoot;

/*
Allocates GOs.
Updates GO states.
Distributes events to GOs.
Fulfills general GO queries.
*/
class GameObjectEngine
{
public:
	GameObjectEngine(VikingRoot& root);
	void Update(u32 dt);
private:
	VikingRoot& root;
};

}

#endif // GAMEOBJECTENGINE_H_INCLUDED
