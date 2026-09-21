**Bài 34. LCM Sum.**

Cho số nguyên dương n, tính tổng lcm(1,n) + lcm(2,n) + ... + lcm(n,n).

Trong đó lcm(a,b) là bội chung nhỏ nhất của a và b.

**Input**

Dòng đầu tiên là số lượng test case T (1≤T≤300000).

Mỗi test case là một số nguyên dương n (1≤n≤1000000).

**Output**

In kết quả mỗi test case trên 1 dòng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>5<br>1000000 | <br>55<br>2933779482000000 |

**Code**
- Cách 1 : Phương pháp trâu bò
```cpp
                #include <stdio.h>
                #include <math.h>

                #define ll long long 
                // dung phuong phap duyet 2 vong for
                ll gcd(ll a, ll b){
                    if(b == 0) return a;
                    else return gcd(b,a%b);
                }
                // tim boi chung nho nhat 
                ll lcm(ll a, ll b){
                    return a*gcd(a,b) / b;
                }
                // duyet tung ham 
                int selve(int n){
                    int res = 0;
                    // duyet tu 1, den n
                    for(int i = 1; i<= n;i++){
                        res += lcm(i,n);
                    }
                    return res;
                }
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        printf("%d\n",selve(n));
                    }
                }
```

- Cách 2 : Sử dụng phi hàm Euler 
```cpp
                #include <stdio.h>
                #include <math.h>

                // khai bao mang phi euler 
                int p[1000001];
                void phi(){
                    // gan cho cac phi = chinh no 
                    for(int i = 1; i<= 1000000;i++){
                        p[i] = i;
                    }
                    // 
                    for(int i = 2; i<= 1000000; i++){
                        // neu phi[i] van bang i 
                        if(p[i] == i){
                            // gan phi[i] = i-1 
                            p[i] = i-1;
                            // duyet cac boi cua i 
                            for(int j = 2*i; j <= 1000000; j += i){
                                p[j] -= p[j]/i;
                            }
                        }
                    }
                }
                // 
                ll res[1000001];
                void solve(){
                    for(int i = 1; i<= 1000000;i++){    
                        // duyet cac boi cua i 
                        for(int j = i; j<=1000000;j+=i){
                            // cong don 
                            res[j] += i*1LL*p[i];
                        }
                    }
                }
                int main(){
                    int t;
                    phi();
                    solve();
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        // Công thức từ tổng GCD sang tổng LCM
                        long long ans = n * 1LL * (res[n] + 1) / 2;
                        printf("%lld\n", ans);
                    }
                }
```
- Ý nghĩa : 

1. Ý nghĩa toán học: Tại sao lại xuất hiện $\phi(d)$?

Đề bài yêu cầu tính tổng LCM:
$$L(n) = \text{lcm}(1, n) + \text{lcm}(2, n) + \dots + \text{lcm}(n, n)$$

Vì $\text{lcm}(k, n) = \frac{k \cdot n}{\gcd(k, n)}$, ta thấy tổng LCM phụ thuộc trực tiếp vào GCD. Do đó, ta cần nhóm các số có cùng GCD với $n$ lại với nhau.
Ta xét bài toán phụ là tính tổng của phần lõi GCD:
$$S(n) = \sum_{d \mid n} d \cdot \phi(d)$$

Nhận xét: Giá trị của $\gcd(k, n)$ chắc chắn luôn là một ước số $d$ của $n$.

Thay vì duyệt từng $k$ từ $1$ đến $n$ để tính $\gcd$, ta đổi góc nhìn: Có bao nhiêu số $k$ ($1 \le k \le n$) để $\gcd(k, n) = d$?

Chia cả hai vế cho $d$:
$$\gcd(k, n) = d \iff \gcd\left(\frac{k}{d}, \frac{n}{d}\right) = 1$$

Đặt $x = \frac{k}{d}$. Vì $1 \le k \le n$ nên $1 \le x \le \frac{n}{d}$.

Điều kiện trở thành: Tìm số lượng $x$ sao cho:
$$1 \le x \le \frac{n}{d} \quad \text{và} \quad \gcd\left(x, \frac{n}{d}\right) = 1$$

Theo định nghĩa của phi hàm Euler, số lượng giá trị $x$ thỏa mãn chính là $\phi\left(\frac{n}{d}\right)$ vì định nghĩa là $\phi\left(m\right)$ là số các số nguyên dương nhỏ hơn bằng m và nguyên tố cùng nhau với m.

Vì mỗi giá trị như vậy đóng góp $d$ vào phần lõi, nên tổng của phần lõi là:
$$S(n) = \sum_{d \mid n} d \cdot \phi\left(\frac{n}{d}\right)$$

Đặt $i = \frac{n}{d}$ (khi $d$ chạy qua các ước của $n$ thì $i$ cũng chạy qua tất cả các ước của $n$), biểu thức tương đương:
$$S(n) = \sum_{d \mid n} d \cdot \phi(d)$$
(Vì tập hợp các ước $d$ và tập hợp $\frac{n}{d}$ là giống hệt nhau).

- Chuyển đổi tổng GCD sang tổng LCM:

Bước 1: Ghép cặp đối xứng $k$ và $n - k$

Ta cần tính:
$$L(n) = \sum_{k=1}^n \text{lcm}(k, n) = \sum_{k=1}^n \frac{k \cdot n}{\gcd(k, n)} = n \sum_{k=1}^n \frac{k}{\gcd(k, n)}$$

Nhận xét tính chất đối xứng quan trọng của ước chung lớn nhất:
$$\gcd(k, n) = \gcd(n - k, n)$$
(Ví dụ: Với $n = 10, k = 2 \implies \gcd(2, 10) = \gcd(8, 10) = 2$).

Viết tổng $L(n)$ theo chiều xuôi và chiều ngược:
Chiều xuôi ($k$ chạy từ $1 \to n$):
$$L(n) = n \left[ \frac{1}{\gcd(1, n)} + \frac{2}{\gcd(2, n)} + \dots + \frac{n-1}{\gcd(n-1, n)} + \frac{n}{\gcd(n, n)} \right]$$

Chiều ngược (thay $k$ bằng $n - k$):
$$L(n) = n \left[ \frac{n-1}{\gcd(n-1, n)} + \dots + \frac{1}{\gcd(1, n)} + \frac{n}{\gcd(n, n)} \right]$$

Tách riêng số hạng cuối cùng $k = n$ (vì $\frac{n}{\gcd(n, n)} = \frac{n}{n} = 1$):
$$L(n) - n = n \sum_{k=1}^{n-1} \frac{k}{\gcd(k, n)}$$

Bước 2: Cộng hai vế để làm xuất hiện tổng các số $1$

Viết lại tổng từ $1$ đến $n-1$ hai lần:
$$L(n) - n = n \sum_{k=1}^{n-1} \frac{k}{\gcd(k, n)}$$
$$L(n) - n = n \sum_{k=1}^{n-1} \frac{n - k}{\gcd(n - k, n)} = n \sum_{k=1}^{n-1} \frac{n - k}{\gcd(k, n)}$$

Cộng hai đẳng thức lại:
$$2(L(n) - n) = n \sum_{k=1}^{n-1} \left( \frac{k + (n - k)}{\gcd(k, n)} \right) = n \sum_{k=1}^{n-1} \frac{n}{\gcd(k, n)}$$

Chia cả hai vế cho $2$, rồi chuyển $n$ sang vế phải:
$$L(n) = \frac{n}{2} \sum_{k=1}^{n-1} \frac{n}{\gcd(k, n)} + n$$

Số hạng $n$ bên ngoài có thể viết thành $\frac{n}{2} \cdot 2 = \frac{n}{2} \left( \frac{n}{\gcd(n, n)} + 1 \right)$ vì $\frac{n}{\gcd(n, n)} = 1$. Đưa $\frac{n}{\gcd(n, n)}$ vào bên trong dấu tổng:
$$L(n) = \frac{n}{2} \left[ \sum_{k=1}^{n} \frac{n}{\gcd(k, n)} + 1 \right]$$

Mà ta đã chứng minh ở trên $S(n) = \sum_{k=1}^n \frac{n}{\gcd(k, n)}$, do đó:
$$L(n) = \frac{n}{2} \big(S(n) + 1\big)$$

