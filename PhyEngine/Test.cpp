#include "Test.h"

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
}

void Test::Run()
{
	UpdateEvents();

	m_input->Update();
	m_time->Update();


	m_graphics->SetColor({ 10, 120, 160, 255 });
	m_graphics->Clear();
	
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, {randomf(), randomf(), randomf(), 1});
	m_graphics->DrawFilledCircle(m_input->GetMousePosition(), 10, {randomf(), randomf(), randomf(), 1});
	
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
