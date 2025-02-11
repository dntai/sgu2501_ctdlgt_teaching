Input:
10
10 1 2 5 2 3 8 10 1 9

Output:
1: 2
2: 2
3: 1
5: 1
8: 1
9: 1
10: 1

y tuong
Gia su mien tri 0<=max<=10000
Mang xai nhu tu dien

Goi tanso[i] la so lan xuat hien cua gia tri i
tanso[0->maxv] = 0
for(ai thuoc a)
	tanso[ai] = tanso[ai] + 1

Example:
a: 10 1 2 5 2 3 8 10 1 9
     0 1 2 3 4 5 6 7 8 9 10
ts   0 0 0 0 0 0 0 0 0 0  0
     
 10: 0 0 0 0 0 0 0 0 0 0  1
  1: 0 1 0 0 0 0 0 0 0 0  1
  2: 0 1 1 0 0 0 0 0 0 0  1
  5: 0 1 1 0 0 1 0 0 0 0  1
  2: 0 1 2 0 0 1 0 0 0 0  1
  3: 0 1 2 1 0 1 0 0 0 0  1
  8: 0 1 2 1 0 1 0 0 1 0  1
 10: 0 1 2 1 0 1 0 0 1 0  2
  1: 0 2 2 1 0 1 0 0 1 0  2
  9: 0 2 2 1 0 1 0 0 1 1  2