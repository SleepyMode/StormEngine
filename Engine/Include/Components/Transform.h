
#pragma once

#include "Core/IEntityComponent.h"
#include "Math/Vector3.h"

//
// This is missing a Quaternion for rotation.
// Really should get to adding that.
//
class Transform : public IEntityComponent
{
public:
	Transform();

	void setPosition(Vector3 position);
	Vector3 getPosition() const;

	virtual std::string toString() override;

private:
	Vector3 position;
};
