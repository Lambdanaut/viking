#ifndef TRANSFORMABLE_H_INCLUDED
#define TRANSFORMABLE_H_INCLUDED

#include "viking/math/transform.h"
#include "viking/math/vector3.h"

namespace vik
{

class Transformable
{
public:
    Transformable():
    transform_dirty(false),
    inverse_dirty(false)
    {
    }

    void SetPosition(const Vector3f& pos)
    {
         position = pos;
         transform_dirty = true;
         inverse_dirty = true;
    }

    const Vector3f& GetPosition() const
    {
        return position;
    }
    
    void SetScale(const Vector3f& s)
    {
         scale = s;
         transform_dirty = true;
         inverse_dirty = true;
    }

    const Vector3f& GetScale() const
    {
        return scale;
    }

    // euler angles in radians
    void SetRotation(const Vector3f& rot)
    {
         rotation = rot;
         transform_dirty = true;
         inverse_dirty = true;
    }

    const Vector3f& GetRotation() const
    {
        return rotation;
    }

    const Transformf& GetTransform() const
    {
        if(transform_dirty)
        {
            transform = Transformf::Identity;
            transform.Scale(scale);
            transform.Rotate(rotation);
            transform.Translate(origin+position);
            transform_dirty = false;
        }
        return transform;
    }

    const Transformf& GetInverseTransform() const
    { 
        if(inverse_dirty)
        {
            inverse = Transformf::Identity;
            inverse.Translate(-origin-position);
            inverse.Rotate(-rotation);
            inverse.Scale(1.0f/scale.x, 1.0f/scale.y, 1.0f/scale.z);
            inverse_dirty = false;
        }
        return inverse;
    }
    
private:
    Vector3f origin;
    Vector3f position;
    Vector3f scale;
    Vector3f rotation; // radians/euler angles

    mutable Transformf transform;
    mutable bool transform_dirty;
    mutable Transformf inverse;
    mutable bool inverse_dirty;
};

} // end namespace vik

#endif // TRANSFORMABLE_H_INCLUDED
