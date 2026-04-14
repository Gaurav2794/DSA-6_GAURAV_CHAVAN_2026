/*
Create a structure "Students" with below member variables:
    - Name of student,
    - Roll no. Of Student,
    - array of 5 Subject marks,
    - Total Percentage 
    
- Calculate the Percentage for "N" number of students,
- Display all details for all students,
- Display the details of topper.
(use array of structure)*/
#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float marks[5];
    float percentage;
};

int main() {
    int n, i, j;
    struct Student s[100];
    int topperIndex = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Roll No: ");
        scanf("%d", &s[i].roll);

        float total = 0;
        printf("Enter marks of 5 subjects:\n");
        for(j = 0; j < 5; j++) {
            scanf("%f", &s[i].marks[j]);
            total += s[i].marks[j];
        }

        s[i].percentage = total / 5.0;

        if(s[i].percentage > s[topperIndex].percentage) {
            topperIndex = i;
        }
    }

    printf("\n--- All Students Details ---\n");
    for(i = 0; i < n; i++) {
        printf("\nName: %s\n", s[i].name);
        printf("Roll No: %d\n", s[i].roll);
        printf("Marks: ");
        for(j = 0; j < 5; j++) {
            printf("%.2f ", s[i].marks[j]);
        }
        printf("\nPercentage: %.2f\n", s[i].percentage);
    }

    printf("\n--- Topper Details ---\n");
    printf("Name: %s\n", s[topperIndex].name);
    printf("Roll No: %d\n", s[topperIndex].roll);
    printf("Percentage: %.2f\n", s[topperIndex].percentage);

    return 0;
}