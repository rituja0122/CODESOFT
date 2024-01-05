#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void removeTask(std::vector<Task>& todoList, int taskNumber) {
    todoList.erase(todoList.begin() + taskNumber - 1);
}

int main() {
    std::vector<Task> todoList;
    bool running = true;

    while (running) {
        std::cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\nEnter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Task newTask;
                std::cin.ignore(); // To consume the newline character after the choice input
                std::cout << "Enter task description: ";
                std::getline(std::cin, newTask.description);
                newTask.completed = false;
                todoList.push_back(newTask);
                std::cout << "Task added!\n";
                break;
            }
            case 2: {
                if (todoList.empty()) {
                    std::cout << "No tasks in the list!\n";
                } else {
                    std::cout << "\nTasks:\n";
                    for (size_t i = 0; i < todoList.size(); ++i) {
                        std::cout << i + 1 << ". ";
                        if (todoList[i].completed) {
                            std::cout << "[Completed] ";
                        }
                        std::cout << todoList[i].description << std::endl;
                    }
                }
                break;
            }
            case 3: {
                if (todoList.empty()) {
                    std::cout << "No tasks in the list!\n";
                } else {
                    std::cout << "Enter the task number to mark as completed: ";
                    int taskNumber;
                    std::cin >> taskNumber;
                    if (taskNumber > 0 && taskNumber <= static_cast<int>(todoList.size())) {
                        todoList[taskNumber - 1].completed = true;
                        std::cout << "Task marked as completed!\n";
                    } else {
                        std::cout << "Invalid task number!\n";
                    }
                }
                break;
            }
            case 4: {
                if (todoList.empty()) {
                    std::cout << "No tasks in the list!\n";
                } else {
                    std::cout << "Enter the task number to remove: ";
                    int taskNumber;
                    std::cin >> taskNumber;
                    if (taskNumber > 0 && taskNumber <= static_cast<int>(todoList.size())) {
                        removeTask(todoList, taskNumber);
                        std::cout << "Task removed!\n";
                    } else {
                        std::cout << "Invalid task number!\n";
                    }
                }
                break;
            }
            case 5:
                std::cout << "Exiting the to-do list program...\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice! Please enter a valid option.\n";
        }
    }

    return 0;
}

