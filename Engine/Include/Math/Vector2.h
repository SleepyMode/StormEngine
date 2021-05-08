
#pragma once

#include "Concept/IStringifyable.h"

class Vector2 : public IStringifyable
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float value);
	Vector2(float x, float y);

	float length()			const;
	float lengthSquared()	const;

	float min() const;
	float max() const;

	void	clamp(float min, float max);
	Vector2 getClamped(float min, float max) const;

	virtual std::string toString() override;

	Vector2& operator=(const Vector2& vector);
	Vector2& operator=(float value);
	Vector2& operator-();

	friend inline bool		operator==(const Vector2&	lhs, const Vector2&	rhs);
	friend inline bool		operator!=(const Vector2&	lhs, const Vector2&	rhs);
	friend inline Vector2&	operator+=(const Vector2&	lhs, const Vector2&	rhs);
	friend inline Vector2&	operator-=(const Vector2&	lhs, const Vector2&	rhs);
	friend inline Vector2&	operator*=(const Vector2&	lhs, const Vector2&	rhs);
	friend inline Vector2&	operator/=(const Vector2&	lhs, const Vector2&	rhs);
	friend inline Vector2&	operator+ (const Vector2&	lhs, const Vector2&	rhs);
	friend inline Vector2&	operator- (const Vector2&	lhs, const Vector2&	rhs);
	friend inline Vector2&	operator* (const Vector2&	lhs, const Vector2&	rhs);
	friend inline Vector2&	operator/ (const Vector2&	lhs, const Vector2&	rhs);
	friend inline Vector2&	operator+=(const Vector2&	lhs, float			rhs);
	friend inline Vector2&	operator-=(const Vector2&	lhs, float			rhs);
	friend inline Vector2&	operator*=(const Vector2&	lhs, float			rhs);
	friend inline Vector2&	operator/=(const Vector2&	lhs, float			rhs);
	friend inline Vector2&	operator+ (const Vector2&	lhs, float			rhs);
	friend inline Vector2&	operator- (const Vector2&	lhs, float			rhs);
	friend inline Vector2&	operator* (const Vector2&	lhs, float			rhs);
	friend inline Vector2&	operator/ (const Vector2&	lhs, float			rhs);
	friend inline Vector2&	operator+=(float			lhs, const Vector2&	rhs);
	friend inline Vector2&	operator-=(float			lhs, const Vector2&	rhs);
	friend inline Vector2&	operator*=(float			lhs, const Vector2&	rhs);
	friend inline Vector2&	operator/=(float			lhs, const Vector2&	rhs);
	friend inline Vector2&	operator+ (float			lhs, const Vector2&	rhs);
	friend inline Vector2&	operator- (float			lhs, const Vector2&	rhs);
	friend inline Vector2&	operator* (float			lhs, const Vector2&	rhs);
	friend inline Vector2&	operator/ (float			lhs, const Vector2&	rhs);
};

inline bool operator==(const Vector2& lhs, const Vector2& rhs)
{
	return (lhs.x == rhs.x and lhs.y == rhs.y);
}

inline bool operator!=(const Vector2& lhs, const Vector2& rhs)
{
	return (lhs.x != rhs.x or lhs.y != rhs.y);
}

inline Vector2& operator+=(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result(lhs.x + rhs.x, lhs.y + rhs.y);
	return result;
}

inline Vector2& operator-=(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result(lhs.x - rhs.x, lhs.y - rhs.y);
	return result;
}

inline Vector2& operator*=(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result(lhs.x * rhs.x, lhs.y * rhs.y);
	return result;
}

inline Vector2& operator/=(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result(lhs.x / rhs.x, lhs.y / rhs.y);
	return result;
}

inline Vector2& operator+(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result(lhs.x + rhs.x, lhs.y + rhs.y);
	return result;
}

inline Vector2& operator-(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result(lhs.x - rhs.x, lhs.y - rhs.y);
	return result;
}

inline Vector2& operator*(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result(lhs.x * rhs.x, lhs.y * rhs.y);
	return result;
}

inline Vector2& operator/(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result(lhs.x / rhs.x, lhs.y / rhs.y);
	return result;
}

inline Vector2& operator+=(const Vector2& lhs, float rhs)
{
	Vector2 result(lhs.x + rhs, lhs.y + rhs);
	return result;
}

inline Vector2& operator-=(const Vector2& lhs, float rhs)
{
	Vector2 result(lhs.x - rhs, lhs.y - rhs);
	return result;
}

inline Vector2& operator*=(const Vector2& lhs, float rhs)
{
	Vector2 result(lhs.x * rhs, lhs.y * rhs);
	return result;
}

inline Vector2& operator/=(const Vector2& lhs, float rhs)
{
	Vector2 result(lhs.x / rhs, lhs.y / rhs);
	return result;
}

inline Vector2& operator+(const Vector2& lhs, float rhs)
{
	Vector2 result(lhs.x + rhs, lhs.y + rhs);
	return result;
}

inline Vector2& operator-(const Vector2& lhs, float rhs)
{
	Vector2 result(lhs.x - rhs, lhs.y - rhs);
	return result;
}

inline Vector2& operator*(const Vector2& lhs, float rhs)
{
	Vector2 result(lhs.x * rhs, lhs.y * rhs);
	return result;
}

inline Vector2& operator/(const Vector2& lhs, float rhs)
{
	Vector2 result(lhs.x / rhs, lhs.y / rhs);
	return result;
}

inline Vector2& operator+=(float lhs, const Vector2& rhs)
{
	Vector2 result(lhs + rhs.x, lhs + rhs.y);
	return result;
}

inline Vector2& operator-=(float lhs, const Vector2& rhs)
{
	Vector2 result(lhs - rhs.x, lhs - rhs.y);
	return result;
}

inline Vector2& operator*=(float lhs, const Vector2& rhs)
{
	Vector2 result(lhs * rhs.x, lhs * rhs.y);
	return result;
}

inline Vector2& operator/=(float lhs, const Vector2& rhs)
{
	Vector2 result(lhs / rhs.x, lhs / rhs.y);
	return result;
}

inline Vector2& operator+(float lhs, const Vector2& rhs)
{
	Vector2 result(lhs + rhs.x, lhs + rhs.y);
	return result;
}

inline Vector2& operator-(float lhs, const Vector2& rhs)
{
	Vector2 result(lhs - rhs.x, lhs - rhs.y);
	return result;
}

inline Vector2& operator*(float lhs, const Vector2& rhs)
{
	Vector2 result(lhs * rhs.x, lhs * rhs.y);
	return result;
}

inline Vector2& operator/(float lhs, const Vector2& rhs)
{
	Vector2 result(lhs / rhs.x, lhs / rhs.y);
	return result;
}
