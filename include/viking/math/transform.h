#ifndef TRANSFORM_H_INCLUDED
#define TRANSFORM_H_INCLUDED

#include <array>
#include <algorithm>
#include <cmath>
#include "viking/core/types.h"
#include "viking/math/vector2.h"
#include "viking/math/vector3.h"

namespace vik
{

/*
transformation matrix interface
inspired by SFML's sf::Transform and Game Engine Architecture's Transform
Stored in memory using column major ordering to conform with OpenGL.
Matrix is stored in memory as:
m[0] m[4] m[8]  m[12] 
m[1] m[5] m[9]  m[13] 
m[2] m[6] m[10] m[14] 
m[3] m[7] m[11] m[15] 
The top left 3x3 matrix contains info about rotation and scaling
The fourth column represents a translation
*/
template<class T>
class Transform
{
public:
    static const Transform Identity;

    Transform():
    m(Identity.m)
    {
    }

    Transform(T a11, T a12, T a13, T a14,
              T a21, T a22, T a23, T a24,
              T a31, T a32, T a33, T a34,
              T a41, T a42, T a43, T a44)
    {
        m[0] = a11; m[4] = a12; m[8] = a13;  m[12] = a14;
        m[1] = a21; m[5] = a22; m[9] = a23;  m[13] = a24;
        m[2] = a31; m[6] = a32; m[10] = a33; m[14] = a34;
        m[3] = a41; m[7] = a42; m[11] = a43; m[15] = a44;
    }

    
    void Translate(T x, T y, T z)
    {
        m[12] += x;
        m[13] += y;
        m[14] += z;
    }

    void Translate(T x, T y)
    {
        Translate(x,y,0);
    }

    void Translate(const Vector2<T>& v)
    {
        Translate(v.x,v.y);
    }
    
    void Translate(const Vector3<T>& v)
    {
        Translate(v.x,v.y,v.z);
    }

    void Scale(T x, T y, T z)
    {
        m[0] *= x;
        m[5] *= y;
        m[10] *= z;
    }

    void Scale(T x, T y)
    {
        Scale(x,y,0);
    }

    void Scale(const Vector3<T>& v)
    {
        Scale(v.x,v.y,v.z);
    }

    void Scale(const Vector2<T>& v)
    {
        Scale(v.x,v.y);
    }

    // rotate by euler angles in radians
    void Rotate(f32 x, f32 y, f32 z)
    {
        const f64 cr = cos( x );
        const f64 sr = sin( x );
        const f64 cp = cos( y );
        const f64 sp = sin( y );
        const f64 cy = cos( z );
        const f64 sy = sin( z );

        m[0] = ( cp*cy );
        m[4] = ( cp*sy );
        m[8] = ( -sp );

        const f64 srsp = sr*sp;
        const f64 crsp = cr*sp;

        m[1] = ( srsp*cy-cr*sy );
        m[5] = ( srsp*sy+cr*cy );
        m[9] = ( sr*cp );

        m[2] = ( crsp*cy+sr*sy );
        m[6] = ( crsp*sy-sr*cy );
        m[10] = ( cr*cp );
    }

    // rotate by euler angles in radians
    void Rotate(const Vector3f rot)
    {
        Rotate(rot.x,rot.y,rot.z);
    }

    void Combine(const Transform<T>& t)
    {
        const std::array<T,4*4>& m2 = t.m;
        const Transform<T> cpy(
        m[0]*m2[0] + m[4]*m2[1] + m[8]*m2[2] + m[12]*m2[3],
        m[0]*m2[4] + m[4]*m2[5] + m[8]*m2[6] + m[12]*m2[7],
        m[0]*m2[8] + m[4]*m2[9] + m[8]*m2[10] + m[12]*m2[11],
        m[0]*m2[12] + m[4]*m2[13] + m[8]*m2[14] + m[12]*m2[15],

        m[1]*m2[0] + m[5]*m2[1] + m[9]*m2[2] + m[13]*m2[3],
        m[1]*m2[4] + m[5]*m2[5] + m[9]*m2[6] + m[13]*m2[7],
        m[1]*m2[8] + m[5]*m2[9] + m[9]*m2[10] + m[13]*m2[11],
        m[1]*m2[12] + m[5]*m2[13] + m[9]*m2[14] + m[13]*m2[15],

        m[2]*m2[0] + m[6]*m2[1] + m[10]*m2[2] + m[14]*m2[3],
        m[2]*m2[4] + m[6]*m2[5] + m[10]*m2[6] + m[14]*m2[7],
        m[2]*m2[8] + m[6]*m2[9] + m[10]*m2[10] + m[14]*m2[11],
        m[2]*m2[12] + m[6]*m2[13] + m[10]*m2[14] + m[14]*m2[15],

        m[3]*m2[0] + m[7]*m2[1] + m[11]*m2[2] + m[15]*m2[3],
        m[3]*m2[4] + m[7]*m2[5] + m[11]*m2[6] + m[15]*m2[7],
        m[3]*m2[8] + m[7]*m2[9] + m[11]*m2[10] + m[15]*m2[11],
        m[3]*m2[12] + m[7]*m2[13] + m[11]*m2[14] + m[15]*m2[15]
        );
        *this = cpy;
    }

    const T* GetData() const
    {
         return m.data();
    }
private:
    std::array<T,4*4> m;
};

typedef Transform<f32> Transformf;
typedef Transform<f64> Transformd;

template<class T>
const Transform<T> Transform<T>::Identity(1,0,0,0,
                                          0,1,0,0,
                                          0,0,1,0,
                                          0,0,0,1);

} // end namespace vik

#endif // TRANSFORM_H_INCLUDED
