#include <stdio.h>

struct employee {
    int emp_id;
    char name[50];
    float salary;
};

int main() {
    struct employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.emp_id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp.name);  // handles spaces

    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);   // MUST have &

    printf("\nEmployee Details:\n");
    printf("ID: %d\n", emp.emp_id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);

    return 0;
}