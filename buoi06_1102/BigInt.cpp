#include "BigInt.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


void BigInt_TuChuoi(BigInt* b, const char* s)
{
	int ns = strlen(s);
	if (ns == 0 || (ns == 1 && s[0] == '0'))
	{
		b->n = 1;
		b->a[0] = 0;
	}
	else
	{
		b->n = ns;
		for (int i = ns - 1; i >= 0; i--)
		{
			b->a[(ns - 1) - i] = s[i] - '0';
		}
	}
}

void BigInt_TuSo(BigInt* b, long long n)
{

}

void BigInt_Xuat(BigInt* b)
{
	for (int i = b->n - 1; i >= 0; i--)
	{
		printf("%d", b->a[i]);
	}
}