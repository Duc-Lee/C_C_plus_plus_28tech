# Cấu Trúc Dữ Liệu Map Trong C++

## 1. Khái niệm cơ bản
Map là một tập hợp các cặp có thứ tự (ordered pairs), mỗi cặp chứa một **key** (khóa) và một **value** (giá trị). Trong một map, tất cả các keys đều yêu cầu phải là **duy nhất**, nhưng các values thì có thể lặp lại (trùng nhau).

Maps có 3 chức năng chính:
- Thêm một cặp key-value.
- Lấy ra giá trị (value) ứng với một khóa (key) cho trước.
- Xóa một cặp key-value khỏi map.

Độ phức tạp của các thao tác thêm (Insertions), xóa (deletions), và tìm kiếm (searches) đều là $\mathcal{O}(\log N)$, trong đó $N$ là số lượng phần tử trong map.

Khai báo 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    //khai bao map 
    // map<kieu du lieu key, kieu du lieu value> ten_map;
    // khai bao map 
    map<int, string> m;
    // khai bao map voi du lieu ban dau 
    map<int, string> m = {{1, "a"}, {2, "b"}, {3, "c"}}; 
    return 0; 
}

```

## 2. Các thao tác trong C++
Giả sử ta có một biến map trong C++ `map m`:

- Toán tử `m[key] = value` gán một giá trị cho một khóa và đưa cặp key-value này vào trong map. Toán tử `m[key]` sẽ trả về giá trị liên kết với khóa đó. **Nếu khóa không có sẵn trong map, thì `m[key]` sẽ được gán giá trị mặc định là 0** (đối với kiểu số).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // khai bao map bang toan tu 
    map<int,string> mp;
    mp[1] = "meo meo"
    mp[2] = "ha ha"
    // in ra cac phan tu trong map 
    // do map luon duoc sap xep theo thu tu tang dan 
    // nen khi in ra cac phan tu 
    // thi key se duoc sap xep theo thu tu tang dan 
    // con value thi khong duoc sap xep 
    // duyet qua map 
    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }
    // output : 1 meo meo 
    //          2 ha ha
    // su dung begin va end   
    // begin tra ve iterator tro den phan tu dau tien 
    // end tra ve iterator tro den vi tri ngay sau phan tu cuoi cung
    // map cung giong nhu set  
}
```

- Phương thức `m.insert({key, value})` : Dùng để chèn thêm một cặp key-value vào map.
    *   **Lưu ý quan trọng**: Khác với toán tử `[]`, nếu `key` đã tồn tại trong map, phương thức `insert` sẽ **không** ghi đè giá trị mới lên giá trị cũ (nó sẽ bỏ qua lệnh chèn).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, string> mp;
    mp.insert({1, "apple"});
    mp.insert({2, "banana"});
    // Thử chèn lại key 1 với value khác bằng insert
    mp.insert({1, "orange"}); // Thao tác này bị bỏ qua vì key 1 đã tồn tại
    // Ghi đè bằng toán tử []
    mp[2] = "mango"; // Value của key 2 được cập nhật thành "mango"
    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }
    // Output:
    // 1 apple
    // 2 mango
    
    return 0;
}
```

- Phương thức `m.count(key)` : Đếm số lần xuất hiện của `key` trong `map`. Vì `key` trong `map` luôn là duy nhất, nên phương thức này chỉ trả về 1 nếu `key` tồn tại và 0 nếu không tồn tại.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, string> mp;
    mp.insert({1, "apple"});
    mp.insert({2, "banana"});
    // Kiem tra key ton tai
    if(mp.count(1)){
        cout << "Key 1 ton tai trong map" << endl; // Sẽ in ra
    }
    
    // Su dung cho if
    int searchKey = 2;
    if(mp.count(searchKey)){
        cout << "Tim thay key " << searchKey << " voi value: " << mp[searchKey] << endl;
    }
    return 0;
}
```

- Phương thức `m.size()` : Lấy kích thước của map.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, string> mp;
    mp.insert({1, "apple"});
    mp.insert({2, "banana"});
    mp.insert({3, "cherry"});
    cout << "Kich thuoc cua map: " << mp.size() << endl; // Output: 3
    // gan lai phan tu 
    mp[1] = "orange";
    cout << "Kich thuoc cua map: " << mp.size() << endl;
    // nhu v kich thuoc cua map van la 3 chu khong phai 4 
    // boi vi khong the update lai phan tu trong map 
    // ban than map luu cac pair
    // cap key value cung giong nhu vector cap key value chi la no duoc sap xep 
    for(pair <int, string> it : mp){
        cout << it.first << " " << it.second << endl;
    }
    // hoac co the dung auto cho tien 
    for(auto it : mp){
        // first la in ra key  
        // second la in ra value 
        cout << it.first << " " << it.second << endl;
    }
    // map cung co begin va end
    for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
        // luu y phai dung * de truy cap vao phan tu 
        // boi vi iterator tro den phan tu trong map 
        // dung v de truy xuat den pair
        // trong pair first la key, second la value
        cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}

- map hỗ  trợ tìm kiếm bằng hàm `find()`, độ phức tạp là $O(log n)$. Hàm `find()` nếu tìm thấy sẽ trả về iterator trỏ đến key đó, ngược lại thì trả về `end()`.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> mp;
    mp.insert({1, 10});
    mp.insert({2, 20});
    mp.insert({3, 30});
    // tim kiem key 2
    // neu find() khong tim thay key thi no se tra ve end()
    if(mp.find(2) != mp.end()){
        cout << "Key 2 ton tai trong map" << endl;
    }
    return 0;
}
```

- Muốn xóa một key trong map ta có thể dùng `erase()`, độ phức tạp là $O(log n)$, hàm `erase()` sẽ xóa key và value tương ứng ra khỏi map.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> mp;
    mp.insert({1, 10});
    mp.insert({2, 20});
    mp.insert({3, 30});
    // xoa key 2
    mp.erase(2);
    // duyet qua map
    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }
    // output : 1 10
    //          3 30
    return 0;
}
```

## 3. Các phương pháp hay sử dụng `map()`

### a. Đếm số lần xuất hiện của phần tử trong mảng, sau đó in ra kèm tần suất của nó
- Ví dụ  : 

Input :
``` 
8 
1 1 2 1 3 5 1 4 
```

Output : 
```
1 4 
2 1 
3 1 
4 1 
5 1
```
- Code : 

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    // khai bao map tan suat 
    map<int, int> freq;
    // khai bao bao mang 
    int a[n];
    // nhap cac phan tu cho mang 
    for(int i = 0;i<n;i++){
        cin >> a[i];
        // nhap mang tan suat xuat hien 
        freq[a[i]]++;
    }
    // in theo cap key value
    // moi cai chi in 1 lan 
    for(auto i : freq) {
        cout << i.first << " " << i.second << endl;
    }
    /*
    // in theo mang 
    for(int i = 0;i<n;i++){
        if( freq[a[i]] > 0){
            cout << a[i] << " " << freq[a[i]] << endl;
            // gan lai 0 de khong phai in lai
            freq[a[i]] = 0;
        }   
    }
    */
}
```

### b. Đếm xem từ nào xuất hiện nhiều nhất trong xâu kí tự 
- ví dụ 

Input 
```
9 

python java python c++ java python sql
```

Output 
```
python 3
java 2
sql 1
 c++ 1
```
- code 
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    // khai bao map tan suat
    // key dang string value dang int 
    map<string,int> freq;
    // duyet qua chuoi 
    for(int i = 0; i<n;i++){
        string s;
        cin >> s;
        freq[s]++;
    }
    // in ra cac cap key value  
    // duyet qua map theo thu tu tang dan cua key 
    for(auto it : freq){
        cout << it.first << " " << it.second << endl;
    }
    // tim chuoi xuat hien nhieu nhat 
    // khai bao tan suat xuat hien nhieu nhat 
    int max_freq = 0;
    // khai bao chuoi xuat hien nhieu nhat 
    string res;
    // duyet qua map
    for(auto it : freq){
        // neu tan suat xuat hien cua chuoi hien tai lon hon tan suat xuat hien cua chuoi lon nhat 
        if(it.second > max_freq){
            // gan lai tan suat xuat hien nhieu nhat 
            max_freq = it.second;
            // gan lai chuoi xuat hien nhieu nhat 
            res = it.first;
        }
    }
    // in ra chuoi xuat hien nhieu nhat 
    cout << res << " " << max_freq << endl;
    return 0; 
}
```

- Thêm yêu cầu nếu có nhiều từ xuất hiện cùng tần suất thì in ra từ nào xuất hiện có từ điển nhỏ hơn 

Input :
```
9 

java python python c++ java python sql java sql
```

Output:
```
python 3 
```

- Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    // khai bao map tan suat
    // key dang string value dang int 
    map<string,int> freq;
    // duyet qua chuoi 
    for(int i = 0; i<n;i++){
        string s;
        cin >> s;
        freq[s]++;
    }
    int freq_max = 0;
    string res;
    for(auto i : freq){
        // su dung >= de khi gap so lon hon hoac bang thi update lai
        // neu gap so bang nhau thi map tu dong duyet theo thu tu tu dien 
        if(i.second >= freq_max){
            freq_max = i.second;
            res = i.first;
        }
    }
    cout << res << " " << freq_max << endl;
    return 0; 
}
```

## 4. Multimap

### a. Khái niệm cơ bản
- `multimap` trong C++ tương tự như `map`, nhưng cho phép lưu trữ **nhiều cặp key-value có cùng một key** (các key có thể trùng nhau).
- Các cặp phần tử trong `multimap` vẫn được **tự động sắp xếp tăng dần theo key**.
- Độ phức tạp của các thao tác thêm (`insert`), xóa (`erase`), tìm kiếm (`find`) đều là $\mathcal{O}(\log N)$.
- Thư viện: `#include <map>` (hoặc `#include <bits/stdc++.h>`).

**Cú pháp khai báo:**
```cpp
// multimap<kieu_du_lieu_key, kieu_du_lieu_value> ten_multimap;
multimap<int, string> mm;
```

> [!WARNING]
> **Lưu ý cực kỳ quan trọng**: `multimap` **KHÔNG** hỗ trợ toán tử `[]` (subscript operator) như `mp[key] = value`. Lý do là vì một key có thể có nhiều value khác nhau nên trình biên dịch không thể xác định được cần truy cập hay gán vào value nào. Vì vậy, ta bắt buộc phải sử dụng phương thức `insert()` để thêm phần tử vào `multimap`.

### b. Các thao tác cơ bản trong `multimap`

#### 1. Thao tác `insert()` và duyệt `multimap`
- Thêm cặp phần tử vào `multimap` bằng cách truyền vào một `pair`: `{key, value}` hoặc `make_pair(key, value)`.
- Các cặp có cùng key vẫn được thêm vào bình thường và nằm cạnh nhau theo thứ tự sắp xếp của key.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // Khai bao multimap
    multimap<int, string> mm;

    // Chen cac cap key - value
    mm.insert({1, "apple"});
    mm.insert({2, "banana"});
    mm.insert({1, "avocado"}); // Key 1 xuat hien lan 2
    mm.insert({3, "cherry"});
    mm.insert({1, "apricot"}); // Key 1 xuat hien lan 3

    // Duyet va in cac phan tu trong multimap
    // Cac phan tu se duoc sap xep tang dan theo key
    for(auto it : mm){
        cout << it.first << " " << it.second << endl;
    }
    // Output:
    // 1 apple
    // 1 avocado
    // 1 apricot
    // 2 banana
    // 3 cherry
    return 0;
}
```

#### 2. Thao tác `count()` và `size()`
- `mm.size()`: Trả về tổng số phần tử (cặp key-value) trong `multimap`.
- `mm.count(key)`: Trả về số lượng phần tử có khóa trùng với `key` (khác với `map` chỉ trả về 0 hoặc 1).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    multimap<int, int> mm;
    mm.insert({1, 10});
    mm.insert({1, 20});
    mm.insert({1, 30});
    mm.insert({2, 50});
    cout << "Kich thuoc cua multimap: " << mm.size() << endl; // Output: 4
    cout << "So phan tu co key = 1: " << mm.count(1) << endl;  // Output: 3
    cout << "So phan tu co key = 2: " << mm.count(2) << endl;  // Output: 1
    cout << "So phan tu co key = 5: " << mm.count(5) << endl;  // Output: 0
    return 0;
}
```

#### 3. Thao tác `find()`
- `mm.find(key)`: Tìm kiếm `key` trong `multimap`.
- Nếu tìm thấy, `find()` sẽ trả về iterator trỏ đến **vị trí phần tử đầu tiên** có khóa bằng `key`.
- Nếu không tìm thấy, trả về `mm.end()`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    multimap<int, string> mm;
    mm.insert({1, "C++"});
    mm.insert({2, "Java"});
    mm.insert({2, "Python"});
    auto it = mm.find(2);
    if(it != mm.end()){
        // it tro den phan tu dau tien co key = 2
        cout << "Tim thay: " << it->first << " - " << it->second << endl;
        // Output: Tim thay: 2 - Java
    } else {
        cout << "Khong tim thay" << endl;
    }
    // find(2) chi tim thay phan tu dau tien co key = 2 
    // con neu muon tim tat ca cac phan tu co key = 2 thi phai dung equal_range()
    return 0;
}
```

#### 4. Thao tác `erase()`
Tương tự như `multiset`, cần hết sức lưu ý khi sử dụng hàm `erase()` trong `multimap`:
- **`mm.erase(key)`**: Xóa **TẤT CẢ** các cặp phần tử có khóa bằng `key`.
- **`mm.erase(iterator)`**: Chỉ xóa **MỘT phần tử duy nhất** mà iterator đang trỏ tới.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    multimap<int, string> mm;
    mm.insert({1, "apple"});
    mm.insert({1, "avocado"});
    mm.insert({1, "apricot"});
    mm.insert({2, "banana"});
    // Cach 1: Xoa tat ca phan tu co key = 1
    // mm.erase(1); // Se xoa sach ca 3 phan tu co key = 1
    // Cach 2: Chi muon xoa 1 phan tu dau tien co key = 1
    auto it = mm.find(1);
    if(it != mm.end()){
        mm.erase(it); // Chi xoa phan tu dau tien {1, "apple"}
    }
    // In lai multimap
    // no chi xoa 1 phan tu cap key value dau tien
    for(auto p : mm){
        cout << p.first << " " << p.second << endl;
    }
    // Output:
    // 1 avocado
    // 1 apricot
    // 2 banana
    return 0;
}
```

#### 5. Duyệt tất cả các phần tử có cùng một key (`equal_range`)
Khi một key có nhiều value, ta có thể dùng `equal_range(key)` để lấy một cặp iterator `[first, second)` chứa toàn bộ các phần tử có key đó:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    multimap<string, string> dictionary;
    dictionary.insert({"run", "chay"});
    dictionary.insert({"run", "khoi dong"});
    dictionary.insert({"run", "quan ly"});
    dictionary.insert({"book", "quyen sach"});
    // Lay khoang chua tat ca cac gia tri cua key "run"
    auto range = dictionary.equal_range("run");
    cout << "Cac nghia cua tu 'run':" << endl;
    for(auto it = range.first; it != range.second; ++it){
        cout << "- " << it->second << endl;
    }
    // Output:
    // - chay
    // - khoi dong
    // - quan ly
    return 0;
}
```

---

## 5. Unordered Map

### a. Khái niệm cơ bản
- `unordered_map` cũng lưu trữ các cặp key-value với các key là **duy nhất** (không trùng lặp) tương tự như `map`.
- Điểm khác biệt lớn nhất: Các phần tử trong `unordered_map` **KHÔNG được sắp xếp** theo bất kỳ thứ tự nào.
- Cấu trúc dữ liệu bên dưới: `unordered_map` sử dụng **bảng băm (Hash Table)**, trong khi `map` sử dụng **cây đỏ-đen (Red-Black Tree)**.
- Thư viện: `#include <unordered_map>` (hoặc `#include <bits/stdc++.h>`).

**Độ phức tạp thuật toán:**
| Thao tác | `map` (Red-Black Tree) | `unordered_map` (Hash Table) |
| :--- | :--- | :--- |
| Tìm kiếm (`find`) | $\mathcal{O}(\log N)$ | Trung bình $\mathcal{O}(1)$, tệ nhất $\mathcal{O}(N)$ |
| Chèn (`insert`, `[]`) | $\mathcal{O}(\log N)$ | Trung bình $\mathcal{O}(1)$, tệ nhất $\mathcal{O}(N)$ |
| Xóa (`erase`) | $\mathcal{O}(\log N)$ | Trung bình $\mathcal{O}(1)$, tệ nhất $\mathcal{O}(N)$ |

> [!NOTE]
> Trường hợp xấu nhất $\mathcal{O}(N)$ của `unordered_map` xảy ra khi có hiện tượng xung đột băm (Hash Collision) quá nhiều. Tuy nhiên, trong phần lớn các trường hợp thực tế, `unordered_map` chạy nhanh hơn `map` đáng kể (thời gian $\mathcal{O}(1)$).

**Cú pháp khai báo:**
```cpp
// unordered_map<kieu_du_lieu_key, kieu_du_lieu_value> ten_unordered_map;
unordered_map<int, int> ump;
unordered_map<string, int> word_count;
```

### b. Các thao tác cơ bản trong `unordered_map`
`unordered_map` hỗ trợ đầy đủ các hàm và toán tử giống hệt như `map`:
- Toán tử `ump[key] = value` và `ump[key]`.
- Phương thức: `insert()`, `count()`, `find()`, `erase()`, `size()`, `empty()`, `clear()`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // Khai bao unordered_map
    unordered_map<string, int> ump;

    // Them phan tu bang toan tu [] hoac insert
    ump["apple"] = 10;
    ump["banana"] = 20;
    ump.insert({"cherry", 30});
    ump["orange"] = 15;

    // Ghi de gia tri
    ump["apple"] = 50;

    // Duyet qua unordered_map
    // Luu y: Thu tu in ra khong theo thu tu tu dien hay thu tu chen vao
    for(auto it : ump){
        cout << it.first << " : " << it.second << endl;
    }
    // Output (thu tu co the khac nhau tuy vao ham bam):
    // orange : 15
    // cherry : 30
    // apple : 50
    // banana : 20
    // In lai lan nua ket qua cung se khong giong lan truoc
    for(auto it : ump){
        cout << it.first << " : " << it.second << endl;
    }
    // Output:
    // banana : 20
    // cherry : 30
    // apple : 50
    // orange : 15
    // Kiem tra su ton tai bang count() hoac find()
    if(ump.count("banana")){
        cout << "Gia tri cua banana: " << ump["banana"] << endl;
    }

    // Xoa mot key khoi unordered_map
    ump.erase("cherry");
    cout << "Kich thuoc sau khi xoa: " << ump.size() << endl; // Output: 3

    return 0;
}
```

### c. So sánh khi nào nên dùng `map` và `unordered_map`

| Tiêu chí | `map` | `unordered_map` |
| :--- | :--- | :--- |
| **Thứ tự phần tử** | Luôn được sắp xếp theo key (mặc định tăng dần) | Không sắp xếp, thứ tự ngẫu nhiên theo bucket |
| **Tốc độ truy xuất** | $\mathcal{O}(\log N)$ ổn định | Trung bình $\mathcal{O}(1)$ cực nhanh |
| **Cấu trúc lưu trữ** | Cây nhị phân tìm kiếm tự cân bằng (Red-Black Tree) | Bảng băm (Hash Table) |
| **Hàm `lower_bound`, `upper_bound`** | Có hỗ trợ | **Không hỗ trợ** |
| **Hỗ trợ kiểu dữ liệu Key** | Hỗ trợ mọi kiểu dữ liệu có toán tử `<` (kể cả `pair`, `vector`, `set`, struct...) | Chỉ hỗ trợ sẵn các kiểu dữ liệu cơ bản (`int`, `long long`, `string`, `double`...). Muốn dùng `pair` hay `vector` làm key thì phải tự viết hàm băm (custom hash function). |
| **Khi nào nên sử dụng?** | Khi cần duyệt dữ liệu theo thứ tự, cần tìm phần tử lớn nhất/nhỏ nhất, hoặc cần dùng tìm kiếm nhị phân (`lower_bound`). | Khi bài toán cần tốc độ cao, xử lý số lượng truy vấn lớn và không cần quan tâm đến thứ tự phần tử. |
