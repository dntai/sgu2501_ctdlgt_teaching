#include <iostream>
#include <ctime> // time(NULL)
#include <cstdlib> // srand, rand
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

bool op_chan_le(int a, int b)
{
    bool kq = false;
    if(a%2==0 && b%2==1)
        kq = true;
    return kq;
}

bool op_giam_dan(int a, int b)
{
    return a>b;
}

void insertion_sort_tq(int a[], int n, bool (*op_less)(int, int))
{
    // gia su i=0,..0 la duoc sort
    // chen gia tri tu vi tri i=1..n-1 vao mang a[0], a[1],...,a[i-1] (da co thu tu)
    for(int i=1; i<=n-1; i++) {
        int j = i - 1;
        int x = a[i];
        bool cond = true;
        while((j>=0) && cond){
            if(op_less(x, a[j])){ // x < a[j] <-> op_less(x, a[j]) == true
                a[j+1] = a[j];
                j = j - 1;
            } else {
                cond = false;
            }
        }
        a[j+1] = x;
    }
}

void insertion_sort_cnt(int a[], int n, int *cnt_sosanh, int *cnt_dichuyen)
{
    (*cnt_sosanh) = 0;
    (*cnt_dichuyen) = 0;
    // gia su i=0,..0 la duoc sort
    // chen gia tri tu vi tri i=1..n-1 vao mang a[0], a[1],...,a[i-1] (da co thu tu)
    for(int i=1; i<=n-1; i++) {
        (*cnt_sosanh) += 1;
        int j = i - 1;
        int x = a[i];
        bool cond = true;
        while((j>=0) && cond){
            (*cnt_sosanh) +=3;
            if(a[j]>x){
                a[j+1] = a[j];
                j = j - 1;
                (*cnt_dichuyen) += 1;
            } else {
                cond = false;
            }
        }
        a[j+1] = x;
        (*cnt_dichuyen) += 1;
    }
}

void xuat_mang(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
}

void sinh_mang(int a[], int n, int vfrom, int vto)
{
    for(int i=0;i<n;i++)// a->b: rand()%(b-a+1) [0,b-a]+a -> [a, b]
        a[i]= rand()%(vto-vfrom+1) + vfrom;
}

void test3_cnt(int n, int t, long long *cnt_ss, long long *cnt_dc) {
    int a[100001] = {};
    *cnt_ss = 0;
    *cnt_dc = 0;
    for(int i=0; i<t; i++){
        int ss, dc;
        sinh_mang(a, n, 0, 100000);
        insertion_sort_cnt(a, n, &ss, &dc);
        (*cnt_ss) += ss;
        (*cnt_dc) += dc;
    }
    *cnt_ss = (*cnt_ss) / t;
    *cnt_dc = *cnt_dc / t;
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

void test4()
{
    int a[] = {6, 8, 1, 5, 6, 2, 7, 4}, n = 8;
    printf("----- TEST 4 -----\n");
    printf("Mang a: "); xuat_mang(a, n); printf("\n");
    insertion_sort_tq(a, n, op_chan_le);
    printf("Mang a (chan/le): "); xuat_mang(a, n); printf("\n");
    insertion_sort_tq(a, n, op_giam_dan);
    printf("Mang a (giam dan): "); xuat_mang(a, n); printf("\n");
    printf("\n");
}

void test2()
{
    int a[] = {6, 8, 1, 5, 6, 2, 7, 4}, n = 8;
    int cnt_ss, cnt_dc;
    printf("----- TEST 2 -----\n");
    printf("Mang a (truoc sort): "); xuat_mang(a, n); printf("\n");
    insertion_sort_cnt(a, n, &cnt_ss, &cnt_dc);
    printf("Mang a (sau sort): "); xuat_mang(a, n); printf("\n");
    printf("So lan so sanh: %d\n", cnt_ss);
    printf("So lan di chuyen: %d\n", cnt_dc);
    printf("\n");
}

void test3()
{
    printf("----- TEST 3 -----\n");
    int n = 4000, t = 10;
    long long n_ss, n_dc;
    
    printf("So lan thuc nghiem: %d\n", t);
    printf("Kich thuoc mang: %d\n", n);
    test3_cnt(n, t, &n_ss, &n_dc);
    printf("So lan so sanh trung binh: %lld\n", n_ss);
    printf("So lan dich chuyen trung binh: %lld\n", n_dc);
}

int main()
{
    srand(time(NULL));

    printf("--- INSERT SORT --- \n");
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}
