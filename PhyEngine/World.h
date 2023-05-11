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

	void AddForceGenerators(class ForceGenerator* forceGens);

	static glm::vec2 _gravity;

private:
	std::list<class Body*> _bodies;

	std::vector<class ForceGenerator*> _forceGens;
};
