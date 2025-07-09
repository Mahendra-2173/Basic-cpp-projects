#include <iostream>
using namespace std;

struct Student {
    string name;
    int roll;
    float marks;
    Student* next;
};

Student* head = nullptr;

void addStudent(string name, int roll, float marks) {
    Student* newNode = new Student{name, roll, marks, nullptr};
    newNode->next = head;
    head = newNode;
}

void displayStudents() {
    Student* temp = head;
    if (!temp) {
        cout << "No records found.\n";
        return;
    }
    while (temp) {
        cout << "Name: " << temp->name << ", Roll: " << temp->roll << ", Marks: " << temp->marks << endl;
        temp = temp->next;
    }
}

void deleteStudent(int roll) {
    Student *temp = head, *prev = nullptr;
    while (temp && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Student not found.\n";
        return;
    }
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    delete temp;
    cout << "Student deleted.\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. View Students\n3. Delete Student\n4. Exit\nChoose: ";
        cin >> choice;
        if (choice == 1) {
            string name;
            int roll;
            float marks;
            cout << "Enter name, roll, marks: ";
            cin >> ws;
            getline(cin, name);
            cin >> roll >> marks;
            addStudent(name, roll, marks);
        } else if (choice == 2) {
            displayStudents();
        } else if (choice == 3) {
            int roll;
            cout << "Enter roll number to delete: ";
            cin >> roll;
            deleteStudent(roll);
        }
    } while (choice != 4);
    return 0;
}
