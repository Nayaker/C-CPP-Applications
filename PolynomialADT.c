// ADT for Polynomial
#include <stdio.h>
#include <stdlib.h>

struct Term_Structure{
    int coeff; 
    int power;
} typedef Term;

struct Polynomial_Structure{
    int max_power; 
    Term* ptr;
} typedef Polynomial;

void createPolynomial(Polynomial* polynomial, int highest_power){
    polynomial->max_power = highest_power;
    polynomial->ptr = (Term*) malloc((highest_power + 1) * sizeof(Term));

    int value; 
    for(int i = highest_power; i+1; i--){
        printf("Print coefficient of x^%d : ", i); scanf("%d", &value);
        (polynomial->ptr + i)->coeff = value;
        (polynomial->ptr + i)->power = i;
    }

    printf("Your polynomial : ");
    for(int i = highest_power; i+1; i--){
        if((polynomial->ptr + i)->coeff)
            printf("+ %dx^%d ", (polynomial->ptr + i)->coeff, (polynomial->ptr + i)->power);
    } printf("\n");
}

Polynomial addPolynomials(Polynomial* polynomial1, Polynomial* polynomial2, int highest_power){
    Polynomial sum; 
    sum.max_power = highest_power;
    sum.ptr = (Term*) malloc ((highest_power + 1) * sizeof(Term));

    for(int i = highest_power; i+1; i--){
        (sum.ptr + i)->coeff = (polynomial1->ptr + i)->coeff + (polynomial2->ptr + i)->coeff;
        (sum.ptr + i)->power = i;
    }

    printf("\n\nSum of the two polynomials : ");
    for(int i = highest_power; i+1; i--){
        if((sum.ptr + i)->coeff)
            printf("+ %dx^%d ", (sum.ptr + i)->coeff, (sum.ptr + i)->power);
    } printf("\n");

    return sum;
}

int main() {
    int n;
    printf("Enter the highest power of the expression : "); scanf("%d", &n);

    Polynomial polynomial1, polynomial2;
    createPolynomial(&polynomial1, n);
    createPolynomial(&polynomial2, n);
    
    Polynomial sum = addPolynomials(&polynomial1, &polynomial2, n);


    return 0;
}   
