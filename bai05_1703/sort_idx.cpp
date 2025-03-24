#include <iostream>
using namespace std;

int *_a;
bool laNhoHon(int idx1, int idx2)
{
    return _a[idx1] < _a[idx2];
}

void sort_idx(int idx[], int n, 
    bool laNhoHon(int idx1, int idx2))
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(laNhoHon(idx[j], idx[i]))
            // if(idx[i] > idx[j]) // idx[j] < idx[i]
            {
                int tmp = idx[i];
                idx[i] = idx[j];
                idx[j] = tmp;
            }
}

void test1()
{
    int a[] = {5, 1, 9, 3, 2, 4, 6}, n = 7;


    int idx[] = {0, 1, 2, 3, 4, 5, 6};

    printf("idx (truoc sort): ");
    for(int i=0; i<n; i++)
        printf("%d ", idx[i]);
    printf("\n");
    printf("a[idx] (truoc sort): ");
    for(int i=0; i<n; i++)
        printf("%d ", a[idx[i]]);
    printf("\n");

    _a = a;
    sort_idx(idx, n, laNhoHon);

    printf("idx (sau sort): ");
    for(int i=0; i<n; i++)
        printf("%d ", idx[i]);
    printf("\n");
    printf("a[idx] (sau sort): ");
    for(int i=0; i<n; i++)
        printf("%d ", a[idx[i]]);
    printf("\n");
    
}

int main()
{
	test1();
	return 0;
}
