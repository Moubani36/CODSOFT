#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 100

typedef struct {
    char task[TASK_LENGTH];
    int completed;
} ToDo;

ToDo toDoList[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter the task: ");
        getchar(); // to consume the newline character left by previous input
        fgets(toDoList[taskCount].task, TASK_LENGTH, stdin);
        toDoList[taskCount].task[strcspn(toDoList[taskCount].task, "\n")] = 0; // remove newline character
        toDoList[taskCount].completed = 0;
        taskCount++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full!\n");
    }
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
    } else {
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s [%s]\n", i + 1, toDoList[i].task, toDoList[i].completed ? "Completed" : "Incomplete");
        }
    }
}

void markComplete() {
    int taskNumber;
    printf("Enter the task number to mark as complete: ");
    scanf("%d", &taskNumber);
    if (taskNumber > 0 && taskNumber <= taskCount) {
        toDoList[taskNumber - 1].completed = 1;
        printf("Task marked as complete!\n");
    } else {
        printf("Invalid task number!\n");
    }
}

void deleteTask() {
    int taskNumber;
    printf("Enter the task number to delete: ");
    scanf("%d", &taskNumber);
    if (taskNumber > 0 && taskNumber <= taskCount) {
        for (int i = taskNumber - 1; i < taskCount - 1; i++) {
            toDoList[i] = toDoList[i + 1];
        }
        taskCount--;
        printf("Task deleted successfully!\n");
    } else {
        printf("Invalid task number!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nTo-Do List App\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Complete\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markComplete();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
