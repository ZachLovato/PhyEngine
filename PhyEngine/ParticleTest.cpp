#include "ParticleTest.h"
#include <iostream>
#include "CircleShape.h"

void ParticleTest::Initialize()
{
	Test::Initialize();
}

void ParticleTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = { randomf(-1, 1), randomf(-1,1) };
		glm::vec2 posModi = randomUnitCircle() * randomf(10, 20);
		glm::vec4 color = { random(255), random(255), random(255), random(255) };

		auto po = new PhysicsObject(
			new Body(m_input->GetMousePosition(),
				velocity), new CircleShape(randomf(10, 20), color));
		/*
		auto po = new PhysicsObject(
			new Body(posModi + m_input->GetMousePosition(),
				velocity), new CircleShape(randomf(10, 20), color));
				*/

		m_world->AddPhysicsObject(po);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->TimeDelta());
}

void ParticleTest::Render()
{
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);
}
