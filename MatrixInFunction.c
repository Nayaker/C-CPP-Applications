#include <stdio.h>

// IMP - n must be passed before the 2D array
void print(int m, int n, int arr[][n]){ 
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
}

int main(){
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // we cannot write arr[][]
    int m = 3, n = 3;
    print(m, n, arr);
    return 0;
}


// Important notes :- 
// 1. You cannot take print(int** arr) in the function ever with static allocation, 
//    because array is a pointer to integers even when it is a matrix, not pointer to pointer. 

