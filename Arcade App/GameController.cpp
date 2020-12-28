#include "GameController.h"
#include <SDL.h>

GameController::GameController() : mMouseMovedAction(nullptr)
{
}

void GameController::AddInputActionForKey(const ButtonAction& buttonAction)
{
	mButtonActions.push_back(buttonAction);
}

bool GameController::IsPressed(InputState state)
{
	return state == SDL_PRESSED;
}

InputKey GameController::CancelKey()
{
	return static_cast<InputKey>(SDLK_s);
}
