# Bài 16. Tìm (a^b)%MOD trong đó a là số nguyên lớn

Cho số nguyên dương a, b, M, trong đó a là số rất lớn được biểu diễn như một xâu ký tự số. Hãy tìm K = (a^b) %M. Ví dụ a = 3, b=2, M = 4 thì K = (3^2)%4 = 1

**Input:**

Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là bộ ba a, b, M được viết trên một dòng.

T, a, b, M thỏa mãn ràng buộc : 1≤T≤100; 0≤length(a) ≤1000; 2≤ b, M ≤10^12.

**Output:**

Đưa ra kết quả mỗi test theo từng dòng.

**Ví dụ**

| Input | Output |
|---|---|
| 1 | |
| 3 2 4 | 1 |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>
                    
                    // tính a%b với a là số rất lớn
                    long long find(long a[], long long b){
                        long long res = 0;
                        for(int i = 0;i< strlen(a);i++){
                            res = res * 10 + a[i] - '0';
                            // tính dư luôn từng bước 
                            res %= 10;
                        }
                        return res;
                    }
                    // (a^b) % m = (a%m)^b % m 
                    // tính (a^b) % m bằng phương pháp lũy thừa nhị phân 
                    // vì a có thể là số rất lớn 
                    // vì vậy ta chia lấy dư luôn 
                    // giảm thiểu tìm ước chung bị tràn số do số quá lớn 
                    // tránh trường hợp không tìm được ước chung
                    long long powmod(long long a, long long b, long long m){
                        long long res = 1;
                        while(b){
                            // b lẻ không thể chia đôi 
                            // nên chia lẻ a ra 
                            // nếu lẻ sẽ tính trực tiếp vào kết quả cuối cùng 
                            // nếu chẵn thì chia 2 a ra 
                            if(b % 2 == 1){
                                res *= a;
                                // tính đến đâu chia dư tới đó để ko bị phình to th
                                res %= m;
                            }
                            // áp dụng (a^2)^(b/2) % m = a^b % m 
                            // gộp cả phép tính b chẵn, b lẻ luôn cùng 1 vòng lặp
                            // để giảm số lần lặp, tận dụng tính toán 
                            a *= a;
                            // tính đến đâu chia dư tới đó để không bị phình to 
                            a %= m; 
                            // giảm số mũ b 
                            b /= 2; 
                        }
                        return res;
                    }
                    int main(){
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            char c[1001];
                            long long b, m;
                            scanf("%s%lld%lld",c,&b,&m);
                            // (a^b) % m = (a%m)^b % m 
                            // ví dụ 123 ^ 2 % 10 = 15129 % 10 = 9 
                            // (123 % 10) ^ 2 % 10 = 3 ^ 2 % 10 = 9 
                            // do số a có thể là số rất lớn
                            // vì vậy ta chia lấy dư luôn 
                            // giảm thiểu tìm ước chung bị tràn số do số quá lớn 
                            // tránh trường hợp không tìm được ước chung
                            long long a = find(c,m);
                            printf("%lld\n",powmod(a,b,m));
                        }
                        return 0;
                    }

```