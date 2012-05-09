#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <cstdint>

/*
TODO:
The way primitive types work varies by compiler, OS...
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

/*
tests which assure all types have the correct size
*/

static_assert(sizeof(s8) == 1, "Signed 8-bit integer size incorrect.");
static_assert(sizeof(s16) == 2, "Signed 16-bit integer size incorrect.");
static_assert(sizeof(s32) == 4, "Signed 32-bit integer size incorrect.");
static_assert(sizeof(s64) == 8, "Signed 64-bit integer size incorrect.");

static_assert(sizeof(u8) == 1, "Unsigned 8-bit integer size incorrect.");
static_assert(sizeof(u16) == 2, "Unsigned 16-bit integer size incorrect.");
static_assert(sizeof(u32) == 4, "Unsigned 32-bit integer size incorrect.");
static_assert(sizeof(u64) == 8, "Unsigned 64-bit integer size incorrect.");

static_assert(sizeof(f32) == 4, "Float size incorrect.");
static_assert(sizeof(f64) == 8, "Double size incorrect.");

} // end namespace vik

#endif // TYPES_H_INCLUDED
