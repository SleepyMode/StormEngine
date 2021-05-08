
#include <cmath>
#include <algorithm>
#include "Wrappers/Format.h"
#include "Math/Vector2.h"

Vector2::Vector2()
{
	this->x = 0.f;
	this->y = 0.f;
}

Vector2::Vector2(float value)
{
	this->x = value;
	this->y = value;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2::length() const
{
	return std::sqrt((this->x * this->x) + (this->y * this->y));
}

float Vector2::lengthSquared() const
{
	return ((this->x * this->x) + (this->y * this->y));
}

float Vector2::min() const
{
	return std::min(this->x, this->y);
}

float Vector2::max() const
{
	return std::max(this->x, this->y);
}

void Vector2::normalize()
{
	float scale = 1.f / this->length();
	this->x *= scale;
	this->y *= scale;
}

Vector2 Vector2::getNormalized()
{
	float scale = 1.f / this->length();
	Vector2 result(
		this->x * scale,
		this->y * scale
	);

	return result;
}

void Vector2::clamp(float min, float max)
{
	this->x = std::clamp(this->x, min, max);
	this->y = std::clamp(this->y, min, max);
}

Vector2 Vector2::getClamped(float min, float max) const
{
	return Vector2(std::clamp(this->x, min, max), std::clamp(this->y, min, max));
}

std::string Vector2::toString()
{
	return std::format("Vector2[{}, {}]", this->x, this->y);
}

Vector2& Vector2::operator=(const Vector2& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	return *this;
}

Vector2& Vector2::operator=(float value)
{
	this->x = value;
	this->y = value;
	return *this;
}

Vector2& Vector2::operator-()
{
	this->x = -(this->x);
	this->y = -(this->y);
	return *this;
}
