
#pragma once


#pragma once

#include "Concept/IStringifyable.h"

class Vector4 : public IStringifyable
{
public:
	float x;
	float y;
	float z;
	float w;

	Vector4();
	Vector4(float value);
	Vector4(float x, float y);
	Vector4(float x, float y, float z);
	Vector4(float x, float y, float z, float w);

	float length()			const;
	float lengthSquared()	const;

	float min() const;
	float max() const;

	void	normalize();
	Vector4	getNormalized();

	void	clamp(float min, float max);
	Vector4 getClamped(float min, float max) const;

	virtual std::string toString() override;

	Vector4& operator=(const Vector4& vector);
	Vector4& operator=(float value);
	Vector4& operator-();

	friend inline bool		operator==(const Vector4&	lhs, const Vector4& rhs);
	friend inline bool		operator!=(const Vector4&	lhs, const Vector4& rhs);
	friend inline Vector4&	operator+=(const Vector4&	lhs, const Vector4& rhs);
	friend inline Vector4&	operator-=(const Vector4&	lhs, const Vector4& rhs);
	friend inline Vector4&	operator*=(const Vector4&	lhs, const Vector4& rhs);
	friend inline Vector4&	operator/=(const Vector4&	lhs, const Vector4& rhs);
	friend inline Vector4&	operator+ (const Vector4&	lhs, const Vector4& rhs);
	friend inline Vector4&	operator- (const Vector4&	lhs, const Vector4& rhs);
	friend inline Vector4&	operator* (const Vector4&	lhs, const Vector4& rhs);
	friend inline Vector4&	operator/ (const Vector4&	lhs, const Vector4& rhs);
	friend inline Vector4&	operator+=(const Vector4&	lhs, float			rhs);
	friend inline Vector4&	operator-=(const Vector4&	lhs, float			rhs);
	friend inline Vector4&	operator*=(const Vector4&	lhs, float			rhs);
	friend inline Vector4&	operator/=(const Vector4&	lhs, float			rhs);
	friend inline Vector4&	operator+ (const Vector4&	lhs, float			rhs);
	friend inline Vector4&	operator- (const Vector4&	lhs, float			rhs);
	friend inline Vector4&	operator* (const Vector4&	lhs, float			rhs);
	friend inline Vector4&	operator/ (const Vector4&	lhs, float			rhs);
	friend inline Vector4&	operator+=(float			lhs, const Vector4& rhs);
	friend inline Vector4&	operator-=(float			lhs, const Vector4& rhs);
	friend inline Vector4&	operator*=(float			lhs, const Vector4& rhs);
	friend inline Vector4&	operator/=(float			lhs, const Vector4& rhs);
	friend inline Vector4&	operator+ (float			lhs, const Vector4& rhs);
	friend inline Vector4&	operator- (float			lhs, const Vector4& rhs);
	friend inline Vector4&	operator* (float			lhs, const Vector4& rhs);
	friend inline Vector4&	operator/ (float			lhs, const Vector4& rhs);
};

inline bool operator==(const Vector4& lhs, const Vector4& rhs)
{
	return (lhs.x == rhs.x and lhs.y == rhs.y and lhs.z == rhs.z and lhs.w == rhs.w);
}

inline bool operator!=(const Vector4& lhs, const Vector4& rhs)
{
	return (lhs.x != rhs.x or lhs.y != rhs.y or lhs.z != rhs.z or lhs.w != rhs.w);
}

inline Vector4& operator+=(const Vector4& lhs, const Vector4& rhs)
{
	Vector4 result(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
	return result;
}

inline Vector4& operator-=(const Vector4& lhs, const Vector4& rhs)
{
	Vector4 result(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
	return result;
}

inline Vector4& operator*=(const Vector4& lhs, const Vector4& rhs)
{
	Vector4 result(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
	return result;
}

inline Vector4& operator/=(const Vector4& lhs, const Vector4& rhs)
{
	Vector4 result(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
	return result;
}

inline Vector4& operator+(const Vector4& lhs, const Vector4& rhs)
{
	Vector4 result(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
	return result;
}

inline Vector4& operator-(const Vector4& lhs, const Vector4& rhs)
{
	Vector4 result(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
	return result;
}

inline Vector4& operator*(const Vector4& lhs, const Vector4& rhs)
{
	Vector4 result(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
	return result;
}

inline Vector4& operator/(const Vector4& lhs, const Vector4& rhs)
{
	Vector4 result(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
	return result;
}

inline Vector4& operator+=(const Vector4& lhs, float rhs)
{
	Vector4 result(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs);
	return result;
}

inline Vector4& operator-=(const Vector4& lhs, float rhs)
{
	Vector4 result(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs);
	return result;
}

inline Vector4& operator*=(const Vector4& lhs, float rhs)
{
	Vector4 result(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
	return result;
}

inline Vector4& operator/=(const Vector4& lhs, float rhs)
{
	Vector4 result(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
	return result;
}

inline Vector4& operator+(const Vector4& lhs, float rhs)
{
	Vector4 result(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs);
	return result;
}

inline Vector4& operator-(const Vector4& lhs, float rhs)
{
	Vector4 result(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs);
	return result;
}

inline Vector4& operator*(const Vector4& lhs, float rhs)
{
	Vector4 result(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
	return result;
}

inline Vector4& operator/(const Vector4& lhs, float rhs)
{
	Vector4 result(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
	return result;
}

inline Vector4& operator+=(float lhs, const Vector4& rhs)
{
	Vector4 result(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w);
	return result;
}

inline Vector4& operator-=(float lhs, const Vector4& rhs)
{
	Vector4 result(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w);
	return result;
}

inline Vector4& operator*=(float lhs, const Vector4& rhs)
{
	Vector4 result(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
	return result;
}

inline Vector4& operator/=(float lhs, const Vector4& rhs)
{
	Vector4 result(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w);
	return result;
}

inline Vector4& operator+(float lhs, const Vector4& rhs)
{
	Vector4 result(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w);
	return result;
}

inline Vector4& operator-(float lhs, const Vector4& rhs)
{
	Vector4 result(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w);
	return result;
}

inline Vector4& operator*(float lhs, const Vector4& rhs)
{
	Vector4 result(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
	return result;
}

inline Vector4& operator/(float lhs, const Vector4& rhs)
{
	Vector4 result(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w);
	return result;
}
