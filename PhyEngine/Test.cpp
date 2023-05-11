#include "Test.h"
#include <iostream>

Test::Test()
{
	//
}

Test::~Test()
{
	if (m_world) delete m_world;
	if (m_time) delete m_time;
	if (m_input) delete m_input;
	if (m_graphics) delete m_graphics;
}

void Test::Initialize()
{
	m_graphics = new Graphics();
	m_graphics->CreateWindow("Physics", 800, 600);
	m_input = new Input();
	m_time = new Time();
	m_world = new World();
	m_time->SetFixedDeltaTime( 1.0f / 60 );
}

void Test::Run()
{
	Update();

	//while loop
	// gotta fix the while loop, while it look right something is making this run slow
	// ad move fixed update into the while loop
	m_fixedTime += m_time->TimeDelta();
		FixedUpdate();
	while (m_fixedTime > m_time->GetFixedDeltaTime())
	{
		//std::cout << m_fixedTime << std::endl;
		//std::cout << m_time->GetFixedDeltaTime() << std::endl;
		m_fixedTime -= m_time->GetFixedDeltaTime();
	}

	// Render
	PreRender();
	Render();
	PostRender();
}

void Test::Update()
{
	UpdateEvents();

	m_input->Update();
	m_time->Update();
}

void Test::PreRender()
{
	m_graphics->SetColor({ 0, 255, 0, 255 });
	m_graphics->Clear();
}

void Test::PostRender()
{
	m_graphics->Present();
}

void Test::UpdateEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_quit = true;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			m_quit = true;
		}
	}
}
