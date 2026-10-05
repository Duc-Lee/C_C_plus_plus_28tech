# Kiểu Pair Trong Ngôn Ngữ Lập Trình C++

## 1. Khái niệm
`pair` (cặp) là một class template (khuôn mẫu lớp) trong C++ được sử dụng để kết hợp hai giá trị (có thể cùng hoặc khác kiểu dữ liệu) thành một đơn vị duy nhất.
Nó được định nghĩa trong thư viện `<utility>` (hoặc có thể dùng thư viện chung `<bits/stdc++.h>`).

## 2. Cú pháp khai báo
```cpp
pair<datatype1, datatype2> p;
```
Trong đó `datatype1` và `datatype2` có thể là bất kỳ kiểu dữ liệu nào (int, float, string, hoặc kể cả cấu trúc dữ liệu khác như vector, map, set hay một `pair` khác).

## 3. Khởi tạo và gán giá trị
Có nhiều cách để khởi tạo hoặc gán giá trị cho một `pair`:

**Cách 1: Sử dụng hàm `make_pair()`**
```cpp
pair<int, string> p;
p = make_pair(100, "Hello");
```

**Cách 2: Khởi tạo bằng `{}` (từ C++11)**
```cpp
pair<int, string> p = {100, "Hello"};
// Hoặc gán lại giá trị
p = {200, "World"};
```

## 4. Truy cập các phần tử
Để truy cập vào các phần tử của `pair`, ta sử dụng toán tử `.` (dot) với `first` và `second`:
- `p.first`: Truy cập vào phần tử đầu tiên.
- `p.second`: Truy cập vào phần tử thứ hai.

**Ví dụ:**
```cpp
#include <iostream>
#include <utility>

using namespace std;

int main() {
    pair<int, string> p = {1, "Mot"};
    
    cout << "Phan tu thu nhat: " << p.first << endl; // Output: 1
    cout << "Phan tu thu hai: " << p.second << endl; // Output: Mot
    
    return 0;
}
```