#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> tasks;
    vector<bool> done;
    int choice;

    while (true) {
        cout << "\n=== To-Do List ===\n";
        cout << "1. Add task\n";
        cout << "2. Show tasks\n";
        cout << "3. Mark task done\n";
        cout << "4. Remove task\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            string task;
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, task);
            tasks.push_back(task);
            done.push_back(false);
            cout << "Task added.\n";
        } else if (choice == 2) {
            if (tasks.empty()) {
                cout << "No tasks.\n";
            } else {
                for (size_t i = 0; i < tasks.size(); ++i) {
                    cout << i + 1 << ". " << tasks[i]
                         << (done[i] ? " [done]" : " [pending]") << "\n";
                }
            }
        } else if (choice == 3) {
            int index;
            cout << "Enter task number to mark done: ";
            cin >> index;
            if (index > 0 && index <= (int)tasks.size()) {
                done[index - 1] = true;
                cout << "Task marked done.\n";
            } else {
                cout << "Invalid task number.\n";
            }
        } else if (choice == 4) {
            int index;
            cout << "Enter task number to remove: ";
            cin >> index;
            if (index > 0 && index <= (int)tasks.size()) {
                tasks.erase(tasks.begin() + index - 1);
                done.erase(done.begin() + index - 1);
                cout << "Task removed.\n";
            } else {
                cout << "Invalid task number.\n";
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
