#include "Students.h"

Students::Students() : head(nullptr) {}

bool Students::isDuplicate(string firstName, string lastName) {
	Node* current = head;

	// Traverse the list to find duplicates
	while (current != nullptr) {
		if (current->student.firstName == firstName && current->student.lastName == lastName) {
			return true;
		}
		current = current->next;
	}

	return false;
}

void Students::addStudentsFromFile() {
	ifstream file("StudentData.txt");
	string fileText;

	// Checks for file with data
	if (file.is_open()) {
		cout << "Existing student data found.\n" << endl;
		while (getline(file, fileText)) {
			istringstream ss(fileText);
			string firstName, lastName;
			double gpa;

			ss >> firstName >> lastName >> gpa;
			
			if (isDuplicate(firstName, lastName)) {
				return;
			}
			addStudent(firstName, lastName, gpa);
		}
	}
	else {
		cout << "No existing student data.\n" << endl;
		return;
	}
	file.close();
}

void Students::addStudent(string firstName, string lastName, double gpa) {
	Node* newStudent = new Node(firstName, lastName, gpa);

	// Check for duplicate students
	if (isDuplicate(firstName, lastName)) {
		delete newStudent;
		return;
	}

	// If nothing in list
	if (head == nullptr) {
		head = newStudent;
	}	// If so append to end
	else {
		Node* current = head;

		while (current->next != nullptr) {
			current = current->next;
		}

		current->next = newStudent;
	}
}

Student* Students::searchStudent(string firstName, string lastName) {
	Node* current = head;

	while (current != nullptr) {
		// Check in linked list for student
		if (current->student.firstName == firstName && current->student.lastName == lastName) {
			cout << "\nStudent found: " << current->student.firstName
				<< " " << current->student.lastName << " GPA: "
				<< fixed << setprecision(1) << current->student.gpa << endl;
			return &current->student;
		}
		current = current->next;
	}
	cout << "\nNo student found." << endl;
}

void Students::printStudents() {
	Node* current = head;

	// Iterate list for all student information
	while (current != nullptr) {
		cout << current->student.firstName
			<< " " << current->student.lastName << " GPA:"
			<< " " << fixed << setprecision(1) <<  current->student.gpa << endl;
		current = current->next;
	}
}
