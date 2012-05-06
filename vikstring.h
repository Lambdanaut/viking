#ifndef VIKSTRING_H_INCLUDED
#define VIKSTRING_H_INCLUDED

#include "viktypes.h"

namespace vik
{
// always use the HashedString typedef over u32.
typedef u32 HashedString;

// from http://www.cse.yorku.ca/~oz/hash.html
HashedString HashString(const char *str)
{
    HashedString hash = 5381;
    int c;

    while( (c = *str++))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

} // end namespace vik

#endif // VIKSTRING_H_INCLUDED
