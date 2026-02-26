#include "first_lab.c" 

char *reverse(char str[]){
    int j,i;
    static char revstr[10];
    i = 0;
    while(str[i] != '\0'){
        push(str[i]);
        i++;
    }

    j = 0;
    while(top != -1){
        revstr[j] = pop();
        j++;
    }

    revstr[j] = '\0';
    return revstr;

}

void main(){
    char str[10];
    printf("enter a string:");
    scanf("%s", str);
    printf("reverse of striing is: %s\n", reverse(str));
}