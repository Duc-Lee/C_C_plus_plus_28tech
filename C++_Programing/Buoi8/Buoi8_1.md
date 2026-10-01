# Bài tập mảng 1 chiều 

## Bài 1: Sắp đặt dãy số

Cho mảng $A[]$ gồm $n$ phần tử. Nhiệm vụ của bạn là hãy sắp đặt lại các phần tử của mảng sao cho $A[i] = i$. Nếu phần tử $A[j]$ có giá trị khác $j$, hãy ghi vào $-1$. 

Ví dụ với mảng $A[] = \{-1, -1, 6, 1, 9, 3, 2, -1, 4, -1\}$ ta có kết quả $A[] = \{-1, 1, 2, 3, 4, -1, 6, -1, -1, 9\}$.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng:
  - Dòng đầu tiên đưa vào $n$ là số phần tử của mảng $A[]$.
  - Dòng kế tiếp đưa vào $n$ số $A[i]$ của mảng, các số được viết cách nhau một vài khoảng trống.
- Ràng buộc: $1 \le T \le 100$; $1 \le n \le 10^7$; $-10^{18} \le A[i] \le 10^{18}$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>10<br>-1 -1 6 1 9 3 2 -1 4 -1<br>6<br>0 -3 1 -2 3 -4 | -1 1 2 3 4 -1 6 -1 -1 9<br>0 1 -1 3 -1 -1 |

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
    // dung map de luu cac gia tri cua mang
    map<long long,bool> a;
    for(int i = 0;i<n;i++){
      long long x;
      cin >> x;
      // nhap so x vao map, neu x day xuat hien thi true
      // neu chua thi false 
      a[x] = true;
    }
    // in ra ket qua
    for(int i = 0;i <n;i++){
      // chay i den n
      // neu a[i] la true thi in ra i
      // neu a[i] la false thi in ra -1
      // do nhap lan luot ham map ban dau no xep theo thu tu san nhap vao nen ta chi can in ra theo thu tu tu 0 den n thoi
      if(a[i]){
        cout << i << " ";
      }
      else{
        cout << -1 << " ";
      }
    }
    cout << endl;
  }
}
```

------
## Bài 2: Số nhỏ nhất chưa xuất hiện

Cho mảng $A[]$ gồm $n$ số nguyên bao gồm cả số $0$. Nhiệm vụ của bạn là tìm số nguyên dương nhỏ nhất không có mặt trong mảng. Ví dụ với mảng $A[] = \{5, 8, 3, 7, 9, 1\}$, ta có kết quả là $2$.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào $n$ là số phần tử của mảng $A[]$; dòng kế tiếp đưa vào $n$ số $A[i]$ của mảng; các số được viết cách nhau một vài khoảng trống.
- $T, n, A[i]$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le n \le 10^6$; $-10^6 \le A[i] \le 10^6$;

### Output
- Đưa ra kết quả mỗi test theo từng dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>5<br>1 2 3 4 5<br>5<br>0 -10 1 3 -20 | 6<br>2 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// khai bao mang tinh 
long long cnt[1000001];

int main(){
  int t;
  cin >> t;
  while(t--){
    // dung mang anh xa
    int n;
    cin >> n;
    // reset lai mang cnt tat ca phan tu ve gia tri 0
    memset(cnt,0,sizeof(cnt));
    // nhap mang kiem tra luon 
    for(int i =0;i<n;i++){
      long long x;
      cin >> x;
      // kiem tra
      // so nay da xuat hien trong mang
      if( x > 0) cnt[x] = 1;
    }
    // In ra ket qua 
    for(int i = 0;i<n;i++){
      // duyet tu dau lan luot tu 0 den n-1
      // neu cnt[i] chua xuat hien
      if(cnt[i] == 0){
        cout << i ;
        // break de dam bao do la so dau tien 
        // do mk duyet tu be len 
        break;
      }
    }
    cout << endl;
  }
}
```

------

## Bài 3: Khoảng cách nhỏ nhất

Cho mảng $A[]$ gồm $n$ số chưa được sắp xếp. Hãy tìm $Min(|A[i] - A[j]|)$ (khoảng cách không âm) với $i \ne j$ và $i, j = 0, 1, 2, ..., n-1$. Ví dụ với $A[] = \{1, 5, 3, 19, 18, 25\}$ ta có kết quả là $1 = 19-18$. Với $A[] = \{1, 19, -4, 31, 28, 35, 100\}$ ta có kết quả là $3 = 31-28$.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng $n$; dòng tiếp theo là $n$ số $A[i]$ của mảng $A[]$; các số được viết cách nhau một vài khoảng trống.
- $T, n, A[i]$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le n \le 10^3$; $-10^3 \le A[i] \le 10^3$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>5<br>2 4 5 7 9<br>10<br>87 32 99 75 56 43 21 10 68 49 | 1<br>6 |

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
    int a[n];
    for(int i = 0;i<n;i++){
      cin >> a[i];
    }
    // khoi tao bien distance min 
    int res = 0;
    /*
    // duyet mang 
    // cach dai 
    for(int i = 0;i<n-1;i++){
      for(int j = i+1;j <n;j++){
        // duyet tung phan tu 
        // tim khoang cach nho nhat 
        // cu lay phan tu lon nhat tru phan tu nho nhat
        // lam sao de res be nhat la duoc 
        res = min(res,max(a[i],a[j])-min(a[i],a[j]));
      }
    }
    */
   // cach O(nlogn)
   // sap xep mang tu nho den lon
   sort(a,a+n);
   for(int i = 0;i<n-1;i++){
    // tru lay ty le 
    res = min(res,a[i+1]-a[i]);
   }
    cout << res << endl;
  }
}
```
------
## Bài 4: Liệt kê K phần tử lớn nhất

Cho mảng $A[]$ gồm $n$ phần tử, hãy tìm $k$ phần tử lớn nhất của mảng. Các phần tử được đưa ra theo thứ tự giảm dần.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào $N$ và $K$; dòng tiếp theo đưa vào $n$ số $A[i]$; các số được viết cách nhau một vài khoảng trống.
- $T, N, K, A[i]$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le K < N \le 10^3$; $1 \le A[i] \le 10^6$.

### Output
- Đưa ra kết quả mỗi bộ test trên một dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>5 3<br>10 7 9 12 6<br>6 2<br>9 7 12 8 6 5 | 12 10 9<br>12 9 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i = 0;i<n;i++){
            cin >> a[i];
        } 
        // sap xep mang tu nho den lon
        sort(a,a+n);
        // in ra k phan tu lon nhat 
        // 
        for(int i = 0;i<k;i++){
            cout << a[n-i-1] << " ";
        }
        cout << endl;
    }
}
```
------

## Bài 5: Đếm số phần tử lặp lại

Cho mảng $A[]$ gồm $N$ phần tử. Hãy đếm số phần tử bị lặp lại ít nhất 1 lần. Ví dụ với mảng $A[] = \{5, 6, 1, 2, 1, 4\}$ thì ta có đáp án là $2$ vì có $2$ phần tử $1$.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào số phần tử của mảng $N$; dòng tiếp theo là $N$ số $A[i]$ là các phần tử của mảng $A[]$.
- $T, N, A[i]$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le N \le 10^6$; $1 \le A[i] \le 10^6$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>5<br>4 5 1 2 1<br>6<br>10 20 30 30 20 5 | 2<br>4 |

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;
// khoi tao mang tan so 
int freq[1000001];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        // reset lai mang tan so 
        memset(freq,0,sizeof(freq));
        for(int i = 0;i<n;i++){
            cin >> a[i];
            // den luon so lan xuat hien 
            freq[a[i]]++;
        }
        // dem so phan tu lap lai
        int ans = 0;
        for(int i = 0; i< n;i++){
            if(freq[a[i]] > 1) ++ans;
        }
        // in ra tong so phan tu lap lai
        cout << ans << endl;
    }
}
```

------

## Bài 6: Tính giá trị đa thức

Tính toán giá trị đa thức $P(n, x) = a_{n-1}x^{n-1} + a_{n-2}x^{n-2} + \dots + a_0$.

Kết quả có thể rất lớn nên hãy chia dư cho $10^9 + 7$.

### Input
- Dòng đầu tiên đưa vào số lượng test $T$.
- Những dòng kế tiếp đưa vào các bộ test. Mỗi test gồm hai dòng: dòng thứ nhất đưa vào hai số $n, x$; dòng tiếp theo đưa vào $n$ số $a_{n-1}, a_{n-2}, \dots, a_0$ là hệ số của đa thức $P$. Các số được viết cách nhau một vài khoảng trống.
- $T, n, x, P[i]$ thỏa mãn ràng buộc: $1 \le T \le 100$; $0 \le n \le 2000$; $0 \le x, P[i] \le 1000$.
- **Chú ý**: Các hệ số của đa thức $P$ được viết theo thứ tự từ bậc $0$ đến bậc $n-1$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 1<br>4 2<br> | 20 |

### Code 
```cpp
#include <bits/stdc++.h>

using namespace std;
// khoi tao bien de tranh tran so 
const long long MOD = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        // nhap mang
        for(int i = 0; i <n;i++) cin >> a[i];
        int res = 0;
        long long lt = 1;
        // tinh bieu thuc da thuc
        for(int i = n-1; i>=0;i--){
            // % de tranh bi tran so 
            res += (lt*a[i])%MOD;
            lt = (lt*x)%MOD;
        }
        cout << res << endl;
    }
}
```

------

## Bài 7: Kiểm tra dãy Fibo

Cho mảng $A[]$ gồm $n$ số nguyên không âm. Hãy tìm dãy con lớn nhất chỉ toàn các số Fibonacci. Số $0$ được coi là số Fibonacci đầu tiên.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào $n$ là số phần tử của mảng $A[]$; dòng tiếp theo đưa vào $n$ số các phần tử của mảng $A[]$; các số được viết cách nhau một vài khoảng trống.
- $T, n, A[i]$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le n \le 100$; $1 \le A[i] \le 1000$.

### Output
- Đưa ra dãy con lớn nhất bao gồm các số Fibonacci của mỗi test theo từng dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>7<br>1 4 3 9 10 13 7<br>9<br>0 2 8 5 2 1 4 13 23 | 1 3 13<br>0 2 8 5 2 1 13 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// khoi tao mang tan suat
int freq[1000001];
void selve(int a[],int n){
    // khoi tao mang fibo
    int fibo[25];
    // sang so fibo
    fibo[0] = 0;
    fibo[1] = 1;
    // tinh cac so fibo con lai
    for(int i = 2; i<n;i++) fibo[i] = fibo[i-1] + fibo[i-2];
    // gan tan suat nhung so xuat hien trong mang a[n]
    for(int i = 0; i<n;i++){
        freq[fibo[i]] = 1;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        // nhap mang
        for(int i = 0; i <n;i++) cin >> a[i];
        selve(a,n);
        for(int i = 0; i<n;i++){
            // tim cac so fibo trong mang a
            // in ra cac so fibo trong mang a theo thu tu xuat hien 
            if(freq[a[i]] == 1) cout << a[i] << " ";
        }
        cout << endl;
    }
}
```

------

## Bài 8: Hiệu lớn nhất của cặp phần tử đúng thứ tự

Cho mảng $A[]$ gồm $n$ số nguyên. Hãy tìm hiệu lớn nhất của bất kể hai phần tử nào của mảng dãy con thỏa mãn ràng buộc số lớn hơn xuất hiện sau số nhỏ hơn. Nếu không tìm được cặp phần tử của mảng hãy đưa ra $-1$. Ví dụ với mảng $A[] = \{2, 3, 10, 6, 4, 8, 1\}$ ta nhận được kết quả là $8 = 10-2$. Với mảng $A[] = \{7, 9, 5, 6, 3, 2\}$ ta có kết quả là $2 = 9-7$.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào $n$ là số phần tử của mảng $A[]$; dòng kế tiếp đưa vào $n$ số $A[i]$ của mảng; các số được viết cách nhau một vài khoảng trống.
- $T, n, A[i]$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le n \le 10^3$; $1 \le A[i] \le 10^5$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>7<br>2 3 10 6 4 8 1<br>3<br>3 2 1 | 8<br>-1 |

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
        int a[n];
        // nhap mang 
        for(int i = 0;i < n;i++) cin >> a[i];
        // khoi tao bien nho nhat va hieu 
        int min_val = a[0], res = -1e9;
        for(int i = 1; i < n;i++){
            // neu a[i] lon hon min_val thi tinh hieu va gan vao res
            if(a[i] > min_val) res = max(res,a[i] - min_val);
            // cap nhat lai min_val de tim cap tiep theo 
            // de tim a[j] - a[i] lon nhat thi a[i] nho nhat 
            // tu do ta luon nho nhat 
            min_val = min(min_val,a[i]);
        }
        // neu res khong thay doi nghia la khong tim duoc cap 
        cout << (res == -1e9? -1:res)<< endl;
    } 
}
```

------

## Bài 9: Dãy con trung bình lớn nhất

Cho mảng $A[]$ gồm $n$ số và số nguyên dương $k$. Hãy tìm dãy con liên tục độ dài $k$ có giá trị trung bình các phần tử lớn nhất. Ví dụ với $A[] = \{ 1, 12, -5, -6, 50, 3\}$ và $k = 4$ ta có câu trả lời là $\{12, -5, -6, 50\}$ có trung bình các phần tử lớn nhất là $(12-5-6+50)/4=12.75$.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng $n$ và số $k$; dòng tiếp theo là $n$ số $A[i]$ của mảng $A[]$; các số được viết cách nhau một vài khoảng trống.
- $T, n, k, A[i]$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le k \le n \le 10^3$; $-10^3 \le A[i] \le 10^3$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>5 2<br>10 4 5 15 20<br>4 2<br>-12 34 56 7 | 15 20<br>34 56 |

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i<n;i++) cin >> a[i];
        int sum = 0;
        // tinh tong k phan tu dau tien 
        for(int i = 0; i<k;i++) sum += a[i];
        // khoi tao bien ki luc va idx bat dau ki luc
        int res = sum, idx = 0;
        for(int i = k; i<n;i++){
            // cua so truot gia tri
            sum = sum - a[i-k] + a[i];
            // kiem tra ki luc
            if(res < sum){
                res = sum;
                idx = i - k + 1; // bien bat dau
            }
        }
        // in ra day con trung binh lon nhat 
        for(int i = idx;i<k;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
```

------

## Bài 10: Số nhỏ nhất lớn hơn A[i]

Cho mảng $A[]$ gồm $n$ phần tử. Nhiệm vụ của bạn là tìm giá trị nhỏ nhất lớn hơn $A[i]$ ($i=0, 1, 2,\dots, n-1$). Đưa ra `_` nếu $A[i]$ không có phần tử lớn hơn nó. Ví dụ với mảng $A[] = \{13, 6, 7, 12\}$, ta có kết quả là `_ 7 12 13`.


### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào $n$ là số phần tử của mảng $A[]$; dòng kế tiếp đưa vào $n$ số $A[i]$ của mảng; các số được viết cách nhau một vài khoảng trống.
- $T, n, A[i]$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le n \le 10^6$; $-10^6 \le A[i] \le 10^6$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>9<br>6 3 9 8 10 2 1 15 7<br>4<br>13 6 7 12 | 7 6 10 9 15 3 2 _ 8<br>_ 7 12 13 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> v(a, a + n); // copy noi dung mang a cho vector v
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++){
            // su dung upper bound de tim so nho nhat lon hon a[i] 
            // upper bound tra ve con tro den phan tu nho nhat lon hon a[i]
            // neu khong tim duoc thi tra ve v.end()
            auto it = upper_bound(v.begin(), v.end(), a[i]);
            if(it == v.end()){
                cout << "_ ";
            }
            else cout << (*it) << " ";
        }
        cout << endl;
    }
}
```
