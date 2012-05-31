#include "viking/ActorState.hpp"
#include "viking/Actor.hpp"

namespace vik
{

ActorState::ActorState(HashedString stateName, Actor* context):
context(context),
stateName(stateName)
{
}

Actor* ActorState::getContext()
{
	return context;
}

HashedString ActorState::getName() const
{
	return stateName;
}

} // end namespace vik

