#ifndef INPUT_GAMECONTROLLER_H_
#define INPUT_GAMECONTROLLER_H_

#include "InputAction.h"

class GameController
{
public:
	GameController();
	inline const MouseMovedAction& GetMouseMovedAction() { return mMouseMovedAction; }

private:
	MouseMovedAction mMouseMovedAction;


};

#endif
