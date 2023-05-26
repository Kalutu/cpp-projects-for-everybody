#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> todoList;

void displayMenu() {
    cout << "=== To-Do List ===" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Mark Task as Completed" << endl;
    cout << "3. Display List" << endl;
    cout << "4. Quit" << endl;
    cout << "==================" << endl;
    cout << "Enter your choice: ";
}

void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    todoList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void markTaskAsCompleted() {
    int index;
    cout << "Enter the index of the task to mark as completed: ";
    cin >> index;
    if (index >= 0 && index < todoList.size()) {
        todoList[index].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void displayList() {
    cout << "=== To-Do List ===" << endl;
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << "[" << i << "] ";
        if (todoList[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << todoList[i].description << endl;
    }
    cout << "==================" << endl;
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                markTaskAsCompleted();
                break;
            case 3:
                displayList();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

