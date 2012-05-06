#ifndef SDLINCLUDE_H_INCLUDED
#define SDLINCLUDE_H_INCLUDED

/*
since stuff has to be included differently for different systems,
just include this file instead.
*/

// must include windows.h for OpenGL when using visual studio
#ifdef _MSC_VER
#include <windows.h>
#endif

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#endif // SDLINCLUDE_H_INCLUDED
