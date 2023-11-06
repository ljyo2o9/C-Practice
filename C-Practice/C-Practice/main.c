#include "stdio.h"
#include "stdlib.h"

struct Listnode {
    int data;
    struct Listnode* link;
};

struct Listnode* insert_first(struct Listnode* head, int value) {
    // p를 먼저 만들자.
    struct Listnode* p = (struct Listnode*)malloc(sizeof(struct Listnode));
    // p의 data 필드에 값을 넣는다.
    p -> data = value;
    // p의 link값에는 head를 향하게 두고
    p -> link = head;
    // head는 p를 향하게 둔다.
    head = p;
    
    return head;
}

struct Listnode* insert(struct Listnode* head, struct Listnode* pre, int value) {
    // p를 먼저 만들자
    struct Listnode* p = (struct Listnode*)malloc(sizeof(struct Listnode));
    // p의 data필드에 값을 넣는다
    p -> data = value;
    // p의 link값에는 pre다음의 들어갈 link를 넣는다
    p -> link = pre->link;
    // pre의 link필드는 p에 넣어준다
    pre->link = p;
    return head;
}

struct Listnode* delete_first(struct Listnode* head) {
    // 삭제할 너도를 저장할 removed를 생성
    struct Listnode* removed = head;
    // head의 link위치를 그 다음 node로 바꾸어준다
    head = head -> link;
    // free를 해준다
    free(removed);
    
    return head;
}

struct Listnode* delete(struct Listnode* head, struct Listnode* pre) {
    // node removed
    struct Listnode* removed = pre->link;
    
    pre->link = pre->link->link;
    free(removed);
    
    return head;
}


void print_list(struct Listnode* head) {
    //struct Listnode* p = head;
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("NULL\n");
}

int main(void) {
    struct Listnode* head = NULL;
    head = (struct Listnode*)malloc(sizeof(struct Listnode));
    head->data = 2;
    head->link = NULL;
    
    head = insert_first(head, 1);
    head = insert_first(head, 10);
    head = insert_first(head, 10);
    head = insert_first(head, 5);
    head = insert_first(head, 5);
    head = insert(head, head->link, 8);
    
    head = delete_first(head);
    head = delete_first(head);
    head = delete_first(head);
    
    print_list(head);
    
    head = insert_first(head, 5);
    head = insert_first(head, 5);
    head = delete(head, head);
    head = delete(head, head);
    
    print_list(head);
    return 0;
}
