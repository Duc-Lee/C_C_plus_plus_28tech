### Bài 3. Tìm hàng có nhiều số nguyên tố nhất

Cho ma trận có n hàng, m cột, hãy tìm hàng có nhiều số nguyên tố nhất.

**Input**

Dòng đầu tiên là `n`, `m`. $1 \le n,m \le 100$.
`n` dòng tiếp theo, mỗi dòng có `m` số nguyên.

**Output**

In ra hàng có nhiều số nguyên tố nhất và liệt kê các số nguyên tố trên hàng đó. Trong trường hợp có nhiều hàng có cùng số lượng số nguyên tố thì in ra hàng đầu tiên.

**Ví dụ**

**Input**
```text
3 3
23 11 22
14 5 9
2 3 90
```

**Output**
```text
1
23 11
```

**Code**
```cpp
                        #include <stdio.h>
                        
                        int check(int n){
                            // kiểm tra số  nguyên tố 
                            for(int i = 2; i*i <= n;i++){
                                if(n % i == 0) return 0;
                            }
                            return n > 1;
                        }

                        int main(){
                            int n, m;
                            scanf("%d%d",&n,&m);
                            int x, b[n][m];
                            int cnt = 0, row = 0; 
                            // nhập ma trận 2 chiều 
                            for(int i = 0;i<n;i++){
                                int res = 0;
                                for(int j = 0; j < m ;j++){
                                    scanf("%d",&x);
                                    // kiểm tra xem có phải số nguyên tố ko
                                    if(check(x)){
                                        b[i][res++] = x;
                                    }
                                }
                                // tìm kỉ lục
                                if(res > cnt){
                                    cnt = res;
                                    row = i;
                                }
                            }
                            printf("%d\n",row+1);
                            for(int i = 0;i<cnt;i++){
                                // in kết quả hàng i 
                                printf("%d ",b[row][i]);
                            }
                        }
```

### Bài 4. Tìm cột có nhiều số nguyên tố nhất

Cho ma trận có n hàng, m cột, hãy tìm cột có nhiều số nguyên tố nhất

**Input**

Dòng đầu tiên là `n`, `m`. $1 \le n,m \le 100$.
`n` dòng tiếp theo, mỗi dòng có `m` số nguyên.

**Output**

In ra cột có nhiều số nguyên tố nhất và liệt kê các số nguyên tố trên cột đó. Trong trường hợp có nhiều cột có cùng số lượng số nguyên tố thì in ra cột đầu tiên

**Ví dụ**

**Input**
```text
3 3
23 11 22
14 5 9
2 3 90
```

**Output**
```text
2
11 5 3
```

**Code**
```cpp
                        #include <stdio.h>
                        
                        int check(int n){
                            // kiểm tra số nguyên tố 
                            for(int i = 2; i*i <= n;i++){
                                if(n % i == 0) return 0;
                            }
                            return n > 1;
                        }

                        int main(){
                            int n, m;
                            scanf("%d%d",&n,&m);
                            int a[n][m];
                            // nhap ma tran 
                            for(int i = 0;i<n;i++){
                                for(int j = 0;j<m;j++){
                                    scanf("%d",&a[i][j]);
                                }
                            }
                            int cnt = 0, cot = 0;
                            // duyệt ma trận theo chuyển vị 
                            for(int i = 0;i<m;i++){
                                int res = 0;
                                for(int j =0;j<n;j++){
                                    if(check(a[i][j])){
                                        ++res;
                                    }
                                }
                                // tìm kỉ lục 
                                if(cnt < res){
                                    cnt = res;
                                    cot = i;
                                }
                            }
                            // In ket qua 
                            printf("%d\n",cot + 1);
                            for(int i = 0;i<cnt;i++){
                                if(check(a[i][cot])){
                                    printf("%d ",a[i][cot]);
                                }
                            }
                        }
```