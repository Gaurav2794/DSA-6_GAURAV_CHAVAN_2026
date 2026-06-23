#include <stdio.h> //for declaration of printf()
#include <stdlib.h>//for declaration of malloc(),free(),exit()
#include <string.h>//for declaration of memset()

struct date
{
    int day;
    int month;
    int year;
};

struct array
{
    int *a;
    int n;
};

void dynamic_builtin(void);
void dynamic_user_defined_date(void);
void dynamic_user_defined_array(void);

int main(void)
{
    dynamic_builtin();
    dynamic_user_defined_date();
    dynamic_user_defined_array();

    return (0);
}

void dynamic_builtin(void)
{
    // Step 1: Declare a pointer and initialize it to NULL
    int *ptr = NULL;

    // Step 2:  Allocate dynamic memory using malloc() and
    //          do the validation check
    ptr = (int *)malloc(sizeof(int));
    if (NULL == ptr)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }
    // Step 3:  Initialize allocated instance to 0
    memset(ptr, 0, sizeof(int));

    // Step 4-5: Read/Write on dynamically allocated instance
    *ptr = 100;                     //write operation
    int n = *ptr;                   //read opearation
    printf("*ptr = %d\n", *ptr);    //read opearation

    //  Step 6:  When dynamic instance is no longer wanted
    //           Release it and make pointer NULL again
    free(ptr);
    ptr = NULL;
}
void dynamic_user_defined_date(void)
{
    //step 1
    struct date *newdate = NULL;
    newdate = (struct date *)malloc(sizeof(struct date));

    if (NULL == newdate)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }
    memset(newdate, 0, sizeof(struct date));

    newdate->day = 27;
    newdate->month = 9;
    newdate->year = 2004;

    printf("%d/%d/%d\n", newdate->day, newdate->month, newdate->year);
    free(newdate);
    newdate = NULL;
}

void dynamic_user_defined_array(void)
{
    struct array *p_array = NULL;

    p_array = (struct array *)malloc(sizeof(struct array));
    if (NULL == p_array)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }
    p_array->n = 8;
    p_array->a = (int *)malloc(p_array->n * sizeof(int));
    if (NULL == p_array->a)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    for (i = 0; i < p_array->n; ++i)
    {
        p_array->a[i] = (i + 1) * 10;
    }
    puts("showing array: ");
    for (i = 0; i < p_array->n; ++i)
    {
        printf("o_array->a[%d]: %d\n", i, p_array->a[i]);
    }
    free(p_array->a);
    p_array->a = NULL;

    free(p_array);
    p_array = NULL;
}