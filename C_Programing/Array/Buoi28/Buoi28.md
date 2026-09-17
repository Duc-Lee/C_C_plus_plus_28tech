### Bài 16. Tổng 2 ma trận

Tính tổng của 2 ma trận cùng cấp.

**Input**

Dòng đầu tiên là `n`, `m`. $1 \le n, m \le 100$.
Các dòng tiếp theo là 2 ma trận.

**Output**

Tổng của 2 ma trận

**Ví dụ**

**Input**
```text
3 3
1 2 3
2 2 0
1 4 5
1 1 0
1 2 3
1 2 6
```

**Output**
```text
2 3 3
3 4 3
2 6 11
```

**Code**
```cpp
                                #include <stdio.h>
                                int main(){
                                    int n, m;
                                    scanf("%d %d", &n, &m);
                                    int a[n][m];
                                    int b[n][m];
                                    int c[n][m];
                                    
                                    // Doc ma tran thu nhat
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++){
                                            scanf("%d", &a[i][j]);
                                        }
                                    }
                                    
                                    // Doc ma tran thu hai
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++){
                                            scanf("%d", &b[i][j]);
                                        }
                                    }
                                    
                                    // Tinh tong 2 ma tran
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++){
                                            c[i][j] = a[i][j] + b[i][j];
                                        }
                                    }
                                    
                                    // In ket qua
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++){
                                            printf("%d ", c[i][j]);
                                        }
                                        printf("\n");
                                    }
                                    
                                    return 0;
                                }
```

### Bài 17. Tính hiệu của 2 ma trận

Tính tổng của 2 ma trận cùng cấp

**Input**

Dòng đầu tiên là `n`, `m`. $1 \le n, m \le 100$.
Các dòng tiếp theo là 2 ma trận.

**Output**

Hiệu của 2 ma trận

**Ví dụ**

**Input**
```text
3 3
1 2 3
2 2 0
1 4 5
1 1 0
1 2 3
1 2 6
```

**Output**
```text
0 1 3
1 0 -3
0 2 -1
```
**Code**
```cpp
                                #include <stdio.h>
                                int main(){
                                    int n, m;
                                    scanf("%d %d", &n, &m);
                                    int a[n][m];
                                    int b[n][m];
                                    int c[n][m];
                                    
                                    // Doc ma tran thu nhat
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++){
                                            scanf("%d", &a[i][j]);
                                        }
                                    }
                                    
                                    // Doc ma tran thu hai
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++){
                                            scanf("%d", &b[i][j]);
                                        }
                                    }
                                    
                                    // Tinh tong 2 ma tran
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++){
                                            c[i][j] = a[i][j] - b[i][j];
                                        }
                                    }
                                    
                                    // In ket qua
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++){
                                            printf("%d ", c[i][j]);
                                        }
                                        printf("\n");
                                    }
                                    
                                    return 0;
                                }
```