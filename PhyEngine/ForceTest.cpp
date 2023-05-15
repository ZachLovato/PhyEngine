#include "ForceTest.h"
#include "Body.h"
#include "CircleShape.h"
#include "GravityField.h"
#include "GravForce.h"

void ForceTest::Initialize()
{
	Test::Initialize();

	World::_gravity = { 0, 9.81f };

	auto ForceGen = new GravitationalForce(1300);
	m_world->AddForceGenerators(ForceGen);
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

		auto shape = new CircleShape(size, color);
		auto body = new Body(shape, m_input->GetMousePosition(), velocity, randomf(1, 5));

		body->_damping = 3;
		body->_gravityScale = 30;

		m_world->AddBodyObject(body);
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
