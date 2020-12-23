#include "ArcadeScene.h"
#include "App.h"
#include "GameScene.h"

ArcadeScene::ArcadeScene() : ButtonOptionsScene({ "Tetris", "Break Out!", "Asteroids", "Pac-man" }, Color::Cyan())
{
}

void ArcadeScene::Init()
{
	std::vector<Button::ButtonAction> actions;
	actions.push_back([this] {
		App::Singleton().PushScene(GetScene(TETRIS));
	});
}
