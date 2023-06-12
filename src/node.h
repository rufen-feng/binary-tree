
typedef struct node Node;
struct node {
	Node* left;
	Node* right;
	int value;
};

int binarysearch(Node *root, int searchvalue);
Node * addnode(Node *root, int addvalue); 
void printnode(Node *root);
void printsinglenode(Node* root);
