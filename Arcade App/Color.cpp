#include "Color.h"
#include <SDL.h>

const SDL_PixelFormat* Color::mFormat = nullptr;

void Color::InitColorFormat(const SDL_PixelFormat* format)
{
	Color::mFormat = format;
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SetRGBA(r, g, b, a);
}

void Color::SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	mColor = SDL_MapRGBA(mFormat, r, g, b, a);
}