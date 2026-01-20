#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int roomNo;
    int days;
    float fee;
};

vector<Student> students;

// Add new student
void addStudent() {
    Student s;
    cout << "\nEnter Student ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Room Number: ";
    cin >> s.roomNo;
    cout << "Enter Number of Days Stayed: ";
    cin >> s.days;

    s.fee = s.days * 200; // hostel fee per day
    students.push_back(s);

    cout << "\nStudent added successfully!\n";
}

// Display all students
void viewStudents() {
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    for (auto s : students) {
        cout << "ID: " << s.id
             << "\nName: " << s.name
             << "\nRoom No: " << s.roomNo
             << "\nDays Stayed: " << s.days
             << "\nTotal Fee: " << s.fee
             << "\n----------------------\n";
    }
}

// Search student by ID
void searchStudent() {
    int id;
    cout << "\nEnter Student ID to search: ";
    cin >> id;

    for (auto s : students) {
        if (s.id == id) {
            cout << "\nStudent Found!\n";
            cout << "Name: " << s.name
                 << "\nRoom No: " << s.roomNo
                 << "\nDays Stayed: " << s.days
                 << "\nTotal Fee: " << s.fee << endl;
            return;
        }
    }
    cout << "\nStudent not found!\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n===== Hostel Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "\nExiting program...\n"; break;
            default: cout << "\nInvalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
