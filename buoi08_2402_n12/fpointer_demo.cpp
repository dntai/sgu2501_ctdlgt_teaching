#include <iostream>
using namespace std;

// TinhTong: const int (*)(int, int) (chu ky ham)
int TinhTong(int a, int b)
{
    return a + b;
}

int TinhTru(int a, int b)
{
    return a - b;
}

int (*TinhToan)(int,int);

int main(){
    int a = 10, b = 20, kq;
    printf("a=%d, b=%d\n", a, b);
    
    TinhToan = TinhTong;
    kq = TinhToan(a, b);
    printf("TinhTong: %d\n", kq);
    
    TinhToan = TinhTru;
    kq = TinhToan(a, b);
    printf("TinhTry: %d\n", kq);
    return 0;
}