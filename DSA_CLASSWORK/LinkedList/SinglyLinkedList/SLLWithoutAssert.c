#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

/* Create an Empty List with a head (dummy) */
struct node* Create_List(void){
    struct node* head = malloc(sizeof(struct node));
    if(!head){
        puts("Out of memory!");
        exit(EXIT_FAILURE);
    }
    head->data = 0;
    head->next = NULL;
    return head;
}

void show_List(struct node* head, const char* msg){
    if(msg){
        puts(msg);
        printf("[START]-->");
        struct node* it = head->next;
        while(it){
            printf("[%d]->", it->data);
            it = it->next;
        }
        printf("[END]\n");
    }
}

/* INSERT START */
void Insert_start(struct node* head, int data){
    struct node* n = malloc(sizeof(struct node));
    if(!n){
        puts("Out of Memory!");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->next = head->next;
    head->next = n;
}

/* INSERT END */
void Insert_end(struct node* head, int data){
    struct node* n = malloc(sizeof(struct node));
    if(!n){
        puts("Out of Memory!");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->next = NULL;

    struct node* it = head;
    while(it->next){
        it = it->next;
    }
    it->next = n;
}

/* INSERT AFTER */
int Insert_After(struct node* head, int After, int data){
    struct node* it = head->next;
    while(it){
        if(it->data == After){
            struct node* n = malloc(sizeof(struct node));
            if(!n){
                puts("Out of Memory!!");
                exit(EXIT_FAILURE);
            }
            n->data = data;
            n->next = it->next;
            it->next = n;
            return 1;
        }
        it = it->next;
    }
    return 0;
}

/* INSERT BEFORE */
int Insert_Before(struct node* head, int Before, int data){
    struct node* it = head;
    while(it->next){
        if(it->next->data == Before){
            struct node* n = malloc(sizeof(struct node));
            if(!n){
                puts("Out of Memory!!!!");
                exit(EXIT_FAILURE);
            }
            n->data = data;
            n->next = it->next;
            it->next = n;
            return 1;
        }
        it = it->next;
    }
    return 0;
}

/* GET START */
int get_start(struct node* head, int *out){
    if(!head->next){
        return 0;
    }
    *out = head->next->data;
    return 1;
}

/* GET END */
int get_End(struct node* head, int *out){
    if(!head->next){
        return 0;
    }
    struct node* it = head->next;
    while(it->next){
        it = it->next;
    }
    *out = it->data;
    return 1;
}

/* POP START */
int Pop_start(struct node* head, int *out){
    if(!head->next){
        return 0;
    }
    struct node* t = head->next;
    *out = t->data;
    head->next = t->next;
    free(t);
    t = NULL;
    return 1;
}

/* POP END */
int Pop_End(struct node* head, int *out){
    if(!head->next){
        return 0;
    }
    struct node* it = head;
    while(it->next && it->next->next){
        it = it->next;
    }
    struct node* t = it->next;
    *out = t->data;
    it->next = NULL;
    free(t);
    return 1;
}

/* REMOVE START */
int Remove_start(struct node* head){
    if(!head->next){
        return 0;
    }
    struct node* t = head->next;
    head->next = t->next;
    free(t);
    t = NULL;
    return 1;
}

/* REMOVE END */
int Remove_End(struct node* head){
    if(!head->next){
        return 0;
    }
    struct node* it = head;
    while(it->next && it->next->next){
        it = it->next;
    }
    struct node* t = it->next;
    it->next = NULL;
    free(t);
    return 1;
}

/* REMOVE DATA */
int Remove_data(struct node* head, int data){
    struct node* it = head;
    while(it->next){
        if(it->next->data == data){
            struct node* t = it->next;
            it->next = t->next;
            free(t);
            t = NULL;
            return 1;
        }
        it = it->next;
    }
    return 0;
}

/* FIND */
int Find(struct node* head, int data){
    struct node* it = head->next;
    while(it){
        if(it->data == data){
            return 1;
        }
        it = it->next;
    }
    return 0;
}

/* LENGTH */
int length(struct node* head){
    int count = 0;
    struct node* it = head->next;
    while(it){
        count++;
        it = it->next;
    }
    return count;
}

/* DESTROY LIST */
void Destroy_List(struct node* head){
    struct node* it = head->next;
    while(it){
        struct node* t = it;
        it = it->next;
        free(t);
    }
    head->next = NULL;
}

/* MAIN */
int main(void){
    struct node* list = Create_List();

    puts("Step 1: Create List And Show List");
    show_List(list, "List right after Creation:");

    Insert_start(list,10);
    Insert_start(list,20);
    Insert_start(list,30);
    show_List(list,"\nAfter insert Start Operation:");

    Insert_end(list,5);
    Insert_end(list,15);
    Insert_end(list,25);
    show_List(list,"\nAfter Insert_End Operation:");

    Insert_After(list,10,15);
    Insert_Before(list,5,1);
    show_List(list,"\nAfter Insertion:");

    int x;
    get_start(list,&x);
    printf("\nFirst Element : %d",x);

    get_End(list,&x);
    printf("\nLast Element : %d",x);

    Pop_start(list,&x);
    printf("\nPop From Start : %d",x);

    Pop_End(list,&x);
    printf("\nPop From End : %d\n",x);
    show_List(list,"\nAfter Poping:");

    Remove_start(list);
    Remove_End(list);
    Remove_data(list,10);
    show_List(list,"\nAfter Removal Function:");

    printf("Find 15 ? %s\n", Find(list,15) ? "YES" : "NO");
    printf("Length = %d\n", length(list));

    Destroy_List(list);
    show_List(list,"\nAfter Destroy List:");

    return 0;
}