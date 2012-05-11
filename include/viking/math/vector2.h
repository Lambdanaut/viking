#ifndef VECTOR2_H_INCLUDED
#define VECTOR2_H_INCLUDED

#include <cmath>

namespace vik
{

// Repurposed from irrlicht
template <class T>
class Vector2
{
public:
	// Default constructor (null vector)
	Vector2() : x(T()), y(T()) {}
	// Constructor with two different values
	Vector2(const T x, const T y) : x(x), y(y) {}
        void Set(const T x, const T y){ this->x = x; this->y = y; }

	// operators
	Vector2<T> operator-() const { return Vector2<T>(-x, -y); }

	Vector2<T> operator+(const Vector2<T>& other) const { return Vector2<T>(x + other.x, y + other.y); }
	Vector2<T>& operator+=(const Vector2<T>& other) { x+=other.x; y+=other.y; return *this; }

	Vector2<T> operator-(const Vector2<T>& other) const { return Vector2<T>(x - other.x, y - other.y); }
	Vector2<T>& operator-=(const Vector2<T>& other) { x-=other.x; y-=other.y; return *this; }

	Vector2<T> operator*(const T v) const { return Vector2<T>(x * v, y * v); }
	Vector2<T>& operator*=(const T v) { x*=v; y*=v; return *this; }

	Vector2<T> operator/(const T v) const { return Vector2<T>(x / v, y / v); }
	Vector2<T>& operator/=(const T v) { x/=v; y/=v; return *this; }

	T MagnitudeSQ() const
	{
		return x*x + y*y;
	}

	T Magnitude() const
	{
		return std::sqrt(MagnitudeSQ());
	}

	Vector2<T>& Normalize()
        {
		(*this) /= Magnitude();
		return *this;
        }

	T x;
	T y;
};

typedef Vector2<f32> Vector2f;
typedef Vector2<f64> Vector2d;
typedef Vector2<s32> Vector2i;
typedef Vector2<u32> Vector2u;

} // end namespace vik

#endif // VECTOR2_H_INCLUDED
