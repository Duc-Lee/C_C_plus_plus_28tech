# Xâu kí tự trong C++

## 1. Giới thiệu xâu kí tự trong C++ 
- Nếu muốn lưu 1 kí tự ta dùng `char` ví dụ `char a = 'a';` 
- Nếu muốn lưu chuỗi kí tự hay nói cách khác là 1 xâu kí tự ta dùng mảng kí tự `char a[] = "Xin chào";`
- Khai báo : 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Khai bao mang ky tu (String)
    // trong C++ su dung string de khai bao xau ky tu
    string name = " Trinh Tran Phuong Tuan";
    cout << name;
    return 0;
}
```

- Khi khai báo có dấu cách 
```cpp
#include <iostream>
using namespace std;

int main() {
    // khai bao bien string 
    string s;
    // nhap : Le Anh Duc
    cin >> s;
    // Ket qua : Le 
    // vi ham cin chi nhap toi khi gap khoang trang
    cout << s;
    return 0;
}
```
- Để có thể nhập cả dòng thì ta dùng `getline`
```cpp
#include <iostream>
using namespace std;

int main() {
    // khai bao bien string 
    string s;
    // nhap : Le Anh Duc
    getline(cin, s);
    // Ket qua : Le Anh Duc 
    // vi ham getline nhap ca dong 
    cout << s;
    return 0;
}
```
- Lưu ý ; hàm `getline` hay bị trôi lệnh nên ta dùng `cin.ignore()` trước khi dùng `getline`
```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    // ham cin de lai 1 phim enter trong bo dem
    // khai bao bien string 
    string s;
    // nhap : Le Anh Duc
    // dung cin.ignore(); de xoa du lieu trong bo dem
    // neu khong dung cin.ignore(); thi ham getline se khong nhap duoc du lieu do con phim enter
    // truyen vo 1 tham so, tuong duong xoa 1 ki tu
    cin.ignore(1);
    getline(cin, s);
    // Ket qua : Le Anh Duc 
    // vi ham getline nhap ca dong 
    // ham getline chi ket thuc khi gap ki tu 'Enter' (\n)
    cout << s << endl;
    return 0;
}
``` 

## 2. Mảng kí tự
- Bản chất chuỗi kí tự sẽ được lưu các phần tử như mảng 1 chiều
- Ví dụ `string s = "Hello";` sẽ được lưu như sau:

| Chỉ số (Index) | 0 | 1 | 2 | 3 | 4 |
| :---: | :---: | :---: | :---: | :---: | :---: |
| Kí tự (Value) | 'H' | 'e' | 'l' | 'l' | 'o' |

- Ta có thể truy cập từng kí tự trong chuỗi thông qua chỉ số (index) bắt đầu từ 0, tương tự như mảng 1 chiều: `s[0]` là 'H', `s[1]` là 'e', v.v.

- Muốn kiểm tra độ dài mảng ta dùng hàm `s.length()` hoặc `s.size()`
```cpp
#include <iostream>
using namespace std;

int main() {
    string s = "Hello";
    // in ra ket qua
    // In ra do dai xau s
    cout << s.length() << endl; 
    // tuong tu dung ham length
    cout << s.size() << endl; 
    // dung ham do dai de duyet xau
    for(int i = 0; i < s.length(); i++) {
        // truy cap truc tiep cac phan tu nhu mang 1 chieu
        cout << s[i] << " ";
    }
    // neu muon in theo for loop
    for(char i : s){
        cout << i << " ";
    }
    return 0;
}
``` 

- Truy cập kí tự của xâu  thông qua `index` với độ phức tạp O(1)
- Duyệt qua từng kí tự của xâu với độ phức tạp O(n)
```cpp
#include <iostream>
using namespace std;

int main() {
    string s = "Hello";
    // truy cap ki tu cua xau thong qua index
    cout << s[0] << endl; // H
    cout << s[1] << endl; // e
    cout << s[2] << endl; // l
    cout << s[3] << endl; // l
    cout << s[4] << endl; // o
    return 0;
}
```

## 3. Toán tử trong xâu 

### a. Cộng chuỗi (Nối chuỗi)
- Dùng toán tử `+` để nối chuỗi 
- Ví dụ 
```cpp
#include <iostream>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = " World";
    // noi chuoi
    string s3 = s1 + s2;
    cout << s3 << endl; // Hello World
    // cong truc tiep noi dung xau b vao xau a
    s1 += s2; 
    cout << s1 << endl; // Hello World
    return 0;
}
``` 
### b. So sánh xâu 
- Dùng các toán tử so sánh `==`, `!=`, `<`, `>`, `<=`, `>=` để so sánh xâu 
- C++ khác C ở chỗ có thể dùng toán tử để so sánh xâu, ở C không thể dùng toán tử để so sánh xâu mà phải dùng hàm `strcmp()`
- Ví dụ 
```cpp
#include <iostream>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = " Hello";
    string s3 = "Hello";
    // so sanh xau
    // so sanh theo tieu chi thu tu tu dien
    // so sanh tung ki tu mot, ki tu nao nho hon thi xau do nho hon
    if(s1 == s2) {
        cout << "Bang nhau" << endl; 
    } else {
        cout << "Khac nhau" << endl; 
    }
    return 0;
}
``` 
- Ta cũng có thể sử dụng hàm `compare()` để so sánh xâu, hàm này trả về giá trị 0 nếu 2 xâu bằng nhau, -1 nếu xâu thứ nhất nhỏ hơn xâu thứ hai, 1 nếu xâu thứ nhất lớn hơn xâu thứ hai
- Ví dụ 
```cpp
#include <iostream>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = " Hello";
    string s3 = "Hello";
    // so sanh xau
    // so sanh theo tieu chi thu tu tu dien
    // so sanh tung ki tu mot, ki tu nao nho hon thi xau do nho hon
    if(s1.compare(s2) == 0) {
        cout << "Bang nhau" << endl; 
    } else {
        cout << "Khac nhau" << endl; 
    }
    return 0;
}
``` 
- Cái này không tiện bằng dùng toán tử so sánh trực tiếp, nhưng bù lại nó có thể so sánh 2 xâu con, nếu ta muốn so sánh xâu s1 từ index i với độ dài k với xâu s2 từ index j với độ dài k

### c. Cắt xâu 
- Dùng toán tử `substr()` để cắt xâu, ta có 2 cách dùng
- Cách 1: `s.substr(pos, len)`
    - `pos`: index bắt đầu cắt
    - `len`: độ dài cắt 
- Cách 2: `s.substr(pos)`
    - `pos`: index bắt đầu cắt
    - `len`: độ dài cắt (mặc định cắt đến hết xâu)
- Ví dụ 
```cpp
#include <iostream>
using namespace std;

int main() {
    string s = "Hello";
    // cat xau
    // cat tu index 0, do dai 2
    cout << s.substr(0, 2) << endl; // He
    // cat tu index 1, do dai 3
    cout << s.substr(1, 3) << endl; // ell
    // cat tu index 2, do dai den het xau
    cout << s.substr(2) << endl; // llo
    // cat 2 xau con de so sanh
    string s1 = "Hello";
    string s2 = "Hello";
    // cat s1 tu index 0, do dai 5
    // cat s2 tu index 0, do dai 5
    if(s1.substr(0, 5) == s2.substr(0, 5)) {
        cout << "Bang nhau" << endl; 
    } else {
        cout << "Khac nhau" << endl; 
    }
    return 0;
}
``` 

### d. Chuyển đổi xâu 
#### 1. Chuyển đổi xâu thành số 
- Dùng hàm `stoi()` để chuyển xâu thành số nguyên 
- Ví dụ 
```cpp
#include <iostream>
using namespace std;

int main() {
    string s = "123";
    // chuyen xau thanh so nguyen
    // Tham so thu 2 quy dinh index bat dau chuyen, mac dinh la 0
    // Tham so thu 3 quy dinh do dai chuyen, mac dinh la het xau
    int n = stoi(s);
    cout << n << endl; // 123
    return 0;
}
``` 
- Dùng hàm `stod()` để chuyển xâu thành số thực 
- Ví dụ 
```cpp
#include <iostream>
using namespace std;

int main() {
    string s = "123.456";
    // chuyen xau thanh so thuc
    double d = stod(s);
    cout << d << endl; // 123.456
    return 0;
}
``` 
- Dùng hàm `stoll()` để chuyển xâu thành số nguyên lớn 
- Ví dụ 
```cpp
#include <iostream>
using namespace std;

int main() {
    string s = "1234567890123456789";
    // chuyen xau thanh so nguyen lon
    long long ll = stoll(s);
    cout << ll << endl; // 1234567890123456789
    return 0;
}
``` 
- Dùng hàm `stold()` để chuyển xâu thành số thực lớn 
- Ví dụ 
```cpp
#include <iostream>
using namespace std;

int main() {
    string s = "1234567890123456789.123456789";
    // chuyen xau thanh so thuc lon
    long double ld = stold(s);
    cout << ld << endl; // 1234567890123456789.123456789
    return 0;
}
``` 
#### 2. Chuyển đổi số thành xâu 
- Dùng hàm `to_string()` để chuyển số thành xâu 
- Ví dụ 
```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 123;
    // chuyen so nguyen thanh xau
    // Tham so thu 2 quy dinh index bat dau chuyen, mac dinh la 0
    // Tham so thu 3 quy dinh do dai chuyen, mac dinh la het xau
    string s = to_string(n);
    cout << s << endl; // 123
    // chuyen so thuc thanh xau
    float a = 123.456;
    string s1 = to_string(a);
    cout << s1 << endl; // 123.456000
    return 0;
}
``` 

## 4. Một số hàm thao tác cơ bản

### a. Tìm kiếm 
- Dùng hàm `find()` để tìm kiếm xâu 
- Ví dụ 
```cpp
#include <iostream>
using namespace std;

int main() {
    string s = "Hello";
    // tim kiem xau
    // Tim kiem xau "Hello" trong xau "Hello"
    // Tra ve index bat dau tim thay, neu khong tim thay tra ve -1
    cout << s.find("Hello") << endl; // 0
    // Tim kiem xau "lo" trong xau "Hello"
    cout << s.find("lo") << endl; // 3
    // Tim kiem xau "lo" trong xau "Hello" tu index 4 tro di
    cout << s.find("lo", 4) << endl; // -1
    return 0;
}
``` 

### b. Đếm 
- Dùng hàm `count()` để đếm số lần xuất hiện của một kí tự trong xâu 
- Cú pháp: `count(first, last, val)`
    - `first`: iterator bắt đầu đếm
    - `last`: iterator kết thúc đếm
    - `val`: giá trị cần đếm
    - return: số lần xuất hiện của `val` trong xâu 
- Ví dụ 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "Hello";
    // dem so lan xuat hien cua mot ki tu trong xau
    // Dem so lan xuat hien cua ki tu 'l' trong xau "Hello"
    cout << s.count('l') << endl; // 2
    // hoac dung cu phap khac 
    cout << count(s.begin(), s.end(), 'l') << endl; // 2
    // voi s.begin() la iterator bat dau
    // s.end() la iterator ket thuc 
    return 0;
}
``` 

### c. Xóa 
- Dùng hàm `erase()` để xóa một đoạn trong xâu 
- Cú pháp: `erase(pos, len)`
    - `pos`: index bắt đầu xóa
    - `len`: độ dài xóa (mặc định xóa đến hết xâu)
- Ví dụ 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "Hello";
    // xoa mot doan trong xau
    // Xoa tu index 0, do dai 2
    s.erase(0, 2);
    cout << s << endl; // llo
    return 0;
}
``` 

### d. Đảo ngược 
- Dùng hàm `reverse()` để đảo ngược xâu 
- Ví dụ 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "Hello";
    // dao nguoc xau
    reverse(s.begin(), s.end());
    cout << s << endl; // olleH
    return 0;
}
``` 
### e. Hàm `getline()`
- Dùng hàm `getline()` được dùng để áp dụng một chức năng hàm lên một đối tượng
- Cú pháp: `getline(obj, s, delim)`
    - `obj`: đối tượng áp dụng hàm
    - `s`: biến để lưu trữ 
    - `delim`: kí tự phân cách (mặc định là '\n')
- Ví dụ 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    // doc mot dong tu cin
    // ap dung ham cin la nhap vao len string s
    getline(cin, s);
    cout << s << endl; 
    return 0;
}
``` 
### f. Tách từ
- Sử dụng hàm `stringstream()` để tách từ 
- Ví dụ 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "Hello World";
    // tach tu 
    stringstream ss(s);
    // no se tach thanh hello va world
    // khoi tao bien tam
    string word;
    // ss >> word se tra ve 1 neu thanh cong, 0 neu that bai
    // khi nao ss khong con du lieu de doc thi vong lap se ket thuc
    // >> la toan tu lay du lieu tu stringstream
    while(ss >> word) {
        cout << word << endl; 
        // Output:
        // Hello 
        // World
    }
    return 0;
}
``` 
- Đối với trường hợp đặc biệt, ví dụ như ta có xâu `string s = "java.python.php.lap.trinh"` và ta muốn tách các từ trong xâu này ra, ta có thể sử dụng hàm `getline()` với tham số thứ 3 là kí tự phân cách 
- Cú pháp: `getline(ss, word, delim)`
    - `ss`: `stringstream` 
    - `word`: biến để lưu trữ 
    - `delim`: kí tự phân cách (mặc định là khoảng trắng) 
- Ví dụ 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "java.python.php.lap.trinh";
    // tach tu 
    stringstream ss(s);
    // no se tach thanh java, python, php, lap, trinh
    // khoi tao bien tam
    string word;
    // . la ki tu phan tach
    // getline(ss, word, '.') se tra ve 1 neu thanh cong, 0 neu that bai
    // khi nao ss khong con du lieu de doc thi vong lap se ket thuc
    while(getline(ss, word, '.')) {
        cout << word << endl; 
        // Output:
        // java
        // python
        // php
        // lap
        // trinh
    }
    return 0;
}
``` 
