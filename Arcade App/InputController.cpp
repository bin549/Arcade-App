#include "InputController.h"

InputController::InputController() : mQuit(nullptr), mnoptrCurrentController(nullptr)
{
}

void InputController::Init(InputAction quitAction)
{
	mQuit = quitAction;
}