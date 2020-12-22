#include "App.h"
#include <SDL.h>
#include "InputAction.h"

App::App()
{

}

App::~App()
{
}

App& App::Singleton()
{
	static App theApp;
	return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
	mnoptrWindow = mScreen.Init(width, height, mag);
	return mnoptrWindow;
}

void App::Run()
{
	if (mnoptrWindow)
	{
		bool running = true;
		uint32_t lastTick = SDL_GetTicks();
		uint32_t currentTick = lastTick;

		uint32_t dt = 10;
		uint32_t accumulator = 0;

		mInputController.Init([&running](uint32_t dt, InputState state) {
			running = false;
		});

		while (running)
		{
			mScreen.SwapScreens();
		}
	}
}