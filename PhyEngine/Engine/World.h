#pragma once
#include <list>
#include <vector>
#include <glm/glm.hpp>

class World
{
public:
	~World();
	
	void Step(float dt);
	void Draw(class Graphics* graphics);

	void AddBodyObject(class Body* body);
	void RemoveBodyObject(class Body* body);

	void AddJoint(class Joint* joint);
	void RemoveJoint(class Joint* joint);

	void AddForceGenerators(class ForceGenerator* forceGens);

	static glm::vec2 _gravity;

private:
	std::list<class Body*> _bodies;
	std::list<class Joint*> _joints;
	std::vector<class ForceGenerator*> _forceGens;
};
