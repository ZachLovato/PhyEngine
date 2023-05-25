#include "Tests/JointTest.h"
#include "Tests/CollisionTest.h"


int main(int arg, char* args[])
{
	Test* test = new CollisionTest();

	test->Initialize();

	while (!test->IsQuit())
	{
		test->Run();
	}
	delete test;

	return 0;
}