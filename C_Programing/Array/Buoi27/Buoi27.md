### Bài 12. In ma trận 1

In ma trận chuyển vị

**Input**

Dòng đầu tiên là `n`: Cấp của ma trận. $1 \le n \le 100$.
`n` dòng tiếp theo, mỗi dòng có `n` số nguyên. Các số đều là số nguyên dương không vượt quá 10000.

**Output**

In ra ma trận chuyển vị của ma trận ban đầu

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
1 4 7
2 5 8
3 6 9
```

**Code**
```cpp
                                #include <stdio.h>
                                int main(){
                                    int n;
                                    scanf("%d", &n);
                                    int a[n][n];
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<n;j++){
                                            scanf("%d", &a[i][j]);
                                        }
                                    }
                                    
                                    // In ket qua
                                    for(int j=0;j<n;j++){
                                        // In cot theo hang
                                        for(int i=0;i<n;i++){
                                            printf("%d ", a[i][j]);
                                        }
                                        printf("\n");
                                    }
                                    return 0;
                                }
```

### Bài 13. In ma trận 2

In ma trận zigzag

**Input**

Dòng đầu tiên là `n`: Cấp của ma trận. $1 \le n \le 100$.
`n` dòng tiếp theo, mỗi dòng có `n` số nguyên. Các số đều là số nguyên dương không vượt quá 10000.

**Output**

In ra ma trận zigzag của ma trận ban đầu

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
1 2 3
6 5 4
7 8 9
```

**Code**
```cpp
                                #include <stdio.h>
                                int main(){
                                    int n;
                                    scanf("%d", &n);
                                    int a[n][n];
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<n;j++){
                                            scanf("%d", &a[i][j]);
                                        }
                                    }
                                    
                                    // In ket qua
                                    for(int i=0;i<n;i++){
                                        // hang chan thi in thuan
                                        // hang le thi in nghich
                                        if(i % 2 == 0){
                                            for(int j=0;j<n;j++){
                                                printf("%d ", a[i][j]);
                                            }
                                        }else{
                                            for(int j=n-1;j>=0;j--){
                                                printf("%d ", a[i][j]);
                                            }
                                        }
                                        printf("\n");
                                    }
                                    return 0;
                                }
```

### Bài 14. Đếm số 1

Đếm số lượng số 1 trong ma trận

**Input**

Dòng đầu tiên là `n`: Cấp của ma trận. $1 \le n \le 100$.
`n` dòng tiếp theo, mỗi dòng có `n` số nguyên. Các số đều là số nguyên dương không vượt quá 10000.

**Output**

In ra số lượng số 1 trong ma trận

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
1
```

**Code**
```cpp
                                #include <stdio.h>
                                int main(){
                                    int n;
                                    scanf("%d", &n);
                                    int a[n][n];
                                    int cnt = 0;
                                    for(int i=0;i<n;i++){
                                        for(int j=0;j<n;j++){
                                            scanf("%d", &a[i][j]);
                                            if(a[i][j] == 1){
                                                cnt++;
                                            }
                                        }
                                    }
                                    printf("%d\n", cnt);
                                    return 0;
                                }
```

