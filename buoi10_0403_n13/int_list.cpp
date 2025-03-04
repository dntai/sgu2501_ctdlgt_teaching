#include <iostream>
using namespace std;

typedef struct node
{
    int info;
    struct node* next;
} Node;

void init(Node* &pHead){
    pHead = NULL;
}

bool isEmpty(Node* pHead){
    return (pHead == NULL);
}

Node* createNode(int x){
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

Node* test_data(int a[], int n){
    Node *pHead = NULL;
    if(n>0)
    {
        pHead = createNode(a[0]);
        Node *p = pHead;
        for(int i=1; i<n; i++)
        {
            p->next = createNode(a[i]);
            p = p->next;
        }
    }
    return pHead;
}

void ShowList(Node* pHead){
    if(pHead == NULL){
        printf("Danh sach rong");
    } else {
        Node *p = pHead;
        while(p!=NULL){
            printf("%d ", p->info);
            p = p->next;
        }
    }
}

void ClearList(Node* &pHead){
    while(pHead != NULL){
        Node* p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

void ShowList1(Node* pHead){
    if(pHead == NULL){
        printf("Danh sach rong");
    } else {
        for(Node *p=pHead; p!=NULL; p = p->next){
            printf("%d ", p->info);
        }
    }
}

Node *Find(Node* pHead, int x){
    bool found = false;
    Node *p = pHead;
    while( p!= NULL && !found){
        if(p->info == x){
            found = true;
        } else {
            p = p->next;
        }
    }
    if(!found)
        p = NULL;
    return p;
}

void InsertFirst(Node* &pHead, int x){
    Node *p = createNode(x);
    p->next = pHead;
    pHead = p;
}

void InsertAfter(Node *p, int x){
    if(p!=NULL){
        Node *q = createNode(x);
        q->next = p->next;
        p->next = q;
    }
}

void test1()
{
    printf("--- TEST1 --- \n");
    int a[] = {2, 5, 8, 10}, n = 4;

    Node *list1;
    init(list1);
    if(isEmpty(list1))
        printf("Danh sach rong\n");
    else
        printf("Danh sach khac rong\n");
    list1 = test_data(a, n);
    if(isEmpty(list1))
        printf("Danh sach rong\n");
    else
        printf("Danh sach khac rong\n");
    printf("Danh sach: ");
    ShowList(list1);
    printf("\n\n");

    ClearList(list1);
}

void test2()
{
    printf("--- TEST2 --- \n");
    int a[] = {2, 6, 10, 14, 8, 9}, n = 6;
    int x;
    Node *p;

    Node *list1 = test_data(a, n);
    printf("Danh sach: ");
    ShowList(list1);
    printf("\n");

    x = 14;
    p = Find(list1, x);
    if(p == NULL)
        printf("Gia tri %d khong tim thay!\n", x);
    else 
    printf("Gia tri %d tim thay!\n", p->info);
    printf("\n");

    x = 5;
    p = Find(list1, x);
    if(p == NULL)
        printf("Gia tri %d khong tim thay!\n", x);
    else 
    printf("Gia tri %d tim thay!\n", p->info);
    printf("\n");

    ClearList(list1);
}

void test3()
{
    printf("--- TEST3 --- \n");
    int a[] = {2, 6, 10, 14, 8, 9}, n = 6;
    int x, y;
    Node *p;

    Node *list1 = test_data(a, n);
    printf("Danh sach: ");
    ShowList(list1);
    printf("\n");

    x = 7;
    InsertFirst(list1, x);
    printf("Danh sach: ");
    ShowList(list1);
    printf("\n");

    x = 10; y = 20;
    p = Find(list1, x);
    InsertAfter(p, y);
    printf("Danh sach: ");
    ShowList(list1);
    printf("\n");

    int b[] = {2, 5, 8, 10}, m = 4;
    x = 6;

    Node *list2;
    list2 = test_data(b, m);
    printf("Danh sach: ");
    ShowList(list2);
    printf("\n");

    ClearList(list1);
    ClearList(list2);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}