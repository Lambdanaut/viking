#ifndef RENDERINGENGINE_H_INCLUDED
#define RENDERINGENGINE_H_INCLUDED

#include "viktypes.h"
#include <string>

namespace vik
{

class Camera2D;

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

    // set the currently used camera
    Camera2D* SetCamera2D();
    // Camera3D* SetCamera3D();

    // Rendering
    void Render();
    void SwapBuffers();
private:
    struct RenderingEngineData;
    RenderingEngineData* data;
};

} // end namespace vik

#endif // RENDERINGENGINE_H_INCLUDED
