#include "PhysicsObject.h"

PhysicsObject::~PhysicsObject()
{
	delete _body;
	delete _shape;
}

void PhysicsObject::Step(float dt)
{
	_body->Step(dt);
}

void PhysicsObject::Draw(Graphics* graphics)
{
	_shape->Draw(graphics, _body->_position);
}
