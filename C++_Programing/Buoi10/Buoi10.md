# Mảng Cộng Dồn Trên Mảng 1 Chiều Và 2 Chiều | Truy Vấn Tổng Trên Đoạn

## Mảng cộng dồn trên mảng 1 chiều 

Giả sử chúng ta có một mảng số nguyên `arr` (đánh chỉ số từ 1) có kích thước $N$ và chúng ta muốn tính giá trị của:

$$ \text{arr}[a] + \text{arr}[a + 1] + \dots + \text{arr}[b] $$

cho $Q$ cặp $(a, b)$ khác nhau thỏa mãn $1 \le a \le b \le N$. Chúng ta sẽ xem xét ví dụ sau với $N = 6$:

| Chỉ số $i$ | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| `arr[i]` | 1 | 6 | 4 | 2 | 5 | 3 |

Theo cách thông thường (ngây thơ), với mỗi truy vấn, chúng ta có thể dùng vòng lặp duyệt qua tất cả các phần tử từ chỉ số $a$ đến chỉ số $b$ để cộng chúng lại. Vì chúng ta có $Q$ truy vấn và mỗi truy vấn yêu cầu tối đa $\mathcal{O}(N)$ phép toán để tính tổng, độ phức tạp thời gian tổng cộng của chúng ta là $\mathcal{O}(N \times Q)$. Đối với hầu hết các bài toán dạng này, các giới hạn thường là $N, Q \le 10^5$, do đó $N \times Q$ sẽ có độ lớn cỡ $10^{10}$. Điều này là **không thể** chấp nhận được; thuật toán gần như chắc chắn sẽ bị quá giới hạn thời gian (Time Limit Exceeded).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a[n];
    // nhap mang
    for(int &i : a) cin >> a[i];
    // cach tinh tong mang ngay tho 
    int sum = 0;
    for(int i : a){
        // tinh tong lan luot 
        // co do phuc tap O(n)
        sum += a[i];
    }
    cout << sum;
}
```

Thay vào đó, chúng ta có thể sử dụng mảng cộng dồn (prefix sums) để xử lý các truy vấn tính tổng này. Chúng ta gọi mảng cộng dồn là `prefix`. Đầu tiên, vì chúng ta đang đánh chỉ số mảng từ 1, ta đặt `prefix[0] = 0`, sau đó với các chỉ số $k$ sao cho $1 \le k \le n$, mảng cộng dồn được định nghĩa như sau:

$$ \text{prefix}[k] = \sum_{i=1}^{k} \text{arr}[i] $$


Về cơ bản, điều này có nghĩa là phần tử tại chỉ số $k$ của mảng cộng dồn lưu trữ tổng của tất cả các phần tử trong mảng ban đầu từ chỉ số 1 cho đến $k$. Điều này có thể được tính toán dễ dàng với độ phức tạp $\mathcal{O}(N)$ bằng công thức sau cho mỗi $1 \le k \le n$:

$$ \text{prefix}[k] = \text{prefix}[k - 1] + \text{arr}[k] $$

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a[n];
    // nhap mang
    for(int &i : a) cin >> a[i];
    // khoi tao mang prefix sum
    int prefix[n+1] = {0};
    for(int i = 1; i <= n; i++){
        // cong don cac phan tu lai
        // 1 6 4 2 5 3
        // mang prefix sau khi tinh la
        // 1 7 11 13 18 21
        // bay gio ta truy xuat nhanh 
        // muon tinh tong k so hang vi tri [l,r]
        prefix[i] = prefix[i-1] + a[i];
    }
    // truy van tinh tong voi do phuc tap O(1)
    int l,r;
    cin >> l >> r;
    // tong trong doan [l,r] = tong [1,r] - tong [1,l-1]
    int sum = prefix[r] - prefix[l-1];
    cout << sum;
}
```

## Mảng cộng dồn trên mảng 2 chiều 

Bây giờ, nếu chúng ta muốn xử lý $Q$ truy vấn tính tổng các phần tử trong một hình chữ nhật con (subrectangle) của một ma trận 2 chiều có kích thước $N$ hàng và $M$ cột? Giả sử cả hàng và cột đều được đánh chỉ số từ 1 (1-indexed), chúng ta xem xét ma trận ví dụ sau:

| Chỉ số | 0 | 1 | 2 | 3 | 4 | 5 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **0** | 0 | 0 | 0 | 0 | 0 | 0 |
| **1** | 0 | 1 | 5 | 6 | 11 | 8 |
| **2** | 0 | 1 | 7 | 11 | 9 | 4 |
| **3** | 0 | 4 | 6 | 1 | 3 | 2 |
| **4** | 0 | 7 | 5 | 4 | 2 | 3 |

Theo cách thông thường (ngây thơ), với mỗi truy vấn, chúng ta có thể dùng vòng lặp lồng nhau duyệt qua tất cả các phần tử trong hình chữ nhật con từ hàng $h_1$ đến $h_2$, từ cột $c_1$ đến $c_2$ để cộng chúng lại. Vì chúng ta có $Q$ truy vấn và mỗi truy vấn yêu cầu tối đa $\mathcal{O}(N \times M)$ phép toán, độ phức tạp thời gian tổng cộng là $\mathcal{O}(Q \times N \times M)$. Điều này là quá chậm!

Ví dụ: Cần tính tổng các phần tử trong hình chữ nhật từ hàng 2 đến 3, cột 2 đến 4:
$$ 7 + 11 + 9 + 6 + 1 + 3 = 37 $$

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    // Nhap mang 2 chieu (danh so tu 1)
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    // Nhap pham vi hinh chu nhat: hang h1 -> h2, cot c1 -> c2
    int h1, h2, c1, c2;
    cin >> h1 >> h2 >> c1 >> c2;
    
    // Cach tinh tong ngay tho: duyet qua tung o
    // Do phuc tap O(N * M) cho moi truy van
    int sum = 0;
    for(int i = h1; i <= h2; i++){
        for(int j = c1; j <= c2; j++){
            sum += a[i][j];
        }
    }
    cout << sum << endl;
}
```

### Bước 1: Áp dụng ý tưởng mảng cộng dồn 1 chiều trên từng hàng

Bước tối ưu hợp lý đầu tiên là tính mảng cộng dồn 1 chiều cho từng hàng của ma trận. Khi đó, ta có ma trận cộng dồn theo từng hàng như sau:

| Chỉ số | 0 | 1 | 2 | 3 | 4 | 5 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **0** | 0 | 0 | 0 | 0 | 0 | 0 |
| **1** | 0 | 1 | 6 | 12 | 23 | 31 |
| **2** | 0 | 1 | 8 | 19 | 28 | 32 |
| **3** | 0 | 4 | 10 | 11 | 14 | 16 |
| **4** | 0 | 7 | 12 | 16 | 18 | 21 |

Tổng đoạn con cần tính trên mỗi hàng đơn giản bằng phần tử ở biên phải trừ đi phần tử ngay trước biên trái trên cùng hàng đó. Ta tính cho từng hàng rồi cộng lại:
$$ (28 - 1) + (14 - 4) = 27 + 10 = 37 $$

Bằng cách này, ta chia hình chữ nhật con thành các đoạn con trên từng hàng rồi cộng tổng của chúng lại bằng kỹ thuật prefix sum 1 chiều. Vì ma trận có $N$ hàng, mỗi truy vấn mất $\mathcal{O}(N)$, tổng độ phức tạp cho $Q$ truy vấn là $\mathcal{O}(Q \times N)$. Cách này có thể đủ nhanh với $Q = 10^5$ và $N = 10^3$, nhưng ta hoàn toàn có thể làm tốt hơn nữa.

### Bước 2: Sử dụng mảng cộng dồn 2 chiều (Prefix Sum 2D)

Thay vào đó, chúng ta có thể sử dụng mảng cộng dồn 2 chiều. Chúng ta gọi mảng cộng dồn là `prefix`. Đầu tiên, các hàng 0 và cột 0 được gán bằng 0 (`prefix[0][j] = prefix[i][0] = 0`), sau đó với các chỉ số $1 \le a \le n$ và $1 \le b \le m$, mảng cộng dồn 2 chiều được định nghĩa như sau:

$$ \text{prefix}[a][b] = \sum_{i=1}^{a} \sum_{j=1}^{b} \text{arr}[i][j] $$

Về cơ bản, điều này có nghĩa là phần tử tại vị trí $(a, b)$ của mảng cộng dồn lưu trữ tổng của tất cả các phần tử trong mảng ban đầu từ ô góc trên-trái $(1, 1)$ cho đến ô $(a, b)$. Điều này có thể được tính toán dễ dàng với độ phức tạp $\mathcal{O}(N \times M)$ bằng công thức truy hồi sau cho mỗi $1 \le i \le n$ và $1 \le j \le m$:

$$ \text{prefix}[i][j] = \text{prefix}[i - 1][j] + \text{prefix}[i][j - 1] - \text{prefix}[i - 1][j - 1] + \text{arr}[i][j] $$

**Giải thích công thức (Nguyên lý bù trừ):**
- $\text{prefix}[i - 1][j]$: Tổng hình chữ nhật phía bên trên ô $(i, j)$.
- $\text{prefix}[i][j - 1]$: Tổng hình chữ nhật phía bên trái ô $(i, j)$.
- $-\ \text{prefix}[i - 1][j - 1]$: Trừ đi phần hình chữ nhật góc trên-trái giao nhau vì đã bị cộng lặp 2 lần.
- $+\ \text{arr}[i][j]$: Cộng thêm giá trị của chính ô hiện tại $(i, j)$.

Sau khi đã xây dựng xong mảng `prefix`, tổng của một hình chữ nhật con bất kỳ có góc trên-trái $(h_1, c_1)$ và góc dưới-phải $(h_2, c_2)$ có thể được tính toán ngay lập tức với độ phức tạp $\mathcal{O}(1)$ bằng công thức:

$$ \text{sum} = \text{prefix}[h_2][c_2] - \text{prefix}[h_1 - 1][c_2] - \text{prefix}[h_2][c_1 - 1] + \text{prefix}[h_1 - 1][c_1 - 1] $$

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    // Nhap mang (danh chi so tu 1)
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    // Khoi tao mang prefix sum 2D voi cac gia tri ban dau bang 0
    // y tuong dau tien la tinh san mang prefix 2 chieu
    // tinh tu (1,1) den (n,m) 
    // prefix[i][j] sẽ bằng tổng các phần tử từ (1,1) đến (i,j)
    int prefix[n + 1][m + 1] = {0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // vi du mang 2 chieu 3x3 
            // 1 2 3
            // 4 5 6
            // 7 8 9
            // muon tinh prefix[3][3]
            // prefix[i-1][j] = 1 + 2 + 3 + 4 + 5 + 6 = 
            // prefix[i][j-1] = 1 + 2 + 4 + 5 + 7 + 8 = 
            // thay trung 1 + 2 + 4 + 5 day chinh la prefix[i-1][j-1]
            // nen ta phai tru di 2 cong trung ay 
            // thay con thieu a[3][3] la 9 nen phai cong vo moi du tong  
            prefix[i][j] = prefix[i - 1][j] 
                         + prefix[i][j - 1] 
                         - prefix[i - 1][j - 1] 
                         + a[i][j];
        }
    }
    // Truy van tinh tong tren hinh chu nhat con voi do phuc tap O(1)
    // Toa do: tu hang h1 den hang h2, tu cot c1 den cot c2
    int h1, h2, c1, c2;
    cin >> h1 >> h2 >> c1 >> c2;
    // theo vi du ma tran 
    // 1 2 3
    // 4 5 6
    // 7 8 9
    // ket qua mang prefix[][]
    // 1 3 6 
    // 5 12 21
    // 12 27 45
    // muon tinh tong 5 6 8 9, hinh chu nhat duoi 
    // h1 = 2, h2 = 3, c1 = 2, c2 = 3
    // 45 la tong tu (1,1) den (3,3)
    // 45 phai tru hang 1, tuc la h1 - 1
    // tiep tuc tru di cot 1, tuc la c1 - 1
    // ta thay so 1 deu bi tru 2 lan 
    // nen pha cong bu 1, tuc la [h1 - 1][c1 - 1]
    int sum = prefix[h2][c2] 
            - prefix[h1 - 1][c2] 
            - prefix[h2][c1 - 1] 
            + prefix[h1 - 1][c1 - 1];
    // IN ra ket qua 
    cout << sum << endl;
}
```
