#include "PointForce.h"
#include "../Shape/Body.h"

void PointForce::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
	{
		if (!_body->Intersects(body)) continue;
			//<compute direction from body and m_body>
		glm::vec2 direction = body->_position - _body->_position;
			//<use the glm normalize from to create a unit vector>
		glm::vec2 force = glm::normalize(direction);
				//<scale the force with the force magnitude>
		body->ApplyForce(force * m_forceMagnitude);
	}
}
