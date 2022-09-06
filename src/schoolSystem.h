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




	std::vector<student> students;
	std::vector<std::string> schoolClasses;



private:
	bool runSystem = true;
};
