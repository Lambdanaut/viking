#ifndef VIKSTRING_H_INCLUDED
#define VIKSTRING_H_INCLUDED

#include "viktypes.h"

namespace vik
{

typedef u32 HashedString;

HashedString HashString(const char *str);

} // end namespace vik

#endif // VIKSTRING_H_INCLUDED
