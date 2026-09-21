**Bài 4. Fibonacci modulo.**

Dãy số Fibonacci được định nghĩa $F_n = F_{n-1} + F_{n-2}$ với $n > 1$ và $F_0 = 0, F_1 = 1$. Dưới đây là một số số Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21...

Nhiệm vụ của bạn là tìm số Fibonacci thứ n.

**Input:**
- Dòng đầu tiên đưa vào số lượng bộ test T.
- Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên dương n.
- T, n thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le n \le 1000$.

**Output:**
- Đưa ra kết quả mỗi test theo modulo $10^9 + 7$ theo từng dòng.

**Ví dụ:**

| Input | Output |
| :--- | :--- |
| 2<br>2<br>5 | 1<br>5 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                #define ll long long 
                const ll MOD = 1e9 + 7;

                // su dung phuong phap thong thuong 
                int fibo(int n){
                    if(n == 0 || n == 1) return n;
                    return (fibo(n-1)%MOD + fibo(n-2)%MOD)%MOD;
                }
                
                // su dung sang so 
                int fibo1[1001];
                void sangso(){
                    fibo1[0] = 0;
                    fibo1[1] = 1;
                    // duyet tu 2
                    for(int i = 2; i<= 1000;i++){
                        fibo[i] = fibo[i-1] + fibo[i-2];
                        fibo[i] %= MOD;
                    }
                }
                
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        // 
                        
                    }
                    return 0;
                }
```