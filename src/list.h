typedef struct list List;


struct list {
	List *next;
	int value;
};

List* readlistfromfile(const char * filename);
