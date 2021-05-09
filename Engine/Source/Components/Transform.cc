
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

void Transform::setRotation(Quaternion rotation)
{
	this->rotation = rotation;
}

Quaternion Transform::getRotation() const
{
	return this->rotation;
}

std::string Transform::toString()
{
	return std::format("Transform[{}, {}]", this->position.toString(), this->rotation.toString());
}
