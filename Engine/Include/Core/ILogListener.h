
#pragma once

#include <string>
#include "Core/Platform.h"

INTERFACE ILogListener
{
public:
	virtual ~ILogListener() = default;

	virtual void onLog(std::string message) = 0;
};
