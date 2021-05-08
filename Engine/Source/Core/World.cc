
#include "Core/World.h"
#include <stdexcept>

Entity* World::CreateEntity()
{
	std::uint64_t entityId = this->entityList.size();
	Entity* entity = new Entity(entityId, this);
	this->entityList.push_back(entity);
	if (this->entityList.at(entityId) != entity)
		throw 0;
	return entity;
}

Entity* World::GetEntity(std::uint64_t entityId)
{
	return this->entityList.at(entityId);
}

std::vector<Entity*>& World::GetEntities()
{
	return this->entityList;
}

void World::RemoveEntity(std::uint64_t entityId)
{
	try
	{
		Entity*& entity = this->entityList.at(entityId);
		delete entity;
		entity = nullptr;
	}
	catch (std::out_of_range exception)
	{
		//
		// TODO: Debug stuff
		// (update 2021/05/08: could throw an assert false & fastfail?)
		//
	}
}
