#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 10000
#define FI "C1_BAI1B.INP"

// #define DEBUG
#ifdef DEBUG
    #define D(x) x
#else
    #define D(x)
#endif

// Du lieu nhap
int n;
int a[MAX];

int cnt[MAX];
int ans;

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

	// Xu ly
	cnt[0] = 1;
	for (int i = 1; i <= n - 1;i++)
	{
		if (a[i] < a[i - 1])
			cnt[i] = 1;
		else
			cnt[i] = cnt[i - 1] + 1;
	}

	// Tim max
	ans = 1;
	for (int i = 0; i < n; i++)
		if (ans < cnt[i])
			ans = cnt[i];

	printf("%d\n", ans);
}

int main()
{
	// freopen(FI, "rt", stdin);
	solve();
	return 0;
}