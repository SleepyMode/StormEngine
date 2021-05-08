#include "Core/Debug.h"

#include "Wrappers/Format.h"
#include "Components/Transform.h"

Transform::Transform()
{
	this->position = Vector3(0.f);
}

void Transform::setPosition(Vector3 position)
{
	this->position = position;
}

Vector3 Transform::getPosition() const
{
	return this->position;
}

std::string Transform::toString()
{
	return std::format("Transform[{}, {}, {}]", this->position.x, this->position.y, this->position.z);
}
