#include "World.h"

World::~World()
{
	for (auto po : _objects)
	{
		delete po;
	}

	_objects.clear();
}

void World::Step(float dt)
{
	for (auto po : _objects)
	{
		po->Step(dt);
	}
}

void World::Draw(Graphics* graphics)
{
	for (auto po : _objects)
	{
		po->Draw(graphics);
	}
}

void World::AddPhysicsObject(PhysicsObject* po)
{
	_objects.push_back(po);
}

void World::RemovePhysicsObject(PhysicsObject* po)
{
	_objects.remove(po);
}
