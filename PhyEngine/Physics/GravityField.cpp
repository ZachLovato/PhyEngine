#include "GravityField.h"
//#include "../Shape/Body.h"
#include "../Physics/Shape/Body.h"

void GravityField::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
	{
		body->ApplyForce({ 0, -_strength });
	}
}
