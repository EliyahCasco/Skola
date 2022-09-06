#pragma once
#include "student.h"
#include <vector>
#include <iostream>

class schoolSystem
{
public:
	void run();
	void addStudent();
	void removeStudent();


	std::vector<student> students;
	std::vector<std::string> schoolClasses;



private:

};
