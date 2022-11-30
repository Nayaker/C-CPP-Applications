#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student_data{
    int roll;
    char name[40];
    int marks[5];
} typedef student;


int main() {
    student stdnt; 
    char name[40];
    printf("Enter roll : "); scanf("%d", &stdnt.roll);
    printf("Enter Name : "); scanf("%s", name); strcpy(stdnt.name, name);
    for(int i = 0; i<5; i++)
        printf("Enter marks in subject %d : ", i+1), scanf("%d", &stdnt.marks[i]);

    // printf("Hello %s your roll is %d, your marks in subject 3 is %d\n", stdnt.name, stdnt.roll, stdnt.marks[2]);

    
    
    FILE* file;
    file = fopen("program.bin", "wb");
    fwrite(&stdnt, sizeof(student), 1, file);
    fclose(file);

    file = fopen("program.bin", "rb");
    student new_student;
    fread(&new_student, sizeof(student), 1, file);
    printf("Hello %s your roll is %d, your marks in subject 3 is %d\n", new_student.name, new_student.roll, new_student.marks[2]);
    fclose(file);


    // How to know when the file end ?
    return 0;
}
