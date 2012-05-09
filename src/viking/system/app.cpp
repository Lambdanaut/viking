#include "viking/system/app.h"
#include "viking/sdl/include.h"

namespace vik
{

App::App()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

App::~App()
{
    SDL_Quit();
}

void App::Sleep(u32 ms)
{
    SDL_Delay(ms);
}

} // end namespace vik
