#include "World.h"
#include "../Physics/Shape/Body.h"
#include "../Physics/Force/ForceGenerator.h"
#include "../Physics/Joint.h"

//later change this to negative
glm::vec2 World::_gravity{ 0, 0 };

World::~World()
{
	for (auto body : _bodies)
	{
		if (body != nullptr )delete body;
	}

	_bodies.clear();
}

void World::Step(float dt)
{
	if (_bodies.size() != 0 && _forceGens.size() != 0)
	{
		std::vector<Body*> bodies(_bodies.begin(), _bodies.end());
		for (auto forceGenerator : _forceGens)
		{
			forceGenerator->Apply(bodies);
		}
	}
	for (auto joint : _joints) joint->Step(dt);
	for (auto body : _bodies) body->Step(dt);
}

void World::Draw(Graphics* graphics)
{
	for (auto joint : _joints)
	{
		joint->Draw(graphics);
	}
	for (auto force : _forceGens)
	{
		force->Draw(graphics);
	}
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

void World::AddJoint(Joint* joint)
{
	_joints.push_back(joint);
}

void World::RemoveJoint(Joint* joint)
{
	_joints.remove(joint);
}

void World::AddForceGenerators(ForceGenerator* forceGens)
{
	_forceGens.push_back(forceGens);
}
