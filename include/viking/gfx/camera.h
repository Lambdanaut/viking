#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "viking/core/types.h"
#include "viking/math/vector2.h"

namespace vik
{

class Camera2D
{
public:
    // width and height of area viewed
    Camera2D();

    void OnPreRender();

    // width and height of area viewed
    // usually the same as the window size
    Vector2<f32> view;
    // top left relative to (0,0)
    Vector2<f32> position; 
    // scale relative to 1.0
    Vector2<f32> scale; 
    // degrees
    f32 rotation; 
};

// TODO: class Camera3D

} // end namespace vik

#endif // CAMERA_H_INCLUDED
