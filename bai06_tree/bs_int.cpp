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
		Node* q = p;
		delete q;
		p = NULL;
	}
}

void preOrder(BSTREE& p, int i)
{
	if (p != NULL)
	{
		displayNode(p, i);			// N
		preOrder(p->left, i + 3);	// L
		preOrder(p->right, i + 3);	// R
	}
}

void inOrder(BSTREE& p, int i)
{
	if (p != NULL)
	{
		inOrder(p->left, i + 3);	// L
		displayNode(p, i);			// N
		inOrder(p->right, i + 3);	// R
	}
}

void postOrder(BSTREE& p, int i)
{
	if (p != NULL)
	{
		postOrder(p->left, i + 3);	// L
		postOrder(p->right, i + 3); // R
		displayNode(p, i);			// N
	}
}

void insertNonRecursive(BSTREE& t, int x)
{
	if (t == NULL)
		t = createNode(x);
	else {
		Node* p = t;
		bool found = false;
		bool moving_left = false;
		Node* parent = NULL;
		while (p!= NULL && !found) {
			if (p->info > x)
			{
				parent = p;
				p = p->left;
				moving_left = true;
			} else if(p->info < x){ 
				parent = p;
				p = p->right;
				moving_left = false;
			}
			else {
				found = true;
				p->count++;
			}
		}
		if (!found) {
			p = createNode(x);
			if (moving_left)
				parent->left = p;
			else
				parent->right = p;
		}
	}
}

void insertRecursive(BSTREE& t, int x)
{
	if (t == NULL)
		t = createNode(x);
	else if (t->info > x)
		insertRecursive(t->left, x);
	else if (t->info < x)
		insertRecursive(t->right, x);
	else
		t->count++;
}

Node* findNonRecursive(BSTREE& t, int x) {
	Node* p = t;
	bool found = false;
	while (p != NULL && !found) {
		if (p->info > x)
			p = p->left;
		else if (p->info < x)
			p = p->right;
		else
			found = true;
	}
	return p;
}

void deleteNonRecursive(BSTREE& t, int x) {
	Node * p = t;
	Node* parent_p = NULL;
	bool found = false;
	bool moving_left = true;
	while (p != NULL && !found) {
		if (p->info < x) {
			parent_p = p;
			p = p->right;
			moving_left = false;
		}
		else if (p->info > x) {
			parent_p = p;
			p = p->left;
			moving_left = true;
		}
		else
			found = true;
	}
	if (found) {
		// p la nut la
		if (p->left == NULL && p->right == NULL) {
			if (p == t)
				t = NULL;
			else if (moving_left)
				parent_p->left = NULL;
			else
				parent_p->right = NULL;
			delete p;
		}
		else if (p->right == NULL) { // co con trai
			if (p == t)
				t = p->left;
			else if (moving_left)
				parent_p->left = p->left;
			else
				parent_p->right = p->left;
			delete p;
		}
		else if (p->left == NULL) { // co con phai
			if (p == t)
				t = p->right;
			else if (moving_left)
				parent_p->left = p->right;
			else
				parent_p->right = p->right;
			delete p;
		}
		else { // co 2 con
			Node* q = p->right;
			Node* parent_q = NULL;
			while (q->left != NULL) {
				parent_q = q;
				q = q->left;
			}
			// sao chep noi dung
			p->info = q->info;
			p->count = q->count;
			// dieu chinh tham chieu
			if (q == p->right)
				p->right = q->right;
			else
				parent_q->left = q->right;
			// huy q
			delete q;
		}
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

	printf("--- PreOrder ---\n");
	preOrder(tree, 0);
	printf("\n");

	printf("--- InOrder ---\n");
	inOrder(tree, 0);
	printf("\n");

	printf("--- PostOrder ---\n");
	postOrder(tree, 0);
	printf("\n");

	printf("\n");
	destroyTree(tree);
}

void test2()
{
	printf("---TEST2---\n");

	int a[] = { 15, 7, 20, 3, 17, 25, 10 };
	int n = sizeof(a) / sizeof(int);
	int x;
	Node* p;

	BSTREE tree;
	init(tree);

	for (int i = 0; i < n; i++)
		insertNonRecursive(tree, a[i]);
	printf("--- InOrder ---\n");
	inOrder(tree, 0);
	printf("\n");

	printf("--- Find ---\n");
	x = 17; p = findNonRecursive(tree, x);
	if (p == NULL)
		printf("Node {%d} khong tim thay!\n", x);
	else
		printf("Node {%d} tim thay!\n", p->info);

	x = 19; p = findNonRecursive(tree, x);
	if (p == NULL)
		printf("Node {%d} khong tim thay!\n", x);
	else
		printf("Node {%d} tim thay!\n", p->info);

	destroyTree(tree);
}

void test3()
{
	printf("---TEST3---\n");

	int a[] = { 64, 37, 10, 6, 0, 0, 0, 57, 0, 0, 78, 69, 67, 0, 0, 0, 82, 0, 93 }, n, i;
	n = sizeof(a) / sizeof(int);
	int x;

	BSTREE tree;
	init(tree);

	i = 0; createTree(tree, a, n, i);
	
	printf("Tree: \n");
	inOrder(tree, 0);
	printf("\n");

	x = 78; printf("Xoa nut {%d}: \n", x);
	deleteNonRecursive(tree, x);
	inOrder(tree, 0);
	printf("\n");

	x = 10; printf("Xoa nut {%d}: \n", x);
	deleteNonRecursive(tree, x);
	inOrder(tree, 0);
	printf("\n");

	x = 64; printf("Xoa nut {%d}: \n", x);
	deleteNonRecursive(tree, x);
	inOrder(tree, 0);
	printf("\n");

	destroyTree(tree);
}

int main()
{
	// test1();
	// test2();
	test3();
	return 0;
}