#include <stdio.h>

void function1(int *array, int len){
    printf("\nWe are in function1 -----\n");

    for(int i = 0; i<len; i++){
        printf("%d ", array[i]);
    } printf("\n");
}

void function2(int array[], int len){
    printf("\nWe are in function2 -----\n");

    for(int i = 0; i<len; i++){
        printf("%d ", array[i]);
    } printf("\n");
}

void function3(int array[], int len){
    printf("\nWe are in function3 -----\n");

    for(int i = 0; i<len; i++){
        printf("%d ", *(array + i));
    } printf("\n");
}

int main() {
    int len = 4;
    int array[] = {1, 3, 4, 7}; 
    
    for(int i = 0; i<len; i++){
        printf("%d ", array[i]);
    } printf("\n");

    function1(array, len);
    function2(array, len);
    function3(array, len);

    return 0;
}
