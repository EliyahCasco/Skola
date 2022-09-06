#include "schoolSystem.h"

void schoolSystem::run()
{
	int counter = 0;
	while (true)
	{
		std::cout << "Loop: " << counter << "\n";
		counter++;
		std::cin.get();
	}
}

void schoolSystem::addStudent()
{
	student student;
	student.name = "blacka";
	student.age = 123;
	students.push_back(student);
}

void schoolSystem::removeStudent()
{
}
