#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int priority[MAX_SIZE];
    int front;
    int rear;
} PriorityQueue;

void initQueue(PriorityQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(PriorityQueue *queue) {
    return (queue->front == -1);
}

int isFull(PriorityQueue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(PriorityQueue *queue, int element, int priority) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        int i;
        for (i = queue->rear; i >= queue->front; i--) {
            if (priority > queue->priority[i]) {
                queue->data[i + 1] = queue->data[i];
                queue->priority[i + 1] = queue->priority[i];
            } else {
                break;
            }
        }
        queue->rear = i + 1;
    }

    queue->data[queue->rear] = element;
    queue->priority[queue->rear] = priority;

    printf("Enqueued element: %d with priority: %d\n", element, priority);
}

int dequeue(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int removedElement = queue->data[queue->front];
    int removedPriority = queue->priority[queue->front];

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;

    printf("Dequeued element: %d with priority: %d\n", removedElement, removedPriority);
    return removedElement;
}

int front(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue->data[queue->front];
}

void printQueue(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    printf("Element\tPriority\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\t%d\n", queue->data[i], queue->priority[i]);
    }
}

int main() {
    PriorityQueue queue;
    initQueue(&queue);

    int choice, element, priority;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Print Queue\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                printf("Enter the priority of the element: ");
                scanf("%d", &priority);
                enqueue(&queue, element, priority);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                element = front(&queue);
                if (element != -1) {
                    printf("Front of the queue: %d\n", element);
                }
                break;
            case 4:
                printQueue(&queue);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
