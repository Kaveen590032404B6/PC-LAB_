#include <stdio.h>
#include <string.h>

#define MAX_TASKS 50

struct Task
{
    char taskName[50];
    char subject[30];
    int daysLeft;
    int priority;
    float studyHours;
    int completed;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

/* Function declarations */
void addTask();
void viewTasks();
void sortTasks();
void markCompleted();
void generateStudyPlan();

int main()
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf(" STUDENT TASK PRIORITISATION & PLANNER\n");
        printf("========================================\n");

        printf("1. Add Task\n");
        printf("2. View All Tasks\n");
        printf("3. View Tasks by Priority\n");
        printf("4. Mark Task as Completed\n");
        printf("5. Generate Study Plan\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                sortTasks();
                break;

            case 4:
                markCompleted();
                break;

            case 5:
                generateStudyPlan();
                break;

            case 6:
                printf("\nThank you for using Study Planner!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}


/* Add a new task */
void addTask()
{
    if (taskCount >= MAX_TASKS)
    {
        printf("\nTask limit reached!\n");
        return;
    }

    printf("\n----- ADD NEW TASK -----\n");

    getchar();

    printf("Enter task name: ");
    fgets(tasks[taskCount].taskName, 50, stdin);
    tasks[taskCount].taskName[
        strcspn(tasks[taskCount].taskName, "\n")
    ] = '\0';

    printf("Enter subject: ");
    fgets(tasks[taskCount].subject, 30, stdin);
    tasks[taskCount].subject[
        strcspn(tasks[taskCount].subject, "\n")
    ] = '\0';

    printf("Enter number of days left: ");
    scanf("%d", &tasks[taskCount].daysLeft);

    printf("Enter priority (1 = High, 2 = Medium, 3 = Low): ");
    scanf("%d", &tasks[taskCount].priority);

    printf("Enter estimated study hours: ");
    scanf("%f", &tasks[taskCount].studyHours);

    tasks[taskCount].completed = 0;

    taskCount++;

    printf("\nTask added successfully!\n");
}


/* Display all tasks */
void viewTasks()
{
    int i;

    if (taskCount == 0)
    {
        printf("\nNo tasks added yet!\n");
        return;
    }

    printf("\n================ TASK LIST ================\n");

    for (i = 0; i < taskCount; i++)
    {
        printf("\nTask %d\n", i + 1);
        printf("Task Name   : %s\n", tasks[i].taskName);
        printf("Subject     : %s\n", tasks[i].subject);
        printf("Days Left   : %d\n", tasks[i].daysLeft);

        printf("Priority    : ");

        if (tasks[i].priority == 1)
            printf("High\n");
        else if (tasks[i].priority == 2)
            printf("Medium\n");
        else
            printf("Low\n");

        printf("Study Hours : %.1f\n", tasks[i].studyHours);

        if (tasks[i].completed == 1)
            printf("Status      : Completed\n");
        else
            printf("Status      : Pending\n");

        printf("-------------------------------------------\n");
    }
}


/* Sort tasks according to priority */
void sortTasks()
{
    int i, j;
    struct Task temp;

    if (taskCount == 0)
    {
        printf("\nNo tasks available!\n");
        return;
    }

    for (i = 0; i < taskCount - 1; i++)
    {
        for (j = 0; j < taskCount - i - 1; j++)
        {
            if (tasks[j].priority > tasks[j + 1].priority)
            {
                temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    printf("\nTasks arranged according to priority!\n");
    viewTasks();
}


/* Mark a task as completed */
void markCompleted()
{
    int taskNumber;

    if (taskCount == 0)
    {
        printf("\nNo tasks available!\n");
        return;
    }

    viewTasks();

    printf("\nEnter task number to mark as completed: ");
    scanf("%d", &taskNumber);

    if (taskNumber >= 1 && taskNumber <= taskCount)
    {
        tasks[taskNumber - 1].completed = 1;
        printf("\nTask marked as completed successfully!\n");
    }
    else
    {
        printf("\nInvalid task number!\n");
    }
}


/* Generate simple study plan */
void generateStudyPlan()
{
    int i;
    float hoursPerDay;

    if (taskCount == 0)
    {
        printf("\nNo tasks available to create a study plan!\n");
        return;
    }

    sortTasks();

    printf("\n=========== YOUR STUDY PLAN ===========\n");

    for (i = 0; i < taskCount; i++)
    {
        if (tasks[i].completed == 0)
        {
            if (tasks[i].daysLeft > 0)
                hoursPerDay =
                    tasks[i].studyHours / tasks[i].daysLeft;
            else
                hoursPerDay = tasks[i].studyHours;

            printf("\n%s - %s\n",
                   tasks[i].subject,
                   tasks[i].taskName);

            printf("Complete within : %d day(s)\n",
                   tasks[i].daysLeft);

            printf("Study approx.   : %.1f hour(s) per day\n",
                   hoursPerDay);

            if (tasks[i].priority == 1)
                printf("Priority        : HIGH - Do this first!\n");
            else if (tasks[i].priority == 2)
                printf("Priority        : MEDIUM\n");
            else
                printf("Priority        : LOW\n");
        }
    }

    printf("\n=======================================\n");
}
