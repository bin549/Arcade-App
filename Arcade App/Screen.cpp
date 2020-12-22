#include "Screen.h"
#include "Vec2D.h"

#include <SDL.h>
#include <cassert>

Screen::Screen() : mWidth(0), mHeight(0), moptrWindow(nullptr), mnoptrWindowSurface(nullptr), mRenderer(nullptr), mPixelFormat(nullptr), mTexture(nullptr), mFast(true)
{

}

Screen::~Screen()
{
}

Screen::Screen(const Screen& screen)
{
}

SDL_Window* Screen::Init(uint32_t w, uint32_t h, uint32_t mag, bool fast)
{
	mFast = fast;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Error SDL_Init Failed" << std::endl;
		return nullptr;
	}
	mWidth = w;
	mHeight = h;
	moptrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth * mag, mHeight * mag, 0);
	if (moptrWindow)
	{
		uint8_t rClear = 0;
		uint8_t gClear = 0;
		uint8_t bClear = 0;
		uint8_t aClear = 255;
		if (mFast)
		{
			mRenderer = SDL_CreateRenderer(moptrWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mRenderer == nullptr)
			{
				std::cout << "SDL_CreateRenderer failed" << std::endl;
				return nullptr;
			}
			SDL_SetRenderDrawColor(mRenderer, rClear, gClear, bClear, aClear);
		}
		else
		{
			mnoptrWindowSurface = SDL_GetWindowSurface(moptrWindow);
		}
		mPixelFormat = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
		if (mFast)
		{
			mTexture = SDL_CreateTexture(mRenderer, mPixelFormat->format, SDL_TEXTUREACCESS_STREAMING, w, h);
		}
		Color::InitColorFormat(mPixelFormat);
		mClearColor = Color(rClear, gClear, bClear, aClear);
		mBackBuffer.Init(mPixelFormat->format, mWidth, mHeight);
		mBackBuffer.Clear(mClearColor);
	}
	return moptrWindow;
}

void Screen::SwapScreens()
{
	assert(moptrWindow);
	if (moptrWindow)
	{
		ClearScreen();
		if (mFast)
		{
			uint8_t* textureData = nullptr;
			int texturePitch = 0;
			if (SDL_LockTexture(mTexture, nullptr, (void**)&textureData, &texturePitch) >= 0)
			{
				SDL_Surface* surface = mBackBuffer.GetSurface();
				memcpy(textureData, surface->pixels, surface->w * surface->h * mPixelFormat->BytesPerPixel);
				SDL_UnlockTexture(mTexture);
				SDL_RenderCopy(mRenderer, mTexture, nullptr, nullptr);
				SDL_RenderPresent(mRenderer);
			}
			SDL_UpdateWindowSurface(moptrWindow);
		}
		else
		{
			SDL_BlitScaled(mBackBuffer.GetSurface(), nullptr, mnoptrWindowSurface, nullptr);
			SDL_UpdateWindowSurface(moptrWindow);
		}
		mBackBuffer.Clear(mClearColor);
	}
}

void Screen::ClearScreen()
{
	assert(moptrWindow);
	if (moptrWindow)
	{
		if (mFast)
		{
			SDL_RenderClear(mRenderer);
		}
		else
		{
			SDL_FillRect(mnoptrWindowSurface, nullptr, mClearColor.GetPixelColor());
		}
	}
}
