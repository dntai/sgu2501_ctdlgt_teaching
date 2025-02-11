#include <iostream>
#include <cstdio>

#include "BigInt.h"

using namespace std;

void test1()
{
	BigInt b1, b2, b3, b4;

	BigInt_TuChuoi(&b1, "12345");
	BigInt_TuSo(&b2, 23456);

	printf("b1: "); BigInt_Xuat(&b1); printf("\n");
	printf("b2: "); BigInt_Xuat(&b2); printf("\n");
}

int main()
{
	test1();
	return 0;
}