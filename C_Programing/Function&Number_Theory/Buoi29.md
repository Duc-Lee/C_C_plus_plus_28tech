# **Bài 9. Tổng chữ số.**

Tính tổng chữ số của 1 số nguyên dương n.

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là 1 số nguyên dương n (1≤n≤10¹⁸)

**Output**

Mỗi test case in ra trên 1 dòng tổng các chữ số của n.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>1000000000000000<br>124 | 1<br>7 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                // ham tinh tong cac chu so 
                int sumdigit(long long n){
                    int sum = 0;
                    while(n != 0){
                        sum += n % 10;
                        n /= 10;
                    }
                    return sum;
                }
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        long long n;
                        scanf("%lld",&n);
                        printf("%d\n",sumdigit(n));
                    }
                }
```