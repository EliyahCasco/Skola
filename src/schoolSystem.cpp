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
	std::cout << "Welcome to School system program\n" << "Do you want to login press 1.\n" << "Do you want to Create account press 2.\n" << "Quit press 3.\n";
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
		quit();
		break;
	default:
		
		break;

	}
    
	
}

void schoolSystem::createAccount()
{


	std::cout << "REGISTER\nWelcome do please register a username\n";
	std::string username = "";
	std::cin >> username; 

	for (auto i : usernames)
	{

		if (i == username)
		{
			std::cout << "The username you are trying to use already exists. Please try again\n"; 
			createAccount();

		} 

	}
	usernames.push_back(username);

	std::cout << "Please register a password\n";
	std::string password = "";
	std::cin >> password;

	usernames.push_back(password);

	std::cout << "Congratulations you made an account\nDo you want to\n1. Go to menyu\n2. Log in\n3. Quit\n";
	int accountCreateAnswer = 0;
	std::cin >> accountCreateAnswer;
	switch (accountCreateAnswer)
	{
	case 1:
		menu();
		break;
	case 2:
		login();
		break;
	case 3:
		quit();
		break;
	default:
		break;
	}



}

void schoolSystem::login()
{
	if (usernames.size() > 0)
	{
		std::cout << "Write your username\n";
		std::string loginName = "";
		std::cin >> loginName;

		for (auto i : usernames)
		{
			if (i == loginName)
			{
				std::cout << "Please write your password";
			}
			else
			{
				std::cout << "The username you're trying to use doesn't exist please try again\n";
				
			}
		}
	}
	else
	{
		std::cout << "There are no accounts registered please create one\n";
		createAccount();
	}

}

void schoolSystem::quit()
{
	std::cout << "Goodbye!";
	runSystem = false;
}
