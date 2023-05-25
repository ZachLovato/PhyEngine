#include "CollisionTest.h"
#include "../Physics/Shape/Body.h"
#include "../Physics/Shape/CircleShape.h"
#include <iostream>

void CollisionTest::Initialize()
{
	Test::Initialize();

	m_user = new Body(new CircleShape(1, { 0, 0, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::KINEMATIC);
	m_world->AddBodyObject(m_user);

	//auto body = new Body(new CircleShape(200, glm::vec4{ 1.0f }), { 0, -207.5 }, { 0, 0 }, 1, Body::STATIC);
	//m_world->AddBodyObject(body);
}

void CollisionTest::Update()
{
	Test::Update();

	glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
	//std::cout << position.x << " " << position.y << std::endl;
	m_user->_velocity = position - m_user->_position;
	m_user->_position = position;

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(1, 3);
		float size = randomf(0.1f, 1.0f);

		

		auto body = new Body(new CircleShape(0.5f, { random(255), random(255), random(255), 1 }), {0,0}, {0,0}, 0.5f);
		body->_damping = 0;
		body->_gravityScale = 1;

		m_world->AddBodyObject(body);
	}
	//Test::Update();

	//glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
	////userBody->_velocity = position - userBody->_position;
	//userBody->_position = position;

	//if (m_input->GetMouseButton(0))
	//{
	//	glm::vec2 velocity = randomUnitCircle() * randomf(1, 3);
	//	float size = randomf(0.1f, 1.0f);

	//	auto body = new Body(new CircleShape(size, { random(255), random(255), random(255), 1 }), position, velocity, size);
	//	body->_damping = 0;
	//	body->_gravityScale = 1;

	//	m_world->AddBodyObject(body);
	//}
}

void CollisionTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void CollisionTest::Render()
{
	m_world->Draw(m_graphics);
}