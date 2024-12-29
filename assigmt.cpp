#include <iostream>
#include <vector>
using namespace std;

// Class for Student
class Student {
private:
    string name;
    int rollNumber;
    float marks;
    int age;
    string programme;

public:
    // Constructor to initialize student details
    Student(string n, int r, float m) : name(n), rollNumber(r), marks(m),int a, string p,{}

    // Function to display student details
    void displayStudentDetails() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "age:" << age<< endl;
        cout << "programme:" << programme << endl;
    }

    // Getter for roll number
    int getRollNumber() {
        return rollNumber;
    }
};

// Class for School Management
class SchoolManagement {
private:
    vector<Student> students;

public:
    // Function to add a student
    void addStudent(string name, int rollNumber, float marks) {
        Student student(name, rollNumber, marks);
        students.push_back(student);
    }

    // Function to display all students
    void displayAllStudents() {
        if (students.empty()) {
            cout << "No students to display!" << endl;
        } else {
            for (auto &student : students) {
                student.displayStudentDetails();
            }
        }
    }

    // Function to find a student by roll number
    void findStudent(int rollNumber) {
        bool found = false;
        for (auto &student : students) {
            if (student.getRollNumber() == rollNumber) {
                student.displayStudentDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with Roll Number " << rollNumber << " not found!" << endl;
        }
    }
};

int main() {
    SchoolManagement school;
    int choice;

    do {
        cout << "==== School Management System ====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Find Student by Roll Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cout << "Enter your age:";
        cout << "Enter your programme:";
        cin >> choice;

        if (choice == 1) {
            string name;
            int rollNumber;
            float marks;

            cout << "Enter student name: ";
            cin.ignore(); // To ignore the newline character left by the previous input
            getline(cin, name);

            cout << "Enter roll number: ";
            cin >> rollNumber;

            cout << "Enter marks: ";
            cin >> marks;

            school.addStudent(name, rollNumber, marks);
        }
        else if (choice == 2) {
            school.displayAllStudents();
        }
        else if (choice == 3) {
            int rollNumber;
            cout << "Enter roll number to search: ";
            cin >> rollNumber;
            school.findStudent(rollNumber);
        }
        else if (choice == 4) {
            cout << "Exiting the system." << endl;
        }
        else {
            cout << "Invalid choice. Please try again!" << endl;
        }

    } while (choice != 4);

    return 0;
}
