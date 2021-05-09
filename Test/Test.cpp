
//
// This is a temporary project to test some things while developing.
//

#include <cstdio>
#include "Core/Entity.h"
#include "Core/World.h"
#include "Components/Transform.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

#pragma comment(lib, "Engine.lib")

#define QUICK_TEST(name, id, eval) std::printf("[%c] "##name##" "##id##": %s\n", (eval) ? '+' : '-', (eval) ? "SUCCESS" : "FAILED")

int main(int argc, char* argv[])
{
	World* world = new World();
	Entity* entity = world->CreateEntity();
	if (entity == nullptr)
	{
		std::printf("[-] Failed to create entity!\n");
		return -1;
	}

	std::printf("[+] Entity World: 0x%llx [%s]\n", reinterpret_cast<std::uintptr_t>(entity->GetWorld()),
		(reinterpret_cast<std::uintptr_t>(entity->GetWorld()) == reinterpret_cast<std::uintptr_t>(world)) ? "CONFIRMED" : "UNCONFIRMED");
	std::printf("[+] Entity ID: %llu\n", entity->GetEntityId());

	Entity* entity2 = world->CreateEntity();
	Entity* entity3 = world->CreateEntity();

	for (const auto& x : world->GetEntities())
		std::printf("[+] 0x%llx [%s]\n", reinterpret_cast<std::uintptr_t>(x), (reinterpret_cast<std::uintptr_t>(x) == reinterpret_cast<std::uintptr_t>(entity)) ? "CONFIRMED" : "UNCONFIRMED");

	std::printf("[+] %s\n", entity->toString().c_str());
	std::printf("[+] %s\n", entity2->toString().c_str());
	std::printf("[+] %s\n", entity3->toString().c_str());
	entity2->Remove();
	for (const auto& x : world->GetEntities())
	{
		if (x == nullptr)
		{
			std::printf("[+] <null>\n");
			continue;
		}
		std::printf("[+] 0x%llx [%s]\n", reinterpret_cast<std::uintptr_t>(x), (reinterpret_cast<std::uintptr_t>(x) == reinterpret_cast<std::uintptr_t>(entity)) ? "CONFIRMED" : "UNCONFIRMED");
	}

	entity->AddComponent<Transform>();
	Transform* transform = entity->GetComponent<Transform>();
	if (transform == nullptr)
	{
		std::printf("[-] Entity transform is nullptr.\n");
		return -1;
	}
	std::printf("[+] %s\n", transform->toString().c_str());
	transform->setPosition(Vector3(5.3f, 1.f, 2.f));
	std::printf("[+] %s\n", transform->toString().c_str());

	for (const auto& x : world->GetEntities())
	{
		if (x == nullptr)
			continue;

		if (x->HasComponent<Transform>())
			std::printf("[+] %s: %s\n", x->toString().c_str(), x->GetComponent<Transform>()->toString().c_str());
		else
			std::printf("[+] %s: no\n", x->toString().c_str());
	}

	Vector2 v2_1;
	Vector2 v2_2;
	Vector2 v2_3(5412.f);
	Vector2 v2_4(5.f, 12.f);
	Vector2 v2_5(11.f, 11.f);

	QUICK_TEST("Vector2", "1", (v2_1 == v2_2));
	QUICK_TEST("Vector2", "2", (v2_1 != v2_3));

	return 0;
}
