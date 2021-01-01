#include "SpriteSheet.h"
#include "FileCommandLoader.h"
#include "Utils.h"
#include "App.h"

SpriteSheet::SpriteSheet()
{
}

bool SpriteSheet::Load(const std::string& name)
{
	bool loadedImage = mBMPImage.Load(App::Singleton().GetBasePath() + std::string("Assets\\") + name + ".bmp");
	bool loadedSpriteSections = LoadSpriteSections(App::Singleton().GetBasePath() + std::string("Assets\\") + name + ".txt");

	return loadedImage && loadedSpriteSections;
}

Sprite SpriteSheet::GetSprite(const std::string& spriteName) const
{
	size_t length = mSections.size();

	for (size_t i = 0; i < length; ++i)
	{
		if (StringCompare(mSections[i].key, spriteName))
		{
			return mSections[i].sprite;
		}
	}

	return Sprite();
}

bool SpriteSheet::LoadSpriteSections(const std::string& path)
{
	FileCommandLoader fileLoader;
	return fileLoader.LoadFile(path);
}