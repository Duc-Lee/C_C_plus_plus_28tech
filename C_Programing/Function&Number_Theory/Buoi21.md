**Bài 8**. Ước số nguyên tố lớn nhất của số nguyên dương.

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là một số nguyên dương n (1≤n≤10⁶)

**Output**

Ước số nguyên tố lớn nhất của n in ra mỗi test case trên 1 dòng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>10<br>17 | <br>5<br>17 |

**Code**
```cpp
            #include <stdio.h>
            #include <math.h>

            int solve(int n){
                int res = -1; // bien uoc lon nhat 
                // duyet qua cac thua so nguyen to 
                for(int i = 2; i <= sqrt(n);i++){
                    // giam het so uoc so nho nhat 
                    // vi du 10 = 2 . 5 
                    // giam cho 2 thi con 5, 5 la uoc lon nhat 
                    while(n % i == 0){
                        // i la uoc so hien tai
                        // dung vong lap de tim uoc lon nhat 
                        res = i;
                        n /= i;
                    }
                }
                // neu n != 1 tuc la n la so nguyen to 
                if(n != 1) res = n;
                return res;
            }
            int main(){
                int t;
                scanf("%d",&t);
                while(t--){
                    int n;
                    scanf("%d",&n);
                    printf("%d\n",solve(n));
                }
            }
```