#include "App.h"
#include <SDL.h>
#include <iostream>
#include "ArcadeScene.h"
#include "InputAction.h"
#include <cassert>

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
	if (!mFont.Load("ArcadeFont"))
	{
		std::cout << "Could not load arcade font!" << std::endl;
		return false;
	}

	mnoptrWindow = mScreen.Init(width, height, mag);
	std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();
	PushScene(std::move(arcadeScene));

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
			currentTick = SDL_GetTicks();
			uint32_t frameTime = currentTick - lastTick;
			if (frameTime > 300)
			{
				frameTime = 300;
			}
			lastTick = currentTick;
			accumulator += frameTime;
			mInputController.Update(dt);
			
			mScreen.SwapScreens();
		}
	}
}

const std::string& App::GetBasePath()
{
	static std::string basePath = SDL_GetBasePath();
	return basePath;
}

void App::PushScene(std::unique_ptr<Scene> scene)
{
	assert(scene && "Don't push nullptr");
	if (scene)
	{
		scene->Init();
		
	}
}
