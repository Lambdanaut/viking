#ifndef HASHSTRING_HPP_INCLUDED
#define HASHSTRING_HPP_INCLUDED

#include <irrlicht/irrTypes.h>

namespace vik
{

typedef irr::u32 HashedString;

// don't call this one, call hashString instead.
constexpr HashedString _hashStringRecursive(HashedString hash, const char* str)
{
	return ( !*str ? hash :
		_hashStringRecursive(((hash << 5) + hash) + *str, str + 1)); 
}

// performs a compile time string hash
constexpr HashedString hashString(const char* str)
{
	return ( !str ? 0 :
		_hashStringRecursive(5381, str));
}

} // end namespace vik

#endif // HASHSTRING_HPP_INCLUDED
