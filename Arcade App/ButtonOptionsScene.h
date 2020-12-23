#ifndef APP_BUTTONOPTIONSSCENE_H_
#define APP_BUTTONOPTIONSSCENE_H_

#include "Scene.h"
#include "Color.h"
#include <vector>
#include "Button.h"


class Screen;

class ButtonOptionsScene : public Scene
{
public:
	ButtonOptionsScene(const std::vector<std::string>& optionNames, const Color& textColor);
	virtual void Init() override;

private:
	int mHighlightedOption;
};

#endif
