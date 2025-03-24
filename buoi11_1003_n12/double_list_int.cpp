#include <iostream>
using namespace std;

typedef struct node
{
    int info;
    struct node* next;
    struct node* prev;
} Node;

struct DoubleListInt
{
    Node *pHead, *pTail;
};

void init(DoubleListInt &list)
{
    list.pHead = list.pTail = NULL;
}

bool  isEmpty(DoubleListInt &list)
{
    return list.pHead == NULL;
}

Node* createNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

DoubleListInt make_data(int a[], int n)
{
    DoubleListInt list;
    init(list);
    if(n>0)
    {
        Node *p = createNode(a[0]);
        list.pHead = list.pTail = p;
        for(int i=1; i<n; i++)
        {
            p = createNode(a[i]);
            list.pTail->next = p;
            p->prev = list.pTail;
            list.pTail = p;
        }
    }
    return list;
}

void ShowList(DoubleListInt list)
{
    for(Node *p = list.pHead; p!= NULL; p = p->next)
    {
        printf("%d ", p->info);
    }
}

void ShowRevList(DoubleListInt list)
{
    Node *p = list.pTail;
    while(p != NULL)
    {
        printf("%d ", p->info);
        p = p->prev;
    }
}

void ClearList(DoubleListInt &list)
{
    while(list.pHead != NULL)
    {
        Node *p = list.pHead;
        list.pHead = list.pHead->next;
        delete p;
    }
}

void insertOrder(DoubleListInt &list, int x)
{
    Node *p = createNode(x);
    if(isEmpty(list)) {
        list.pHead = list.pTail = p;
    } else {
        Node *tq = NULL;
        Node *q  = list.pHead;
        bool cont = true;
        while( q!=NULL && cont)
        {
            if(q->info <= x) {
                q = q->next;
                tq = q;
            } else 
                cont = false;
        }
        if(list.pHead == q)// [1] -> | 2, 5, 8, 8, 10
        {
            p->next = list.pHead;
            list.pHead->prev = p;
            list.pHead = p;
        } else if(q == NULL) { // [11] --> 2, 5, 8, 8, 10 |
            list.pTail->next = p;
            p->prev = list.pTail;
            list.pTail = p;
        } else { // [8] --> 2, 5, 8, 8| 10
            p->next = tq->next;
            p->prev = tq;
            tq->next = p;
            tq->next->prev = p;   
        }

    }
}

void test1()
{
    printf("--- TEST1 --- \n");
    int a[] = {2, 5, 8, 10}, n = 4;

    DoubleListInt list1;
    init(list1);
    if(isEmpty(list1) == true)
        printf("Danh sach rong!\n");
    else
        printf("Danh sach khac rong!\n");
    list1 = make_data(a, n);
    printf("Danh sach: "); 
    ShowList(list1);
    printf("\n");
    printf("Danh sach (nguoc): "); 
    ShowRevList(list1);
    printf("\n");

    int a1[] = {2}, n1 = 1;
    DoubleListInt lista1 = make_data(a1, n1);
    printf("Danh sach a1: "); ShowList(lista1);printf("\n");
    insertOrder(lista1, 1);
    printf("--> Danh sach a1: "); ShowList(lista1);printf("\n");

    ClearList(lista1);
    init(lista1);
    lista1 = make_data(a1, n1);
    printf("Danh sach a2: "); ShowList(lista1);printf("\n");
    insertOrder(lista1, 10);
    printf("--> Danh sach a2: "); ShowList(lista1);printf("\n");

    printf("\n");
    ClearList(list1);
    ClearList(lista1);
}

int main()
{
    test1();
    return 0;
}