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

Cách làm ngây thơ la cộng dồn mảng từng hàng, từng cột 

```cpp
#include <bits/stdc++.h>
using namspace std;

int main(){
    int n, m;

}

```