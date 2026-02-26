#include<stdio.h>
#include<stdlib.h>

struct element{
    int data;
    struct element *link;
};

struct element *head = NULL;

int addL(int x){
    struct element *p, *current;
    p = (struct element*) malloc(sizeof(struct element));
    p-> data = x;
    p -> link = NULL;
    if (head == NULL){
        head = p;
        return;
    }
    current = head;
    while(current->link!=NULL){
        current = current ->link;
    }
    current -> link = p;
    head = p;
    return 0;

}
