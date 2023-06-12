#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

//为结构体类型起了一个别名 Node 和直接在struct 后括号后面加 Node一样
typedef struct node Node; 

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}   //按中序遍历（左->根->右）输出树中的值

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    return 0;
}   //在主函数中创建一个空树，向树中插入七个值，然后按中序遍历输出树中的值
