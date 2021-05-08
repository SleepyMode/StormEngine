
#include <cmath>
#include "Math/Quaternion.h"
#include "Core/Platform.h"

Quaternion::Quaternion()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

Quaternion::Quaternion(float value)
{
	this->x = value;
	this->y = value;
	this->z = value;
	this->w = value;
}

Quaternion::Quaternion(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Quaternion::Quaternion(Vector3 eulerAngles, float w)
{
	this->x = eulerAngles.x;
	this->y = eulerAngles.y;
	this->z = eulerAngles.z;
	this->w = w;
}

Quaternion::Quaternion(float rotationX, float rotationY, float rotationZ)
{
	//
	// Thank you, OpenTK!
	//
	static constexpr float multiplier = 0.5f;
	rotationX *= multiplier;
	rotationY *= multiplier;
	rotationZ *= multiplier;

	float c1 = std::cos(rotationX);
	float c2 = std::cos(rotationY);
	float c3 = std::cos(rotationZ);
	float s1 = std::sin(rotationX);
	float s2 = std::sin(rotationY);
	float s3 = std::sin(rotationZ);

	this->x = (s1 * c2 * c3) + (c1 * s2 * s3);
	this->y = (c1 * s2 * c3) - (s1 * c2 * s3);
	this->z = (c1 * c2 * s3) + (s1 * s2 * c3);
	this->w = (c1 * c2 * c3) - (s1 * s2 * s3);
}

Quaternion::Quaternion(Vector3 eulerAngles)
{
	static constexpr float multiplier = 0.5f;
	float rotationX = eulerAngles.x * multiplier;
	float rotationY = eulerAngles.y * multiplier;
	float rotationZ = eulerAngles.z * multiplier;

	float c1 = std::cos(rotationX);
	float c2 = std::cos(rotationY);
	float c3 = std::cos(rotationZ);
	float s1 = std::sin(rotationX);
	float s2 = std::sin(rotationY);
	float s3 = std::sin(rotationZ);

	this->x = (s1 * c2 * c3) + (c1 * s2 * s3);
	this->y = (c1 * s2 * c3) - (s1 * c2 * s3);
	this->z = (c1 * c2 * s3) + (s1 * s2 * c3);
	this->w = (c1 * c2 * c3) - (s1 * s2 * s3);
}

float Quaternion::length()
{
	return std::sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w));
}

float Quaternion::lengthSquared()
{
	return ((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w));
}

void Quaternion::normalize()
{
	float scale = 1.f / this->length();
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;
	this->w *= scale;
}

Quaternion Quaternion::getNormalized()
{
	float scale = 1.f / this->length();
	Quaternion result(
		this->x * scale,
		this->y * scale,
		this->z * scale,
		this->w * scale
	);

	return result;
}

void Quaternion::invert()
{
	float lengthSquared = this->lengthSquared();
	if (lengthSquared == 0.f)
		return;

	float scale = 1.f / lengthSquared;
	this->x *= -scale;
	this->y *= -scale;
	this->z *= -scale;
	this->w *= scale;
}

Quaternion Quaternion::getInverted()
{
	float lengthSquared = this->lengthSquared();
	if (lengthSquared == 0.f)
	{
		Quaternion result(
			this->x,
			this->y,
			this->z,
			this->w
		);

		return result;
	}
	else
	{
		float scale = 1.f / lengthSquared;
		Quaternion result(
			this->x * -scale,
			this->y * -scale,
			this->z * -scale,
			this->w * scale
		);

		return result;
	}

	UNREACHABLE;
}

void Quaternion::conjugate()
{
	this->x = -(this->x);
	this->y = -(this->y);
	this->z = -(this->z);
}

Quaternion Quaternion::getConjugated()
{
	Quaternion result(
		-(this->x),
		-(this->y),
		-(this->z),
		this->w
	);

	return result;
}

Vector3 Quaternion::toEulerAngles()
{
	//
	// Apparently the most fucked up number on earth.
	// Out of curiosity I went ahead and searched up how other game engines
	// handle this and this number came up plenty of times. Every single time,
	// it came up as association with things that are completely broken.
	// Bug report after bug report. Gotta love this.
	//
	static constexpr float singularityThreshold = 0.4999995f;
	static constexpr float pi = 3.14159274101257324219f;

	float squaredX = this->x * this->x;
	float squaredY = this->y * this->y;
	float squaredZ = this->z * this->z;
	float squaredW = this->w * this->w;
	float unit = squaredX + squaredY + squaredZ + squaredW;
	float singularityTest = (this->x * this->z) + (this->w * this->y);

	if (singularityTest > (singularityThreshold * unit))
	{
		this->x = 0.f;
		this->y = pi / 2.f;
		this->z = 2.f * std::atan2(this->x, this->y);
	}
	else if (singularityTest < (-singularityThreshold * unit))
	{
		this->x = 0.f;
		this->y = -pi / 2.f;
		this->z = -2.f * std::atan2(this->x, this->y);
	}
	else
	{
		this->x = std::atan2(2.f * ((this->w * this->x) - (this->y * this->z)), squaredW - squaredX - squaredY + squaredZ);
		this->y = std::asin(2.f * singularityTest / unit);
		this->z = std::atan2(2.f * ((this->w * this->z) - (this->x * this->y)), squaredW + squaredX - squaredY - squaredZ);
	}

	UNREACHABLE;
}
