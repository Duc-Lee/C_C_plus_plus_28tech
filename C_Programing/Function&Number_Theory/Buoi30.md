**Bài 11. Fibonacci.**

Dãy số Fibonacci được định nghĩa như sau: F0 = 0, F1 = 1; Fi = Fi-1 + Fi-2.

Cho số nguyên dương n, với 2≤n≤92. Hãy viết chương trình in ra n số Fibonacci đầu tiên.

**Input**

Số nguyên dương n (2≤n≤92)

**Output**

n số fibonacci đầu tiên, mỗi số được in cách nhau một dấu cách.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 5 | 0 1 1 2 3 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                // ham tinh n so fibonacci 
                int fibo(int n){
                    if(n == 0 || n == 1)
                        return n;
                    else return fibo(n-1) + fibo(n-2);
                }
                // ham tinh n so fibonacci
                void fibonacci(int n){
                    if(n == 1){
                        printf("0");
                        return;
                    }
                    if(n == 2){
                        printf("0 1");
                        return;
                    }
                    printf("0 1 ");
                    long long a = 0, b = 1;
                    for(int i = 3; i <= n; i++){
                        long long c = a + b;
                        printf("%lld ",c);
                        a = b;
                        b = c;
                    }
                }

                void selve(int n){
                    long long fibo[n];
                    fibo[0] = 0;
                    fibo[1] = 1;
                    // tinh fibo den n
                    for(int i = 2; i < n; i++){
                        fibo[i] = fibo[i-1] + fibo[i-2];
                    }
                    // in fibo
                    for(int i = 0; i < n; i++){
                        printf("%lld ",fibo[i]);
                    }
                }
                int main(){
                    int n;
                    scanf("%d",&n);
                    for(int i = 0; i < n; i++){
                        printf("%d ",fibo(i));
                    }
                }
```

# **Bài 12. Kiểm tra số fibonacci.**

Nhập vào một số và kiểm tra xem số vừa nhập có phải là số trong dãy fibonacci hay không?

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là 1 số nguyên dương n (1≤n≤10¹⁸)

**Output**

Mỗi test case in trên 1 dòng, in YES nếu n là số fibonacci, ngược lại in NO.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 3<br>2<br>4<br>420196140727489673 | YES<br>NO<br>YES |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                void fibonanci(){
                    long long fibo[100];
                    fibo[0] = 0;
                    fibo[1] = 1;
                    // tinh fibo[i]
                    for(int i = 2; i< 100;i++){
                        fibo[i] = fibo[i-1] + fibo[i-2];
                    }
                }
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        // khoi tao bien check 
                        int ok = 0;
                        for(int i = 0; i < n ;i++){
                            if(i == fibo[i]){
                                ok = 1;
                                break;
                            }
                        }
                        if(ok){
                            printf("YES\n");
                        }else{
                            printf("NO\n");
                        }
                    }
                }
```