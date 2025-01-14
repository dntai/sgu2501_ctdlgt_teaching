#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // so luong phan tu toi da cua day

/*
Nhap day so nguyen tu ban phim
+ Vao: ban phim
+ Ra : (*a), n
+ Vi du: (*a) = {1,2,3}, n = 3
*/
void NhapMang(int*& a, int& n) // x <-> a, nx <-> n // truyen tham bien
{
	printf("Moi ban nhap so luong phan tu: ");// nhap n
	scanf("%d", n);
	a = new int[n];// cap phat mang a co n phan tu
	for (int i = 0; i <= n - 1; i++)// duyet tu vi tri 0 den n-1
	{
		// nhap phan tu thu a[i]: (a+i) <-> &a[i]
		printf("Phan tu %d: ", i);
		scanf("%d", a + i);// scanf("%d",&a[i]);
	}// for i
}// NhapMang

void NhapMang(int** a, int* n) // truyen tham chieu
{
	printf("Moi ban nhap so luong phan tu: ");// nhap (*n)
	scanf("%d", n);
	(*a) = new int[(*n)];// cap phat mang (*a) co (*n) phan tu
	for (int i = 0; i <= (*n) - 1; i++)// duyet tu vi tri 0 den (*n)-1
	{
		// nhap *((*a)+i) <-> (*a)[i]
		printf("Phan tu %d: ", i);
		scanf("%d", (*a) + i);// scanf("%d",&(*a)[i]);
	}// for i
}// NhapMang

 /*
Xuat day so nguyen ra man hinh
+ Vao: (*a), n
+ Ra : man hinh + Vi du:
*a = {2,5,3}, n = 3
=> man hinh = 2 5 3
*/
void XuatMang(int* a, int n) // truyen tham tri
{
	printf("Day so co %d phan tu: ", n);// xuat so luong phan tu
	for (int i = 0; i <= n - 1; i++)// duyet tu vi tri 0 den n-1 lam
	{
		printf("%d ", *(a + i));// xuat a[i] hay printf("%d",a[i]);
	}// for i
	printf("\n");// xuong dong
}// XuatMang

void DoiChan(int* a, int n)// truyen tham tri, đổi các giá trị chẵn thành số 0
{
	for (int i = 0; i <= n - 1; i++)
	{
		if (*(a + i) % 2 == 0)
		{
			*(a + i) = 0;
		}
	}
}

int main()
{
	/* Khai bao bien */
	int* b = NULL, k = 0;
	
	/* Nhap du lieu */
	NhapMang(&b, &k);
	// NhapMang(b,k);
	
	/* Xuat du lieu */
	XuatMang(b, k);
	DoiChan(b, k);
	printf("* Doi gia tri chan thanh cac so 0: \n:");
	XuatMang(b, k);
	
	/* QUAN TRONG - Huy vung nho*/
	if (b != NULL) delete[]b;
	
	/* Dung man hinh xem ket qua */
	system("PAUSE");
	return 0;
}// main