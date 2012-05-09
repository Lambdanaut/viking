#ifndef RENDERINGENGINE_H_INCLUDED
#define RENDERINGENGINE_H_INCLUDED

#include "viking/core/types.h"
#include <string>
#include <memory>

namespace vik
{

class Camera2D;
class Texture;

struct WindowCreationParams
{
    // default constructor is for a typical 640x480 window
    WindowCreationParams(u32 width, u32 height, bool fullscreen = false);

    u32 width;
    u32 height;
    u8 bpp;
    bool fullscreen;
    std::string icon;
};

class RenderingEngine
{
public:
    RenderingEngine();
    ~RenderingEngine();

    // Window manipulation
    // probably setting the icon won't work if you close and recreate the window
    void CreateWindow(const WindowCreationParams& params);
    void SetWindowTitle(const char* title);
    void CloseWindow();

    // General settings
    void SetClearColor(f32 r, f32 g, f32 b);

    // get camera to modify 2D overlay view
    Camera2D& GetCamera2D();
    // TODO: Camera3D* SetCamera3D();

    // Creates a texture and returns reference to it
    // Ensures no copies are made of the same texture
    std::shared_ptr<Texture> GetTexture(const char* filename);
    // Deallocates all textures unused by any objects
    // Should be called every now and then between scenes...
    // TODO: Figure out if this is better than automatically deleting stu
    void CleanTextureCache();

    // Renders everything
    void Render();
    // Renders only the 2D overlay
    void RenderOverlay();
    // Renders 3d scene
    void RenderScene();

    void SwapBuffers();
private:
    struct RenderingEngineData;
    RenderingEngineData* data;
};

} // end namespace vik

#endif // RENDERINGENGINE_H_INCLUDED
