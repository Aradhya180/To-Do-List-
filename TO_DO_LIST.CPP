#include <iostream>
#include <vector>

struct Task
{
    std::string description;
    bool completed;
};

// Function to add a task to the list
void addTask(std::vector<Task> &tasks, const std::string &description)
{
    Task task;
    task.description = description;
    task.completed = false;
    tasks.push_back(task);
}

// Function to view the list of tasks
void viewTasks(const std::vector<Task> &tasks)
{
    if (tasks.empty())
    {
        std::cout << "No tasks in the list." << std::endl;
    }
    else
    {
        std::cout << "Task List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); i++)
        {
            const Task &task = tasks[i];
            std::cout << (i + 1) << ". " << task.description << " - " << (task.completed ? "Completed" : "Pending") << std::endl;
        }
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(std::vector<Task> &tasks, int taskIndex)
{
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size()))
    {
        tasks[taskIndex - 1].completed = true;
        std::cout << "Task marked as completed." << std::endl;
    }
    else
    {
        std::cout << "Invalid task index." << std::endl;
    }
}

// Function to remove a task from the list
void removeTask(std::vector<Task> &tasks, int taskIndex)
{
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size()))
    {
        tasks.erase(tasks.begin() + taskIndex - 1);
        std::cout << "Task removed from the list." << std::endl;
    }
    else
    {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main()
{
    std::vector<Task> tasks;

    while (true)
    {
        std::cout << "Todo List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter the task description: ";
            std::string description;
            std::cin.ignore();
            std::getline(std::cin, description);
            addTask(tasks, description);
            break;
        }

        case 2:
            viewTasks(tasks);
            break;

        case 3:
            std::cout << "Enter the task index to mark as completed: ";
            int taskIndexToMark;
            std::cin >> taskIndexToMark;
            markTaskAsCompleted(tasks, taskIndexToMark);
            break;

        case 4:
            std::cout << "Enter the task index to remove: ";
            int taskIndexToRemove;
            std::cin >> taskIndexToRemove;
            removeTask(tasks, taskIndexToRemove);
            break;

        case 5:
            return 0;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
