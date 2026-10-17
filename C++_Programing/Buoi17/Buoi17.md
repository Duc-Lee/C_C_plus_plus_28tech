# Hướng dẫn giải bài tập sử dụng cấu trúc dữ liệu `set` và `map`

## Bài 1. Đếm số lượng phần tử khác nhau trong mảng số nguyên

**Yêu cầu:** Sử dụng cả `set` và `map`.

### Đề bài:
Đếm số lượng phần tử khác nhau trong mảng số nguyên.

### Input:
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Mỗi test case bao gồm 2 dòng:
  - Dòng đầu tiên là số lượng phần tử trong mảng $n$ ($1 \le n \le 1000$).
  - Dòng thứ 2 bao gồm $n$ phần tử trong mảng $a_i$ ($-10^9 \le a_i \le 10^9$).

### Output:
- In ra số lượng phần tử khác nhau trong mảng.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 2<br>5<br>1 2 2 2 1<br>4<br>1 2 3 4 | 2<br>4 |

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
        // khai bao map 
        map<int, int> mp;
        // nhap so nuyen vo mang 
        for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            // nap ptu x vo map
            mp[x] = true;
        }
        // in ket qua 
        cout << mp.size() << endl;
        // cach 2 : su dung set 
        /*
            set<int> s;
            for(int i = 0;i<n;i++){
                int x;
                cin >> x;
                // nap ptu x vo set
                s.insert(x);
            }
            // in ket qua
            cout << s.size() << endl;
        */
        // cach 3  : su dung sap xep 
        /*
            int a[1000];
            for(int &i : a){
                cin >> i;
            }
            // sap xep mang a tang dan
            sort(a, a + n);
            // khoi tao bien dem 
            int cnt = 1;
            for(int i = 1;i<n;i++){
                if(a[i] != a[i-1]){
                    cnt++;
                }
            }
            cout << cnt << endl;
        */
    }
    return 0;
}
```

## Bài 2. Kiểm tra phần tử trong mảng

**Yêu cầu:** Sử dụng cả `set` và `map`.

### Đề bài:
Cho một mảng số nguyên gồm $n$ phần tử, với mỗi truy vấn hãy kiểm tra xem một số nào đó có nằm trong mảng hay không?

### Input:
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Mỗi test case bao gồm nhiều dòng:
  - Dòng đầu tiên là số lượng phần tử trong mảng $n$ ($1 \le n \le 1000$).
  - Dòng thứ 2 bao gồm $n$ phần tử trong mảng ($-10^9 \le a_i \le 10^9$).
  - Dòng thứ 3 là số lượng truy vấn $q$.
  - $q$ dòng tiếp theo, mỗi dòng là một số nguyên cần kiểm tra.

### Output:
- In ra `YES` nếu số cần kiểm tra xuất hiện trong mảng, ngược lại in `NO`.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 1<br>6<br>1 2 3 8 7 0<br>4<br>1<br>2<br>10<br>20 | YES<br>YES<br>NO<br>NO |

### Code : 
```cpp
#include <bits/stdc++.h>
using namespace std;

// ham check xem 
// cach lam tuyen tinh O(n) 
bool query1(int a[], int n, int q){
    for(int i =0;i<n;i++){
        if(a[i] == q){
            return true;
        }
    }
    return false;
}
// su dung tim kiem nhi phan tren ham 
bool query2(int a[], int n, int q){
    // sap xep mang a tang dan
    sort(a, a + n); 
    // su dung thuat toan tim kiem nhi phan de check 
    // O(log n) 
    return binary_search(a, a + n, q);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >>n >> q;
        // cach su dung set
        set<int> st;
        for(int i =0;i<n;i++){
            int x;
            cin >> x;
            // add phan vo set 
            st.insert(x);
        }
        // su dung set 
        if(st.count(q) == 1){
            cout <<"YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        // cach su dung map 
        /*
            // no tuong tu set thoi 
            map<int,bool> mp;
            for(int i =0;i<n;i++){
                int x;
                cin >> x;
                mp[x] = true;
            }
            // check xem 
            if(mp.count(q) == 1){
                cout <<"YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        */
    }
    return 0;
}
```

## Bài 3. Phần tử thuộc mảng thứ nhất mà không thuộc mảng thứ 2

**Yêu cầu:** Sử dụng cả `set` và `map`.

### Đề bài:
Cho 2 mảng số nguyên, hãy đếm những phần tử thuộc mảng thứ nhất mà không thuộc mảng thứ 2.

### Input:
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Mỗi test case gồm 3 dòng:
  - Dòng đầu tiên là số lượng phần tử của mảng thứ nhất và mảng thứ 2 ($1 \le n, m \le 1000$).
  - Dòng thứ 2 là các số thuộc mảng thứ 1 ($-10^9 \le a_i \le 10^9$).
  - Dòng thứ 3 là các số thuộc mảng thứ 2 ($-10^9 \le a_i \le 10^9$).

### Output:
- Liệt kê các số thuộc mảng thứ 1 mà không thuộc mảng thứ 2, theo thứ tự xuất hiện, nếu không tồn tại số nào in ra "NOT FOUND".

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 1<br>4 5<br>1 2 2 9<br>2 0 9 8 3 | 1 |

### Code 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        // khoi tao 2 mang 
        int a[n], b[m];
        for(int &i : a) cin >> i;
        // nhap mang b su dung set 
        set<int> st;
        for(int i =0; i<m;i++) {
            int x;
            cin >> x;
            // nhap phan tu vo mang set 
            st.insert(x);
        }
        bool ok = false;
        for(int i = 0; i<n; i++) {
            // tim kiem ptu a[i] trong set
            // neu khong tim thay 
            // thi tra ve ket qua tim kiem la end() 
            if(st.find(a[i]) == st.end()) {
                // in ra nhung phan tu thuoc mang a ma khong thuoc mang b 
                cout << a[i] << " ";
                ok = true;
            }
        }
        if(!ok) cout << "NOT FOUND" << endl;
        // cach su dung map 
        /*
            map<int,bool> mp;
            for(int i =0;i<m;i++){
                int x;
                cin >> x;
                mp[x] = true;
            }
            for(int i = 0; i<n; i++){
                int x;
                cin >> x;
                // ham find() tuong tu nhu set
                if(mp.find(x) == mp.end()){
                    cout << x << " ";
                    ok = true;
                }
            }
            if(!ok) cout << "NOT FOUND" << endl;
        */
    }
    return 0;
}
```

## Bài 4. Tìm số xuất hiện nhiều lần nhất trong mảng

### Đề bài:
Tìm số xuất hiện nhiều nhất trong mảng, trong trường hợp có nhiều số có cùng số lần xuất hiện thì lấy số nhỏ nhất.

### Input:
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Mỗi test case bao gồm nhiều dòng:
  - Dòng đầu tiên là số lượng phần tử trong mảng $n$ ($1 \le n \le 100000$).
  - Dòng thứ 2 bao gồm $n$ phần tử trong mảng ($-10^{18} \le a_i \le 10^{18}$).

### Output:
- In ra số xuất hiện nhiều nhất cùng số lần xuất hiện của nó.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 1<br>10<br>1 1 2 2 2 1 4 7 8 19 | 1 3 |

### Code 
```cpp
#include <bis/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // khai bao map 
        map<int, int> mp;
        // nhap mang nhap ca vo map 
        for(int i =0;i<n;i++){
            int x;
            cin >> x;
            // tang tan suat cua phan tu x 
            mp[x]++;
        }
        // khoi tao bien dem 
        int cnt = 0; // bien luu tan suat 
        int res = 0; // bien luu ket qua 
        // duyet qua map 
        for(auto& it : mp){
            // neu tan suat lon nhat 
            if(it.second >= cnt){
                cnt = it.second;
                res = it.first;
            }
        }
        cout << res << " " << cnt << endl;
    }
}
```

## Bài 5. Tìm kí tự xuất hiện nhiều nhất trong chuỗi

### Đề bài:
Tìm kí tự có số lần xuất hiện nhiều nhất và có thứ tự từ điển nhỏ nhất trong chuỗi.

### Input:
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Mỗi test case gồm một dòng là một chuỗi có không quá $100000$ kí tự, bao gồm cả dấu cách.

### Output:
- Tìm kí tự có số lần xuất hiện nhiều nhất và có thứ tự từ điển nhỏ nhất.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 1<br>abcdzzzzu abcd | z |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        map<char,int> mp;
        // duyet qua chuoi 
        for(auto x : s){
            mp[x]++;
        }
        int cnt = 0;
        char res = 'a';
        for(auto& it : mp){
            // neu gap chuoi nao gap hon thi update no 
            if(it.second >= cnt){
                cnt = it.second;
                res = it.first;
            }
        }
        cout << res << endl;
        /*
        // su dung cach khac bang cach dung mang luu tan suat 
        int a[256] = {0};
        for(char x : s){
            a[(int)x]++;
        }
        // khoi tao bien dem va ki tu 
        int cnt = 0;
        char res;
        // duyet qua mang 
        for(int i =0;i<256;i++){
            // neu gap chuoi nao gap hon thi update no 
            if(a[i] >= cnt){
                cnt = a[i];
                res = (char)i;
            }
        }
        cout << res << endl;
        */
    }
}
```

## Bài 6. Kiểm tra xâu pangram bằng mảng đánh dấu và set

### Đề bài:
Xâu được gọi là pangram nếu nó có đủ các chữ cái từ 'a' tới 'z' không phân biệt hoa thường. Kiểm tra một xâu nhập vào có phải là xâu pangram hay không?

### Input:
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Mỗi test case bao gồm một xâu chỉ gồm các kí tự là chữ cái không quá $10000$ kí tự.

### Output:
- In ra `YES` nếu xâu nhập vào là xâu pangram, ngược lại in `NO`.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 2<br>ThequickbrownfoxjumpsoverthelazyDOG<br>andrewneiMan | YES<br>NO |

### Code 
```cpp
#include <bits/stdc++,h>
using namespace std;

// su dung mang dem 
bool freq(string s){
    // khoi tao mang dem 
    int a[26] = {0};
    // duyet qua chuoi
    for(char i : s){
        a[tolwwer(i) - 'a'] = 1;
    }
    // duyet qua mang dem
    int cnt = 0;
    for(int i = 0; i< 26;i++){
        // cong don mang dem
        cnt += a[i]; 
    }
    if(cnt == 26) return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        // khoi tao set
        set<char> st;
        // chuyen toan bo chuoi ve chu thuong
        for(int i =0;i<s.size();i++){
            s[i] = tolower(s[i]);
            // add ki tu vua chuyen vo set
            st.insert(s[i]);
        }
        // neu mang set = 26 ki tu 
        // thi do la xau pangram
        if(st.size() == 26) cout << "YES" << endl;
        else cout << "NO" << endl;
        /*
        // su dung map 
        map<char, bool> mp;
        // duyet qua chuoi 
        for(char x : s){
            // add vo map va dong thoi 
            // chuyen ve ki tu thuong
            mp.insert(tolwer(x)) = true;
        }
        // neu map co 26 ki tu 
        if(mp.size() == 26) cout << "YES" << endl;
        else cout << "NO" << endl;
        */
    }
}
```

## Bài 7. Đếm số lượng từ khác nhau trong câu

### Đề bài:
Đếm số lượng từ khác nhau trong một câu (phân biệt hoa thường).

### Input:
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Mỗi test case gồm một dòng là một xâu bao gồm cả khoảng trắng có không quá $10000$ kí tự.

### Output:
- In ra số lượng từ khác nhau trong câu.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 2<br>Python C++ java php Python python<br>Andrew neiman heisenberg neiman | 5<br>3 |

### Code 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        // khoi tao ham set 
        set<string> st;
        // tach chuoi 
        stringstream ss(s);
        // khoi tao bien tam
        string w;
        // duyet qua chuoi 
        // ss >> w la phep toan lay tu chuoi 
        // tu stringstream tu dong cat theo khoang trang 
        while(ss >> w){
            st.insert(w);
        }
        // in ra ket qua 
        cout << st.size() << endl;
        /*
        // cach su dung map 
        map<string, int> mp;
        stringstream ss(s);
        string w;
        while(ss >> w){
            mp[w]++;
        }
        cout << mp.size() << endl;
        */
    }
    return 0;
}   
```

## Bài 8. Tìm từ có số lần xuất hiện nhiều nhất trong chuỗi

### Đề bài:
Tìm từ có số lần xuất hiện nhiều nhất trong chuỗi, trường hợp các từ có số lần xuất hiện giống nhau thì từ có thứ tự từ điển nhỏ hơn sẽ là kết quả.

### Input:
- Dòng đầu tiên là số lượng test case $T$ ($1 \le T \le 100$).
- Mỗi test case gồm một dòng là một xâu bao gồm cả khoảng trắng có không quá $10000$ kí tự.

### Output:
- In ra từ có số lần xuất hiện nhiều nhất và có thứ tự từ điển nhỏ nhất.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 1<br>ngon ngu lap trinh ngon ngu | ngon |

### Code 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        // khoi tao map
        map<string, int> mp;
        // tach chuoi 
        stringstream ss(s);
        // khoi tao bien tam
        string w;
        while(ss >> w){
            mp[w]++;
        }
        // khoi tao bien dem
        int cnt = 0;
        string res;
        // duyet qua map
        for(auto& it : mp){
            // neu gap tu nao gap hon thi update no
            // tu nho den lon vi set da sap xep nho den lon 
            if(it.second > cnt){
                cnt = it.second;
                res = it.first;
            }
        }
        cout << res << endl;
    }
}

```

## Bài 9. Từ lặp đầu tiên

### Đề bài:
Tìm từ được lặp lại đầu tiên trong câu.

### Input:
- Dòng đầu tiên là số lượng bộ test $T$ ($1 \le T \le 100$).
- $T$ dòng tiếp theo, mỗi dòng chứa một chuỗi đầu vào.

### Output:
- In ra từ đầu tiên được lặp lại. Dữ liệu đảm bảo câu có từ 2 từ trở lên và có xuất hiện từ được lặp lại.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 2<br>abc abc abc zzz zzz cd<br>ngon ngu lap lap ngu ngon | abc<br>lap |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        // khoi tao set
        set<string> st;
        // tach chuoi 
        stringstream ss(s);
        // khoi tao bien tam
        string w;
        // khoi tao vector v
        vector<string> v;
        // day cac tu vo vector
        while(ss >> w){
            v.push_back(w);
        }
        // duyet qua vector
        for(int i = 0;i<v.size();i++){
            // neu gap tu nao gap hon thi update no
            // neu find tu do ma khac end() thi la no da ton tai 
            // khi do la tu duoc lap lai
            if(st.find(v[i]) != st.end()){
                cout << v[i] << endl;
                break;
            }
            // khong thi them vo vector
            st.insert(v[i]);
        }
    }
}
```

## Bài 10. Đặt tên người dùng

### Đề bài:
Xây dựng chương trình đặt tên tài khoản người dùng. Nếu tên người dùng muốn đặt đã xuất hiện trong hệ thống thì sẽ đặt tên tài khoản theo cú pháp: "tên người dùng muốn đặt" + số tài khoản cùng tên trong hệ thống cộng thêm 1.
- **Ví dụ:** Giả sử trong hệ thống đã tồn tại tên người dùng `rech` thì người dùng tiếp theo muốn sử dụng tên tài khoản là `rech` sẽ được lưu ở hệ thống với tên `rech1`. Tương tự như vậy, trong trường hợp có 2 tài khoản tên `rech` trong hệ thống thì người dùng tiếp theo có tên `rech` sẽ được lưu với tên `rech2`.

### Input:
- Dòng đầu tiên là số lượng tên người dùng $n$ muốn cài đặt vào hệ thống.
- $n$ dòng tiếp theo là tên người dùng.

### Output:
- In kết quả là tên người dùng được lưu trong hệ thống.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 14<br>an<br>binh<br>an<br>binh<br>long<br>huong<br>ngoc<br>thuan<br>nhung<br>nhung<br>ngoc thuan<br>nhung<br>nhung<br>nhung | an<br>binh<br>an1<br>binh1<br>long<br>huong<br>ngoc<br>thuan<br>nhung<br>nhung1<br>ngoc thuan<br>nhung2<br>nhung3<br>nhung4 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // tang toc do xuat nhap 
    ios :: sync_with_stdio(false);
    // bo xung dot giua cin / cout voi iostream
    cin.tie(nullptr);
    // khoi tao bien 
    int t;
    cin >> t;
    // khoi tao mang map 
    map<string,int> mp;
    while(t--){
        // khoi tao bien luu ten 
        string usename;
        cin >> usename;
        // kiem tra dieu kieu 
        // tim xem map co ten usename kia chua
        // neu chua thi ham find() se tra ve con tro end()
        // cu the in thang tu do ra
        // neu da xuat hien roi thi cong them mp[usename] vao 
        // ten duoi duoi 
        if(mp.find(usename) == mp.end()){
            cout << usename << endl;
        }else{
            // neu da co
            // ghi lai so thu tu cua no
            cout << usename << mp[usename] << endl;
        }
        mp[usename]++;
    }
    return 0;
}
```