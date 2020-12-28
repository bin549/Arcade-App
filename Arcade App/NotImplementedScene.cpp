#include "NotImplementedScene.h"
#include "App.h"


void NotImplementedScene::Init()
{
	ButtonAction backAction;
	backAction.key = GameController::CancelKey();
	backAction.action = [](uint32_t dt, InputState state) {
		if (GameController::IsPressed(state))
		{
			App::Singleton().PopScene();
		}
	};
	mGameController.AddInputActionForKey(backAction);
}

void NotImplementedScene::Update(uint32_t dt)
{
}


void NotImplementedScene::Draw(Screen& theScreen)
{
}

const std::string& NotImplementedScene::GetSceneName() const
{
	static std::string name = "Not Implemented!";
	return name;
}
