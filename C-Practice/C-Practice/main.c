#include "stdio.h"
#include "stdlib.h"

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode n1 = { 4, NULL, NULL };
struct TreeNode n2 = { 5, NULL, NULL };
struct TreeNode n3 = { 6, NULL, NULL };
struct TreeNode n4 = { 2, &n1, &n2 };
struct TreeNode n5 = { 3, NULL, &n3 };
struct TreeNode n6 = { 1, &n4, &n5 };
struct TreeNode* root = &n6;

void ino(struct TreeNode* root) {
    if (root != NULL) {
        ino(root->left);
        printf("%d", root->data);
        ino(root->right);
    }
}

void pre(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d", root->data);
        pre(root->left);
        pre(root->right);
    }
}

void pos(struct TreeNode* root) {
    if (root != NULL) {
        pos(root->left);
        pos(root->right);
        printf("%d", root->data);
    }
}

int main(void) {
    printf("중위 순회 = ");
    ino(root);
    printf("\n");

    printf("전위 순회 = ");
    pre(root);
    printf("\n");

    printf("후위 순회 = ");
    pos(root);
    printf("\n");

    return 0;
}
