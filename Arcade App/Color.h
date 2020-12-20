#ifndef GRAPHICS_COLOR_H_
#define GRAPHICS_COLOR_H_

#include <stdint.h>

struct SDL_PixelFormat;

class Color
{
public:
	static const SDL_PixelFormat* mFormat;
	static void InitColorFormat(const SDL_PixelFormat* format);
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	static Color Black() { return Color(0, 0, 0, 255); }
};

#endif
