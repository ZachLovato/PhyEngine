#include "Collision.h"
#include "../Shape/CircleShape.h"
#include "../../Engine/Random.h"

namespace Collision
{
	void CreateContacts(std::vector<Body*>& bodies, std::vector<Contact>& contacts)
	{
		for (size_t i = 0; i < bodies.size() - 1; i++)
		{
			for (size_t j = i + 1; j < bodies.size(); j++)
			{
				Body* bodyA = bodies[i];
				Body* bodyB = bodies[j];

				// contact needs at least one dynamic body
				if (bodyA->_type != Body::DYNAMIC && bodyB->_type != Body::DYNAMIC) continue;

				// check for intersection between bodies
				if (bodyA->Intersects(bodyB))
				{
					// create contact
					Contact contact = Collision::GenerateContact(bodyA, bodyB);
					contacts.push_back(contact);
				}
			}
		}
	}

	Contact GenerateContact(Body* bodyA, Body* bodyB)
	{
		Contact contact;

		contact.bodyA = bodyA;
		contact.bodyB = bodyB;

		glm::vec2 direction = bodyA->_position - bodyB->_position;
		float distance = glm::length(direction);
		if (distance == 0)
		{
			direction = { randomf(-0.5f, 0.5f), randomf(-0.5f, 0.5f) };
		}

		float radius = ((CircleShape*)bodyA->_shape)->radius + ((CircleShape*)bodyB->_shape)->radius;
		contact.depth = radius - distance;

		contact.normal = glm::normalize(direction);

		contact.restitution = (bodyA->restitution + bodyB->restitution) * 0.5f;

		return contact;
	}

	void SeparateContacts(std::vector<Contact>& contacts)
	{
		for (auto& contact : contacts)
		{
			float totalInvMass = contact.bodyA->_invMass + contact.bodyB->_invMass;
			glm::vec2 seperation = contact.normal * (contact.depth / totalInvMass);

			contact.bodyA->_position += seperation * contact.bodyA->_invMass;
			contact.bodyB->_position -= seperation * contact.bodyB->_invMass;
		}
	}
	void ResolveContacts(std::vector<Contact>& contacts)
	{
		for (auto& contact : contacts)
		{
			glm::vec2 relativeVelocity = contact.bodyA->_velocity - contact.bodyB->_velocity;
			float normalVelocity = glm::dot(relativeVelocity, contact.normal);

			if (normalVelocity > 0) continue;

			float totalInvMass = contact.bodyA->_invMass + contact.bodyB->_invMass;
			float impulseManitude = -(1.0f + contact.restitution) * normalVelocity / totalInvMass;

			glm::vec2 impulse = contact.normal * impulseManitude;
			contact.bodyA->_velocity += (impulse * contact.bodyA->_invMass);
			contact.bodyB->_velocity -= (impulse * contact.bodyB->_invMass);

		}
	}
}