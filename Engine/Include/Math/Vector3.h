
#pragma once

#include "Concept/IStringifyable.h"

class Vector3 : public IStringifyable
{
public:
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float value);
	Vector3(float x, float y);
	Vector3(float x, float y, float z);

	float length()			const;
	float lengthSquared()	const;

	float min() const;
	float max() const;

	void	normalize();
	Vector3	getNormalized();

	float dot(const Vector3& other);
	Vector3& cross(const Vector3& other);

	void	clamp(float min, float max);
	Vector3 getClamped(float min, float max) const;

	virtual std::string toString() override;

	Vector3& operator=(const Vector3& vector);
	Vector3& operator=(float value);
	Vector3& operator-();

	friend inline bool		operator==(const Vector3&	lhs, const Vector3& rhs);
	friend inline bool		operator!=(const Vector3&	lhs, const Vector3& rhs);
	friend inline Vector3&	operator+=(const Vector3&	lhs, const Vector3& rhs);
	friend inline Vector3&	operator-=(const Vector3&	lhs, const Vector3& rhs);
	friend inline Vector3&	operator*=(const Vector3&	lhs, const Vector3& rhs);
	friend inline Vector3&	operator/=(const Vector3&	lhs, const Vector3& rhs);
	friend inline Vector3&	operator+ (const Vector3&	lhs, const Vector3& rhs);
	friend inline Vector3&	operator- (const Vector3&	lhs, const Vector3& rhs);
	friend inline Vector3&	operator* (const Vector3&	lhs, const Vector3& rhs);
	friend inline Vector3&	operator/ (const Vector3&	lhs, const Vector3& rhs);
	friend inline Vector3&	operator+=(const Vector3&	lhs, float			rhs);
	friend inline Vector3&	operator-=(const Vector3&	lhs, float			rhs);
	friend inline Vector3&	operator*=(const Vector3&	lhs, float			rhs);
	friend inline Vector3&	operator/=(const Vector3&	lhs, float			rhs);
	friend inline Vector3&	operator+ (const Vector3&	lhs, float			rhs);
	friend inline Vector3&	operator- (const Vector3&	lhs, float			rhs);
	friend inline Vector3&	operator* (const Vector3&	lhs, float			rhs);
	friend inline Vector3&	operator/ (const Vector3&	lhs, float			rhs);
	friend inline Vector3&	operator+=(float			lhs, const Vector3& rhs);
	friend inline Vector3&	operator-=(float			lhs, const Vector3& rhs);
	friend inline Vector3&	operator*=(float			lhs, const Vector3& rhs);
	friend inline Vector3&	operator/=(float			lhs, const Vector3& rhs);
	friend inline Vector3&	operator+ (float			lhs, const Vector3& rhs);
	friend inline Vector3&	operator- (float			lhs, const Vector3& rhs);
	friend inline Vector3&	operator* (float			lhs, const Vector3& rhs);
	friend inline Vector3&	operator/ (float			lhs, const Vector3& rhs);
};

inline bool operator==(const Vector3& lhs, const Vector3& rhs)
{
	return (lhs.x == rhs.x and lhs.y == rhs.y and lhs.z == rhs.z);
}

inline bool operator!=(const Vector3& lhs, const Vector3& rhs)
{
	return (lhs.x != rhs.x or lhs.y != rhs.y or lhs.z != rhs.z);
}

inline Vector3& operator+=(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	return result;
}

inline Vector3& operator-=(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	return result;
}

inline Vector3& operator*=(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
	return result;
}

inline Vector3& operator/=(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
	return result;
}

inline Vector3& operator+(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	return result;
}

inline Vector3& operator-(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	return result;
}

inline Vector3& operator*(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
	return result;
}

inline Vector3& operator/(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
	return result;
}

inline Vector3& operator+=(const Vector3& lhs, float rhs)
{
	Vector3 result(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
	return result;
}

inline Vector3& operator-=(const Vector3& lhs, float rhs)
{
	Vector3 result(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
	return result;
}

inline Vector3& operator*=(const Vector3& lhs, float rhs)
{
	Vector3 result(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
	return result;
}

inline Vector3& operator/=(const Vector3& lhs, float rhs)
{
	Vector3 result(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
	return result;
}

inline Vector3& operator+(const Vector3& lhs, float rhs)
{
	Vector3 result(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
	return result;
}

inline Vector3& operator-(const Vector3& lhs, float rhs)
{
	Vector3 result(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
	return result;
}

inline Vector3& operator*(const Vector3& lhs, float rhs)
{
	Vector3 result(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
	return result;
}

inline Vector3& operator/(const Vector3& lhs, float rhs)
{
	Vector3 result(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
	return result;
}

inline Vector3& operator+=(float lhs, const Vector3& rhs)
{
	Vector3 result(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);
	return result;
}

inline Vector3& operator-=(float lhs, const Vector3& rhs)
{
	Vector3 result(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z);
	return result;
}

inline Vector3& operator*=(float lhs, const Vector3& rhs)
{
	Vector3 result(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
	return result;
}

inline Vector3& operator/=(float lhs, const Vector3& rhs)
{
	Vector3 result(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
	return result;
}

inline Vector3& operator+(float lhs, const Vector3& rhs)
{
	Vector3 result(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);
	return result;
}

inline Vector3& operator-(float lhs, const Vector3& rhs)
{
	Vector3 result(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z);
	return result;
}

inline Vector3& operator*(float lhs, const Vector3& rhs)
{
	Vector3 result(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
	return result;
}

inline Vector3& operator/(float lhs, const Vector3& rhs)
{
	Vector3 result(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
	return result;
}
