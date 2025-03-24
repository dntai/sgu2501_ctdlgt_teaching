#include <iostream>
using namespace std;
typedef struct node {
	int info;			// chua khoa, va thong tin
	int count;
	struct node* left;  // info(left) < info(node) < info(right)
	struct node* right;
} Node;
typedef Node* BSTREE;

void init(BSTREE& root)
{
	root = NULL;
}

bool isEmty(BSTREE root)
{
	return root == NULL;
}

Node* createNode(int x, Node* left=NULL, Node *right=NULL)
{
	Node* p = new Node;
	p->info = x;
	p->count = 1;
	p->left  = left;
	p->right = right;
	return p;
}

void displayNode(Node* p, int i) {
	for (int j = 0; j < i; j++)// space indent i
		printf(" ");
	printf("%3d\n", p->info);
}

void createTree(BSTREE& p, int a[], int& n, int& i) {
	if (i < n) {
		if (a[i] == 0)
			p = NULL;
		else
		{
			p = createNode(a[i]);    	    // N
			i++;
			createTree(p->left, a, n, i);   // L
			i++;
			createTree(p->right, a, n, i);  // R
		}
	}
}

void destroyTree(BSTREE& p)
{
	if (p != NULL)
	{
		destroyTree(p->left);
		destroyTree(p->right);
	}
}

void preOder(BSTREE& p, int i)
{
	if (p != NULL)
	{
		displayNode(p, i);
		preOder(p->left, i + 3);
		preOder(p->right, i + 3);
	}
}

void test1()
{
	printf("---TEST1---\n");
	int a[] = { 64, 37, 10, 6, 0, 0, 0, 57, 0, 0, 78, 69, 67, 0, 0, 0, 82, 0, 93 }, n, i;
	n = sizeof(a) / sizeof(int);
	BSTREE tree;
	init(tree);
	i = 0; createTree(tree, a, n, i);
	preOder(tree, 0);
	printf("\n");
}

int main()
{
	test1();

	return 0;
}