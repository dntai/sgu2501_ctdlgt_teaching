<pre>
Chương 1 - Ví dụ 1.5
+ Input
  * n = 7
  * 4 -5 6 -4 2 3 -7
+ Output
  7 // 6, -4, 2, 3

Thuat giai 1:
+ gia su vmax = a[0]
+ Vet tat ca cac doan con (i, j)
+ Tinh tong [a[i], a[j]]
+ So sanh vmax 
--> cap nhat neu chua toi uu
--> Do phuc tap O(n^3)

Vi du:
vmax = 4
i=0 (ai=4) : (4), (4, -5), (4,-5,6), ...
i=1 (ai=-5): (-5), (-5, 6)
...
i=6


</pre>