#ifndef ACTORFACTORY_HPP_INCLUDED
#define ACTORFACTORY_HPP_INCLUDED

#include "viking/GameObjectFactory.hpp"
#include "viking/Actor.hpp"

namespace vik
{

// Actors give ActorFactories a hook to perform last rites before they are deleted
class ActorFactory : public GameObjectFactory
{
public:
	ActorFactory(HashedString factoryID):
	GameObjectFactory(factoryID){}
	virtual void destroy(Actor* destroyMe) = 0;
};

} // end namespace vik

#endif // ACTORFACTORY_HPP_INCLUDED
