//Header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//symbolic constant
#define SUCCESS              1
#define TRUE                 1
#define FALSE                0
#define LIST_DATA_NOT_FOUND  2
#define LIST_EMPTY           3

//Node Layout defination
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
//Interface Function Declaration
//List Creation Function
struct node* create_list(void);
/*data addition/insertion function*/
int insert_start(struct node* p_list , int new_data);
int insert_end(struct node* p_list , int new_data);
int insert_after(struct node* p_list , int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data , int new_data);

/*Get Functions*/
int get_start(struct node* p_list , int* p_start_data);
int get_end(struct node* p_list , int* p_end_data);

/*POP Functions*/
int pop_start(struct node* p_list , int* p_start_data);
int pop_end(struct node *p_list , int* p_end_data);

/*Remove Functions*/
int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list , int r_data);

/*Miscellinious Function*/
int find (struct node* p_list, int f_data);
int get_list_length(struct node* p_list);
int is_list_empty(struct node* p_list);

/*Display List*/
void show_list(struct node* p_list, const char* msg);
    
/*List Destruction Function*/
int destroy_list(struct node* p_list);




/* Client of linked list */
int main(void)
{
    struct node* p_list = NULL;

    int status;
    int data, start_data, end_data;
    int length;

    static const char* line = "------------------------------------------------------------";

    p_list = create_list();
    assert(p_list != NULL);
    printf("List created successfully\n");
    puts(line);

    printf("Testing assertions on the empty list\n");
    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);
    assert(get_start(p_list, &start_data) == LIST_EMPTY);
    assert(get_end(p_list, &end_data) == LIST_EMPTY);
    assert(pop_start(p_list, &start_data) == LIST_EMPTY);
    assert(pop_end(p_list, &end_data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);
    printf("All assertions on the empty list are successful\n");
    puts(line);

    show_list(p_list, "Showing empty list immediately after creation:");
    puts(line);

    for(data = 0; data < 5; ++data)
    {
        status = insert_start(p_list, data * 10);
        assert(status == SUCCESS);
        printf("%d inserted successfully at the start of the list\n", data * 10);
    }

    show_list(p_list, "Showing list after inserting 5 data elements at the start:");
    puts(line);

    for(data = 1; data <= 5; ++data)
    {
        status = insert_end(p_list, data * 5);
        assert(status == SUCCESS);
        printf("%d inserted successfully at the end of the list\n", data * 5);
    }

    show_list(p_list, "Showing list after inserting 5 data elements at the end:");
    puts(line);

    status = insert_after(p_list, -5, 100);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 100 after non-existent data -5\n");
    puts(line);

    status = insert_after(p_list, 0, 100);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after successfully inserting 100 after 0:");
    puts(line);

    status = insert_before(p_list, 43, 200);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 200 after non-existent data 43\n");
    puts(line);

    status = insert_before(p_list, 0, 200);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after successfully inserting data 200 before 0:");
    puts(line);

    status = get_start(p_list, &start_data);
    assert(status == SUCCESS);
    printf("Data at the start:%d\n", start_data);
    show_list(p_list, "Showing list to demonstrate that get_start() returns start data without removing it:");
    puts(line);

    status = get_end(p_list, &end_data);
    assert(status == SUCCESS);
    printf("Data at the end:%d\n", end_data);
    show_list(p_list, "Showing list to demonstrate that get_end() returns the end data without removing it:");
    puts(line);

    status = pop_start(p_list, &start_data);
    assert(status == SUCCESS);
    printf("Data at the start = %d\n", start_data);
    show_list(p_list, "Showing list to demonstrate that pop_start() removes and returns the start data:");
    puts(line);

    status = pop_end(p_list, &end_data);
    assert(status == SUCCESS);
    printf("Data at the end = %d\n", end_data);
    show_list(p_list, "Showing list to demonstrate that pop_end() removes and returns the end data:");
    puts(line);

    status = remove_start(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after remove_start():");
    puts(line);

    status = remove_end(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after remove_end():");
    puts(line);

    status = remove_data(p_list, 78);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected error in removing non-existent data 78\n");
    puts(line);

    status = remove_data(p_list, 0);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after removing existing data 0:");
    puts(line);

    status = find(p_list, 91);
    assert(status == FALSE);
    printf("Expected return value FALSE from find() for non-existent data 91\n");
    puts(line);

    status = find(p_list, 100);
    assert(status == TRUE);
    printf("Expected return value TRUE from find() for existing data 30\n");
    puts(line);

    status = is_list_empty(p_list);
    assert(status == FALSE);
    printf("Expected return value FALSE from is_list_empty()\n");
    puts(line);

    length = get_list_length(p_list);
    printf("Length of the list = %d\n", length);
    puts(line);

    status = destroy_list(p_list);
    assert(status == SUCCESS);
    p_list = NULL;
    printf("List is destroyed successfully\n");
    puts(line);

    return (0);
}

/*Client of Linked List
Entry Point Function
Main / Starting Function*/


/*Server side of Linked List
Interface functions definations*/

//creation list function
struct node* create_list(){
    struct node* head_node = NULL;
    head_node=(struct node*)malloc(sizeof(struct node));
    if(NULL == head_node)
    {
        puts("Out Of Memory");
        exit(EXIT_FAILURE);
    }
    head_node -> data=0;
    head_node -> next = NULL;
    head_node -> prev = NULL;
    return head_node;
}

//data addition functions
//INSERT AT HEAD
int insert_start(struct node* p_list,int new_data){
    struct node* new_node=NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }
    new_node -> data= new_data;
    new_node -> next = p_list->next; 
    p_list ->next = new_node;
    return (SUCCESS);
}
//INSERT AT END
int insert_end(struct node* p_list, int new_data){
    struct node* new_node=NULL;
    struct node* run=NULL;
    new_node=(struct node*)malloc(sizeof(struct node));//step1.allocate memory and initialize memory
    if(new_node==NULL){
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }
    new_node -> data= new_data;
    new_node -> next = NULL;
    //2.locate last node
    run=p_list;
    while(run->next != NULL)
    {
        run = run-> next;
    }
    //3.link the new node at the end
    run -> next = new_node;
    return(SUCCESS);   
}
//INSERT AFTER
int insert_after(struct node* p_list , int existing_data, int new_data)
{
    struct node* existing_node = NULL;
    struct node* new_node = NULL;
    struct node* run = NULL;

    //1.search for the node which contains the first occurance of existing data
    run = p_list-> next;
    while(run != NULL)
    {
        if(run->data==existing_data)
        {
            break;
        }
        run = run->next;
    }
    //if existing data isnt there 
    if(run == NULL){
        return (LIST_DATA_NOT_FOUND);
    }
    //2.Alloacte and initialize a new node
    existing_node=run;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }
    new_node-> data = new_data;

    //3.insert the node at appropriate position
    new_node -> next = existing_node->next; 
    existing_node->next = new_node;
    return (SUCCESS);
}
//INSERT BEFORE
int insert_before(struct node* p_list , int existing_data , int new_data)
{
    struct node* run = NULL;
    struct node* run_prev = NULL;
    struct node* new_node = NULL;

    //1.search for the first occurance of the existing data
    //with maintaining the back Pointer

    run_prev = p_list ;
    run = p_list-> next;
    while(run != NULL)
    {
        if(run-> data == existing_data)
        break;
        run_prev = run;
        run = run->next;
    }
    /*if the existing data is not found then return error message*/
    if(run == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }
    //2.allocate and initalize new node

    new_node = (struct node*)malloc(sizeof(struct node));
    if( new_node==NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    } 
    new_node-> data = new_data;
    new_node->next = run;
    run_prev-> next= new_node;
    return (SUCCESS);
}

//GET FUNCTIONS
int get_start(struct node* p_list , int* p_start_data)
{
    if(p_list->next == NULL)
    {
        return LIST_EMPTY;
    }
    *p_start_data = p_list->next->data;
    return (SUCCESS);
}
//GET END
int get_end(struct node* p_list , int* p_end_data)
{
    struct node* run=NULL;
    if(p_list-> next == NULL)
    {
        return LIST_EMPTY;
    }
    run = p_list->next;
    while(run-> next != NULL)
    {
        run = run->next;
    }
    *p_end_data = run->data;
    return (SUCCESS);
}
//POP FUNCTIONS
//POP START
int pop_start(struct node* p_list , int* p_start_data)
{
    struct node* delete_node = NULL;
    struct node* delete_prev = NULL;
    struct node* delete_next = NULL;

    if(p_list->next == NULL)
    {
        return LIST_EMPTY;
    }
    *p_start_data = p_list->next->data;

    delete_prev = p_list;
    delete_node = p_list->next;
    delete_next = p_list->next->next;

    delete_prev -> next= delete_next;
    free(delete_node);
    delete_node=NULL;
    return (SUCCESS);
}
//POP END
int pop_end(struct node* p_list , int* p_end_data)
{
    struct node* run = NULL;
    struct node* run_prev = NULL;

    if(p_list->next == NULL)
    {
        return LIST_EMPTY;
    }
    run_prev = p_list;
    run = p_list->next;
    while(run->next != NULL)
    {
        run_prev = run;
        run = run-> next;
    }
    *p_end_data = run->data;
    free(run);
    run=NULL;
    run_prev -> next = NULL;
    return(SUCCESS);
}

//REMOVE FUNCTIONS
//REMOVE START
int remove_start(struct node* p_list)
{
    struct node* delete_node = NULL;
    struct node* delete_prev = NULL;
    struct node* delete_next = NULL;

    if(p_list->next == NULL)
    {
        return LIST_EMPTY;
    }
    delete_prev = p_list;
    delete_node = p_list->next;
    delete_next = p_list->next->next;

    delete_prev -> next= delete_next;
    free(delete_node);
    delete_node=NULL;
    return (SUCCESS);
}
//REMOVE END
int remove_end(struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_prev = NULL;

    if(p_list->next == NULL)
    {
        return LIST_EMPTY;
    }
    run_prev = p_list;
    run = p_list->next;
    while(run->next != NULL)
    {
        run_prev = run;
        run = run-> next;
    }
    free(run);
    run=NULL;
    run_prev -> next = NULL;
    return(SUCCESS);
}
int remove_data(struct node* p_list , int r_data)
{
    struct node* run = NULL;
    struct node* run_prev = NULL;
    run_prev = p_list;
    run = p_list -> next;
    while(run != NULL)
    {
        if(run -> data == r_data)
        {
             break;
        }
        run_prev = run;
        run=run->next;
    }
    if(run==NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }
    run_prev->next = run->next;
    free(run);
    run = NULL;
    return (SUCCESS);
}

//miscelenious function
//find
int find (struct node* p_list, int f_data)
{
    struct node* run = NULL;
    run = p_list->next;
    while(run!=NULL)
    {
        if(run->data==f_data)
        {
            return TRUE;
        }
        run = run->next;
    }
    return FALSE;
}
//LENGTH
 int get_list_length(struct node* p_list)
 {
    int len =0;
    struct node* run =NULL;

    run = p_list->next;
    while(run!=NULL)
    {
        len = len+1;
        run = run->next;
    }
    return len;
 }
 //EMPTY LIST
 int is_list_empty(struct node* p_list)
 {
    return (p_list->next==NULL);
 }
 //SHOW LIST
 void show_list(struct node* p_list , const char* msg)
 {
    struct node* run = NULL;
    if(msg!=NULL)
    {
        puts(msg);
    }
    printf("[START]->");
    run=p_list->next;
    while(run!=NULL)
    {
        printf("[%d ]-> ",run->data);
        run=run->next;
    }
    printf("[END]\n");
 }
 //DISTROY LIST
 int destroy_list(struct node* p_list)
 {
    struct node* run = NULL;
    struct node* run_next = NULL;
    run=p_list;
    while(run!=NULL)
    {
        run_next = run->next;
        free(run);
        run=run_next;

    }
    return (SUCCESS);
 }