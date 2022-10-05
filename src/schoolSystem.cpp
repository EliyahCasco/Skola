#include "schoolSystem.h"


void schoolSystem::run()
{
	int counter = 0;
	while (runSystem)
	{
		menu();
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
	std::string deletStudent = "";
	std::cout << "What is the name of the student you want to remove?\n";
	std::cin >> deletStudent;
	std::vector<student> newStudents;
	for (auto x : students)
	{
		if (x.name != deletStudent)
		{
			newStudents.push_back(x);
		}
		else {
			std::cout << "You removed " << x.name << "\n";
		}
	}
	students = newStudents;
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
					std::cout << "You are logged in!\n";
					studentMenu();
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
	std::string klassName = "";
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
		studentMenu();
		break;
	case 2:
		removeStudent();
		break;
	case 3:
		std::cout << "What is the namne of the class u want to add\n";
		std::cin >> klassName;
		addClass(klassName);
		studentMenu();
		break;
	case 4:
		addStudentToClass();
		break;
	case 5:

		break;
	case 6:
		info();
		break;
	case 7:
		quit();
		break;
	default:

		break;
	}

}

void schoolSystem::addClass(std::string klassNamn)
{
	student student;
	student.klass = klassNamn;
	students.push_back(student);
}

void schoolSystem::addStudentToClass()
{
	std::string studentName = "";
	std::string skolKlass = "";
	std::cout << "What is the name of the student?\n";
	std::cin >> studentName;
	std::cout << "What class does ur student go in?\n";
	std::cin >> skolKlass;

	for (auto& classes : schoolClasses)
	{
		if (classes != skolKlass)
		{
			std::cout << "No classes exist please try again!\n";
			studentMenu();
		}
	}

	for (auto& student : students)
	{
		if (student.name == studentName)student.klass = skolKlass;
	}
	studentMenu();
}

void schoolSystem::info()
{
	int infoAnswer = 0;
	std::cout << "What info do you want to know?\n1. All students\n2. All classes?\n3. Everything\n4. info about single student\n5. Info about a single class\n";
	std::cin >> infoAnswer;
	std::string answerStudent = "";
	switch (infoAnswer)
	{
	case 1:
		std::cout << "All students: \n";
		for (auto i : students)
		{
			std::cout << i.name << ", " << i.age << ", \n";
        }
		break;
    case 2:
		std::cout << "All classes\n";
		for (auto k : students)
		{
			std::cout << k.klass << ", \n";
		}
		break;
	case 3:
		std::cout << "all info\n";
		for (auto q : students)
		{
			std::cout << q.name << ", " << q.age << ", " << q.klass << ", \n";
		}
		break;
	case 4:
		std::cout << "What is the name of the student?\n";
		std::cin >> answerStudent;
		for (auto k : students)
		{
			if (answerStudent == k.name)
			{
				std::cout << "Age: " << k.age << ", Name: " << k.name << ", Class: " << k.klass << "\n";
			}
		}
		break;
	case 5:
		std::cout << "What is the name of the class?\n";
		std::cin >> answerStudent;
		std::cout << "THe person's in the class are: \n";
		for (auto k : students)
		{
			if (answerStudent == k.klass)
			{
				std::cout << k.name << ", ";
			}
		}
		std::cout << "\n";
		break;
		break;
	default:
		break;
	}
}

void schoolSystem::removeStudentFromClass()
{
	std::string deletStudent = "";
	std::cout << "What is the name of the student you want to remove?\n";
	std::cin >> deletStudent;
	std::vector<student> newStudents;
	student stud;
	for (auto x : students)
	{
		if (x.name != deletStudent)
		{
			newStudents.push_back(x);
		}
		else {
			stud = x;
			std::cout << "You removed " << x.name << " from the class:\n" << x.klass << "\n";
		}
	}
	students = newStudents;
	stud.klass = "";
	students.push_back(stud);

}
