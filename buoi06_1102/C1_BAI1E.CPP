#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

#define FI "C1_BAI1E.INP"

// #define DEBUG
#ifdef DEBUG
#define D(x) x
#else
#define D(x)
#endif

// Du lieu nhap
#define MAX  1000
#define MAXV 10000
int n;
int a[MAX];

int cnt[MAXV + 1] = { 0 };

void solve()
{
	// Nhap du lieu
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	// Xu ly
	for (int i = 0; i < n; i++)
		cnt[a[i]] = cnt[a[i]] + 1;

	// In dap an
	for (int i = 0; i <= MAXV;i++)
	{
		if (cnt[i] > 0)
		{
			printf("%d: %d\n", i, cnt[i]);
		}
	}
}

int main()
{
	freopen(FI, "rt", stdin);
	solve();
	return 0;
}