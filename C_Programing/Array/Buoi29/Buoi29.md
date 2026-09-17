### Bài 18. Tính tích của 2 ma trận

Cho ma trận a có cấp nxm, ma trận b có cấp mxp, tính tích của 2 ma trận trên.

**Input**

Dòng đầu tiên là 3 số `n`, `m`, `p` ($1 \le m, n, p \le 100$).
`n` dòng tiếp theo, mỗi dòng `m` số của ma trận thứ 1.
`m` dòng tiếp theo, mỗi dòng `p` số của ma trận thứ 2.

**Output**

In ra tích của 2 ma trận ban đầu.

**Ví dụ**

**Input**
```text
3 4 5
1 2 3 4
5 6 7 8
9 10 11 12
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
```

**Output**
```text
110 120 130 140 150
246 272 298 324 350
382 424 466 508 550
```

**Code**
```cpp
                                #include <stdio.h>
                                int main(){
                                    int n, m, p;
                                    scanf("%d %d %d", &n, &m, &p);
                                    int a[n][m];
                                    int b[m][p];
                                    int c[n][p];
                                    
                                    // Doc ma tran thu nhat
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++){
                                            scanf("%d", &a[i][j]);
                                        }
                                    }
                                    
                                    // Doc ma tran thu hai
                                    for(int i=0;i<m;i++){
                                        for(int j=0;j<p;j++){
                                            scanf("%d", &b[i][j]);
                                        }
                                    }
                                    
                                    // Tinh tich 2 ma tran
                                    // duyet theo hang
                                    for(int i=0;i<n;i++){
                                        // duyet theo cot
                                        for(int j=0;j<p;j++){
                                            // duyet theo phan tu
                                            c[i][j] = 0; // gan cho no 0 de de cong don
                                            for(int k = 0; k < m; k++){
                                                c[i][j] += a[i][k] * b[k][j];
                                            }
                                        }
                                    }
                                    
                                    // In ket qua
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<p;j++){
                                            printf("%d ", c[i][j]);
                                        }
                                        printf("\n");
                                    }
                                    
                                    return 0;
                                }
```

### Bài 19. Tích của ma trận với ma trận chuyển vị của nó

Cho ma trận cấp n,m. Tìm tích của nó với ma trận chuyển vị.

**Input**

Dòng đầu tiên là `n`, `m`. $1 \le n, m \le 100$.
`n` dòng tiếp theo, mỗi dòng có `m` số nguyên.

**Output**

Kết quả tích của ma trận với chuyển vị của nó

**Ví dụ**

**Input**
```text
4 5
16 42 84 60 16
28 8 81 83 43
68 82 76 68 95
65 45 84 55 78
```

**Output**
```text
12932 13256 16516 14534
13256 16147 18445 16903
16516 18445 30773 25644
14534 16903 25644 22415
```

**Code**
```cpp
                                #include <stdio.h>
                                int main(){
                                    int n, m;
                                    scanf("%d %d", &n, &m);
                                    int a[n][m];
                                    int b[m][n];
                                    int c[n][n];
                                    
                                    // Doc ma tran thu nhat
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++){
                                            scanf("%d", &a[i][j]);
                                        }
                                    }
                                    
                                    // chuyển vị ma trận a để gán cho ma trận b
                                    for(int i=0;i<m;i++){
                                        for(int j=0;j<n;j++){
                                            b[i][j] = a[j][i];
                                        }
                                    }
                                    
                                    // Tinh tich 2 ma tran
                                    // duyet theo hang cua ma tran c
                                    for(int i=0;i<n;i++){
                                        // duyet theo cot cua ma tran c
                                        for(int j=0;j<n;j++){
                                            // duyet theo phan tu c[i][j]
                                            c[i][j] = 0; // gan cho no 0 de de cong don
                                            // do a[n][m] x b[m][n] = c[n][n]
                                            // nên duyet theo k từ 0 đến m
                                            for(int k = 0; k < m; k++){
                                                c[i][j] += a[i][k] * b[k][j];
                                            }
                                        }
                                    }
                                    
                                    // In ket qua
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<n;j++){
                                            printf("%d ", c[i][j]);
                                        }
                                        printf("\n");
                                    }
                                    
                                    return 0;
                                }
```