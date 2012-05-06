#ifndef VIKDEBUG_H_INCLUDED
#define VIKDEBUG_H_INCLUDED

namespace vik
{

// TODO: Add compatibility for other debug flags if necessary
#ifdef DEBUG
#define VIK_DEBUG
#endif

// This makes sure that no time is wasted calling debug functions in non-debug builds.
#ifdef VIK_DEBUG
// debug configuration
#define DebugPrintf(...) _DebugPrintf(__VA_ARGS__)
#define Assert(...) _Assert(__VA_ARGS__)
#else
// release configuration
#define DebugPrintf(...)
#define Assert(...)
#endif

void _DebugPrintf(const char* fmt, ...);
void _Assert(bool exp, const char* error_msg_fmt, ...);

} // end namespace vik

#endif // VIKDEBUG_H_INCLUDED
