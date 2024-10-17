#include "Students.h"
#include "FileManagement.h"

using namespace std;

int main() {
	Students studentApp;
	FileManagement fileManager(studentApp);

	string firstName, lastName;
	double gpa;
	int menuOption;
	bool firstLoop = false;
	bool exit = false;
	
	do {
		if (!firstLoop) {
			studentApp.addStudentsFromFile();
			firstLoop = true;
		}

		cout << "Select Menu Option:" << endl;
		cout << "1: Add Student" << endl;
		cout << "2: Search Student" << endl;
		cout << "3: List all Students" << endl;
		cout << "4: Exit & Save File" << endl;
		
		cin >> menuOption;

		switch (menuOption) {
			case 1:
				cout << "\nEnter first name: " << endl;
				cin >> firstName;
				cout << "Enter last name: " << endl;
				cin >> lastName;
				cout << "Enter GPA: " << endl;
				cin >> gpa;

				studentApp.addStudent(firstName, lastName, gpa);
				cout << "\nStudent added successfully." << endl;
				break;
			case 2:
				cout << "\nEnter first name: " << endl;
				cin >> firstName;
				cout << "Enter last name: " << endl;
				cin >> lastName;
				cout << "Searching....." << endl;

				studentApp.searchStudent(firstName, lastName);
				break;

			case 3:
				cout << "\nPrinting all students....." << endl;
				studentApp.printStudents();
				break;
			case 4:
				cout << "\nExiting program and saving....." << endl;
				fileManager.makeFile();
				exit = true;
				break;
			default:
				cout << "\nInvalid option! Please select a valid menu option." << endl;
				break;
		}
		cout << endl;
	} while (!exit);
	return 0;
}