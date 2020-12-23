#ifndef APP_APP_H_
#define APP_APP_H_

#include "Screen.h"
#include "Scene.h"
#include <stdint.h>
#include <memory>
#include "InputController.h"
#include "BitmapFont.h"

struct SDL_Window;

class App
{
public:
	App();
	~App();
	static App& Singleton();
	bool Init(uint32_t width, uint32_t height, uint32_t mag);
	void Run();

	void PushScene(std::unique_ptr<Scene> scene);

	static const std::string& GetBasePath();

private:
	Screen mScreen;
	SDL_Window* mnoptrWindow;

	InputController mInputController;
	BitmapFont mFont;
};

#endif