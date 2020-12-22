#include "ScreenBuffer.h"

#include <SDL.h>
#include <cassert>

ScreenBuffer::ScreenBuffer() : mSurface(nullptr)
{
}

void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height)
{
	mSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
	Clear();
}

void ScreenBuffer::Clear(const Color& c)
{
	assert(mSurface);
	if (mSurface)
	{
		SDL_FillRect(mSurface, nullptr, c.GetPixelColor());
	}
}


