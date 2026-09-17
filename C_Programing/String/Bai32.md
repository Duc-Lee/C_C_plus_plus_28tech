# Bài 14. Tìm số dư của 1 số nguyên lớn với 1 số long long.

Cho số nguyên dương N rất lớn được biểu diễn như một xâu và số M. Hãy tìm K = N%M.
Ví dụ N=123456789873123456778976, M = 100 thì K=76.

**Input:**

Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp mỗi dòng đưa vào các test. Mỗi test là bộ đôi N, M được viết trên hai dòng khác nhau.

T, N, M thỏa mãn ràng buộc : 1≤T≤100; 0≤length(N)≤1000; 2≤M ≤10^12.

**Output:**

Đưa ra kết quả mỗi test theo từng dòng.

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>
                    
                    long long check(char c[], long long m){
                        long long sum = 0;
                        for(int i = 0;i<strlen(c);i++){
                            // chuyen ky tu thanh so 
                            // duyệt mỗi ký tự trong chuỗi số N 
                            // nén chuỗi số N lại (giảm dung lượng dữ liệu) bằng cách chia lấy dư mỗi bước 
                            // sau khi duyệt xong thì ta được kết quả cuối cùng 
                            sum = sum * 10 + (c[i] - '0');
                            // tính chia dư mỗi bước luôn
                            // ví dụ 123 chia 7 
                            // first loop: sum = 1 % 7 = 1
                            // second loop: sum = 1 * 10 + 2 = 12
                            // 12 % 7 = 5
                            // third loop: sum = 5 * 10 + 3 = 53
                            // 53 % 7 = 4
                            // không làm ảnh hưởng tới kết quả cuối cùng 
                            sum %= m;
                        }
                        return sum;
                    }
                    int main(){
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            char c[1001];
                            scanf("%s",c);
                            long long m;
                            scanf("%lld",&m);
                            printf("%lld\n",check(c,m));
                        }
                        return 0;
                    }

```