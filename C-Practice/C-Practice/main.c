#include<stdio.h>
#include<stdlib.h>

struct Treenode {
    int data;
    struct Treenode *left, *right;
};

struct Treenode* search(struct Treenode* node, int key) {
    if (node == NULL) return NULL;
    if (key == node->data) return node;
    else if (key < node->data) return search(node -> left, key);
    else return search(node -> right, key);
}

struct Treenode* new_node(int key) {
    struct Treenode* new = (struct Treenode*)malloc(sizeof(struct Treenode));
    
    new -> data = key;
    new -> left = NULL;
    new -> right = NULL;
    
    return new;
}

struct Treenode* insert(struct Treenode* node, int key) {
    if (node == NULL) return new_node(key);

    if (node->data > key)
        node->left = insert(node->left, key);
    else if (node->data < key)
        node->right = insert(node->right, key);

    return node;
}

int main(void){
    struct Treenode* tree = NULL;
    int n;
    
    while(1){
        printf("삽입(0을 입력하면 원하는 값을 찾음) : ");
        scanf("%d", &n);
        if(n == 0) break;
        
        tree = insert(tree, n);
    }
    
    while(1){
        printf("찾고 싶은 값 : ");
        scanf("%d", &n);
        if(n == 0) break;
        
        if(search(tree, n) != NULL){
            printf("%d(는)은 있음\n", n);
        } else {
            printf("%d(는)은 없음\n", n);
        }
    }

    return 0;
}
