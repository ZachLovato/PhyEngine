#pragma once
#include "Body.h"

namespace Integrator
{
	void ExplicitEuler(Body& body, float dt)
	{
		body._position = body._position + body._velocity * dt;
		body._velocity = body._velocity + (body._force * body._invMass) * dt;
	}

	void SemiImplicitEuler(Body& body, float dt)
	{
		body._velocity = body._velocity + (body._force * body._invMass) * dt;
		body._position = body._position + body._velocity * dt;
	}	
}