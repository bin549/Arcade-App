#include "FileCommandLoader.h"

#include <fstream>
#include <iostream>

bool FileCommandLoader::LoadFile(const std::string& filePath)
{
	std::ifstream inFile;
	inFile.open(filePath);
	std::string line = "";
	if (!inFile.is_open())
	{
		std::cout << "Could not open the file: " << filePath << std::endl;
		return false;
	}
	while (!inFile.eof())
	{
		std::getline(inFile, line);
		size_t commandPos = std::string::npos;
		if ((commandPos = line.find(":")) != std::string::npos)
		{
			size_t dilimitPos = line.find_first_of(" ", commandPos);
			if (dilimitPos == std::string::npos)
			{
				dilimitPos = line.length();
			}
			else
			{
				dilimitPos -= 1;
			}
			std::string commandStr = line.substr(commandPos + 1, dilimitPos);
			dilimitPos += 1;
			for (size_t commandIndex = 0; commandIndex < mCommands.size(); ++commandIndex)
			{
				if (commandStr == mCommands[commandIndex].command)
				{
					if (mCommands[commandIndex].commandType == COMMAND_ONE_LINE)
					{
						ParseFuncParams params;
						params.dilimitPos = dilimitPos;
						params.lineNum = 0;
						params.line = line;
						mCommands[commandIndex].parseFunc(params);
					}
					else
					{
						std::string numLines = line.substr(dilimitPos + 1);
						int totalLines = std::stoi(numLines);
						int lineNum = 0;
						while (lineNum < totalLines)
						{
							std::getline(inFile, line);
							if (line.empty())
							{
								continue;
							}
							else
							{
								ParseFuncParams params;
								params.dilimitPos = 0;
								params.lineNum = lineNum;
								params.line = line;
								mCommands[commandIndex].parseFunc(params);
								++lineNum;
							}
						}
					}
				}
			}
		}
	}
	return true;
}