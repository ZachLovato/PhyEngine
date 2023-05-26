#include "Tests/JointTest.h"
#include "Tests/ForceTest.h"
#include "Tests/ParticleTest.h"
#include "Tests/CollisionTest.h"


int main(int arg, char* args[])
{
	//Test* test = new CollisionTest();
	Test* test = new JointTest();

	test->Initialize();

	while (!test->IsQuit())
	{
		test->Run();
	}
	delete test;

	return 0;
}