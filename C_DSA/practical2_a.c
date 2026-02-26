#include<stdio.h>
#include<conio.h>
#define n 10                                        
int top = -1;
char stack[10];

void push(char x){                                  
    if(top == x-1){
        printf("Stack is full\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}

char pop(){
    char x;
    if(top == -1){
        printf("Stack is empty\n");
        return '\0';
    }
    else{
        x = stack[top];
        top--;
        return x;
    }
}

void print(){
    if(top == -1){
        printf("Stack is empty\n");
    } else{
        for(int i=top; i>=0; i--){
            printf("%c\n",stack[i]);
        }
    }
}

int main(){
    int choice; 
    char x;
    do{
        printf("\n--------------------------------------\n");
        printf("Stack operations:");
        printf("\n--------------------------------------\n");
        printf("1\tpush\n");
        printf("2\tpop\n");
        printf("3\tprint\n");
        printf("4\texit\n");
        printf("\n--------------------------------------\n");
        
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("\n--------------------------------------\n");
        switch(choice){
            case 1:
                int x;
                printf("Input the value:");
                scanf(" %c",&x);
                push(x);
                break;

            case 2:
                x = pop();
                if(x!='\0'){
                    printf("Value popped:%c",x);
                }
                break;


            case 3:
                print();
                break;


            case 4:
            break;

            
        };

    }while(choice!=9);
    getch();
    return 0;

}
