#ifndef GRAPHICS_SCREEN_H_
#define GRAPHICS_SCREEN_H_

#include <stdint.h>

#include "ScreenBuffer.h"
#include "Color.h"

struct SDL_Window;


class Screen
{
public:
	SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag, bool fast = true);

private:
	uint32_t mWidth;
	uint32_t mHeight;

	Color mClearColor;

	SDL_Window* moptrWindow;
	SDL_Surface* mnoptrWindowSurface;
	SDL_Renderer* mRenderer;
	SDL_Texture* mTexture;
	SDL_PixelFormat* mPixelFormat;

	ScreenBuffer mBackBuffer;

	bool mFast;
};

#endif