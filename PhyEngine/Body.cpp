#include "Body.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->_force += force;
}

void Body::Step(float dt)
{
	glm::vec2 acceleration = (_force * _invMass);

	_position += _velocity * dt;
	_velocity += acceleration * dt;

	_velocity *= 1.0f / (1.0f + (dt * 0.1f));
}
