#include "PacmanStartScene.h"

PacmanStartScene::PacmanStartScene() : ButtonOptionsScene({ "Play Game", "High Scores" }, Color::Yellow())
{
}


void PacmanStartScene::Init()
{
	ButtonOptionsScene::Init();

}

void PacmanStartScene::Update(uint32_t dt)
{
}

void PacmanStartScene::Draw(Screen& theScreen)
{
	ButtonOptionsScene::Draw(theScreen);
}

const std::string& PacmanStartScene::GetSceneName() const
{
	static std::string name = "!Pacman Start!";
	return name;
}
