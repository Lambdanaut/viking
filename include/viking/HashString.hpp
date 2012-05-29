#ifndef HASHSTRING_HPP_INCLUDED
#define HASHSTRING_HPP_INCLUDED

#include <irrlicht/irrTypes.h>

namespace vik
{

typedef irr::u32 HashedString;

// don't call this one, call HashString instead.
constexpr HashedString _HashStringRecursive(HashedString hash, const char* str)
{
	return ( !*str ? hash :
		_HashStringRecursive(((hash << 5) + hash) + *str, str + 1)); 
}

// playing with clojure finally comes in handy
// performs a compile time string hash
constexpr HashedString HashString(const char* str)
{
	return ( !str ? 0 :
		_HashStringRecursive(5381, str));
}

} // end namespace vik

#endif // HASHSTRING_HPP_INCLUDED
