#include "renderingengine.h"

#include "sdlinclude.h"

namespace vik
{

WindowCreationParams::WindowCreationParams(u32 width, u32 height, bool fullscreen):
width(width),
height(height),
bpp(32),
fullscreen(fullscreen),
icon(NULL)
{
}

struct RenderingEngine::RenderingEngineData
{
    RenderingEngineData():
    screen(0),
    icon(0)
    {
    }

    ~RenderingEngineData()
    {
        SDL_FreeSurface(icon);
    }

    SDL_Surface* screen;
    SDL_Surface* icon;
};

RenderingEngine::RenderingEngine():
data(new RenderingEngineData())
{
}

RenderingEngine::~RenderingEngine()
{
    delete data;
}

void RenderingEngine::CreateWindow(const WindowCreationParams& params)
{
    if(params.icon)
    {
        if(data->icon)
        {
            SDL_FreeSurface(data->icon);
        }
        data->icon = SDL_LoadBMP(params.icon);
        SDL_WM_SetIcon(data->icon, NULL);
    }

    u32 flags = SDL_OPENGL;
    if(params.fullscreen)
    {
        flags |= SDL_FULLSCREEN;
    }

    data->screen = SDL_SetVideoMode(params.width, params.height, params.bpp, flags);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void RenderingEngine::SetWindowTitle(const char* title)
{
    SDL_WM_SetCaption(title, NULL);
}

// not sure if this actually works
void RenderingEngine::CloseWindow()
{
    data->screen = SDL_SetVideoMode(0,0,0,SDL_NOFRAME);
}

void RenderingEngine::Render()
{
    // TODO: Conditionally allow depth testing
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    SDL_GL_SwapBuffers();
}

} // end namespace vik
