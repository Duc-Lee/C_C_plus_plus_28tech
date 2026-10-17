# Cách Sử Dụng Hàm Sắp Xếp Trong C++ | Xây Dựng Comparator Cho Hàm Sort của STL

## 1. Hàm `sort()`

- Trong thư viện chuẩn C++ (<algorithm>), hàm std::sort() được dùng để sắp xếp các phần tử trong một phạm vi [first, last) theo một thứ tự xác định (mặc định là tăng dần).

- Thuật toán bên dưới của std::sort thường là Introsort — sự kết hợp tối ưu giữa Quicksort, Heapsort và Insertion Sort, đảm bảo hiệu năng cao và tránh trường hợp xấu nhất của Quicksort.

- Cú pháp cơ bản : 
```cpp
#include <algorithm>

// 1. Sắp xếp mặc định (tăng dần)
sort(first, last);

// 2. Sắp xếp theo điều kiện tùy biến (custom comparator)
sort(first, last, comp);
```

- Các tham số  : 
    - first, last: Các iterator hoặc con trỏ xác định phạm vi cần sắp xếp trên nửa khoảng [first, last).
    
    - comp (tùy chọn): Hàm so sánh, functor, hoặc biểu thức Lambda trả về true nếu phần tử thứ nhất phải đứng trước phần tử thứ hai

- Ví dụ 1 : 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // khoi tao mang 1 chieu 
    int arr = {2,9,1,2,6,1,4};
    // tinh chieu dai mang 
    int n = sizeoff(arr) / sizeoff(arr[0]);
    // sap xep tang dan 
    sort(arr,arr + n);
    // neu muon sap xep giam dan 
    // truyen tham so thu 3 la greater<int>()
    sort(arr,arr + n, greater<int>());
}

```

- Ví dụ 2: Sắp xếp với `vector`
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // khoi tao vector
    vector<int> v = {2,9,1,2,6,1,4};
    // sap xep tang dan
    sort(v.begin(),v.end());
    // sap xep giam dan
    sort(v.begin(),v.end(), greater<int>());
}
```

- Ví dụ 3: Sắp xếp với chuỗi con trong chuỗi
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // vi du : python c++ java sql golang
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    // in cac chuoi con ra 
    for(string x : s){
        cout << x << " ";
    }
    // ket qua : c++ golang java python sql 
    // no sap xep theo thu tu tu a-z tang dan 
    sort(s.begin(),s.end(),greater<string>());
    for(string x : s){
        cout << x << " ";
    }
    // ket qua : sql python java golang c++ 
    // no sap xep theo thu tu tu z-a giam dan 
}
```

- Ví dụ 4: Sắp xếp kí tư trong chuỗi
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // cho chuoi : ạgshgqowk
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    // in cac chuoi con ra 
    cout << s << endl;
    // ket qua : agghjknoqqsw
    sort(s.begin(),s.end(),greater<string>());
    cout << s << endl;
    // ket qua : wsqqonkjhgga
}
```

- Ví dụ 5: Sắp xếp các `pair`
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // khoi tao vector cac cap
    vector<pair<int,int>> v = {{2,3},{1,2},{3,4}};
    // sap xep tang dan 
    sort(v.begin(),v.end());
    // in ra cac cap 
    for(pair<int,int> x : v){
        cout << x.first << " " << x.second << endl;
    }
    // ket qua : 
    // 1 2
    // 2 3
    // 3 4
    // no sap xep theo cap gia tri thu nhat tang dan
    // neu cap gia tri thu nhat bang nhau 
    // thi no sap xep cap gia tri thu hai tang dan
    // 
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    // in ra cac cap 
    for(pair<int,int> x : v){
        cout << x.first << " " << x.second << endl;
    }
    // ket qua : 
    // 3 4
    // 2 3
    // 1 2
    // no sap xep theo cap gia tri thu nhat giam dan
    // neu cap gia tri thu nhat bang nhau
    // thi no sap xep cap gia tri thu hai giam dan
}
```

- Ví dụ 6 : Xây dựng hàm truyền vào hàm sort để sắp xếp
```cpp
#include <bits/stdc++.h>
using namespace std;

// xay dung ham de sap xep theo thu tu giam dan
int cmp(int a, int b){
    // ham sort se lay phan tu a[i] va a[i+1]
    // neu tra ve true thi a[i] dung truoc a[i+1]
    // neu tra ve false thi a[i+1] dung truoc a[i]
    // vay neu a > b thi tra ve true thi a[i] dung truoc a[i+1] va nguoc lai 
    // vay ham nay se sap xep theo thu tu giam dan 
    return a > b;
}

// xay dung ham binh phuong
int power(int a, int b){
    return a*a < b*b;
}

// xay dung ham sap xep theo gia tri tuyet doi
int abs_val(int a, int b){
    // neu gia tri tuyet doi cua a nho hon gia tri tuyet doi cua b thi a dung truoc b
    return abs(a) < abs(b);
}

int main() {
    vector<int> v = {2,3,1,2,6,1,4};
    // truyen tham so thu 3 la ham de sap xep
    // no se sap xep theo thu tu giam dan
    sort(v.begin(),v.end(),cmp);
    for(int x : v){
        cout << x << " ";
    }
    // ket qua : 
    // 6 4 3 2 2 1 1 
    // no sap xep theo thu tu giam dan
    sort(v.begin(),v.end(),power);
    for(int x : v){
        cout << x << " ";
    }
    // ket qua : 
    // 1 1 2 2 3 4 6
    // no sap xep theo thu tu binh phuong 
    // nhung ham sort() khong dam bao tinh on dinh 
    // vi vay neu can dam bao tinh on dinh thi dung stable_sort()
    sort(v.begin(),v.end(),abs_val);
    for(int x : v){
        cout << x << " ";
    }
    // ket qua : 
    // 1 1 2 2 3 4 6 
    // no sap xep theo thu tu gia tri tuyet doi 
    // nhung ham sort() khong dam bao tinh on dinh 
    // no co the swap vi tri cua cac phan tu bang nhau
}
```

- Ví dụ 7 : Sắp xếp nhiều tiêu chí với ví dụ sắp xếp các từ theo chiều dài, nếu các từ bằng nhau thì sắp xếp theo vần abc
    - Input : 
    ```
    5
    python java php c sql
    ```
    - Output : 
    ```
    c sql php java python
    ```
    - Code : 

```cpp
#include <bits/stdc++.h>
using namespace std;

int cmp(string a, string b){
    // neu chieu dai khac nhau 
    // sap xep theo ai lon hon 
    if(a.length() != b.length()){
        return a.length() > b.length();
    }
    // neu chieu dai bang nhau 
    // sap xep theo ai nho hon 
    return a < b;
}
int main(){
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    // in ra cac chuoi con ra 
    cout << s << endl;
    // ket qua : agghjknoqqsw
}
```

## 2. Hàm `stable_sort`

- Hàm `std::stable_sort()` trong thư viện chuẩn C++ (<algorithm>) dùng để sắp xếp các phần tử trong phạm vi [first, last) theo một thứ tự xác định, với đặc tính cốt lõi là đảm bảo tính ổn định (stable).

- Tác dụng chính
    - Sắp xếp dữ liệu: Đưa mảng hoặc container về thứ tự tăng dần (mặc định) hoặc theo điều kiện tự định nghĩa (custom comparator).
    
    - Bảo toàn thứ tự gốc: Nếu hai phần tử có giá trị hoặc khóa so sánh bằng nhau, `stable_sort()` đảm bảo phần tử nào đứng trước ở danh sách ban đầu thì vẫn sẽ đứng trước sau khi sắp xếp.
    
- Cú pháp cơ bản : 
```cpp
#include <algorithm>

// 1. Sắp xếp ổn định tăng dần
stablesort(first, last);

// 2. Sắp xếp ổn định theo điều kiện tùy biến (custom comparator)
stablesort(first, last, comp);
```

- Các tham số  : 
    - first, last: Các iterator hoặc con trỏ xác định phạm vi cần sắp xếp trên nửa khoảng [first, last).
    
    - comp (tùy chọn): Hàm so sánh, functor, hoặc biểu thức Lambda trả về true nếu phần tử thứ nhất phải đứng trước phần tử thứ hai
    
- Khi nào nên dùng stable_sort()?
    - Sắp xếp theo nhiều tiêu chí độc lập (Multi-level sort): Ví dụ ban đầu đã sắp xếp danh sách theo Tên, sau đó muốn gom nhóm theo Điểm. Dùng `stable_sort()` theo Điểm sẽ giúp những người cùng điểm vẫn giữ nguyên thứ tự tên theo bảng chữ cái.
    
    - Cần bảo toàn logic nghiệp vụ: Khi thứ tự nhập vào ban đầu (thời gian nộp bài, thời gian gửi đơn, số thứ tự) có ý nghĩa ưu tiên đối với các trường hợp bằng điểm/bằng hạng.

- Ví dụ : Sắp xếp các phần tử trong mảng theo thứ tự tăng dần theo giá trị tuyệt đối
    - Input : 
    ```
    8 
    1 -1 2 1 5 -2 -5 9
    ```

    - Output : 
    ```
    1 -1 1 2 -2 5 -5 9 
    ```
    
    - Code : 

```cpp
#include <bits/stdc++.h>
using namespace std;

// Hàm so sánh tùy biến: so sánh theo giá trị tuyệt đối
bool compareAbs(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    // sap xep tang dan theo gia tri tuyet doi va bao toan thu tu ban dau
    stable_sort(arr, arr + n, compareAbs);
    // in ra mang da sap xep 
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    // ket qua : 1 -1 1 2 -2 5 -5 9 
    // nhu da thay cac so co gia tri tuyet doi bang nhau
    // van giu nguyen thu tu ban dau
    cout << endl;
    return 0;
}
```

- Ví dụ 2 : Minh họa trực quan sự khác biệt giữa `sort` và `stable_sort`

    * **Bối cảnh bài toán:**
      * Ta quản lý danh sách $20$ thí sinh nộp bài thi dưới dạng `pair<int, int>`:
        * `first`: Thứ tự nộp bài của thí sinh (từ $0$ đến $19$).
        * `second`: Điểm thi (giả sử cả $20$ thí sinh đều đạt cùng một mức điểm là $5$).
      * **Yêu cầu:** Sắp xếp danh sách theo điểm thi tăng dần (chỉ so sánh `second`, bỏ qua `first`).
      * **Mục đích:** Khi điểm thi bằng nhau, ta kiểm tra xem **thứ tự nộp bài ban đầu (`first`)** có được giữ nguyên không.

    * **Code minh họa:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm so sánh chỉ dựa trên điểm số (second)
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    // neu phan tu thu 2 cua a nho hon phan tu thu 2 cua b thi tra ve true
    // neu phan tu thu 2 cua a lon hon phan tu thu 2 cua b thi tra ve false
    return a.second < b.second;
}

int main() {
    int n = 20;
    // Khởi tạo 2 danh sách giống hệt nhau
    // first = Thứ tự nộp bài (0 -> 19), second = Điểm số (đều là 5)
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = {i, 5}; 
    }
    b = a;

    // Sắp xếp ổn định
    stable_sort(a.begin(), a.end(), cmp);

    // Sắp xếp thông thường
    sort(b.begin(), b.end(), cmp);

    cout << "--- stable_sort (Bảo toàn thứ tự ban đầu) ---\n";
    for (auto &p : a) cout << p.first << " ";
    cout << "\n\n";

    cout << "--- sort thường (Không bảo toàn thứ tự ban đầu) ---\n";
    for (auto &p : b) cout << p.first << " ";
    cout << "\n";

    return 0;
}
```

* **Kết quả khi chạy chương trình:**
```text
--- stable_sort (Bảo toàn thứ tự ban đầu) ---
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 

--- sort thường (Không bảo toàn thứ tự ban đầu) ---
10 19 18 17 16 15 14 13 12 11 0 9 8 7 6 5 4 3 2 1 
```

* **Nhận xét & Kết luận:**
* **`stable_sort`:** Các thí sinh cùng được $5$ điểm vẫn giữ **chính xác $100\%$ thứ tự nộp bài từ $0 \rightarrow 19$**.
* **`sort` thông thường:** Thuật toán (Introsort/Quicksort) trong quá trình phân hoạch đã hoán đổi vị trí của các phần tử bằng nhau, làm thứ tự ban đầu bị **đảo lộn lung tung** (thí sinh nộp bài thứ $10, 19, 18\dots$ bị nhảy lên trước).