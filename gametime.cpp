#include "gametime.h"

#include "sdlinclude.h"

namespace vik
{

GameTime::GameTime():
lastTime(0),
currentTime(0),
deltaTime(0)
{
}

void GameTime::Start()
{
	lastTime = currentTime = SDL_GetTicks();
}

void GameTime::Update()
{
	currentTime = SDL_GetTicks();
	deltaTime = currentTime - lastTime;
	lastTime = currentTime;
}

} // end namespace vik
