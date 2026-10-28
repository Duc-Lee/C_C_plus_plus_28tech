# Hướng Dẫn Giải Bài Tập Thuật Toán Sắp Xếp Và Tìm Kiếm (Phần 1)

## Bài 1. Thuật toán đổi chỗ trực tiếp

In ra các bước của thuật toán sắp xếp đổi chỗ trực tiếp.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 4<br>5 7 3 2 | Buoc 1: 2 7 5 3<br>Buoc 2: 2 3 7 5<br>Buoc 3: 2 3 5 7 |

### Code : 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    // dung thuat toan sap xep noi bot
    for(int i =0;i<n-1;i++){
        // duyet cac ptu sau i 
        for(int j = i + 1; j <n;j++){
            if(a[i] > a[j]){
                // doi cho ptu 
                swap(a[i], a[j]);
            }
        }
    }
    // in ra cac buoc sap xep 
    for(int i =0;i<n-1;i++){
        cout << "Buoc " << i + 1 << ": ";
        for(int j = 0; j <n;j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

```

## Bài 2. Thuật toán sắp xếp chọn

In ra các bước của thuật toán sắp xếp chọn.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 4<br>5 7 3 2 | Buoc 1: 2 7 3 5<br>Buoc 2: 2 3 7 5<br>Buoc 3: 2 3 5 7 |

### Code 
```cpp
#include <bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min_index]){
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    selection_sort(a, n);
    for(int i = 0; i < n - 1; i++){
        cout << "Buoc " << i + 1 << ": ";
        for(int j = 0; j < n; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## Bài 3. Thuật toán sắp xếp chèn

In ra các bước của thuật toán sắp xếp chèn.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 4<br>5 7 3 2 | Buoc 0: 5<br>Buoc 1: 5 7<br>Buoc 2: 3 5 7<br>Buoc 3: 2 3 5 7 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        // khi nao j lon hon hoac bang 0 va a[j] lon hon key thi dich mang sang phai de tao khoang trong cho key 
        while(j >= 0 && a[j] > key){
            // dich mang sang phai 
            a[j+1] = a[j];
            j--;
        }
        // gan gia tri cua key vao vi tri hien tai 
        a[j+1] = key;
    }
}
    

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    insertion_sort(a, n);
    for(int i = 0; i < n; i++){
        cout << "Buoc " << i << ": ";
        for(int j = 0; j < i + 1; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## Bài 4. Thuật toán sắp xếp nổi bọt

In ra các bước của thuật toán sắp xếp nổi bọt.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 4<br>5 3 2 7 | Buoc 1: 3 2 5 7<br>Buoc 2: 2 3 5 7 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        bool ok = false;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                ok = true;
            }
        }
        // cu xong moi lan lap noi bot i 
        // thi in ra mang 
        // neu trong lan lap khong co su trao doi nao xay ra thi dung thuat toan 
        if(ok){
            cout << "Buoc " << i + 1 << ": ";
            for(int j = 0; j < n; j++){
                cout << a[j] << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    bubble_sort(a, n);
    return 0;
}
```

## Bài 5. Thuật toán tìm kiếm tuyến tính

Kiểm tra xem phần tử x có nằm trong mảng hay không, nếu có in ra 1, ngược lại in ra 0.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 5 3<br>1 2 3 4 5 | 1 |
| 6 4<br>1 1 2 0 7 8 | 0 |

### Code 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int &i : a) cin >> i;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
```

## Bài 6. Thuật toán tìm kiếm nhị phân

Kiểm tra xem phần tử x có nằm trong mảng đã được sắp xếp hay không? Nếu có in ra 1, ngược lại in ra 0.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 5 3<br>1 2 3 4 5 | 1 |
| 6 4<br>0 1 1 2 7 8 | 0 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int n, int x){
    int left = 0;
    int right = n - 1;
    while(left <= right){
        // lay phan tu o giua mang 
        int mid = left + (right - left) / 2;
        // neu phan tu o giua bang x thi tra ve vi tri cua no 
        if(a[mid] == x){
            return mid;
        }
        // neu phan tu o giua nho hon x thi tim o nua ben phai 
        if(a[mid] < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    int x;
    cin >> x;
    if(binary_search(a, n, x) != -1){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}
```

## Bài 7. Vị trí đầu tiên

Cho mảng số nguyên đã được sắp xếp tăng dần và số nguyên $x$. Tìm vị trí xuất hiện đầu tiên của $x$ trong mảng hoặc xác định rằng nó không tồn tại.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng:
  - Dòng đầu tiên là số phần tử của mảng $n$ và phần tử $x$.
  - Dòng tiếp theo là $n$ số $A[i]$ của mảng $A[]$; các số được viết cách nhau một vài khoảng trống.
- Ràng buộc: $1 \le T \le 100$; $1 \le n \le 10^3$.

### Output
- In ra vị trí xuất hiện đầu tiên của $x$ trong mảng (chỉ số tính từ 1), in ra `-1` nếu $x$ không nằm trong mảng.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 2<br>5 3<br>1 2 3 3 3<br>5 4<br>1 1 2 5 6 | 3<br>-1 |

### Code 
```cpp
#include <bits/stdc++.h>
using namespace std;

int first_occurrence1(int a[], int n, int x){
    // duyet qua mang de tim vi tri xuat hien dau tien cua x 
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}

// Phuong phap 2 : O(logn)
int first_occurrence2(int a[], int n, int x){
    int left = 0, right = n - 1; 
    // khoi tao bien ket qua index tim kiem x 
    int ans = -1;
    // dung thuat toan binary search 
    while(left <= right){
        int mid = left + (right - left) / 2; 
        if(a[mid] == x){
            // neu phan tu o giua bang x thi 
            ans = mid;
            // tiep tuc tiem mang trai xem con x khong 
            right = mid - 1; 
        }else if (a[mid] < x){
            // neu phan tu o giua nho hon x thi tim o nua ben phai 
            left = mid + 1; 
        }else{
            // neu phan tu o giua lon hon x thi tim o nua ben trai 
            right = mid - 1;
        }
    }
    return ans;
}

// Phuong phap 3 :dung binary search cai tien  
int first_occurrence3(int a[], int n, int x){
    // dung ham co san trong c++ 
    int *res = lower_bound(a,a+n,x);
    // check dieu kien 
    if(res != a + n && *res == x) {
        // neu tim thay x thi tra ve index
        return res - a;
    }
    return -1;
}    
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n];
        for(int &i : a) cin >> i;
        cout << "Phuong phap 1 (O(n)): " << first_occurrence1(a, n, x) << endl;
        cout << "Phuong phap 2 (O(logn)): " << first_occurrence2(a, n, x) << endl;
        cout << "Phuong phap 3 (O(logn)): " << first_occurrence3(a, n, x) << endl;
    }
}
```

## Bài 8. Vị trí cuối cùng

Cho mảng số nguyên đã được sắp xếp tăng dần và số nguyên $x$. Tìm vị trí xuất hiện cuối cùng của $x$ trong mảng hoặc xác định rằng nó không tồn tại.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng:
  - Dòng đầu tiên là số phần tử của mảng $n$ và phần tử $x$.
  - Dòng tiếp theo là $n$ số $A[i]$ của mảng $A[]$; các số được viết cách nhau một vài khoảng trống.
- $T, n$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le n \le 10^3$.

### Output
- In ra vị trí xuất hiện cuối cùng của $x$ trong mảng (chỉ số tính từ 1), in ra `-1` nếu $x$ không nằm trong mảng.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 2<br>5 3<br>1 2 3 3 3<br>5 4<br>1 1 2 5 6 | 5<br>-1 |

### Code
```cpp
```cpp
#include <bits/stdc++.h>
using namespace std;

// Phuong phap 1 : O(logn)
int first_occurrence2(int a[], int n, int x){
    int left = 0, right = n - 1; 
    // khoi tao bien ket qua index tim kiem x 
    int ans = -1;
    // dung thuat toan binary search 
    while(left <= right){
        int mid = left + (right - left) / 2; 
        if(a[mid] == x){
            // neu phan tu o giua bang x thi 
            ans = mid;
            // tiep tuc tiem mang phai xem con x khong 
            left = mid + 1; 
        }else if (a[mid] < x){
            // neu phan tu o giua nho hon x thi tim o nua ben phai 
            left = mid + 1; 
        }else{
            // neu phan tu o giua lon hon x thi tim o nua ben trai 
            right = mid - 1;
        }
    }
    return ans;
}

// Phuong phap 2 :dung binary search cai tien  
int first_occurrence3(int a[], int n, int x){
    // dung ham co san trong c++ 
    int *res = upper_bound(a,a+n,x);
    // check dieu kien 
    if(res != a + n && *res == x) {
        // neu tim thay x thi tra ve index
        return res - a;
    }
    return -1;
}    
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n];
        for(int &i : a) cin >> i;
        cout << "Phuong phap 2 (O(logn)): " << first_occurrence2(a, n, x) << endl;
        cout << "Phuong phap 3 (O(logn)): " << first_occurrence3(a, n, x) << endl;
    }
}
```

## Bài 9. Đếm số lần xuất hiện của phần tử trong mảng sắp xếp

Cho mảng số nguyên đã được sắp xếp tăng dần và số nguyên $x$. Đếm số lần xuất hiện của $x$ trong mảng.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng:
  - Dòng đầu tiên là số phần tử của mảng $n$ và phần tử $x$.
  - Dòng tiếp theo là $n$ số $A[i]$ của mảng $A[]$; các số được viết cách nhau một vài khoảng trống.
- $T, n$ thỏa mãn ràng buộc: $1 \le T \le 100$; $1 \le n \le 10^3$.

### Output
- In ra số lần xuất hiện của $x$ trong mảng.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 2<br>5 3<br>1 2 3 3 3<br>5 4<br>1 1 2 5 6 | 3<br>0 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// Phuong phap 1 : Duyet tuyen tinh 
int freq_array(int a[], int n,int x){
    // khoi tao mang mp 
    unordered_map<int,int> mp;
    // duyet lan luot cac phan tu 
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
    }
    return mp[x];
}

// Phuong phap 2 : Dung Binary search 
int freq_binarysearch(int a[], int n, int x){
    //  lay vi tri xuat hien dau tien cua x
    int left = lower_bound(a,a+n,x);
    // lay vi tri xuat hien cuoi cung cua x 
    int right = upper_bound(a,a+n,x);
    // check dieu kien 
    if(left == right){
        return 0;
    }
    // tra ve so lan xuat hien 
    return right - left +1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n];
        for(int &i : a) cin >> i;
        cout << "Phuong phap 1 (O(n)): " << freq_array(a, n, x) << endl;
        cout << "Phuong phap 2 (O(logn)): " << freq_binarysearch(a, n, x) << endl;
    }
    return 0; 
}
```

## Bài 10. Quick Sort

Để sắp xếp tăng dần một mảng $A$ gồm $n$ phần tử $a_1, a_2, \dots, a_n$, thuật toán sắp xếp nhanh (QuickSort) áp dụng phân hoạch để chia mảng $A$ thành hai mảng con $B$ và $C$ sao cho $b_i \le c_j$ (với mọi $i, j$). Có nhiều thuật toán phân hoạch, một trong số đó là thuật toán Lomuto. Thuật toán thực hiện như sau:
- Chọn phần tử cuối của mảng $A$ làm chốt phân hoạch.
- Duyệt qua các phần tử của mảng $A$ từ phần tử đầu đến phần tử kế cuối. Nếu phần tử nào nhỏ hơn hoặc bằng chốt thì hoán vị về đầu (đưa vào mảng $B$).
- Hoán vị chốt vào giữa sao cho chốt là phần tử phân định giữa $B$ và $C$.

**Ví dụ minh họa:** Phân hoạch 8 phần tử: `8 7 2 1 5 3 6 4`. Chọn chốt phân hoạch là `4`.
- Hoán vị 2 về đầu: `2 7 8 1 5 3 6 [4]`
- Hoán vị 1 về đầu: `2 1 8 7 5 3 6 [4]`
- Hoán vị 3 về đầu: `2 1 3 7 5 8 6 [4]`
- Hoán vị chốt vô giữa: `2 1 3 [4] 5 8 6 7`
*(Các phần tử $\le 4$ là mảng $B$, các phần tử còn lại $\ge 4$ là mảng $C$)*

Cho một mảng $n$ phần tử bất kỳ, bạn hãy phân hoạch mảng trên dùng thuật toán Lomuto.

### Input
- Dòng đầu tiên là số nguyên $n$ ($2 \le n \le 20$) là số phần tử của mảng.
- Dòng tiếp theo gồm $n$ số nguyên $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 100$), mỗi số cách nhau một khoảng trắng.

### Output
- Là một dòng gồm $n$ phần tử sau khi đã phân hoạch, mỗi phần tử cách nhau một khoảng trắng. Phần tử chốt được đánh dấu bằng cặp dấu `[]`.

### Ví dụ:

| Input | Output |
| :--- | :--- |
| 8<br>8 7 2 1 5 3 6 4 | 2 1 3 [4] 5 8 6 7 |

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// ham phan hoach 
int partition(int a[], int l, int r){
    // chon phan tu pivot 
    int pivot = a[r];
    // khoi tao con tro mang 
    int i = l - 1; 
    for(int j =0;j<r;j++){
        // kiem tra dieu kien 
        // lam sao cac phan tu dau < hon pivot
        if(pivot >= a[j]){
            // neu be hon thi tang i len 
            ++i;
            // swap 
            swap(a[i],a[j]);
        }
        // cac phan tu > pivot se bo qua cau lenh if
        // i se duyet cac phan tu ay 
    }
    // tang i len phan tu > pivot dau tien 
    ++i; 
    swap(a[i], pivot);
    return i;
}

// ham quicksort
void quicksort(int a[], int l, int r){
    // de quy de sap xep mang 
    if(l >= r) return;
    int mid = partition(a,l,r);
    // in ra phan tu sau khi da phan hoach 
    for(int i = l; i <= r; i++){
        // lam sao in ra phan tu pivot 
        if(i == mid){
            cout << "[" << a[i] << "] ";
        }else{
            cout << a[i] << " ";
        }
    }
    cout << endl;
    // de quy de sap xep mang con ben trai 
    quicksort(a,l,mid-1);
    // de quy de sap xep mang con ben phai 
    quicksort(a,mid+1,r);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    quicksort(a,0,n-1);
    for(int &i : a) cout << i << " ";
    return 0;
}
```

## Bài 11 : 