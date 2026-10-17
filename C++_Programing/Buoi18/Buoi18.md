# Thuật Toán Tìm Kiếm Nhị Phân | Hàm Lower_bound và Upper_bound Trong Thư Viện STL

## 1. Tìm kiếm tuyến tính
- Tìm kiếm tuyến tính (Linear Search hoặc Sequential Search) là thuật toán tìm kiếm cơ bản nhất trong khoa học máy tính. Thuật toán này kiểm tra tuần tự từng phần tử trong danh sách từ đầu đến cuối cho đến khi tìm thấy phần tử cần tìm hoặc duyệt hết danh sách

- Nguyên lý hoạt động: 
    - Ví dụ: Cho mảng `arr[] = {3, 2, 6, 5, 9}` và `target = 5`

        + **Tại $i = 0$:**
        ```text
           0     1     2     3     4
        ┌─────┬─────┬─────┬─────┬─────┐
        │  3  │  2  │  6  │  5  │  9  │
        └─────┴─────┴─────┴─────┴─────┘
           ▲
           │
           │
        ```
        $\Rightarrow \text{target} \neq \text{arr}[0] \ (5 \neq 3) \implies i\text{++}$

        + **Tại $i = 1$:**
        ```text
           0     1     2     3     4
        ┌─────┬─────┬─────┬─────┬─────┐
        │  3  │  2  │  6  │  5  │  9  │
        └─────┴─────┴─────┴─────┴─────┘
                 ▲
                 │
                 │
        ```
        $\Rightarrow \text{target} \neq \text{arr}[1] \ (5 \neq 2) \implies i\text{++}$

        + **Tại $i = 2$:**
        ```text
           0     1     2     3     4
        ┌─────┬─────┬─────┬─────┬─────┐
        │  3  │  2  │  6  │  5  │  9  │
        └─────┴─────┴─────┴─────┴─────┘
                       ▲
                       │
                       │
        ```
        $\Rightarrow \text{target} \neq \text{arr}[2] \ (5 \neq 6) \implies i\text{++}$

        + **Tại $i = 3$:**
        ```text
           0     1     2     3     4
        ┌─────┬─────┬─────┬─────┬─────┐
        │  3  │  2  │  6  │  5  │  9  │
        └─────┴─────┴─────┴─────┴─────┘
                             ▲
                             │
                             │
        ```
        $\Rightarrow \text{target} == \text{arr}[3] \ (5 == 5) \implies \text{True}$ *(Tìm thấy phần tử tại vị trí $i = 3$, kết thúc tìm kiếm)*

- Do duyệt từng phần tử một nên thuật toán có độ phức tạp là $O(n)$

```cpp
#include <bits/stdc++.h>
using namespace std;

// khoi tao ham tim kiem tuyen tinh 
bool linear_search(int a[], int n, int target){
    // duyet qua tung ptu trong mang 
    for(int i =0;i<n;i++){
        // neu tim thay phan tu 
        if(a[i] == target){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    // khoi tao phan tu can tim
    int target;
    cin >> target;
    if(linear_search(a, n, target)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
```

## 2. Thuật toán tìm kiếm nhị phân 

- Tìm kiếm nhị phân (Binary Search) là thuật toán tìm kiếm áp dụng trên một mảng đã được sắp xếp. Thuật toán hoạt động theo nguyên lý chia để trị (divide and conquer): liên tục so sánh giá trị cần tìm với phần tử ở vị trí giữa danh sách và loại bỏ một nửa không gian tìm kiếm sau mỗi bước.

- Thuật toán tìm kiếm nhị phân có độ phức tạp là $O(\log n)$

- Nguyên lý hoạt động:
    - Xác định hai chỉ số biên của không gian tìm kiếm: low = 0 và high = n - 1.
    - Tính chỉ số ở giữa: mid = low + (high - low) / 2.
    - So sánh phần tử tại mid với giá trị mục tiêu target:
        - Nếu arr[mid] == target: Tìm thấy phần tử, trả về chỉ số mid.
        - Nếu arr[mid] < target: Phần tử cần tìm nằm ở nửa bên phải $\rightarrow$ Cập nhật low = mid + 1.
        - Nếu arr[mid] > target: Phần tử cần tìm nằm ở nửa bên trái $\rightarrow$ Cập nhật high = mid - 1.
    - Lặp lại bước 2–3 cho đến khi tìm thấy hoặc khi low > high (phần tử không tồn tại trong mảng, trả về -1).

    - **Ví dụ:** Cho mảng `arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}` ($n = 10$) và giá trị cần tìm `target = 3`.

#### Quá trình thực hiện từng bước:

* **Bước 1:** Khởi tạo $l = 0, r = 9$ (với $l$ là `low`, $r$ là `high`)
    * Tính $mid = \lfloor \frac{l + r}{2} \rfloor = \lfloor \frac{0 + 9}{2} \rfloor = 4$.
    * Mô phỏng mảng:
      ```text
         0     1     2     3     4     5     6     7     8     9
      ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      │  0  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │
      └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
         ▲                       ▲                             ▲
         │                       │                             │
       l = 0                  mid = 4                        r = 9
      ```
    * So sánh: $target < arr[mid] \ (3 < 4) \rightarrow$ Phần tử cần tìm nằm ở nửa bên trái của $mid$.
    * Cập nhật biên phải: $r = mid - 1 = 4 - 1 = 3$.

---

* **Bước 2:** Không gian tìm kiếm thu hẹp còn $l = 0, r = 3$
    * Tính $mid = \lfloor \frac{l + r}{2} \rfloor = \lfloor \frac{0 + 3}{2} \rfloor = 1$.
    * Mô phỏng mảng:
      ```text
         0     1     2     3     4     5     6     7     8     9
      ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      │  0  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │
      └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
         ▲     ▲                 ▲
         │     │                 │
        l=0  mid=1              r=3
      ```
    * So sánh: $target > arr[mid] \ (3 > 1) \rightarrow$ Phần tử cần tìm nằm ở nửa bên phải của $mid$.
    * Cập nhật biên trái: $l = mid + 1 = 1 + 1 = 2$.

---

* **Bước 3:** Không gian tìm kiếm thu hẹp còn $l = 2, r = 3$
    * Tính $mid = \lfloor \frac{l + r}{2} \rfloor = \lfloor \frac{2 + 3}{2} \rfloor = 2$.
    * Mô phỏng mảng:
      ```text
         0     1     2     3     4     5     6     7     8     9
      ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      │  0  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │
      └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
                     ▲     ▲
                     │     │
                  l=mid=2 r=3
      ```
    * So sánh: $target > arr[mid] \ (3 > 2) \rightarrow$ Phần tử cần tìm nằm ở nửa bên phải của $mid$.
    * Cập nhật biên trái: $l = mid + 1 = 2 + 1 = 3$.

---

* **Bước 4:** Không gian tìm kiếm chỉ còn $l = 3, r = 3$
    * Tính $mid = \lfloor \frac{l + r}{2} \rfloor = \lfloor \frac{3 + 3}{2} \rfloor = 3$.
    * Mô phỏng mảng:
      ```text
         0     1     2     3     4     5     6     7     8     9
      ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      │  0  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │
      └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
                           ▲
                           │
                       l=r=mid=3
      ```
    * So sánh: $target == arr[mid] \ (3 == 3) \rightarrow$ **True** *(Tìm thấy phần tử tại vị trí $mid = 3$, kết thúc tìm kiếm)*.

---

#### Mô hình hóa theo nguyên lý chia để trị (Divide & Conquer):

```text
       0     1     2     3     4     5     6     7     8     9
    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
    │  0  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │
    └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
             │                 │                 │
             ▼                 ▼                 ▼
    ┌───┬───┬───┬───┐        ┌───┐        ┌───┬───┬───┬───┬───┐
    │ 0 │ 1 │ 2 │ 3 │        │ 4 │        │ 5 │ 6 │ 7 │ 8 │ 9 │   (target < arr[mid] -> Loại nửa phải)
    └───┴───┴───┴───┘        └───┘        └───┴───┴───┴───┴───┘
      0   1   2   3         mid=4
      │   │   │
      ▼   ▼   ▼
    ┌───┐┌───┐┌───┬───┐
    │ 0 ││ 1 ││ 2 │ 3 │                                           (target > arr[mid] -> Loại nửa trái)
    └───┘└───┘└───┴───┘
      0  mid=1  2   3
                │   │
                ▼   ▼
              ┌───┐┌───┐
              │ 2 ││ 3 │                                          (target > arr[mid] -> target == 3 => True)
              └───┘└───┘
              mid=2 mid=3
```

#### Cài đặt thuật toán 
```cpp
#include <iostream>
using namespace std;

// thuat toan tim kiem nhi phan 
bool binary_search(int arr[], int n, int target){
    // khoi tao 2 bien luu tru chi so cua phan tu dau va cuoi 
    int l = 0;
    int r = n-1;
    // lap khi nao tim thay hoac khi nao chi so cua phan tu dau nho hon chi so cua phan tu cuoi 
    while(l <= r){
        // tinh gia tri cua phan tu o giua 
        int mid = l + (r-l)/2;
        // kiem tra xem co bang target khong 
        if(arr[mid] == target){
            return true;
        }
        // neu phan tu o giua nho hon target 
        if(arr[mid] < target){
            l = mid + 1;
        }
        // neu phan tu o giua lon hon target 
        else{
            r = mid - 1;
        }
    }
    // neu khong tim thay target 
    return false;
}

// dung phuong phap de quy 
// nen truyen san tham so l, r
bool binary_search1(int arr[], int n, int l, int r, int target){
    // neu khong tim thay 
    if(l > r) return false; 
    // tinh phan tu mid
    int mid = l + (r-l)/2;
    // neu phan tu o giua bang target 
    if(arr[mid] == target){ 
        return true;
    }
    // neu phan tu o giua nho hon target 
    if(arr[mid] < target){
        // kiem tra lai mang ben phai cua mid
        return binary_search1(arr, n, mid+1, r, target);
    }
    // neu phan tu o giua lon hon target 
    else{
        // kiem tra lai mang ben trai cua mid
        return binary_search1(arr, n, l, mid-1, target);
    }
}

int main(){
    // khoi tao mang da duoc sap xep san 
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 3;
    if(binary_search(arr, n, target)){
        cout << "Tim thay target" << endl;
    }
    else{
        cout << "Khong tim thay target" << endl;
    }
    return 0;
}
```

#### Sử dụng sẵn có trong C++ 
- TRong thư viện `<algorithm>` có hàm `std::binary_search()` 
- Hàm này trả về `true` nếu tìm thấy phần tử và `false` nếu không tìm thấy phần tử
- Cú pháp : 
```cpp
    bool found = std::binary_search(first, last, value);
    // first: con tro tro den phan tu dau tien trong mang 
    // last: con tro tro den phan tu cuoi cung trong mang 
    // value: gia tri can tim
```
- Ví dụ : 
```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 3;
    // con tro dau tien la a, mac dinh la a[0]
    // con tro ket thuc la a+n, mac dinh la a[n]
    // vi du tim kiem trong khoang tu a[l] den a[r] (bao gom ca a[r]) 
    // thi con tro dau tien la a+l, con tro ket thuc la arr+r+1 
    if(binary_search(arr, arr + n, target)){
        cout << "Tim thay target" << endl;
    }
    else{
        cout << "Khong tim thay target" << endl;
    }
    return 0;
}
```

- Ví dụ : Sử dụng với `vector`
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    int target = 3;
    // truyen v.begin() la con tro dau tien, v.end() la con tro cuoi cung 
    // the same voi mang 
    // con tro ket thuc la v.end() khong bao gom phan tu cuoi cung 
    // con tro bat dau la v.begin() bao gom phan tu dau tien 
    // trong vector 
    if(binary_search(v.begin(), v.end(), target)){
        cout << "Tim thay target" << endl;
    }
    else{
        cout << "Khong tim thay target" << endl;
    }
    return 0;
}
```

#### Ví dụ : 

##### a. Tìm vị trí đầu tiên của 1 phần tử  x trong 1 mảng đã sắp xếp
- Input : 
```
10 3 
1 2 2 3 3 3 3 7 8 9
```

- Output : 
```
3
```

- Code : 
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int binary_search(int arr[], int n, int target){
    // khoi tao 2 bien dau cuoi 
    int l = 0, r = n -1;
    // khoi tao bien luu tru ket qua 
    int ans = -1; 
    // lap khi nao tim thay 
    while(l <= r){
        // tinh phan tu giua
        int mid = l + (r-l)/2;
        // kiem tra xem co bang target khong 
        if(arr[mid] == target){
            ans = mid;
            // tim xem ben trai co con phan tu arr[mid] ?
            r = mid - 1;
        }
        // neu phan tu o giua nho hon target 
        else if(arr[mid] < target){
            l = mid + 1;
        }
        // neu phan tu o giua lon hon target 
        else{
            r = mid - 1;
        }
    }
    return ans;
}
    
int main(){
    int n,x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << binary_search(arr, n, x);
    return 0;
}
```

##### b. Tìm vị trí đầu tiên của 1 phần tử  >  x trong 1 mảng đã sắp xếp
- Input :
```
10 4
1 2 2 3 4 4 4 7 8 9
```

- Output :
```
7
```

- Code :
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int binary_search(int arr[], int n, int target){
    // khoi tao 2 bien dau cuoi 
    int l = 0, r = n -1;
    // khoi tao bien luu tru ket qua 
    int ans = -1; 
    // lap khi nao tim thay 
    while(l <= r){
        // tinh phan tu giua
        int mid = l + (r-l)/2;
        // kiem tra xem co lon hon target khong 
        if(arr[mid] > target){
            ans = mid;
            // tim xem ben trai co con phan tu > target ?
            r = mid - 1;
        }
        // neu phan tu o giua nho hon target 
        else{
            l = mid + 1;
        }
    }
    return ans;
}
    
int main(){
    int n,x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << binary_search(arr, n, x);
    return 0;
}
```

## 3. Hàm `lower_bound` 
- Trong thư viện chuẩn C++ (<algorithm>), hàm std::lower_bound() dùng thuật toán tìm kiếm nhị phân để tìm vị trí của phần tử đầu tiên trong đoạn `lớn hơn hoặc bằng` ($\ge$) giá trị cần tìm.

- Hàm `lower_bound()` lấy cận từ `first` (bao gồm `first`) đến cận `last` (không bao gồm `last`), tức là `[first, last)`

- Cú pháp cơ bản:
```cpp
    auto it = lower_bound(first, last, val);
```
- first, last: Các con trỏ hoặc iterator xác định phạm vi tìm kiếm [first, last).
- val: Giá trị cần tìm ($x$).
- Giá trị trả về: Trả về iterator (hoặc con trỏ) trỏ tới phần tử đầu tiên thỏa mãn $\ge val$.Nếu mọi phần tử trong đoạn đều nhỏ hơn $val$, hàm trả về last (vị trí kết thúc của đoạn, ngoài phạm vi hợp lệ).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {0,1,2,3,3,3,3,7,8,9};
    // tinh chieu dai mang arr
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    auto it = lower_bound(arr, arr + n, x);
    // the same voi vector 
    vector<int> v = {0,1,2,3,3,3,3,7,8,9};
    auto it1 = lower_bound(v.begin(), v.end(), x);
    // do tra ve vi tri nen phai tru di vi tri dau tien 
    // ham lower_bound() tra ve con tro nen phai lay gia tri cua con tro de so sanh 
    cout << *it - arr << endl; // ket qua : 7 
    cout << it1 - v.begin() << endl; // ket qua : 7 
    return 0;
}
```

- Nếu mà tất cả phần tử trong mảng đều nhỏ hơn `key` thì `it` và `it1` sẽ bằng `arr+n` và `v.end()` ( các phần tử cuối cùng) 

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {0,1,2,3,3,3,3,7,8,9};
    // tinh chieu dai mang arr
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    auto it = lower_bound(arr, arr + n, x);
    // neu khong tim thay se tra ve phan tu cuoi cung
    // neu vector thi .end() 
    if(it == (arr+n)){
        cout << "Khong tim thay phan tu lon hon hoac bang " << x << endl;
    }
    else{
        cout << "Phan tu lon hon hoac bang " << x << " dau tien la " << *it << endl;
    }
    // ket qua : Khong tim thay phan tu lon hon hoac bang 10
    return 0;
}
```

## 4. Hàm `upper_bound`

- Trong thư viện chuẩn C++ (<algorithm>), hàm std::upper_bound() dùng thuật toán tìm kiếm nhị phân để tìm vị trí của phần tử đầu tiên trong dãy `lớn hơn hẳn` ($>$) giá trị cần tìm.

- Hàm `upper_bound()` lấy cận từ `first` (bao gồm `first`) đến cận `last` (không bao gồm `last`), tức là `[first, last)`.

- Cú pháp cơ bản:
```cpp
    auto it = upper_bound(first, last, val);
```

- first, last: Các con trỏ hoặc iterator xác định phạm vi tìm kiếm `[first, last)`.

- val: Giá trị cần tìm ($x$).

- Giá trị trả về: Trả về iterator (hoặc con trỏ) trỏ tới phần tử đầu tiên thỏa mãn `> val`. Nếu mọi phần tử trong đoạn đều nhỏ hơn hoặc bằng `val`, hàm trả về last (vị trí kết thúc của đoạn, ngoài phạm vi hợp lệ).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,2,3,3,3,3,7,8,9};
    // tinh chieu dai mang arr
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    // ham upper_bound() tra ve con tro nen phai lay gia tri cua con tro de so sanh 
    auto it = upper_bound(arr, arr + n, x);
    // the same voi vector 
    vector<int> v = {1,2,2,3,3,3,3,7,8,9};
    auto it1 = upper_bound(v.begin(), v.end(), x);
    // do tra ve vi tri nen phai tru di vi tri dau tien 
    cout << *it - arr << endl; // ket qua : 8 
    cout << it1 - v.begin() << endl; // ket qua : 8 
    return 0;
}
```