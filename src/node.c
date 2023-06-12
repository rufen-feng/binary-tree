#include "node.h"
#include <stdio.h>
#include <stdlib.h>

int binarysearch(Node *root, int searchvalue) {
	if (root == NULL) return 1;
	if (root->value == searchvalue) {
		printf("\nfind value %d\n\n", searchvalue);
		printnode(root);
		return 0;
	}
	if (root->value < searchvalue) {
		if (root->right != NULL ) {
			printf("\ncurrent value  %d searchvalue %d try right\n\n", root->value, searchvalue);
			return binarysearch(root->right, searchvalue);
		}		
	}
	if (root->value > searchvalue) {
		if (root->left != NULL ) {
			printf("\ncurrent value  %d searchvalue %d try left \n\n", root->value, searchvalue);
			return binarysearch(root->left , searchvalue); 
		}
	}
}


Node * addnode(Node *root, int addvalue) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->left = NULL;
                root->right = NULL;
		printf("\n added to value %d\n\n", addvalue); 
		root->value = addvalue;
	} else if (root->value < addvalue) {
		printf("\n add to right %d\n\n", addvalue); 
		root->right = addnode(root->right, addvalue);
	} else if (root->value > addvalue) {
		printf("\n add to  left %d\n\n", addvalue); 
		root->left = addnode(root->left, addvalue);
	}
	return root;
}
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

