
#pragma once

#include <vector>
#include "Core/Entity.h"

class World
{
public:
	Entity* CreateEntity();
	Entity* GetEntity(std::uint64_t entityId);
	std::vector<Entity*>& GetEntities();
	void RemoveEntity(std::uint64_t entityId);

private:
	std::vector<Entity*> entityList;
};
