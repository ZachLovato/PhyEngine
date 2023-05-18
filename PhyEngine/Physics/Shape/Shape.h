#pragma once
#include <glm/glm.hpp>

class Shape
{
public:
	Shape(){}
	Shape(const glm::vec4& color) : color{ color } {}

	virtual void Draw(class Graphics* graphics, glm::vec2 position) = 0;

	float size{ 1 };
	glm::vec4 color{ 1 , 1 , 1 , 1 };
private:

protected:

};