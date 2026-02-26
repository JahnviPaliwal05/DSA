#include<stdio.h>
#include<conio.h>

#define n 10
int top = -1;
int stack[10];

void push(int x){
    if (top == x-1){
        printf("Stack is full\n");
    }
    else{
        top++;
        stack[top] = x;
    }
}

int pop(){
    int x;
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

int peek(){
    int x;
    if (top == -1){
        printf("Stack is empty\n");
        return '\0';
    }
    else{
        x = stack[top];
        return x;
    }
}

int factorial(int m){
    int i, product, x;
    for (i = 1; i <= m; i++){
        push(i);
    }
    product = 1;
    while(top!= -1){
        x = pop();
        product = product * x;
    }
    return product;
}

int main(){
    int m ;
    printf("Enter a number:");
    scanf("%d", &m);
    printf("Factorial of the number : %d is %d", m, factorial(m));
    return 0;
}