#include "viking/GameObjectFactoryTag.hpp"
#include "viking/GameObject.hpp"
#include "viking/GameObjectFactory.hpp"
#include <iostream>

namespace vik
{

GameObjectFactoryTag::GameObjectFactoryTag(GameObject* shipment, GameObjectFactory* manufacturer):
manufacturer(manufacturer),
shipment(shipment)
{
}

GameObjectFactoryTag::~GameObjectFactoryTag()
{
	manufacturer->destroy(shipment);
}

} // end namespace vik
