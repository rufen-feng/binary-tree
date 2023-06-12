#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node* addnode(Node *root, int value) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    } else if (value < root->value) {
        root->left = addnode(root->left, value);
    } else {
        root->right = addnode(root->right, value);
    }
    return root;
}  //把createnode 和addnode放在一起

void printsinglenode(Node* root) {
    printf("\n current node:  %d \n", root->value);
}

void printnode(Node *root) {
    if (root == NULL) {
        return;
    } else {
        printsinglenode(root);
        if (root->left != NULL ) {
            printf("\n print left\t ");
            printnode(root->left);
        }
        if (root->right != NULL ) {
            printf("\n print right\t ");
            printnode(root->right);
        }
    }
}

int main() {
    Node *root = NULL;
    root = addnode(root, 4);
    root = addnode(root, 2);
    root = addnode(root, 6);
    root = addnode(root, 1);
    root = addnode(root, 3);
    root = addnode(root, 5);
    root = addnode(root, 7);
    printnode(root);
    return 0;
}

