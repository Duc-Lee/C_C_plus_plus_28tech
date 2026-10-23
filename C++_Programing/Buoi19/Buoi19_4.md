# Thuật Toán Sắp Xếp Nhanh QuickSort | Phân Hoạch Lomuto Và Phân Hoạch Hoare

- Độ phức tạp : $O(n \log n)$

- Trường hợp tốt nhất : $O(n \log n)$

- Trường hợp xấu nhất : $O(n^2)$

- Không ổn định

- Tư tưởng : Thuật toán áp dụng phương pháp chia và trị:
  - **Chia (Divide)**: Phân hoạch (sắp xếp lại) mảng $A[p \dots r]$ thành hai mảng con (có thể rỗng) $A[p \dots q - 1]$ và $A[q + 1 \dots r]$ sao cho mỗi phần tử của $A[p \dots q - 1]$ đều nhỏ hơn hoặc bằng $A[q]$, và $A[q]$ nhỏ hơn hoặc bằng mỗi phần tử của $A[q + 1 \dots r]$. Chỉ số $q$ được tính toán trong quá trình phân hoạch này.
  - **Trị (Conquer)**: Sắp xếp hai mảng con $A[p \dots q - 1]$ và $A[q + 1 \dots r]$ bằng cách gọi đệ quy thuật toán quicksort.
  - **Kết hợp (Combine)**: Do các mảng con đã được sắp xếp xong, ta không cần làm thêm thao tác nào để kết hợp chúng: toàn bộ mảng $A[p \dots r]$ đã được sắp xếp hoàn tất.

## 1. Thuật toán QuickSort với phân hoạch Lomuto 

- Phân hoạch Lomuto là thuật toán phân hoạch mảng thành 2 phần, phần bên trái chốt đều nhỏ hơn chốt, phần bên phải chốt đều lớn hơn chốt, phần tử chốt cuối mảng (chọn pivot là phần tử cuối của mảng)
- Mã giả :

```text
Lomuto(A, l, r):
    x = A[r]
    i = l-1
    for j = l to r-1:
        if A[j] <= x:
            i = i+1
            swap(A[i], A[j])
    swap(A[i+1], A[r])
    return i+1
```

- Ví dụ minh họa phân hoạch Lomuto :

```text
                                                            Pivot
                                                            ↓
                        ┌───┬────┬───┬───┬───┬───┬────┬───┬───┐
                        │ 9 │ -3 │ 5 │ 2 │ 6 │ 8 │ -6 │ 1 │ 3 │
                        └───┴────┴───┴───┴───┴───┴────┴───┴───┘
                                       /               \
                                      /                 \
                                     /                   \
                       (<= 3)       /                     \       (>= 3)
                                   ↓                       ↓
                       ┌────┬───┬────┬───┐       ┌───┐       ┌───┬───┬───┬───┐
                       │ -3 │ 2 │ -6 │ 1 │       │ 3 │       │ 8 │ 5 │ 9 │ 6 │
                       └────┴───┴────┴───┘       └───┘       └───┴───┴───┴───┘
                                       ↑                                     ↑
                                     Pivot                                 Pivot
                                    /     \                               /     \
                                   /       \                             /       \
                     (<= 1)       /         \ (>= 1)       (<= 6)       /         \ (>= 6)
                                 ↓           ↓                         ↓           ↓
                   ┌────┬────┐     ┌───┐     ┌───┐       ┌───┐     ┌───┐     ┌───┬───┐
                   │ -3 │ -6 │     │ 1 │     │ 2 │       │ 5 │     │ 6 │     │ 9 │ 8 │
                   └────┴────┘     └───┘     └───┘       └───┘     └───┘     └───┴───┘
                            ↑                                                       ↑
                          Pivot                                                   Pivot
                         /     \                                                 /     \
             (<= -6)    /       \ (>= -6)                            (<= 8)     /       \ (>= 8)
                       ↓         ↓                                             ↓         ↓
                     ┌────┐   ┌────┐                                         ┌───┐     ┌───┐
                     │ -6 │   │ -3 │                                         │ 8 │     │ 9 │
                     └────┘   └────┘                                         └───┘     └───┘
```

- Mã giả phân hoạch Lomuto (PARTITION):

```text
PARTITION(A, p, r)
1  x = A[r]
2  i = p - 1
3  for j = p to r - 1
4      if A[j] <= x
5          i = i + 1
6          exchange A[i] with A[j]
7  exchange A[i + 1] with A[r]
8  return i + 1
```

- Minh họa từng bước phân hoạch Lomuto :

Cho mảng: $a[] = [2, 8, 7, 1, 5, 3, 6, 4]$  ($l = 0, r = 7$, $\text{pivot} = a[r] = 4$)

### Phân đoạn lần 1 :

#### • Bước 1: Khởi tạo
- $i = -1, l = 0, r = 7$
- $j = 0$

```text
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
        └───┴───┴───┴───┴───┴───┴───┴───┘
          ↑                           ↑
        j = 0                       pivot
(i = -1)
```

#### • Bước 2: Xét $j = 0$
- $a[j] = 2 \le 4 \Rightarrow i++ \ (i = 0)$
- $\text{swap}(a[i], a[j]) = \text{swap}(2, 2)$

```text
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
        └───┴───┴───┴───┴───┴───┴───┴───┘
          ↑   ↑                       ↑
        i=0  j=1                    pivot
```

#### • Bước 3: Xét $j = 1$
- $a[j] = 8 > 4 \Rightarrow \text{continue}$

```text
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
        └───┴───┴───┴───┴───┴───┴───┴───┘
          ↑       ↑                   ↑
        i=0      j=2                pivot
```

#### • Bước 4: Xét $j = 2$
- $a[j] = 7 > 4 \Rightarrow \text{continue}$

```text
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
        └───┴───┴───┴───┴───┴───┴───┴───┘
          ↑           ↑               ↑
        i=0          j=3            pivot
```

#### • Bước 5: Xét $j = 3$
- $a[j] = 1 \le 4 \Rightarrow i++ \ (i = 1)$
- $\text{swap}(a[i], a[j]) = \text{swap}(8, 1)$

```text
- Trước khi swap:
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
        └───┴───┴───┴───┴───┴───┴───┴───┘
              ↑       ↑               ↑
             i=1     j=3            pivot

- Sau khi swap:
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 1 │ 7 │ 8 │ 5 │ 3 │ 6 │ 4 │
        └───┴───┴───┴───┴───┴───┴───┴───┘
              ↑           ↑           ↑
             i=1         j=4        pivot
```

#### • Bước 6: Xét $j = 4$
- $a[j] = 5 > 4 \Rightarrow \text{continue}$

```text
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 1 │ 7 │ 8 │ 5 │ 3 │ 6 │ 4 │
        └───┴───┴───┴───┴───┴───┴───┴───┘
              ↑               ↑       ↑
             i=1             j=5    pivot
```

#### • Bước 7: Xét $j = 5$
- $a[j] = 3 \le 4 \Rightarrow i++ \ (i = 2)$
- $\text{swap}(a[i], a[j]) = \text{swap}(7, 3)$

```text
- Trước khi swap:
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 1 │ 7 │ 8 │ 5 │ 3 │ 6 │ 4 │
        └───┴───┴───┴───┴───┴───┴───┴───┘
                  ↑           ↑       ↑
                 i=2         j=5    pivot

- Sau khi swap:
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 1 │ 3 │ 8 │ 5 │ 7 │ 6 │ 4 │
        └───┴───┴───┴───┴───┴───┴───┴───┘
                  ↑               ↑   ↑
                 i=2             j=6 pivot
```

#### • Bước 8: Xét $j = 6$
- $a[j] = 6 > 4 \Rightarrow \text{continue}$
- $j$ đã duyệt hết từ $l$ đến $r - 1$ ($j = 6 \Rightarrow$ Kết thúc vòng lặp $j$)

```text
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 1 │ 3 │ 8 │ 5 │ 7 │ 6 │ 4 │   (Kết thúc vòng lặp j)
        └───┴───┴───┴───┴───┴───┴───┴───┘
                  ↑                   ↑
                 i=2                pivot
```

- **Sau khi kết thúc vòng lặp $j$:**
  - $i++ \Rightarrow i = 3$
  - $\text{swap}(a[i], \text{pivot}) = \text{swap}(a[3], a[7]) = \text{swap}(8, 4)$

```text
Mảng sau khi đưa Pivot về đúng vị trí:
Index:    0   1   2   3   4   5   6   7
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 1 │ 3 │ 4 │ 5 │ 7 │ 6 │ 8 │
        └───┴───┴───┴───┴───┴───┴───┴───┘
                      ↑
                 Chốt cố định
```

$\Rightarrow$ **Kết quả phân hoạch Lomuto lần 1:**

```text
                 ┌───┬───┬───┬───┬───┬───┬───┬───┐
                 │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
                 └───┴───┴───┴───┴───┴───┴───┴───┘
                       /           │           \
                      /            │            \
                     ↓             ↓             ↓
                ┌───┬───┬───┐    ┌───┐    ┌───┬───┬───┬───┐
                │ 2 │ 1 │ 3 │    │ 4 │    │ 5 │ 7 │ 6 │ 8 │
                └───┴───┴───┘    └───┘    └───┴───┴───┴───┘
                    (< 4)        (Chốt)         (> 4)
```

- Tiếp tục phân hoạch các mảng con cho đến khi chỉ còn 1 phần tử.

### Code 
```cpp
// ham phan doan 
int partition(int a[], int l, int r){
    // khoi tao phan tu pivot
    int pivot = a[r]
    // khoi tao bien i 
    int i = l - 1;
    // duyet qua mang 
    for(int j = 0; j < r; j++){
        // neu phan tu a[j] nho hon pivot 
        // swap 2 phan tu do  
        if(a[j] <= pivot){
            ++i; // tang bien len 
            swap(a[i],a[j]);
        }
    }
    // tang bien i len 
    ++i;
    // swap pivot voi phan tu dau tien > pivot
    swap(a[i],pivot);
    // tra ve index cua pivot sau khi chuyen vo giua 2 mang 
    return i;
}

// thuat toan sap xep nhanh 
void quicksort(int a[], int l, int r){
    // dieu kien dung 
    if(l >= r) return;
    // gan index privot 
    // phan doan mang 
    int p = partition(a,l,r);
    // goi de quy voi mang < privot
    quicksort(a,l,p-1);
    // goi de quy voi mang > privot
    quicksort(a,p+1,r);
    // luu y phai bo qua phan tu chot p khi goi de quy 
}
```

## 2. Thuật toán Quicksort với phân hoạch Hoare

- Phân hoạch Hoare là thuật toán phân hoạch Quicksort được viết bởi C.A.R. Hoare. Ý tưởng là muốn tìm ra cặp nghịch thế $(A[i], A[j])$ thỏa mãn $A[i] > A[j]$ và $i < j$, từ đó thực hiện việc hoán vị hai phần tử này để mảng dần được sắp xếp. 

- Thuật toán này thường nhanh hơn Lomuto một chút vì nó thực hiện ít phép hoán vị hơn. Nhưng đổi lại thuật toán này khó cài đặt hơn và không ổn định.

- Mã giả : 

```text
HOARE-PARTITION(A, p, r)
1  x = A[p]
2  i = p - 1
3  j = r + 1
4  while TRUE
5      repeat
6          j = j - 1
7      until A[j] <= x
8      repeat
9          i = i + 1
10     until A[i] >= x
11     if i < j
12         exchange A[i] with A[j]
13     else return j
```

- Chọn privot ở đây chọn phần tử  đầu tiên, cũng có thể  chọn cuối cùng hoặc trung bình 

- Code : 
```cpp
// phan hoach mang 
int partition(int a[], int l, int r){
    // khoi tao pivot la phan tu dau tien mang 
    int pivot = a[l];
    // khoi tao 2 con tro 
    int i = l - 1; 
    int j = r + 1;
    // 2 con tro nay nen tro ngoai 
    // lap mang 
    while(1){
        // neu a[i] < pivot
        // tuc la phan ay nam dung vi tri
        // tang bien i len 
        do{
            ++i;
        }while(a[i] < pivot);
        // neu a[j] > pivot 
        // tuc la phan tu ay nam dung vi tri ben phai pivot 
        // giam bien j 
        do{
            --j;
        }while(a[j] > pivot);
        // dung do while de luon tang truoc i, j 1 lan truoc khi kiem tả dieu kien 
        // khi 2 con tro giao nhau tuc la da tim duoc giao diem 
        // neu i < j 
        // swap 2 phan tu 
        if( i < j){
            // swap vi 
            swap(a[i],a[j]);
        }else{
            // neu i > j 
            // tuc la da qua giao diem 
            // tra ve vi tri j 
            // vi tri j la vi tri can de chia cat 
            // de chia thanh 2 mang 
            // mang 1 la < pivot o ben trai j 
            // mang 2 la > pivot o ben phai j 
            return j;
        }
    }
}

// ham sap xep nhanh hoare 
void quicksort(int a[], int l, int r){
    // dieu kien dung 
    if(l >= r) return;
    // gan index privot 
    // phan doan mang 
    int p = partition(a,l,r);
    // goi de quy voi mang < privot
    quicksort(a,l,p);
    // goi de quy voi mang > privot
    quicksort(a,p+1,r);
    // luu y khac voi lomuto o day la khong tru p 
}
```

### Mô phỏng chi tiết thuật toán Hoare Partition

- **Ví dụ mảng ban đầu:** $a = [2, 8, 7, 1, 5, 3, 6, 4]$ với $n = 8$ (chỉ số từ $0 \to 7$).
- **Chiến lược:** Chọn **Pivot** là phần tử đầu tiên của phân đoạn hiện tại ($pivot = a[l]$).

---

## Phân đoạn lần 1: Trên toàn bộ mảng `a[0..7]`

### Bước 1: Khởi tạo con trỏ và Pivot
- $l = 0, \ r = 7$
- $i = l - 1 = -1$ *(nằm ngoài biên trái)*
- $j = r + 1 = 8$ *(nằm ngoài biên phải)*
- $\text{pivot} = a[l] = a[0] = 2$

```text
Index:      0   1   2   3   4   5   6   7
          ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:        │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
          └───┴───┴───┴───┴───┴───┴───┴───┘
            ↑
        pivot = 2
(i = -1)                                 (j = 8)
```

---

### Bước 2: Vòng lặp `while(1)` – Lần lặp 1

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i$ lên 1: $i = 0$
- Kiểm tra điều kiện: $a[i] < \text{pivot} \iff a[0] < 2 \ (2 < 2)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 0$**.

```text
Index:      0   1   2   3   4   5   6   7
          ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:        │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
          └───┴───┴───┴───┴───┴───┴───┴───┘
            ↑
        pivot, i=0
```

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 7 \Rightarrow a[7] = 4 > 2$ (**True**, tiếp tục)
- Giảm $j$ đi 1: $j = 6 \Rightarrow a[6] = 6 > 2$ (**True**, tiếp tục)
- Giảm $j$ đi 1: $j = 5 \Rightarrow a[5] = 3 > 2$ (**True**, tiếp tục)
- Giảm $j$ đi 1: $j = 4 \Rightarrow a[4] = 5 > 2$ (**True**, tiếp tục)
- Giảm $j$ đi 1: $j = 3 \Rightarrow a[3] = 1 > 2$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 3$**.

```text
Index:      0   1   2   3   4   5   6   7
          ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:        │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
          └───┴───┴───┴───┴───┴───┴───┴───┘
            ↑           ↑
        pivot, i=0     j=3
```

#### 3. Kiểm tra điều kiện đổi chỗ:
- So sánh chỉ số: $i < j \ (0 < 3)$ $\Rightarrow$ **Đúng**
- Thực hiện: $\text{swap}(a[i], a[j]) \iff \text{swap}(a[0], a[3])$ *(đổi chỗ 2 và 1)*

```text
Mảng sau khi hoán đổi a[0] và a[3]:
Index:      0   1   2   3   4   5   6   7
          ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:        │ 1 │ 8 │ 7 │ 2 │ 5 │ 3 │ 6 │ 4 │
          └───┴───┴───┴───┴───┴───┴───┴───┘
            ↑           ↑
           i=0         j=3
```

---

### Bước 3: Vòng lặp `while(1)` – Lần lặp 2

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i$ lên 1: $i = 1$
- Kiểm tra: $a[i] < \text{pivot} \iff a[1] < 2 \ (8 < 2)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 1$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 2 \Rightarrow a[2] = 7 > 2$ (**True**, tiếp tục)
- Giảm $j$ đi 1: $j = 1 \Rightarrow a[1] = 8 > 2$ (**True**, tiếp tục)
- Giảm $j$ đi 1: $j = 0 \Rightarrow a[0] = 1 > 2$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 0$**.

```text
Index:      0   1   2   3   4   5   6   7
          ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:        │ 1 │ 8 │ 7 │ 2 │ 5 │ 3 │ 6 │ 4 │
          └───┴───┴───┴───┴───┴───┴───┴───┘
            ↑   ↑
           j=0 i=1
```

#### 3. Kiểm tra điều kiện dừng:
- So sánh: $i < j \ (1 < 0)$ $\Rightarrow$ **Sai** ($i \ge j$, hai con trỏ đã bắt chéo nhau)
- Rơi vào nhánh `else`: **`return j`** $\Rightarrow$ Trả về **$j = 0$** ($p = 0$).

---

### Kết quả sau phân hoạch lần 1 và Call Stack

```text
Mảng ban đầu:
                    ┌───┬───┬───┬───┬───┬───┬───┬───┐
                    │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
                    └───┴───┴───┴───┴───┴───┴───┴───┘
                                   │
                      Phân hoạch Hoare (p = j = 0)
                                   ▼
               ┌───┐                       ┌───┬───┬───┬───┬───┬───┬───┐
               │ 1 │                       │ 8 │ 7 │ 2 │ 5 │ 3 │ 6 │ 4 │
               └───┘                       └───┴───┴───┴───┴───┴───┴───┘
          quicksort(a, 0, 0)                     quicksort(a, 1, 7)
          (l >= r -> return)
```

#### Mô hình ngăn xếp (Call Stack):
```text
│                         │        │                         │
│   quicksort(a, 0, 0)    │  pop   │                         │
├─────────────────────────┤ ────►  ├─────────────────────────┤
│   quicksort(a, 0, 7)    │        │   quicksort(a, 1, 7)    │  ◄── Đang xử lý tiếp
└─────────────────────────┘        └─────────────────────────┘
```

---

## Phân đoạn lần 2: Trên mảng con `a[1..7]`

Mảng con đang xét: `[8, 7, 2, 5, 3, 6, 4]` nằm ở vị trí từ chỉ số $1 \to 7$.

### Bước 1: Khởi tạo con trỏ và Pivot
- $l = 1, \ r = 7$
- $i = l - 1 = 0$
- $j = r + 1 = 8$
- $\text{pivot} = a[l] = a[1] = 8$

```text
Index:      0   1   2   3   4   5   6   7
          ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:        │ 1 │ 8 │ 7 │ 2 │ 5 │ 3 │ 6 │ 4 │
          └───┴───┴───┴───┴───┴───┴───┴───┘
                ↑
            pivot = 8
 (i = 0)                                 (j = 8)
```

---

### Bước 2: Vòng lặp `while(1)` – Lần lặp 1

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i$ lên 1: $i = 1$
- Kiểm tra: $a[i] < \text{pivot} \iff a[1] < 8 \ (8 < 8)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 1$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 7$
- Kiểm tra: $a[j] > \text{pivot} \iff a[7] > 8 \ (4 > 8)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 7$**.

```text
Index:      0   1   2   3   4   5   6   7
          ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:        │ 1 │ 8 │ 7 │ 2 │ 5 │ 3 │ 6 │ 4 │
          └───┴───┴───┴───┴───┴───┴───┴───┘
                ↑                       ↑
            pivot, i=1                 j=7
```

#### 3. Kiểm tra điều kiện đổi chỗ:
- So sánh: $i < j \ (1 < 7)$ $\Rightarrow$ **Đúng**
- Thực hiện: $\text{swap}(a[1], a[7]) \iff \text{swap}(8, 4)$

```text
Mảng sau khi hoán đổi a[1] và a[7]:
Index:      0   1   2   3   4   5   6   7
          ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:        │ 1 │ 4 │ 7 │ 2 │ 5 │ 3 │ 6 │ 8 │
          └───┴───┴───┴───┴───┴───┴───┴───┘
                ↑                       ↑
               i=1                     j=7
```

---

### Bước 3: Vòng lặp `while(1)` – Lần lặp 2

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i = 2 \Rightarrow a[2] = 7 < 8$ (**True**, tiếp tục)
- Tăng $i = 3 \Rightarrow a[3] = 2 < 8$ (**True**, tiếp tục)
- Tăng $i = 4 \Rightarrow a[4] = 5 < 8$ (**True**, tiếp tục)
- Tăng $i = 5 \Rightarrow a[5] = 3 < 8$ (**True**, tiếp tục)
- Tăng $i = 6 \Rightarrow a[6] = 6 < 8$ (**True**, tiếp tục)
- Tăng $i = 7 \Rightarrow a[7] = 8 < 8$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 7$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 6$
- Kiểm tra: $a[6] = 6 > 8$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 6$**.

```text
Index:      0   1   2   3   4   5   6   7
          ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:        │ 1 │ 4 │ 7 │ 2 │ 5 │ 3 │ 6 │ 8 │
          └───┴───┴───┴───┴───┴───┴───┴───┘
                                        ↑   ↑
                                       j=6 i=7
```

#### 3. Kiểm tra điều kiện dừng:
- So sánh: $i < j \ (7 < 6)$ $\Rightarrow$ **Sai** ($i \ge j$)
- Rơi vào nhánh `else`: **`return j`** $\Rightarrow$ Trả về **$j = 6$** ($p = 6$).

---

### Kết quả sau 2 lần phân đoạn

```text
                             ┌───┬───┬───┬───┬───┬───┬───┬───┐
                             │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
                             └───┴───┴───┴───┴───┴───┴───┴───┘
                                            │
                                  Lần 1: p = j = 0
                                            ▼
                       ┌───┐                               ┌───┬───┬───┬───┬───┬───┬───┐
                       │ 1 │                               │ 8 │ 7 │ 2 │ 5 │ 3 │ 6 │ 4 │
                       └───┘                               └───┴───┴───┴───┴───┴───┴───┘
                 quicksort(a, 0, 0)                                      │
                      (Xong)                                   Lần 2: p = j = 6
                                                                         ▼
                                                    ┌───┬───┬───┬───┬───┬───┐        ┌───┐
                                                    │ 4 │ 7 │ 2 │ 5 │ 3 │ 6 │        │ 8 │
                                                    └───┴───┴───┴───┴───┴───┘        └───┘
                                                       quicksort(a, 1, 6)      quicksort(a, 7, 7)
                                                        (Tiếp tục đệ quy)            (Xong)
```

#### Trạng thái Call Stack sau lần 2:
```text
│                         │
│   quicksort(a, 1, 6)    │  ◄── Đang xử lý tiếp tục
├─────────────────────────┤
│   quicksort(a, 7, 7)    │  ◄── Chờ trong ngăn xếp
├─────────────────────────┤
│   quicksort(a, 1, 7)    │
├─────────────────────────┤
│   quicksort(a, 0, 7)    │
└─────────────────────────┘
```

---

## Phân đoạn lần 3: Trên mảng con `[4, 7, 2, 5, 3]`

### Bước 1: Khởi tạo con trỏ và Pivot
- Xét theo chỉ số cục bộ $0 \to 4$:
- $i = -1$ *(nằm ngoài biên trái)*
- $j = 5$ *(nằm ngoài biên phải)*
- $\text{pivot} = a[0] = 4$

```text
Index:      0   1   2   3   4
          ┌───┬───┬───┬───┬───┐
a:        │ 4 │ 7 │ 2 │ 5 │ 3 │
          └───┴───┴───┴───┴───┘
            ↑
        pivot = 4
(i = -1)                     (j = 5)
```

---

### Bước 2: Vòng lặp `while(1)` – Lần lặp 1

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i$ lên 1: $i = 0$
- Kiểm tra điều kiện: $a[i] < \text{pivot} \iff a[0] < 4 \ (4 < 4)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 0$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 4$
- Kiểm tra điều kiện: $a[j] > \text{pivot} \iff a[4] > 4 \ (3 > 4)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 4$**.

```text
Index:      0   1   2   3   4
          ┌───┬───┬───┬───┬───┐
a:        │ 4 │ 7 │ 2 │ 5 │ 3 │
          └───┴───┴───┴───┴───┘
            ↑               ↑
        pivot, i=0         j=4
```

#### 3. Kiểm tra điều kiện đổi chỗ:
- So sánh: $i < j \ (0 < 4)$ $\Rightarrow$ **Đúng**
- Thực hiện: $\text{swap}(a[0], a[4]) \iff \text{swap}(4, 3)$

```text
Mảng sau khi hoán đổi a[0] và a[4]:
Index:      0   1   2   3   4
          ┌───┬───┬───┬───┬───┐
a:        │ 3 │ 7 │ 2 │ 5 │ 4 │
          └───┴───┴───┴───┴───┘
            ↑               ↑
           i=0         pivot, j=4
```

---

### Bước 3: Vòng lặp `while(1)` – Lần lặp 2

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i$ lên 1: $i = 1$
- Kiểm tra điều kiện: $a[i] < \text{pivot} \iff a[1] < 4 \ (7 < 4)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 1$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 3 \Rightarrow a[3] = 5 > 4$ (**True**, tiếp tục)
- Giảm $j$ đi 1: $j = 2 \Rightarrow a[2] = 2 > 4$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 2$**.

```text
Index:      0   1   2   3   4
          ┌───┬───┬───┬───┬───┐
a:        │ 3 │ 7 │ 2 │ 5 │ 4 │
          └───┴───┴───┴───┴───┘
                ↑   ↑       ↑
               i=1 j=2    pivot
```

#### 3. Kiểm tra điều kiện đổi chỗ:
- So sánh: $i < j \ (1 < 2)$ $\Rightarrow$ **Đúng**
- Thực hiện: $\text{swap}(a[1], a[2]) \iff \text{swap}(7, 2)$

```text
Mảng sau khi hoán đổi a[1] và a[2]:
Index:      0   1   2   3   4
          ┌───┬───┬───┬───┬───┐
a:        │ 3 │ 2 │ 7 │ 5 │ 4 │
          └───┴───┴───┴───┴───┘
                ↑   ↑       ↑
               i=1 j=2    pivot
```

---

### Bước 4: Vòng lặp `while(1)` – Lần lặp 3

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i$ lên 1: $i = 2$
- Kiểm tra điều kiện: $a[i] < \text{pivot} \iff a[2] < 4 \ (7 < 4)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 2$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 1$
- Kiểm tra điều kiện: $a[j] > \text{pivot} \iff a[1] > 4 \ (2 > 4)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 1$**.

```text
Index:      0   1   2   3   4
          ┌───┬───┬───┬───┬───┐
a:        │ 3 │ 2 │ 7 │ 5 │ 4 │
          └───┴───┴───┴───┴───┘
                ↑   ↑       ↑
               j=1 i=2    pivot
```

#### 3. Kiểm tra điều kiện dừng:
- So sánh: $i < j \ (2 < 1)$ $\Rightarrow$ **Sai** ($i \ge j$, hai con trỏ đã bắt chéo nhau)
- Rơi vào nhánh `else`: **`return j`** $\Rightarrow$ Trả về **$j = 1$** ($p = 1$).

---

### Kết quả sau 3 lần phân đoạn

```text
                             ┌───┬───┬───┬───┬───┬───┬───┬───┐
                             │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
                             └───┴───┴───┴───┴───┴───┴───┴───┘
                                            │
                                  Lần 1: p = j = 0
                                            ▼
                       ┌───┐                               ┌───┬───┬───┬───┬───┬───┬───┐
                       │ 1 │                               │ 8 │ 7 │ 2 │ 5 │ 3 │ 6 │ 4 │
                       └───┘                               └───┴───┴───┴───┴───┴───┴───┘
                 quicksort(a, 0, 0)                                      │
                      (Xong)                                   Lần 2: p = j = 6
                                                                         ▼
                                                    ┌───┬───┬───┬───┬───┬───┐        ┌───┐
                                                    │ 4 │ 7 │ 2 │ 5 │ 3 │ 6 │        │ 8 │
                                                    └───┴───┴───┴───┴───┴───┘        └───┘
                                                               │
                                                     Lần 3: p = j = 1
                                                               ▼
                                                    ┌───┬───┐        ┌───┬───┬───┐
                                                    │ 3 │ 2 │        │ 7 │ 5 │ 4 │
                                                    └───┴───┘        └───┴───┴───┘
```

#### Trạng thái Call Stack sau lần 3:
```text
│                         │
│   quicksort mảng [3, 2] │  ◄── Đang xử lý tiếp tục
├─────────────────────────┤
│   quicksort mảng [7,5,4]│  ◄── Chờ trong ngăn xếp
├─────────────────────────┤
│   quicksort(a, 1, 6)    │
├─────────────────────────┤
│   quicksort(a, 7, 7)    │
├─────────────────────────┤
│   quicksort(a, 1, 7)    │
├─────────────────────────┤
│   quicksort(a, 0, 7)    │
└─────────────────────────┘
```

---

## Phân đoạn lần 4: Trên mảng con `[3, 2]`

### Bước 1: Khởi tạo con trỏ và Pivot
- Xét theo chỉ số cục bộ $0 \to 1$:
- $i = -1$
- $j = 2$
- $\text{pivot} = a[0] = 3$

```text
Index:      0   1
          ┌───┬───┐
a:        │ 3 │ 2 │
          └───┴───┘
            ↑
        pivot = 3
(i = -1)         (j = 2)
```

---

### Bước 2: Vòng lặp `while(1)` – Lần lặp 1

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i$ lên 1: $i = 0$
- Kiểm tra điều kiện: $a[i] < \text{pivot} \iff a[0] < 3 \ (3 < 3)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 0$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 1$
- Kiểm tra điều kiện: $a[j] > \text{pivot} \iff a[1] > 3 \ (2 > 3)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 1$**.

```text
Index:      0   1
          ┌───┬───┐
a:        │ 3 │ 2 │
          └───┴───┘
            ↑   ↑
           i=0 j=1
```

#### 3. Kiểm tra điều kiện đổi chỗ:
- So sánh: $i < j \ (0 < 1)$ $\Rightarrow$ **Đúng**
- Thực hiện: $\text{swap}(a[0], a[1]) \iff \text{swap}(3, 2)$

```text
Mảng sau khi hoán đổi a[0] và a[1]:
Index:      0   1
          ┌───┬───┐
a:        │ 2 │ 3 │
          └───┴───┘
            ↑   ↑
           i=0 j=1
```

---

### Bước 3: Vòng lặp `while(1)` – Lần lặp 2

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i$ lên 1: $i = 1$
- Kiểm tra điều kiện: $a[i] < \text{pivot} \iff a[1] < 3 \ (3 < 3)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 1$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 0$
- Kiểm tra điều kiện: $a[j] > \text{pivot} \iff a[0] > 3 \ (2 > 3)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 0$**.

```text
Index:      0   1
          ┌───┬───┐
a:        │ 2 │ 3 │
          └───┴───┘
            ↑   ↑
           j=0 i=1
```

#### 3. Kiểm tra điều kiện dừng:
- So sánh: $i < j \ (1 < 0)$ $\Rightarrow$ **Sai** ($i \ge j$)
- Rơi vào nhánh `else`: **`return j`** $\Rightarrow$ Trả về **$j = 0$** ($p = 0$).

---

### Kết quả phân hoạch nhánh `[3, 2]`
- Chia thành 2 mảng con:
  - Nhánh trái: mảng con `[2]` (1 phần tử $\Rightarrow l \ge r \Rightarrow$ dừng).
  - Nhánh phải: mảng con `[3]` (1 phần tử $\Rightarrow l \ge r \Rightarrow$ dừng).
- Nhánh `[3, 2]` được sắp xếp hoàn tất thành **`[2, 3]`**.

#### Trạng thái Call Stack sau lần 4:
```text
Gọi quicksort([2]) -> l >= r -> pop
Gọi quicksort([3]) -> l >= r -> pop
Hoàn thành quicksort([3, 2])  -> pop

│                         │
│   quicksort mảng [7,5,4]│  ◄── Lấy ra khỏi ngăn xếp để xử lý (Lần 5)
├─────────────────────────┤
│   quicksort(a, 1, 6)    │
├─────────────────────────┤
│   quicksort(a, 7, 7)    │
├─────────────────────────┤
│   quicksort(a, 1, 7)    │
├─────────────────────────┤
│   quicksort(a, 0, 7)    │
└─────────────────────────┘
```

---

## Phân đoạn lần 5: Trên mảng con `[7, 5, 4]`

### Bước 1: Khởi tạo con trỏ và Pivot
- Xét theo chỉ số cục bộ $0 \to 2$:
- $i = -1$
- $j = 3$
- $\text{pivot} = a[0] = 7$

```text
Index:      0   1   2
          ┌───┬───┬───┐
a:        │ 7 │ 5 │ 4 │
          └───┴───┴───┘
            ↑
        pivot = 7
(i = -1)             (j = 3)
```

---

### Bước 2: Vòng lặp `while(1)` – Lần lặp 1

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i$ lên 1: $i = 0$
- Kiểm tra điều kiện: $a[i] < \text{pivot} \iff a[0] < 7 \ (7 < 7)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 0$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 2$
- Kiểm tra điều kiện: $a[j] > \text{pivot} \iff a[2] > 7 \ (4 > 7)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 2$**.

```text
Index:      0   1   2
          ┌───┬───┬───┐
a:        │ 7 │ 5 │ 4 │
          └───┴───┴───┘
            ↑       ↑
           i=0     j=2
```

#### 3. Kiểm tra điều kiện đổi chỗ:
- So sánh: $i < j \ (0 < 2)$ $\Rightarrow$ **Đúng**
- Thực hiện: $\text{swap}(a[0], a[2]) \iff \text{swap}(7, 4)$

```text
Mảng sau khi hoán đổi a[0] và a[2]:
Index:      0   1   2
          ┌───┬───┬───┐
a:        │ 4 │ 5 │ 7 │
          └───┴───┴───┘
            ↑       ↑
           i=0     j=2
```

---

### Bước 3: Vòng lặp `while(1)` – Lần lặp 2

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i = 1 \Rightarrow a[1] = 5 < 7$ (**True**, tiếp tục)
- Tăng $i = 2 \Rightarrow a[2] = 7 < 7$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 2$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 1$
- Kiểm tra điều kiện: $a[1] > \text{pivot} \iff 5 > 7$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 1$**.

```text
Index:      0   1   2
          ┌───┬───┬───┐
a:        │ 4 │ 5 │ 7 │
          └───┴───┴───┘
                ↑   ↑
               j=1 i=2
```

#### 3. Kiểm tra điều kiện dừng:
- So sánh: $i < j \ (2 < 1)$ $\Rightarrow$ **Sai** ($i \ge j$)
- Rơi vào nhánh `else`: **`return j`** $\Rightarrow$ Trả về **$j = 1$** ($p = 1$).

---

### Kết quả phân hoạch nhánh `[7, 5, 4]`
- Chia thành 2 mảng con:
  - Nhánh trái: mảng con `[4, 5]`.
  - Nhánh phải: mảng con `[7]` (1 phần tử $\Rightarrow$ dừng).

#### Trạng thái Call Stack sau lần 5:
```text
Push quicksort([7])   (Chờ nhánh phải)
Push quicksort([4, 5]) (Xử lý nhánh trái trước)

│                         │
│   quicksort mảng [4, 5] │  ◄── Đang xử lý tiếp tục (Lần 6)
├─────────────────────────┤
│   quicksort mảng [7]    │  ◄── Chờ trong ngăn xếp
├─────────────────────────┤
│   quicksort mảng [7,5,4]│
├─────────────────────────┤
│   quicksort(a, 1, 6)    │
├─────────────────────────┤
│   quicksort(a, 7, 7)    │
├─────────────────────────┤
│   quicksort(a, 1, 7)    │
├─────────────────────────┤
│   quicksort(a, 0, 7)    │
└─────────────────────────┘
```

---

## Phân đoạn lần 6: Trên mảng con `[4, 5]`

### Bước 1: Khởi tạo con trỏ và Pivot
- Xét theo chỉ số cục bộ $0 \to 1$:
- $i = -1, \ j = 2$
- $\text{pivot} = a[0] = 4$

```text
Index:      0   1
          ┌───┬───┐
a:        │ 4 │ 5 │
          └───┴───┘
            ↑
        pivot = 4
(i = -1)         (j = 2)
```

---

### Bước 2: Vòng lặp `while(1)` – Lần lặp 1

#### 1. Dò con trỏ $i$ sang phải:
- Tăng $i$ lên 1: $i = 0$
- Kiểm tra điều kiện: $a[i] < \text{pivot} \iff a[0] < 4 \ (4 < 4)$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $i$ tại **$i = 0$**.

#### 2. Dò con trỏ $j$ sang trái:
- Giảm $j$ đi 1: $j = 1 \Rightarrow a[1] = 5 > 4$ (**True**, tiếp tục)
- Giảm $j$ đi 1: $j = 0 \Rightarrow a[0] = 4 > 4$ $\Rightarrow$ **False**
- $\Rightarrow$ Dừng dò $j$ tại **$j = 0$**.

```text
Index:      0   1
          ┌───┬───┐
a:        │ 4 │ 5 │
          └───┴───┘
            ↑
        i=0, j=0
```

#### 3. Kiểm tra điều kiện dừng:
- So sánh: $i < j \ (0 < 0)$ $\Rightarrow$ **Sai** ($i \ge j$)
- Rơi vào nhánh `else`: **`return j`** $\Rightarrow$ Trả về **$j = 0$** ($p = 0$).
- Chia thành 2 mảng con:
  - Nhánh trái: `[4]` (1 phần tử $\Rightarrow$ dừng).
  - Nhánh phải: `[5]` (1 phần tử $\Rightarrow$ dừng).
- Nhánh `[4, 5]` đã đúng thứ tự và hoàn tất sắp xếp.

#### Quá trình giải phóng Call Stack (Unwinding):
```text
1. quicksort([4]) -> l >= r -> pop
2. quicksort([5]) -> l >= r -> pop
3. quicksort([4, 5]) hoàn tất -> pop
4. quicksort([7]) -> l >= r -> pop
5. quicksort([7, 5, 4]) hoàn tất -> pop
6. quicksort(a, 1, 6) hoàn tất -> pop
7. quicksort(a, 7, 7) -> l >= r -> pop
8. quicksort(a, 1, 7) hoàn tất -> pop
9. quicksort(a, 0, 7) hoàn tất -> pop

==> Call Stack rỗng hoàn toàn:
│                         │
└─────────────────────────┘
```


---

## Tổng kết toàn bộ cây đệ quy Hoare Quick Sort

```text
                             ┌───┬───┬───┬───┬───┬───┬───┬───┐
                             │ 2 │ 8 │ 7 │ 1 │ 5 │ 3 │ 6 │ 4 │
                             └───┴───┴───┴───┴───┴───┴───┴───┘
                                            │
                                  Lần 1: p = j = 0
                                            ▼
                       ┌───┐                               ┌───┬───┬───┬───┬───┬───┬───┐
                       │ 1 │                               │ 8 │ 7 │ 2 │ 5 │ 3 │ 6 │ 4 │
                       └───┘                               └───┴───┴───┴───┴───┴───┴───┘
                 quicksort(a, 0, 0)                                      │
                      (Xong)                                   Lần 2: p = j = 6
                                                                         ▼
                                                    ┌───┬───┬───┬───┬───┬───┐        ┌───┐
                                                    │ 4 │ 7 │ 2 │ 5 │ 3 │ 6 │        │ 8 │
                                                    └───┴───┴───┴───┴───┴───┘        └───┘
                                                               │                  quicksort(a, 7, 7)
                                                     Lần 3: p = 1                         (Xong)
                                                               ▼
                                           ┌───┬───┐                       ┌───┬───┬───┐
                                           │ 3 │ 2 │                       │ 7 │ 5 │ 4 │
                                           └───┴───┘                       └───┴───┴───┘
                                               │                                 │
                                     Lần 4: p = 0                      Lần 5: p = 1
                                               ▼                                 ▼
                                       ┌───┐       ┌───┐                 ┌───┬───┐       ┌───┐
                                       │ 2 │       │ 3 │                 │ 4 │ 5 │       │ 7 │
                                       └───┘       └───┘                 └───┴───┘       └───┘
                                      (Xong)      (Xong)                     │          (Xong)
                                                                   Lần 6: p = 0
                                                                             ▼
                                                                     ┌───┐       ┌───┐
                                                                     │ 4 │       │ 5 │
                                                                     └───┘       └───┘
                                                                    (Xong)      (Xong)
```

---

## Mảng kết quả cuối cùng sau khi sắp xếp

Các mảng con đệ quy lần lượt chạm trường hợp cơ sở ($l \ge r$) và hoàn tất, các hàm trên Call Stack lần lượt được giải phóng (`pop`).

Mảng ban đầu đã được sắp xếp tăng dần hoàn chỉnh:

```text
Index:      0   1   2   3   4   5   6   7
          ┌───┬───┬───┬───┬───┬───┬───┬───┐
a:        │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │
          └───┴───┴───┴───┴───┴───┴───┴───┘
```