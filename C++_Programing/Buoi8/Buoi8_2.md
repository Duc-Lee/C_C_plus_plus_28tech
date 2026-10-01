# Bài tập mảng 1 chiều (tiếp theo)

## Bài 11: Ước chung lớn nhất của mọi cặp số trong mảng

Cho mảng một chiều các số nguyên dương, tìm ước chung lớn nhất của 2 số bất kì trong dãy.

### Input
- Dòng đầu tiên là số lượng test case $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào $n$ là số phần tử của mảng $A[]$; dòng kế tiếp đưa vào $n$ số $A[i]$ của mảng; các số được viết cách nhau một vài khoảng trống.
- $T, n, A[i]$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le n \le 10^3$; $1 \le A[i] \le 10^6$.

### Output
- In ra ước chung lớn nhất của 2 số bất kì trong dãy.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 1<br>10<br>2 3 1 4 5 7 14 3 5 10 | 7 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// tim uoc chung lon nhat 
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++) cin >> a[i];
        int res = 0; // luu gia tri uoc chung lon nhat 2 so bat ki
        
        for(int i = 0;i<n;i++){
            for(int j = j+1;j<n;j++){
                // dung thuat toan euclid de tim uoc chung lon nhat
                res = max(res, gcd(a[i], a[j]));
            }
        }
        cout << res << endl;
    }
}
```
- Cách 2 : 
```cpp
#include <bits/stdc++.h>
using namespace std;

// khoi tao ham map 
map<int,int> mp;
// ham tim uoc cua n
void solve(int n){
    // bat dau tai 1 vi 1 cung la 1 uoc
    for(int i = 1; i<= sqrt(n);i++){
        // neu n chia het cho i 
        // thi i la uoc cua n và n/i cung la so uoc cua n
        if(n % i == 0){
            mp[i]++;
            // neu khong phai i^2 = n
            // thi n/i cung la uoc cua n
            if(i != n/i) mp[n/i]++;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0;i<n;i++){
            cin >> a[i];
            solve(a[i]);
        }
        // duyet qua map tim uoc chung lon nhat 
        int res = 0;
        for(auto it : mp){
            // neu uoc do xuat hien tu 2 lan tro len 
            // thi do la uoc chung cua it nhat 2 so 
            if(it.second >= 2){
                // cap nhat gia tri uoc chung lon nhat 
                // it.first la uoc chung 
                res = max(res,it.first);
            }
        }
        cout << res << endl;
        mp.clear();
    }
}

```

## Bài 12. Liệt kê các số chia hết
Cho mảng một chiều các số nguyên không âm, đếm các số nguyên dương x > 1 sao cho tất cả các phần tử trong mảng đều chia hết cho x.

**Input**
Dòng đầu tiên là số lượng test case T

Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1 <= T <= 100; 1 <= n <= 10^3; 1 <= A[i] <= 10^6;

**Output**
In ra số lượng số x đếm được

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 1<br>4<br>8 24 16 32 | 4 |

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// ham check 
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i<n;i++) cin >> a[i];
        // tim uoc chung lon nhat cua ca mang
        int x= a[0];
        for(int i = 1; i<n;i++){
            // tim uoc chung lon nhat cua x và a[i]
            x = gcd(x,a[i]);
        }
        // dem cac uoc cua x
        int count = 0;
        // duyet tu 2 vi x > 1
        for(int i = 2; i<= sqrt(x);i++){
            if(x % i == 0){
                // luon luon cong 1 so voi 2 uoc 
                count += 2;
                if(i*i == x) count--;
            }
        }
        // neu x > 1 nghia la x co it nhat 1 uoc 
        // do la chinh no
        // ta cong 1 vi 1 khong duoc tinh trong vong lap 
        // nen ta bu them
        if(x > 1) count++;
        cout << count << endl;
    }
}

```
- Ý tưởng : 
    - Tìm ước chung lớn nhất của tất cả các phần tử trong mảng
    - Sau đó liệt kê tất cả các ước của ước chung lớn nhất
    - In ra số lượng số x đếm được
    - Ví dụ : 
        - Input : 8 24 16 32
        - Ước chung lớn nhất của tất cả các phần tử trong mảng là 8
        - Các ước của 8 là 1, 2, 4, 8
        - Số lượng số x đếm được là 4
        - Output : 4

----

## Bài 13. Điểm cân bằng (Equilibrium index)
Cho mảng một chiều các số nguyên, hãy liệt kê các chỉ số x trong mảng mà tổng các phần tử có chỉ số nhỏ hơn x bằng với tổng các phần tử có chỉ số lớn hơn x.

**Input**
Dòng đầu tiên là số lượng test case T

Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1 <= T <= 100; 1 <= n <= 10^6; 1 <= A[i] <= 10^6;

**Output**
In ra kết quả của mỗi test trên 1 dòng. Nếu mảng không tồn tại chỉ số I in ra -1.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>7<br>-7 1 5 2 -4 3 0<br>4<br>1 2 3 4 | 3<br>-1 |

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        long long sum1 =0, sum2 =0;
        // nhpa mang 
        for(int i = 0;i,n;i++){
            cin >> a[i];
            // tinh tong cac phan tu 
            sum1 += a[i];
        }
        // duyet qua mang 
        // tru a[i] khoi tong de voi gia tri 
        // ap dung ki thuat 2 con tro
        for(int i = 0;i<n;i++){
            // tru a[i] khoi tong de voi gia tri
            sum1 -= a[i];
            if(sum1 == sum2){ // neu tong 2 nua bang nhau 
                // in ra chi so i 
                cout << i << endl;
                return 0;
            }
            sum2 += a[i];
        }
        // neu khong tim thay 
        cout << -1 << endl;

    }
    return 0;
}

```

---

## Bài 14. Tần suất lẻ
Cho dãy số A[] gồm có N phần tử. Các phần tử trong dãy số đều xuất hiện với tần suất chẵn, chỉ có duy nhất 1 số có số lần xuất hiện là số lẻ. Nhiệm vụ của bạn là hãy tìm số này.

**Input:**
Dòng đầu tiên là số lượng bộ test T (T <= 10).

Mỗi test gồm số nguyên N (1 <= N <= 100 000), số lượng phần tử trong dãy số ban đầu. N là một số lẻ.

Dòng tiếp theo gồm N số nguyên A[i] (1 <= A[i] <= 1 000 000).

**Output:**
Với mỗi test in ra trên mỗi dòng một số nguyên là đáp án của bài toán.

**Ví dụ:**

| Input | Output |
| :--- | :--- |
| 2<br>7<br>1 2 3 2 3 1 3<br>5<br>1 1 3 3 2 | 3<br>2 |

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

// khoi tao mang dem tan suat 
int freq[10000];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        // reset lai mang tan suat 
        memset(freq,0,sizeof(freq));
        for(int i =0;i<n;i++){
            cin >> a[i];
            freq[a[i]]++;
        }
        // duyet qua mang 
        for(int i =0;i<n;i++){
            // neu xuat hien le thi in ra
            if(freq[a[i]] % 2 != 0){
                cout << a[i] << endl;
                break;
            }
        }
    }
    return 0;
}
```

----

## Bài 15. Loại bỏ mèo
Như bạn biết Nam là một người rất yêu mèo, bởi vậy trong nhà anh ấy cũng nuôi rất nhiều mèo với những màu sắc rất khác nhau.
Vào một ngày đẹp trời nọ, Nam tập hợp N con mèo của mình thành một hàng ngang, và cảm thấy rất ngứa mắt vì màu sắc của chúng là khác nhau. Bởi vậy, anh ta muốn loại bỏ một số ít nhất những con mèo ra khỏi hàng để những con mèo còn lại có màu giống nhau. Mỗi bước loại bỏ, Nam sẽ yêu cầu con mèo ở ngoài cùng bên trái hoặc ngoài cùng bên phải rời khỏi hàng ngang.
Hãy giúp Nam tính xem anh ta sẽ phải loại bỏ bao nhiêu con mèo ra khỏi hàng ngang.

**Input**
Dòng 1: Số nguyên N, số con mèo của Nam (1 <= N <= 10^5).
Dòng 2: Gồm N số nguyên A[i] là màu của con mèo thứ i (0 <= A[i] <= 10^9).

**Output**
Kết quả bài toán.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 4<br>1 2 3 4 | 3 |
| 5<br>1 2 2 1 2 | 3 |

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++) cin >> a[i];
        // ban chat là tim day con dai nhat 
        // tim day con dai nhat 
        int dem = 1;
        int max_length = 0;
        for(int i =1;i<n;i++){
            // neu phan tu hien tai bang phan tu truoc do thi tang dem
            if(a[i] == a[i-1]){
                dem++;
            }
            // neu khong bang nhau thi cap nhat max_length
            else{
                dem = 1;
            }
            // tim day con dai nhat
            max_length = max(max_length,dem);
        }
        // in ra ket qua
        cout << n - max_length << endl;
    }
    return 0;
}
```

-----

## Bài 16. Sắp xếp lại mảng
Bạn được cung cấp một mảng a có độ dài n.

Bạn cũng được cung cấp một tập hợp các vị trí riêng biệt p1, p2, ..., pm, trong đó 1 <= pi < n. Vị trí pi có nghĩa là bạn có thể hoán đổi các phần tử a[pi] và a[pi + 1]. Bạn có thể áp dụng thao tác này bất kỳ số lần nào cho mỗi vị trí đã cho.

Nhiệm vụ của bạn là xác định xem có thể sắp xếp mảng ban đầu theo thứ tự không giảm (a1 <= a2 <= ... <= an) chỉ sử dụng các hoán đổi được phép hay không.

Ví dụ, nếu a = [3,2,1] và p = [1,2], thì trước tiên chúng ta có thể hoán đổi các phần tử a[2] và a[3] (vì vị trí 2 nằm trong tập p đã cho). Ta được mảng a = [3,1,2]. Sau đó, chúng ta hoán đổi a[1] và a[2] (vị trí 1 cũng được chứa trong p). Ta được mảng a = [1,3,2]. Cuối cùng, chúng ta lại hoán đổi a[2] và a[3] và nhận được mảng a = [1,2,3], được sắp xếp theo thứ tự không giảm.

Bạn có thể thấy rằng nếu a = [4,1,2,3] và p = [3,2] thì bạn không thể sắp xếp mảng.

**Input**
Dòng đầu tiên của dữ liệu đầu vào chứa một số nguyên t (1 <= t <= 100).

Sau đó, t các trường hợp thử nghiệm theo sau. Dòng đầu tiên của mỗi test case chứa hai số nguyên n và m (1 <= m < n <= 100) - số phần tử trong a và số phần tử trong p. Dòng thứ hai của test case chứa n số nguyên a1, a2, ..., an (1 <= ai <= 100). Dòng thứ ba của test case chứa m số nguyên p1, p2, ..., pm (1 <= pi < n, tất cả pi đều khác biệt) - tập hợp các vị trí được mô tả trong câu lệnh.

**Output**
In YES hoặc NO với mỗi test case

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 6<br>3 2<br>3 2 1<br>1 2<br>4 2<br>4 1 2 3<br>3 2<br>5 1<br>1 2 3 4 5<br>1<br>4 2<br>2 1 4 3<br>1 3<br>4 2<br>4 3 2 1<br>1 3<br>5 2<br>2 1 2 3 3<br>1 4 | YES<br>NO<br>YES<br>YES<br>NO<br>YES |

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int a[n];
        // nhap mang a 
        for(int i = 0;i<n;i++) cin >> a[i];
        // danh dau cac vi tri co the hoan doi 
        int pos[1001] = {0};
        for(int i = 0;i<m;i++){
            int x ; cin >> x;
            // danh dau vi tri i va i+1 co the hoan doi
            pos[x-1] = 1;
        }
        for(int i = 0;i < n;i++){
            // neu phan tu khong co the hoan doi thi bo qua
            if(pos[i] == 0) continue;
            int idx = i;
            // tim den khi nao gap phan tu khong the hoan doi hoac gap phan tu cuoi mang
            while(idx < n && pos[idx] == 1){
                ++idx;
            }
            // sap xep doan a[i..idx] theo thu tu tang dan
            sort(a+i,a+idx);
            i = idx;
        }
        bool ok = true;
        // kiem tra xem mang a da sap xep theo thu tu khong giam chua 
        for(int i =0;i<n-1;i++){
            if(a[i]>a[i+1]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
```

## Bài 17. Máy tính

ZS the Coder đang mã hóa trên một máy tính điên. Nếu bạn không gõ một từ trong một giây liên tiếp, mọi thứ bạn gõ sẽ biến mất!

Nếu bạn gõ một từ ở giây thứ $a$ và sau đó là từ tiếp theo ở giây $b$, thì nếu $b - a \le c$, chỉ từ mới được thêm vào các từ khác trên màn hình. Nếu $b - a > c$, thì mọi thứ trên màn hình sẽ biến mất và sau đó từ bạn đã gõ sẽ xuất hiện trên màn hình.

Ví dụ: nếu $c = 5$ và bạn đã gõ các từ ở giây $1, 3, 8, 14, 19, 20$ thì ở giây thứ $8$ sẽ có $3$ từ trên màn hình. Sau đó, mọi thứ biến mất vào giây thứ $13$ vì không có gì được gõ. Ở giây $14$ và $19$, hai từ khác được gõ và cuối cùng, ở giây thứ $20$, một từ nữa được gõ và tổng cộng $3$ từ vẫn còn trên màn hình.

Bạn được cung cấp thời gian khi ZS gõ các từ. Xác định có bao nhiêu từ vẫn còn trên màn hình sau khi anh ta gõ xong mọi thứ.

**Input**
- Dòng đầu tiên chứa hai số nguyên $n$ và $c$ ($1 \le n \le 100\,000, 1 \le c \le 10^9$) - số lượng từ ZS the Coder đã nhập và độ trễ của máy tính điên tương ứng.
- Dòng tiếp theo chứa $n$ số nguyên $t_1, t_2, \dots, t_n$ ($1 \le t_1 < t_2 < \dots < t_n \le 10^9$), trong đó $t_i$ biểu thị số giây khi ZS gõ từ thứ $i$.

**Output**
- In một số nguyên dương duy nhất, số lượng từ còn lại trên màn hình sau khi tất cả $n$ từ được gõ.

**Ví dụ:**

| Input | Output |
| :--- | :--- |
| `6 5`<br>`1 3 8 14 19 20` | `3` |

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n >> c;
        int t[n];
        for(int i =0;i<n;i++) cin >> t[i];
        int ans = 1;
        for(int i=1 ; i<n ; i++){
            // neu thoi gian chenh lech nho hon hoac bang c thi ta se duoc them 1 tu
            // thoi gian nhap chenh lenh giua 2 tu khong nho hon hoac bang c thi ta se reset lai ans
            // t[i] la thoi gian nhap tu thu i
            // t[i-1] la thoi gian nhap tu thu i-1
            if(t[i]-t[i-1] <=c){
                ans++;
            }else{
                // neu khong thi ta se reset lai ans = 1
                ans = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

```
## Bài 18. Dãy con liên tục nhỏ nhất

Cho mảng $A[]$ gồm $n$ số nguyên và số $X$. Hãy tìm độ dài dãy con liên tục nhỏ nhất có tổng lớn hơn $X$. Ví dụ với $A[] = \{1, 4, 45, 6, 0, 19\}$ và $X = 51$ ta có câu trả lời là $3$ tương ứng với dãy con $\{4, 45, 6\}$. Với dãy $A[] = \{1, 10, 5, 2, 7\}$ và $X = 9$ ta có câu trả lời là $1$ tương ứng với dãy con $\{10\}$. Với dãy $A[] = \{1, 2, 4\}$ và $X = 8$ ta có câu trả lời là $-1$.

**Input:**
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng $n$ và số $X$; dòng tiếp theo là $n$ số $A[i]$ của mảng $A[]$; các số được viết cách nhau một vài khoảng trống.
- $T, n, X, A[i]$ thỏa mãn ràng buộc: $1 \le T \le 100; 1 \le n \le 10^7; 1 \le A[i] \le 10^7$.

**Output:**
- Đưa ra kết quả mỗi test theo từng dòng.

**Ví dụ:**

| Input | Output |
| :--- | :--- |
| `2`<br>`6 51`<br>`1 4 45 6 0 19`<br>`3 8`<br>`1 2 4` | `3`<br>`-1` |

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n];
        // nhap mang a 
        for(int &i : a) cin >> i;
        int l =0, res = 1e9;
        long long sum = 0;
        // duyệt qua mảng
        for(int r = 0; r < n ;r ++){
            // cộng thêm phần tử hiện tại vào tổng
            sum += a[r];
            // nếu tổng lớn hơn x thì ta sẽ thu hẹp khoảng cách từ left đến right
            // res = min(res, r - l + 1); // cập nhật kết quả nhỏ nhất
            // sum -= a[l]; // trừ đi phần tử ở bên trái
            // ++l; // tăng l lên 1
            while(sum > x){
                // cập nhật độ dài dãy con liên tục nhỏ nhất
                // r - l + 1 là độ dài của dãy con hiện tại 
                // phải cộng 1 vì mảng bắt đầu từ 0 và l là chỉ số bắt đầu của dãy con 
                // r là chỉ số kết thúc của dãy con 
                // r - l + 1 là số lượng phần tử trong dãy con 
                res = min(res, r - l + 1);
                // trừ đi phần tử ở bên trái
                sum -= a[l];
                // tăng l lên 1
                ++l;
            }
        }
        if (res == 1e9)
        {
            cout << "-1" << endl;
        }else{
            cout << res << endl;
        }
    }
    return 0;
}

```
## Bài 19. Median

Phần tử được gọi là **trung vị** (median) của mảng là phần tử đứng giữa theo thứ tự các phần tử đã được sắp xếp trong trường hợp số lượng phần tử của mảng là lẻ, hoặc là phần tử nhỏ hơn trong 2 phần tử đứng giữa trong trường hợp số lượng phần tử của mảng là chẵn. Hãy tìm median của mảng.

**Input:**
- Dòng đầu tiên là số lượng bộ test $T$ ($T \le 10$).
- Mỗi test gồm số nguyên $N$ ($1 \le N \le 100\,000$), số lượng phần tử trong dãy số ban đầu.
- Dòng tiếp theo gồm $N$ số nguyên $A[i]$ ($1 \le A[i] \le 1\,000\,000$).

**Output:**
- Với mỗi test in ra trên mỗi dòng một số nguyên là đáp án của bài toán.

**Ví dụ:**

| Input | Output |
| :--- | :--- |
| `1`<br>`5`<br>`1 2 4 5 3`<br>`6`<br>`7 8 10 9 5 6` | `3`<br>`7` |

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        // nhap mang a 
        for(int i = 0 ; i< n ; i++) cin >> a[i];
        // sap xep mang a tang dan 
        sort(a,a+n);
        if(n % 2 == 0){
            // neu n chan thi median la phan tu nho hon trong 2 phan tu dung giua 
            // a[n/2-1] la phan tu nho hon trong 2 phan tu dung giua 
            cout << a[n/2-1] << endl;
        }else{
            // neu n le thi median la phan tu dung giua 
            // a[n/2] la phan tu dung giua 
            cout << a[n/2] << endl;
        }
    }
    return 0;
}
```
## Bài 20. Tăng mảng

Bạn được cung cấp một mảng $n$ số nguyên. Bạn muốn sửa đổi mảng để nó tăng lên, tức là mọi phần tử đều lớn ít nhất bằng phần tử trước đó.

Trên mỗi lần di chuyển, bạn có thể tăng giá trị của bất kỳ phần tử nào lên một. Số lần di chuyển tối thiểu cần thiết là bao nhiêu?

**Input:**
- Dòng đầu tiên chứa một số nguyên $n$: kích thước của mảng.
- Sau đó, dòng thứ hai chứa $n$ số nguyên $x_1, x_2, \dots, x_n$: nội dung của mảng.

**Output:**
- In số lần di chuyển tối thiểu.

**Ràng buộc:**
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$

**Ví dụ:**

| Input | Output |
| :--- | :--- |
| `5`<br>`3 2 5 1 7` | `5` |

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i< n ; i++) cin >> a[i];
    // khoi tao bien dem gia tri can tang 
    int ans = 0;
    for(int i = 1 ; i< n ; i++){
        // neu a[i] nho hon a[i-1] thi ta se cong them a[i-1] - a[i] vao ans
        // vi du : 3 2 5 1 7
        // i = 1 : a[1] = 2 , a[0] = 3 
        // a[1] < a[0] nen ans += a[0] - a[1] = 3 - 2 = 1 
        // a[1] = a[0] = 3
        // mang a tro thanh : 3 3 5 1 7
        // i = 2 : a[2] = 5 , a[1] = 3 
        // a[2] > a[1] nen ta se khong lam gi 
        // mang a van la : 3 3 5 1 7
        // i = 3 : a[3] = 1 , a[2] = 5 
        // a[3] < a[2] nen ans += a[2] - a[3] = 5 - 1 = 4
        // a[3] = a[2] = 5
        // mang a tro thanh : 3 3 5 5 7
        // i = 4 : a[4] = 7 , a[3] = 5 
        // a[4] > a[3] nen ta se khong lam gi 
        // mang a van la : 3 3 5 5 7
        // cuoi cung mang a tro thanh : 3 3 5 5 7
        // ans = 1 + 4 = 5 
        if(a[i] < a[i-1]){
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}
```