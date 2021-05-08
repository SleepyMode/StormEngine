
#pragma once

#include "Math/Vector3.h"

class Quaternion
{
public:
	float x;
	float y;
	float z;
	float w;

	Quaternion();
	Quaternion(float value);
	Quaternion(float x, float y, float z, float w);
	Quaternion(Vector3 eulerAngles, float w);
	Quaternion(float rotationX, float rotationY, float rotationZ);
	Quaternion(Vector3 eulerAngles);

	float length();
	float lengthSquared();

	void normalize();
	Quaternion getNormalized();

	void invert();
	Quaternion getInverted();

	void conjugate();
	Quaternion getConjugated();

	Vector3 toEulerAngles();
};
