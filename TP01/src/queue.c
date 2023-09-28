#include "queue.h"

void initializeQueue(struct Queue *queue, int capacity) {
    queue->elements = malloc(sizeof(struct Element) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

bool enqueue(struct Queue *queue, enum DataType type, union GenericData data) {
    if (queue->size >= queue->capacity) {
        return false; // Queue is full
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear].type = type;
    queue->elements[queue->rear].data = data;
    queue->size++;

    return true;
}

bool dequeue(struct Queue *queue, enum DataType *type, union GenericData *data) {
    if (queue->size <= 0) {
        return false; // Queue is empty
    }

    *type = queue->elements[queue->front].type;
    *data = queue->elements[queue->front].data;
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return true;
}

bool isEmpty(struct Queue *queue) {
    return queue->size <= 0;
}

bool front(struct Queue *queue, enum DataType *type, union GenericData *data) {
    if (queue->size <= 0) {
        return false; // Queue is empty
    }

    *type = queue->elements[queue->front].type;
    *data = queue->elements[queue->front].data;

    return true;
}