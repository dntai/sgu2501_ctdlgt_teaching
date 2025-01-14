#include <stdio.h>
#include <stdlib.h>

void test1()
{
	printf("Test1: \n");

	int *a[3] = { NULL };
	a[0] = new int[] {1, 2, 3};
	a[1] = new int[] {4, 5, 6};
	a[2] = new int[] {7, 8, 9};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	delete[]a[0];
	delete[]a[1];
	delete[]a[2];
}

void test2()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int (*b)[4] = (int (*)[4])a;

	printf("4 cot: \n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	int (*b1)[3] = (int (*)[3])a;
	printf("3 cot: \n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", b1[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	test1();
	test2();
	return 0;
}