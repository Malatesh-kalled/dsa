#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5
#define MAX_CAR_NUMBER_LENGTH 10

typedef struct {
    int front;
    int rear;
    int count;
    char car_number[MAX_QUEUE_SIZE][MAX_CAR_NUMBER_LENGTH];
} CircularQueue;

void enqueue(CircularQueue* queue, const char* car_number) {
    if (queue->count == MAX_QUEUE_SIZE) {
        printf("Queue is full. Cannot enqueue car number %s\n", car_number);
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    strcpy(queue->car_number[queue->rear], car_number);
    queue->count++;
}

char* dequeue(CircularQueue* queue) {
    if (queue->count == 0) {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    char* car_number = queue->car_number[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->count--;

    return car_number;
}

void displayQueue(CircularQueue* queue) {
    if (queue->count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Car numbers in the queue: ");
    int i;
    for (i = 0; i < queue->count; i++) {
        int index = (queue->front + i) % MAX_QUEUE_SIZE;
        printf("%s ", queue->car_number[index]);
    }
    printf("\n");
}

int main() {
    CircularQueue queue;
    queue.front = 0;
    queue.rear = -1;
    queue.count = 0;

    FILE* file = fopen("C:\\users\\malatesh\\desktop\\dsa.txt", "w+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    FILE* input_file = fopen("C:\\users\\malatesh\\desktop\\input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        fclose(file);
        return -1;
    }

    char car_number[MAX_CAR_NUMBER_LENGTH];
    while (fscanf(input_file, "%s", car_number) == 1) {
        enqueue(&queue, car_number);
        fprintf(file, "%s ", car_number);
    }

    fclose(file);
    fclose(input_file);

    return 0;
}
