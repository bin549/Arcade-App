#ifndef GRAPHICS_SCREENBUFFER_H_
#define GRAPHICS_SCREENBUFFER_H_
#include "Color.h"

#include <SDL.h>

struct SDL_Surface;

class ScreenBuffer
{
public:
	ScreenBuffer();
	void Init(uint32_t format, uint32_t width, uint32_t h);
	void Clear(const Color& c = Color::Black());

private:
	SDL_Surface* mSurface;
};

#endif