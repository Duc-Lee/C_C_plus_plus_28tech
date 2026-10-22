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
    // khoi tao phan tu privot
    int privot = a[r]
    // khoi tao bien i 
    int i = l - 1;
    // duyet qua mang 
    for(int j = 0; j < r; j++){
        // neu phan tu a[j] nho hon privot 
        // swap 2 phan tu do  
        if(a[j] <= privot){
            ++i; // tang bien len 
            swap(a[i],a[j]);
        }
    }
    // tang bien i len 
    ++i;
    // swap privot voi phan tu dau tien > privot
    swap(a[i],privot);
    // tra ve index cua privot sau khi chuyen vo giua 2 mang 
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
