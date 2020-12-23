#ifndef APP_BUTTON_H_
#define APP_BUTTON_H_

#include <functional>

class Button
{
public:
	using ButtonAction = std::function<void(void)>;
};


#endif