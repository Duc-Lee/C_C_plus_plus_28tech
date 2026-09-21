**Bài 31. Phi hàm Euler sử dụng sàng số nguyên tố.**

Cho số nguyên dương n, nhiệm vụ của bạn là in ra φ(i) với 1≤i≤n. Trong đó φ(i) là phi hàm Euler của i.

**Input**

Dòng đầu tiên là số lượng bộ test T. (1≤T≤100).

Mỗi test case là một số nguyên dương n (1≤n≤10^6).

**Output**

In kết quả mỗi test case trên 1 dòng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 1<br>10 | 1 1 2 2 4 2 6 4 6 4 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                // su dung thuat toan sang so nguyen to 
                // khai tao mang so nguyen to 
                int prime[1000001];
                void selve(){
                    // gan tat ca gia tri prime[i] = i
                    for(int i = 1; i<= 1000000;i++){
                        prime[i] = i;
                    }
                    // loc cac so nguyen to 
                    for(int i = 2; i<= 1000000;i++){
                        // neu i chua tung bi so nguyen to nao nho hon cham toi
                        // thi i la so nguyen to 
                        // voi so nt p thi tat ca cac so tu 1 den p-1 deu ngt cung nhau voi p
                        // do do phi[p] = p - 1
                        if(prime[i] == i){
                            // theo cong thuc euler 
                            // phi = n* (xich ma )(1 - 1/p) = n - n/p, p la so nguyen to 
                            prime[i] = i - 1;
                            // loc cac boi cua i 
                            // khi gap 1 so chia het cho i 
                            for(int j = 2*i; j <= 1000000; j += i){
                                prime[j] -= prime[j]/i;
                            }
                        }
                    }
                }
                
                int main(){
                    selve();
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        for(int i = 1; i<= n; i++){
                            printf("%d ",prime[i]);
                        }
                        printf("\n");
                    }
                }
```

1. Ý nghĩa toán học của Phi hàm Euler 
- $\phi(n)$ đếm số lượng các số nguyên từ $1$ đến $n$ nguyên tố cùng nhau với $n$ (tức là có $\gcd(k, n) = 1$).
Ví dụ: Với $n = 6$:
- Các số từ $1$ đến $6$ là: $1, 2, 3, 4, 5, 6$.
- Các số nguyên tố cùng nhau với $6$ là: $1$ và $5$ (vì $\gcd(1,6)=1$, $\gcd(5,6)=1$).
- Các số bị loại: $2, 4, 6$ (chia hết cho $2$) và $3, 6$ (chia hết cho $3$).
Vậy $\phi(6) = 2$.

2. Công thức tính $\phi(n)$ (Công thức tích Euler)
Nếu một số $n$ phân tích ra thừa số nguyên tố có dạng:
$$n = p_1^{a_1} \cdot p_2^{a_2} \dots p_k^{a_k}$$
Thì công thức tính $\phi(n)$ là:
$$\phi(n) = n \cdot \left(1 - \frac{1}{p_1}\right) \cdot \left(1 - \frac{1}{p_2}\right) \dots \left(1 - \frac{1}{p_k}\right)$$
Bản chất xác suất / loại trừ: Khi một số nguyên tố $p$ là ước của $n$, cứ mỗi nhóm $p$ số liên tiếp thì có đúng $1$ số chia hết cho $p$ (chiếm tỉ lệ $\frac{1}{p}$). Số lượng phần tử không chia hết cho $p$ sẽ còn lại tỉ lệ $\left(1 - \frac{1}{p}\right)$.
Quy đổi đại số:
$$X \cdot \left(1 - \frac{1}{p}\right) = X - \frac{X}{p}$$