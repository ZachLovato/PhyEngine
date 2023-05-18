#include "DragForce.h"
#include "../Shape/Body.h"
#include <glm/gtx/norm.hpp>

void DragForce::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
	{
		if (!_body->Intersects(body)) continue;

		if (body->_velocity == glm::vec2{ 0 }) continue;

		float f = 0.5f * glm::length2(body->_velocity) * m_drag;
		glm::vec2 force = glm::normalize(body->_velocity);
		body->ApplyForce(force  * -f);
	}
}
