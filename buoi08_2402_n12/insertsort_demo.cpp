#include <iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
    // gia su i=0,..0 la duoc sort
    // chen gia tri tu vi tri i=1..n-1 vao mang a[0], a[1],...,a[i-1] (da co thu tu)
    for(int i=1; i<=n-1; i++) {
        int j = i - 1;
        int x = a[i];
        bool cond = true;
        while((j>=0) && cond){
            if(a[j]>x){
                a[j+1] = a[j];
                j = j - 1;
            } else {
                cond = false;
            }
        }
        a[j+1] = x;
    }
}

void xuat_mang(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
}

void test1()
{
    int a[] = {6, 8, 1, 5, 6, 2, 7, 4}, n = 8;
    printf("----- TEST 1 -----\n");
    printf("Mang a (truoc sort): "); xuat_mang(a, n); printf("\n");
    insertion_sort(a, n);
    printf("Mang a (sau sort): "); xuat_mang(a, n); printf("\n");
    printf("\n");
}


int main()
{
    printf("--- INSERT SORT --- \n");
    test1();
    return 0;
}
