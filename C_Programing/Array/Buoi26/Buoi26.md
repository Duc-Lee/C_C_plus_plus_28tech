### Bài 10. Đếm số nguyên tố trên đường chéo chính, phụ 1

Đếm số lượng số nguyên tố trên đường chéo chính và đường chéo phụ, mỗi phần tử thỏa mãn chỉ đếm một lần.

**Input**

Dòng đầu tiên là `n`: Cấp của ma trận. $1 \le n \le 100$.
`n` dòng tiếp theo, mỗi dòng có `n` số nguyên.

**Output**

In ra số lượng phần tử là số nguyên tố thuộc đường chéo chính hoặc đường chéo phụ

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
3
```

**Code**
```cpp
                                #include <stdio.h>
                                // ham check so nguyen to
                                int check(int n){
                                    for(int i = 2;i*i<=n;i++){
                                        if(n%i==0) return 0;
                                    }
                                    return n > 1;
                                }
                                int main(){
                                    int n;
                                    scanf("%d",&n);
                                    int a[n][n];
                                    for(int i = 0;i<n;i++){
                                        for(int j = 0;j<n;j++){
                                            scanf("%d",&a[i][j]);
                                        }
                                    }
                                    int cnt = 0;
                                    for(int i = 0; i < n; i++){
                                        // Kiem tra duong cheo chinh
                                        if(check(a[i][i])) ++cnt;
                                        // Kiem tra duong cheo phu 
                                        // Neu vi tri khac duong cheo chinh de tranh dem trung o phan tu trung tam
                                        if(i != n - 1 - i){
                                            if(check(a[i][n - 1 - i])) ++cnt;
                                        }
                                    }
                                    printf("%d\n",cnt);
                                }
```

### Bài 11. Đếm số nguyên tố trên đường chéo chính, phụ 2

Đếm số lượng số nguyên tố trên đường chéo chính và đường chéo phụ, mỗi giá trị thỏa mãn chỉ đếm 1 lần.

**Input**

Dòng đầu tiên là `n`: Cấp của ma trận. $1 \le n \le 100$.
`n` dòng tiếp theo, mỗi dòng có `n` số nguyên. Các số đều là số nguyên dương không vượt quá 10000.

**Output**

In ra số lượng phần tử là số nguyên tố thuộc đường chéo chính hoặc đường chéo phụ

**Ví dụ**

**Input**
```text
3
1 2 3
4 5 6
7 8 3
```

**Output**
```text
3
```

**Code**
```cpp
                            #include <stdio.h>
                            // check so nguyen to 
                            int check(int n){
                                for(int i = 2;i*i<=n;i++){
                                    if(n%i==0) return 0;
                                }
                                return n>1;
                            }
                            int main(){
                                int n;
                                scanf("%d",&n);
                                int a[n][n];
                                for(int i = 0;i<n;i++){
                                    for(int j = 0;j<n;j++){
                                        scanf("%d",&a[i][j]);
                                    }
                                }
                                int cnt = 0;
                                // mang danh dau phai co kich thuoc du lon de chua gia tri lon nhat la 10000
                                int b[10005] = {0};
                                for(int i = 0;i < n;i++){
                                    // duong cheo chinh 
                                    if(check(a[i][i]) && b[a[i][i]] == 0){
                                        cnt++;
                                        b[a[i][i]] = 1;
                                    }
                                    // duong cheo phu
                                    if(check(a[i][n-1-i]) && b[a[i][n-1-i]] == 0){
                                        cnt++;
                                        b[a[i][n-1-i]] = 1;
                                    }
                                }
                                printf("%d\n", cnt);
                            }
```

**Cách 2: Dùng sàng số nguyên tố (Sieve of Eratosthenes)**
- Cơ bản vẫn giống cách 1, chỉ khác thay vì dùng hàm `check()` và mảng `b`, ta dùng sàng số nguyên tố `p`. Sàng số nguyên tố sẽ là:
```cpp
                            #include <stdio.h>

                            int p[10005];

                            void sieve(){
                                for(int i=0;i<=10000;i++)
                                    p[i] = 1;
                                p[0] = p[1] = 0;
                                for(int i=2;i<=100;i++){
                                    if(p[i]){
                                        for(int j=i*i;j<=10000;j+=i)
                                            p[j] = 0;
                                    }
                                }
                            }

                            int main(){
                                sieve();
                                int n;
                                scanf("%d", &n);
                                int a[n][n];
                                for(int i=0;i<n;i++){
                                    for(int j=0;j<n;j++){
                                        scanf("%d", &a[i][j]);
                                    }
                                }
                                int cnt = 0;
                                for(int i=0;i<n;i++){
                                    if(p[a[i][i]]){
                                        ++cnt; 
                                        p[a[i][i]] = 0; // Danh dau da dem roi thi xoa di
                                    }
                                    if(p[a[i][n-i-1]]){
                                        ++cnt; 
                                        p[a[i][n-i-1]] = 0;
                                    }
                                }
                                printf("%d\n", cnt);
                                return 0;
                            }
```