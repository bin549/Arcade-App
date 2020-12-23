#ifndef INPUT_INPUTCONTROLLER_H_
#define INPUT_INPUTCONTROLLER_H_

#include "InputAction.h"
#include "GameController.h"

class GameController;

class InputController
{
public:
	InputController();
	void Update(uint32_t dt);
	void Init(InputAction quitAction);
	void SetGameController(GameController* controller);

private:
	InputAction mQuit;
	GameController* mnoptrCurrentController;
};

#endif