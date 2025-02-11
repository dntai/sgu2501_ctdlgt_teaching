#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 10000
#define FI "C1_BAI1B.INP"

#define DEBUG
#ifdef DEBUG
    #define D(x) x
#else
    #define D(x)
#endif

// Du lieu nhap
int n;
int a[MAX];

void solve()
{
	// Nhap du lieu
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	// DEBUG
	D(printf("%d\n", n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");)
}

int main()
{
	// freopen(FI, "rt", stdin);
	solve();
	return 0;
}