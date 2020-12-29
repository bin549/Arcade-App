#include "ButtonOptionsScene.h"
#include "App.h"


ButtonOptionsScene::ButtonOptionsScene(const std::vector<std::string>& optionNames, const Color& textColor) : mHighlightedOption(0)
{
	const BitmapFont& font = App::Singleton().GetFont();

	for (size_t i = 0; i < optionNames.size(); ++i)
	{
		Button b = { font, textColor };
		mButtons.push_back(b);
		mButtons.back().SetButtonText(optionNames[i]);
	}

	if (optionNames.size() > 0)
	{
		mButtons[mHighlightedOption].SetHighlighted(true);
	}
}

void ButtonOptionsScene::Init()
{
	ButtonAction upAction;
}

void ButtonOptionsScene::Update(uint32_t dt)
{
}

void ButtonOptionsScene::Draw(Screen& theScreen)
{
	for (auto& button : mButtons)
	{
		button.Draw(theScreen);
	}
}

void ButtonOptionsScene::SetButtonActions(const std::vector<Button::ButtonAction>& buttonActions)
{
	for (size_t i = 0; i < mButtons.size(); ++i)
	{
		mButtons[i].SetButtonAction(buttonActions[i]);
	}
}