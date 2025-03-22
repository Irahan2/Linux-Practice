#include <stdio.h>
#include <stdlib.h>

int main()
{

// TASK 1: Define the structure for a Task
typedef struct Task {
    char name[50];          // Task name
    char priority[10];      // Task priority (e.g., "High", "Low")
    int totalTime;          // Total task time
    int remainingTime;      // Remaining execution time
} Task;





//TASK2
// Reuse the Task struct from TASK 1

// Function to create a new Task instance
Task* createTask(char *name, char *priority, int time, int remaining) {
    Task *t = (Task*)malloc(sizeof(Task));
    strcpy(t->name, name);
    strcpy(t->priority, priority);
    t->totalTime = time;
    t->remainingTime = remaining;
    return t;
}

// Function to display the Task in the required format
void show(Task *task) {
    printf("%s - %s priority  %d / %d done\n",
           task->name,
           task->priority,
           task->totalTime - task->remainingTime,
           task->totalTime);
}

// Example usage
int main() {
    Task *task = createTask("Learn C", "High", 10, 9);
    show(task);
    free(task); // free memory after use
    return 0;
}






// TASK 3 & 4: Define the Task structure
typedef struct Task {
    char name[50];          // Task name
    char priority[10];      // Task priority (e.g., "High", "Low")
    int totalTime;          // Total task time
    int remainingTime;      // Remaining execution time
} Task;

// TASK 3: Function to create a new Task
Task* createTask(char *name, char *priority, int time, int remaining) {
    Task *t = (Task*)malloc(sizeof(Task));
    strcpy(t->name, name);
    strcpy(t->priority, priority);
    t->totalTime = time;
    t->remainingTime = remaining;
    return t;
}

// TASK 3: Function to display the Task in the required format
void show(Task *task) {
    printf("%s - %s priority  %d / %d done\n",
           task->name,
           task->priority,
           task->totalTime - task->remainingTime,
           task->totalTime);
}

// TASK 4: Function to increase remaining time by 1
void increase(Task *task) {
    task->remainingTime++;
}

// TASK 4: Function to decrease remaining time by 1
void decrease(Task *task) {
    if (task->remainingTime > 0)
        task->remainingTime--;
}

// MAIN FUNCTION to demonstrate Task 3 and 4
int main() {
    // Create a task
    Task *task = createTask("Learn C", "High", 10, 9);

    // Show initial state
    show(task);  // Output: Learn C - High priority  1 / 10 done

    // Decrease task time
    decrease(task);
    show(task);  // Output: Learn C - High priority  2 / 10 done

    // Increase task time
    increase(task);
    show(task);  // Output: Learn C - High priority  1 / 10 done

    // Free the task
    free(task);

    return 0;
}

//TASK5






// Define the Node structure
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Define the Queue structure
typedef struct Queue {
    Node* front;
    Node* back;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->back = NULL;
}

// Enqueue: Add element to the end
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (q->back == NULL) {
        q->front = q->back = newNode;
    } else {
        q->back->next = newNode;
        q->back = newNode;
    }
}

// Dequeue: Remove element from the front
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->value;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->back = NULL;
    }

    free(temp);
    return value;
}

// Display: Print all elements in the queue
void displayQueue(Queue* q) {
    Node* current = q->front;
    if (current == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the queue
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQueue(&q); // Output: 10 20 30

    int removed = dequeue(&q);
    printf("Removed: %d\n", removed); // Output: 10

    displayQueue(&q); // Output: 20 30

    return 0;
}

//TASK6




// Reuse Task structure from previous tasks
typedef struct Task {
    char name[50];
    char priority[10];
    int totalTime;
    int remainingTime;
} Task;

// Function to create a new Task
Task* createTask(char *name, char *priority, int total, int remaining) {
    Task *t = (Task*)malloc(sizeof(Task));
    strcpy(t->name, name);
    strcpy(t->priority, priority);
    t->totalTime = total;
    t->remainingTime = remaining;
    return t;
}

// Function to display a task
void show(Task *task) {
    printf("%s - %s priority  %d / %d done\n",
           task->name,
           task->priority,
           task->totalTime - task->remainingTime,
           task->totalTime);
}

// Define the node structure for Task queue
typedef struct TaskNode {
    Task *task;
    struct TaskNode* next;
} TaskNode;

// Define the queue structure
typedef struct TaskQueue {
    TaskNode *front;
    TaskNode *back;
} TaskQueue;

// Initialize task queue
void initTaskQueue(TaskQueue *q) {
    q->front = NULL;
    q->back = NULL;
}

// Enqueue a task
void enqueueTask(TaskQueue *q, Task *task) {
    TaskNode *newNode = (TaskNode*)malloc(sizeof(TaskNode));
    newNode->task = task;
    newNode->next = NULL;

    if (q->back == NULL) {
        q->front = q->back = newNode;
    } else {
        q->back->next = newNode;
        q->back = newNode;
    }
}

// Dequeue a task
Task* dequeueTask(TaskQueue *q) {
    if (q->front == NULL) return NULL;

    TaskNode *temp = q->front;
    Task *task = temp->task;
    q->front = q->front->next;
    if (q->front == NULL) q->back = NULL;
    free(temp);
    return task;
}

// Display the queue
void displayTaskQueue(TaskQueue *q) {
    TaskNode *current = q->front;
    if (!current) {
        printf("Queue is empty.\n");
        return;
    }

    while (current != NULL) {
        show(current->task);
        current = current->next;
    }
    printf("\n");
}

// MAIN
int main() {
    TaskQueue q;
    initTaskQueue(&q);

    Task *t1 = createTask("Learn C", "High", 10, 9);
    Task *t2 = createTask("Do laundry", "Low", 5, 5);
    Task *t3 = createTask("Write report", "High", 8, 3);

    enqueueTask(&q, t1);
    enqueueTask(&q, t2);
    enqueueTask(&q, t3);

    printf("Initial Task Queue:\n");
    displayTaskQueue(&q);

    printf("Dequeued task:\n");
    Task *removed = dequeueTask(&q);
    show(removed);

    printf("Queue after dequeue:\n");
    displayTaskQueue(&q);

    // Clean up memory
    free(t1);
    free(t2);
    free(t3);

    return 0;
}


//TASK7



// Task structure
typedef struct Task {
    char name[50];
    char priority[10];  // "High", "Low", etc.
    int totalTime;
    int remainingTime;
} Task;

// Task creator
Task* createTask(char *name, char *priority, int total, int remaining) {
    Task *t = (Task*)malloc(sizeof(Task));
    strcpy(t->name, name);
    strcpy(t->priority, priority);
    t->totalTime = total;
    t->remainingTime = remaining;
    return t;
}

// Task display
void show(Task *task) {
    printf("%s - %s priority  %d / %d done\n",
           task->name,
           task->priority,
           task->totalTime - task->remainingTime,
           task->totalTime);
}

// Node for task queue
typedef struct TaskNode {
    Task *task;
    struct TaskNode *next;
} TaskNode;

// Task Queue
typedef struct TaskQueue {
    TaskNode *front;
    TaskNode *back;
} TaskQueue;

// Queue initializer
void initTaskQueue(TaskQueue *q) {
    q->front = NULL;
    q->back = NULL;
}

// Enqueue
void enqueueTask(TaskQueue *q, Task *task) {
    TaskNode *newNode = (TaskNode*)malloc(sizeof(TaskNode));
    newNode->task = task;
    newNode->next = NULL;

    if (q->back == NULL) {
        q->front = q->back = newNode;
    } else {
        q->back->next = newNode;
        q->back = newNode;
    }
}

// Display queue
void displayTaskQueue(TaskQueue *q, char *title) {
    printf("=== %s ===\n", title);
    TaskNode *current = q->front;
    if (!current) {
        printf("Queue is empty.\n\n");
        return;
    }

    while (current != NULL) {
        show(current->task);
        current = current->next;
    }
    printf("\n");
}

// MAIN
int main() {
    // Two queues: Important and Other
    TaskQueue importantQueue, otherQueue;
    initTaskQueue(&importantQueue);
    initTaskQueue(&otherQueue);

    // Create 6 tasks
    Task *t1 = createTask("Learn C", "High", 10, 9);
    Task *t2 = createTask("Do laundry", "Low", 5, 5);
    Task *t3 = createTask("Write report", "High", 8, 3);
    Task *t4 = createTask("Clean room", "Low", 6, 6);
    Task *t5 = createTask("Read book", "Medium", 7, 7);
    Task *t6 = createTask("Prepare slides", "High", 9, 4);

    // Enqueue to the appropriate queue
    Task *tasks[] = {t1, t2, t3, t4, t5, t6};
    for (int i = 0; i < 6; i++) {
        if (strcmp(tasks[i]->priority, "High") == 0)
            enqueueTask(&importantQueue, tasks[i]);
        else
            enqueueTask(&otherQueue, tasks[i]);
    }

    // Show queues
    displayTaskQueue(&importantQueue, "Important Tasks");
    displayTaskQueue(&otherQueue, "Other Tasks");

    // Clean up
    for (int i = 0; i < 6; i++)
        free(tasks[i]);

    return 0;
}






}
