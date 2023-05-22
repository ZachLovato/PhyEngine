#pragma once

class Body;

class Joint
{
public:
	Joint(Body* bodyA, Body* bodyB, float stiffness, float restLength = 0);
	~Joint();

	void Step(float dt);
	void Draw(class Graphics* graphics);

protected:
	float _restLength{ 0 };
	float _stiffness{ 0 };

	Body* _bodyA{ nullptr };
	Body* _bodyB{ nullptr };
};