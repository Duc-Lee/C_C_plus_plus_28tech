**Bài 30. Ước chung lớn nhất, bội chung nhỏ nhất.**

Tìm ước chung lớn nhất của 2 số nguyên không âm a và b.

**Input**

2 số nguyên không âm a và b (0 ≤ a, b ≤ 10^9).

**Output**

In ra ước chung lớn nhất của 2 số và bội chung nhỏ nhất của 2 số.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 100 20 | 20 100 |
| 17 29 | 1 493 |

**Code**
```cpp
                #include <stdio.h>
                
                // Hàm tìm ước chung lớn nhất (GCD) của 2 số không âm a và b
                // sử dụng thuật toán Euclidean
                // Độ phức tạp: O(log(min(a, b)))
                long long gcd(long long a, long long b){
                    while(b){
                        a %= b;
                        long long temp = a;
                        a = b;
                        b = temp;
                    }
                    return a;
                }
                // Định nghĩa hàm lcm với a, b là số nguyên không âm 
                // (0,x)=x,(0,0)=0
                long long lcm(long long a, long long b){
                    if(a == 0 || b == 0){
                        return a + b;
                    }
                    // (a*b)/gcd(a,b) 
                    // để tránh tràn số nên dùng (a / gcd(a, b)) * b
                    return (a / gcd(a, b)) * b;
                }
                int main(){
                    long long a, b;
                    scanf("%lld %lld", &a, &b);
                    printf("%lld %lld", gcd(a, b), lcm(a, b));
                    return 0;
                }  
```
