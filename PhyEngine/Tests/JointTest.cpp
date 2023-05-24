#include "JointTest.h"
#include "../Physics/Joint.h"
#include "../Physics/Shape/CircleShape.h"
#include "../Physics/Shape/Body.h"
#include <iostream>

#define SPRING_STIFFENSS 100
#define SPRING_LENGTH 1
#define BODY_DAMPING 10
#define CHAIN_SIZE 4

#define GRID
#define GRID_WIDTH 3
#define GRID_HEIGHT 5

void JointTest::Initialize()
{
	Test::Initialize();

	_anchor = new Body(new CircleShape(1, { 1, 1, 1, 1 }), {0, 0 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBodyObject(_anchor);

	auto prevBody = _anchor;

#if defined(GRID)
	auto links = new Body*[2][GRID_HEIGHT];
	for (int t = 0; t < GRID_HEIGHT; t++)
	{
		links[0][t] = nullptr;
	}

	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			glm::vec4 color = { random(255) ,random(255) ,random(255) , 1 };
			if (i == 0 && j == 0 ) glm::vec4 color = {1 ,1 ,1 ,1 };
			
			glm::vec2 pos{ (3 * i), (3 * j)};

			auto body = new Body(new CircleShape(0.5f, color), pos, { 0, 0 }, 1, Body::DYNAMIC);
			body->_gravityScale = 2;
			body->_damping = BODY_DAMPING;
			m_world->AddBodyObject(body);
			links[1][j] = body;

			auto joint = new Joint(body, prevBody, SPRING_STIFFENSS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			if (links[0][j] != nullptr)
			{
				auto sJoint = new Joint(body, links[0][j], SPRING_STIFFENSS, SPRING_LENGTH);
				m_world->AddJoint(sJoint);

				if (j > 0)
				{
					auto diaJoint = new Joint(body, links[0][j - 1], SPRING_STIFFENSS, SPRING_LENGTH * 2);
					m_world->AddJoint(diaJoint);
				}
				if (j < GRID_HEIGHT)
				{
					auto diaJoint = new Joint(body, links[0][j + 1], SPRING_STIFFENSS, SPRING_LENGTH * 2);
					m_world->AddJoint(diaJoint);
				}
			}
			

			
			prevBody = body;
		}

		// sets first row as the prev bodies
		for (int t = 0; t < GRID_HEIGHT; t++)
		{
			links[0][t] = links[1][t];
		}

		prevBody = _anchor;
	}
#else
	// Chain
	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		glm::vec4 color = { random(255) ,random(255) ,random(255) , 1};

		auto body = new Body(new CircleShape(0.5f, color), { -10, -2 * i }, { 0, 0 }, 1, Body::DYNAMIC);
		//body->_gravityScale = 150;
		body->_damping = BODY_DAMPING;
		m_world->AddBodyObject(body);

		auto joint = new Joint(body, prevBody, SPRING_STIFFENSS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody = body;
	}
#endif
}


void JointTest::Update()
{
	Test::Update();
	{
		//_anchor->_position = { 400, 100 };
		_anchor->_position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
	}
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
