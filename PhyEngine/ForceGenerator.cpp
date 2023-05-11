#include "ForceGenerator.h"
#include "body.h"


void ForceGenerator::Draw(Graphics* graphics)
{
	if (_body) _body->Draw(graphics);
}
