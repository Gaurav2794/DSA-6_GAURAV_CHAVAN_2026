/* 	
write a c program to Create and Display Singly Linked list. with structure "Student" with following data members:
-Name 
-Roll no
-standard
-Division*/
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[20];
    int roll;
    int std;
    char div;
    struct Student* next;
};

struct Student* create() {
    struct Student *n;
    n = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter Name: ");
    scanf("%s", n->name);

    printf("Enter Roll: ");
    scanf("%d", &n->roll);

    printf("Enter Standard: ");
    scanf("%d", &n->std);

    printf("Enter Division: ");
    scanf(" %c", &n->div);

    n->next = NULL;
    return n;
}

void display(struct Student *n) {
    printf("\nStudent Data:\n");
    printf("Name: %s\n", n->name);
    printf("Roll: %d\n", n->roll);
    printf("Standard: %d\n", n->std);
    printf("Division: %c\n", n->div);
}

void destroy(struct Student *head) {
    struct Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Student *head;

    head = create();
    display(head);

    destroy(head);

    return 0;
}