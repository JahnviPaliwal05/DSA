#include<stdio.h>
#include<conio.h>
#define n 5                                      
int front = -1,rear = -1;
char queue[n];

void addQ(char x){                                  
    if(rear == n-1){
        printf("queue is full\n");
    }
    else{
        if(front == -1){
            front = 0;
        rear++;
        queue[rear]=x;
        printf("Added %c to the queue: \n", x);
        }
    }   
}

char deleteQ(){
    if(front == -1|| front > rear){
        printf("queue is empty\n");
        return '\0';