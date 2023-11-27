#include<stdio.h>
#include<stdlib.h>

struct Treenode {
    int data;
    struct Treenode *left, *right;
};

struct Treenode n1 = { 1, NULL, NULL };
struct Treenode n2 = { 3, NULL, NULL };
struct Treenode n3 = { 6, NULL, NULL };
struct Treenode n4 = { 2, &n1, &n2 };
struct Treenode n5 = { 5, NULL, &n3 };
struct Treenode n6 = { 4, &n4, &n5 };
struct Treenode* root = &n6;

struct Treenode* search(struct Treenode* node, int key) {
    if (node == NULL) return NULL;
    if (key == node->data) return node;
    else if (key < node->data) return search(node -> left, key);
    else return search(node -> right, key);
}

int main(void){
    int n = 6;
    
    if (search(root, n) != NULL) {
        printf("%d은 찾을 수 있습니다.\n", n);
    } else {
        printf("%d은 찾을 수 없습니다.\n", n);
    }
    
    return 0;
}
