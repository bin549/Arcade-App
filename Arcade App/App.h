#ifndef APP_APP_H_
#define APP_APP_H_

#include "Screen.h"

#include <stdint.h>

struct SDL_Window;

class App
{
public:
	static App& Singleton();
	bool Init(uint32_t width, uint32_t height, uint32_t mag);
	void Run();

private:
	Screen mScreen;
	SDL_Window* mnoptrWindow;

};

#endif