#include <iostream>
using namespace std;

typedef struct node
{
    int info;
    struct node *prev;
    struct node *next;
} Node;

struct ListInt
{
    node *pHead, *pLast;
};

void init(ListInt* pList)
{
    pList->pHead = NULL;
    pList->pLast = NULL;
}

bool isEmpty(ListInt *pList)
{
    return pList->pHead == NULL;
}

Node* createNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insertFirst(ListInt &list, int x)
{
    Node *p = createNode(x);
    if(isEmpty(&list))
    {
        list.pHead = p;
        list.pLast = p;
    } 
    else
    {
        p->next = list.pHead;
        list.pHead->prev = p;
        list.pHead = p;
    }
}

void insertLast(ListInt &list, int x)
{
    Node *p = createNode(x);
    if(isEmpty(&list))
    {
        list.pHead = p;
        list.pLast = p;
    } 
    else
    {
        list.pLast->next = p;
        p->prev = list.pLast;
        list.pLast = p;
    }
}

ListInt test_data(int a[], int n){
    ListInt list;
    init(&list);
    if(n>0)
    {
        list.pHead = createNode(a[0]);
        list.pLast = list.pHead; 
        Node *p = list.pHead;
        for(int i=1; i<n; i++)
        {
            Node *q = createNode(a[i]);
            p->next = q;
            q->prev = p;
            p = p->next;
            list.pLast = p;
        }
    }
    return list;
}

void ShowList(ListInt &list){
    if(list.pHead == NULL){
        printf("Danh sach rong");
    } else {
        Node *p = list.pHead;
        while(p!=NULL){
            printf("%d ", p->info);
            p = p->next;
        }
    }
}

void ShowRevList(ListInt &list){
    if(list.pHead == NULL){
        printf("Danh sach rong");
    } else {
        Node *p = list.pLast;
        while(p!=NULL){
            printf("%d ", p->info);
            p = p->prev;
        }
    }
}

void ClearList(ListInt &list){
    while(list.pHead != NULL){
        Node* p = list.pHead;
        list.pHead = list.pHead->next;
        delete p;
    }
    list.pHead = NULL;
    list.pLast = NULL;
}

void test1()
{
    printf("--- TEST1 --- \n");
    int a[] = {2, 5, 8, 10}, n = 4;

    ListInt list1;
    init(&list1);
    if(isEmpty(&list1))
        printf("Danh sach rong\n");
    else
        printf("Danh sach khac rong\n");
    list1 = test_data(a, n);
    if(isEmpty(&list1))
        printf("Danh sach rong\n");
    else
        printf("Danh sach khac rong\n");
    printf("+ Danh sach thuan: ");
    ShowList(list1);
    printf("\n");
    printf("+ Danh sach nguoc: ");
    ShowRevList(list1);
    printf("\n");

    ClearList(list1);
}

int main(){
    test1();
    return 0;
}