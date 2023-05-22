#pragma once
#include "Shape.h"

class CircleShape : public Shape
{
public:
	CircleShape(float radius) : radius{ radius } {}
	CircleShape(float radius, const glm::ivec4& color) : 
		radius{ radius }, Shape{ color } {}

	virtual void Draw(Graphics* graphics, glm::vec2 position) override;

	float radius{ 1 };

};