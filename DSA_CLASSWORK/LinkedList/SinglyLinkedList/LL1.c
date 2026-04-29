#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    int no;
    char name[20];
    struct node *next;
} ll;
//1. create node
ll* createNode(int no, char name[]) {
    ll *p = (ll*)malloc(sizeof(ll));
    p->no = no;
    strcpy(p->name, name);
    p->next = NULL;
    return p;
}
//2. display
void display(ll *head) {
    while (head) {
        printf("%d %s -> ", head->no, head->name);
        head = head->next;
    }
    printf("NULL\n");
}
//3. insert at end
ll* insertEnd(ll *head, int no, char name[]) {
    ll *p = createNode(no, name);
    if (!head) return p;
    ll *t = head;
    while (t->next) t = t->next;
    t->next = p;
    return head;
}
//4. insert at head
ll* insertHead(ll *head, int no, char name[]) {
    ll *p = createNode(no, name);
    p->next = head;
    return p;
}
//5. insert at position
ll* insertPos(ll *head, int pos, int no, char name[]) {
    if (pos == 1) return insertHead(head, no, name);
    ll *t = head;
    for (int i = 1; i < pos-1 && t; i++)
        t = t->next;
    if (!t) {
        printf("Invalid position\n");
        return head;
    }
    ll *p = createNode(no, name);
    p->next = t->next;
    t->next = p;
    return head;
}
//6. delete head
ll* deleteHead(ll *head) {
    if (!head) return NULL;
    ll *t = head;
    head = head->next;
    free(t);
    return head;
}
//7. delete end
ll* deleteEnd(ll *head) {
    if (!head) return NULL;
    if (!head->next) {
        free(head);
        return NULL;
    }
    ll *t = head;
    while (t->next->next)
        t = t->next;
    free(t->next);
    t->next = NULL;
    return head;
}
//8. delete position
ll* deletePos(ll *head, int pos) {
    if (pos == 1) return deleteHead(head);
    ll *t = head;
    for (int i = 1; i < pos-1 && t->next; i++)
        t = t->next;
    if (!t->next) {
        printf("Invalid position\n");
        return head;
    }
    ll *del = t->next;
    t->next = del->next;
    free(del);
    return head;
}
//9. search
void search(ll *head, int key) {
    while (head) {
        if (head->no == key) {
            printf("Found\n");
            return;
        }
        head = head->next;
    }
    printf("Not Found\n");
}
//10. alternate display
void alternate(ll *head) {
    while (head) {
        printf("%d %s\n", head->no, head->name);
        if (!head->next) break;
        head = head->next->next;
    }
}
//11. reverse display
void reverse(ll *head) {
    if (!head) return;
    reverse(head->next);
    printf("%d %s\n", head->no, head->name);
}
//12. swap consecutive
void swap(ll *head) {
    while (head && head->next) {
        ll *q = head->next;
        int t = head->no;
        head->no = q->no;
        q->no = t;
        char temp[20];
        strcpy(temp, head->name);
        strcpy(head->name, q->name);
        strcpy(q->name, temp);
        head = q->next;
    }
}
//13. sort
void sort(ll *head) {
    for (ll *i = head; i; i = i->next)
        for (ll *j = i->next; j; j = j->next)
            if (i->no > j->no) {
                int t = i->no;
                i->no = j->no;
                j->no = t;
                char temp[20];
                strcpy(temp, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp);
            }
}
//14. insert after data
ll* insertAfter(ll *head, int key, int no, char name[]) {
    for (ll *t = head; t; t = t->next) {
        if (t->no == key) {
            ll *p = createNode(no, name);
            p->next = t->next;
            t->next = p;
            return head;
        }
    }
    printf("Data not found\n");
    return head;
}
//15. insert before data
ll* insertBefore(ll *head, int key, int no, char name[]) {
    if (head->no == key)
        return insertHead(head, no, name);

    ll *t = head;
    while (t->next && t->next->no != key)
        t = t->next;

    if (!t->next) {
        printf("Data not found\n");
        return head;
    }
    ll *p = createNode(no, name);
    p->next = t->next;
    t->next = p;
    return head;
}
//16. delete by data
ll* deleteData(ll *head, int key) {
    if (head->no == key)
        return deleteHead(head);

    ll *t = head;
    while (t->next && t->next->no != key)
        t = t->next;

    if (!t->next) {
        printf("Not found\n");
        return head;
    }
    ll *del = t->next;
    t->next = del->next;
    free(del);
    return head;
}
// main menu
int main() {
    ll *head = NULL;
    int ch, no, pos, key;
    char name[20];
    do {
        printf("\n1.Insert Node\n2.Display\n3.Insert Head\n4.Insert Pos\n5.Delete Head\n6.Delete End\n7.Delete Pos\n8.Search\n9.Alternate\n10.Reverse\n11.Swap\n12.Sort\n13.Insert After\n14.Insert Before\n15.Delete by Data\n0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d %s", &no, name);
                head = insertEnd(head, no, name);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d %s", &no, name);
                head = insertHead(head, no, name);
                break;
            case 4:
                printf("Enter pos, data: ");
                scanf("%d %d %s", &pos, &no, name);
                head = insertPos(head, pos, no, name);
                break;
            case 5:
                head = deleteHead(head);
                break;
            case 6:
                head = deleteEnd(head);
                break;
            case 7:
                printf("Enter pos: ");
                scanf("%d", &pos);
                head = deletePos(head, pos);
                break;
            case 8:
                printf("Enter key: ");
                scanf("%d", &key);
                search(head, key);
                break;
            case 9:
                alternate(head);
                break;
            case 10:
                reverse(head);
                break;
            case 11:
                swap(head);
                break;
            case 12:
                sort(head);
                break;
            case 13:
                printf("Enter key then new data: ");
                scanf("%d %d %s", &key, &no, name);
                head = insertAfter(head, key, no, name);
                break;
            case 14:
                printf("Enter key then new data: ");
                scanf("%d %d %s", &key, &no, name);
                head = insertBefore(head, key, no, name);
                break;
            case 15:
                printf("Enter key: ");
                scanf("%d", &key);
                head = deleteData(head, key);
                break;
        }
    } while (ch != 0);
    return 0;
}