#include "BitmapFont.h"

#include <iostream>

bool BitmapFont::Load(const std::string& name)
{
	return mFontSheet.Load(name);
}
