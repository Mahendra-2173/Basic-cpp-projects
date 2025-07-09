#include <iostream>
using namespace std;

const int MAX = 100;
string tasks[MAX];
int taskCount = 0;

void addTask(string task) {
    if (taskCount < MAX) {
        tasks[taskCount++] = task;
        cout << "Task added.\n";
    } else {
        cout << "Task list full.\n";
    }
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks.\n";
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask(int index) {
    if (index < 1 || index > taskCount) {
        cout << "Invalid task number.\n";
        return;
    }
    for (int i = index - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    cout << "Task deleted.\n";
}

int main() {
    int choice;
    string task;
    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                addTask(task);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                int delIndex;
                cout << "Enter task number to delete: ";
                cin >> delIndex;
                deleteTask(delIndex);
                break;
        }
    } while (choice != 4);
    return 0;
}
