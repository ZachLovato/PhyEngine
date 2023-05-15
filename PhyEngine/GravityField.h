#pragma once
#include "ForceGenerator.h"
#include <vector>

class GravityField : public ForceGenerator
{
public:

	GravityField(float strength) : _strength{ strength } { }

	void Apply(std::vector<class Body*> bodies) override;

private:
	float _strength{ 0 };
};