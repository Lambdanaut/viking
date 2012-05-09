#ifndef RECT_H_INCLUDED
#define RECT_H_INCLUDED

#include "viking/math/vector2.h"

namespace vik
{

template<class T>
class Rect
{
public:
    Rect(const Vector2<T>& position = Vector2<T>(), const Vector2<T>& size = Vector2<T>()):
    position(position),
    size(size)
    {
    }

    Vector2<T> position; // top left corner's x y
    Vector2<T> size; // width, height
};

} // end namespace vik

#endif // RECT_H_INCLUDED
