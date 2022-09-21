#pragma once
#include "student.h"
#include <vector>
#include <iostream>

class schoolSystem
{
public:
	void run();
	void addStudent(std::string name, int age);
	void removeStudent(); 
	void menu();
	void createAccount();
	void login();
	void quit();
	void studentMenu();
	void addClass();
	void addStudentToClass();

	std::vector<student> students;
	std::vector<std::string> schoolClasses;

	std::vector<std::string> usernames;
	std::vector<std::string> passwords;




private:
	bool runSystem = true;
};
