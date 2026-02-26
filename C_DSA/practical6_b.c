#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize the queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Add operation to enqueue an element into the queue
void add(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        printf("%d added to the queue\n", value);
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("%d added to the queue\n", value);
}

// Delete operation to dequeue an element from the queue
int delete(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int deletedValue = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return deletedValue;
}

// Print operation to display all elements in the queue
void printQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue
int main() {
    struct Queue* queue = createQueue();

    add(queue, 10);
    add(queue, 20);
    add(queue, 30);

    printQueue(queue);

    printf("Deleted element: %d\n", delete(queue));
    printQueue(queue);

    return 0;
}