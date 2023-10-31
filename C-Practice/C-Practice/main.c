#include "stdio.h"
#include "stdlib.h"

struct Listnode {
    int data;
    struct Listnode* link;
};

struct Listnode* insert_first(struct Listnode* head, int value) {
    struct Listnode* p = (struct Listnode*)malloc(sizeof(struct Listnode));
    p -> data = value;
    p -> link = head;
    head = p;
    
    return head;
}

int main(void){
    struct Listnode* head = NULL;
    head = (struct Listnode*)malloc(sizeof(struct Listnode));
    head -> data = 2;
    head -> link = NULL;
    
    head = insert_first(head, 1);
    head = insert_first(head, 10);
    head = insert_first(head, 5);
    
    printf("%d -> ", head -> data);
    printf("%d -> ", head -> link -> data);
    printf("%d -> ", head -> link -> link -> data);
    printf("%d -> ", head -> link -> link -> link -> data);
}
