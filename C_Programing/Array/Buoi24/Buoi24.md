### Bài 5. Loại bỏ hàng và cột 1

Cho ma trận có n hàng, m cột, hãy loại bỏ hàng có tổng lớn nhất và cột có tổng phần tử lớn nhất khỏi ma trận.

**Input**

Dòng đầu tiên là số bộ test `T` ($1 \le T \le 100$).
Mỗi test case gồm:
Dòng đầu tiên là `n`, `m`. $1 \le n,m \le 100$.
`n` dòng tiếp theo, mỗi dòng có `m` số nguyên.

**Output**

In ra ma trận sau khi xóa hàng và cột có tổng các phần tử lớn nhất

**Ví dụ**

**Input**
```text
1
3 3
1 2 3
4 5 6
7 8 9
```

**Output**
```text
#TC 1:
1 2
4 5
```

**Code**
```cpp
                        #include <stdio.h>
                        #include <math.h>

                        int max(int a, int b){
                            return a < b ? b : a;
                        }

                        int main(){
                            int t;
                            scanf("%d",&t);
                            for(int i = 1;i<=t;i++){
                                int n,m;
                                scanf("%d%d",&n,&m);
                                int a[n][m];
                                // nhap ma tran 
                                for(int i =0;i<n;i++){
                                    for(int j = 0;j<m;j++){
                                        scanf("%d",&a[i][j]);
                                    }
                                }
                                int hang = 0, cot = 0, res = -1e9;
                                // tìm tổng hàng lớn nhất 
                                for(int i = 0;i<n;i++){
                                    int sum = 0;
                                    for(int j = 0;j<m;j++){
                                        sum += a[i][j];
                                    }
                                    if(sum > res){
                                        res = sum;
                                        hang = i;
                                    }
                                }
                                // tim tong cot lon nhat 
                                res = -1e9; // gán lại biến 
                                for(int i = 0;i<m;i++){
                                    int sum = 0;
                                    for(int j = 0;j<n;j++){
                                        sum += a[i][j];
                                    }
                                    if(sum > res){
                                        res = sum;
                                        cot = i;
                                    }
                                }
                                // In ra ket qua
                                for(int i = 0;i<n;i++){
                                    // bo hang 
                                    if(i != hang){
                                        for(int j = 0;j<m;j++){
                                            // bo cot 
                                            if(j != cot){
                                                printf("%d ",a[i][j]);
                                            }
                                        }
                                        printf("\n");
                                    }
                                }
                            }
                        }
```

### Bài 6. Loại bỏ hàng và cột 2

Cho ma trận có n hàng, m cột, hãy loại bỏ hàng có tổng lớn nhất ra khỏi ma trận, sau đó tính toán lại trên ma trận mới rồi loại bỏ cột có tổng các phần tử lớn nhất ra khỏi ma trận.

**Input**

Dòng đầu tiên là số bộ test `T` ($1 \le T \le 100$).
Mỗi test case gồm:
Dòng đầu tiên là `n`, `m`. $1 \le n,m \le 100$.
`n` dòng tiếp theo, mỗi dòng có `m` số nguyên.

**Output**

In ra ma trận sau khi xóa hàng và cột có tổng các phần tử lớn nhất

**Ví dụ**

**Input**
```text
1
3 3
1 2 0
3 5 6
1 3 9
```

**Output**
```text
#TC 1:
1 2
1 3
```

**Code**
```cpp
                        #include <stdio.h>

                        int main(){
                            int t;
                            scanf("%d",&t);
                            for(int tc = 1; tc <= t; tc++){
                                int n,m;
                                scanf("%d%d",&n,&m);
                                int a[n][m];
                                // nhap ma tran 
                                for(int i = 0;i<n;i++){
                                    for(int j = 0;j<m;j++){
                                        // cũng có thể viết scanf("%d", *(a + i) + j);
                                        scanf("%d", &a[i][j]);
                                    }
                                }
                                int hang = 0, cot = 0, res = -1e9;
                                // tinh tong hang 
                                for(int i =0;i<n;i++){
                                    int sum = 0;
                                    for(int j=0;j<m;j++){
                                        sum += a[i][j];
                                    }
                                    if(sum > res){
                                        res = sum;
                                        hang = i;
                                    }
                                }
                                // tinh tong cot khi loai bo hang max
                                res = -1e9;
                                for(int j = 0; j < m; j++){
                                    int sum = 0;
                                    for(int i = 0; i < n; i++){
                                        // chi tinh nhung hang chua bi loai bo
                                        if(i != hang){
                                            sum += a[i][j];
                                        }
                                    }
                                    if(sum > res){
                                        res = sum;
                                        cot = j;
                                    }
                                }
                                // In ra ket qua
                                printf("#TC %d:\n", tc);
                                for(int i = 0;i<n;i++){
                                    // bo hang 
                                    if(i != hang){
                                        for(int j = 0;j<m;j++){
                                            // bo cot 
                                            if(j != cot){
                                                printf("%d ",a[i][j]);
                                            }
                                        }
                                        printf("\n");
                                    }
                                }
                            }
                        }
```