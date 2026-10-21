# Thuật Toán Sắp Xếp Chèn | Sắp Xếp Nổi Bọt | Sắp Xếp Chọn | Sắp Xếp Đếm Phân Phối\

## 1. Thuật Toán Sắp Xếp Chọn (Selection Sort)

- Ý tưởng : Ở mỗi bước của thuật toán luôn đưa phần tử nhỏ nhất về vị trí đầu tiên của phần chưa được sắp xếp.

- Độ phức tạp : $O(n^2)$

- Mã giả :
```
SelectionSort(array A)
Input: một mảng số thực A
Output: mảng A được sắp xếp
for i from 0 to n-2 do
  min_index = i
  for j from i+1 to n-1 do
    if A[j] < A[min_index] then
      min_index = j
  end if
  end for
  Swap(A[i], A[min_index])
end for
end
```

- Cài đặt :
```cpp
// thuat toan sap xep chon
void selection_sort(vector<int> &a)
{
  int n = a.size();
  // duyet qua mang
  for (int i = 0; i < n-1; i++){
    // dung mot bien de luu chi so cua phan tu nho nhat
    int min_idx = i;
    // duyet qua phan chua sap xep
    for (int j = i + 1; j < n; j++){
        // neu tim thay phan tu nho nhat thi luu chi so cua no vao bien min_idx
        if (a[j] < a[min_idx]){
            min_idx = j;
        }
    }
    // hoan doi vi tri cua phan tu nho nhat voi phan tu hien tai
    swap(a[i], a[min_idx]);
  }
}
```

---

### Minh họa chi tiết từng bước chạy thuật toán

- **Giả sử mảng ban đầu:** `arr = [20, 12, 10, 15, 2]` ($n = 5$)

#### • Bước 1 ($i = 0$):
```text
Index:       0         1         2         3         4
        ┌─────────┬─────────┬─────────┬─────────┬─────────┐
Array:  │   20    │   12    │   10    │   15    │    2    │
        └─────────┴─────────┴─────────┴─────────┴─────────┘
             ↑         │────────── j duyệt ──────────>│
            i=0                                       ↑
                                                  min_idx=4 (arr[4] = 2)

➜ swap(arr[0], arr[4]) ➔ Hoán đổi 20 ⇄ 2
➜ Mảng sau bước 1: [ 2 | 12, 10, 15, 20 ] (cố định index 0)
```

#### • Bước 2 ($i = 1$):
```text
Index:       0         1         2         3         4
        ┌─────────┬─────────┬─────────┬─────────┬─────────┐
Array:  │    2    │   12    │   10    │   15    │   20    │
        └─────────┴─────────┴─────────┴─────────┴─────────┘
        [ cố định ]    ↑         │───── j duyệt ─────>│
                      i=1        ↑                    │
                             min_idx=2 (arr[2] = 10) j=4

➜ swap(arr[1], arr[2]) ➔ Hoán đổi 12 ⇄ 10
➜ Mảng sau bước 2: [ 2, 10 | 12, 15, 20 ] (cố định index 0, 1)
```

#### • Bước 3 ($i = 2$):
```text
Index:       0         1         2         3         4
        ┌─────────┬─────────┬─────────┬─────────┬─────────┐
Array:  │    2    │   10    │   12    │   15    │   20    │
        └─────────┴─────────┴─────────┴─────────┴─────────┘
        [---- đã cố định ----]   ↑         │── j ───>│
                                i=2                  ↑
                            (min_idx=2)             j=4

➜ swap(arr[2], arr[2]) ➔ Giữ nguyên vị trí (12 là nhỏ nhất trong đoạn còn lại)
➜ Mảng sau bước 3: [ 2, 10, 12 | 15, 20 ] (cố định index 0, 1, 2)
```

#### • Bước 4 ($i = 3$):
```text
Index:       0         1         2         3         4
        ┌─────────┬─────────┬─────────┬─────────┬─────────┐
Array:  │    2    │   10    │   12    │   15    │   20    │
        └─────────┴─────────┴─────────┴─────────┴─────────┘
        [--------- đã cố định ---------]   ↑          ↑
                                          i=3        j=4
                                      (min_idx=3)

➜ swap(arr[3], arr[3]) ➔ Giữ nguyên vị trí
➜ Kết quả cuối cùng: [ 2, 10, 12, 15, 20 ] (Mảng đã được sắp xếp tăng dần hoàn tất)
```

- Code minh họa :

```cpp
#include <iostream>
using namespace std;

// xay dung ham swap
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void selection_sort(int arr[], int n){
    // duyet qua mang 1 chieu 
    for(int i  = 0; i<n-1;i++){
        // khoi tao bien luu chi so nho nhat 
        int min_idx = i;
        // duyet tiep cac phan sau i 
        // kiem tra xem phan tu nao nho hon de swap
        for(int j = i + 1;j<n;j++){
            // neu sap xep giam dan thi doi lai dau < thanh >
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        // hoan doi vi tri cua phan tu nho nhat voi phan tu hien tai
        swap(arr[i],arr[min_idx]);
    } 
}

int main(){
    // khoi tao mang 1 chieu 
    int arr[] = {20,12,10,15,2};
    // tinh chieu dai mang 
    int n = sizeof(arr) / sizeof(arr[0]);
    // sap xep mang 
    selection_sort(arr,n);
    // in ra mang 
    for(int i = 0; i<n;i++){
        cout << arr[i] << " ";
    }
    // ket qua : 2 10 12 15 20
}
```

## 2. Thuật toán Sắp xếp nổi bọt ( Bubble Sort)

- Ý tưởng : Thuật toán so sánh các cặp phần tử kề nhau và đổi chỗ nếu chúng sai thứ tự. Lặp lại quá trình này cho đến khi mảng được sắp xếp.

- Độ phức tạp : $O(n^2)$

- Có nhiều cách triển khai như swap 2 phần tử cuối hay swap 2 phần tử đầu nhưng kết quả cuối cùng vẫn như nhau

- Nếu triển khai duyệt từ phẩn tử  đầu. Ở mỗi bước thuật toán sẽ có thêm 1 phần tử được sắp xếp và đưa cuối dãy, ở các bước tiếp theo phần tử sẽ không được xét lại nữa

- Mã giả :

```text
bubbleSort(array)
  // lap qua mang cho den khi no duoc sap xep 
  for i <- 1 to indexOfLastUnsortedElement-1
    // so sanh hai phan tu lien tiep
    if leftElement > rightElement
      // neu sai thu tu thi hoan doi 
      swap leftElement and rightElement
end bubbleSort
```

- Code : 
```cpp
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
void bubble_sort(int arr[], int n){
    // duyet qua mang 
    for(int i = 0; i < n-1; i++){
        // duyet cac phan tu chua duoc sap xep o dau mang
        for(int j = 0; j < n-i-1; j++){
            // neu phan tu truoc lon hon phan tu sau thi hoan doi (sap xep tang dan)
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
```

- **Ví dụ mô phỏng:** Cho mảng `arr = {8, 2, 3, 9, 7, 1, 4}` ($n = 7$)

---

### Mô phỏng trực quan từng bước bằng sơ đồ mảng (Array Diagrams)

#### 🔹 Vòng lặp 1: Xét $i = 0$ ($j = 0 \to 5$)

```text
• Bước 1 (j = 0): So sánh arr[0] và arr[1] (8 > 2) ➔ swap(8, 2)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 8 │ 2 │ 3 │ 9 │ 7 │ 1 │ 4 │
    └───┴───┴───┴───┴───┴───┴───┘
      ╰───╯
      swap

• Bước 2 (j = 1): So sánh arr[1] và arr[2] (8 > 3) ➔ swap(8, 3)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 8 │ 3 │ 9 │ 7 │ 1 │ 4 │
    └───┴───┴───┴───┴───┴───┴───┘
          ╰───╯
          swap

• Bước 3 (j = 2): So sánh arr[2] và arr[3] (8 < 9) ➔ Đúng thứ tự (giữ nguyên)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 8 │ 9 │ 7 │ 1 │ 4 │
    └───┴───┴───┴───┴───┴───┴───┘
              ╰───╯
              true

• Bước 4 (j = 3): So sánh arr[3] và arr[4] (9 > 7) ➔ swap(9, 7)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 8 │ 9 │ 7 │ 1 │ 4 │
    └───┴───┴───┴───┴───┴───┴───┘
                  ╰───╯
                  swap

• Bước 5 (j = 4): So sánh arr[4] và arr[5] (9 > 1) ➔ swap(9, 1)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 8 │ 7 │ 9 │ 1 │ 4 │
    └───┴───┴───┴───┴───┴───┴───┘
                      ╰───╯
                      swap

• Bước 6 (j = 5): So sánh arr[5] và arr[6] (9 > 4) ➔ swap(9, 4)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 8 │ 7 │ 1 │ 9 │ 4 │
    └───┴───┴───┴───┴───┴───┴───┘
                          ╰───╯
                          swap

➜ Kết thúc vòng i = 0: Số lớn nhất [9] đã nổi về cuối mảng tại index 6!
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 8 │ 7 │ 1 │ 4 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
                            [chốt]
```

---

#### 🔹 Vòng lặp 2: Xét $i = 1$ ($j = 0 \to 4$)

```text
• Bước 1 (j = 0): So sánh arr[0] và arr[1] (2 < 3) ➔ Đúng thứ tự
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 8 │ 7 │ 1 │ 4 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
      ╰───╯
      true

• Bước 2 (j = 1): So sánh arr[1] và arr[2] (3 < 8) ➔ Đúng thứ tự
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 8 │ 7 │ 1 │ 4 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
          ╰───╯
          true

• Bước 3 (j = 2): So sánh arr[2] và arr[3] (8 > 7) ➔ swap(8, 7)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 8 │ 7 │ 1 │ 4 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
              ╰───╯
              swap

• Bước 4 (j = 3): So sánh arr[3] và arr[4] (8 > 1) ➔ swap(8, 1)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 7 │ 8 │ 1 │ 4 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
                  ╰───╯
                  swap

• Bước 5 (j = 4): So sánh arr[4] và arr[5] (8 > 4) ➔ swap(8, 4)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 7 │ 1 │ 8 │ 4 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
                      ╰───╯
                      swap

➜ Kết thúc vòng i = 1: Số lớn nhì [8] đã về đúng vị trí tại index 5!
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 7 │ 1 │ 4 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
                        [--chốt--]
```

---

#### 🔹 Vòng lặp 3: Xét $i = 2$ ($j = 0 \to 3$)

```text
• Bước 1 (j = 0): So sánh arr[0] và arr[1] (2 < 3) ➔ Đúng thứ tự
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 7 │ 1 │ 4 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
      ╰───╯
      true

• Bước 2 (j = 1): So sánh arr[1] và arr[2] (3 < 7) ➔ Đúng thứ tự
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 7 │ 1 │ 4 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
          ╰───╯
          true

• Bước 3 (j = 2): So sánh arr[2] và arr[3] (7 > 1) ➔ swap(7, 1)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 7 │ 1 │ 4 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
              ╰───╯
              swap

• Bước 4 (j = 3): So sánh arr[3] và arr[4] (7 > 4) ➔ swap(7, 4)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 1 │ 7 │ 4 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
                  ╰───╯
                  swap

➜ Kết thúc vòng i = 2: Số [7] đã về đúng vị trí tại index 4!
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 1 │ 4 │ 7 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
                    [---chốt---]
```

---

#### 🔹 Vòng lặp 4: Xét $i = 3$ ($j = 0 \to 2$)

```text
• Bước 1 (j = 0): So sánh arr[0] và arr[1] (2 < 3) ➔ Đúng thứ tự
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 1 │ 4 │ 7 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
      ╰───╯
      true

• Bước 2 (j = 1): So sánh arr[1] và arr[2] (3 > 1) ➔ swap(3, 1)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 3 │ 1 │ 4 │ 7 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
          ╰───╯
          swap

• Bước 3 (j = 2): So sánh arr[2] và arr[3] (3 < 4) ➔ Đúng thứ tự
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 1 │ 3 │ 4 │ 7 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
              ╰───╯
              true

➜ Kết thúc vòng i = 3: Số [4] đã về đúng vị trí tại index 3!
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 1 │ 3 │ 4 │ 7 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
                [----chốt----]
```

---

#### 🔹 Vòng lặp 5: Xét $i = 4$ ($j = 0 \to 1$)

```text
• Bước 1 (j = 0): So sánh arr[0] và arr[1] (2 > 1) ➔ swap(2, 1)
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 2 │ 1 │ 3 │ 4 │ 7 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
      ╰───╯
      swap

• Bước 2 (j = 1): So sánh arr[1] và arr[2] (2 < 3) ➔ Đúng thứ tự
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 1 │ 2 │ 3 │ 4 │ 7 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
          ╰───╯
          true

➜ Kết thúc vòng i = 4: Số [3] đã về đúng vị trí tại index 2!
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 1 │ 2 │ 3 │ 4 │ 7 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
            [-----chốt-----]
```

---

#### 🔹 Vòng lặp 6: Xét $i = 5$ ($j = 0$)

```text
• Bước 1 (j = 0): So sánh arr[0] và arr[1] (1 < 2) ➔ Đúng thứ tự
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 1 │ 2 │ 3 │ 4 │ 7 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
      ╰───╯
      true

KẾT QUẢ CUỐI CÙNG: Mảng đã hoàn tất sắp xếp tăng dần!
      0   1   2   3   4   5   6
    ┌───┬───┬───┬───┬───┬───┬───┐
    │ 1 │ 2 │ 3 │ 4 │ 7 │ 8 │ 9 │
    └───┴───┴───┴───┴───┴───┴───┘
    [======== ĐÃ HOÀN TẤT ========]
```

- Code 
```cpp
#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

// thuat toan sap xep noi bot 
void bubble_sort(int a[], int n){
    // duyet qua mang 
    for(int i = 0; i<n;i++){
        // duyet cac phan tu tu dau den n - i - 1
        for(int j =0;j < n - i - 1;j++){
            // so sanh tang dan
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}
int main(){
    int a[] = {1,2,1,3,4,6,7,8,9};
    int n = sizeof(a)/sizeof(a[0]);
    bubble_sort(a,n);
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
```

## 3. Thuật toán sắp xếp chèn (insertion sort)

- Ý tưởng : Ở mỗi bước của thuật toán sẽ cố  gắng đưa phần tử  ở vị trí đúng bằng chèn nó vào dãy các phần tử  đứng trước nó sao cho đúng thứ tự

- Độ phức tạp : $O(n^2)$

- Mã giả : 
```text
insertionSort(array)
  // đánh dấu phần tử đầu tiên là đã được sắp xếp
  mark first element as sorted
  for each unsorted element X
    'extract' the element X
    // duyệt ngược từ phải sang trái các phần tử đã được sắp xếp
    for j <- lastSortedIndex down to 0
      // nếu phần tử hiện tại lớn hơn X 
      if current element j > X
        // dịch sang phải 1 ô để tạo chỗ trống cho X
        move sorted element to the right by 1
    // chèn X vào vị trí thích hợp
    break loop and insert X here
end insertionSort
```
- Code : 
```cpp
#include <iostream>
using namespace std;

void insertion_sort(int a[], int n){
    // Lap qua tung phan tu tu chi so 1 den n - 1
    for(int i = 1; i < n; i++){
        // Lay ra phan tu can chen (Key)
        int key = a[i];
        // duyet cac phan tu truoc i 
        int j = i - 1;
        // Duyet nguoc ve dau mang va dich phai cac phan tu lon hon key
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j]; // dich phai 1 o
            j--;
        }
        // Chen key vao vi tri thich hop
        a[j + 1] = key;
    }
}
```

- **Ví dụ mô phỏng:** Cho mảng ban đầu `a = {9, 5, 1, 4, 3}` ($n = 5$)

---

### Mô phỏng trực quan từng bước bằng sơ đồ mảng (Array Diagrams)

```text
• Mảng ban đầu:
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 9 │ 5 │ 1 │ 4 │ 3 │
    └───┴───┴───┴───┴───┘
```

#### 🔹 Bước 1: Xét phần tử tại $i = 1 \Rightarrow \text{Key} = 5$

```text
1. Trích xuất Key = 5:
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 9 │ 5 │ 1 │ 4 │ 3 │
    └───┴─┬─┴───┴───┴───┘
          │
          ▼
       Key = [5]

2. So sánh với phần tử trước đó:
   • j = 0: a[0] = 9 > 5 (Key) ➔ Dịch 9 sang phải ô kế tiếp (index 1)
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 9 │ 9 │ 1 │ 4 │ 3 │
    └───┴─▲─┴───┴───┴───┘
      └───┘ (dịch phải)

3. j = -1 (< 0) ➔ Dừng vòng lặp, chèn Key = 5 vào vị trí index 0:
      0   1 ┊ 2   3   4
    ┌───┬───┼───┬───┬───┐
    │ 5 │ 9 │ 1 │ 4 │ 3 │
    └───┴───┴───┴───┴───┘
      ▲
      │ (chèn Key = 5 vào đây)
```
*(Sau bước 1: Đoạn đã sắp xếp gồm 2 phần tử `[5, 9]`)*

---

#### 🔹 Bước 2: Xét phần tử tại $i = 2 \Rightarrow \text{Key} = 1$

```text
1. Trích xuất Key = 1:
      0   1 ┊ 2   3   4
    ┌───┬───┼───┬───┬───┐
    │ 5 │ 9 │ 1 │ 4 │ 3 │
    └───┴───┴─┬─┴───┴───┘
              │
              ▼
           Key = [1]

2. So sánh và dịch các phần tử lớn hơn Key:
   • j = 1: a[1] = 9 > 1 (1 < 9 nên dịch phải 9 vào index 2)
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 5 │ 9 │ 9 │ 4 │ 3 │
    └───┴───┴─▲─┴───┴───┘
          └───┘ (dịch phải)

   • j = 0: a[0] = 5 > 1 (1 < 5 nên dịch phải 5 vào index 1)
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 5 │ 5 │ 9 │ 4 │ 3 │
    └───┴─▲─┴───┴───┴───┘
      └───┘ (dịch phải)

3. j = -1 (< 0) ➔ Dừng vòng lặp, chèn Key = 1 vào vị trí index 0:
      0   1   2 ┊ 3   4
    ┌───┬───┬───┼───┬───┐
    │ 1 │ 5 │ 9 │ 4 │ 3 │
    └───┴───┴───┴───┴───┘
      ▲
      │ (chèn Key = 1 vào đây)
```
*(Sau bước 2: Đoạn đã sắp xếp gồm 3 phần tử `[1, 5, 9]`)*

---

#### 🔹 Bước 3: Xét phần tử tại $i = 3 \Rightarrow \text{Key} = 4$

```text
1. Trích xuất Key = 4:
      0   1   2 ┊ 3   4
    ┌───┬───┬───┼───┬───┐
    │ 1 │ 5 │ 9 │ 4 │ 3 │
    └───┴───┴───┴─┬─┴───┘
                  │
                  ▼
               Key = [4]

2. So sánh và dịch các phần tử lớn hơn Key:
   • j = 2: a[2] = 9 > 4 (4 < 9 nên dịch phải 9 vào index 3)
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 1 │ 5 │ 9 │ 9 │ 3 │
    └───┴───┴───┴─▲─┴───┘
              └───┘ (dịch phải)

   • j = 1: a[1] = 5 > 4 (4 < 5 nên dịch phải 5 vào index 2)
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 1 │ 5 │ 5 │ 9 │ 3 │
    └───┴───┴─▲─┴───┴───┘
          └───┘ (dịch phải)

   • j = 0: a[0] = 1 < 4 (1 < 4 nên dừng lặp, chèn 4 sang bên phải của 1 tại index 1)

3. Chèn Key = 4 vào vị trí index 1:
      0   1   2   3 ┊ 4
    ┌───┬───┬───┬───┼───┐
    │ 1 │ 4 │ 5 │ 9 │ 3 │
    └───┴─▲─┴───┴───┴───┘
          │ (chèn Key = 4 vào đây)
```
*(Sau bước 3: Đoạn đã sắp xếp gồm 4 phần tử `[1, 4, 5, 9]`)*

---

#### 🔹 Bước 4: Xét phần tử tại $i = 4 \Rightarrow \text{Key} = 3$

```text
1. Trích xuất Key = 3:
      0   1   2   3 ┊ 4
    ┌───┬───┬───┬───┼───┐
    │ 1 │ 4 │ 5 │ 9 │ 3 │
    └───┴───┴───┴───┴─┬─┘
                      │
                      ▼
                   Key = [3]

2. So sánh và dịch các phần tử lớn hơn Key:
   • j = 3: a[3] = 9 > 3 (3 < 9 nên dịch phải 9 vào index 4)
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 1 │ 4 │ 5 │ 9 │ 9 │
    └───┴───┴───┴───┴─▲─┘
                  └───┘ (dịch phải)

   • j = 2: a[2] = 5 > 3 (3 < 5 nên dịch phải 5 vào index 3)
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 1 │ 4 │ 5 │ 5 │ 9 │
    └───┴───┴───┴─▲─┴───┘
              └───┘ (dịch phải)

   • j = 1: a[1] = 4 > 3 (3 < 4 nên dịch phải 4 vào index 2)
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 1 │ 4 │ 4 │ 5 │ 9 │
    └───┴───┴─▲─┴───┴───┘
          └───┘ (dịch phải)

   • j = 0: a[0] = 1 < 3 (3 > 1 nên dừng lặp, chèn 3 sang bên phải của 1 tại index 1)

3. Chèn Key = 3 vào vị trí index 1:
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 1 │ 3 │ 4 │ 5 │ 9 │
    └───┴─▲─┴───┴───┴───┘
          │ (chèn Key = 3 vào đây)
```

---

➜ **Kết quả cuối cùng:** Mảng hoàn tất sắp xếp tăng dần:
```text
      0   1   2   3   4
    ┌───┬───┬───┬───┬───┐
    │ 1 │ 3 │ 4 │ 5 │ 9 │
    └───┴───┴───┴───┴───┘
```

## 4. THuật toán sắp xếp đếm phân phối (Counting sort)

- **Ý tưởng** : Thuật toán Counting sort hoạt động bằng cách đếm số lần xuất hiện của mỗi phần tử trong mảng đầu vào, sau đó sử dụng thông tin này để đặt các phần tử vào đúng vị trí trong mảng đầu ra.

- **Điều kiện sử dụng** : Thuật toán này chỉ hoạt động được khi các phần tử trong mảng đầu vào là các số nguyên không âm và có phạm vi giá trị nhỏ (trong phạm vi bộ nhớ có sẵn).

- **Độ phức tạp** : $O(n + k)$, trong đó $n$ là số lượng phần tử trong mảng đầu vào và $k$ là phạm vi giá trị của các phần tử trong mảng đầu vào.

```cpp
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n];
    // khoi tao mang dem 
    int cnt[n] = {0};
    // khoi tao bien luu gia tri lon nhat
    int max_val = INT_MIN;
    // nhap ma tran 
    for(int i =0;i<n;i++){
        cin >> a[i];
        cnt[a[i]]++;
        // tim gia tri phan tu max
        max_val = max(max_val, a[i]);
    }
    // duyet tu 1 den max_val de tinh tong du luy
    for(int i =1;i<max_val;i++){
        // neu khac 0 tuc la co xuat hien 
        if(cnt[i] != 0) {
            // In ra so lan xuat hien 
            for(int j = 0;j<cnt[i];j++){
                cout << i << " ";
            }
        }
    }
}
```