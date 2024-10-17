#include "FileManagement.h"
#include"Students.h"

void FileManagement::makeFile() {
	Node* current = students.getHead();
	stringstream tempText;

	// Check for file
	ifstream presentStudentData("StudentData.txt");

	// If no file create a new one and append all data
	if (!presentStudentData.is_open()) {
		ofstream newStudentData("StudentData.txt");

		while (current != nullptr) {
			tempText << current->student.firstName
				<< " " << current->student.lastName
				<< fixed << setprecision(1) << " " << current->student.gpa << "\n";
			current = current->next;
		}
		newStudentData << tempText.str();
		newStudentData.close();
	}
	else {  // Append to file if their is one
		ofstream appendStudentData("StudentData.txt", ios::app);

		while (current != nullptr) {
			tempText << current->student.firstName
				<< " " << current->student.lastName
				<< fixed << setprecision(1) << " " << current->student.gpa << "\n";
			current = current->next;
		}
		appendStudentData << tempText.str();
		appendStudentData.close();
	}
}
