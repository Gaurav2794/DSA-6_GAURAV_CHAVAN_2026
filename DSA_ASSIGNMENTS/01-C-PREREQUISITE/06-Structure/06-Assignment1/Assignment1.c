/*	
- write a C program to create, declare and initialize structure.
- define a structure "student", which includes the details of students,
- declare an object of the structure and initialize the structure members
*/
#include <stdio.h>
#include <stdlib.h>

struct student{
    int rollNo;
    char name[50];
    float marks;
};

int main(){
    struct student s1= {1,"Gaurav",99.9};
    printf("Student Details:\n");
    printf("Roll No: %d\n", s1.rollNo);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);
    return 0;
}
