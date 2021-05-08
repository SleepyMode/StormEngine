
#pragma once

#include <string>
#include "Core/Platform.h"

INTERFACE IStringifyable
{
public:
	virtual std::string toString() = 0;
};
