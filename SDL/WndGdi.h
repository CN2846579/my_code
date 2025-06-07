#pragma once
#include <thread>
Uint32 _RGB(SDL_Surface* surface, short r, short g, short b) {
	if (!surface) {
		return 0; // Return 0 if surface is null
	}
	return  SDL_MapRGB(surface->format, r, g, b);
}
#ifndef SURFACE_MODE
#define SURFACE_MODE 0
#endif // !SURFACE_MODE
#ifndef RENDER_MODE
#define RENDER_MODE 1
#endif // !RENDER_MODE
#ifndef RGB
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef DWORD   COLORREF;
#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#endif
Uint32 _RGB(short r, short g, short b) {
	return RGB(b, g, r);
}
std::thread t;