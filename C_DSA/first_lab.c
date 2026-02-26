#include<stdio.h>
#include<conio.h>

#define n 10
int top = -1;
char stack[10];

void push(char x){
    if (top == x-1){
        printf("Stack is full\n");
    }
    else{
        top++;
        stack[top] = x;
    }
}

char pop(){
    char x;
    if (top == -1){
        printf("Stack is empty\n");
        return '0';
    }
    else{
        x = stack[top];
        top--;
        return x;
    }
}

char peek(){
    char x;
    if (top == -1){
        printf("Stack is empty\n");
        return '\0';
    }
    else{
        x = stack[top];
        return x;
    }
}

void print(){
    if (top == -1){
        printf("Stack is empty\n");
        
    }
    else{
        for(int i = top; i>=0; i--){
            printf("%c\n",stack[i]);

        }
    }

}

// void main(){
//     print();
//     push('A');
//     push('B');
//     push('C');
//     push('D');
//     print();
//     char x;
//     x = pop();
//     printf("Element popped:%c\n",x);
//     x = peek();
//     printf("peek:%c\n",x);
//     x = pop();
//     printf("Element popped:%c\n",x);
//     print();

// }