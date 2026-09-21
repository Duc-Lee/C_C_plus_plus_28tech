**Phần 4. Phép toán Modulo**

**Bài 1. Pow mod**

Cho ba số nguyên dương x, y, p. Nhiệm vụ của bạn là tính (x^y) %p. Ví dụ với x = 2, y = 3, p = 5 thì (2^3)%5=3.

**Input:**

Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là bộ ba x, y, p được viết cách nhau một vài khoảng trống.

T, x, y, p thỏa mãn ràng buộc : 1≤T≤100; 1≤x, y≤10^6; 1≤P≤10^9+7.

**Output:**

Đưa ra kết quả mỗi test theo từng dòng.

**Ví dụ**

| Input: | Output: |
| :--- | :--- |
| 2<br>2 3 5<br> 3 2 4 | 3<br>1 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                #define ll long long 

                // Cach tinh trau bo
                int powmod1(int x,int y,int p){
                    long long res = 1;
                    // ta tinh theo cong thuc x^y = x * x * x * ... * x (y lan)
                    // theo cong thuc modulo thi : x^y % p = ((x%p) * (x%p) * ... * (x%p)) % p
                    
                    for(int i = 1; i<= y;i++){
                        res *= x;
                        res %= p;
                    }
                    return res;
                }
                
                // theo cach tinh thu 2
                int powmod2(int x, int y, int p){
                    long long res = 1;
                    // ta ap dung cong thuc x^y = x^(2k+1) = x * x^(2k) = x * (x^k)^2 neu y le
                    // x^y = x^(2k) = (x^k)^2 neu y chan 
                    while(y){
                        // neu y la so le 
                        // ta ap dung cong thuc x^y %p = (x * x^(y-1))%p = (x%p * x^(y-1)%p)%p
                        // = (x%p * x^((y-1)/2)%p * x^((y-1)/2)%p)%p
                        if(y % 2 == 1){
                            res *= x;
                            res %= p;
                        }
                        // x^y = x^(y/2) * x^(y/2) neu y chan
                        // x^y %p = (x^(y/2) * x^(y/2))%p
                        // muon chuyen lai thanh (x^2)^(y/2)
                        // x^2 %p = (x%p * x%p)%p
                        // (x^2)^(y/2) % p = ((x^2%p)*(x^2%p)*...*(x^2%p))%p
                        x *= x;
                        x %= p;
                        y /= 2;
                    }
                    return res;
                }

                // de quy phuong phap chia de tri 
                int powmod3(int x,int y,int p){
                    if(y==0) return 1;
                    // dùng đệ quy để tính x^(y/2) % p
                    // y/2 để chia đôi bài toán, giảm số lần tính 
                    // se bat dau tinh tu y=0
                    int tmp = powmod3(x,y/2,p);
                    // neu y le thi y = 2k + 1
                    // theo cong thuc thi : x^(2k+1) = x * x^(2k) = x * (x^k)^2
                    // ta ap dung cong thuc 
                    // modulo mo rong : x^(2k+1) % p = ((x % p) * (x^k % p) * (x^k % p)) % p
                    if(y%2 == 1 ){
                        return ((x % p)*(tmp%p)*(tmp%p))%p;
                    }
                    // neu y chan thi y = 2k, y la so luy thua
                    // theo cong thuc thi : x^(2k) = (x^k)^2, ta ap dung cong thuc 
                    // modulo : x^(2k) % p = ((x^k % p) * (x^k % p)) % p
                    else{
                        return ((tmp%p)*(tmp%p))%p;
                    }
                }

                // thuat toan dich bit
                int binpow(int x,int y,int p){
                    int res = 1;
                    x %= p;
                    while(y>0){
                        if(y&1) res = (res*x)%p;
                        x = (x*x)%p;
                        y >>= 1;
                    }
                    return res;
                }

                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                            int x,y,p;
                        scanf("%d %d %d",&x,&y,&p);
                        printf("%d\n",binpow(x,y,p));
                    }
                    return 0;
                }

```

1. Cơ sở đồng dư số học
Phép nhân có tính chất bảo toàn qua phép lấy modulo:
$$(a \cdot b) \pmod p = \big((a \pmod p) \cdot (b \pmod p)\big) \pmod p$$
Từ đó, với một tích liên tiếp:
$$x^y \pmod p = (\underbrace{x \cdot x \cdots x}_{y \text{ lần}}) \pmod p$$
Ta có thể lấy modulo $p$ ở từng bước nhân trung gian để các giá trị không bao giờ vượt quá $p^2$.

2. Thuật toán lũy thừa nhị phân
Nếu nhân liên tiếp $y$ lần, độ phức tạp thời gian là $O(y)$. Khi $y$ lớn, cách này chạy rất chậm hoặc bị quá thời gian (TLE). Thay vào đó, ta giảm số phép tính xuống $O(\log_2 y)$ bằng cách phân tích:

Nếu $y$ chẵn ($y = 2k$):
$$x^y = x^{2k} = (x^2)^k = (x^k)^2$$
Nếu $y$ lẻ ($y = 2k + 1$):
$$x^y = x \cdot x^{2k} = x \cdot (x^2)^k$$

Bản chất biểu diễn nhị phân:
Mọi số nguyên dương $y$ đều được viết duy nhất dưới dạng nhị phân:
$$y = b_k 2^k + b_{k-1} 2^{k-1} + \dots + b_1 2^1 + b_0 2^0 \quad (b_i \in \{0, 1\})$$
Khi đó:
$$x^y = x^{\sum b_i 2^i} = \prod_{b_i = 1} x^{2^i}$$
Dãy các lũy thừa cơ số 2 gồm: $x^1, x^2, x^4, x^8, x^{16}, \dots$ Mỗi số hạng phía sau chính là bình phương của số hạng liền trước:
$$x^{2^{i+1}} = (x^{2^i})^2$$
Ta chỉ cần nhân dồn các lũy thừa $x^{2^i}$ ứng với các vị trí mà bit thứ $i$ của $y$ bằng $1$, đồng thời lấy modulo $p$ sau mỗi phép nhân.

3. Ví dụ cụ thể

Tính $x=3, y=5, p=7$

Ta có $y=5$ dưới dạng nhị phân là $101_2$, tức là $5 = 1 \cdot 2^2 + 0 \cdot 2^1 + 1 \cdot 2^0 = 4 + 1$.
Vậy:$$3^5 = 3^{4+1} = 3^4 \cdot 3^1$$

Ta tính các lũy thừa cơ số 2:$$x^1 = 3^1 \equiv 3 \pmod 7$$
$$x^2 = (x^1)^2 \equiv 3^2 \equiv 9 \equiv 2 \pmod 7$$
$$x^4 = (x^2)^2 \equiv 2^2 \equiv 4 \pmod 7$$

Cuối cùng, nhân các lũy thừa ứng với bit 1 của $y$ (bit 0 và bit 2):
$$3^5 \equiv x^4 \cdot x^1 \equiv 4 \cdot 3 \equiv 12 \equiv 5 \pmod 7$$
Kết quả là 5.
