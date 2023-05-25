#include "ForceTest.h"
#include "../Physics/Shape/Shape.h"
#include "../Physics/Shape/CircleShape.h"
#include "../Physics/GravityField.h"
#include "../Physics/Force/GravForce.h"
#include <iostream>
#include "../Physics/Force/PointForce.h"
#include "../Physics/Force/AreaForce.h"
#include "../Physics/Force/DragForce.h"

#define POINT_FORCE
//#define AREA_FORCE
//#define DRAG_FORCE

void ForceTest::Initialize()
{
	Test::Initialize();

	World::_gravity = { 0, 0 };

#if defined(POINT_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 1 }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC)
		;
	ForceGenerator* forceGenerator = new PointForce(body, 20);
	m_world->AddForceGenerators(forceGenerator);
#elif defined(AREA_FORCE)
	auto body = new Body(new CircleShape(200, { 0.5f, 0.5f, 0.5f, 0.5f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC)
		;
	ForceGenerator* forceGenerator = new AreaForce(body, 20, -45);
	m_world->AddForceGenerators(forceGenerator);
#elif defined(DRAG_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC)
		;
	ForceGenerator* forceGenerator = new DragForce(body, 0.5f);
	m_world->AddForceGenerators(forceGenerator);
#endif

	//auto ForceGen = new GravitationalForce(1300);
	//m_world->AddForceGenerators(ForceGen);
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		//glm::vec2 velocity = { 0,0 };
		glm::vec2 velocity{ randomf(-1, 1), randomf(-1,1) };
		glm::vec2 posModi = randomUnitCircle() * randomf(100, 200);
		glm::vec4 color = { random(255), random(255), random(255), random(255) };

		float size = randomf(10, 20);

		auto shape = new CircleShape(size, color);
		glm::vec2 pos = m_graphics->ScreenToWorld(m_input->GetMousePosition());
		auto body = new Body(shape, pos, velocity, randomf(1, 5));

		body->_damping = 3;
		body->_gravityScale = 30;

		m_world->AddBodyObject(body);
	}
}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Render()
{
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);
}
