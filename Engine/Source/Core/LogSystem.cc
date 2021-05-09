
#include "Core/LogSystem.h"

void LogSystem::write(std::string message)
{
	for (auto listener : LogSystem::listeners)
	{
		listener->onLog(message);
	}
}
