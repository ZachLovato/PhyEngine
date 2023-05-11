#include "Body.h"
#include "Shape.h"
#include "Integrator.h"
#include "World.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->_force += force;
}

void Body::Step(float dt)
{
	if (_type != DYNAMIC) return;

	// gravity
	ApplyForce(World::_gravity * _gravityScale * _mass);

	Integrator::SemiImplicitEuler(*this, dt);
	ClearForce();
	// damping
	_velocity *= (1.0f / (1.0f + (_damping * dt)));
}

void Body::Draw(Graphics* graphics)
{
	_shape->Draw(graphics, _position);
}