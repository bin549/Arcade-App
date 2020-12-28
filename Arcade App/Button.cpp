#include "Button.h"
#include "Screen.h"

Button::Button(const BitmapFont& bitmapFont, const Color& textColor, const Color& highlightColor) : mBitmapFont(bitmapFont), mTitle(""), mTextColor(textColor), mHighlightColor(highlightColor), mAction(nullptr), mHighlighted(false)
{
}

void Button::Draw(Screen& theScreen)
{
	theScreen.Draw(mBitmapFont, mTitle, mBitmapFont.GetDrawPosition(mTitle, mBBox, BFXA_CENTER, BFYA_CENTER), mTextColor);

	if (mHighlighted)
	{
		theScreen.Draw(mBBox, mHighlightColor);
	}
}