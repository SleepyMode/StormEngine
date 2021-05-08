
#pragma once

#include "Core/IEntityComponent.h"
#include "Math/Quaternion.h"
#include "Math/Vector3.h"

class Transform : public IEntityComponent
{
public:
	Transform();

	void setPosition(Vector3 position);
	Vector3 getPosition() const;

	void setRotation(Quaternion rotation);
	Quaternion getRotation() const;

	virtual std::string toString() override;

private:
	Vector3 position;
	Quaternion rotation;
};
