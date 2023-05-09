#pragma once
#include <glm/glm.hpp>

class Body
{
public:
	Body(const glm::vec2& position, const glm::vec2& velocity) : _position {position}, _velocity {velocity} {}
	Body(const glm::vec2& position, const glm::vec2& velocity, const float mass) : 
		_position{ position }, _velocity{ velocity }, _mass{ mass } 
	{
		_invMass = (mass == 0) ? 0 : 1 / mass ;
	}

	void ApplyForce(const glm::vec2& force);
	void Step(float dt);
	void ClearForce() { _force = glm::vec2{ 0, 0 }; };

	glm::vec2 _position{ 0, 0 };
	glm::vec2 _velocity{ 0, 0 };
	glm::vec2 _force{ 0, 0 };
	float _mass{ 1 };
	float _invMass{ 1 };
	float _damping{ 1 };
};