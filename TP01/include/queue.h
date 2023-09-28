#include <stdbool.h>
#include <stdlib.h>

#include "types.h"

// Define the queue structure
struct Queue {
    struct Element *elements;
    int capacity;
    int front;
    int rear;
    int size;
};

// Function to initialize the queue
void initializeQueue(struct Queue *queue, int capacity);

// Function to enqueue an element into the queue
bool enqueue(struct Queue *queue, enum DataType type, union GenericData data);

// Function to dequeue an element from the queue
bool dequeue(struct Queue *queue, enum DataType *type, union GenericData *data);

// Function to check if the queue is empty
bool isEmpty(struct Queue *queue);

// Function to get the front element of the queue
bool front(struct Queue *queue, enum DataType *type, union GenericData *data);
