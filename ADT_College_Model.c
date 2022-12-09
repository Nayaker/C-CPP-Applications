// College Model 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_structure{
    char name[50];
    int roll;
    float percentage; 
} typedef student;

struct students_structure{
    int max_students;
    int curr_students;
    student*  ptr;
} typedef students;

void createStudentsArray(students* all_students, int max_students, int curr_students){
    all_students->max_students = max_students;
    // (*all_students).max_students = max_students; --> same thing
    all_students->curr_students = curr_students;
    all_students->ptr = (student*) malloc(sizeof(student*)*max_students);
}

void takeData(students* all_students, int curr_students){
    for(int i = 0; i<curr_students; i++){
        printf("\nEnter data for student %d :-\n", i+1);
        printf("Enter student name : "); scanf("%s", ((all_students->ptr) + i)->name);
        printf("Enter student roll : "); scanf("%d", &((all_students->ptr) + i)->roll);
        printf("Enter student percentage : "); scanf("%f", &((all_students->ptr) + i)->percentage);
    }
}

void showData(students* all_students, int curr_students){
    for(int i = 0; i<curr_students; i++){
        printf("\nShowing data for student %d :-\n", i+1);
        printf("Student name : %s\n", ((all_students->ptr) + i)->name); 
        printf("Student roll : %d\n", ((all_students->ptr) + i)->roll); 
        printf("Student percentage : %f\n", ((all_students->ptr) + i)->percentage); 
    }
}

int main() {
    students all_students;
    
    int max_students, curr_students;
    printf("Enter the maximum number of students : "); scanf("%d", &max_students);
    printf("Enter the current number of students : "); scanf("%d", &curr_students);

    createStudentsArray(&all_students, max_students, curr_students);    
    takeData(&all_students, curr_students);    
    showData(&all_students, curr_students);    

    return 0;
}
