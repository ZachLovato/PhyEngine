#include "World.h"
#include "../Physics/Shape/Body.h"
#include "../Physics/Force/ForceGenerator.h"
#include "../Physics/Joint.h"
#include "../Physics/Collision/Collision.h"
#include <vector>

glm::vec2 World::_gravity{ 0, 9.81 };

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
	for (auto joint : _joints) joint->Step(dt);
	if (_bodies.empty()) return;
	std::vector<Body*> bodies(_bodies.begin(), _bodies.end());
	if (_bodies.size() != 0 && _forceGens.size() != 0)
	{
		for (auto forceGenerator : _forceGens)
		{
			forceGenerator->Apply(bodies);
		}
	}
	for (auto body : _bodies) body->Step(dt);

	//collisions
	std::vector<Contact> contacts;
	Collision::CreateContacts(bodies, contacts);
	Collision::SeparateContacts(contacts);
	Collision::ResolveContacts(contacts);
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
