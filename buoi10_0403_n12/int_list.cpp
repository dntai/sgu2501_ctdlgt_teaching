#include <iostream>
using namespace std;

typedef struct node
{
    int info;
    struct node *next;
} Node;

Node *pHead = NULL;

bool isEmpty(Node* pHead){
    return (pHead == NULL);
}

void init(Node* &pHead){
    pHead = NULL;
}

Node* createNode(int x){
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void ShowList(Node* pHead){
    if(pHead == NULL)
        printf("Danh sach rong\n");
    else {
        Node *p = pHead;
        while(p != NULL){
            printf("%d ", p->info);
            p = p->next;
        }
    }
}

void ShowList1(Node* pHead){
    if(pHead == NULL)
        printf("Danh sach rong\n");
    else {
        for(Node *p=pHead; p != NULL; p = p->next){
            printf("%d ", p->info);
        }
    }
}

void insertFirst(Node* &pHead, int x){
    Node *p = createNode(x);
    p->next = pHead;
    pHead = p;
}

void test1()
{
    printf("--- Test1 ---\n");
    
    Node *pHead;
    init(pHead);
    if(isEmpty(pHead))
        printf("List bi rong");
    else
        printf("List co phan tu");
    printf("\n");
}

void test2()
{
    printf("--- Test2 ---\n");
    int a[] = {2, 5, 4, 2, 1, 8}, n = 6;
    
    Node *pHead;
    init(pHead);
    for(int i=0; i<n; i++)
    {
        insertFirst(pHead, a[i]);
    }
    printf("Noi dung danh sach: ");
    ShowList(pHead);
    printf("\n\n");
}

int main()
{
    test1();
    test2();
    return 0;
}