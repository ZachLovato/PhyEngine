#pragma once
#include "Body.h"
#include "Shape.h"

class PhysicsObject
{
public:
	PhysicsObject(Body* body, Shape* shape) : _body{ body }, _shape{ shape } {}
	~PhysicsObject();

	Body* GetBody() { return _body; }
	Shape* GetShape() { return _shape; }

	void Step(float dt);
	void Draw(class Graphics* m_graphics);

protected:
	Body* _body{ nullptr };
	Shape* _shape{ nullptr };
};