#include "schoolSystem.h"


void schoolSystem::run()
{
	int counter = 0;
	while (runSystem)
	{
		//menu();
		studentMenu();
		std::cout << "Loop: " << counter << "\n";
		counter++;
		if (!runSystem) break;
		std::cin.get();
	}
}

void schoolSystem::addStudent(std::string name, int age)
{
	student student;
	student.name = name;
	student.age = age;
	students.push_back(student);
}

void schoolSystem::removeStudent()
{
	std::string studentDelete = "";
	std::cout << "Write in the name of the student you want to remove\n";
	std::cin >> studentDelete;
	if (students.size() == 0) 
	{
		std::cout << "There are no students to remove please try again";
		studentMenu();
	}

	for (size_t i = 0; i < students.size(); i++) 
	{
		for (auto x : students) 
		{
			if (x.name == studentDelete) 
			{
				students.erase(std::begin(students) + i);
				std::cout << "Removed student " << x.name << "\nList of students:\n ";
				for (auto k : students) {
					std::cout << k.name << ", ";
				}
			}
			else
			{
				std::cout << "The name you are trying to remove doesn't exist";
			}
		}
	}

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

	passwords.push_back(password);

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
		std::string loginPass = " ";
		std::cin >> loginName;

		for (size_t i = 0; i < usernames.size(); i++)
		{
			if (usernames[i] == loginName)
			{
				std::cout << "Please write your password\n";
				std::cin >> loginPass;
				if (passwords[i] == loginPass)
				{
					std::cout << "You are logged in!";
					
				}
				else
				{
					std::cout << "The password is incorect please try again\n";
					login();
				}
			}
			else
			{
				std::cout << "The username you're trying to use doesn't exist please try again\n";
				login();
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

void schoolSystem::studentMenu()
{
	int studentAnswer = 0;
	int studentAge = 0;
	std::string studentName = "";
	std::cout << "HELLAW AND WELCOME TO STUDENT THING THING\n";
	std::cout << "Do you want to\n1 Add student\n2 remove student\n3 Add class\n4 Add student to class\n5 remove student from class\n6 info about classes\n7 quit.\n";
	std::cin >> studentAnswer;
	switch (studentAnswer)
	{
	case 1:
		std::cout << "what is the name of the student?\n";
		std::cin >> studentName;
		std::cout << "What is the age of your student\n";
		std::cin >> studentAge;
		addStudent(studentName, studentAge);
		break;
	case 2:
		removeStudent();
		break;
	case 3:
		
		break;
	default:

		break;
	}

}

void schoolSystem::addClass()
{
}

void schoolSystem::addStudentToClass()
{
}
