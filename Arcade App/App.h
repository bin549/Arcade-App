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
	static App& Singleton();
	bool Init(uint32_t width, uint32_t height, uint32_t mag);
	void Run();
	inline uint32_t Width() const { return mScreen.Width(); }
	inline uint32_t Height() const { return mScreen.Height(); }
	void PushScene(std::unique_ptr<Scene> scene);
	void PopScene();
	static const std::string& GetBasePath();
	Scene* TopScene();
	inline const BitmapFont& GetFont() const { return mFont; }

private:
	Screen mScreen;
	SDL_Window* mnoptrWindow;
	std::vector<std::unique_ptr<Scene>> mSceneStack;
	InputController mInputController;
	BitmapFont mFont;
};

#endif