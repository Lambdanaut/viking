#include "viking/core/string.h"

namespace vik
{

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
