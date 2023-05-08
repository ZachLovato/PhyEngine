#include "Graphics.h"
#include <include/SDL.h>
#include "Primitives.h"

Graphics::Graphics()
{
	SDL_Init(SDL_INIT_VIDEO);
}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Graphics::CreateWindow(const char* title,int x, int y)
{
	_window = SDL_CreateWindow
	(
		title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		x,
		y,
		SDL_WINDOW_SHOWN
	);

	_renderer = SDL_CreateRenderer(_window, -1, 0);
}

void Graphics::Clear()
{
	SDL_RenderClear(_renderer);
}

void Graphics::Present()
{
	SDL_RenderPresent(_renderer);
}

void Graphics::SetColor(const glm::vec4& color)
{
	glm::ivec4 icolor;
	icolor.r = (int)(color.r * 255);
	icolor.g = (int)(color.g * 255);
	icolor.b = (int)(color.b * 255);
	icolor.a = (int)(color.a * 255);
	SDL_SetRenderDrawColor(_renderer, icolor.r, icolor.g, icolor.b, icolor.a);
}

glm::ivec4 Graphics::ConvertColor(const glm::vec4& color)
{
	glm::ivec4 icolor;
	icolor.r = (int)(color.r * 255);
	icolor.g = (int)(color.g * 255);
	icolor.b = (int)(color.b * 255);
	icolor.a = (int)(color.a * 255);
	return icolor;
}

void Graphics::DrawPoint(const glm::ivec2& point,const glm::vec4& color)
{
	SetColor(color);
	SDL_RenderDrawPoint(_renderer, point.x, point.y);

}

void Graphics::DrawLine(const glm::ivec2& start, const glm::ivec2& end, const glm::vec4& color)
{
	SetColor(color);
	SDL_RenderDrawLine(_renderer, start.x, start.y, end.x, end.y);
}

void Graphics::DrawCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
{
	glm::ivec4 icolor = ConvertColor(color);
	circleRGBA(_renderer, point.x, point.y, radius, icolor.r, icolor.g, icolor.b, icolor.a);
}

void Graphics::DrawFilledCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
{
	glm::ivec4 icolor = ConvertColor(color);
	filledCircleRGBA(_renderer, point.x, point.y, radius, icolor.r, icolor.g, icolor.b, icolor.a);
}
