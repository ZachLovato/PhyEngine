#include "DragForce.h"
#include "Body.h"
#include <glm/gtx/norm.hpp>

void DragForce::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
	{
		if (!_body->Intersects(body)) continue;

		//<compute the drag force using 0.5f * length sqr * m_drag>
		float f = 0.5f * glm::length2(body->_position) * m_drag;
		glm::vec2 force = glm::normalize(body->_velocity);
		body->ApplyForce(force  * -f);
	}
}
