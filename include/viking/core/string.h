#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "viking/core/types.h"

namespace vik
{

typedef u32 HashedString;

HashedString HashString(const char *str);

} // end namespace vik

#endif // STRING_H_INCLUDED
