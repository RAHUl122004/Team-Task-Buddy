
#include <stdio.h>
#include <stdlib.h>



// structure with description, assignee, next task pointer, and dependency pointer
struct Task {
    char description[100];
    char assignee[50];
    struct Task *next;
    struct Task *dependency;
};

// prototype for adding a task to the task list
struct Task *addTask(struct Task *head, const char *description, const char *assignee, struct Task *dependency);

// prototype for printing all tasks in the task list
void printTasks(struct Task *head);

// prototype for freeing memory allocated for tasks
void freeTasks(struct Task *head);

// Main function
int main() {
    struct Task *taskList = NULL;
    char description[100];
    char assignee[50];
    struct Task *dependency = NULL;

    int choice = 0;
    while (choice != 3) {
        printf("Task Manager Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]s", description);
                printf("Enter assignee name: ");
                scanf(" %[^\n]s", assignee);
                printf("Enter dependency description (if any, otherwise press Enter): ");
                char dependencyDescription[100];
                scanf(" %[^\n]s", dependencyDescription);

                // Find the task with the specified dependency description
                struct Task *temp = taskList;
                while (temp != NULL) {
                    int i = 0;
                    while (dependencyDescription[i] != '\0' && temp->description[i] != '\0' && dependencyDescription[i] == temp->description[i]) {
                        i++;
                    }

                    // to check the loop ended because of a match or because one of the strings ended
                    if (dependencyDescription[i] == '\0' && temp->description[i] == '\0') {
                        dependency = temp;
                        break;
                    }

                    temp = temp->next;
                }

                // Set the dependency accordingly
                if (temp != NULL) {
                    dependency = temp;
                } else {
                    dependency = NULL;  // No matching task found, set dependency to NULL
                }

                taskList = addTask(taskList, description, assignee, dependency);
                printf("Task added successfully!\n\n");
                break;

            case 2:
                printTasks(taskList);
                break;

            case 3:
                printf("Exiting Task Manager.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    freeTasks(taskList);

    return 0;
}

// definition for adding a task to the task list
struct Task *addTask(struct Task *head, const char *description, const char *assignee, struct Task *dependency) {
    struct Task *newTask = (struct Task *)malloc(sizeof(struct Task));
    if (newTask == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (i < 99&& description[i] != '\0') {
        newTask->description[i] = description[i];
        i++;
    }
    newTask->description[i] = '\0';

    i = 0;
    while (i < 49 && assignee[i] != '\0') {
        newTask->assignee[i] = assignee[i];
        i++;
    }
    newTask->assignee[i] = '\0';

    newTask->dependency = dependency;

    newTask->next = head;
    return newTask;
}

// Function definition for printing all tasks 
void printTasks(struct Task *head) {
    printf("Tasks:\n");
    while (head != NULL) {
        printf("- Description: %s\n  Assignee: %s\n", head->description, head->assignee);
        if (head->dependency != NULL) {
            printf("  Dependency on: %s\n", head->dependency->description);
        }
        head = head->next;
    }
    printf("\n");
}

// for freeing memory allocated for tasks
void freeTasks(struct Task *head) {
    while (head != NULL) {
        struct Task *temp = head;
        head = head->next;
        free(temp);
    }
}
