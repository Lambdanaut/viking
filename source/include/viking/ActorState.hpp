#ifndef ACTORSTATE_HPP_INCLUDED
#define ACTORSTATE_HPP_INCLUDED

#include "viking/HashString.hpp"
#include "viking/EventListener.hpp"

namespace vik
{

class GameTime;
class Actor;

class ActorState : public EventListener
{
public:
	ActorState(HashedString stateName, Actor* context);
	virtual ~ActorState(){}

	virtual void onEnter(){}
	virtual void onUpdate(GameTime& time){}
	virtual void onLeave(){}
	
	HashedString getName() const;
protected:
	Actor* getContext();
private:
	Actor* context;
	HashedString stateName;
};

} // end namespace vik

#endif // ACTORSTATE_HPP_INCLUDED
