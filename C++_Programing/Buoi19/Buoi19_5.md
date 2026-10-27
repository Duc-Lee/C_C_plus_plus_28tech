# Các Hàm Thuật Toán Thông Dụng Trong Thư Viện Algorithm C++

## 1. Hàm `min()` và `min_element()`

### Hàm `min(a,b)`
- Cú pháp : `std::min(a, b)`
- Trả về giá trị nhỏ hơn giữa `a` và `b`.
- Độ phức tạp : $O(1)$

```cpp
#include <iostream>
#include <algorithm>
using namesapce std;


int main(){
    int a = 10;
    int b = 20;
    // tim gia tri nho nhat 
    int c = min(a, b);
    cout << c << endl;
    // ngoai ra min con co the cho nhieu gia tri 
    int d = min({30,6,77,8,33,1});
    cout << d << endl;
    // min cho mang, vector 
    vector<int> v = {10,20,30,40,50};
    int e = min(v);
    cout << e << endl;
    return 0;
}
```

### Hàm `min_element()`
- Cú pháp : `std::min_element(begin, end)`
- Dùng để tìm phần tử có giá trị nhỏ nhất trong đoạn `[begin, end)`.
- Trả về iterator đến phần tử nhỏ nhất.
- Độ phức tạp : $O(n)$

```cpp
#include <iostream>
#include <algorithm>
using namesapce std;


int main(){
    int a[] = {10,20,30,40,50};
    int n = sizeof(a)/sizeof(a[0]);
    // tim phan tu nho nhat 
    // luu y ham min_element tra ve iterator chu khong tra ve gia tri 
    // nen can de tham chieu 
    int min = min_element(a, a+n);
    cout << *min << endl;
    // min_element cho vector 
    vector<int> v = {10,20,30,40,50};
    auto min_it = min_element(v.begin(), v.end());
    cout << *min_it << endl;
    return 0;
}
```

## 2. Hàm `max()` và `max_element()`

### Hàm `max(a, b)`
- Cú pháp : `std::max(a, b)`
- Trả về giá trị lớn nhất giữa `a` và `b`.
- Độ phức tạp : $O(1)$

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a = 10;
    int b = 20;
    // tim gia tri lon nhat 
    int c = max(a, b);
    cout << c << endl;
    // ngoai ra max con co the cho nhieu gia tri 
    int d = max({30, 6, 77, 8, 33, 1});
    cout << d << endl;
    return 0;
}
```

### Hàm `max_element()`
- Cú pháp : `std::max_element(begin, end)`
- Dùng để tìm phần tử có giá trị lớn nhất trong đoạn `[begin, end)`.
- Trả về iterator đến phần tử lớn nhất.
- Độ phức tạp : $O(n)$

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    // tim phan tu lon nhat 
    // luu y ham max_element tra ve iterator chu khong tra ve gia tri 
    // nen can giai tham chieu (*)
    int* max_val = max_element(a, a + n);
    cout << *max_val << endl;
    // max_element cho vector 
    vector<int> v = {10, 20, 30, 40, 50};
    auto max_it = max_element(v.begin(), v.end());
    cout << *max_it << endl;
    return 0;
}
```

## 3. Hàm `accumulate()` 

- Cú pháp : `accumulate(begin, end, init)`
- Hàm `accumulate()` tính tổng của tất cả các phần tử trong đoạn `[begin, end)` và cộng thêm giá trị `init`.
- Độ phức tạp : $O(n)$

```cpp
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main(){
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    // tinh tong cua mang 
    // 10+20+30+40+50+0 = 150
    // tham so 0 la gia tri duoc cong them 
    int sum = accumulate(a, a + n, 0);
    cout << sum << endl;
    // tinh tong cua vector 
    // 10+20+30+40+50+0 = 150 
    // neu thay the no bang 10
    // 10 + 10 + 20 + 30 + 40 + 50 = 160
    vector<int> v = {10,20,30,40,50};
    int sum_vector = accumulate(v.begin(), v.end(), 10);
    cout << sum_vector << endl;
    return 0;
}
```

## 4. Hàm `swap()`

- Cú pháp : `std::swap(a, b)`
- Hàm `swap()` hoán đổi giá trị của `a` và `b`.
- Độ phức tạp : $O(1)$

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a = 10;
    int b = 20;
    // hoan doi gia tri cua a va b 
    // sau khi hoan doi a = 20 va b = 10
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}
```

## 5. Hàm `sort()`

- Cú pháp : `std::sort(begin, end, cmp)`
- Sắp xếp các phần tử trong đoạn `[begin, end)` theo thứ tự tăng dần.
- Độ phức tạp : $O(n \log n)$

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    // sap xep mang theo thu tu tang dan 
    sort(a, a + n);
    // in ra mang da sap xep 
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    // sap xep mang giam dan 
    // thi them tham so greater<int>()
    sort(a, a + n, greater<int>());
    // in ra mang da sap xep 
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    // sap xep theo 1 ham nao do 
    // su dung lambda expression 
    sort(a, a + n, [](int x, int y){
        return x > y;
    });
    // in ra mang da sap xep theo lambda 
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;   
    return 0;
}
```

## 6. Hàm `stable_sort()`

- Cú pháp : `std::stable_sort(begin, end, cmp)`
- Hàm `stable_sort()` là phiên bản cải tiến của hàm `sort()`, nó đảm bảo rằng các phần tử có giá trị bằng nhau sẽ giữ nguyên thứ tự tương đối của chúng trong mảng sau khi được sắp xếp.
- Độ phức tạp : $O(n \log n)$

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    // sap xep mang theo thu tu tang dan 
    stable_sort(a, a + n);
    // in ra mang da sap xep 
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    // sap xep mang giam dan 
    // thi them tham so greater<int>()
    stable_sort(a, a + n, greater<int>());
    // in ra mang da sap xep 
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    // sap xep theo 1 ham nao do 
    // su dung lambda expression 
    stable_sort(a, a + n, [](int x, int y){
        return x > y;
    });
    // in ra mang da sap xep theo lambda 
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;   
    return 0;
}
```

## 7. Hàm `find()`

- Cú pháp : `std::find(begin, end, value)`
- Hàm `find()` tìm kiếm phần tử có giá trị `value` trong đoạn `[begin, end)`.
- Trả về iterator đến phần tử tìm thấy.
- Độ phức tạp : $O(n)$

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    // tim phan tu co gia tri 30
    auto it = find(a, a + n, 30);
    // neu tim thay thi in ra vi tri 
    if (it != a + n){
        cout << "Phan tu duoc tim thay tai vi tri: " << it - a << endl;
    }
    // tim phan tu khong co trong mang 
    auto it2 = find(a, a + n, 60);
    // neu khong tim thay thi in ra -1 
    if (it2 == a + n){
        cout << "Phan tu khong duoc tim thay " << endl;
    }
    // find cho vector 
    vector<int> v = {10, 20, 30, 40, 50};
    auto it3 = find(v.begin(), v.end(), 30);
    if (it3 != v.end()){
        cout << "Phan tu duoc tim thay tai vi tri: " << it3 - v.begin() << endl;
    }
    return 0;
}
```

## 8. Hàm `binary_search()`

- Cú pháp : `std::binary_search(begin, end, value)`
- Hàm `binary_search()` tìm kiếm phần tử có giá trị `value` trong đoạn `[begin, end]`. 
  - Yêu cầu mảng phải được sắp xếp.
- Trả về `true` nếu tìm thấy, `false` nếu không tìm thấy.
- Độ phức tạp : $O(\log n)$

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    // tim phan tu co gia tri 30
    bool found = binary_search(a, a + n, 30);
    // neu tim thay thi in ra vi tri 
    if (found){
        // dung lower_bound de tim vi tri (index) xuat hien dau tien cua 30
        cout << "Phan tu duoc tim thay tai vi tri: " << lower_bound(a, a + n, 30) - a << endl;
    }
    // tim phan tu khong co trong mang 
    bool found2 = binary_search(a, a + n, 60);
    // neu khong tim thay thi in ra -1 
    if (!found2){
        cout << "Phan tu khong duoc tim thay " << endl;
    }
    // binary_search cho vector 
    vector<int> v = {10, 20, 30, 40, 50};
    bool found3 = binary_search(v.begin(), v.end(), 30);
    if (found3){
        cout << "Phan tu duoc tim thay tai vi tri: " << lower_bound(v.begin(), v.end(), 30) - v.begin() << endl;
    }
    return 0;
}
```

## 9. Hàm `lower_bound()` và `upper_bound()`

> **Điều kiện bắt buộc:** Mảng hoặc vector **phải được sắp xếp tăng dần** trước khi dùng. Nếu chưa sắp xếp, kết quả trả về sẽ không chính xác!  
> Cả 2 hàm đều sử dụng thuật toán tìm kiếm nhị phân nên có độ phức tạp: $O(\log n)$.

### a. Hàm `lower_bound()`
- **Cú pháp:** `std::lower_bound(begin, end, value)`
- **Ý nghĩa:** Trả về iterator trỏ đến phần tử **đầu tiên** có giá trị **$\ge$ `value`** (lớn hơn hoặc bằng `value`) trong nửa khoảng `[begin, end)`.
- **Nếu không tìm thấy:** (tức mọi phần tử trong đoạn đều nhỏ hơn `value`), hàm trả về iterator `end`.

### b. Hàm `upper_bound()`
- **Cú pháp:** `std::upper_bound(begin, end, value)`
- **Ý nghĩa:** Trả về iterator trỏ đến phần tử **đầu tiên** có giá trị **$>$ `value`** (lớn hơn hẳn `value`) trong nửa khoảng `[begin, end)`.
- **Nếu không tìm thấy:** (tức không có phần tử nào lớn hơn `value`), hàm trả về iterator `end`.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a[] = {1, 2, 3, 3, 3, 5, 8, 10};
    int n = sizeof(a) / sizeof(a[0]);

    // 1. lower_bound: tim phan tu dau tien >= 3
    // -> tra ve con tro toi so 3 dau tien (chi so 2)
    auto it1 = lower_bound(a, a + n, 3);
    if (it1 != a + n){
        cout << "lower_bound(3): vi tri = " << it1 - a << ", gia tri = " << *it1 << endl;
    }

    // 2. upper_bound: tim phan tu dau tien > 3
    // -> tra ve con tro toi so 5 (chi so 5)
    auto it2 = upper_bound(a, a + n, 3);
    if (it2 != a + n){
        cout << "upper_bound(3): vi tri = " << it2 - a << ", gia tri = " << *it2 << endl;
    }

    // 3. Dem so lan xuat hien cua so 3 trong mang: upper_bound - lower_bound
    int count_3 = upper_bound(a, a + n, 3) - lower_bound(a, a + n, 3);
    cout << "So lan xuat hien cua so 3: " << count_3 << endl;

    // 4. Truong hop khong tim thay: tim phan tu >= 15
    auto it3 = lower_bound(a, a + n, 15);
    if (it3 == a + n){
        cout << "Khong co phan tu nao >= 15 trong mang" << endl;
    }

    // 5. Ap dung cho vector
    vector<int> v = {10, 20, 20, 30, 40};
    auto it_vec = lower_bound(v.begin(), v.end(), 20);
    cout << "Vi tri dau tien >= 20 trong vector: " << it_vec - v.begin() << endl;

    return 0;
}
```

## 10. Hàm `fill()`

- Cú pháp : `std::fill(begin, end, value)`
- Hàm `fill()` gán giá trị `value` cho tất cả các phần tử trong đoạn `[begin, end)`.
- Độ phức tạp : $O(n)$

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[10] = {0};
    // gan 10 cho toan bo mang
    fill(a, a + 10, 10);
    // in ra mang
    for (int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    // out : 10 10 10 10 10 10 10 10 10 10
    cout << endl;
    return 0;
}
```

## 11. Hàm `memset()`

- Cú pháp : `memset(pointer, value, size)`
- Hàm `memset()` gán giá trị `value` cho tất cả các byte trong đoạn bộ nhớ bắt đầu từ địa chỉ `pointer` với độ dài `size` (tính bằng byte).
- Hàm `memset()` chỉ có tác dụng chính xác với giá trị 0 hoặc -1.
- Hàm `memset()` không có tác dụng với các kiểu dữ liệu có kích thước lớn hơn 1 byte (ví dụ: `int`, `long`, `double`).
- Hàm `memset()` có độ phức tạp $O(n)$.
- Hàm `memset()` khác `fill()` ở chỗ `memset()` gán giá trị `value` cho tất cả các byte trong đoạn bộ nhớ bắt đầu từ địa chỉ `pointer` với độ dài `size` (tính bằng byte), trong khi `fill()` gán giá trị `value` cho tất cả các phần tử trong đoạn `[begin, end)`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[10] = {0};
    // gan 10 cho toan bo mang
    memset(a, 10, sizeof(a));
    // in ra mang
    for (int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    // out : 10 10 10 10 10 10 10 10 10 10
    cout << endl;
    return 0;
}
```

## 12. Hàm `merge()`

- Cú pháp : `std::merge(begin1, end1, begin2, end2, result)`
- Hàm `merge()` gộp hai mảng đã sắp xếp `[begin1, end1)` và `[begin2, end2)` thành một mảng đã sắp xếp `result`.
- Điều kiện : Hai mảng `[begin1, end1)` và `[begin2, end2)` phải được sắp xếp.
- Hàm `merge()` có độ phức tạp $O(n)$.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int c[n + m];
    // gop hai mang da sap xep 
    merge(a, a + n, b, b + m, c);
    // in ra mang da sap xep
    for (int i = 0; i < n + m; i++){
        cout << c[i] << " ";
    }
    // out : 1 2 3 4 5 6 7 8 9 10
    cout << endl;
    return 0;
}
```

## 13. Hàm `reverse()`

- Cú pháp : `std::reverse(begin, end)`
- Hàm `reverse()` đảo ngược thứ tự các phần tử trong đoạn `[begin, end)`.
- Hàm `reverse()` có độ phức tạp $O(n)$.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    // dao nguoc mang
    reverse(a, a + n);
    // in ra mang da dao nguoc
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    // out : 5 4 3 2 1
    cout << endl;
    return 0;
}
```

## 14. Hàm `set_union()`

- Cú pháp : `std::set_union(begin1, end1, begin2, end2, result)`
- Hàm `set_union()` gộp hai mảng đã sắp xếp `[begin1, end1)` và `[begin2, end2)` thành một mảng đã sắp xếp `result`.
- Điều kiện : Hai mảng `[begin1, end1)` và `[begin2, end2)` phải được sắp xếp.
- Hàm `set_union()` có độ phức tạp $O(n)$.
- Hàm `set_union()` khác `merge` ở chỗ nó chỉ lấy các phần tử duy nhất, tức là nếu có phần tử trùng lặp trong hai mảng thì nó sẽ chỉ lấy một lần.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int c[n + m];
    // gop hai mang da sap xep 
    set_union(a, a + n, b, b + m, c);
    // in ra mang da sap xep
    for (int i = 0; i < n + m; i++){
        cout << c[i] << " ";
    }
    // out : 1 2 3 4 5 6 7 8 9 10
    cout << endl;
    return 0;
}
```

## 15. Hàm `set_intersection()`

- Cú pháp : `std::set_intersection(begin1, end1, begin2, end2, result)`
- Hàm `set_intersection()` tìm các phần tử chung của hai mảng đã sắp xếp `[begin1, end1)` và `[begin2, end2)` và gộp chúng thành một mảng đã sắp xếp `result`.
- Điều kiện : Hai mảng `[begin1, end1)` và `[begin2, end2)` phải được sắp xếp.
- Hàm `set_intersection()` có độ phức tạp $O(n)$.
- Hàm `set_intersection()` khác `merge` ở chỗ nó chỉ lấy các phần tử chung của hai mảng.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int c[n + m];
    // tim cac phan tu chung cua hai mang da sap xep 
    set_intersection(a, a + n, b, b + m, c);
    // in ra mang cac phan tu chung 
    for (int i = 0; i < n + m; i++){
        cout << c[i] << " ";
    }
    // out : 2 4
    cout << endl;
    return 0;
}
```

## 16. Hàm `set_difference()`

- Cú pháp : `std::set_difference(begin1, end1, begin2, end2, result)`
- Hàm `set_difference()` tìm các phần tử trong mảng `[begin1, end1)` nhưng không có trong mảng `[begin2, end2)` và gộp chúng thành một mảng đã sắp xếp `result`.
- Điều kiện : Hai mảng `[begin1, end1)` và `[begin2, end2)` phải được sắp xếp.
- Hàm `set_difference()` có độ phức tạp $O(n)$.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int c[n + m];
    // tim cac phan tu trong mang a nhung khong co trong mang b
    set_difference(a, a + n, b, b + m, c);
    // in ra mang cac phan tu trong a nhung khong co trong b
    for (int i = 0; i < n + m; i++){
        cout << c[i] << " ";
    }
    // out : 1 3 5
    cout << endl;
    return 0;
}
```

## 17. Hàm `set_symmetric_difference()`

- Cú pháp : `std::set_symmetric_difference(begin1, end1, begin2, end2, result)`
- Hàm `set_symmetric_difference()` tìm các phần tử trong mảng `[begin1, end1)` hoặc `[begin2, end2)` nhưng không có trong cả hai mảng và gộp chúng thành một mảng đã sắp xếp `result`.
- Điều kiện : Hai mảng `[begin1, end1)` và `[begin2, end2)` phải được sắp xếp.
- Hàm `set_symmetric_difference()` có độ phức tạp $O(n)$.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int c[n + m];
    // tim cac phan tu trong mang a hoac mang b nhung khong co trong ca hai mang 
    set_symmetric_difference(a, a + n, b, b + m, c);
    // in ra mang cac phan tu trong a hoac mang b nhung khong co trong ca hai mang
    for (int i = 0; i < n + m; i++){
        cout << c[i] << " ";
    }
    // out : 1 3 5 6 8 10
    cout << endl;
    return 0;
}
```