#include "SpriteSheet.h"
#include "FileCommandLoader.h"
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

bool SpriteSheet::LoadSpriteSections(const std::string& path)
{
	FileCommandLoader fileLoader;
	return fileLoader.LoadFile(path);
}
