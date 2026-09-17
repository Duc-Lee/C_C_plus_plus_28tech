# Bài 15. Tìm ước chung lớn nhất của 1 số nguyên lớn với 1 số long long.
Tìm ước chung lớn nhất của 2 số m và n.

**Input**

Dòng đầu tiên là số lượng test case T (1≤T≤100).

Mỗi test case gồm 2 số n và m. Trong đó (0≤m≤10^16, 0≤n≤10^1000).

**Output**

In ra gcd của m và n trên một dòng

**Ví dụ**

| Input | Output |
|---|---|
| 2 | |
| 10120391293189239192318294124871248124172471247179241297417982 | 1 |
| 1000000007 | |
| 12030123012949129491240120410240124912949124912041024010010230135 | 5 |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>
                    
                    // tìm số dư m % n 
                    long long check(char c[], long long m){
                        long long res = 0;
                        for(int i = 0;i<strlen(c);i++){
                            // tính 2 số liền kề
                            res = (res * 10) + c[i] - '0';
                            // tính chia dư luôn
                            res %= m;
                        }
                        return res;
                    }
                    // sau khi có dư của m%n thì tính ước chung lớn nhất
                    long long gcd(long long a,long long b){
                        if(b == 0){
                            return a;
                        }else{
                            // chính vì số dư cuối cùng này
                            // giảm thiểu tìm ước chung bị tràn số do số quá lớn 
                            // tránh trường hợp không tìm được ước chung
                            return gcd(b,a%b);
                        }
                    }
                    int main(){
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            char c[1001], d[1001];
                            scanf("%s%s",c,d);
                            // chuyen chuoi duoi dang so long long
                            // tính sẵn số dư 
                            long long m = check(c,d); 
                            printf("%lld\n",gcd(m,d));
                        }
                        return 0;
                    }

```