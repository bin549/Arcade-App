#ifndef INPUT_INPUTCONTROLLER_H_
#define INPUT_INPUTCONTROLLER_H_

#include "InputAction.h"
#include "GameController.h"


class InputController
{
public:
	InputController();
	void Init(InputAction quitAction);

private:
	InputAction mQuit;
	GameController* mnoptrCurrentController;
};

#endif