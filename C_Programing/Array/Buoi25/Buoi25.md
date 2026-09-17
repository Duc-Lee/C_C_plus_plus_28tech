### Bài 7. Hoán vị 2 hàng

Thực hiện hoán vị 2 hàng của ma trận.

**Input**

Dòng đầu tiên là `n`, `m`. $1 \le n,m \le 100$.
`n` dòng tiếp theo, mỗi dòng có `m` số nguyên.
Dòng cuối cùng là `x`, `y`: 2 hàng cần hoán vị của ma trận.

**Output**

In ra ma trận sau khi hoán vị 2 hàng

**Ví dụ**

**Input**
```text
3 3
1 2 3
4 5 6
7 8 9
1 3
```

**Output**
```text
7 8 9
4 5 6
1 2 3
```

**Code**
```cpp
                    #include <stdio.h>
                    
                    int main(){
                        int n,m;
                        scanf("%d%d",&n,&m);
                        int a[n][m];
                        // nhap ma tran 
                        for(int i =0;i<n;i++){
                            for(int j = 0;j<m;j++){
                                scanf("%d",&a[i][j]);
                            }
                        }
                        // 2 hang can hoan vi
                        int x,y;
                        scanf("%d %d",&x,&y);
                        // duyet theo hang cua tung cot x, y
                        for(int j = 0; j < m; j++){
                            int tmp = a[x-1][j];
                            a[x-1][j] = a[y-1][j];
                            a[y-1][j] = tmp;
                        }
                        // in ra ket qua
                        for(int i =0;i<n;i++){
                            for(int j = 0;j<m;j++){
                                printf("%d ",a[i][j]);
                            }
                            printf("\n");
                        }
                    }           
```

### Bài 8. Hoán vị 2 cột

Thực hiện hoán vị 2 cột của ma trận.

**Input**

Dòng đầu tiên là `n`, `m`. $1 \le n,m \le 100$.
`n` dòng tiếp theo, mỗi dòng có `m` số nguyên.
Dòng cuối cùng là `x`, `y`: 2 cột cần hoán vị của ma trận.

**Output**

In ra ma trận sau khi hoán vị 2 cột

**Ví dụ**

**Input**
```text
3 3
1 2 3
4 5 6
7 8 9
1 3
```

**Output**
```text
3 2 1
6 5 4
9 8 7
```

**Code**
```cpp
                    #include <stdio.h>
                    
                    int main(){
                        int n,m;
                        scanf("%d%d",&n,&m);
                        int a[n][m];
                        // nhap ma tran 
                        for(int i =0;i<n;i++){
                            for(int j = 0;j<m;j++){
                                scanf("%d",&a[i][j]);
                            }
                        }
                        // 2 cot can hoan vi
                        int x,y;
                        scanf("%d %d",&x,&y);
                        // duyet theo cot cua tung cot x, y
                        for(int i = 0; i < n; i++){
                            int tmp = a[i][x-1];
                            a[i][x-1] = a[i][y-1];
                            a[i][y-1] = tmp;
                        }
                        // in ra ket qua
                        for(int i =0;i<n;i++){
                            for(int j = 0;j<m;j++){
                                printf("%d ",a[i][j]);
                            }
                            printf("\n");
                        }
                    }
```

### Bài 9. Hoán vị 2 đường chéo của ma trận vuông

Thực hiện hoán vị 2 đường chéo của ma trận.

**Input**

Dòng đầu tiên là `n`: Cấp của ma trận. $1 \le n \le 100$.
`n` dòng tiếp theo, mỗi dòng có `n` số nguyên.

**Output**

In ra ma trận sau khi hoán vị 2 đường chéo

**Ví dụ**

**Input**
```text
3
1 2 3
4 5 6
7 8 9
```

**Output**
```text
3 2 1
4 5 6
9 8 7
```

**Code**
```cpp
                    #include <stdio.h>

                    int main(){
                        int n;
                        scanf("%d",&n);
                        int a[n][n];
                        // nhap ma tran 
                        for(int i =0;i<n;i++){
                            for(int j = 0;j<n;j++){
                                scanf("%d",&a[i][j]);
                            }
                        }
                        
                        // hoan vi 2 duong cheo
                        for(int i = 0; i < n; i++){
                            // duong cheo chinh la a[i][i]
                            // duong cheo phu la a[i][n - i - 1]
                            int tmp = a[i][i];
                            a[i][i] = a[i][n - i - 1];
                            a[i][n - i - 1] = tmp;
                        }
                        
                        // in ra ket qua
                        for(int i =0;i<n;i++){
                            for(int j = 0;j<n;j++){
                                printf("%d ",a[i][j]);
                            }
                            printf("\n");
                        }
                    }
```