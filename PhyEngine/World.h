#pragma once
#include "PhysicsObject.h"
#include <list>

class World
{
public:
	~World();
	
	void Step(float dt);
	void Draw(class Graphics* graphics);

	void AddPhysicsObject(PhysicsObject* po);
	void RemovePhysicsObject(PhysicsObject* po);

	static glm::vec2 _gravity;

private:
	std::list<PhysicsObject*> _objects;
};
