
#pragma once

#include "Concept/IStringifyable.h"
#include "Core/Platform.h"

INTERFACE IEntityComponent : public IStringifyable
{
public:
	virtual ~IEntityComponent() = default;
};
