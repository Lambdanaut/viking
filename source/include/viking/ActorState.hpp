#ifndef ACTORSTATE_HPP_INCLUDED
#define ACTORSTATE_HPP_INCLUDED

#include "viking/HashedString.hpp"
#include "viking/EventListener.hpp"

namespace vik
{

class GameTime;
class Actor;

// modifies state of Actors as a function of time and events.
class ActorState : public EventListener
{
public:
	ActorState(HashedString stateName, Actor* context);
	virtual ~ActorState(){}

	// Called when the state is entered
	virtual void onEnter(){}
	// Called at each tick
	virtual void onUpdate(GameTime& time){}
	// Called when the state is switched or the object is destroyed
	virtual void onLeave(){}
	
	// returns the name used to construct the state
	HashedString getName() const;
protected:
	// returns reference to actor this state modifies
	Actor* getContext();
private:
	Actor* context;
	HashedString stateName;
};

} // end namespace vik

#endif // ACTORSTATE_HPP_INCLUDED
