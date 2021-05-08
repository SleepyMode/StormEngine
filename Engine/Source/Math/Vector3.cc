
#include <cmath>
#include <algorithm>
#include "Wrappers/Format.h"
#include "Math/Vector3.h"

Vector3::Vector3()
{
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
}

Vector3::Vector3(float value)
{
	this->x = value;
	this->y = value;
	this->z = value;
}

Vector3::Vector3(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0.f;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3::length() const
{
	return std::sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

float Vector3::lengthSquared() const
{
	return ((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

float Vector3::min() const
{
	return std::min(std::min(this->x, this->y), this->z);
}

float Vector3::max() const
{
	return std::max(std::max(this->x, this->y), this->z);
}

float Vector3::dot(const Vector3& other)
{
	return std::sqrt((this->x * other.x) + (this->y * other.y) + (this->z * other.z));
}

Vector3& Vector3::cross(const Vector3& other)
{
	//
	// Xyzzy intensifies.
	// Aka yzx->shift 2->yzx->shift 2.
	//
	this->x = (this->y * other.z) - (this->z * other.y);
	this->y = (this->z * other.x) - (this->x * other.z);
	this->z = (this->x * other.y) - (this->y * other.x);

	return *this;
}

void Vector3::clamp(float min, float max)
{
	this->x = std::clamp(this->x, min, max);
	this->y = std::clamp(this->y, min, max);
	this->z = std::clamp(this->z, min, max);
}

Vector3 Vector3::getClamped(float min, float max) const
{
	return Vector3(std::clamp(this->x, min, max), std::clamp(this->y, min, max), std::clamp(this->z, min, max));
}

std::string Vector3::toString()
{
	return std::format("Vector3[{}, {}, {}]", this->x, this->y, this->z);
}

Vector3& Vector3::operator=(const Vector3& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
	return *this;
}

Vector3& Vector3::operator=(float value)
{
	this->x = value;
	this->y = value;
	this->z = value;
	return *this;
}

Vector3& Vector3::operator-()
{
	this->x = -(this->x);
	this->y = -(this->y);
	this->z = -(this->z);
	return *this;
}
