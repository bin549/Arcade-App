#ifndef GRAPHICS_SPRITESHEET_H_
#define GRAPHICS_SPRITESHEET_H_

#include "BMPImage.h"
#include <string>
#include <vector>
#include <stdint.h>

struct Sprite
{
	uint32_t xPos = 0;
	uint32_t yPos = 0;
	uint32_t width = 0;
	uint32_t height = 0;
};

class SpriteSheet
{
public:
	SpriteSheet();
	bool Load(const std::string& name);
	Sprite GetSprite(const std::string& spriteName) const;
	inline const BMPImage& GetBMPImage() const { return mBMPImage; }

private:
	bool LoadSpriteSections(const std::string& path);
	struct BMPImageSection
	{
		std::string key = "";
		Sprite sprite;
	};
	BMPImage mBMPImage;
	std::vector<BMPImageSection> mSections;
};

#endif
