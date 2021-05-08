
#include "Core/World.h"
#include "Core/Entity.h"
#include "Wrappers/Format.h"

Entity::Entity(std::uint64_t entityId, World* world)
{
	this->world = world;
	this->entityId = entityId;
	this->components = std::vector<IEntityComponent*>();
}

Entity::~Entity()
{
	for (auto component : components)
	{
		delete component;
	}
}

std::string Entity::toString()
{
	return std::format("Entity[{}]", this->entityId);
}

World* Entity::GetWorld()
{
	return this->world;
}

std::uint64_t Entity::GetEntityId()
{
	return this->entityId;
}

std::vector<IEntityComponent*> Entity::GetComponents()
{
	return this->components;
}

void Entity::Remove()
{
	//
	// Fun fact, at one point this used to be a "clear and suicide" function.
	// It would call GetEntities, set its own pointer to nullptr and then proceed
	// to call "delete this". Luckily, there's better alternatives. :)
	// Just goes to prove how incompetent of a programmer I am.
	//
	this->world->RemoveEntity(this->entityId);
}
