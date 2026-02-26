#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Structure to represent the queue
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// // Function to check if the queue is full
// int isFull(struct Queue* q) {
//     return q->rear == MAX - 1;
// }

// // Function to check if the queue is empty
// int isEmpty(struct Queue* q) {
//     return q->front == -1 || q->front > q->rear;
// }

// Function to add an element to the queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("\nQueue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // Initialize front for the first element
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("\nEnqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(struct Queue* q) {
    if (q->front == -1) {
        printf("\nQueue is empty. Cannot dequeue.\n");
        return -1; // Indicate that the queue is empty
    }
    int dequeuedValue = q->items[q->front];
    q->front++;
    if (q->front > q->rear) { // Reset the queue when it becomes empty
        initQueue(q);
    }
    printf("\nDequeued: %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to print the elements of the queue
void printQueue(struct Queue* q) {
    if (q->front == -1) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->items[i]);
        printf("\n");
    }
    printf("\n");
}

// Main function to demonstrate the queue operations
int main() {
    struct Queue myQueue;
    initQueue(&myQueue);
    int choice,x;
    do{
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.print\n");
        printf("4.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
            printf("\nInput the value:");
            scanf("%d",&x);
            enqueue(&myQueue, x);
            break;

            case 2:
            x = dequeue(&myQueue);
            break;

            case 3:
            printQueue(&myQueue);
            break;
        };
    }while(choice<4);
    return 0;
}
