**Bài 2. Tổng modulo 1**

Cho hai số nguyên không âm N và K. Nhiệm vụ của bạn là tìm S = 1%K + 2%K + ... + N%K. Ví dụ với N = 10, K=2 ta có S = 1%2 + 2%2 + 3%2 + 4%2 + 5%2 + 6%2 + 7%2 + 8%2 + 9%2 + 10%2 = 5.

**Input:**
- Dòng đầu tiên đưa vào số lượng test T.
- Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là bộ đôi N, K được viết cách nhau một vài khoảng trống.
- T, N, K thỏa mãn ràng buộc: 1 ≤ T ≤ 100; 0 ≤ N ≤ 1000; 0 ≤ K ≤ 10^12.

**Output:**
- Đưa ra kết quả mỗi test theo từng dòng.

**Ví dụ:**

| Input | Output |
| :--- | :--- |
| 2<br>10 55<br>1 11 | 55<br>1 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                // ham trau bo 
                long long solve(long long n, long long k){
                    long long sum = 0;
                    for(long long i = 1; i<= n; i++){
                        sum += i%k;
                    }
                    return sum;
                }

                // su dung
                long long solve1(long long n, long long k){
                    // x la so luong chu ki day du (moi chu ki co do dai k)
                    long long x = n / k;
                    // r la so luong phan tu bi le ra sau khi chia thanh x chu ki day du
                    long long r = n % k;
                    // tong1 la tong cac so du trong 1 chu ki day du
                    // Vi day so du cua 1 chu ki luon la: 1, 2, ..., k-1, 0
                    // Nen tong cua no se bang: 1 + 2 + ... + (k-1)
                    long long tong1 = (k-1)*k/2;
                    // tong2 la tong cua r phan tu le cuoi cung (nhom du ra, chua tao thanh 1 chu ki)
                    // Cac phan tu nay se co so du quay vong bat dau lai tu: 1, 2, ..., r
                    // Nen tong cua r phan tu nay la: 1 + 2 + ... + r
                    long long tong2 = r*(r+1)/2;
                    // Ket qua = (so chu ki * tong 1 chu ki) + tong phan le
                    return x*tong1 + tong2;
                }

                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        long long n,k;
                        scanf("%lld %lld",&n,&k);
                        printf("%lld\n",solve1(n,k));
                    }
                    return 0;
                }
```
### 1. Phép biểu diễn số học Euclid
Với hai số nguyên dương $N$ và $K$, theo định lý chia Euclid, tập hợp các số nguyên từ $1$ đến $N$ luôn được chia thành hai nhóm:
$$N = x \cdot K + r \quad (0 \le r < K)$$
- $x = \lfloor N / K \rfloor$: Số nhóm đầy đủ độ dài $K$.
- $r = N \pmod K$: Số phần tử còn dư lại của nhóm cuối cùng chưa hoàn chỉnh.

Khi đó, tổng ban đầu được phân rã thành:
$$S = \sum_{i=1}^{N} (i \pmod K) = \underbrace{\sum_{i=1}^{x \cdot K} (i \pmod K)}_{\text{Nhóm các chu kỳ đầy đủ}} + \underbrace{\sum_{i=x \cdot K + 1}^{x \cdot K + r} (i \pmod K)}_{\text{Nhóm phần dư lẻ}}$$

### 2. Ý nghĩa toán học của biến tong1
Xét một chu kỳ $K$ số nguyên liên tiếp bắt đầu từ bội số của $K$:
$$\{m \cdot K + 1, \; m \cdot K + 2, \; \dots, \; m \cdot K + (K - 1), \; (m + 1)K\}$$
Áp dụng tính chất đồng dư $(a + b) \pmod K = \big((a \pmod K) + (b \pmod K)\big) \pmod K$:
$$(m \cdot K + 1) \pmod K = 1$$
$$(m \cdot K + 2) \pmod K = 2$$
$$\dots$$
$$(m \cdot K + (K - 1)) \pmod K = K - 1$$
$$((m + 1)K) \pmod K = 0$$
Tập các số dư của một chu kỳ đầy đủ luôn tạo thành cấp số cộng:
$$\{1, 2, 3, \dots, K - 1, 0\}$$
Tổng các số dư trong một chu kỳ chính là tổng của cấp số cộng từ $1$ đến $K - 1$:
$$\text{tong1} = \sum_{j=1}^{K-1} j + 0 = \frac{(K - 1)K}{2}$$
Vì có đúng $x$ chu kỳ đầy đủ nên tổng đóng góp của chúng là:
$$x \cdot \text{tong1} = x \cdot \frac{(K - 1)K}{2}$$

### 3. Ý nghĩa toán học của biến tong2
Sau khi đã trừ đi $x \cdot K$ phần tử của các chu kỳ đầy đủ, dãy còn lại $r$ phần tử:
$$\{x \cdot K + 1, \; x \cdot K + 2, \; \dots, \; x \cdot K + r\}$$
Lấy modulo từng phần tử cho $K$:
$$(x \cdot K + j) \pmod K = j \quad (\text{với } 1 \le j \le r)$$
Tập hợp số dư của đoạn lẻ này là $\{1, 2, \dots, r\}$, tạo thành cấp số cộng gồm $r$ số hạng có công sai $d = 1$:
$$\text{tong2} = \sum_{j=1}^{r} j = \frac{r(r + 1)}{2}$$