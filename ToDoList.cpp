#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;

class Task {
public:
    string description;
    bool completed = false;

    Task() {}
    Task(string desc) : description(desc) {}
};

class ToDoList {
private:
    Task tasks[MAX_TASKS];
    int taskCount = 0;

public:
    void displayMenu() {
        cout << "\nTODO LIST MANAGER\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
    }

    void addTask() {
        if(taskCount == MAX_TASKS) {
            cout << "List is full!";
            return;
        }

        string desc;
        cout << "Enter task description: ";
        cin.ignore();
        getline(cin, desc);
        
        tasks[taskCount++] = Task(desc);
    }

    void viewTasks() {
        for(int i = 0; i < taskCount; i++) {
            cout << i + 1 << ". " << tasks[i].description;
            cout << (tasks[i].completed ? " (Completed)" : " (Pending)") << endl;
        }
    }

    void markCompleted() {
        int index;
        cout << "Enter task number to mark as completed: ";
        cin >> index;

        if(index > 0 && index <= taskCount) {
            tasks[index - 1].completed = true;
        } else {
            cout << "Invalid task number!";
        }
    }

    void removeTask() {
        int index;
        cout << "Enter task number to remove: ";
        cin >> index;

        if(index > 0 && index <= taskCount) {
            for(int i = index - 1; i < taskCount - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
        } else {
            cout << "Invalid task number!";
        }
    }
};

int main() {
    ToDoList list;
    int choice;

    do {
        list.displayMenu();
        cin >> choice;

        switch(choice) {
            case 1: list.addTask(); break;
            case 2: list.viewTasks(); break;
            case 3: list.markCompleted(); break;
            case 4: list.removeTask(); break;
            case 5: cout << "Exiting..."; break;
            default: cout << "Invalid option!"; break;
        }
    } while(choice != 5);

    return 0;
}
