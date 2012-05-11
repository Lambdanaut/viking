#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "viking/core/types.h"
#include "viking/math/transformable.h"

namespace vik
{

class Camera : public Transformable
{
public:
    // width and height of area viewed
    Camera();

    void OnPreRender();

    void SetView(const Vector2f& view);
    Vector2f& GetView();
private:
    // width and height of area viewed
    // usually the same as the window size
    Vector2f view;
};

} // end namespace vik

#endif // CAMERA_H_INCLUDED
