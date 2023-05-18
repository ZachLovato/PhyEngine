#include "Joint.h"
#include "../Physics/Shape/Body.h"
#include "../Engine/Graphics.h"

Joint::Joint(Body* bodyA, Body* bodyB, float stiffness, float restLength) :
	_bodyA{ bodyA },
	_bodyB{ bodyB },
	_stiffness{ stiffness },
	_restLength{ restLength }
{
	if (restLength == 0) _restLength = glm::distance(bodyA->_position, bodyB->_position);
}

void Joint::Step(float dt)
{
	glm::vec2 direction = _bodyA->_position - _bodyB->_position;
	
	float length = glm::length(direction);
	
	float x = length - _restLength;
	if (x < 0) return;
	float f = -_stiffness * x;

	glm::vec2 ndir = glm::normalize(direction);
	_bodyA->ApplyForce(f * -ndir);
	_bodyB->ApplyForce(f * ndir);
}

void Joint::Draw(Graphics* graphics)
{
	graphics->DrawLine(_bodyA->_position, _bodyB->_position, glm::vec4{ 1 });
}
