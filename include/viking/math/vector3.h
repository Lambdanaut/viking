#ifndef VECTOR3_H_INCLUDED
#define VECTOR3_H_INCLUDED

#include <cmath>

namespace vik
{

// Repurposed from irrlicht
template <class T>
class Vector3
{
public:
	// Default constructor (null vector)
	Vector3() : x(0), y(0), z(0) {}
	// Constructor with two different values
	Vector3(T x, T y, T z) : x(x), y(y),z(z) {}
        void Set(T x, T y, T z){ this->x = x; this->y = y; this->z = z; }

	// operators
	Vector3<T> operator-() const { return Vector3<T>(-x, -y, -z); }

	Vector3<T> operator+(const Vector3<T>& other) const { return Vector3<T>(x + other.x, y + other.y, z + other.z); }
	Vector3<T>& operator+=(const Vector3<T>& other) { x+=other.x; y+=other.y; z+=other.z; return *this; }

	Vector3<T> operator-(const Vector3<T>& other) const { return Vector3<T>(x - other.x, y - other.y, z - other.z); }
	Vector3<T>& operator-=(const Vector3<T>& other) { x-=other.x; y-=other.y; z-=other.z; return *this; }

	Vector3<T> operator*(const T v) const { return Vector3<T>(x * v, y * v, z * v); }
	Vector3<T>& operator*=(const T v) { x*=v; y*=v; z*=v; return *this; }

	Vector3<T> operator/(const T v) const { return Vector3<T>(x / v, y / v, z / v); }
	Vector3<T>& operator/=(const T v) { x/=v; y/=v; z/=v; return *this; }

	T MagnitudeSQ() const
	{
		return x*x + y*y + z*z;
	}

	T Magnitude() const
	{
		return std::sqrt(MagnitudeSQ());
	}

	Vector3<T>& Normalize()
        {
		(*this) /= Magnitude();
		return *this;
        }

	T x;
	T y;
	T z;
};

typedef Vector3<f32> Vector3f;
typedef Vector3<f64> Vector3d;
typedef Vector3<s32> Vector3i;
typedef Vector3<u32> Vector3u;

} // end namespace vik

#endif // VECTOR3_H_INCLUDED
