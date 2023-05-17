#pragma once
#include "ForceGenerator.h"
#include "Body.h"

class AreaForce : public ForceGenerator
{
public:
	//<take in the pointer to a body, force magnitude and angle>
	AreaForce(class Body* body, float forceMagnitude, float angle) :
		ForceGenerator{ body },
		m_forceMagnitude{ forceMagnitude },
		m_angle{ angle }
	{}
	void Apply(std::vector<class Body*> bodies) override;
private:
	float m_forceMagnitude{ 1 };
	float m_angle{ 0 };
};