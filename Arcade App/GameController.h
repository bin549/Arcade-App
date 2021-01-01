#ifndef INPUT_GAMECONTROLLER_H_
#define INPUT_GAMECONTROLLER_H_

#include "InputAction.h"
#include <vector>

class GameController
{
public:
	GameController();
	void AddInputActionForKey(const ButtonAction& buttonAction);
	inline const MouseMovedAction& GetMouseMovedAction() { return mMouseMovedAction; }
	static bool IsPressed(InputState state);
	static InputKey ActionKey();
	static InputKey CancelKey();
	static InputKey LeftKey();
	static InputKey RightKey();
	static InputKey UpKey();
	static InputKey DownKey();

private:
	std::vector<ButtonAction> mButtonActions;
	MouseMovedAction mMouseMovedAction;
};

#endif
