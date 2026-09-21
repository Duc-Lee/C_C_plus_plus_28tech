**Bài 25. Thừa số nguyên tố thứ k**

Đưa ra số nguyên tố thứ k trong phân tích thừa số nguyên tố của một số nguyên dương n.

Ví dụ n=28, k=3 ta có kết quả là 7 vì 28=2x2x7.

**Input**

2 số n,k (1 ≤ n,k ≤ 10^9).

**Output**

In ra số nguyên tố thứ k trong phân tích thừa số nguyên tố của n, trường hợp không tồn tại in -1.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 28 3 | 7 |
| 8 5 | -1 |
| 60 3 | 3 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                long long check(long long n, long long k){
                    long long cnt = 0;
                    for(long long i = 2; i <= sqrt(n);i++){
                        if(n % i == 0){
                            while( n % i == 0){
                                ++cnt;
                                n /= i;
                                //neu thua so nguyen to thu k la i
                                if(cnt == k) return i; 
                            }
                        }
                    }
                    // neu n la so nguyen to 
                    if( n != 1) ++cnt;
                    // neu thua so nguyen so thu k
                    // cnt == k lan nua o day de tranh truong hop thua so nguyen to lon nhat la n
                    // vi du n = 7, k = 1, khi chay vong for i <= sqrt(n) no chi chay den 2
                    if( cnt == k) return n;
                    // neu khong thi khong co thua so nguyen to thu k
                    return -1;
                }
                int main(){
                    long long n, k;
                    scanf("%lld %lld", &n, &k);
                    printf("%lld\n", check(n, k));
                    return 0;
                }

```
---

**Bài 26. Chữ số nguyên tố**

Liệt kê số lần xuất hiện của chữ số nguyên tố của 1 số theo thứ tự từ nhỏ đến lớn.

**Input**

Số nguyên dương n (1 ≤ n ≤ 10^18).

**Output**

Chữ số nguyên tố xuất hiện trong số ban đầu cùng với số lần xuất hiện của nó.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 722334123232277 | 2 6<br>3 4<br>7 3 |

**Code**
```cpp
                #include <stdio.h>
                
                // khoi tao mang tan suat 
                int arr[10] = {0};
                
                void prime_digits(long long n){
                    // Tach tung chu so de kiem tra
                    while(n > 0){
                        int digit = n % 10;
                        // Neu la chu so nguyen to
                        if(digit == 2 || digit == 3 || digit == 5 || digit == 7){
                            arr[digit]++;
                        }
                        n /= 10;
                    }
                }

                int main(){
                    long long n;
                    scanf("%lld", &n);
                    prime_digits(n);
                    // In ra tu nho den lon (tu 2 den 7)
                    for(int i = 2 ; i <= 7 ; i++){
                        if(arr[i] != 0){
                            printf("%d %d\n", i, arr[i]);
                        }
                    }
                    return 0;
                }
```
