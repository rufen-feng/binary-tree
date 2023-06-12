#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

List* readlistfromfile(const char * filename) {
    int a;  
    List* list = NULL;
    FILE *file = fopen(filename,"r");
    char charval[10];

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }

    while (fscanf(file, "%d", &a) != EOF) { // loop until end of file
           if (list == NULL) {
		list = (List*) malloc(sizeof(List));
		list->next = NULL;
		list->value = a;
            } else {
		List *currentlist = list;
		while (currentlist->next != NULL) currentlist = currentlist->next;
		List *nextlist = (List*) malloc(sizeof(List));
		nextlist->next = NULL;
		nextlist->value = a;
		currentlist->next = nextlist;
	    }
	    
      }

    fclose(file);

    return list;
	
}
