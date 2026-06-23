#ifndef _LIST_H
#define _LIST_H

/*-------Header Files----------*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*-------Symbolic constants---------*/

enum Status{
    SUCCESS =               1;
    TRUE    =               1;
    FALSE   =               0;
    LIST_DATA_NOT_FOUND =   0;
    LIST_EMPTY          =   3;
};

/*----------Typedef-------*/

typedef int    data_t;
typedef int    len_t;
typedef enum   Status status_t;
typedef struct node node_t;
typedef node_t list_t;

/*-------Node layout definatio---------*/

struct node {
    data_t data;
    struct node* prev;
    struct node* next;
};

/*-------Declaration of interface function-----*/
//create_list() function
list_t* create_list(void);

//insertion functions
status_t insert_start(list_t* , p_list , data_t new_data);
status_t insert_end(list_t* , p_list , data_t new_data);
status_t insert_after(list_t* , p_list , data_t existing_data, data_t new_data);
status_t insert_before(list_t* , p_list, data_t exisitng_data, data_t new_data);

//get and pop functions
status_t get_start(list_t* , data_t* p_start_data);
status_t get_end(list_t* , data_t* p_end_data);
status_t pop_start(list_t* , data_t* p_start_data);
status_t pop_end(list_t* , data_t* p_end_data);

//remove functions
status_t remove_start(list_t* );
status_t remove_end(list_t* );
status_t remove_data(list_t* p_list, data_t_e_data);

//Misllanous functions
status_t find(list_t* , data_t search_data);
status_t is_list_empty(list_t* p_list);
len_t get_list_length(list_t* p_list);
void show(list_t* p_list, const char *msg);

//destroy list
status_t destroy_list(list_t** pp_list);

//helper functions
void generic_insert(node_t* start_node, node_t* mid_node, node_t* end_node);
void generic_delete(node_t* delete_node);
node_t* search_node(list_t* p_list , data_t search_data);
void* xmalloc(size_t size);

#endif