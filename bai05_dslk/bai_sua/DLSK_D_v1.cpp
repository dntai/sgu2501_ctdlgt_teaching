// Author: Nguyen Gia Bao
#include <iostream>
using namespace std;
typedef struct node {
	int info;
	struct node* next;
} Node;

typedef Node* ListInt;

void init(ListInt& p)
{
	p = NULL;
}

bool isEmty(ListInt& p)
{
	return p == NULL;
}

Node* CreateNode(int x)
{
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

ListInt MakeData(int a[], int n)
{
	ListInt lst;
	init(lst);
	if (n > 0) {
		Node* p = CreateNode(a[0]);
		Node* last;
		lst = p;
		last = p;
		for (int i = 1; i < n; i++)
		{
			p = CreateNode(a[i]);
			last->next = p;
			last = p;
		}
	}
	return lst;
}

void Showlist(ListInt lst)
{
	for (Node* p = lst; p != NULL; p = p->next)
	{
		printf("%d ", p->info);
	}
}

void test1()
{
	printf("---TEST1---\n");
	int a[] = { 2,5,8,10 }, n = 4;
	ListInt list1;
	init(list1);
	if (isEmty(list1) == true)
	{
		printf("Danh sach rong!\n");
	}
	else
	{
		printf("Danh sach khac rong!\n");
	}
	list1 = MakeData(a, n);
	printf("Danh sach: "); Showlist(list1);
	printf("\n");
}

int main()
{
	test1();

	return 0;
}