#include "schoolSystem.h"


void schoolSystem::run()
{
	


	int counter = 0;
	while (runSystem)
	{
		menu();

		std::cout << "Loop: " << counter << "\n";
		counter++;
		if (!runSystem) break;
		std::cin.get();
	}

}

void schoolSystem::addStudent(std::string name, int age)
{
	student student;
	student.name = "name";
	student.age = age;
	students.push_back(student);
}

void schoolSystem::removeStudent()
{
}

void schoolSystem::menu()
{
	int answer = 0;
	std::cout << "Welcome to School system program\n" << "Do you want to login press 1.\n" << "Do you want to Create account press 2.\n" << "Quit press 3.";
	std::cin >> answer;

	switch (answer) 
	{
	case 1:
		login();
		break;
	case 2:
		createAccount();
		break;
	case 3:
		std::cout << "Goodbye!";
		runSystem = false;
		break;
	default:
		
		break;

	}
    
	
}

void schoolSystem::createAccount()
{

}

void schoolSystem::login()
{
}
