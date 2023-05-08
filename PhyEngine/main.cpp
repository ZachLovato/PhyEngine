#include "ParticleTest.h"

int main(int arg, char* args[])
{
	Test* test = new ParticleTest();

	test->Initialize();

	while (!test->IsQuit())
	{
		test->Run();
	}
	delete test;

	return 0;
}