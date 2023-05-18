#include "Tests/JointTest.h"


int main(int arg, char* args[])
{
	Test* test = new JointTest();

	test->Initialize();

	while (!test->IsQuit())
	{
		test->Run();
	}
	delete test;

	return 0;
}