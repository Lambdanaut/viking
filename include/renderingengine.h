#ifndef RENDERINGENGINE_H_INCLUDED
#define RENDERINGENGINE_H_INCLUDED

#include "viktypes.h"
#include "vikstring.h"

namespace vik
{

struct WindowCreationParams
{
    // default constructor is for a typical 640x480 window
    WindowCreationParams(u32 width, u32 height, bool fullscreen = false);

    u32 width;
    u32 height;
    u8 bpp;
    bool fullscreen;
    const char* icon;
};

class RenderingEngine
{
public:
    RenderingEngine();
    ~RenderingEngine();

    // probably setting the icon won't work if you close and recreate the window
    void CreateWindow(const WindowCreationParams& params);
    void SetWindowTitle(const char* title);
    void CloseWindow();

    void Render();
private:
    struct RenderingEngineData;
    RenderingEngineData* data;
};

} // end namespace vik

#endif // RENDERINGENGINE_H_INCLUDED
