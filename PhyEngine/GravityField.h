#pragma once
#include "ForceGenerator.h"

class GravityField : public ForceGenerator
{
public:

	GravityField(float strength) : _strength{ strength } { }

	void Apply(std::list<class Body*> bodies) override;

private:
	float _strength{ 0 };
};