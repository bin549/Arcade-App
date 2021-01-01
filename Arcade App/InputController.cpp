#include "InputController.h"
#include <SDL.h>
#include "GameController.h"

InputController::InputController() : mQuit(nullptr), mnoptrCurrentController(nullptr)
{
}

void InputController::Init(InputAction quitAction)
{
	mQuit = quitAction;
}

void InputController::Update(uint32_t dt)
{
	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
		{
			mQuit(dt, SDL_PRESSED);
		}
		break;
		case SDL_MOUSEMOTION:
		{
			if (mnoptrCurrentController)
			{
				if (MouseMovedAction mouseMoved = mnoptrCurrentController->GetMouseMovedAction())
				{
					MousePosition position;
					position.xPos = sdlEvent.motion.x;
					position.yPos = sdlEvent.motion.y;
					mouseMoved(position);
				}
			}
			break;
		}
		}
	}
}

void InputController::SetGameController(GameController* controller)
{
	mnoptrCurrentController = controller;
}
