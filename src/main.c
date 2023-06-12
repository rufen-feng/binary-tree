#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "list.h"

int main(int argc, char* argv[]) {
	if(argc < 2) {
		printf(" use as bs filename, filename contains int values");
		return 1;
	}
	List *intvalues = readlistfromfile(argv[1]);
	Node *root = NULL;
	List *currentList = intvalues;
	while (currentList!=NULL) {
		root = addnode(root, currentList->value);
		currentList= currentList->next;
	}
	printnode(root);
	currentList = intvalues;
	while (currentList!=NULL) {
		printf(" find value %d\n %d\n" ,currentList->value, binarysearch(root, currentList->value));
		currentList= currentList->next;
	}
}

