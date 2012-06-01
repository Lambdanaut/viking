#include "viking/GameTime.hpp"

namespace vik
{

GameTime::GameTime(irr::ITimer* timer):
timer(timer),
lastTime(0),
deltaTime(0)
{
}

irr::u32 GameTime::getRealTime() const
{
	return timer->getRealTime();
}

irr::f32 GameTime::getSpeed() const
{
	return timer->getSpeed();
}

irr::u32 GameTime::getTime() const
{
	return timer->getTime();
}

irr::u32 GameTime::getLastTime() const
{
	return lastTime;
}

irr::u32 GameTime::getDeltaTime() const
{
	return deltaTime;
}

bool GameTime::isStopped() const
{
	return timer->isStopped();
}

void GameTime::setSpeed(irr::f32 speed)
{
	timer->setSpeed(speed);
}

void GameTime::setTime(irr::u32 time)
{
	lastTime = timer->getTime();
	timer->setTime(time);
	deltaTime = timer->getTime() - lastTime;
}

void GameTime::start()
{
	timer->start();
}

void GameTime::stop()
{
	lastTime = timer->getTime();
	timer->stop();
	deltaTime = 0;
}

void GameTime::tick()
{
	lastTime = getTime();
	timer->tick();
	deltaTime = timer->getTime() - lastTime;
}

} // end namespace vik
