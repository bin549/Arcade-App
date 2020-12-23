#ifndef GRAPHICS_SPRITESHEET_H_
#define GRAPHICS_SPRITESHEET_H_

#include "BMPImage.h"
#include <string>

class SpriteSheet
{
public:
	SpriteSheet();
	bool Load(const std::string& name);


private:
	bool LoadSpriteSections(const std::string& path);
	BMPImage mBMPImage;
};

#endif
