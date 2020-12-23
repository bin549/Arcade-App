#ifndef GRAPHICS_BITMAPFONT_H_
#define GRAPHICS_BITMAPFONT_H_

#include "SpriteSheet.h"
#include <stdint.h>

class BitmapFont
{
public:
	BitmapFont() {}
	bool Load(const std::string& name);

private:
	SpriteSheet mFontSheet;
};


#endif