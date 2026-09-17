### Bài 24. Sắp xếp các phần tử theo hàng

Cho ma trận cấp nxm. Sắp xếp các phần tử ở mỗi hàng theo thứ tự tăng dần.

**Input**

Dòng đầu tiên là số lượng hàng và cột `n`, `m`. $1 \le n, m \le 100$.
`n` dòng tiếp theo, mỗi dòng `m` cột là các phần tử của ma trận.

**Output**

In ra ma trận sau khi đã sắp xếp các hàng của nó.

**Ví dụ**

**Input**
```text
3 3
1 4 1
2 9 8
3 3 1
```

**Output**
```text
1 1 4
2 8 9
1 3 3
```

**Code**
```cpp
                            #include <stdio.h>

                            void selectionSort(int a[], int n){
                                for(int i = 0; i<n; i++){
                                    int min = i;
                                    for(int j = i+1; j<n; j++){
                                        if(a[j]<a[min]){
                                            min = j;
                                        }
                                    }
                                    // hoan vi
                                    int temp = a[i];
                                    a[i] = a[min];
                                    a[min] = temp;
                                }
                            }

                            int main(){
                                int n,m;
                                scanf("%d%d",&n,&m);
                                int a[n][m];
                                for(int i=0; i<n; i++){
                                    for(int j=0; j<m; j++){
                                        scanf("%d",&a[i][j]);
                                    }
                                }
                                // sap xep tung hang
                                for(int i=0; i<n; i++){
                                    selectionSort(a[i],m);
                                }
                                // in ra ket qua
                                for(int i=0; i<n; i++){
                                    for(int j=0; j<m; j++){
                                        printf("%d ",a[i][j]);
                                    }
                                    printf("\n");
                                }
                                return 0;
                            }
```

### Bài 25. Sắp xếp các phần tử theo cột

Cho ma trận cấp nxm. Sắp xếp các phần tử ở mỗi cột theo thứ tự tăng dần.

**Input**

Dòng đầu tiên là số lượng hàng và cột `n`, `m`. $1 \le n, m \le 100$.
`n` dòng tiếp theo, mỗi dòng `m` cột là các phần tử của ma trận.

**Output**

In ra ma trận sau khi đã sắp xếp các cột của nó.

**Ví dụ**

**Input**
```text
3 3
1 4 1
2 9 8
3 3 1
```

**Output**
```text
1 3 1
2 4 1
3 9 8
```

**Code**
```cpp
                            #include <stdio.h>

                            int main(){
                                int n,m;
                                scanf("%d%d",&n,&m);
                                int a[n][m];
                                for(int i=0; i<n; i++){
                                    for(int j=0; j<m; j++){
                                        scanf("%d",&a[i][j]);
                                    }
                                }

                                // sap xep tung cot
                                for(int j=0; j<m; j++){
                                    for(int i=0; i<n; i++){
                                        int min = i;
                                        for(int k=i+1; k<n; k++){
                                            if(a[k][j]<a[min][j]){
                                                min = k;
                                            }
                                        }
                                        // hoan vi
                                        int temp = a[i][j];
                                        a[i][j] = a[min][j];
                                        a[min][j] = temp;
                                    }
                                }
                                // in ra ket qua
                                for(int i=0; i<n; i++){
                                    for(int j=0; j<m; j++){
                                        printf("%d ",a[i][j]);
                                    }
                                    printf("\n");
                                }
                                return 0;
                            }
```