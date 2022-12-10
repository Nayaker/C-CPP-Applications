#include <stdio.h>
int main() {
    FILE* file; 
    file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("no such file.");
        return 0;
    }
 
    /* Assuming that file.txt has content in below
       format
       NAME    AGE   CITY
       abc     12    hyderabad
       bef     25    delhi
       cce     65    bangalore */

    char city[100];
    while (fscanf(file, "%*s %*s %s", city) == 1) // sometimes do it > 0, then it will work
        printf("%s\n", city);

    // %*s %*s %s -> brings three strings from the file, and each time 
    // stores the third value on city. 

    // If we have %*s %*s %s %*s, we would have got CITY bef 65 instead
 
    return 0;
}
