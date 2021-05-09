
#pragma once

#include <vector>
#include "Core/Entity.h"

class World
{
public:
	Entity* createEntity();
	Entity* getEntity(std::uint64_t entityId);
	std::vector<Entity*>& getEntities();
	void removeEntity(std::uint64_t entityId);

private:
	std::vector<Entity*> entityList;
};
