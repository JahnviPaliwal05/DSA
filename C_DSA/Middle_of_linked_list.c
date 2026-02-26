#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* find_middle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    int mid = count / 2 + 1;
    temp = head;
    while (temp != NULL) {
        mid--;
        if (mid == 0) {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

int main() {
    Node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(23);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);

    Node* middle_node = find_middle(head);
    printf("The middle node value is: %d\n", middle_node->data);

    // Free allocated memory (not shown for brevity)
    return 0;
}