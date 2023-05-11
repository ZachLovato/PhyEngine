#include "GravityField.h"
#include "Body.h"

void GravityField::Apply(std::list<class Body*> bodies)
{
	for (auto body : bodies)
	{
		body->ApplyForce({ 0, -_strength });
	}
}
