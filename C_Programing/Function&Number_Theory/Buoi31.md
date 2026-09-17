**Bài 13. Số đẹp.**

Một số được coi là đẹp nếu nó là số nguyên tố và tổng chữ số là một số trong dãy Fibonaci. Viết chương trình liệt kê trong một đoạn giữa hai số nguyên cho trước có bao nhiêu số đẹp như vậy.

**Input**

Dòng duy nhất là 2 số nguyên dương a, b (1≤a≤b≤10⁹).

**Output**

In ra các số đẹp trong đoạn từ a tới b. Trong trường hợp không tồn tại số đẹp trong đoạn từ a tới b thì in ra -1.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2 50 | 2 3 5 11 17 23 41 |
| 24 30 | -1 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                int prime_check(int n){
                    for(int i = 2; i <= sqrt(n);i++){
                        if(n % i == 0) return 0;
                    }
                    return n>1;
                }

                int sumdigit(int n){
                    // neu n la so nguyen to
                    int sum = 0;
                    while(n != 0){
                        sum += n % 10;
                        n /= 10;
                    }
                    return sum;
                }

                int fibonanci(int n){
                    if ( n == 0 || n == 1) return 1;
                    int f1 = 0, f2 = 1;
                    // loop until f2 >= n
                    while(f2 < n){
                        // f = f1 + f2, day la so fibo tiep theo
                        int f = f1 + f2;
                        // f1 = f2, f2 = f, update f1, f2
                        f1 = f2;
                        f2 = f;
                    }
                    // f2 chinh la f da duoc luu lai sau khi f1 + f2
                    return f2 == n;
                }

                void check(int a, int b){
                    int ok = 0;
                    // neu tong so nguyen to la so fibo
                    for(int i = a; i <= b; i++){
                        if(prime_check(i) && fibonanci(sumdigit(i))){
                            printf("%d ",i);
                            ok = 1;
                        }
                    }
                    if(ok == 0){
                        printf("-1");
                    }
                }

                int main(){
                    int a, b;
                    scanf("%d %d",&a,&b);
                    check(a,b);
                }
```