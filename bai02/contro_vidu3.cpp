#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* Con trỏ với mảng tĩnh */
	int a[5] = { 2, 4, 5, 8 }; // Mảng tĩnh
	int na = 3; // Số phần tử của mảng
	
	int* p = NULL; // con trỏ rỗng
	p = a + 1; // hay &a[1] - trỏ tới phần tử thứ 1
	
	// địa chỉ, giá trị, giá trị tham chiếu 
	printf("p: Addr=%X, Val=%X, ValRef=%d\n", &p, p, *p);
	
	p = p + 1; // p = p + 1*sizeof(int) --> di chuyen qua ben phai 1 don vi
	int x = p[-2]; // *(p - 2) - di chuyen qua trai 2 don vi
	
	/* Con trỏ với mảng động */
	int* b = NULL; // Khai báo mảng rỗng
	int nb = 0;
	
	nb = 3;
	b = (int*)malloc(sizeof(int) * nb);// stdlib.h, Cấp phát nb phần tử (C)
	// b = new int[nb]; // Cấp phát nb phần tử (C++)
	
	*(b + 0) = 10;
	*(b + 1) = 20;
	
	b[2] = 30;
	if (b != NULL) free(b); // Hủy vùng nhớ cấp phát
	
	return 0;
}