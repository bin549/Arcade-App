#include "ScreenBuffer.h"


void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height)
{
	mSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
	Clear();
}