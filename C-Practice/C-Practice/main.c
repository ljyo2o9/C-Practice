#include<stdio.h>
#include<stdlib.h>

struct Treenode {
    int data;
    struct Treenode *left, *right;
};

void ino(struct Treenode* node){
    if(node != NULL){
        ino(node->left);
        printf("%d ", node->data);
        ino(node->right);
    }
}

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

struct Treenode* min_value(struct Treenode* node) {
    struct Treenode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct Treenode* delete(struct Treenode* node, int key) {
    if (node == NULL) return node;

    if (node->data > key) node->left = delete(node->left, key);
    else if (node->data < key) node->right = delete(node->right, key);
    else {
        if (node->left == NULL) {
            struct Treenode* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct Treenode* temp = node->left;
            free(node);
            return temp;
        }
        struct Treenode* temp = min_value(node->right);
        node->data = temp->data;
        node->right = delete(node->right, temp->data);
    }

    return node;
}

struct Treenode* insert(struct Treenode* node, int key) {
    if (node == NULL) return new_node(key);

    if (node->data > key) node->left = insert(node->left, key);
    else if (node->data < key) node->right = insert(node->right, key);

    return node;
}

int main(void){
    struct Treenode* tree = NULL;
    int n;
    
    while(1){
        printf("삽입 : ");
        scanf("%d", &n);
        if(n == 0) break;
        
        tree = insert(tree, n);
    }
    
    while (1) {
        printf("삭제 : ");
        scanf("%d", &n);
        if(n == 0) break;
        
        tree = delete(tree, n);
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
    
    printf("잘 들어갔나?? - ");
    ino(tree);
    printf("\n");

    return 0;
}
