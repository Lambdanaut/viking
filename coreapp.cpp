#include "coreapp.h"
#include "sdlinclude.h"

namespace vik
{

CoreApp::CoreApp()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

CoreApp::~CoreApp()
{
    SDL_Quit();
}

void CoreApp::sleep(u32 ms)
{
    SDL_Delay(ms);
}

} // end namespace vik
