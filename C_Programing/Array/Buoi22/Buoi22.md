## PHẦN 3. MẢNG 2 CHIỀU
### Bài 1. Tính tổng các hàng của ma trận

Cho ma trận có n hàng, m cột, tính tổng các phần tử của từng hàng.

**Input**

Dòng đầu tiên là `n`, `m`. $1 \le n,m \le 100$.
`n` dòng tiếp theo, mỗi dòng có `m` số nguyên.

**Output**

In ra tổng các phần tử của từng hàng.

**Ví dụ**

**Input**
```text
3 3
1 2 3
4 5 6
7 8 9
```

**Output**
```text
6
15
24
```
**Code**
```cpp
                    #include <stdio.h>

                    int main(){
                        int n,m;
                        scanf("%d %d",&n,&m);
                        int a[n][m];
                        for(int i = 0;i<n;i++){
                            // tính tổng của hàng i
                            int sum = 0;
                            for(int j = 0;j<m;j++){
                                scanf("%d",&a[i][j]);
                                sum += a[i][j];
                            }
                            printf("%d\n",sum);
                        }
                    }
```
### Bài 2. Tính tổng các cột của ma trận

Cho ma trận có n hàng, m cột, tính tổng các phần tử của từng cột.

**Input**

Dòng đầu tiên là `n`, `m`. $1 \le n,m \le 100$.
`n` dòng tiếp theo, mỗi dòng có `m` số nguyên.

**Output**

In ra tổng các phần tử của từng cột.

**Ví dụ**

**Input**
```text
3 3
1 2 3
4 5 6
7 8 9
```

**Output**
```text
12
15
18
```
**Code**
```cpp
                    #include <stdio.h>

                    int main(){
                        int n,m;
                        scanf("%d %d",&n,&m);
                        int a[n][m];
                        // nhap ma trận
                        for(int i = 0;i<n;i++){
                            for(int j = 0;j<m;j++){
                                scanf("%d",&a[i][j]);
                            }
                        }
                        // tính tổng các cột
                        for(int j = 0;j<m;j++){
                            int sum = 0;
                            for(int i = 0;i<n;i++){
                                sum += a[i][j];
                            }
                            printf("%d\n",sum);
                        }
                    }

```