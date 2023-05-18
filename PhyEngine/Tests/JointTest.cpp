#include "JointTest.h"
#include "../Physics/Joint.h"
#include "../Physics/Shape/CircleShape.h"
#include "../Physics/Shape/Body.h"

#define SPRING_STIFFENSS 250
#define SPRING_LENGTH 50
#define BODY_DAMPING 10
#define CHAIN_SIZE 3

void JointTest::Initialize()
{
	Test::Initialize();

	_anchor = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 100 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBodyObject(_anchor);

	auto prevBody = _anchor;

	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		auto body = new Body(new CircleShape(20, { 0.5f, 0.5f, 0.5f, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
		body->_gravityScale = 2;
		body->_damping = BODY_DAMPING;
		m_world->AddBodyObject(body);

		auto joint = new Joint(body, prevBody, SPRING_STIFFENSS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody = body;

		body = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
		body->_gravityScale = 2;
		body->_damping = BODY_DAMPING;
		m_world->AddBodyObject(body);

		joint = new Joint(body, prevBody, SPRING_STIFFENSS, SPRING_LENGTH);
		m_world->AddJoint(joint);

	}


}

void JointTest::Update()
{
	Test::Update();
	_anchor->_position = m_input->GetMousePosition();
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}
