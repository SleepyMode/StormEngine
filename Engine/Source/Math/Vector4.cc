
#include <cmath>
#include <algorithm>
#include "Wrappers/Format.h"
#include "Math/Vector4.h"

Vector4::Vector4()
{
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
	this->w = 0.f;
}

Vector4::Vector4(float value)
{
	this->x = value;
	this->y = value;
	this->z = value;
	this->w = value;
}

Vector4::Vector4(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0.f;
	this->w = 0.f;
}

Vector4::Vector4(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = 0.f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

float Vector4::length() const
{
	return std::sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w));
}

float Vector4::lengthSquared() const
{
	return ((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w));
}

float Vector4::min() const
{
	return std::min(std::min(this->x, this->y), std::min(this->z, this->w));
}

float Vector4::max() const
{
	return std::max(std::max(this->x, this->y), std::max(this->z, this->w));
}

void Vector4::normalize()
{
	float scale = 1.f / this->length();
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;
	this->w *= scale;
}

Vector4 Vector4::getNormalized()
{
	float scale = 1.f / this->length();
	Vector4 result(
		this->x * scale,
		this->y * scale,
		this->z * scale,
		this->w * scale
	);

	return result;
}

void Vector4::clamp(float min, float max)
{
	this->x = std::clamp(this->x, min, max);
	this->y = std::clamp(this->y, min, max);
	this->z = std::clamp(this->z, min, max);
	this->w = std::clamp(this->w, min, max);
}

Vector4 Vector4::getClamped(float min, float max) const
{
	return Vector4(std::clamp(this->x, min, max), std::clamp(this->y, min, max), std::clamp(this->z, min, max), std::clamp(this->w, min, max));
}

std::string Vector4::toString()
{
	return std::format("Vector4[{}, {}, {}, {}]", this->x, this->y, this->z, this->w);
}

Vector4& Vector4::operator=(const Vector4& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
	this->w = vector.w;
	return *this;
}

Vector4& Vector4::operator=(float value)
{
	this->x = value;
	this->y = value;
	this->z = value;
	this->w = value;
	return *this;
}

Vector4& Vector4::operator-()
{
	this->x = -(this->x);
	this->y = -(this->y);
	this->z = -(this->z);
	this->w = -(this->w);
	return *this;
}
