#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* Con trỏ tham chiếu tới đối tượng tĩnh */
	int n; // biến số nguyên n 
	
	// biến con trỏ chứa địa chỉ tham chiếu tới vùng nhớ chứa số nguyên
	int* p = NULL; // con trỏ không sử dụng phải gán NULL
	n = 20;
	
	p = &n; // gán địa chỉ của biến n cho
	printf("n: Addr=%X, Val=%d\n", &n, n); // in thông tin biến n: địa chỉ, giá trị
	
	// địa chỉ, giá trị, giá trị tham chiếu
	printf("p: Addr=%X, Val=%X, ValRef=%d\n", &p, p, *p);
	
	/* Con trỏ tham chiếu tới đối tượng động */
	int* pn = NULL;
	
	// cấp phát vùng có kích thước kiểu int 
	// và pn chứa địa chỉ vừa cấp phát
	pn = (int*)malloc(sizeof(int));
	(*pn) = 10;// gán 10 vào đối tượng pn tham chiếu
	printf("sizeof(int): %d byte(s)\n", sizeof(int));// in kích thước kiểu int
	
	// địa chỉ, giá trị, giá trị tham chiếu
	printf("pn: Addr=%X, Val=%X, ValRef=%d\n", &pn, pn, *pn);
	
	// ! hủy vùng nhớ sau khi sử dụng xong
	free(pn);
	
	return 0;
}