#include "Body.h"
#include "Integrator.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->_force += force;
}

void Body::Step(float dt)
{
	Integrator::ExplicitEuler(*this, dt);
	ClearForce();
	// damping
	_velocity *= (1.0f / (1.0f + (_damping * dt)));
}
