### Bài 20. Ma trận xoáy ốc

Cho cấp của ma trận xoáy ốc, in ra ma trận xoáy ốc tương ứng.

**Input**

Dòng duy nhất chứa số nguyên dương `n` không quá 10.

**Output**

In ra ma trận xoáy ốc cấp `n` tương ứng

**Ví dụ**

**Input**
```text
3
```

**Output**
```text
1 2 3
8 9 4
7 6 5
```

**Code**
```cpp
                    #include <stdio.h>
                    
                    int main(){
                        int n;
                        scanf("%d",&n);
                        int a[n][n];
                        int cnt = 1;
                        // khởi tạo biến 
                        int c1 = 0, c2 = n -1, h1 = 0, h2 = n - 1;
                        while(c1 <= c2 && h1 <= h2){
                            // In hang 1 
                            for(int i = c1;i<=c2;i++){
                                a[h1][i] = cnt;
                                ++cnt;
                            }
                            // tang hàng lên
                            ++h1;
                            // In cot ngoài cùng (từ trên xuống dưới)
                            for(int i = h1; i <= h2; i++){
                                a[i][c2] = cnt;
                                ++cnt;
                            }
                            // trừ cột vừa gán
                            --c2;
                            // hàng dưới cùng (từ phải qua trái)
                            if(h1 <= h2){
                                for(int i = c2; i >= c1; i--){
                                    a[h2][i] = cnt;
                                    ++cnt;
                                }
                                --h2;
                            }
                            // cột đầu tiên (từ dưới lên trên)
                            if(c1 <= c2){
                                for(int i = h2; i >= h1; i--){
                                    a[i][c1] = cnt;
                                    ++cnt;
                                }
                                ++c1;
                            }
                        }
                        // In ra ket qua
                        for(int i=0;i<n;i++){
                            for(int j = 0; j<n; j++){
                                printf("%d ",a[i][j]);
                            }
                            printf("\n");
                        }
                        return 0;
                    }
```

### Bài 21. Ma trận xoáy ốc ngược

Cho cấp của ma trận xoáy ốc, in ra ma trận xoáy ốc ngược tương ứng.

**Input**

Dòng duy nhất chứa số nguyên dương `n` không quá 10.

**Output**

In ra ma trận xoáy ốc cấp `n` tương ứng.

**Ví dụ**

**Input**
```text
3
```

**Output**
```text
9 8 7
2 1 6
3 4 5
```

**Code**
```cpp
                    #include <stdio.h>
                    
                    int main(){
                        int n;
                        scanf("%d",&n);
                        int a[n][n];
                        int cnt = n*n;
                        // khởi tạo biến 
                        int c1 = 0, c2 = n -1, h1 = 0, h2 = n - 1;
                        while(c1 <= c2 && h1 <= h2){
                            // In hang 1 
                            for(int i = c1;i<=c2;i++){
                                a[h1][i] = cnt;
                                --cnt;
                            }
                            // tang hàng lên
                            ++h1;
                            // In cot ngoài cùng (từ trên xuống dưới)
                            for(int i = h1; i <= h2; i++){
                                a[i][c2] = cnt;
                                --cnt;
                            }
                            // trừ cột vừa gán
                            --c2;
                            // hàng dưới cùng (từ phải qua trái)
                            if(h1 <= h2){
                                for(int i = c2; i >= c1; i--){
                                    a[h2][i] = cnt;
                                    --cnt;
                                }
                                --h2;
                            }
                            // cột đầu tiên (từ dưới lên trên)
                            if(c1 <= c2){
                                for(int i = h2; i >= h1; i--){
                                    a[i][c1] = cnt;
                                    --cnt;
                                }
                                ++c1;
                            }
                        }
                        // In ra ket qua
                        for(int i=0;i<n;i++){
                            for(int j = 0; j<n; j++){
                                printf("%d ",a[i][j]);
                            }
                            printf("\n");
                        }
                        return 0;
                    }
```

### Bài 22. Ma trận xoáy ốc nguyên tố

Cho cấp của ma trận xoáy ốc, in ra ma trận xoáy ốc gồm các số nguyên tố tăng dần tương ứng.

**Input**

Dòng duy nhất chứa số nguyên dương `n` không quá 10.

**Output**

In ra ma trận xoáy ốc cấp `n` tương ứng.

**Ví dụ**

**Input**
```text
3
```

**Output**
```text
2 3 5
19 23 7
17 13 11
```

**Code**
```cpp
                        #include <stdio.h>
                        
                        // thuat toan sang so nguyen to
                        int p[10005];
                        void sieve(){
                            for(int i=0; i<=10000; i++)
                                p[i] = 1;
                            p[0] = p[1] = 0;
                            for(int i=2; i<=100; i++){
                                if(p[i]){
                                    for(int j=i*i; j<=10000; j+=i)
                                        p[j] = 0;
                                }
                            }
                        }

                        int main(){
                            sieve();
                            int n;
                            scanf("%d", &n);
                            int a[n][n];
                            int cnt = 1;
                            int c1 = 0, c2 = n-1, h1 = 0, h2 = n-1;
                            while(c1<=c2 && h1<=h2){
                                for(int i=c1; i<=c2; i++){
                                    a[h1][i] = p[cnt];
                                    ++cnt;
                                }
                                ++h1;
                                for(int i=h1; i<=h2; i++){
                                    a[i][c2] = p[cnt];
                                    ++cnt;
                                }
                                c2--; 
                                if(h1<=h2){
                                    for(int i=c2; i>=c1; i--){
                                        a[h2][i] = p[cnt];
                                        ++cnt;
                                    }
                                    h2--;
                                }
                                if(c1<=c2){
                                    for(int i=h2; i>=h1; i--){
                                        a[i][c1] = p[cnt];
                                        ++cnt;
                                    }
                                    c1++;
                                }
                            }
                            for(int i=0; i<n; i++){
                                for(int j=0; j<n; j++)
                                    printf("%d ", a[i][j]);
                                printf("\n");
                            }
                            return 0;
                        }   
```

### Bài 23. Ma trận xoáy ốc Fibonacci

Cho cấp của ma trận xoáy ốc, in ra ma trận xoáy ốc gồm các số fibonacci tăng dần tương ứng.

**Input**

Dòng duy nhất chứa số nguyên dương `n` không quá 9.

**Output**

In ra ma trận xoáy ốc cấp `n` tương ứng.

**Ví dụ**

**Input**
```text
3
```

**Output**
```text
0 1 1
13 21 2
8 5 3
```

**Code**
```cpp
                        #include <stdio.h>

                        int f[100];

                        void gen_fib(){
                            f[0] = 0;
                            f[1] = 1;
                            for(int i=2; i<=45; i++)
                                f[i] = f[i-1] + f[i-2];
                        }

                        int main(){
                            gen_fib();
                            int n;
                            scanf("%d", &n);
                            int a[n][n];
                            int cnt = 1;
                            int c1 = 0, c2 = n-1, h1 = 0, h2 = n-1;
                            while(c1<=c2 && h1<=h2){
                                for(int i=c1; i<=c2; i++){
                                    a[h1][i] = f[cnt];
                                    ++cnt;
                                }
                                ++h1;
                                for(int i=h1; i<=h2; i++){
                                    a[i][c2] = f[cnt];
                                    ++cnt;
                                }
                                c2--; 
                                if(h1<=h2){
                                    for(int i=c2; i>=c1; i--){
                                        a[h2][i] = f[cnt];
                                        ++cnt;
                                    }
                                    h2--;
                                }
                                if(c1<=c2){
                                    for(int i=h2; i>=h1; i--){
                                        a[i][c1] = f[cnt];
                                        ++cnt;
                                    }
                                    c1++;
                                }
                            }
                            for(int i=0; i<n; i++){
                                for(int j=0; j<n; j++)
                                    printf("%d ", a[i][j]);
                                printf("\n");
                            }
                            return 0;
                        }
```

### Bài 24. Ma trận xoáy ốc giảm dần ngược chiều kim đồng hồ

Cho cấp của ma trận xoáy ốc, in ra ma trận xoáy ốc giảm dần và ngược chiều kim đồng hồ tương ứng.

**Input**

Dòng duy nhất chứa số nguyên dương `n` không quá 10.

**Output**

In ra ma trận xoáy ốc cấp `n` thỏa mãn yêu cầu.

**Ví dụ**

**Input**
```text
3
```

**Output**
```text
9 2 3
8 1 4
7 6 5
```

**Code**
```cpp
                        #include <stdio.h>

                        int main(){
                            int n;
                            scanf("%d", &n);
                            int a[n][n];
                            int cnt = n*n;
                            int c1 = 0, c2 = n-1, h1 = 0, h2 = n-1;
                            while(c1<=c2 && h1<=h2){
                                // Cột ngoài cùng bên trái (từ dưới lên trên)
                                for(int i=h2; i>=h1; i--){
                                    a[i][c1] = cnt;
                                    --cnt;
                                }
                                ++c1;
                                // Hàng dưới cùng (từ trái sang phải)
                                if(c1<=c2){
                                    for(int i=c1; i<=c2; i++){
                                        a[h2][i] = cnt;
                                        --cnt;
                                    }
                                    --h2;
                                }
                                // Cột ngoài cùng bên phải (từ trên xuống dưới)
                                if(h1<=h2){
                                    for(int i=h1; i<=h2; i++){
                                        a[i][c2] = cnt;
                                        --cnt;
                                    }
                                    --c2;
                                }
                                // Hàng trên cùng (từ phải sang trái)
                                if(c1<=c2){
                                    for(int i=c2; i>=c1; i--){
                                        a[h1][i] = cnt;
                                        --cnt;
                                    }
                                    ++h1;
                                }
                            }
                            for(int i=0; i<n; i++){
                                for(int j=0; j<n; j++)
                                    printf("%d ", a[i][j]);
                                printf("\n");
                            }
                            return 0;
                        }
```

### Bài 25. Xoắn ốc tăng dần theo đường chéo

Cho `n` là kích thước của ma trận xoáy ốc. Hãy điền vào ma trận theo quy luật tăng dần từ góc trên bên phải và xoáy ốc theo chiều kim đồng hồ. Các số trong ma trận xoáy ốc tăng dần theo đường chéo chính từ góc trên cùng bên phải đến góc dưới cùng bên trái, sau đó điền các số tiếp theo theo đường chéo chính tăng dần đến khi gặp đường chéo phụ, tiếp tục điền các số tiếp theo theo quy luật trên cho đến khi đầy ma trận.

**Input**

Dòng duy nhất chứa số nguyên dương `n` (không quá 9).

**Output**

In ra ma trận xoáy ốc theo quy luật trên.

**Ví dụ**

**Input**
```text
3
```

**Output**
```text
1 2 3
8 9 4
7 6 5
```

**Code**
```cpp
                        #include <stdio.h>

                        int main(){
                            int n;
                            scanf("%d", &n);
                            int a[n][n];
                            int cnt = 1;
                            int c1 = 0, c2 = n-1, h1 = 0, h2 = n-1;
                            while(c1<=c2 && h1<=h2){
                                // Đường chéo phụ (từ trên phải xuống dưới trái)
                                for(int i=c2, j=h1; i>=c1 && j<=h2; i--, j++){
                                    a[j][i] = cnt;
                                    ++cnt;
                                }
                                --c2;
                                --h1;
                                // Đường chéo chính (từ dưới trái lên trên phải)
                                if(c1<=c2 && h1<=h2){
                                    for(int i=c1, j=h2; i<=c2 && j>=h1; i++, j--){
                                        a[j][i] = cnt;
                                        ++cnt;
                                    }
                                    ++c1;
                                    ++h2;
                                }
                            }
                            for(int i=0; i<n; i++){
                                for(int j=0; j<n; j++)
                                    printf("%d ", a[i][j]);
                                printf("\n");
                            }
                            return 0;
                        }
```
