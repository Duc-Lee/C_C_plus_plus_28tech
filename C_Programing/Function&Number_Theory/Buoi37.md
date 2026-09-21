**Bài 23. Nguyên tố cùng nhau.**

Nhập 2 số nguyên dương a,b. Xác định xem 2 số vừa nhập có phải là 2 số nguyên tố cùng nhau.

**Input**

2 số nguyên dương a,b (1 ≤ a,b ≤ 10^12).

**Output**

In YES nếu 2 số a,b nguyên tố cùng nhau, ngược lại in NO.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 20 17 | YES |
| 14 15 | YES |
| 8 128 | NO |

**Code**

```cpp
                #include <stdio.h>

                // 2 so nguyen to cung nhau la 2 so co UCLN = 1
                // Ham tim UCLN bang thuat toan Euclid
                long long gcd(long long a, long long b) {
                    while (b != 0) {
                        long long r = a % b;
                        a = b;
                        b = r;
                    }
                    return a;
                }

                // su dung de quy 
                long long gcd_recursive(long long a, long long b){
                    if(b == 0) return a;
                    return gcd_recursive(b, a%b);
                }

                int main(){
                    long long a, b;
                    // Đề bài cho a, b lên tới 10^12 nên phải dùng long long
                    scanf("%lld %lld", &a, &b);
                    // Nếu ƯCLN(a, b) == 1 thì là 2 số nguyên tố cùng nhau
                    if(gcd(a, b) == 1){
                        printf("YES\n");
                    }else{
                        printf("NO\n");
                    }
                    return 0;
                }
```

---

**Bài 24. Phi hàm Euler.**

Đếm số lượng các số nguyên tố cùng nhau với n không vượt quá n.

**Input**

Số nguyên duy nhất n (1 ≤ n ≤ 10^16).

**Output**

Kết quả của bài toán.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 9 | 6 |
| 10000000000000000 | 4000000000000000 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                // Hàm tính Phi hàm Euler trong O(sqrt(N))
                long long phi(long long n) {
                    long long res = n;
                    for (long long i = 2; i <= sqrt(n); i++) {
                        if (n % i == 0) {
                            // Chia để loại bỏ hết các thừa số nguyên tố i
                            while (n % i == 0) {
                                n /= i;
                            }
                            // Công thức Euler: res = res * (1 - 1/i) = res - res / i
                            res -= res / i;
                        }
                    }
                    // Nếu n > 1 thì n còn lại chính là thừa số nguyên tố cuối cùng
                    if (n > 1) {
                        res -= res / n;
                    }
                    return res;
                }

                int main(){
                    long long n;
                    // Đề cho n lên tới 10^16 nên phải dùng long long
                    scanf("%lld", &n);
                    printf("%lld\n", phi(n));
                    return 0;
                }
```

### Giải thích: Phi hàm Euler

Công thức Phi hàm Euler (Euler's Totient Function):
$$ \phi(n) = n \prod_{p|n} \left(1 - \frac{1}{p}\right) $$

**Trong đó:**
- $\phi(n)$: Là số lượng các số nguyên dương không vượt quá $n$ và nguyên tố cùng nhau với $n$ (tức là có ƯCLN với $n$ bằng 1).
- Ký hiệu $\prod$ (Pi): Là ký hiệu của "Tích" (nhân liên tiếp các biểu thức), tương tự như $\sum$ (Sigma) đại diện cho "Tổng".
- $p|n$: Có nghĩa là điều kiện duyệt. Ở đây ta lấy tích qua tất cả các số nguyên tố $p$ là **thừa số nguyên tố** của $n$.

**Ý nghĩa thuật toán:**
Thay vì phải dùng vòng lặp thử từng số nhỏ hơn $n$ xem ƯCLN có bằng 1 hay không (cách này rất chậm), ta chỉ cần **phân tích $n$ ra thừa số nguyên tố**. 
Với mỗi thừa số nguyên tố $p$ tìm được, ta đem nhân kết quả (ban đầu bằng $n$) với $(1 - \frac{1}{p})$.
- Trong code C++, phép toán $res \times (1 - \frac{1}{p})$ được biến đổi thành $res - \frac{res}{p}$ và viết gọn lại thành `res -= res / p`. Viết như thế này giúp code luôn tính toán trên số nguyên, không bị sai số (nếu dùng số thập phân float/double).
- Nhờ công thức này, bài toán quy về việc tìm các thừa số nguyên tố của $n$, do đó vòng lặp chỉ cần chạy tới tối đa $\sqrt{n}$. Thuật toán $O(\sqrt{N})$ này giúp chương trình chạy chớp nhoáng (chưa tới 1 giây) kể cả khi $n$ lớn lên tới $10^{16}$.