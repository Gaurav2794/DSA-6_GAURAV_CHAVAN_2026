/*
Write a c program which demonstrate a nested structure 
- define a structure employee inside a structure person.
- structure person data: Name, Age, Date of birth, blood group.
- structure employee data: Company name, Emp id, salary, years of experiance.                     
- create objects of structure and display the all details of a person.
*/

#include <stdio.h>

struct employee {
    char companyName[50];
    int empId;
    float salary;
    int experiance;
};

struct person {
    char name[50];
    int age;
    char dob[15];
    char bloodGrp[5];
    struct employee emp;
};

int main() {
    struct person p1;

    printf("Enter Name: ");
    scanf(" %[^\n]", p1.name);

    printf("Enter Age: ");
    scanf("%d", &p1.age);

    printf("Enter Date of Birth (DD/MM/YYYY): ");
    scanf("%s", p1.dob);

    printf("Enter Blood Group: ");
    scanf("%s", p1.bloodGrp);

    printf("Enter Company Name: ");
    scanf(" %[^\n]", p1.emp.companyName);

    printf("Enter Employee ID: ");
    scanf("%d", &p1.emp.empId);

    printf("Enter Salary: ");
    scanf("%f", &p1.emp.salary);

    printf("Enter Years of Experience: ");
    scanf("%d", &p1.emp.experiance);

    printf("\n--- Person Details ---\n");
    printf("Name: %s\n", p1.name);
    printf("Age: %d\n", p1.age);
    printf("DOB: %s\n", p1.dob);
    printf("Blood Group: %s\n", p1.bloodGrp);

    printf("\n--- Employee Details ---\n");
    printf("Company Name: %s\n", p1.emp.companyName);
    printf("Employee ID: %d\n", p1.emp.empId);
    printf("Salary: %.2f\n", p1.emp.salary);
    printf("Experience: %d years\n", p1.emp.experiance);

    return 0;
}