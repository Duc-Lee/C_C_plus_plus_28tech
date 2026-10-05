# Cấu Trúc Dữ Liệu Set Trong C++

## 1. Khái niệm 
- `set` là một cấu trúc dữ liệu lưu trữ các phần tử **duy nhất** (không chứa các phần tử trùng lặp) và các phần tử này luôn được **tự động sắp xếp** (mặc định là tăng dần).
- `set` được định nghĩa trong thư viện `<set>`.

## 2. Khai báo 
- Để khai báo cấu trúc dữ liệu `set` trong C++, ta sử dụng cú pháp sau:
```cpp
#include <set>

set<dataType> setName;
```
- Ví dụ : 
```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){
    // khai bao set
    set <int> s;
    // cung co the khai bao kieu gan gia tri 
    // dung ngoac nhon 
    set <int> s1 = {1,2,3,4,5};
    // ví dụ ta co mang 
    int a[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10}; 
    // ta cho cac phan tu cua mang vao set 
    for(int x : a){
        // them cac phan tu mang a vo set
        s.insert(x);
    }
    for(int i : s){
        cout << i << " ";
    }
    // output : 1 2 3 4 5 6 7 8 9 10 
    // Nhu ban thay: 
    // 1. set da loc cac phan tu trung nhau.
    // 2. set tu dong sap xep cac phan tu theo thu tu tang dan.
    // Khong giong nhu unordered_set, set LUON duy tri thu tu nay moi khi ban duyet qua no. 
    return 0; 
}
```

- Do cơ chế không trùng các phần tử nên ta có ví dụ nhập biến đầu vào
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // khai bao set
    set <int> s;
    int n; 
    cin >> n; 
    // nhap n phan tu vao set 
    // nhap n = 10
    // nhap 1 1 2 2 3 3 4 4 5 5
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    // sau khi nhap xong n phan tu 
    // output : 1 2 3 4 5
    // in ra cac phan tu trong set 
    for(int i : s){
        cout << i << " ";
    }
    // output : 1 2 3 4 5
    return 0; 
}
```

- Sử dụng string trong `set`
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // khaii bao set co kieu string cac phan tu trong set la string
    set <string> s;
    int n;
    cin >> n;
    cin.ignore();
    // nhap n phan tu vao set
    // nhap n = 5 
    // nhap "a b"
    // nhap "c d"
    // nhap "a b" 
    for(int i = 0; i < n; i++){
        string x;
        // khi nhap chuoi nhan khoang trang ta dung getline de nhap
        // neu chi dung cin thi khong the nhap chuoi co khoang trang
        getline(cin, x);
        s.insert(x);
    }
    for(string i : s){
        cout << i << " ";
    }
    // output : a b c d
    return 0;
}
```

## 3. Các thao tác cơ bản 
- Đa số các hàm thao tác của `set` đều có độ phức tạp $O(log n)$ 
- Các thao tác cơ bản của `set` bao gồm:

### Hàm `begin()` và `end()`
- **`begin()`**: Trả về một *iterator* trỏ đến phần tử **đầu tiên** (có giá trị nhỏ nhất) trong `set`.
- **`end()`**: Trả về một *iterator* trỏ đến vị trí ngay **sau** phần tử cuối cùng trong `set`. Lưu ý: vị trí này là một vị trí "ảo", không chứa dữ liệu thực sự của `set`.
- Hai hàm này thường được kết hợp với vòng lặp `for` hoặc `while` để duyệt qua toàn bộ các phần tử của `set` theo chiều thuận (tăng dần).

*(Lưu ý: Tương tự, ta có **`rbegin()`** trỏ đến phần tử cuối cùng và **`rend()`** trỏ đến vị trí trước phần tử đầu tiên, dùng để duyệt `set` theo chiều ngược).*

**Iterator là gì ?**
- Iterator (bộ lặp) trong C++ là một đối tượng hoạt động giống như con trỏ, được dùng để duyệt qua các phần tử của một container (như `vector`, `list`, `map`, `set`, v.v.) hoặc một dãy dữ liệu. Thay vì dùng địa chỉ bộ nhớ như con trỏ thông thường, iterator cung cấp một giao diện chuẩn (API) để truy cập và di chuyển qua các phần tử.

**Đặc điểm chính của Iterator:**
- **Hằng số (Constants)**: Iterator trong `set` là hằng số. Điều này có nghĩa là bạn **không thể thay đổi giá trị** của phần tử thông qua iterator. Nếu muốn thay đổi giá trị, bạn phải xóa phần tử cũ và chèn lại phần tử mới.
- **So sánh**: Bạn có thể so sánh hai iterator bằng các toán tử: `==`, `!=`, `<` ,`>` ,`<=`, `>=`.
- **Tính đa hình**: Cùng một đoạn mã duyệt, bạn có thể áp dụng cho nhiều loại container khác nhau chỉ bằng cách thay đổi kiểu dữ liệu của iterator.

```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    // Khoi tao set
    set<int> s = {5, 2, 4, 1, 3}; 
    
    // Su dung begin() va end() de duyet set
    cout << "Duyet xuoi (tang dan): ";
    for(auto it = s.begin(); it != s.end(); ++it){ 
        cout << *it << " "; 
    } 
    cout << endl; // output: 1 2 3 4 5 
    
    // Su dung rbegin() va rend() de duyet nguoc set
    cout << "Duyet nguoc (giam dan): ";
    for(auto it = s.rbegin(); it != s.rend(); ++it){ 
        cout << *it << " "; 
    } 
    cout << endl; // output: 5 4 3 2 1 

    // bien auto chi la bien suy luan kieu du lieu thoi 
    // duoc ap dung cho loop 
    // neu khong dung auto 
    // phai khai bao ca cum lon nhu v 
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    // output : 1 2 3 4 5
    return 0; 
} 
```

### Hàm `insert()`
- Hàm `insert()` được sử dụng để thêm các phần tử vào `set`.

```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){
    // khai bao set 
    set <int> s; 
    // them cac phan tu vao set 
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    // duyet qua set
    for(int i : s){
        cout << i << " ";
    }
    // output : 1 2 3 4 5 
    return 0; 
}
```
### Hàm `size()`
- Hàm `size()` được sử dụng để lấy kích thước của `set`.

```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    set<int> s; 
    // them cac phan tu vao set 
    s.insert(1); 
    s.insert(2); 
    s.insert(3); 
    s.insert(4); 
    s.insert(5); 
    // lay kich thuoc cua set 
    cout << s.size() << endl; 
    // output : 5 
    return 0; 
} 
```

### Hàm `find()`
- Hàm `find()` được sử dụng để tìm kiếm các phần tử trong `set`.
- Hàm `find()` trả về iterator đến phần tử được tìm thấy, hoặc iterator đến `s.end()` nếu không tìm thấy.

```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    set<int> s; 
    // them cac phan tu vao set 
    s.insert(1); 
    s.insert(2); 
    s.insert(3); 
    s.insert(4); 
    s.insert(5); 
    // tim phan tu trong set 
    auto it = s.find(3); 
    // s.end() tra ve iterator den phan tu sau phan tu cuoi cung trong set 
    // s.end() o day dang la bien luu tru dia chi cua phan tu sau phan tu cuoi cung trong set 
    // neu it khac s.end() nghia la phan tu duoc tim thay 
    if(it != s.end()){ 
        // neu tim thay thi in ra gia tri cua o nho day ra 
        // do ham find() tim kiem tren con tro
        cout << "Phan tu duoc tim thay: " << *it << endl; 
    }else{ 
        cout << "Phan tu khong duoc tim thay" << endl; 
    } 
    // output : Phan tu duoc tim thay: 3 
    return 0; 
} 
```
### Hàm `count()`
- Hàm `count()` được sử dụng để đếm số lần xuất hiện của một phần tử trong `set`. 
- Hàm `count()` trả về 1 nếu phần tử được tìm thấy, hoặc 0 nếu không tìm thấy. 

```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    set<int> s; 
    // them cac phan tu vao set 
    s.insert(1); 
    s.insert(2); 
    s.insert(3); 
    s.insert(4); 
    s.insert(5); 
    // co the dung count de tim kiem trong set
    if(s.count(3) != 0){ 
        cout << "Phan tu duoc tim thay" << endl; 
    }else{ 
        cout << "Phan tu khong duoc tim thay" << endl; 
    } 
    // output : Phan tu duoc tim thay 
    return 0; 
} 
```

### Hàm `erase()`
- Hàm `erase()` được sử dụng để xóa các phần tử khỏi `set`.

```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    set<int> s; 
    // them cac phan tu vao set 
    s.insert(1); 
    s.insert(2); 
    s.insert(3); 
    s.insert(4); 
    s.insert(5); 
    // xoa phan tu trong set 
    s.erase(3); 
    // duyet qua set 
    for(int i : s){ 
        cout << i << " "; 
    } 
    // output : 1 2 4 5 
    return 0; 
} 
```

### Hàm `empty()`
- Hàm `empty()` được sử dụng để kiểm tra xem `set` có rỗng hay không.

```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    set<int> s; 
    // them cac phan tu vao set 
    s.insert(1); 
    s.insert(2); 
    s.insert(3); 
    s.insert(4); 
    s.insert(5); 
    // kiem tra xem set co rong hay khong 
    if(s.empty()){ 
        cout << "Set rong" << endl; 
    }else{ 
        cout << "Set khong rong" << endl; 
    } 
    // output : Set khong rong 
    return 0; 
} 
```

### Hàm `clear()`
- Hàm `clear()` được sử dụng để xóa tất cả các phần tử trong `set`.

```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    set<int> s; 
    // them cac phan tu vao set 
    s.insert(1); 
    s.insert(2); 
    s.insert(3); 
    s.insert(4); 
    s.insert(5); 
    // xoa tat ca cac phan tu trong set 
    s.clear(); 
    // duyet qua set 
    for(int i : s){ 
        cout << i << " "; 
    } 
    // output : 
    return 0; 
} 
```

## 4. Multiset và bài toán Maximum sliding window 
- Cú pháp 
```cpp
// cho phep cac phan tu trung nhau 
// va van duoc sap xep tu nho den lon 
multiset <int> ms;
```

- Ví dụ 
```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    multiset<int> ms; 
    // them cac phan tu vao multiset 
    ms.insert(1); 
    ms.insert(2); 
    ms.insert(2); 
    ms.insert(4); 
    ms.insert(5); 
    // duyet qua multiset 
    for(int i : ms){ 
        cout << i << " "; 
    } 
    // output : 1 2 2 4 5 
    return 0; 
} 
```

- `multiset` co cac ham giong nhu `set`, multiset được dùng để muốn tìm kiếm phần tử lớn nhất, nhỏ nhất, phần tử, muốn xoá một cách nhanh chóng

- Lưu ý : `multiset` không thể sử dụng hàm `erase()` do nó sẽ xoá hết tất cả phần tử 
```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    multiset<int> ms; 
    // them cac phan tu vao multiset 
    ms.insert(1); 
    ms.insert(2); 
    ms.insert(2); 
    ms.insert(4); 
    ms.insert(5); 
    // xoa phan tu trong multiset 
    // ma ta chi muon xoa 1 phan tu 
    // thi ta phai su dung ham erase voi tham so la iterator 
    ms.erase(ms.find(2));
    // duyet qua multiset 
    for(int i : ms){ 
        cout << i << " "; 
    } 
    // output : 1 2 4 5 
    return 0; 
} 
```

- Ví dụ : Cho mảnng có n phần tử và số nguyên k, với mỗi cửa sổ của chiều dài k, tìm giá trị lớn nhất 

testcase 
10 3
1 2 3 1 4 5 1 8 9 10 

output :
3 3 4 5 5 8 9 

```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    int n, k; 
    cin >> n >> k; 
    int a[n];
    for(int &i: a){ 
        cin >> i; 
    } 
    // khoi tao multiset cho k phan tu 
    multiset<int> ms; 
    for(int i = 0; i < k; i++){ 
        ms.insert(a[i]); 
    } 
    for(int i = k; i < n; i++){ 
        // in ra phan tu lon nhat trong multiset
        // neu khong rbegin thi dung end()
        cout << *ms.rbegin() << " "; 
        // xoa phan tu nho nhat ra khoi multiset
        // do ta da duyet qua no roi 
        ms.erase(ms.find(a[i - k])); 
        // them phan tu moi vao multiset
        ms.insert(a[i]); 
    } 
    // in ra phan tu lon nhat trong multiset
    // vi khi ket thuc vong lap thi no chi in ra n-1 lan 
    // in them lan cuoi cung 
    cout << *ms.rbegin() << endl; 
    return 0; 
} 
```

## 5. Unordered multiset
- Cú pháp 
```cpp
// cho phep cac phan tu trung nhau 
// nhung khong duoc sap xep tu nho den lon 
unordered_multiset <int> ums;

```

- Ví dụ : 
```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    unordered_multiset<int> ums; 
    // them cac phan tu vao unordered_multiset 
    ums.insert(1); 
    ums.insert(2); 
    ums.insert(2); 
    ums.insert(4); 
    ums.insert(5); 
    // duyet qua unordered_multiset 
    for(int i : ums){ 
        cout << i << " "; 
    } 
    // output : 1 2 2 4 5 
    // in lai lan 2
    for(int i : ums){ 
        cout << i << " "; 
    } 
    // output : co the thay doi thu tu tuy y 
    // tuy nhien khi them vao thi no se luon luon sap xep theo thu tu tang dan 
    return 0; 
} 
```

- Các hàm của `unordered_multiset` cũng giống như `set` và `multiset`, tuy nhiên nó không được sắp xếp và độ phức tạp là O(1) đến O(n) tuỳ thuộc vào hàm băm 