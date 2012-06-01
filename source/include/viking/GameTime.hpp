#ifndef GAMETIME_HPP_INCLUDED
#define GAMETIME_HPP_INCLUDED

#include <irrlicht/ITimer.h>

namespace vik
{

class GameTime
{
public:
	GameTime(irr::ITimer* timer);

	// current time in milliseconds of system
	irr::u32 getRealTime() const;
	// get virtual time of application
	irr::u32 getTime() const;
	// get virtual time of last tick
	irr::u32 getLastTime() const;
	// get difference in virtual time from current to last tick
	irr::u32 getDeltaTime() const;

	// current speed of time relative to system time flow
	irr::f32 getSpeed() const;
	// set speed of virtual timer relative to system time flow
	void setSpeed(irr::f32 speed);
	// true if the virtual timer is stopped
	bool isStopped() const;
	// manually re-arrange the virtual timer to a different time
	void setTime(irr::u32 time);

	// resumes and pauses the virtual timer
	// behaves like a stack: each call of stop must be matched by a start
	void start();
	void stop();

	// updates virtual time based on real time
	void tick();
private:
	irr::ITimer* timer;

	// virtual timer's last tick time.
	irr::u32 lastTime;
	// difference between virtual last and current time
	irr::u32 deltaTime;
};

} // end namespace vik

#endif // GAMETIME_HPP_INCLUDED
