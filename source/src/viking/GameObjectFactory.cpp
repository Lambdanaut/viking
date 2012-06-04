#include "viking/GameObjectFactory.hpp"

namespace vik
{

GameObjectFactory::GameObjectFactory(HashedString factoryID):
factoryID(factoryID)
{
}

HashedString GameObjectFactory::getFactoryID() const
{
	return factoryID;
}

} // end namespace vik
