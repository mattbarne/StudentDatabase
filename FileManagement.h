#pragma once
#include"Students.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

class FileManagement {
private:
	Students& students;
public:
	FileManagement(Students& students) : students(students) {}

	void makeFile();
};

