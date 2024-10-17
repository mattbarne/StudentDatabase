#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>

using namespace std;

struct Student {
	string firstName;
	string lastName;
	double gpa;
};

struct Node {
	Student student;
	Node* next;

	Node(string firstName, string lastName, double gpa) {
		student.firstName = firstName;
		student.lastName = lastName;
		student.gpa = gpa;
		next = nullptr;
	}
};

class Students {
private:
	Node* head;

public:
	Students();

	bool isDuplicate(string firstName, string lastName);

	void addStudentsFromFile();

	void addStudent(string firstName, string lastName, double gpa);

	Student* searchStudent(string firstName, string lastName);

	void printStudents();

	Node* getHead() const {
		return head;
	}
};

