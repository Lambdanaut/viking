#include "renderingengine.h"

#include "sdlinclude.h"
#include "camera.h"

namespace vik
{

WindowCreationParams::WindowCreationParams(u32 width, u32 height, bool fullscreen):
width(width),
height(height),
bpp(32),
fullscreen(fullscreen)
{
}

struct RenderingEngine::RenderingEngineData
{
    RenderingEngineData():
    screen(0),
    icon(0),
    camera(0)
    {
    }

    ~RenderingEngineData()
    {
        SDL_FreeSurface(icon);
        delete camera;
    }

    SDL_Surface* screen;
    SDL_Surface* icon;

    Camera* camera;
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
    if(!params.icon.empty())
    {
        if(data->icon)
        {
            SDL_FreeSurface(data->icon);
        }
        data->icon = SDL_LoadBMP(params.icon.c_str());
        SDL_WM_SetIcon(data->icon, NULL);
    }

    u32 flags = SDL_OPENGL;
    if(params.fullscreen)
    {
        flags |= SDL_FULLSCREEN;
    }

    data->screen = SDL_SetVideoMode(params.width, params.height, params.bpp, flags);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // TODO: This will have to change to allow split-screen, I think.
    glViewport(0,0,params.width,params.height);
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

void RenderingEngine::SetClearColor(f32 r, f32 g, f32 b)
{
    glClearColor(r,g,b,1.0f);
}

Camera2D* RenderingEngine::SetCamera2D()
{
    delete data->camera;
    data->camera = new Camera2D(static_cast<f32>(data->screen->w), static_cast<f32>(data->screen->h));
    data->camera->OnInit();
    return static_cast<Camera2D*>(data->camera);
}

void RenderingEngine::Render()
{
    // TODO: Conditionally allow depth testing
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if(data->camera)
    {
        data->camera->OnPreRender();
    }
}

void RenderingEngine::SwapBuffers()
{
    SDL_GL_SwapBuffers();
}

} // end namespace vik
