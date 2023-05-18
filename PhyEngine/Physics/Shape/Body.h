#pragma once
#include <glm/glm.hpp>

class Body
{
public:
	enum Type
	{
		STATIC,
		KINEMATIC,
		DYNAMIC
	};

	//Body(const glm::vec2& position, const glm::vec2& velocity) : _position {position}, _velocity {velocity} {}
	Body(class Shape* shapez, const glm::vec2& position, const glm::vec2& velocity = { 0, 0 }, const float mass = 1, Type type = Type::DYNAMIC) :
		_shape{ shapez }, _position { position }, _velocity{ velocity }, _mass{ mass }, _type{ type }
	{
		//if (type == STATIC) _mass = 0;
		_invMass = (mass == 0) ? 0 : 1 / mass ;
	}

	void ApplyForce(const glm::vec2& force);
	void Step(float dt);
	void ClearForce() { _force = glm::vec2{ 0, 0 }; };
	void Draw(class Graphics* graphics);

	bool Intersects(class Body* body);

	class Shape* _shape{ nullptr };

	Type _type{ Type::DYNAMIC };

	glm::vec2 _position{ 0, 0 };
	glm::vec2 _velocity{ 0, 0 };
	glm::vec2 _force{ 0, 0 };

	float _gravityScale{ 1 };
	float _mass{ 1 };
	float _invMass{ 1 };
	float _damping{ 1 };
};