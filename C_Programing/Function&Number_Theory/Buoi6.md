**Bài 6. Liệt kê N số nguyên tố đầu tiên**

Viết chương trình liệt kê N số nguyên tố đầu tiên với N là một số nguyên dương không quá $10^5$.

**Input**

Dữ liệu vào chỉ có duy nhất một số N.

**Output**

Kết quả ghi mỗi số nguyên tố trên một dòng, theo thứ tự từ nhỏ đến lớn.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 5 | 2<br>3<br>5<br>7<br>11 |

**Code**
```cpp
        #include <stdio.h>
        #include <math.h>

        int prime[1000001];
        void sieve(){
            // khoi tao 
            for(int i = 0; i < 1000001; i++){
                prime[i] = 1;
            }
            prime[0] = prime[1] = 0;
            for(int i = 2; i <= sqrt(1000001); i++){
                if(prime[i]){
                    for(int j = i * i; j < 1000001; j += i){
                        prime[j] = 0;
                    }
                }
            }
        }
        
        int main(){
            int n;
            scanf("%d",&n);
            sieve();
            int cnt = 0;
            for(int i = 2; i < 1000001; i++){
                if(prime[i]){
                    printf("%d\n",i);
                    ++cnt;
                    if(cnt == n){
                        break;
                    }
                }
            }
            return 0;
        }
```