
#pragma once

#include <cstdint>
#include <vector>
#include "Concept/IStringifyable.h"
#include "Core/IEntityComponent.h"

class World;

class Entity : public IStringifyable
{
public:
	Entity() = delete;
	Entity(std::uint64_t entityId, World* world);
	~Entity();

	virtual std::string toString() override;

	template <typename T>
	inline bool HasComponent();

	template <typename T>
	inline bool AddComponent(bool allowDuplicates = false);

	template <typename T>
	inline void RemoveComponent();

	template <typename T>
	inline T* GetComponent();

	World* GetWorld();
	std::uint64_t GetEntityId();
	std::vector<IEntityComponent*> GetComponents();

	void Remove();

private:
	World* world;
	std::uint64_t entityId;
	std::vector<IEntityComponent*> components;
};

template<typename T>
inline bool Entity::HasComponent()
{
	for (auto component : components)
	{
		if (dynamic_cast<T*>(component))
			return true;
	}

	return false;
}

template<typename T>
inline bool Entity::AddComponent(bool allowDuplicates)
{
	if (!allowDuplicates)
	{
		if (this->HasComponent<T>())
			return false;
	}

	components.push_back(reinterpret_cast<IEntityComponent*>(new T()));
	return true;
}

template <typename T>
inline void Entity::RemoveComponent()
{
	for (auto it = components.begin(); it != components.end(); ++it)
	{
		if (dynamic_cast<T*>(*it))
		{
			components.erase(it);
			break;
		}
	}
}

template<typename T>
inline T* Entity::GetComponent()
{
	for (auto component : components)
	{
		T* castComponent = dynamic_cast<T*>(component);
		if (castComponent != nullptr)
			return castComponent;
	}

	return nullptr;
}
