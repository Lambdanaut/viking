#ifndef RECT2D_H_INCLUDED
#define RECT2D_H_INCLUDED

#include "vector2d.h"

namespace vik
{

template<class T>
class Rect2D
{
public:
    Rect2D(const Vector2D<T>& position = Vector2D<T>(), const Vector2D<T>& size = Vector2D<T>()):
    position(position),
    size(size)
    {
    }

    Vector2D<T> position; // top left corner's x y
    Vector2D<T> size; // width, height
};

} // end namespace vik

#endif // RECT2D_H_INCLUDED
