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

void insertAfter(Node* p, int x){
    if(p!=NULL){
        Node *q = createNode(x);
        q->next = p->next;
        p->next = q;
    }
}

void insertOrder(Node *&pHead, int x){
    Node *tp = NULL;
    Node *p = pHead;
    bool cont = true;
    while((p!=NULL) && cont){
        if(p->info < x){
            tp = p;
            p = p->next;
        } else cont = false;
    }
    if(p == pHead)
        insertFirst(pHead, x);
    else
        insertAfter(tp, x);
}

Node* find(Node* pHead, int x){
    bool found = false;
    Node *p = pHead;
    while((p!=NULL) && !found){
        if(p->info == x)
            found = true;
        else
            p = p->next;
    }
    if(!found)
        p = NULL;
    return p;
} 

void clearList(Node *&pHead){
    Node *p;
    while (pHead != NULL){
        p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

void selectionSort(Node* pHead){
    Node *p, *q, *pmin;
    int vmin;
    for(p = pHead; p->next != NULL; p = p->next){
        vmin = p->info;
        pmin = p;
        for(q=p->next; q!= NULL; q = q->next){
            if(q->info < vmin){
                vmin = q->info;
                pmin = q;
            }
        }
        pmin->info = p->info;
        p->info = vmin;
    }
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
    printf("Noi dung danh sach (insertFirst): ");
    ShowList(pHead);
    printf("\n\n");

    Node *pHead1;
    init(pHead1);
    insertFirst(pHead1, a[0]);
    Node *p = pHead1;
    for(int i=1; i<n; i++){
        insertAfter(p, a[i]);
        p = p->next;
    }
    printf("Noi dung danh sach (insertAfter): ");
    ShowList(pHead1);
    printf("\n\n");

    int b[] = {1, 2, 3, 4, 10, 20, 30};
    n = 7;
    int x = 8;
    Node *pHead2;
    init(pHead2); 
    insertFirst(pHead2, b[0]);
    p = pHead2;
    for(int i=1; i<n;i++)
    {
        insertAfter(p, b[i]);
        p = p->next;
    }
    printf("Noi dung danh sach truoc (insertOrder): ");
    ShowList(pHead2);
    printf("\n\n");
    insertOrder(pHead2, x);
    printf("Noi dung danh sach (chen 8) (insertOrder): ");
    ShowList(pHead2);
    printf("\n\n");
    insertOrder(pHead2, 40);
    printf("Noi dung danh sach (chen 40) (insertOrder): ");
    ShowList(pHead2);
    printf("\n\n");
}

void test3(){
    printf("--- Test3 ---\n");
    int a[] = {2, 5, 4, 2, 1, 8}, n = 6;
    int b[] = {1, 2, 5, 10, 20, 30}, m = 6;

    Node *pHead = NULL, *p, *q;
    insertFirst(pHead, a[0]); p = pHead;
    for(int i=1; i<n;i++){
        insertAfter(p, a[i]);
        p = p->next;
    }
    printf("Tim danh sach (find): ");
    ShowList(pHead);
    printf("\n");
    q = find(pHead, 1);
    if(q == NULL){
        printf("--> Khong tim thay\n");
    } else {
        printf("--> Tim thay gia tri %d\n", q->info);
    }
    q = find(pHead, 30);
    if(q == NULL){
        printf("--> Khong tim thay gia tri 30\n");
    } else {
        printf("--> Tim thay gia tri %d\n", q->info);
    }
    printf("\n\n");
}

void test4()
{
    printf("--- Test3 ---\n");
    int a[] = {2, 5, 4, 2, 1, 8}, n = 6;

    Node *pHead = NULL, *p;
    insertFirst(pHead, a[0]); p = pHead;
    for(int i=1; i<n;i++){
        insertAfter(p, a[i]);
        p = p->next;
    }
    printf("Truoc khi sap xep: ");
    ShowList(pHead);
    printf("\n");
    selectionSort(pHead);
    printf("Sau khi sap xep: ");
    ShowList(pHead);
    printf("\n\n");
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}