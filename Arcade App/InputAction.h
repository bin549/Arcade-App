#ifndef INPUT_INPUTACTION_H_
#define INPUT_INPUTACTION_H_

#include <functional>

using InputState = uint8_t;

using InputAction = std::function<void(uint32_t dt, InputState)>;

struct MousePosition
{
	int32_t xPos, yPos;
};


using MouseMovedAction = std::function<void(const MousePosition& mousePosition)>;

#endif