#ifndef VIKTYPES_H_INCLUDED
#define VIKTYPES_H_INCLUDED

#include <stdint.h>

/*
TODO:
The way primitive types work varies by compiler, OS...
Create some unit tests that ensure sizeof() for each type is correct.
Implement types for incompatible compilers, platforms if errors found.
*/

namespace vik
{

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

} // end namespace vik

#endif // VIKTYPES_H_INCLUDED
