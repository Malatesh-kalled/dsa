#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Deque;

void initDeque(Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isEmpty(Deque *deque) {
    return (deque->front == -1 && deque->rear == -1);
}

int isFull(Deque *deque) {
    return (deque->rear + 1) % MAX_SIZE == deque->front;
}

void enqueueFront(Deque *deque, int element) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot enqueue element at the front.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->data[deque->front] = element;
}

void enqueueRear(Deque *deque, int element) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot enqueue element at the rear.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->data[deque->rear] = element;
}

int dequeueFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot dequeue element from the front.\n");
        return -1;
    }

    int removedElement = deque->data[deque->front];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    return removedElement;
}

int dequeueRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot dequeue element from the rear.\n");
        return -1;
    }

    int removedElement = deque->data[deque->rear];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return removedElement;
}

int front(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return deque->data[deque->front];
}

int rear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return deque->data[deque->rear];
}

void printDeque(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    int i = deque->front;
    printf("Deque: ");
    while (i != deque->rear) {
        printf("%d ", deque->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", deque->data[i]);
}

int main() {
    Deque deque;
    initDeque(&deque);

    int choice, element;

    while (1) {
        printf("\nDouble-Ended Queue (Deque) Operations:\n");
        printf("1. Enqueue at Front\n");
        printf("2. Enqueue at Rear\n");
        printf("3. Dequeue from Front\n");
        printf("4. Dequeue from Rear\n");
        printf("5. Front\n");
        printf("6. Rear\n");
        printf("7. Print Deque\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue at the front: ");
                scanf("%d", &element);
                enqueueFront(&deque, element);
                break;
            case 2:
                printf("Enter the element to enqueue at the rear: ");
                scanf("%d", &element);
                enqueueRear(&deque, element);
                break;
            case 3:
                element = dequeueFront(&deque);
                if (element != -1) {
                    printf("Dequeued element from the front: %d\n", element);
                }
                break;
            case 4:
                element = dequeueRear(&deque);
                if (element != -1) {
                    printf("Dequeued element from the rear: %d\n", element);
                }
                break;
            case 5:
                element = front(&deque);
                if (element != -1) {
                    printf("Front of the deque: %d\n", element);
                }
                break;
            case 6:
                element = rear(&deque);
                if (element != -1) {
                    printf("Rear of the deque: %d\n", element);
                }
                break;
            case 7:
                printDeque(&deque);
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
