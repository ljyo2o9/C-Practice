#include<stdio.h>
#include<stdlib.h>

struct Treenode {
    int key;
    struct Treenode* left;
    struct Treenode* right;
};

struct Treenode* root = NULL;

//반환형이 있는 이유? 재귀함수 하면서 계속 node가 바뀌면서 이동해야 하기 때문에
struct Treenode* search(struct Treenode* node, int key) {
    if (node == NULL) return NULL;
    if (node->key > key)
        return search(node->left, key);
    else if (node->key < key)
        return search(node->right, key);
    else
        return node;
}

struct Treenode* newnode(int key) {
    struct Treenode* new = (struct Treenode*)malloc(sizeof(struct Treenode));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct Treenode* insert(struct Treenode* node, int key) {
    if (node == NULL) return newnode(key);
    if (node->key > key)
        node->left = insert(node->left, key);
    else if (node->key < key)
        node->right = insert(node->right, key);

    return node;
}

struct Treenode* min_value(struct Treenode* node) {
    struct Treenode* current = node;
    while (node->left != NULL) {
        current = current->left;
    }

    return current;
}

struct Treenode* delete(struct Treenode* node, int key) {
    if (node == NULL) return node;
    if (node->key > key)
        node->left = delete(node->left, key);
    else if (node->key < key)
        node->right = delete(node->right, key);
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
        node->key = temp->key;
        node->right = delete(node->right, temp->key);
    }
    return node;
}

void inorder(struct Treenode* root) {
    if (root) {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

int main(void) {
    root = insert(root, 30);          root = insert(root, 20);
    root = insert(root, 10);             root = insert(root, 40);
    root = insert(root, 50);             root = insert(root, 60);

    inorder(root);
    printf("\n\n");

    if (search(root, 30) != NULL) printf("30찾음!\n");
    else printf("30없음!\n");

    printf("\n");
    delete(root, 20);
    inorder(root);
    printf("\n");

    return 0;
}
