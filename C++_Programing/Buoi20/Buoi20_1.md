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