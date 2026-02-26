#include <stdio.h>

#include <conio.h>

#define MAX 100

struct term {

    int coeff; int exp; 
};

int readpoly (struct term[]);

void printpoly (struct term[], int);

void addpoly (struct term[], int, struct term[], int, struct term[], int *);

int main(){

    struct term poly1[MAX], poly2[MAX],result[ MAX];
    int n1, n2, n_result;
    printf("Enter the term of 1st polynomial :");
    n1 = readpoly(poly1);
    printf("Enter the term of 2nd polynomial :");
    n2 = readpoly(poly2);
    addpoly(poly1, n1, poly2, n2, result, &n_result); 
    printf(" The sum of 2 polynomials:");
    printpoly (result, n_result);
    return 0;
}

int readpoly(struct term poly[]){
    int n;
    printf("Enter the no. of terms in the polynomial:");
    scanf("%d", &n);
    printf("Enter the coff and exponent:");
    for(int i= 0;i<n;i++){
        scanf("%d%d",&poly[i].coeff, &poly[i].exp);
    }
    return n;
}


void printpoly (struct term poly[], int n){
    for(int i =0;i<n; i++){
        printf("%d%d", poly[i].coeff, poly[i].exp);
        if(i<n-1){
            printf("\n");
        }
    }

}

void addpoly(struct term poly[], int n1, struct term poly2[],int n2, struct term result[], int *n_result){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(poly[i].exp == poly2[j].exp){
            result[k].coeff = poly[i].coeff;
            result[k].exp = poly[i].exp;
            i++;
        } else{
            result[k].coeff = poly2[j].coeff;
            result[k].exp = poly2[j].exp;
            j++;
        }
        k++;
    }
    while(j<n1){
        result[k].coeff = poly2[j].coeff;
        result[k].exp = poly2[j].exp;
        j++;
        k++;
    }
    *n_result = k;

}



