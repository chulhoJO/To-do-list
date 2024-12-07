// This program implements a simple to-do list application with support for task priority and repeat intervals.
// The user can add tasks, display tasks, and exit the program. Tasks are sorted by priority before being displayed.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100 // Maximum number of tasks
#define MAX_TASK_LENGTH 100 // Maximum length of a task description

// Task structure to store task details
typedef struct {
    char description[MAX_TASK_LENGTH]; // Task description
    int priority; // Task priority (1-5)
    int repeat; // Repeat interval in days (0 for no repeat)
} Task;

// Function prototypes
void addTask(Task tasks[], int *taskCount); // Adds a new task to the list
void displayTasks(Task tasks[], int taskCount); // Displays all tasks
void sortTasksByPriority(Task tasks[], int taskCount); // Sorts tasks by priority

int main() {
    Task tasks[MAX_TASKS]; // Array to store tasks
    int taskCount = 0; // Number of tasks
    int choice; // User's menu choice

    while (1) {
        // Display menu
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle menu choice
        switch (choice) {
            case 1:
                addTask(tasks, &taskCount); // Add a new task
                break;
            case 2:
                sortTasksByPriority(tasks, taskCount); // Sort tasks by priority
                displayTasks(tasks, taskCount); // Display tasks
                break;
            case 3:
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Adds a new task to the list
void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    // Get task details from user
    printf("Enter task description: ");
    getchar(); // Consume newline character left by previous input
    fgets(tasks[*taskCount].description, MAX_TASK_LENGTH, stdin);
    tasks[*taskCount].description[strcspn(tasks[*taskCount].description, "\n")] = 0; // Remove newline character

    printf("Enter task priority (1-5): ");
    scanf("%d", &tasks[*taskCount].priority);

    printf("Enter repeat interval in days (0 for no repeat): ");
    scanf("%d", &tasks[*taskCount].repeat);

    (*taskCount)++; // Increment task count
}

// Displays all tasks
void displayTasks(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }

    // Display each task
    printf("\nTo-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task %d: %s\n", i + 1, tasks[i].description);
        printf("Priority: %d\n", tasks[i].priority);
        printf("Repeat Interval: %d days\n", tasks[i].repeat);
    }
}

// Sorts tasks by priority in ascending order
void sortTasksByPriority(Task tasks[], int taskCount) {
    Task temp;
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = i + 1; j < taskCount; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}