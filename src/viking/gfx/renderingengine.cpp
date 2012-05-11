#include "viking/gfx/renderingengine.h"

#include <map>

#include "viking/core/string.h"
#include "viking/sdl/include.h"
#include "viking/gfx/camera.h"
#include "viking/gfx/texture.h"

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
    icon(0)
    {
    }

    ~RenderingEngineData()
    {
        SDL_FreeSurface(icon);
    }

    SDL_Surface* screen;
    SDL_Surface* icon;

    Camera camera;
    std::map<HashedString, std::shared_ptr<Texture>> texture_map;
};

RenderingEngine::RenderingEngine():
data(new RenderingEngineData())
{
}

RenderingEngine::~RenderingEngine()
{
    delete data;
}

static void Enable2DRendering()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

static void Disable2DRendering()
{
    glDisable(GL_BLEND);
}

static void Enable3DRendering()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_CULL_FACE);
}

static void Disable3DRendering()
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
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
    data->camera.GetView().Set(params.width, params.height);
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

Camera& RenderingEngine::GetCamera()
{
    return data->camera;
}

std::shared_ptr<Texture> RenderingEngine::GetTexture(const char* filename)
{
    HashedString filenameHash = HashString(filename);
    // check if texture was already created
    std::map<HashedString, std::shared_ptr<Texture>>::iterator it = data->texture_map.find(filenameHash);

    // new texture
    if(it == data->texture_map.end())
    {
        std::shared_ptr<Texture> new_tex = std::make_shared<Texture>();
        new_tex->Load(filename, true);
        data->texture_map[filenameHash] = new_tex;
        return new_tex;
    }

    return (*it).second;
}

void RenderingEngine::CleanTextureCache()
{
    std::map<HashedString, std::shared_ptr<Texture>>::iterator it = data->texture_map.begin();
    while(it != data->texture_map.end())
    {
        if( (*it).second.unique() )
        {
            data->texture_map.erase(it++);
        }
        else
        {
            ++it;
        }
    }
}

void RenderingEngine::Render()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    RenderOverlay();

    RenderScene();
}

void RenderingEngine::RenderOverlay()
{
    Enable2DRendering();
    data->camera.OnPreRender();

    glMatrixMode(GL_MODELVIEW);
   
    Disable2DRendering();
}

void RenderingEngine::RenderScene()
{
    Enable3DRendering();
    Disable3DRendering();
}

void RenderingEngine::SwapBuffers()
{
    SDL_GL_SwapBuffers();
}

} // end namespace vik
