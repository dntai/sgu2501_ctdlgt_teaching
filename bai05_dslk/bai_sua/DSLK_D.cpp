// Author: Nguyen Gia Bao
#include <iostream>
using namespace std;
struct Node {
	int info;
	Node* next;
};
struct ListInt {
	Node* pHead;
	Node* pTail;
};

void init(ListInt& lst)
{
	lst.pHead = lst.pTail = NULL;
}

bool isEmty(ListInt& lst)
{
	return lst.pTail == NULL;
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
	ListInt lista;
	init(lista);
	if (n > 0) {
		Node* p = CreateNode(a[0]);
		lista.pHead = lista.pTail = p;
		for (int i = 1; i < n; i++)
		{
			p = CreateNode(a[i]);
			lista.pTail->next = p;
			lista.pTail = p;
		}
	}
	return lista;
}

void Showlist(ListInt list)
{
	for (Node* p = list.pHead; p != NULL; p = p->next)
	{
		printf("%d", p->info);
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