#include "CircleShape.h"
#include "../../Engine/Graphics.h"

void CircleShape::Draw(Graphics* graphics, glm::vec2 position)
{

	int r = graphics->WorldToPixels(radius);
	graphics->DrawFilledCircle(graphics->WorldToScreen(position), r, color);
}
