#ifndef Vector2D_H_INCLUDED
#define Vector2D_H_INCLUDED

namespace vik
{

// Repurposed from irrlicht
template <class T>
class Vector2D
{
public:
	// Default constructor (null vector)
	Vector2D() : x(T()), y(T()) {}
	// Constructor with two different values
	Vector2D(const T x, const T y) : x(x), y(y) {}

	// operators
	Vector2D<T> operator-() const { return Vector2D<T>(-x, -y); }

	Vector2D<T> operator+(const Vector2D<T>& other) const { return Vector2D<T>(x + other.x, y + other.y); }
	Vector2D<T>& operator+=(const Vector2D<T>& other) { x+=other.x; y+=other.y; return *this; }

	Vector2D<T> operator-(const Vector2D<T>& other) const { return Vector2D<T>(x - other.x, y - other.y); }
	Vector2D<T>& operator-=(const Vector2D<T>& other) { x-=other.x; y-=other.y; return *this; }

	Vector2D<T> operator*(const T v) const { return Vector2D<T>(x * v, y * v); }
	Vector2D<T>& operator*=(const T v) { x*=v; y*=v; return *this; }

	Vector2D<T> operator/(const T v) const { return Vector2D<T>(x / v, y / v); }
	Vector2D<T>& operator/=(const T v) { x/=v; y/=v; return *this; }

	T x;
	T y;
};

} // end namespace vik

#endif // Vector2D_H_INCLUDED
