# Hướng dẫn sử dụng Vector trong C++

- Thông thường ta sử dụng mảng `array` để lưu trữ dữ liệu, nhưng đây là mảng tĩnh có kích thước cố định, không thể thay đổi khi chương trình chạy, do đó trong trường hợp không biết trước kích thước của mảng ta sẽ sử dụng `vector`
- `vector` là một lớp trong `STL` (Standard Template Library) của C++, nó là một mảng động có thể thay đổi kích thước khi chương trình chạy 

## 1. Khai báo `vector`
- Cú pháp : 
```cpp
        vector<kieu_du_lieu> ten_vector; 
        // vector co the khai bao kich thuoc ngay khi khai bao 
        vector<kieu_du_lieu> ten_vector[kich_thuoc];
```
- Ví dụ cụ thể : 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Khai bao vector 
    // vector<kieu du lieu> ten_vector;
    // vector<int> v;
    // vector<string> v;
    // vector<char> v;
    // vector<double> v;
    // vector<bool> v;
    // vector<int> v[10]; // khai bao vector 2 chieu
    // vector<vector<int>> v[10]; // khai bao vector 3 chieu
    // vector<vector<vector<int>>> v[10]; // khai bao vector 4 chieu
    return 0;
}
``` 
- Khai 

## 2. Mảng động `vector`
- Bản chất `vector` thực chất là 1 lớp được cài đặt từ `array`, nó là 1 mảng động có thể thay đổi kích thước khi chương trình chạy
- Nên nó có thể truy cập các phần tử thông qua index tương tự như mảng 1 chiều

| Chỉ số (Index) | 0 | 1 | 2 | 3 | 4 |
| :---: | :---: | :---: | :---: | :---: | :---: |
| Giá trị (Value) | 2 | 4 | 6 | 8 | 10 |

- Ví dụ : 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> v;
    // them pha tu vao vector
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);
    // bay gio vector co dang la 2 4 6 8 10
    // truy cap vao phan tu cua vector 
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    // In phan tu cuoi cung 
    cout << v.back() << endl;
    // hoac tuong duong 
    cout << v[v.size() - 1] << endl;
    // duyet vector 
    // trong vector co 2 con tro dac biet do la begin() va end() 
    // begin() la con tro tro den phan tu dau tien cua vector 
    // end() la con tro tro den phan tu sau phan tu cuoi cung cua vector 
    // auto la 1 khai bao bien ngam dinh, o day no ngam dinh kieu du lieu cua bien it la vector<int>::iterator ( toan tu pham vi)
    // for(vector<int>::iterator it = v.begin(); it != v.end(); it++) 
    //      cout << *it << " ";
    // tuong duong voi 
    for(auto it = v.begin(); it != v.end(); it++) {
        // *it la lay gia tri cua vector tai vi tri con tro it tro den 
        cout << *it << " ";
    }
    return 0;
}
```
## 3. Iterator trong vector
- Iterator là 1 con trỏ đặc biệt được sử dụng để truy cập các phần tử của `vector`, nó có các đặc điểm giống như con trỏ thông thường
- Ta có 2 con trỏ đặc biệt trong vector là : `begin()` và `end()`
    - `begin()`: là con trỏ trỏ đến phần tử đầu tiên của vector
    - `end()`: là con trỏ trỏ đến ô nằm sau phần tử cuối cùng của vector (khác với C)

- Ví dụ : 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> v;
    // them pha tu vao vector
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);
    // bay gio vector co dang la 2 4 6 8 10
    // duyet vector 
    // trong vector co 2 con tro dac biet do la begin() va end() 
    // begin() la con tro tro den phan tu dau tien cua vector 
    // end() la con tro tro den phan tu sau phan tu cuoi cung cua vector 
    // auto la 1 khai bao bien ngam dinh, o day no ngam dinh kieu du lieu cua bien it la vector<int>::iterator ( toan tu pham vi)
    // for(vector<int>::iterator it = v.begin(); it != v.end(); it++) 
    //      cout << *it << " ";
    // tuong duong voi 
    for(auto it = v.begin(); it != v.end(); it++) {
        // *it la lay gia tri cua vector tai vi tri con tro it tro den 
        cout << *it << " ";
    }
    return 0;
}
```

## 4. Các thao tác với `vector`

### a. Hàm `push_back()`
- Hàm `push_back()` được sử dụng để thêm một phần tử vào cuối `vector`, nó làm tăng kích thước của `vector` lên 1 đơn vị và có độ phức tạp O(1)

- Ví dụ : 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> v;
    // 1. Thêm phần tử vào cuối vector 
    v.push_back(1);
    // 1 2
    v.push_back(2);
    // 1 2 3
    v.push_back(3);
    // 1 2 3 4
    v.push_back(4);
    // 1 2 3 4 5
    v.push_back(5);
    // in vector 
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
```

### b. Hàm `size`
- Hàm `size` được sử dụng để trả về kích thước của `vector`, có độ phức tạp O(1)
- Ví dụ : 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> v;
    // 1. Thêm phần tử vào cuối vector 
    v.push_back(1);
    // 1 2
    v.push_back(2);
    // 1 2 3
    v.push_back(3);
    // 1 2 3 4
    v.push_back(4);
    // 1 2 3 4 5
    v.push_back(5);
    // in ra size cua vector 
    cout << v.size() << endl; // 5
    return 0;
}
```
