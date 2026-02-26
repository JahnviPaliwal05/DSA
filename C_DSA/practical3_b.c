#include <stdio.h>

#include <conio.h>

#define MAX 100

typedef struct{

    int coeff; 
    int x_exp; 
    int y_exp;
} term;

int readpoly(term poly[]);
int addpoly(term poly1[], int n1, term poly2[], int n2, term poly3[]);
void printpoly(term poly[], int);


int main(){
    term poly1[MAX], poly2[MAX],result[ MAX];
    int n1, n2, n3;
    printf("Enter the term of 1st polynomial :");
    n1 = readpoly(poly1);
    printf("Enter the term of 2nd polynomial :");
    n2 = readpoly(poly2);
    n3 = addpoly(poly1, n1, poly2, n2, result); 
    printf(" The resulted polynomial is:");
    printpoly(result,n3);
    return 0;
}

int readpoly(term poly[]){
    int n;
    printf("Enter the no. of terms in the polynomial:");
    scanf("%d", &n);
    for(int i= 0;i<n;i++){
        printf("enter the coffient and exponent of x and y for the term %d:", i+1);
        scanf("%d%d%d",&poly[i].coeff, &poly[i].x_exp, &poly[i].y_exp);
    }
    return n;
}


void printpoly (term poly[], int n){
    for(int i =0;i<n; i++){
        if(i>0 && poly[i].coeff>0) printf("+");
        printf("%d%d", poly[i].coeff, poly[i].x_exp, poly[i].y_exp);
    }
    printf("\n");
}

int addpoly(term poly1[], int n1, term poly2[],int n2,  term result[]){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if((poly1[i].x_exp > poly2[j].x_exp) || (poly1[i].x_exp == poly2[j].x_exp) && (poly1[i].y_exp > poly2[j].y_exp)){
            result[k++] = poly1[i++];
        }
        else if((poly2[j].x_exp > poly1[i].x_exp) || (poly2[j].x_exp == poly1[1].x_exp) && (poly2[j].y_exp > poly1[i].x_exp)){
            result[k++] = poly2[j++];
        }
        else{
            result[k] = poly1[i];
            result[k++].coeff = poly1[i++].coeff + poly2[j++].coeff;
        }
    
        while(k<n1) result[k++] = poly1[i++];
        while(j<n2) result[k++] = poly2[j++];
 
    }
    return k;

}



