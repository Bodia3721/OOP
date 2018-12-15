#pragma once
#include <string>
#include <time.h>
#include <vector>

struct File
{
public:
	enum class Type
	{
		File = 0,
		Directory
	};

	std::string name;
	Type type;
	size_t size;
	time_t creationTime;
	time_t modificationTime;
};

