#ifndef UTILS_FILECOMMANDLOADER_H_
#define UTILS_FILECOMMANDLOADER_H_

#include <functional>
#include <string>
#include <vector>

enum CommandType
{
	COMMAND_ONE_LINE = 0,
	COMMAND_MULTI_LINE
};

struct ParseFuncParams
{
	std::string line;
	size_t dilimitPos;
	uint32_t lineNum;
};

using ParseFunc = std::function<void(const ParseFuncParams& params)>;

struct Command
{
	CommandType commandType = COMMAND_ONE_LINE;
	std::string command = "";
	ParseFunc parseFunc = nullptr;
};

class FileCommandLoader
{
public:
	bool LoadFile(const std::string& filePath);

private:
	std::vector<Command> mCommands;
};

#endif