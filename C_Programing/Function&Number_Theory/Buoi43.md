**Bài 32. Lũy thừa nhị phân.**

Tính a^b với a,b nguyên không âm.

**Input**

Dòng đầu tiên là số lượng bộ test T. (1≤T≤100).

Mỗi test case là một số nguyên dương a,b.

**Output**

In kết quả mỗi test case trên 1 dòng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>2 10<br>3 3 | <br>1024<br>27 |

**Code**
```cpp
                #include <stdio.h>
                
                // cach lam ngay tho 
                int solve1(int n, int k){
                    int res = 1;
                    for(int i = 1; i<= k; i++){
                        // nhan k lan
                        res *= n;
                    }
                    return res;
                }

                // cach lam tot hon 
                // chi can nhan n/2 lan 
                int solve2(int n, int k){
                    // y tuong la n^k = n^(k/2) * n^(k/2)
                    // neu k la so le 
                    // thi n^k = n^(k-1) * n
                    // n^(k/2) tinh 1 lan roi nhan 2
                    // vi du : n = 2, k = 7 
                    // k = 7 la so le 
                    // res = 1 * 2 = 2
                    // n = 2 * 2 = 4
                    // k = 7 / 2 = 3
                    // k = 3 la so le 
                    // res = 2 * 4 = 8
                    // n = 4 * 4 = 16
                    // k = 3 / 2 = 1
                    // k = 1 la so le 
                    // res = 8 * 16 = 128
                    // n = 16 * 16 = 256
                    // k = 1 / 2 = 0
                    // k = 0 thi break
                    int res = 1;
                    while(k){
                        // neu k la so le 
                        // khi gap 1 so le
                        // khi chia doi lien tuc so mu 
                        // se co 1 co so bi du ra 
                        // do la khi n^1, n^3, n^5,...
                        // duoc nhan vao res de bu
                        // con cac so mu khac n^(2^x)
                        if(k%2 == 1){
                            res *= n;
                        }
                        // nhan gap doi n
                        n *= n;
                        // chia doi k
                        k /= 2;
                    }  
                    return res;      
                }

                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n,k;
                        scanf("%d %d",&n,&k);
                        printf("%d\n",solve2(n,k));
                    }
                    return 0;
                }
```