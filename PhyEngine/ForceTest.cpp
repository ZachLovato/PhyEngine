#include "ForceTest.h"
#include <iostream>
#include "CircleShape.h"

void ForceTest::Initialize()
{
	Test::Initialize();

	World::_gravity = { 4, 9.81f };
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = { 0,0 };//{ randomf(-1, 1), randomf(-1,1) };
		glm::vec2 posModi = randomUnitCircle() * randomf(100, 200);
		glm::vec4 color = { random(255), random(255), random(255), random(255) };

		float size = randomf(10, 20);

		auto body = new Body(m_input->GetMousePosition(), velocity, randomf(1, 5));
		auto shape = new CircleShape(size, color);
		auto po = new PhysicsObject(body, shape);

		po->GetBody()->_damping = 3;
		po->GetBody()->_gravityScale = 30;

		m_world->AddPhysicsObject(po);
	}
}

void ForceTest::FixedUpdate()
{
	//m_world->Step(m_time->TimeDelta());
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Render()
{
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);
}
