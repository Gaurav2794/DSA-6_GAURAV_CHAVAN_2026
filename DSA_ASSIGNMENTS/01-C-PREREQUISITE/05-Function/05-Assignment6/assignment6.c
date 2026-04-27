#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

void searchStudent(Student s[], int n, int key) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (s[i].id == key) {
            printf("\nStudent Found:\n");
            printf("ID: %d\n", s[i].id);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found\n");
    }
}

int main() {
    int n, key;

    printf("Enter number of students: ");
    scanf("%d", &n);

    Student s[n];

    printf("Enter student details (id name marks):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %f", &s[i].id, s[i].name, &s[i].marks);
    }

    printf("Enter student ID to search: ");
    scanf("%d", &key);

    searchStudent(s, n, key);

    return 0;
}