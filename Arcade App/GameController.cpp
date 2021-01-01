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

InputKey GameController::ActionKey()
{
	return static_cast<InputKey>(SDLK_a);
}

InputKey GameController::CancelKey()
{
	return static_cast<InputKey>(SDLK_s);
}

InputKey GameController::LeftKey()
{
	return static_cast<InputKey>(SDLK_LEFT);
}

InputKey GameController::RightKey()
{
	return static_cast<InputKey>(SDLK_RIGHT);
}

InputKey GameController::DownKey()
{
	return static_cast<InputKey>(SDLK_DOWN);
}

InputKey GameController::UpKey()
{
	return static_cast<InputKey>(SDLK_UP);
}

