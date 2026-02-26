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
    }
    else{
        printf("deleted elemet - %c\n", queue[front]);
        front++;
        if(front > rear){
            front = rear = -1;
        }
    }
}

void printQ(){
    if(front == -1|| front > rear){
        printf("queue is empty\n");
    } else{
        for(int i=front; i<=rear; i++){
            printf("%c\n",queue[i]);
        }
        printf("\n");
    }
}

int main(){
    addQ('A');
    addQ('B');
    // addQ('C');
    // addQ('D');
    printQ();
    deleteQ();
    printQ();
    // addQ('O');
    addQ('P');
    addQ('O');
    printQ();
    return 0;

}