//Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* reverse_linked_list(Node* head) {
    Node* temp = head;
    int stack[100]; // Assuming a maximum size of 100 for simplicity
    int top = -1;

    while (temp != NULL) {
        stack[++top] = temp->data;
        temp = temp->next;
    }
    temp = head;

    while (temp != NULL) {
        temp->data = stack[top--];
        temp = temp->next;
    }
    return head;
}

void print_l(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 101;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 38;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 20;
    head->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->data = 44;
    head->next->next->next->next = NULL;

    printf("Original Linked List: ");
    print_l(head);
    head = reverse_linked_list(head);
    printf("Reversed Linked List: ");
    print_l(head);

    // Free allocated memory
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}