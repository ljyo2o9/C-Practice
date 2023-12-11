//#include<stdio.h>
//#include<stdlib.h>
//
//struct Treenode {
//    int data;
//    struct Treenode *left, *right;
//};
//
//void ino(struct Treenode* node){
//    if(node != NULL){
//        ino(node->left);
//        printf("%d ", node->data);
//        ino(node->right);
//    }
//}
//
//struct Treenode* search(struct Treenode* node, int key) {
//    if (node == NULL) return NULL;
//    if (key == node->data) return node;
//    else if (key < node->data) return search(node -> left, key);
//    else return search(node -> right, key);
//}
//
//struct Treenode* new_node(int key) {
//    struct Treenode* new = (struct Treenode*)malloc(sizeof(struct Treenode));
//    
//    new -> data = key;
//    new -> left = NULL;
//    new -> right = NULL;
//    
//    return new;
//}
//
//struct Treenode* min_value(struct Treenode* node) {
//    struct Treenode* current = node;
//    while (current->left != NULL) {
//        current = current->left;
//    }
//
//    return current;
//}
//
//struct Treenode* delete(struct Treenode* node, int key) {
//    if (node == NULL) return node;
//
//    if (node->data > key) node->left = delete(node->left, key);
//    else if (node->data < key) node->right = delete(node->right, key);
//    else {
//        if (node->left == NULL) {
//            struct Treenode* temp = node->right;
//            free(node);
//            return temp;
//        }
//        else if (node->right == NULL) {
//            struct Treenode* temp = node->left;
//            free(node);
//            return temp;
//        }
//        struct Treenode* temp = min_value(node->right);
//        node->data = temp->data;
//        node->right = delete(node->right, temp->data);
//    }
//
//    return node;
//}
//
//struct Treenode* insert(struct Treenode* node, int key) {
//    if (node == NULL) return new_node(key);
//
//    if (node->data > key) node->left = insert(node->left, key);
//    else if (node->data < key) node->right = insert(node->right, key);
//
//    return node;
//}
//
//int main(void){
//    struct Treenode* tree = NULL;
//    int n;
//    
//    while(1){
//        printf("삽입 : ");
//        scanf("%d", &n);
//        if(n == 0) break;
//        
//        tree = insert(tree, n);
//    }
//    
//    while (1) {
//        printf("삭제 : ");
//        scanf("%d", &n);
//        if(n == 0) break;
//        
//        tree = delete(tree, n);
//    }
//    
//    while(1){
//        printf("찾고 싶은 값 : ");
//        scanf("%d", &n);
//        if(n == 0) break;
//        
//        if(search(tree, n) != NULL){
//            printf("%d(는)은 있음\n", n);
//        } else {
//            printf("%d(는)은 없음\n", n);
//        }
//    }
//    
//    printf("잘 들어갔나?? - ");
//    ino(tree);
//    printf("\n");
//
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//struct Treenode {
//    int key;
//    struct Treenode* left;
//    struct Treenode* right;
//};
//
//struct Treenode* root = NULL;
//
////반환형이 있는 이유? 재귀함수 하면서 계속 node가 바뀌면서 이동해야 하기 때문에
//struct Treenode* search(struct Treenode* node, int key) {
//    if (node == NULL) return NULL;
//    if (node->key > key)
//        return search(node->left, key);
//    else if (node->key < key)
//        return search(node->right, key);
//    else
//        return node;
//}
//
//struct Treenode* newnode(int key) {
//    struct Treenode* new = (struct Treenode*)malloc(sizeof(struct Treenode));
//    new->key = key;
//    new->left = NULL;
//    new->right = NULL;
//    return new;
//}
//
//struct Treenode* insert(struct Treenode* node, int key) {
//    if (node == NULL) return newnode(key);
//    if (node->key > key)
//        node->left = insert(node->left, key);
//    else if (node->key < key)
//        node->right = insert(node->right, key);
//
//    return node;
//}
//
//struct Treenode* min_value(struct Treenode* node) {
//    struct Treenode* current = node;
//    while (node->left != NULL) {
//        current = current->left;
//    }
//
//    return current;
//}
//
//struct Treenode* delete(struct Treenode* node, int key) {
//    if (node == NULL) return node;
//    if (node->key > key)
//        node->left = delete(node->left, key);
//    else if (node->key < key)
//        node->right = delete(node->right, key);
//    else {
//        if (node->left == NULL) {
//            struct Treenode* temp = node->right;
//            free(node);
//            return temp;
//        }
//        else if (node->right == NULL) {
//            struct Treenode* temp = node->left;
//            free(node);
//            return temp;
//        }
//        struct Treenode* temp = min_value(node->right);
//        node->key = temp->key;
//        node->right = delete(node->right, temp->key);
//    }
//    return node;
//}
//
//void inorder(struct Treenode* root) {
//    if (root) {
//        inorder(root->left);
//        printf("[%d] ", root->key);
//        inorder(root->right);
//    }
//}
//
//int main(void) {
//    root = insert(root, 30);          root = insert(root, 20);
//    root = insert(root, 10);             root = insert(root, 40);
//    root = insert(root, 50);             root = insert(root, 60);
//
//    inorder(root);
//    printf("\n\n");
//
//    if (search(root, 30) != NULL) printf("30찾음!\n");
//    else printf("30없음!\n");
//
//    printf("\n");
//    delete(root, 20);
//    inorder(root);
//    printf("\n");
//
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack* link;
};

struct stack* top = NULL;

int is_empty(void){
    return top == NULL;
}

void push(int item){
    struct stack* node = (struct stack*)malloc(sizeof(struct stack));
    node->data = item;
    node->link = top;
    top = node;
}

int pop(void){
    if(is_empty()){
        printf("is_empty에러");
        return -9999;
    }
    struct stack* removed = top;
    top = top->link;
    int item = top->data;
    free(removed);
    return item;
}

void print_stack(void){
    struct stack* tmp = top;
    while(tmp != NULL){
        printf("%d -> ", tmp->data);
        tmp = tmp->link;
    }
    printf("NULL\n");
}

int main(void){
    push(1);
    push(2);
    push(2);
    push(2);
    push(2);
    push(4);
    print_stack();
    pop();
    print_stack();
    
    return 0;
}
