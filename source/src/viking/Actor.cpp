#include "viking/Actor.hpp"
#include "viking/GameTime.hpp"
#include "viking/ActorFactory.hpp"
#include <cassert>

namespace vik
{

Actor::Actor(ActorFactory* manufacturer):
manufacturer(manufacturer),
currentState(0)
{
}

Actor::~Actor()
{
	if (currentState)
	{
		currentState->onLeave();
	}

	for (int i = static_cast<int>(states.size()) - 1; i >= 0; --i)
	{
		delete states[i];
	}

	manufacturer->destroy(this);
}

void Actor::startStateMachine(HashedString initialStateName)
{
	unsigned i;
	for (i = 0; i < states.size(); ++i)
	{
		if (states[i]->getName() == initialStateName)
		{
			currentState = states[i];
			break;
		}
	}
	assert(i != states.size());

	currentState->onEnter();
}

void Actor::addState(ActorState* state)
{
	states.push_back(state);
}

void Actor::switchToState(HashedString nextState)
{
	currentState->onLeave();

	unsigned i;
	for (i = 0; i < states.size(); ++i)
	{
		if (states[i]->getName() == nextState)
		{
			currentState = states[i];
			break;
		}
	}
	assert(i != states.size());

	currentState->onEnter();
}

void Actor::update(GameTime& time)
{
	currentState->onUpdate(time);
}

bool Actor::onEvent(const Event& e)
{
	return currentState->onEvent(e);
}

} // end namespace vik
