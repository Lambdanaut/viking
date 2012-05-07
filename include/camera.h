#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "viktypes.h"
#include "vector2d.h"

namespace vik
{

class Camera
{
public:
    virtual ~Camera(){}
    // called once when the camera is set to be used
    virtual void OnInit() =0;
    // called before rendering
    virtual void OnPreRender() =0;
};

class Camera2D : public Camera
{
public:
    // width and height of area viewed
    Camera2D(f32 width, f32 height);

    void OnInit();
    void OnPreRender();

    // original dimensions of camera view
    const f32 width;
    const f32 height;

    Vector2D<f32> position; // top left relative to (0,0)
    Vector2D<f32> scale; // scale relative to 1.0
    f32 rotation; // degrees
};

// TODO: Camera3D

} // end namespace vik

#endif // CAMERA_H_INCLUDED
