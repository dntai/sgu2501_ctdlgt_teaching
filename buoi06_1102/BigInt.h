#ifndef _BIG_INT_
#define _BIG_INT_

#define MAX_DIGIT 1000

typedef struct BigInt
{
	int n;
	char a[MAX_DIGIT];
};

void BigInt_TuChuoi(BigInt* b, const char* s);
void BigInt_TuSo(BigInt *b, long long n);
void BigInt_Xuat(BigInt* b);

#endif // _BIG_INT_