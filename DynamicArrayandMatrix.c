#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows_len = 3, cols_len = 5;
    int** array = (int**) malloc(sizeof(int*)*rows_len);  
    
    for(int i = 0; i<rows_len; i++){
        int* row = (int*) malloc(sizeof(int)*cols_len);
        *(array + i) = row;
    }

    for(int i = 0; i<rows_len; i++)
        for(int j = 0; j<cols_len; j++)
            *(*(array + i) + j) = i*j + i + j;

    for(int i = 0; i<rows_len; i++){
        for(int j = 0; j<cols_len; j++){
            printf("%d ", *(*(array + i) + j));
        }
        printf("\n");
    }

    return 0;
}
