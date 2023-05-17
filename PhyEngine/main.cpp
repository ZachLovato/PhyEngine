#include "ParticleTest.h"
#include "ForceTest.h"



int main(int arg, char* args[])
{
	Test* test = new ForceTest();

	test->Initialize();

	while (!test->IsQuit())
	{
		test->Run();
	}
	delete test;

	return 0;
}