#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

// #define DEBUG
#ifdef DEBUG
   #define D(x) x
#else
   #define D(x)
#endif

#define FI "C1_ViDu1.5.inp"

// Du lieu nhap
#define MAX 10000
int n;
int a[MAX];

int ans;

void solve()
{
	// Nhap du lieu
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	ans = a[0];
	// vet tat ca cac doan con (i,j) trong a
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			// tai doan con (i,j)

			// tinh sum
			int vsum = 0;
			for (int k = i; k <= j; k++)
				vsum = vsum + a[k];

			// so sanh voi ans
			if (ans < vsum)
				ans = vsum;
		}
	}

	// in dap so
	printf("%d", ans);
}

int main()
{
	freopen(FI, "rt", stdin);
	solve();
	return 0;
}