//#include "stdio.h"
//#include "stdlib.h"
//
//struct Listnode {
//    int data;
//    struct Listnode* link;
//};
//
//struct Listnode* insert_first(struct Listnode* head, int value) {
//    // p를 먼저 만들자.
//    struct Listnode* p = (struct Listnode*)malloc(sizeof(struct Listnode));
//    // p의 data 필드에 값을 넣는다.
//    p -> data = value;
//    // p의 link값에는 head를 향하게 두고
//    p -> link = head;
//    // head는 p를 향하게 둔다.
//    head = p;
//
//    return head;
//}
//
//struct Listnode* insert(struct Listnode* head, struct Listnode* pre, int value) {
//    // p를 먼저 만들자
//    struct Listnode* p = (struct Listnode*)malloc(sizeof(struct Listnode));
//    // p의 data필드에 값을 넣는다
//    p -> data = value;
//    // p의 link값에는 pre다음의 들어갈 link를 넣는다
//    p -> link = pre->link;
//    // pre의 link필드는 p에 넣어준다
//    pre->link = p;
//    return head;
//}
//
//struct Listnode* delete_first(struct Listnode* head) {
//    // 삭제할 너도를 저장할 removed를 생성
//    struct Listnode* removed = head;
//    // head의 link위치를 그 다음 node로 바꾸어준다
//    head = head -> link;
//    // free를 해준다
//    free(removed);
//
//    return head;
//}
//
//struct Listnode* delete(struct Listnode* head, struct Listnode* pre) {
//    // node removed
//    struct Listnode* removed = pre->link;
//
//    pre->link = pre->link->link;
//    free(removed);
//
//    return head;
//}
//
//
//void print_list(struct Listnode* head) {
//    //struct Listnode* p = head;
//    while (head != NULL) {
//        printf("%d -> ", head->data);
//        head = head->link;
//    }
//    printf("NULL\n");
//}
//
//int main(void) {
//    struct Listnode* head = NULL;
//    head = (struct Listnode*)malloc(sizeof(struct Listnode));
//    head->data = 1;
//    head->link = NULL;
//
//    head = insert_first(head, 2);
//    head = insert_first(head, 3);
//    head = insert_first(head, 4);
//    head = insert_first(head, 5);
//
//    print_list(head);
//    head = delete(head, head->link->link);
//
//    print_list(head);
//
//    return 0;
//}

//#include "stdio.h"
//#include "stdlib.h"
//
//struct Node {
//    int data;
//    struct Node* link;
//};
//
//struct Node* head = NULL;
//
//void insert_first(int value) {
//    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//    node -> data = value;
//
//    if(head == NULL) {
//        head = node;
//        node->link = node;
//    }
//    else {
//        node->link = head->link;
//        head->link = node;
//    }
//}
//
//void insert_last(int value) {
//    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//    node -> data = value;
//
//    if (head == NULL){
//        head = node;
//        node->link = head;
//    } else {
//        node->link = head->link;
//        head->link = node;
//        head = node;
//    }
//}
//
//void delete_first(void) {
//    struct Node* removed = head->link;
//    head->link = removed -> link;
//
//    free(removed);
//}
//
//void print_list(void) {
//    struct Node* node = head->link;
//
//    if(head == NULL) return;
//    do {
//        printf("%d -> ", node->data);
//        node = node->link;
//    } while(node != head->link);
//
//    printf("\n");
//}
//
//int main(void) {
//    insert_first(10);
//    insert_first(20);
//    insert_first(30);
//
//    print_list();
//
//    insert_last(40);
//
//    print_list();
//
//    delete_first();
//
//    print_list();
//
//    return 0;
//}

// 이중 연결 리스트

#include "stdio.h"
#include "stdlib.h"

//1. 노드 정의
struct Node {
    int data;
    struct Node* llink;
    struct Node* rlink;
};

struct Node* head;

void init(void) {
    head->rlink = head;
    head->llink = head;
}

void insert(struct Node* before, int value) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    
    new -> data = value;
    new -> llink = before;
    new -> rlink = before -> rlink;
    
    before -> rlink -> llink = new;
    before -> rlink = new;
}

void delete(struct Node* removed) {
    if(removed == head) return;
    
    removed -> llink -> rlink = removed -> rlink;
    removed -> rlink -> llink = removed -> llink;
    
    free(removed);
}

void print_list(struct Node* head) {
    struct Node* p;
    for (p = head->rlink; p != head; p = p->rlink) {
        printf("<- %d -> ", p->data);
    }
    printf("\n");
}

int main(void) {
    head = (struct Node*)malloc(sizeof(struct Node));
    init();
    
    printf("삽입 단계\n");
    for (int i = 0; i < 5; i++) {
        insert(head, i);
        print_list(head);
    }
    
    printf("\n삭제 단계\n");
    for (int i = 0; i < 5; i++) {
        delete(head -> rlink);
        print_list(head);
    }
    
    return 0;
}
