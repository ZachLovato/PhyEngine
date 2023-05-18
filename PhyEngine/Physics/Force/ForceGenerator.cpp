#include "ForceGenerator.h"
#include "../Shape/Body.h"


void ForceGenerator::Draw(Graphics* graphics)
{
	if (_body) _body->Draw(graphics);
}
