#include "World.h"
#include "Body.h"
#include "ForceGenerator.h"

//later change this to negative
glm::vec2 World::_gravity{ 0, 9.81f };

World::~World()
{
	for (auto body : _bodies)
	{
		delete body;
	}

	_bodies.clear();
}

void World::Step(float dt)
{
	for (auto fg : _forceGens)
	{
		fg->Apply(_bodies);
	}

	for (auto body : _bodies)
	{
		body->Step(dt);
	}
}

void World::Draw(Graphics* graphics)
{
	for (auto body : _bodies)
	{
		body->Draw(graphics);
	}
}

void World::AddBodyObject(Body* po)
{
	_bodies.push_back(po);
}

void World::RemoveBodyObject(Body* po)
{
	_bodies.remove(po);
}

void World::AddForceGenerators(ForceGenerator* forceGens)
{
	_forceGens.push_back(forceGens);
}
