# Bài 1. Liệt kê số nguyên tố trong ma trận

Cho ma trận các số nguyên. Hãy liệt kê các số nguyên tố trong ma trận theo thứ tự xuất hiện, nếu có số nguyên tố xuất hiện nhiều lần thì chỉ in ra 1 lần duy nhất.

### Input
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Dòng đầu tiên của mỗi test case là số lượng hàng và cột của ma trận ($1 \le N, M \le 500$).
- $N$ dòng tiếp theo mỗi dòng gồm $M$ số nguyên $A_{ij}$ ($-10^9 \le A_{ij} \le 10^9$).

### Output
- Liệt kê các số nguyên tố trong ma trận, mỗi test case in trên 1 dòng.

### Ví dụ

| Input | Output |
| :--- | :--- |
| 1<br>3 3<br>1 7 8<br>2 3 3<br>7 5 2 | 7 2 3 5 |

#### Chi tiết test case ví dụ:
```text
Input:
1
3 3
1 7 8
2 3 3
7 5 2

Output:
7 2 3 5
```

---

> **Ghi chú mở rộng:**
> Đối với bài toán liệt kê các số thỏa mãn tính chất nào đó có thể là nguyên tố, chính phương, thuận nghịch, lộc phát, fibonacci, số đẹp .... Bạn làm bài liệt kê với yêu cầu như bài này nhưng với các số thỏa mãn các tính chất còn lại.

### Code 
```cpp
#include <bits/stdc++.h>
using namespace std;

// ham check so nguyen to 
bool prime(int n){
    for(int i = 2; i<= sqrt(n);i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n][m];
        // nhap ma tran 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        // khoi tao ham map de luu tan so xuat hien dau tien 
        map<int, int> nt;
        // duyet qua mang 2 chieu 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // kiem tra dieu kien so do co phai so nguyen to ko
                // va chi in ra so nguyen to xuat hien dau tien 
                if(prime(a[i][j]) && map[a[i][j]] == 0) {
                    cout << a[i][j] << " ";
                    // neu da xuat hien va in ra roi 
                    // gan lai 1 de khong bao gio in lai nua 
                    map[a[i][j]] = 1;
                }
            }
        }
    }
}
```
----
# Bài 2. Phần tử lớn nhất trong ma trận

Tìm phần tử lớn nhất trong ma trận và liệt kê các vị trí xuất hiện của nó trong ma trận.

### Input
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Dòng đầu tiên của mỗi test case là số lượng hàng và cột của ma trận ($1 \le N, M \le 500$).
- $N$ dòng tiếp theo mỗi dòng gồm $M$ số nguyên $A_{ij}$ ($-10^9 \le A_{ij} \le 10^9$).

### Output
- Dòng đầu tiên in ra số lớn nhất.
- Các dòng tiếp theo in ra các vị trí của số lớn nhất đó trong ma trận theo định dạng: `Vi tri xuat hien : A[i][j]` (chỉ số tính từ 1).

### Ví dụ

```text
Input:
1
3 4
1 2 8 3
2 3 8 8
1 5 2 3

Output:
8
Vi tri xuat hien : A[1][3]
Vi tri xuat hien : A[2][3]
Vi tri xuat hien : A[2][4]
```

### Code 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n][m];
        // khoii tao bien tim so lon nhat 
        int max_val = INT_MIN;
        // nhap ma tran 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                // tim so lon nhat 
                max_val = max(max_val, a[i][j]);
            }
        }
        // duyet lai ma tran 2D 
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == max_val){
                    cout << "Vi tri xuat hien : " << "A[" << i + 1 << "][" << j + 1 << "]\n";
                }
            }
        }    
    }
}
```

-----
# Bài 3. Tìm hàng có tổng các phần tử lớn nhất

Liệt kê các hàng trong ma trận có tổng các phần tử lớn nhất.

### Input
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Dòng đầu tiên của mỗi test case là số lượng hàng và cột của ma trận ($1 \le N, M \le 500$).
- $N$ dòng tiếp theo mỗi dòng gồm $M$ số nguyên $A_{ij}$ ($-10^9 \le A_{ij} \le 10^9$).

### Output
- In tổng lớn nhất trên 1 dòng.
- Dòng thứ 2 liệt kê các dòng có tổng phần tử lớn nhất trên 1 dòng (chỉ số hàng tính từ 1).

### Ví dụ

```text
Input:
1
4 4
1 2 3 4
2 3 4 9
1 2 8 6
8 4 1 5

Output:
18
3 4
```

---

> **Ghi chú mở rộng:**
> Các bạn làm thêm với các yêu cầu, trong trường hợp có nhiều hàng có cùng tổng lớn nhất ta lấy hàng đầu tiên, hàng cuối cùng.

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n][m];
        // nhap ma tran 
        for(int i = 0; i < n;i++){
            for(int j = 0; j<m;j++){
                cin >> a[i][j];
            }
        }
        // khoi tao bien tim so lon nhat 
        int max_val = -1e9;
        // khoi tao vector luu cac chi so hang co tong lon nhat 
        vector<int> vt;
        for(int i = 0; i < n;i++){
            // tinh tong cac phan tu trong 1 hang 
            int sum = 0; 
            for(int j = 0; j < m; j++){
                sum += a[i][j];
            }
            // so sanh voi max_val 
            if(sum > max_val){
                // neu lon hon thi cap nhat lai max_val 
                max_val = sum;
                // xoa toan bo vector vi co so moi lon hon 
                vt.clear();
                // them chi so hang hien tai vao vector 
                vt.push_back(i+1);
            }
            // neu tong bang voi max_val 
            else if(sum == max_val){
                // them chi so hang vao vector 
                vt.push_back(i+1);
            }
        }
        // in ra ket qua 
        cout << max_val << endl;
        for(int i : vt){
            cout << i << " ";
        }
        cout << endl;
    }
}
```
--- 
# Bài 4. Tìm cột có nhiều số Fibonacci nhất

Tìm cột có nhiều số Fibonacci nhất trong ma trận, trong trường hợp có nhiều cột có cùng số lượng số Fibonacci thì in ra cột có tổng các số Fibonacci lớn nhất.

### Input
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Dòng đầu tiên của mỗi test case là số lượng hàng và cột của ma trận ($1 \le N, M \le 500$).
- $N$ dòng tiếp theo mỗi dòng gồm $M$ số nguyên $A_{ij}$ ($1 \le A_{ij} \le 10^{18}$).

### Output
- Dòng đầu tiên in ra thứ tự cột có nhiều số Fibonacci nhất (chỉ số cột tính từ 1).
- Dòng thứ 2 liệt kê các số Fibonacci trong cột đó theo thứ tự xuất hiện từ trên xuống dưới.

### Ví dụ

```text
Input:
1
4 4
1 2 3 5
2 2 5 8
10 1 2 3
21 13 3 3

Output:
4
5 8 3 3
```

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// khoi tao mang set fibo 
set <long long> fibo;

// ham khoi tao so fibo
void khoitaofibo(){
    int fibo[93];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i< 93; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    // tinh cac so fibo 
    for(int i = 0; i < 93; i++){
        fibo.insert(fibo[i]);
    }
}

int main(){
    khoitaofibo();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        long long a[n][m];
        // nhap ma tran 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        // khoi tao bien tim so lon nhat 
        int sum = -1e9;
        // khoi tao bien cot lon nhat 
        int cot;
        // khoi tao bien tan suat lon nhat 
        int ans = -1;
        // duyet cot 
        for(int j =0; j<m;j++){
            // khoi tao bien tong 
            int tmp = 0;
            // khoi tao bien dem tan suat 
            int dem = 0;
            // tong hang va dem so fibo
            for(int i = 0; i<n;i++){
                // neu la so fibonanci
                if(fibo.count(a[i][j]) == 1){
                    ++dem;
                    tmp += a[i][j];
                }
            }
            // kiem tra xem 
            if(ans < dem){
                // dem cot xuat hien nhieu nhat
                ans = dem;
                cot = j;
                sum = tmp;
            }
            else if(ans == dem){
                // neu bang 
                // kiem tra xem tong co be hon khong
                // pha dam bao so luong fibo nhieu nhat
                // va tong lon nhat
                if(sum < tmp){
                    cot = j;
                    sum = tmp;
                }
            }
        }
        // In ra ket qua
        cout << cot + 1 << endl;
        for(int i = 0; i < n;i++){
            if(fibo.count(a[i][cot]) == 1){
                cout << a[i][cot] << " ";
            }
        }
        cout << endl;
    }
}
```

----
# Bài 5. Tổng các phần tử thuộc tam giác dưới của ma trận vuông

Tính tổng các phần tử thuộc tam giác dưới của ma trận vuông (bao gồm cả các phần tử nằm trên đường chéo chính).

### Input
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Dòng đầu tiên của mỗi test case là $N$ - cấp của ma trận vuông ($1 \le N \le 500$).
- $N$ dòng tiếp theo mỗi dòng gồm $N$ số nguyên $A_{ij}$ ($1 \le A_{ij} \le 10^9$).

### Output
- In ra tổng các phần tử thuộc tam giác dưới (mỗi test case in trên 1 dòng).

### Ví dụ

```text
Input:
1
3
1 2 3
4 5 6
7 8 9

Output:
34
```

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int a[n][n];
        // nhap ma tran 
        for(int i =0; i<n;i++){
            for(int j =0; j<n; j++){
                cin >> a[i][j];
            }
        }
        // khoi tao bien tinh tong 
        int sum = 0;
        for(int i = 0; i< n;i++){
            for(int j = 0; j <= i;i++){
                sum += a[i][j];
            }
        }
        cout << sum << endl;
    }
}
```
----
# Bài 6. Thay thế phần tử

Thay thế phần tử của ma trận bằng tổng của chính nó và các phần tử ở các ô xung quanh (tối đa 8 ô xung quanh chung đỉnh/chung cạnh).

Trong trường hợp một phần tử không có đầy đủ 8 ô xung quanh (các ô ở biên hoặc góc) thì chỉ tính tổng của chính nó và các ô xung quanh hợp lệ nằm trong ma trận.

### Input
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Dòng đầu tiên của mỗi test case là số lượng hàng và cột của ma trận ($1 \le N, M \le 500$).
- $N$ dòng tiếp theo mỗi dòng gồm $M$ số nguyên $A_{ij}$ ($-10^9 \le A_{ij} \le 10^9$).

### Output
- In ra ma trận sau khi thay thế.

### Ví dụ

```text
Input:
1
3 3
1 2 3
4 5 6
7 8 9

Output:
12 21 16
27 45 33
24 39 28
```

#### Giải thích ví dụ:
- Phần tử $5$ ở chính giữa có đủ 8 ô xung quanh $\rightarrow$ thay bằng: $1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45$.
- Phần tử $1$ ở góc trên bên trái chỉ có 3 ô xung quanh $\rightarrow$ thay bằng: $1 + 2 + 4 + 5 = 12$.
- Phần tử $2$ ở mép trên có 5 ô xung quanh $\rightarrow$ thay bằng: $1 + 2 + 3 + 4 + 5 + 6 = 21$.

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// khoi tao mang huong
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        long long a[n][m];
        // nhap ma tran 
        for(int i =0; i<n;i++){
            for(int j =0; j<m;j++){
                cin >> a[i][j];
            }
        }
        // khoi tao mang ket qua 
        int res[500][500];
        // duyet ma tran 
        for(int i = 0;i <n;i++){
            for(int j = 0; j < m;j++){
                // tinh (i,j)
                // khoi tao bien tong
                int sum = a[i][j];
                // duyet 8 huong 
                for(int k = 0; k < 8;k++){
                    // gan lai gia tri huong 
                    int x = i + dx[k];
                    int y = j + dy[k];
                    // kiem tra bien 
                    // (x,y) nam trong khoang ma tran 
                    if(x >= 0 && x < n && y >= 0 && y < m){
                        sum += a[x][y];
                    }
                }
                // gan ket qua 
                res[i][j] = sum;
            }
        }
        // duyet ma tran ket qua
        for(int i =0;i<n;i++){
            for(int j = 0; j < m; j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
}
```
### Giải thích: Kỹ thuật mảng hướng (Direction Array) trên ma trận

Kỹ thuật mảng hướng dùng để duyệt các ô lân cận (kề cạnh hoặc kề đỉnh) của một ô $(i, j)$ trong ma trận mà không cần viết nhiều câu lệnh rẽ nhánh phức tạp.

#### 1. Biểu diễn tọa độ các ô lân cận
Giả sử ta đang đứng ở ô $A[i][j]$ (hàng $i$, cột $j$). Xung quanh ô $(i, j)$ có tối đa 8 ô lân cận với tọa độ như sau:

```text
 (i - 1, j - 1)  |  (i - 1, j)  |  (i - 1, j + 1)     <-- Hàng trên (i - 1)
-------------------------------------------------
 (i,     j - 1)  |    (i, j)    |  (i,     j + 1)     <-- Hàng hiện tại (i)
-------------------------------------------------
 (i + 1, j - 1)  |  (i + 1, j)  |  (i + 1, j + 1)     <-- Hàng dưới (i + 1)
```

#### 2. Nguyên lý hoạt động của `dx` và `dy`
Để dịch chuyển từ $(i, j)$ sang một ô lân cận $(x, y)$, ta cộng thêm một lượng độ lệch:
- $x = i + dx$ (độ lệch theo hàng)
- $y = j + dy$ (độ lệch theo cột)

Quy ước độ lệch:
- **Theo hàng (`dx`):**
  - `-1`: di chuyển lên hàng trên.
  - `0`: giữ nguyên hàng.
  - `+1`: di chuyển xuống hàng dưới.
- **Theo cột (`dy`):**
  - `-1`: di chuyển sang cột bên trái.
  - `0`: giữ nguyên cột.
  - `+1`: di chuyển sang cột bên phải.

Ghép tương ứng 8 cặp giá trị $(dx[k], dy[k])$ với chỉ số $k$ chạy từ $0$ đến $7$:

| Hướng di chuyển | $k$ | $dx[k]$ | $dy[k]$ | Tọa độ mới $(x, y)$ |
| :--- | :---: | :---: | :---: | :--- |
| Trên - Trái | 0 | -1 | -1 | $(i - 1, j - 1)$ |
| Lên trên | 1 | -1 | 0 | $(i - 1, j)$ |
| Trên - Phải | 2 | -1 | 1 | $(i - 1, j + 1)$ |
| Sang trái | 3 | 0 | -1 | $(i, j - 1)$ |
| Sang phải | 4 | 0 | 1 | $(i, j + 1)$ |
| Dưới - Trái | 5 | 1 | -1 | $(i + 1, j - 1)$ |
| Xuống dưới | 6 | 1 | 0 | $(i + 1, j)$ |
| Dưới - Phải | 7 | 1 | 1 | $(i + 1, j + 1)$ |

#### 3. Kiểm tra điều kiện biên
Khi ô $(i, j)$ nằm ở góc hoặc ở viền của ma trận, một số ô lân cận sẽ rơi ra ngoài ma trận (chỉ số âm hoặc lớn hơn kích thước ma trận). Do đó, ta phải kiểm tra điều kiện trước khi truy cập:

```cpp
if (x >= 0 && x < n && y >= 0 && y < m) {
    // Ô (x, y) hợp lệ nằm trong ma trận
    sum += a[x][y];
}
```

------
# Bài 8. Biên của ma trận

Cho ma trận vuông $A[N][N]$. Hãy in các phần tử thuộc vùng biên.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm:
  - Dòng đầu tiên đưa vào $N$ là cấp của ma trận $A[N][N]$.
  - Dòng tiếp theo đưa vào $N \times N$ số $A[i][j]$ (các số được viết cách nhau một vài khoảng trống).
- Ràng buộc: $1 \le T \le 100$; $1 \le N \le 100$; $1 \le A[i][j] \le 150$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng (các phần tử thuộc vùng biên in ra giá trị, các phần tử ở trong ruột in ra khoảng trắng).

### Ví dụ

```text
Input:
1
4
1 2 3 4
5 6 7 8
1 2 3 4
5 6 7 8

Output:
1 2 3 4
5     8
1     4
5 6 7 8
```

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int a[n][n];
        // nhap ma tran 
        for(int i =0; i<n;i++){
            for(int j =0; j<n; j++){
                cin >> a[i][j];
            }
        }
        // duyet bien cua ma tran 
        for(int i =0; i <n;i++){
            for(int j=0;j < n;j++){
                // kiem tra bien 
                if(i == 0 || i == n-1 || j == 0 || j == n-1){
                    cout << a[i][j] << " ";
                }else{
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
}
```

-----
# Bài 9. In ma trận 1 (In theo hình con rắn)

Cho ma trận vuông $A[N][N]$. Hãy in các phần tử của ma trận theo hình con rắn:
- Hàng đầu tiên (chỉ số 0): in từ trái sang phải.
- Hàng tiếp theo (chỉ số 1): in từ phải sang trái.
- Cứ xen kẽ như vậy cho đến hết ma trận.

```text
Hàng 0 (chẵn)  --> :  10  ->  20  ->  30  ->  40
                                               |
Hàng 1 (lẻ)    <-- :  50  <-  60  <-  70  <-  80
                       |
Hàng 2 (chẵn)  --> :  27  ->  29  ->  47  ->  48
                                               |
Hàng 3 (lẻ)    <-- :  32  <-  33  <-  39  <-  50
```

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm:
  - Dòng đầu tiên đưa vào $N$ là cấp của ma trận vuông $A[N][N]$.
  - Dòng tiếp theo đưa vào $N \times N$ số $A[i][j]$ (các số được viết cách nhau một vài khoảng trống).
- Ràng buộc: $1 \le T \le 100$; $1 \le N \le 100$; $1 \le A[i][j] \le 150$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng (các số in cách nhau một dấu cách).

### Ví dụ

```text
Input:
2
3
45 48 54 21 89 87 70 78 15
2
25 27 23 21

Output:
45 48 54 87 89 21 70 78 15
25 27 21 23
```

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n][n];
        // nhap ma tran 
        for(int i = 0; i<n;i++){
            for(int j = 0; j < n;j++){
                cin >> a[i][j];
            }
        }
        // In ma tran theo quy tac de bai 
        for(int i = 0;i <n;i++){
            for(int j = 0; j <n;j++){
            // neu hang chan thi in theo tu trai sang phai 
            if(i % 2 == 0){
                for(int j = 0; j <n;j++){
                    cout << a[i][j] << " ";
                }
            // neu hang le thi in theo tu phai sang trai 
            }else{
                for(int j = n -1;j >=0;j--){
                    cout << a[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
```

---- 
# Bài 10. Ma trận xoắn ốc thuận

Cho ma trận $A[N][M]$. Nhiệm vụ của bạn là in các phần tử của ma trận theo hình xoắn ốc (chiều kim đồng hồ từ ngoài vào trong).

Ví dụ về in ma trận theo hình xoắn ốc như dưới đây:
`1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10`

```text
 1  -->  2  -->  3  -->  4
                         |
 5  -->  6  -->  7       8
 |               |       |
 9      10  <-- 11      12
 |                       |
13  <-- 14  <-- 15  <-- 16
```

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng:
  - Dòng đầu tiên đưa vào $N, M$ là cấp của ma trận $A[N][M]$.
  - Dòng tiếp theo đưa vào $N \times M$ số $A[i][j]$ (các số được viết cách nhau một vài khoảng trống).
- Ràng buộc: $1 \le T \le 100$; $1 \le M, N \le 100$; $1 \le A[i][j] \le 10^5$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng (các số in cách nhau một dấu cách).

### Ví dụ

```text
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7
```

### Code
```cpp
#include <bits/stdc++.h> 
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n][m];
        // nhap ma tran 
        for(int i =0; i < n;i++){
            for(int j =0; j < m;j++){
                cin >> a[i][j];
            }
        }
        // khoi tao bien 
        int h1 = 0, h2 = n - 1;
        int c1 = 0, c2 = m - 1;
        while(h1 <= h2 && c1 <= c2){
            // in hang dau tien 
            for(int i = c1; i<= c2;i++){
                cout << a[h1][i] << " ";
            }
            ++h1;
            // in cot cuoi cung 
            for(int i = h1;i<=h2;i++){
                cout << a[i][c2] << " ";
            }
            --c2;
            // neu hang 1 va hang 2 chua trung 
            if(h1 <= h2){
                // In hang cuoi cung 
                for(int i = c2;i >=c1;i--){
                    cout << a[h2][i] << " ";
                }
                --h2;
            }
            // neu cot 1 va cot 2 chua trung 
            if(c1 <= c2){
                // In cot dau tien
                for(int i = h2;i >=h1;i--){
                    cout << a[i][c1] << " ";
                }
                ++c1;
            }
        }
        cout << endl;
    }
    return 0;
}
```

----
# Bài 11. Ma trận xoắn ốc ngược

Cho ma trận $A[N][M]$. Nhiệm vụ của bạn là in các phần tử của ma trận theo hình xoắn ốc ngược (từ tâm ma trận ngược ra ngoài, hay chính là thứ tự đảo ngược của ma trận xoắn ốc thuận).

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm:
  - Dòng đầu tiên đưa vào $N, M$ là số hàng và số cột của ma trận $A[N][M]$.
  - Các dòng tiếp theo đưa vào $N \times M$ số $A[i][j]$ (các số được viết cách nhau một vài khoảng trống).
- Ràng buộc: $1 \le T \le 100$; $1 \le N, M \le 100$; $1 \le A[i][j] \le 10^5$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng (các số in cách nhau một dấu cách).

### Ví dụ

```text
Input:
2
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3 6
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18

Output:
10 11 7 6 5 9 13 14 15 16 12 8 4 3 2 1
11 10 9 8 7 13 14 15 16 17 18 12 6 5 4 3 2 1
```

---

### Phân tích & Giải thích:

#### 1. Bản chất của "Xoắn ốc ngược":
- Với ma trận $4 \times 4$:
  - Thứ tự xoắn ốc **thuận** (Bài 10) từ ngoài vào trong:
    `1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10`
  - Thứ tự xoắn ốc **ngược** (Bài 12) chính là dãy trên đọc ngược từ phần tử cuối cùng về đầu:
    `10 11 7 6 5 9 13 14 15 16 12 8 4 3 2 1`

#### 2. Ý tưởng giải đơn giản & tối ưu nhất:
- Tận dụng **thuật toán 4 biến biên** của Bài 10 (`h1, h2, c1, c2`).
- Thay vì `cout` trực tiếp, ta lưu từng phần tử vào một `vector<int> v;` bằng lệnh `v.push_back(...)`.
- Khi duyệt xong ma trận, chỉ cần duyệt ngược `vector` từ cuối về đầu:
  ```cpp
  for (int i = v.size() - 1; i >= 0; i--) {
      cout << v[i] << " ";
  }
  cout << endl;
  ```

### Code 
```cpp
#include <bits/stdc++.h> 
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n][m];
        // Nhap ma tran
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        
        vector<int> v;
        int h1 = 0, h2 = n - 1;
        int c1 = 0, c2 = m - 1;
        
        while(h1 <= h2 && c1 <= c2){
            // 1. Hang tren cung tu trai sang phai
            for(int i = c1; i <= c2; i++){
                v.push_back(a[h1][i]);
            }
            ++h1;
            
            // 2. Cot phai tu tren xuong duoi
            for(int i = h1; i <= h2; i++){
                v.push_back(a[i][c2]);
            }
            --c2;
            
            // 3. Hang duoi cung tu phai sang trai
            if(h1 <= h2){
                for(int i = c2; i >= c1; i--){
                    v.push_back(a[h2][i]);
                }
                --h2;
            }
            
            // 4. Cot trai tu duoi len tren
            if(c1 <= c2){
                for(int i = h2; i >= h1; i--){
                    v.push_back(a[i][c1]);
                }
                ++c1;
            }
        }
        
        // In nguoc lai cac phan tu tu cuoi ve dau
        for(int i = v.size() - 1; i >= 0; i--){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

----- 
# Bài 12 : Tìm số lớn nhất trên mỗi dòng của ma trận

Cho ma trận $A[N][M]$. Nhiệm vụ của bạn là tìm số lớn nhất trên mỗi dòng của ma trận.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng:
  - Dòng đầu tiên đưa vào $N, M$ là số hàng và số cột của ma trận $A[N][M]$.
  - Các dòng tiếp theo đưa vào $N \times M$ số $A[i][j]$ (các số được viết cách nhau một vài khoảng trống).
- Ràng buộc: $1 \le T \le 100$; $1 \le N, M \le 100$; $1 \le A[i][j] \le 10^5$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng (các số in cách nhau một dấu cách).

### Ví dụ

```text
Input:
2
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3 6
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18

Output:
4 8 12 16
6 12 18
```

-----

### Code
```cpp
#include <bits/stdc++.h> 
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n][m];
        // Nhap ma tran
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        
        // Tim so lon nhat tren moi dong
        for(int i = 0; i < n; i++){
            int max_val = a[i][0];
            for(int j = 1; j < m; j++){
                if(a[i][j] > max_val){
                    max_val = a[i][j];
                }
            }
            cout << max_val << " ";
        }
        cout << endl;
    }
    return 0;
}
```
----- 
# Bài 13. Sắp xếp ma trận xoắn ốc

Cho ma trận vuông $A$ cỡ $N \times N$ chỉ bao gồm các số nguyên dương không quá $1000$. Hãy sắp đặt các giá trị trong ma trận $A$ sao cho các số được điền lần lượt theo kiểu xoắn ốc tăng dần, theo chiều kim đồng hồ.

### Input
- Dòng đầu ghi số $N$ ($2 < N < 20$).
- $N$ dòng tiếp theo ghi ma trận $A$, các giá trị nguyên dương và không quá $1000$.

### Output
- Ghi ra ma trận kết quả sau khi sắp xếp theo hình xoắn ốc tăng dần.

### Ví dụ

```text
Input:
3
3 6 1
8 7 9
12 5 4

Output:
1 3 4
9 12 5
8 7 6
```

---

### Phân tích & Gợi ý cách làm:

#### 1. Ý tưởng thuật toán:
- **Bước 1:** Đọc tất cả $N \times N$ phần tử của ma trận và gom vào một mảng một chiều (hoặc `vector<int> v;`).
- **Bước 2:** Sắp xếp `vector` tăng dần bằng `sort(v.begin(), v.end());`.
- **Bước 3:** Sử dụng **thuật toán 4 biến biên** (`h1, h2, c1, c2`), thay vì in ra thì ta gán lần lượt từng phần tử nhỏ nhất từ `v` vào ma trận kết quả `ans[n][n]`:
  - Dùng biến chỉ số `int idx = 0;`.
  - Hàng trên: `ans[h1][i] = v[idx++];`
  - Cột phải: `ans[i][c2] = v[idx++];`
  - Hàng dưới: `ans[h2][i] = v[idx++];`
  - Cột trái: `ans[i][c1] = v[idx++];`
- **Bước 4:** In ma trận `ans` ra màn hình theo định dạng $N$ dòng, $N$ cột.

#### 2. Code:
```cpp
#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            v.push_back(x);
        }
    }
    
    // Sap xep tang dan
    sort(v.begin(), v.end());
    
    int ans[n][n];
    int h1 = 0, h2 = n - 1;
    int c1 = 0, c2 = n - 1;
    int idx = 0;
    
    while(h1 <= h2 && c1 <= c2){
        // 1. Hang tren
        for(int i = c1; i <= c2; i++){
            ans[h1][i] = v[idx++];
        }
        ++h1;
        
        // 2. Cot phai
        for(int i = h1; i <= h2; i++){
            ans[i][c2] = v[idx++];
        }
        --c2;
        
        // 3. Hang duoi
        if(h1 <= h2){
            for(int i = c2; i >= c1; i--){
                ans[h2][i] = v[idx++];
            }
            --h2;
        }
        
        // 4. Cot trai
        if(c1 <= c2){
            for(int i = h2; i >= h1; i--){
                ans[i][c1] = v[idx++];
            }
            ++c1;
        }
    }
    
    // In ma tran ket qua
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```