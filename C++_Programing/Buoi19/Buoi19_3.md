# Giải Thích Cách Hoạt Động Thuật Toán Sắp Xếp Vun Đống | Thuật Toán Heap Sort

- Tư tưởng : Sắp xếp vun đống hoạt động bằng cách hình dung các phần tử  của mảng như một loại cây nhị phân hoàn chỉnh đặc biệt được gọi là heap

- Độ phức tạp : $O(n \log n)$

- Trường hợp tốt nhất : $O(n \log n)$

- Trường hợp xấu nhất : $O(n \log n)$

## 1. Cây nhị phân hoàn chỉnh (Complete binary tree)

- **Định nghĩa:** Cây nhị phân hoàn chỉnh là cây nhị phân trong đó tất cả các cấp (level) được lấp đầy hoàn toàn ngoại trừ có thể là cấp thấp nhất, và được điền từ bên trái.
- Tất cả các phần tử lá phải nghiêng về bên trái.
- Nốt lá cuối cùng có thể không có anh chị em bên phải.

### Một số ví dụ về cây nhị phân hoàn chỉnh

#### Cây nhị phân hoàn chỉnh (Hợp lệ)

Ví dụ 1: Tất cả các tầng đều được lấp đầy hoàn hảo
```text
           1
        /     \
       2       3
      / \     / \
     4   5   6   7
```

Ví dụ 2: Tầng cuối cùng chưa đầy, nhưng được điền liên tục từ trái sang phải
```text
           1                       1
        /     \                 /     \
       2       3               2       3
      / \     /               / \
     4   5   6               4   5
```

Ví dụ 3: Nốt lá cuối cùng không có anh chị em bên phải
```text
           1
        /     \
       2       3
      /
     4
```

---

#### KHÔNG phải cây nhị phân hoàn chỉnh (Không hợp lệ)

Ví dụ 1: Khuyết con bên trái ở nốt `2` (không điền từ trái qua phải)
```text
           1
        /     \
       2       3
        \     /
         5   6
  (Vi phạm: Nốt 2 thiếu con bên trái)
```

Ví dụ 2: Bị ngắt quãng ở tầng cuối (điền vào con của `3` khi con của `2` chưa đầy)
```text
           1
        /     \
       2       3
      /       / \
     4       6   7
  (Vi phạm: Tầng cuối bị khuyết chỗ con phải của nốt 2)
```

### Mối liên hệ giữa cây nhị phân hoàn chỉnh và mảng

Cây nhị phân hoàn chỉnh có thể được biểu diễn một cách tự nhiên dưới dạng **mảng 1 chiều** mà không cần dùng đến con trỏ (linked list).

#### a. Mảng dữ liệu ban đầu

```text
Index:    0   1   2   3   4   5
        ┌───┬───┬───┬───┬───┬───┐
a:      │ 2 │ 3 │ 7 │ 1 │ 4 │ 6 │
        └───┴───┴───┴───┴───┴───┘
```

#### b. Biểu diễn cây nhị phân hoàn chỉnh tương ứng

Các phần tử của mảng được điền lần lượt theo từng tầng (Level-order) từ trên xuống dưới, từ trái sang phải:

```text
               [ 2 ]
                (0)
             /       \
          /             \
       [ 3 ]           [ 7 ]
        (1)             (2)
      /     \           /
    /         \       /
  [ 1 ]     [ 4 ]   [ 6 ]
   (3)       (4)     (5)
```
*(Số trong ngoặc tròn `(...)` ở dưới là chỉ số `index` tương ứng trong mảng).*

#### c. Công thức tính chỉ số (Index dựa trên 0 - 0-based index)

Với một phần tử nằm tại chỉ số **$i$** trong mảng:

- **Nút con bên trái (Left child):** 
  $$\text{left} = 2i + 1$$
- **Nút con bên phải (Right child):** 
  $$\text{right} = 2i + 2$$
- **Nút cha (Parent):** 
  $$\text{parent} = \left\lfloor \frac{i - 1}{2} \right\rfloor$$

## 2. Cấu trúc dữ liệu Heap 

- Heap là 1 cây nhị phân hoàn chỉnh 

- Tất cả các nút trong cây tuân theo thuộc tính đó là chúng lớn hơn phần tử con của chúng, tức là phần tử lớn nhất nằm ở gốc. 
- Trong trường hợp nốt cha lớn hơn các nốt con của nó ta có **Max-Heap**, ngược lại nếu nốt cha nhỏ hơn 2 nốt con của nó ta có **Min-Heap**.

### Ví dụ về Max-Heap và Min-Heap

#### a. Max-Heap (Đống cực đại)
- Nốt cha luôn **lớn hơn hoặc bằng** ($\ge$) các nốt con của nó.
- Phần tử **lớn nhất** luôn nằm ở vị trí gốc (Root - chỉ số 0).

```text
               [ 9 ]
                (0)
             /       \
          /             \
       [ 7 ]           [ 8 ]
        (1)             (2)
      /     \           /
    /         \       /
  [ 5 ]     [ 3 ]   [ 2 ]
   (3)       (4)     (5)
```

Mảng biểu diễn Max-Heap tương ứng:
```text
Index:    0   1   2   3   4   5
        ┌───┬───┬───┬───┬───┬───┐
a:      │ 9 │ 7 │ 8 │ 5 │ 3 │ 2 │
        └───┴───┴───┴───┴───┴───┘
```

#### b. Min-Heap (Đống cực tiểu)
- Nốt cha luôn **nhỏ hơn hoặc bằng** ($\le$) các nốt con của nó.
- Phần tử **nhỏ nhất** luôn nằm ở vị trí gốc (Root - chỉ số 0).

```text
               [ 1 ]
                (0)
             /       \
          /             \
       [ 3 ]           [ 2 ]
        (1)             (2)
      /     \           /
    /         \       /
  [ 6 ]     [ 7 ]   [ 5 ]
   (3)       (4)     (5)
```

Mảng biểu diễn Min-Heap tương ứng:
```text
Index:    0   1   2   3   4   5
        ┌───┬───┬───┬───┬───┬───┐
a:      │ 1 │ 3 │ 2 │ 6 │ 7 │ 5 │
        └───┴───┴───┴───┴───┴───┘
```

## 3. Thao tác Heapify

- Thao tác heapify là thao tác duy trì tính chất heap của một cây heap, tức là đảm bảo rằng tất cả các nút trong cây đều tuân theo thuộc tính của heap

- Thuật toán heapify có thể được sử dụng để xây dựng một cây heap từ một mảng bất kỳ trong thời gian $O(n)$

- Code 
```cpp
// hàm heapify theo max heap 
void heapify(int a[], int n, int i){
    // khoi tao node cha la gia tri lon nhat tam thoi
    int largest = i;
    // khoi tao node con trai 
    int left = 2 * i + 1;
    // khoi tao node con phai 
    int right = 2 * i + 2;
    // kiem tra xem node con trai co lon hon cha khong 
    if(left < n && a[left] > a[largest]){
        // gan index node con trai vao largest 
        largest = left;
    }
    // kiem tra xem node con phai co lon hon gia tri lon nhat hien tai khong 
    if(right < n && a[right] > a[largest]){
        // gan index node con phai vao largest 
        largest = right;
    }
    // neu node cha khong phai la node lon nhat 
    // thi hoan doi node cha voi node con lon nhat 
    if(largest != i){
        swap(a[i], a[largest]);
        // de quy heapify xuong tiep node con vua bi hoan doi 
        heapify(a, n, largest);
    }
}
```

### Ví dụ minh họa quá trình Heapify

#### Bước 1: Mảng đầu vào
```text
Index:    0   1   2   3   4   5
        ┌───┬───┬───┬───┬───┬───┐
a:      │ 3 │ 9 │ 2 │ 1 │ 4 │ 5 │
        └───┴───┴───┴───┴───┴───┘
```

#### Bước 2: Tạo cây nhị phân hoàn chỉnh từ mảng đầu vào

```text
               [ 3 ]
                (0)
             /       \
          /             \
       [ 9 ]           [ 2 ]
        (1)             (2)
      /     \           /
    /         \       /
  [ 1 ]     [ 4 ]   [ 5 ]
   (3)       (4)     (5)
```

#### Bước 3: Bắt đầu từ các nốt không phải là nốt lá
- Các nốt lá (từ chỉ số $\lfloor n/2 \rfloor \to n - 1$, tức các nốt $3, 4, 5$) bản thân chúng không có con nên đã thỏa mãn thuộc tính Heap.
- Ta chỉ cần thực hiện `heapify` cho các nốt không phải là nốt lá, duyệt ngược từ dưới lên:
  $$i = \left\lfloor \frac{n}{2} \right\rfloor - 1 = \left\lfloor \frac{6}{2} \right\rfloor - 1 = 2$$
- Bắt đầu xét thao tác `heapify` tại nốt có chỉ số **$i = 2$** (có giá trị là **$2$**):

```text
               [ 3 ]
                (0)
             /       \
          /             \
       [ 9 ]          ▶[ 2 ]◀ (Xét nốt cha i = 2)
        (1)             (2)
      /     \           /
    /         \       /
  [ 1 ]     [ 4 ]   [ 5 ]
   (3)       (4)     (5)
```

#### Bước 4: Khởi tạo phần tử lớn nhất tạm thời
- Ta coi phần tử ở chỉ số $i$ này là phần tử lớn nhất giữa 3 phần tử: phần tử ở nốt gốc là chính nó, nốt con bên trái, nốt con bên phải.
  $$\text{largest} = i \quad (\text{largest} = 2)$$

#### Bước 5: Tìm phần tử lớn nhất giữa nút cha và các nút con
- Lần lượt so sánh phần tử ở nút gốc với nút con bên trái, nếu nút con bên trái lớn hơn nút gốc thì cập nhật `largest = 2 * i + 1`.
- Tiếp tục duyệt qua nút con bên phải, nếu nút con bên phải lớn hơn phần tử đang được coi là lớn nhất có chỉ số `largest` thì cập nhật `largest = 2 * i + 2`.
- Vậy sau 2 lần so sánh ta tìm được chỉ số của phần tử lớn nhất trong 3 phần tử: nút cha có chỉ số $i$, nút con bên trái có chỉ số $2 \times i + 1$, nút con bên phải có chỉ số $2 \times i + 2$.
- *(Trong trường hợp nút $i$ không có con, hoặc không có con bên phải thì điều kiện biên `left < n` và `right < n` bảo đảm thao tác trên được thực hiện bình thường).*

**Áp dụng vào nốt $i = 2$ ($a[2] = 2$):**
- Con trái: $\text{left} = 2 \times 2 + 1 = 5 \ (< 6)$. So sánh: $a[\text{left}] = a[5] = 5 > a[\text{largest}] = a[2] = 2$ $\Rightarrow$ Cập nhật **$\text{largest} = 5$**.
- Con phải: $\text{right} = 2 \times 2 + 2 = 6$ (không thỏa $6 < 6$ $\Rightarrow$ không có con phải).
- $\Rightarrow$ Phần tử lớn nhất trong nhóm này là nốt con trái tại chỉ số **$\text{largest} = 5$** (giá trị $5$).

#### Bước 6: Hoán vị phần tử có chỉ số `largest` với nút gốc có chỉ số `i`
- Vì $\text{largest} \ne i \ (5 \ne 2)$, ta thực hiện hoán vị:
  $$\text{swap}(a[i], a[\text{largest}]) \iff \text{swap}(a[2], a[5])$$
- Đổi chỗ giá trị $2$ và $5$.

```text
Cây sau khi hoán vị tại nút i = 2:
               [ 3 ]
                (0)
             /       \
          /             \
       [ 9 ]          ▶[ 5 ]◀ (Đã đưa 5 lên làm cha)
        (1)             (2)
      /     \           /
    /         \       /
  [ 1 ]     [ 4 ]   ▶[ 2 ]◀ (Đưa 2 xuống)
   (3)       (4)     (5)
```

Mảng sau khi hoán vị:
```text
Index:    0   1   2   3   4   5
        ┌───┬───┬───┬───┬───┬───┐
a:      │ 3 │ 9 │ 5 │ 1 │ 4 │ 2 │
        └───┴───┴───┴───┴───┴───┘
```

- Gọi đệ quy `heapify(a, n, largest)` $\Rightarrow$ `heapify(a, 6, 5)`: Do nốt $5$ là nốt lá (không có con), hàm kết thúc thao tác cho nhánh này.

#### Bước 7 : 
- Lặp lại các bước từ 3 tới 7 cho tới khi subtree gốc $i$ cũng đã được heapified.

Để xây dựng Heap ta gọi hàm Heapify với mọi nốt không phải nốt lá:
```cpp
// duyet tu goc cha cuoi cung di len goc cha 0
for (int i = n / 2 - 1; i >= 0; i--){
    heapify(a, n, i);
}
```

### Ví dụ minh họa quá trình Xây dựng Heap (Build Max-Heap)

Xét mảng đầu vào gồm $n = 6$ phần tử:
- Mảng: $a = [1, 12, 9, 5, 6, 10]$
- Số lượng phần tử: $n = 6$
- Chỉ số nút cha cuối cùng (nút không phải lá có chỉ số lớn nhất):
  $$i = \left\lfloor \frac{n}{2} \right\rfloor - 1 = \left\lfloor \frac{6}{2} \right\rfloor - 1 = 2$$
- Vòng lặp sẽ duyệt qua tất cả các nút cha từ dưới lên trên: **$i$ chạy từ $2$ về $0$** ($i = 2, 1, 0$).

```text
Mảng ban đầu:
Index:    0    1    2    3    4    5
        ┌────┬────┬────┬────┬────┬────┐
a:      │  1 │ 12 │  9 │  5 │  6 │ 10 │
        └────┴────┴────┴────┴────┴────┘

Cây nhị phân hoàn chỉnh tương ứng ban đầu:
               [ 1 ]
                (0)
             /       \
          /             \
       [ 12 ]          [ 9 ]
        (1)             (2)
      /     \           /
    /         \       /
  [ 5 ]     [ 6 ]   [ 10 ]
   (3)       (4)     (5)
```

---

#### 1. Gọi hàm heapify với nốt ở chỉ số $i = 2$ (`heapify(a, 6, 2)`)
- Cây con có gốc tại nốt $i = 2$ (giá trị **$9$**):
  - Con trái: $\text{left} = 2 \times 2 + 1 = 5$ (giá trị **$10$**).
  - Con phải: $\text{right} = 2 \times 2 + 2 = 6 \ge n$ (không có con phải).
  - So sánh: $a[5] = 10 > a[2] = 9 \Rightarrow \text{largest} = 5$.
  - Vì $\text{largest} \ne 2$, ta **hoán vị** $a[2]$ và $a[5]$ ($\text{swap}(a[2], a[5])$).
  - Đệ quy `heapify(a, 6, 5)`: Do nốt $5$ là nốt lá nên kết thúc thao tác.

```text
         Trước khi đổi chỗ                                    Sau khi đổi chỗ
               [ 1 ]                                               [ 1 ]
                (0)                                                 (0)
             /       \                                           /       \
          /             \                                     /             \
       [ 12 ]         ▶[ 9 ]◀                              [ 12 ]         ▶[ 10 ]◀ (Đưa 10 lên)
        (1)             (2)                                 (1)             (2)
      /     \           /          ───────────────►       /     \           /
    /         \       /                                 /         \       /
  [ 5 ]     [ 6 ]   ▶[ 10 ]◀                          [ 5 ]     [ 6 ]   ▶[ 9 ]◀ (Đưa 9 xuống)
   (3)       (4)     (5)                               (3)       (4)     (5)

Index:    0    1    2    3    4    5              Index:    0    1    2    3    4    5
        ┌────┬────┬────┬────┬────┬────┐                   ┌────┬────┬────┬────┬────┬────┐
a:      │  1 │ 12 │  9 │  5 │  6 │ 10 │           a:      │  1 │ 12 │ 10 │  5 │  6 │  9 │
        └────┴────┴────┴────┴────┴────┘                   └────┴────┴────┴────┴────┴────┘
                   ▲              ▲                                  ▲              ▲
                   └──────┬───────┘                                  └──────┬───────┘
                     Hoán vị 2 & 5                                  Đã hoán vị xong
```

---

#### 2. Gọi hàm heapify với nốt ở chỉ số $i = 1$ (`heapify(a, 6, 1)`)
- Cây con có gốc tại nốt $i = 1$ (giá trị **$12$**):
  - Con trái: $\text{left} = 2 \times 1 + 1 = 3$ (giá trị **$5$**).
  - Con phải: $\text{right} = 2 \times 1 + 2 = 4$ (giá trị **$6$**).
  - So sánh: Nốt cha mang giá trị $12$, lớn hơn cả con trái ($5$) và con phải ($6$).
  - $\Rightarrow \text{largest} = 1$.
  - Cây con gốc $i = 1$ đã thỏa mãn tính chất Max-Heap (**already heapified**), do đó **không cần đổi chỗ**, kết thúc `heapify(a, 6, 1)`.

```text
               [ 1 ]
                (0)
             /       \
          /             \
      ▶[ 12 ]◀         [ 10 ]         (Cây con gốc 1 đã thỏa mãn Max-Heap:
        (1)             (2)            12 > 5 và 12 > 6 -> Already heapified)
      /     \           /
    /         \       /
  [ 5 ]     [ 6 ]   [ 9 ]
   (3)       (4)     (5)

Index:    0    1    2    3    4    5
        ┌────┬────┬────┬────┬────┬────┐
a:      │  1 │ 12 │ 10 │  5 │  6 │  9 │   (Mảng giữ nguyên không thay đổi)
        └────┴────┴────┴────┴────┴────┘
```

---

#### 3. Gọi hàm heapify với nốt ở chỉ số $i = 0$ (`heapify(a, 6, 0)`)
- Xét cây con có gốc tại nốt $i = 0$ (giá trị **$1$**). Quá trình đệ quy lan truyền (sift-down) diễn ra qua 2 bước:

##### Bước 3.1: Hoán vị tại nốt gốc $i = 0$ với con lớn nhất (nốt $1$)
- Tại nốt gốc $i = 0$ ($a[0] = 1$):
  - Con trái: $a[1] = 12$.
  - Con phải: $a[2] = 10$.
  - Phần tử lớn nhất là con trái $a[1] = 12 \Rightarrow \text{largest} = 1$.
- Vì $\text{largest} \ne 0$, thực hiện hoán vị $\text{swap}(a[0], a[1])$: đưa $12$ lên làm gốc và hạ $1$ xuống nốt $1$.
- Tiếp tục gọi đệ quy kiểm tra cây con tại nốt vừa bị xáo trộn: `heapify(a, 6, 1)`.

```text
         Trước khi đổi chỗ                                    Sau khi đổi chỗ
             ▶[ 1 ]◀ (Xét i = 0)                                 ▶[ 12 ]◀ (Đưa 12 lên làm gốc)
               (0)                                                 (0)
             /     \                                             /     \
          /           \                                       /           \
      ▶[ 12 ]◀       [ 10 ]        ───────────────►       ▶[ 1 ]◀        [ 10 ] (Hạ 1 xuống nốt 1)
        (1)           (2)                                   (1)           (2)
      /     \         /                                   /     \         /
   [ 5 ]   [ 6 ]   [ 9 ]                               [ 5 ]   [ 6 ]   [ 9 ]
    (3)     (4)     (5)                                 (3)     (4)     (5)

Index:    0    1    2    3    4    5              Index:    0    1    2    3    4    5
        ┌────┬────┬────┬────┬────┬────┐                   ┌────┬────┬────┬────┬────┬────┐
a:      │  1 │ 12 │ 10 │  5 │  6 │  9 │           a:      │ 12 │  1 │ 10 │  5 │  6 │  9 │
        └────┴────┴────┴────┴────┴────┘                   └────┴────┴────┴────┴────┴────┘
          ▲    ▲                                            ▲    ▲
          └─┬──┘                                            └─┬──┘
        Hoán vị 0 & 1                                     Đã đưa 12 lên gốc
```

##### Bước 3.2: Đệ quy `heapify(a, 6, 1)` (Xử lý tiếp nhánh nốt $1$)
- Tại nốt $i = 1$ (giá trị hiện tại là **$1$**):
  - Con trái: $\text{left} = 3$ ($a[3] = 5$).
  - Con phải: $\text{right} = 4$ ($a[4] = 6$).
  - Phần tử lớn nhất là con phải $a[4] = 6 \Rightarrow \text{largest} = 4$.
- Vì $\text{largest} \ne 1$, thực hiện hoán vị $\text{swap}(a[1], a[4])$: đưa $6$ lên nốt $1$ và hạ $1$ xuống nốt $4$.
- Gọi đệ quy: `heapify(a, 6, 4)`: Do nốt $4$ là nốt lá nên kết thúc hoàn toàn.

```text
         Trước khi đổi chỗ                                    Sau khi đổi chỗ
              [ 12 ]                                              [ 12 ]
               (0)                                                 (0)
             /     \                                             /     \
          /           \                                       /           \
       ▶[ 1 ]◀       [ 10 ]        ───────────────►        ▶[ 6 ]◀       [ 10 ] (Đưa 6 lên nốt 1)
        (1)           (2)                                   (1)           (2)
      /     \         /                                   /     \         /
   [ 5 ]   ▶[ 6 ]◀ [ 9 ]                               [ 5 ]   ▶[ 1 ]◀ [ 9 ] (Hạ 1 xuống nốt 4)
    (3)     (4)     (5)                                 (3)     (4)     (5)

Index:    0    1    2    3    4    5              Index:    0    1    2    3    4    5
        ┌────┬────┬────┬────┬────┬────┐                   ┌────┬────┬────┬────┬────┬────┐
a:      │ 12 │  1 │ 10 │  5 │  6 │  9 │           a:      │ 12 │  6 │ 10 │  5 │  1 │  9 │
        └────┴────┴────┴────┴────┴────┘                   └────┴────┴────┴────┴────┴────┘
               ▲              ▲                                  ▲              ▲
               └──────┬───────┘                                  └──────┬───────┘
                 Hoán vị 1 & 4                                    Đã đưa 6 lên nốt 1
```

---

#### 4. Tổng kết toàn bộ chu trình lan truyền đệ quy khi gọi `heapify(a, 6, 0)`

Dưới đây là sơ đồ 4 trạng thái mô phỏng đầy đủ chu trình đệ quy của hàm `heapify` tại gốc $i = 0$:

```text
(1) Ban đầu xét gốc i = 0 (1 < 12):            (2) Hoán vị a[0] và a[1] (Đưa 12 lên gốc):
           [ 1 ]                                          [ 12 ]
            (0)                                            (0)
         /       \                                      /       \
     ▶[ 12 ]◀   [ 10 ]         ──────────────►       ▶[ 1 ]◀   [ 10 ]
       (1)       (2)                                   (1)       (2)
     /     \     /                                   /     \     /
  [ 5 ]   [ 6 ] [ 9 ]                             [ 5 ]  ▶[ 6 ]◀[ 9 ]
   (3)     (4)   (5)                               (3)     (4)   (5)
[ 1, 12, 10, 5, 6, 9 ]                         [ 12, 1, 10, 5, 6, 9 ]
                                                          │
                                                          │ Đệ quy heapify(a, 6, 1)
                                                          ▼
(4) Cây hoàn chỉnh tính chất Max-Heap:         (3) Chuẩn bị hoán vị a[1] và a[4] (1 < 6):
          [ 12 ]                                          [ 12 ]
            (0)                                            (0)
         /       \                                      /       \
      [ 6 ]    [ 10 ]          ◄─────────────        ▶[ 1 ]◀   [ 10 ]
       (1)       (2)                                   (1)       (2)
     /     \     /                                   /     \     /
  [ 5 ]   [ 1 ] [ 9 ]                             [ 5 ]  ▶[ 6 ]◀[ 9 ]
   (3)     (4)   (5)                               (3)     (4)   (5)
[ 12, 6, 10, 5, 1, 9 ]                         [ 12, 1, 10, 5, 6, 9 ]
```

## 4. Heap Sort

Sau khi đã xây dựng được cây Max-Heap, ta thực hiện thuật toán **Heap Sort** để sắp xếp mảng theo thứ tự tăng dần theo các bước sau:

- **Bước 1:** Vì cây thỏa mãn thuộc tính **Max-Heap**, nên phần tử lớn nhất luôn được lưu trữ tại nút gốc ($a[0]$).
- **Bước 2 (Hoán đổi):** Loại bỏ phần tử gốc và đặt ở cuối mảng bằng cách đổi chỗ phần tử gốc $a[0]$ với phần tử ở vị trí cuối cùng của heap hiện tại ($a[i]$).
- **Bước 3 (Giảm kích thước):** Giảm kích thước của heap đi $1$ (phần tử lớn nhất vừa đổi chỗ đã nằm đúng vị trí và không còn thuộc heap).
- **Bước 4 (Heapify lại):** Heapify lại phần tử gốc để chúng ta có phần tử cao nhất tiếp theo ở gốc: gọi `heapify(a, i, 0)`.
- **Bước 5 (Lặp lại):** Quá trình này được lặp lại cho đến khi tất cả các mục của danh sách được sắp xếp.

### Ví dụ minh họa quá trình Heap Sort từng bước

Tiếp tục với mảng đã được xây dựng thành cây Max-Heap ở mục trước:
- **Mảng Max-Heap ban đầu ($n = 6$):** $a = [12, 6, 10, 5, 1, 9]$

```text
Index:    0    1    2    3    4    5
        ┌────┬────┬────┬────┬────┬────┐
a:      │ 12 │  6 │ 10 │  5 │  1 │  9 │
        └────┴────┴────┴────┴────┴────┘

               [ 12 ]
                (0)
             /        \
          [ 6 ]      [ 10 ]
           (1)        (2)
         /     \      /
       [ 5 ]  [ 1 ] [ 9 ]
        (3)    (4)   (5)
```

Vòng lặp `for (int i = n - 1; i >= 0; i--)` sẽ lần lượt xét $i$ giảm dần từ $5$ về $1$:

---

#### ◈ Lần lặp 1: Xét $i = 5$ (Đưa phần tử lớn nhất $12$ về vị trí 5)

1. **Hoán vị (Swap):** Đổi chỗ phần tử gốc lớn nhất $a[0] = 12$ với phần tử cuối heap hiện tại $a[5] = 9$ $\Rightarrow$ gọi `swap(a[0], a[5])`.
2. **Loại bỏ (Remove):** Giảm kích thước heap còn $5$ (các chỉ số từ $0$ đến $4$). Nốt $5$ (giá trị $12$) được cố định ở cuối mảng và tách ra khỏi heap.
3. **Vun đống (Heapify):** Gọi `heapify(a, 5, 0)`:
   - Tại gốc $i = 0$ ($a[0] = 9$): Con trái $a[1] = 6$, con phải $a[2] = 10$.
   - Con lớn nhất là con phải $a[2] = 10 > 9 \Rightarrow$ hoán vị $a[0]$ và $a[2]$ (đưa $10$ lên làm gốc, hạ $9$ xuống nốt $2$).
   - Đệ quy `heapify(a, 5, 2)`: Nốt $2$ không còn con trong heap ($2 \times 2 + 1 = 5 \ge 5$) $\Rightarrow$ Kết thúc.

```text
      (1) Hoán đổi (swap a[0] & a[5])                (2) Heapify lại gốc: heapify(a, 5, 0)
                 [ 9 ]                                           [ 10 ]
                  (0)                                             (0)
               /        \                                      /        \
            [ 6 ]      [ 10 ]                               [ 6 ]       [ 9 ]
             (1)        (2)                                  (1)         (2)
           /     \      /            ─────────────►        /     \
         [ 5 ]  [ 1 ] ┆[ 12 ]┆ (Tách ra)                 [ 5 ]  [ 1 ]
          (3)    (4)   - (5) -                            (3)    (4)

Index:    0    1    2    3    4  │  5 (Đã xếp)    Index:    0    1    2    3    4  │  5 (Đã xếp)
        ┌────┬────┬────┬────┬────┼────┐                 ┌────┬────┬────┬────┬────┼────┐
a:      │  9 │  6 │ 10 │  5 │  1 │ 12 │         a:      │ 10 │  6 │  9 │  5 │  1 │ 12 │
        └────┴────┴────┴────┴────┴────┘                 └────┴────┴────┴────┴────┴────┘
```

---

#### ◈ Lần lặp 2: Xét $i = 4$ (Đưa phần tử lớn nhất $10$ về vị trí 4)

1. **Hoán vị (Swap):** Đổi chỗ phần tử gốc $a[0] = 10$ với phần tử cuối heap hiện tại $a[4] = 1$ $\Rightarrow$ gọi `swap(a[0], a[4])`.
2. **Loại bỏ (Remove):** Giảm kích thước heap còn $4$ (các chỉ số $0, 1, 2, 3$). Phần tử $10$ được cố định ở vị trí $4$.
3. **Vun đống (Heapify):** Gọi `heapify(a, 4, 0)`:
   - Tại gốc $i = 0$ ($a[0] = 1$): Con trái $a[1] = 6$, con phải $a[2] = 9$.
   - Con lớn nhất là con phải $a[2] = 9 > 1 \Rightarrow$ hoán vị $a[0]$ và $a[2]$ (đưa $9$ lên làm gốc, hạ $1$ xuống nốt $2$).
   - Đệ quy `heapify(a, 4, 2)`: Nốt $2$ không có con trong heap ($2 \times 2 + 1 = 5 \ge 4$) $\Rightarrow$ Kết thúc.

```text
      (1) Hoán đổi (swap a[0] & a[4])                (2) Heapify lại gốc: heapify(a, 4, 0)
                 [ 1 ]                                            [ 9 ]
                  (0)                                              (0)
               /        \                                       /        \
            [ 6 ]       [ 9 ]                                [ 6 ]       [ 1 ]
             (1)         (2)                                  (1)         (2)
           /                         ─────────────►         /
         [ 5 ]   ┆[ 10 ]┆ (Tách ra)                       [ 5 ]
          (3)     - (4) -                                  (3)

Index:    0    1    2    3  │  4    5 (Đã xếp)     Index:    0    1    2    3  │  4    5 (Đã xếp)
        ┌────┬────┬────┬────┼────┬────┐                 ┌────┬────┬────┬────┼────┬────┐
a:      │  1 │  6 │  9 │  5 │ 10 │ 12 │         a:      │  9 │  6 │  1 │  5 │ 10 │ 12 │
        └────┴────┴────┴────┴────┴────┘                 └────┴────┴────┴────┴────┴────┘
```

---

#### ◈ Lần lặp 3: Xét $i = 3$ (Đưa phần tử lớn nhất $9$ về vị trí 3)

1. **Hoán vị (Swap):** Đổi chỗ phần tử gốc $a[0] = 9$ với phần tử cuối heap hiện tại $a[3] = 5$ $\Rightarrow$ gọi `swap(a[0], a[3])`.
2. **Loại bỏ (Remove):** Giảm kích thước heap còn $3$ (các chỉ số $0, 1, 2$). Phần tử $9$ được cố định ở vị trí $3$.
3. **Vun đống (Heapify):** Gọi `heapify(a, 3, 0)`:
   - Tại gốc $i = 0$ ($a[0] = 5$): Con trái $a[1] = 6$, con phải $a[2] = 1$.
   - Con lớn nhất là con trái $a[1] = 6 > 5 \Rightarrow$ hoán vị $a[0]$ và $a[1]$ (đưa $6$ lên làm gốc, hạ $5$ xuống nốt $1$).
   - Đệ quy `heapify(a, 3, 1)`: Nốt $1$ không có con trong heap ($2 \times 1 + 1 = 3 \ge 3$) $\Rightarrow$ Kết thúc.

```text
      (1) Hoán đổi (swap a[0] & a[3])                (2) Heapify lại gốc: heapify(a, 3, 0)
                 [ 5 ]                                            [ 6 ]
                  (0)                                              (0)
               /        \                                       /        \
            [ 6 ]       [ 1 ]                                [ 5 ]       [ 1 ]
             (1)         (2)         ─────────────►           (1)         (2)
          /
        ┆[ 9 ]┆ (Tách ra)
         - (3) -

Index:    0    1    2  │  3    4    5 (Đã xếp)     Index:    0    1    2  │  3    4    5 (Đã xếp)
        ┌────┬────┬────┼────┬────┬────┐                 ┌────┬────┬────┼────┬────┬────┐
a:      │  5 │  6 │  1 │  9 │ 10 │ 12 │         a:      │  6 │  5 │  1 │  9 │ 10 │ 12 │
        └────┴────┴────┴────┴────┴────┘                 └────┴────┴────┴────┴────┴────┘
```

---

#### ◈ Lần lặp 4: Xét $i = 2$ (Đưa phần tử lớn nhất $6$ về vị trí 2)

1. **Hoán vị (Swap):** Đổi chỗ phần tử gốc $a[0] = 6$ với phần tử cuối heap hiện tại $a[2] = 1$ $\Rightarrow$ gọi `swap(a[0], a[2])`.
2. **Loại bỏ (Remove):** Giảm kích thước heap còn $2$ (các chỉ số $0, 1$). Phần tử $6$ được cố định ở vị trí $2$.
3. **Vun đống (Heapify):** Gọi `heapify(a, 2, 0)`:
   - Tại gốc $i = 0$ ($a[0] = 1$): Con trái $a[1] = 5$, không có con phải.
   - So sánh: $a[1] = 5 > a[0] = 1 \Rightarrow$ hoán vị $a[0]$ và $a[1]$ (đưa $5$ lên làm gốc, hạ $1$ xuống nốt $1$).
   - Dừng đệ quy.

```text
      (1) Hoán đổi (swap a[0] & a[2])                (2) Heapify lại gốc: heapify(a, 2, 0)
                 [ 1 ]                                            [ 5 ]
                  (0)                                              (0)
               /        \                                       /
            [ 5 ]      ┆[ 6 ]┆ (Tách ra)                     [ 1 ]
             (1)        - (2) -      ─────────────►           (1)

Index:    0    1  │  2    3    4    5 (Đã xếp)     Index:    0    1  │  2    3    4    5 (Đã xếp)
        ┌────┬────┼────┬────┬────┬────┐                 ┌────┬────┼────┬────┬────┬────┐
a:      │  1 │  5 │  6 │  9 │ 10 │ 12 │         a:      │  5 │  1 │  6 │  9 │ 10 │ 12 │
        └────┴────┴────┴────┴────┴────┘                 └────┴────┴────┴────┴────┴────┘
```

---

#### ◈ Lần lặp 5: Xét $i = 1$ (Đưa phần tử $5$ về vị trí 1 và hoàn tất)

1. **Hoán vị (Swap):** Đổi chỗ phần tử gốc $a[0] = 5$ với phần tử cuối heap hiện tại $a[1] = 1$ $\Rightarrow$ gọi `swap(a[0], a[1])`.
2. **Loại bỏ (Remove):** Kích thước heap giảm còn $1$ (chỉ còn duy nhất phần tử $a[0] = 1$).
3. **Kết thúc:** Khi heap chỉ còn 1 phần tử, phần tử này hiển nhiên đã nằm đúng vị trí nhỏ nhất trong mảng. Vòng lặp kết thúc.

```text
      (1) Hoán đổi (swap a[0] & a[1])                   (2) Trạng thái mảng hoàn tất
                 [ 1 ]                                            [ 1 ] (Nốt duy nhất)
                  (0)                                              (0)
               /
            ┆[ 5 ]┆ (Tách ra)        ─────────────►
             - (1) -

Index:    0  │  1    2    3    4    5 (Đã xếp)     Index:    0    1    2    3    4    5 (Hoàn tất)
        ┌────┼────┬────┬────┬────┬────┐                 ┌────┬────┬────┬────┬────┬────┐
a:      │  1 │  5 │  6 │  9 │ 10 │ 12 │         a:      │  1 │  5 │  6 │  9 │ 10 │ 12 │
        └────┴────┴────┴────┴────┴────┘                 └────┴────┴────┴────┴────┴────┘
```

- **Kết quả thu được:** Mảng đã được sắp xếp tăng dần hoàn chỉnh:
$$\mathbf{a = [1, 5, 6, 9, 10, 12]}$$

---

### Mã hàm `heapsort`:
```cpp
void heapsort(int a[], int n){
    // Build max-heap: Xây dựng cây Max-Heap ban đầu
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Heap sort: Lần lượt rút trích từng phần tử lớn nhất về cuối mảng
    for (int i = n - 1; i >= 0; i--) {
        // Hoán đổi phần tử lớn nhất ở gốc với phần tử cuối cùng hiện tại của heap
        swap(a[0], a[i]);

        // Heapify root element to get highest element at root again
        // Heapify lại nút gốc với kích thước heap giảm còn i
        heapify(a, i, 0);
    }
}
```

---

## 5. Code và ví dụ 

### Triển khai code hoàn chỉnh (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Thao tac heapify (vun dong) tai nut i
void heapify(int a[], int n, int i){
	// Gan largest ban dau la nut cha
	int largest = i;
	// Gan nut con trai va con phai
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// Kiem tra phan tu con trai co lon hon cha khong?
	if(left < n && a[left] > a[largest]) {
		largest = left;
	} 
	// Kiem tra phan tu con phai co lon hon nut lon nhat hien tai khong?
	if(right < n && a[right] > a[largest]){
		largest = right;
	}

	// Neu nut cha khong phai la nut lon nhat
	// Tien hanh hoan vi va de quy xuong cay con bi anh huong
	if(largest != i) {
		swap(a[i], a[largest]);
		// Thao tac heapify lai voi nut con bi xao tron
		heapify(a, n, largest); 
	}
}

// Thao tac heap sort
void heapsort(int a[], int n){
	// 1. Build max-heap (duyet tu nut cha cuoi cung ve nut goc 0)
	for(int i = n / 2 - 1; i >= 0; i--){
		heapify(a, n, i);
	}

	// 2. Heap sort: dua lan luot cac phan tu lon nhat ve cuoi mang
	for(int i = n - 1; i >= 0; i--){
		swap(a[0], a[i]);
		// Heapify lai goc voi kich thuoc heap giam con i
		heapify(a, i, 0);
	}
}

int main(){
	int n;
	cin >> n;
	int a[n];
	// Nhap mang
	for(int &i : a) cin >> i;

	// Goi thuat toan sap xep vun dong
	heapsort(a, n);

	// In mang sau khi sap xep
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
```


### Ví dụ từng bước chi tiết: Quá trình xây dựng Max-Heap (Build Max-Heap)

Cho mảng $a = [8, 12, 4, 6, 9, 2, 3, 3, 7, 4]$ gồm $n = 10$ phần tử (các chỉ số từ $0$ đến $9$):

```text
Index:    0    1    2    3    4    5    6    7    8    9
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │  8 │ 12 │  4 │  6 │  9 │  2 │  3 │  3 │  7 │  4 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
```

#### 1. Biểu diễn mảng dưới dạng cây nhị phân hoàn chỉnh ban đầu

Từ mảng ban đầu, ta ánh xạ các chỉ số thành cây nhị phân hoàn chỉnh:
- Gốc ở chỉ số $0$ ($a[0] = 8$).
- Với mỗi nốt $i$, con trái là $2i + 1$, con phải là $2i + 2$.

```text
                     [ 8 ]
                      (0)
                 /           \
             /                   \
         [ 12 ]                  [ 4 ]
          (1)                     (2)
        /      \                /     \
     [ 6 ]    [ 9 ]          [ 2 ]   [ 3 ]
      (3)      (4)            (5)     (6)
     /   \     /
   [ 3 ] [ 7 ][ 4 ]
    (7)   (8)  (9)
```

---

#### 2. Xác định phạm vi tạo Heap (Tạo Max-Heap)

Ta duyệt từ nốt cha cuối cùng (nốt có con lớn nhất không phải nốt lá) ngược về nốt gốc:
$$i = \left\lfloor \frac{n}{2} \right\rfloor - 1 = \left\lfloor \frac{10}{2} \right\rfloor - 1 = 4$$

$\Rightarrow$ Biến $i$ sẽ chạy từ $4$ giảm dần về $0$ ($i = 4, 3, 2, 1, 0$).

---

#### 3. Quá trình Vun đống (Heapify) từng bước

##### ◈ Bước 1: Xét $i = 4$

- **Thao tác:** `heapify(a, 10, 4)`
  - Chỉ số nốt con: $\text{left} = 2 \times 4 + 1 = 9$, $\text{right} = 2 \times 4 + 2 = 10 > n$ ($10 \ge 10$, vượt quá kích thước mảng).
  - Khởi tạo: $\text{largest} = 4$.
  - **Kiểm tra con trái:** `a[left] > a[largest]` $\Leftrightarrow a[9] > a[4]$ ($4 > 9$) $\Rightarrow$ **False**.
  - **Kiểm tra con phải:** `right < n && a[right] > a[largest]` $\Rightarrow$ **False** (vì $\text{right} = 10 \ge n$).
  - **Kiểm tra:** $\text{largest} \ne i$ ($4 \ne 4$) $\Rightarrow$ **False**.
  - $\Rightarrow$ Không xảy ra hoán vị.

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 10, 4)   │ ───► pop (kết thúc)
  └──────────────────────┘
```

- **Trạng thái mảng & Cây:** Giữ nguyên không đổi.
```text
                     [ 8 ]
                      (0)
                 /           \
             /                   \
         [ 12 ]                  [ 4 ]
          (1)                     (2)
        /      \                /     \
     [ 6 ]    [ 9 ]          [ 2 ]   [ 3 ]
      (3)      (4)            (5)     (6)
     /   \     /
   [ 3 ] [ 7 ][ 4 ]
    (7)   (8)  (9)

Index:    0    1    2    3    4    5    6    7    8    9
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │  8 │ 12 │  4 │  6 │  9 │  2 │  3 │  3 │  7 │  4 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
```

---

##### ◈ Bước 2: Xét $i = 3$

- **Thao tác 1:** `heapify(a, 10, 3)`
  - Chỉ số con: $\text{left} = 2 \times 3 + 1 = 7$, $\text{right} = 2 \times 3 + 2 = 8$.
  - Khởi tạo: $\text{largest} = 3$.
  - **Kiểm tra con trái:** `a[left] > a[largest]` $\Leftrightarrow a[7] > a[3]$ ($3 > 6$) $\Rightarrow$ **False**.
  - **Kiểm tra con phải:** `a[right] > a[largest]` $\Leftrightarrow a[8] > a[3]$ ($7 > 6$) $\Rightarrow$ **True** $\Rightarrow$ Cập nhật $\text{largest} = 8$.
  - **Kiểm tra:** $\text{largest} = 8 \ne i = 3$ $\Rightarrow$ **True**.
  - $\Rightarrow$ **Thực hiện hoán vị:** $\text{swap}(a[\text{largest}], a[i]) \Leftrightarrow \text{swap}(a[8], a[3])$ (hoán vị giữa $6$ và $7$).
  - $\Rightarrow$ **Gọi đệ quy:** `heapify(a, 10, 8)`.

- **Mô hình Call Stack (Đẩy hàm đệ quy vào Stack):**
```text
  ┌──────────────────────┐
  │  heapify(a, 10, 8)   │ ◄─── push
  ├──────────────────────┤
  │  heapify(a, 10, 3)   │
  └──────────────────────┘
```

- **Trạng thái mảng & Cây sau khi hoán vị:**
```text
                     [ 8 ]
                      (0)
                 /           \
             /                   \
         [ 12 ]                  [ 4 ]
          (1)                     (2)
        /      \                /     \
     [ 7 ]    [ 9 ]          [ 2 ]   [ 3 ]
      (3)      (4)            (5)     (6)
     /   \     /
   [ 3 ] [ 6 ][ 4 ]
    (7)   (8)  (9)

Index:    0    1    2    3    4    5    6    7    8    9
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │  8 │ 12 │  4 │  7 │  9 │  2 │  3 │  3 │  6 │  4 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
                           ▲                        ▲
                           └───────────┬────────────┘
                                 Hoán vị a[3] & a[8]
```

- **Thao tác 2:** `heapify(a, 10, 8)`
  - Chỉ số con: $\text{left} = 2 \times 8 + 1 = 17 > n$, $\text{right} = 2 \times 8 + 2 = 18 > n$.
  - Khởi tạo: $\text{largest} = 8$.
  - **Kiểm tra:** Cả con trái và con phải đều vượt quá kích thước $n = 10$ $\Rightarrow$ **False**.
  - **Kiểm tra:** $\text{largest} \ne i$ ($8 \ne 8$) $\Rightarrow$ **False**.
  - $\Rightarrow$ Kết thúc hàm, lần lượt lấy ra khỏi Call Stack:
    - `pop` `heapify(a, 10, 8)`.
    - `pop` `heapify(a, 10, 3)`.

- **Mô hình Call Stack (Pop kết thúc):**
```text
  ┌──────────────────────┐
  │  heapify(a, 10, 8)   │ ───► pop
  ├──────────────────────┤
  │  heapify(a, 10, 3)   │ ───► pop
  └──────────────────────┘
```

---

##### ◈ Bước 3: Xét $i = 2$

- **Thao tác:** `heapify(a, 10, 2)`
  - Chỉ số con: $\text{left} = 2 \times 2 + 1 = 5$, $\text{right} = 2 \times 2 + 2 = 6$.
  - Khởi tạo: $\text{largest} = 2$.
  - **Kiểm tra con trái:** `a[left] > a[largest]` $\Leftrightarrow a[5] > a[2]$ ($2 > 4$) $\Rightarrow$ **False**.
  - **Kiểm tra con phải:** `a[right] > a[largest]` $\Leftrightarrow a[6] > a[2]$ ($3 > 4$) $\Rightarrow$ **False**.
  - **Kiểm tra:** $\text{largest} \ne i$ ($2 \ne 2$) $\Rightarrow$ **False**.
  - $\Rightarrow$ Không đổi chỗ.

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 10, 2)   │ ───► pop
  └──────────────────────┘
```

- **Trạng thái mảng & Cây:** Giữ nguyên không đổi.
```text
Index:    0    1    2    3    4    5    6    7    8    9
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │  8 │ 12 │  4 │  7 │  9 │  2 │  3 │  3 │  6 │  4 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
```

---

##### ◈ Bước 4: Xét $i = 1$

- **Thao tác:** `heapify(a, 10, 1)`
  - Chỉ số con: $\text{left} = 2 \times 1 + 1 = 3$, $\text{right} = 2 \times 1 + 2 = 4$.
  - Khởi tạo: $\text{largest} = 1$.
  - **Kiểm tra con trái:** `a[left] > a[largest]` $\Leftrightarrow a[3] > a[1]$ ($7 > 12$) $\Rightarrow$ **False**.
  - **Kiểm tra con phải:** `a[right] > a[largest]` $\Leftrightarrow a[4] > a[1]$ ($9 > 12$) $\Rightarrow$ **False**.
  - **Kiểm tra:** $\text{largest} \ne i$ ($1 \ne 1$) $\Rightarrow$ **False**.
  - $\Rightarrow$ Không đổi chỗ.

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 10, 1)   │ ───► pop
  └──────────────────────┘
```

- **Trạng thái mảng & Cây:** Giữ nguyên không đổi.
```text
Index:    0    1    2    3    4    5    6    7    8    9
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │  8 │ 12 │  4 │  7 │  9 │  2 │  3 │  3 │  6 │  4 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
```

---

##### ◈ Bước 5: Xét $i = 0$ (Nốt gốc)

Quá trình vun đống tại gốc lan truyền qua 3 bước đệ quy:

- **Thao tác 1:** `heapify(a, 10, 0)`
  - Chỉ số con: $\text{left} = 1$, $\text{right} = 2$.
  - Khởi tạo: $\text{largest} = 0$.
  - **Kiểm tra con trái:** `a[left] > a[largest]` $\Leftrightarrow a[1] > a[0]$ ($12 > 8$) $\Rightarrow$ **True** $\Rightarrow$ Cập nhật $\text{largest} = 1$.
  - **Kiểm tra con phải:** `a[right] > a[largest]` $\Leftrightarrow a[2] > a[1]$ ($4 > 12$) $\Rightarrow$ **False**.
  - **Kiểm tra:** $\text{largest} = 1 \ne i = 0$ $\Rightarrow$ **True**.
  - $\Rightarrow$ **Thực hiện hoán vị:** $\text{swap}(a[0], a[1]) \Leftrightarrow \text{swap}(8, 12)$ (đưa $12$ lên làm gốc, hạ $8$ xuống nốt $1$).
  - $\Rightarrow$ **Gọi đệ quy:** `heapify(a, 10, 1)`.

- **Mô hình Call Stack (Push `heapify(a, 10, 1)`):**
```text
  ┌──────────────────────┐
  │  heapify(a, 10, 1)   │ ◄─── push
  ├──────────────────────┤
  │  heapify(a, 10, 0)   │
  └──────────────────────┘
```

- **Trạng thái sau Thao tác 1:**
```text
                     [ 12 ]
                      (0)
                 /           \
             /                   \
         [ 8 ]                   [ 4 ]
          (1)                     (2)
        /      \                /     \
     [ 7 ]    [ 9 ]          [ 2 ]   [ 3 ]
      (3)      (4)            (5)     (6)
     /   \     /
   [ 3 ] [ 6 ][ 4 ]
    (7)   (8)  (9)

Index:    0    1    2    3    4    5    6    7    8    9
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │ 12 │  8 │  4 │  7 │  9 │  2 │  3 │  3 │  6 │  4 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
          ▲    ▲
          └──┬─┘
        Hoán vị a[0] & a[1]
```

- **Thao tác 2:** `heapify(a, 10, 1)`
  - Chỉ số con: $\text{left} = 2 \times 1 + 1 = 3$, $\text{right} = 2 \times 1 + 2 = 4$.
  - Khởi tạo: $\text{largest} = 1$.
  - **Kiểm tra con trái:** `a[left] > a[largest]` $\Leftrightarrow a[3] > a[1]$ ($7 > 8$) $\Rightarrow$ **False**.
  - **Kiểm tra con phải:** `a[right] > a[largest]` $\Leftrightarrow a[4] > a[1]$ ($9 > 8$) $\Rightarrow$ **True** $\Rightarrow$ Cập nhật $\text{largest} = 4$.
  - **Kiểm tra:** $\text{largest} = 4 \ne i = 1$ $\Rightarrow$ **True**.
  - $\Rightarrow$ **Thực hiện hoán vị:** $\text{swap}(a[1], a[4]) \Leftrightarrow \text{swap}(8, 9)$ (đưa $9$ lên nốt $1$, hạ $8$ xuống nốt $4$).
  - $\Rightarrow$ **Gọi đệ quy:** `heapify(a, 10, 4)`.

- **Mô hình Call Stack (Push `heapify(a, 10, 4)`):**
```text
  ┌──────────────────────┐
  │  heapify(a, 10, 4)   │ ◄─── push
  ├──────────────────────┤
  │  heapify(a, 10, 1)   │
  ├──────────────────────┤
  │  heapify(a, 10, 0)   │
  └──────────────────────┘
```

- **Trạng thái sau Thao tác 2:**
```text
                     [ 12 ]
                      (0)
                 /           \
             /                   \
         [ 9 ]                   [ 4 ]
          (1)                     (2)
        /      \                /     \
     [ 7 ]    [ 8 ]          [ 2 ]   [ 3 ]
      (3)      (4)            (5)     (6)
     /   \     /
   [ 3 ] [ 6 ][ 4 ]
    (7)   (8)  (9)

Index:    0    1    2    3    4    5    6    7    8    9
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │ 12 │  9 │  4 │  7 │  8 │  2 │  3 │  3 │  6 │  4 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
               ▲              ▲
               └──────┬───────┘
             Hoán vị a[1] & a[4]
```

- **Thao tác 3:** `heapify(a, 10, 4)`
  - Chỉ số con: $\text{left} = 2 \times 4 + 1 = 9$, $\text{right} = 2 \times 4 + 2 = 10 \ge n$.
  - Khởi tạo: $\text{largest} = 4$.
  - **Kiểm tra con trái:** `a[left] > a[largest]` $\Leftrightarrow a[9] > a[4]$ ($4 > 8$) $\Rightarrow$ **False**.
  - **Kiểm tra con phải:** $\text{right} = 10 \ge n$ $\Rightarrow$ **False**.
  - **Kiểm tra:** $\text{largest} \ne i$ ($4 \ne 4$) $\Rightarrow$ **False**.
  - $\Rightarrow$ Không xảy ra hoán vị, kết thúc đệ quy. Lần lượt `pop` sạch các hàm khỏi Call Stack:
    - `pop` `heapify(a, 10, 4)`.
    - `pop` `heapify(a, 10, 1)`.
    - `pop` `heapify(a, 10, 0)`.

- **Mô hình Call Stack (Pop toàn bộ):**
```text
  ┌──────────────────────┐
  │  heapify(a, 10, 4)   │ ───► pop
  ├──────────────────────┤
  │  heapify(a, 10, 1)   │ ───► pop
  ├──────────────────────┤
  │  heapify(a, 10, 0)   │ ───► pop
  └──────────────────────┘
```

---

#### 4. Kết quả hoàn thành Max-Heap

Sau toàn bộ vòng lặp xây dựng heap (`Build Max-Heap`), cây nhị phân đã đạt cấu trúc Max-Heap hoàn chỉnh (mọi nốt cha đều $\ge$ các nốt con):

```text
                     [ 12 ]
                      (0)
                 /           \
             /                   \
         [ 9 ]                   [ 4 ]
          (1)                     (2)
        /      \                /     \
     [ 7 ]    [ 8 ]          [ 2 ]   [ 3 ]
      (3)      (4)            (5)     (6)
     /   \     /
   [ 3 ] [ 6 ][ 4 ]
    (7)   (8)  (9)
```

Mảng kết quả Max-Heap thu được:
```text
Index:    0    1    2    3    4    5    6    7    8    9
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │ 12 │  9 │  4 │  7 │  8 │  2 │  3 │  3 │  6 │  4 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
```

#### 5. Quá trình Sort Heap cho Max-Heap (Heap Sort)

Sau khi hoàn tất quá trình **Build Max-Heap**, ta thu được mảng:
```text
Index:    0    1    2    3    4    5    6    7    8    9
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │ 12 │  9 │  4 │  7 │  8 │  2 │  3 │  3 │  6 │  4 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
```

Biến $i$ duyệt từ $9$ về $0$ ($i = 9, 8, 7, \dots$):

---

##### ◈ Xét $i = 9$

- **Thao tác hoán vị:** `swap(a[0], a[9]) = swap(12, 4)`
- **Đẩy vào Call Stack:** `heapify(a, 9, 0)`

```text
       Cây sau khi hoán vị a[0] và a[9]
                     [ 4 ]
                      (0)
                 /           \
             /                   \
         [ 9 ]                   [ 4 ]
          (1)                     (2)
        /      \                /     \
     [ 7 ]    [ 8 ]          [ 2 ]   [ 3 ]
      (3)      (4)            (5)     (6)
     /   \     /
   [ 3 ] [ 6 ]┆[ 12 ]┆ (Tách khỏi heap)
    (7)   (8)  - (9) -

Index:    0    1    2    3    4    5    6    7    8  │  9 (Đã sắp xếp)
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┼────┐
a:      │  4 │  9 │  4 │  7 │  8 │  2 │  3 │  3 │  6 │ 12 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┼────┘
          ▲                                            ▲
          └─────────────────────┬──────────────────────┘
                              Hoán vị a[0] & a[9]
```

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 9, 0)    │ ◄─── push
  └──────────────────────┘
```

- **Thao tác `heapify(a, 9, 0)`:**

  - **Bước 1: `heapify(a, 9, 0)`**
    - $\text{left} = 1$, $\text{right} = 2$, $\text{largest} = 0$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[1] > a[0]$ ($9 > 4$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 1$.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[2] > a[1]$ ($4 > 9$) $\Rightarrow$ **False**.
    - $\text{Check } \text{largest} = 1 \ne i = 0$ nên:
      - $\text{swap}(a[0], a[1])$ (đổi chỗ $4$ và $9$).
      - Gọi đệ quy: `heapify(a, 9, 1)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 9, 1)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 9, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 1:
                         [ 9 ]
                          (0)
                     /           \
                 /                   \
             [ 4 ]                   [ 4 ]
              (1)                     (2)
            /      \                /     \
         [ 7 ]    [ 8 ]          [ 2 ]   [ 3 ]
          (3)      (4)            (5)     (6)
         /   \     /
       [ 3 ] [ 6 ]┆[ 12 ]┆ (Đã tách)
        (7)   (8)  - (9) -

    Index:    0    1    2    3    4    5    6    7    8  │  9 (Đã sắp xếp)
            ┌────┬────┬────┬────┬────┬────┬────┬────┬────┼────┐
    a:      │  9 │  4 │  4 │  7 │  8 │  2 │  3 │  3 │  6 │ 12 │
            └────┴────┴────┴────┴────┴────┴────┴────┴────┼────┘
              ▲    ▲
              └──┬─┘
            Hoán vị a[0] & a[1]
    ```

  - **Bước 2: `heapify(a, 9, 1)`**
    - $\text{left} = 3$, $\text{right} = 4$, $\text{largest} = 1$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[3] > a[1]$ ($7 > 4$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 3$.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[4] > a[3]$ ($8 > 7$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 4$.
    - $\text{Check } \text{largest} = 4 \ne i = 1$ nên:
      - $\text{swap}(a[1], a[4])$ (đổi chỗ $4$ và $8$).
      - Gọi đệ quy: `heapify(a, 9, 4)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 9, 4)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 9, 1)    │
      ├──────────────────────┤
      │  heapify(a, 9, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 2:
                         [ 9 ]
                          (0)
                     /           \
                 /                   \
             [ 8 ]                   [ 4 ]
              (1)                     (2)
            /      \                /     \
         [ 7 ]    [ 4 ]          [ 2 ]   [ 3 ]
          (3)      (4)            (5)     (6)
         /   \     /
       [ 3 ] [ 6 ]┆[ 12 ]┆ (Đã tách)
        (7)   (8)  - (9) -

    Index:    0    1    2    3    4    5    6    7    8  │  9 (Đã sắp xếp)
            ┌────┬────┬────┬────┬────┬────┬────┬────┬────┼────┐
    a:      │  9 │  8 │  4 │  7 │  4 │  2 │  3 │  3 │  6 │ 12 │
            └────┴────┴────┴────┴────┴────┴────┴────┴────┼────┘
                   ▲              ▲
                   └──────┬───────┘
                 Hoán vị a[1] & a[4]
    ```

  - **Bước 3: `heapify(a, 9, 4)`**
    - $\text{left} = 2 \times 4 + 1 = 9 \ge 9$, $\text{right} = 10 \ge 9$.
    - $\Rightarrow$ **Return** do gốc con tại $a[4]$ không có con trong heap ($n = 9$).
    - Lần lượt `pop` sạch các hàm khỏi Call Stack:
      - `pop` `heapify(a, 9, 4)`.
      - `pop` `heapify(a, 9, 1)`.
      - `pop` `heapify(a, 9, 0)`.

    ```text
    Mô hình Call Stack (Pop toàn bộ):
      ┌──────────────────────┐
      │  heapify(a, 9, 4)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 9, 1)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 9, 0)    │ ───► pop
      └──────────────────────┘
    ```
    - Cây và mảng giữ nguyên: `[9, 8, 4, 7, 4, 2, 3, 3, 6, 12]`.

---

##### ◈ Xét $i = 8$

- **Thao tác hoán vị:** `swap(a[0], a[8]) = swap(9, 6)`
- **Đẩy vào Call Stack:** `heapify(a, 8, 0)`

```text
       Cây sau khi hoán vị a[0] và a[8]
                     [ 6 ]
                      (0)
                 /           \
             /                   \
         [ 8 ]                   [ 4 ]
          (1)                     (2)
        /      \                /     \
     [ 7 ]    [ 4 ]          [ 2 ]   [ 3 ]
      (3)      (4)            (5)     (6)
     /   \
   [ 3 ] ┆[ 9 ]┆ (Tách khỏi heap)
    (7)   - (8) -

Index:    0    1    2    3    4    5    6    7  │  8    9 (Đã sắp xếp)
        ┌────┬────┬────┬────┬────┬────┬────┬────┼────┬────┐
a:      │  6 │  8 │  4 │  7 │  4 │  2 │  3 │  3 │  9 │ 12 │
        └────┴────┴────┴────┴────┴────┴────┴────┼────┴────┘
          ▲                                       ▲
          └───────────────────┬───────────────────┘
                            Hoán vị a[0] & a[8]
```

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 8, 0)    │ ◄─── push
  └──────────────────────┘
```

- **Thao tác `heapify(a, 8, 0)`:**

  - **Bước 1: `heapify(a, 8, 0)`**
    - $\text{left} = 1$, $\text{right} = 2$, $\text{largest} = 0$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[1] > a[0]$ ($8 > 6$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 1$.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[2] > a[1]$ ($4 > 8$) $\Rightarrow$ **False**.
    - $\text{Check } \text{largest} = 1 \ne i = 0$ nên:
      - $\text{swap}(a[0], a[1])$ (đổi chỗ $6$ và $8$).
      - Gọi đệ quy: `heapify(a, 8, 1)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 8, 1)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 8, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 1:
                         [ 8 ]
                          (0)
                     /           \
                 /                   \
             [ 6 ]                   [ 4 ]
              (1)                     (2)
            /      \                /     \
         [ 7 ]    [ 4 ]          [ 2 ]   [ 3 ]
          (3)      (4)            (5)     (6)
         /   \
       [ 3 ] ┆[ 9 ]┆ (Đã tách)
        (7)   - (8) -

    Index:    0    1    2    3    4    5    6    7  │  8    9 (Đã sắp xếp)
            ┌────┬────┬────┬────┬────┬────┬────┬────┼────┬────┐
    a:      │  8 │  6 │  4 │  7 │  4 │  2 │  3 │  3 │  9 │ 12 │
            └────┴────┴────┴────┴────┴────┴────┴────┼────┴────┘
              ▲    ▲
              └──┬─┘
            Hoán vị a[0] & a[1]
    ```

  - **Bước 2: `heapify(a, 8, 1)`**
    - $\text{left} = 3$, $\text{right} = 4$, $\text{largest} = 1$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[3] > a[1]$ ($7 > 6$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 3$.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[4] > a[3]$ ($4 > 7$) $\Rightarrow$ **False**.
    - $\text{Check } \text{largest} = 3 \ne i = 1$ nên:
      - $\text{swap}(a[1], a[3])$ (đổi chỗ $6$ và $7$).
      - Gọi đệ quy: `heapify(a, 8, 3)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 8, 3)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 8, 1)    │
      ├──────────────────────┤
      │  heapify(a, 8, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 2:
                         [ 8 ]
                          (0)
                     /           \
                 /                   \
             [ 7 ]                   [ 4 ]
              (1)                     (2)
            /      \                /     \
         [ 6 ]    [ 4 ]          [ 2 ]   [ 3 ]
          (3)      (4)            (5)     (6)
         /   \
       [ 3 ] ┆[ 9 ]┆ (Đã tách)
        (7)   - (8) -

    Index:    0    1    2    3    4    5    6    7  │  8    9 (Đã sắp xếp)
            ┌────┬────┬────┬────┬────┬────┬────┬────┼────┬────┐
    a:      │  8 │  7 │  4 │  6 │  4 │  2 │  3 │  3 │  9 │ 12 │
            └────┴────┴────┴────┴────┴────┴────┴────┼────┴────┘
                   ▲         ▲
                   └────┬────┘
                 Hoán vị a[1] & a[3]
    ```

  - **Bước 3: `heapify(a, 8, 3)`**
    - $\text{left} = 2 \times 3 + 1 = 7$, $\text{right} = 8 \ge 8$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[7] > a[3]$ ($3 > 6$) $\Rightarrow$ **False**.
    - $\Rightarrow$ **Return** (kết thúc đệ quy do $a[3] \ge$ con).
    - Lần lượt `pop` sạch các hàm khỏi Call Stack:
      - `pop` `heapify(a, 8, 3)`.
      - `pop` `heapify(a, 8, 1)`.
      - `pop` `heapify(a, 8, 0)`.

    ```text
    Mô hình Call Stack (Pop toàn bộ):
      ┌──────────────────────┐
      │  heapify(a, 8, 3)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 8, 1)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 8, 0)    │ ───► pop
      └──────────────────────┘
    ```
    - Cây và mảng giữ nguyên: `[8, 7, 4, 6, 4, 2, 3, 3, 9, 12]`.

---

##### ◈ Xét $i = 7$

- **Thao tác hoán vị:** `swap(a[0], a[7]) = swap(8, 3)`
- **Đẩy vào Call Stack:** `heapify(a, 7, 0)`

```text
       Cây sau khi hoán vị a[0] và a[7]
                     [ 3 ]
                      (0)
                 /           \
             /                   \
         [ 7 ]                   [ 4 ]
          (1)                     (2)
        /      \                /     \
     [ 6 ]    [ 4 ]          [ 2 ]   [ 3 ]
      (3)      (4)            (5)     (6)
     /
   ┆[ 8 ]┆ (Tách khỏi heap)
    - (7) -

Index:    0    1    2    3    4    5    6  │  7    8    9 (Đã sắp xếp)
        ┌────┬────┬────┬────┬────┬────┬────┼────┬────┬────┐
a:      │  3 │  7 │  4 │  6 │  4 │  2 │  3 │  8 │  9 │ 12 │
        └────┴────┴────┴────┴────┴────┴────┼────┴────┴────┘
          ▲                                  ▲
          └────────────────┬─────────────────┘
                         Hoán vị a[0] & a[7]
```

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 7, 0)    │ ◄─── push
  └──────────────────────┘
```

- **Thao tác `heapify(a, 7, 0)`:**

  - **Bước 1: `heapify(a, 7, 0)`**
    - $\text{left} = 1$, $\text{right} = 2$, $\text{largest} = 0$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[1] > a[0]$ ($7 > 3$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 1$.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[2] > a[1]$ ($4 > 7$) $\Rightarrow$ **False**.
    - $\text{Check } \text{largest} = 1 \ne i = 0$ nên:
      - $\text{swap}(a[0], a[1])$ (đổi chỗ $3$ và $7$).
      - Gọi đệ quy: `heapify(a, 7, 1)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 7, 1)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 7, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 1:
                         [ 7 ]
                          (0)
                     /           \
                 /                   \
             [ 3 ]                   [ 4 ]
              (1)                     (2)
            /      \                /     \
         [ 6 ]    [ 4 ]          [ 2 ]   [ 3 ]
          (3)      (4)            (5)     (6)
         /
       ┆[ 8 ]┆ (Đã tách)
        - (7) -

    Index:    0    1    2    3    4    5    6  │  7    8    9 (Đã sắp xếp)
            ┌────┬────┬────┬────┬────┬────┬────┼────┬────┬────┐
    a:      │  7 │  3 │  4 │  6 │  4 │  2 │  3 │  8 │  9 │ 12 │
            └────┴────┴────┴────┴────┴────┴────┼────┴────┴────┘
              ▲    ▲
              └──┬─┘
            Hoán vị a[0] & a[1]
    ```

  - **Bước 2: `heapify(a, 7, 1)`**
    - $\text{left} = 3$, $\text{right} = 4$, $\text{largest} = 1$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[3] > a[1]$ ($6 > 3$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 3$.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[4] > a[3]$ ($4 > 6$) $\Rightarrow$ **False**.
    - $\text{Check } \text{largest} = 3 \ne i = 1$ nên:
      - $\text{swap}(a[1], a[3])$ (đổi chỗ $3$ và $6$).
      - Gọi đệ quy: `heapify(a, 7, 3)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 7, 3)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 7, 1)    │
      ├──────────────────────┤
      │  heapify(a, 7, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 2:
                         [ 7 ]
                          (0)
                     /           \
                 /                   \
             [ 6 ]                   [ 4 ]
              (1)                     (2)
            /      \                /     \
         [ 3 ]    [ 4 ]          [ 2 ]   [ 3 ]
          (3)      (4)            (5)     (6)
         /
       ┆[ 8 ]┆ (Đã tách)
        - (7) -

    Index:    0    1    2    3    4    5    6  │  7    8    9 (Đã sắp xếp)
            ┌────┬────┬────┬────┬────┬────┬────┼────┬────┬────┐
    a:      │  7 │  6 │  4 │  3 │  4 │  2 │  3 │  8 │  9 │ 12 │
            └────┴────┴────┴────┴────┴────┴────┼────┴────┴────┘
                   ▲         ▲
                   └────┬────┘
                 Hoán vị a[1] & a[3]
    ```

  - **Bước 3: `heapify(a, 7, 3)`**
    - $\text{left} = 2 \times 3 + 1 = 7 \ge 7$, $\text{right} = 8 \ge 7$.
    - $\Rightarrow$ **Return** (kết thúc đệ quy do nốt $a[3]$ không có con trong heap $n = 7$).
    - Lần lượt `pop` sạch các hàm khỏi Call Stack:
      - `pop` `heapify(a, 7, 3)`.
      - `pop` `heapify(a, 7, 1)`.
      - `pop` `heapify(a, 7, 0)`.

    ```text
    Mô hình Call Stack (Pop toàn bộ):
      ┌──────────────────────┐
      │  heapify(a, 7, 3)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 7, 1)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 7, 0)    │ ───► pop
      └──────────────────────┘
    ```
    - Cây và mảng giữ nguyên: `[7, 6, 4, 3, 4, 2, 3, 8, 9, 12]`.

---

##### ◈ Xét $i = 6$

- **Thao tác hoán vị:** `swap(a[0], a[6]) = swap(7, 3)`
- **Đẩy vào Call Stack:** `heapify(a, 6, 0)`

```text
       Cây sau khi hoán vị a[0] và a[6]
                     [ 3 ]
                      (0)
                 /           \
             /                   \
         [ 6 ]                   [ 4 ]
          (1)                     (2)
        /      \                /
     [ 3 ]    [ 4 ]          [ 2 ]   ┆[ 7 ]┆ (Tách khỏi heap)
      (3)      (4)            (5)     - (6) -

Index:    0    1    2    3    4    5  │  6    7    8    9 (Đã sắp xếp)
        ┌────┬────┬────┬────┬────┬────┼────┬────┬────┬────┐
a:      │  3 │  6 │  4 │  3 │  4 │  2 │  7 │  8 │  9 │ 12 │
        └────┴────┴────┴────┴────┴────┼────┴────┴────┴────┘
          ▲                             ▲
          └──────────────┬──────────────┘
                    Hoán vị a[0] & a[6]
```

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 6, 0)    │ ◄─── push
  └──────────────────────┘
```

- **Thao tác `heapify(a, 6, 0)`:**

  - **Bước 1: `heapify(a, 6, 0)`**
    - $\text{left} = 1$, $\text{right} = 2$, $\text{largest} = 0$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[1] > a[0]$ ($6 > 3$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 1$.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[2] > a[1]$ ($4 > 6$) $\Rightarrow$ **False**.
    - $\text{Check } \text{largest} = 1 \ne i = 0$ nên:
      - $\text{swap}(a[0], a[1])$ (đổi chỗ $3$ và $6$).
      - Gọi đệ quy: `heapify(a, 6, 1)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 6, 1)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 6, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 1:
                         [ 6 ]
                          (0)
                     /           \
                 /                   \
             [ 3 ]                   [ 4 ]
              (1)                     (2)
            /      \                /
         [ 3 ]    [ 4 ]          [ 2 ]   ┆[ 7 ]┆ (Đã tách)
          (3)      (4)            (5)     - (6) -

    Index:    0    1    2    3    4    5  │  6    7    8    9 (Đã sắp xếp)
            ┌────┬────┬────┬────┬────┬────┼────┬────┬────┬────┐
    a:      │  6 │  3 │  4 │  3 │  4 │  2 │  7 │  8 │  9 │ 12 │
            └────┴────┴────┴────┴────┴────┼────┴────┴────┴────┘
              ▲    ▲
              └──┬─┘
            Hoán vị a[0] & a[1]
    ```

  - **Bước 2: `heapify(a, 6, 1)`**
    - $\text{left} = 3$, $\text{right} = 4$, $\text{largest} = 1$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[3] > a[1]$ ($3 > 3$) $\Rightarrow$ **False**.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[4] > a[1]$ ($4 > 3$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 4$.
    - $\text{Check } \text{largest} = 4 \ne i = 1$ nên:
      - $\text{swap}(a[1], a[4])$ (đổi chỗ $3$ và $4$).
      - Gọi đệ quy: `heapify(a, 6, 4)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 6, 4)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 6, 1)    │
      ├──────────────────────┤
      │  heapify(a, 6, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 2:
                         [ 6 ]
                          (0)
                     /           \
                 /                   \
             [ 4 ]                   [ 4 ]
              (1)                     (2)
            /      \                /
         [ 3 ]    [ 3 ]          [ 2 ]   ┆[ 7 ]┆ (Đã tách)
          (3)      (4)            (5)     - (6) -

    Index:    0    1    2    3    4    5  │  6    7    8    9 (Đã sắp xếp)
            ┌────┬────┬────┬────┬────┬────┼────┬────┬────┬────┐
    a:      │  6 │  4 │  4 │  3 │  3 │  2 │  7 │  8 │  9 │ 12 │
            └────┴────┴────┴────┴────┴────┼────┴────┴────┴────┘
                   ▲         ▲
                   └────┬────┘
                 Hoán vị a[1] & a[4]
    ```

  - **Bước 3: `heapify(a, 6, 4)`**
    - $\text{left} = 2 \times 4 + 1 = 9 \ge 6$, $\text{right} = 10 \ge 6$.
    - $\Rightarrow$ **Return** (kết thúc đệ quy do nốt $a[4]$ không có con trong heap $n = 6$).
    - Lần lượt `pop` sạch các hàm khỏi Call Stack:
      - `pop` `heapify(a, 6, 4)`.
      - `pop` `heapify(a, 6, 1)`.
      - `pop` `heapify(a, 6, 0)`.

    ```text
    Mô hình Call Stack (Pop toàn bộ):
      ┌──────────────────────┐
      │  heapify(a, 6, 4)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 6, 1)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 6, 0)    │ ───► pop
      └──────────────────────┘
    ```
    - Cây và mảng giữ nguyên: `[6, 4, 4, 3, 3, 2, 7, 8, 9, 12]`.

---

##### ◈ Xét $i = 5$

- **Thao tác hoán vị:** `swap(a[0], a[5]) = swap(6, 2)`
- **Đẩy vào Call Stack:** `heapify(a, 5, 0)`

```text
       Cây sau khi hoán vị a[0] và a[5]
                     [ 2 ]
                      (0)
                 /           \
             /                   \
         [ 4 ]                   [ 4 ]
          (1)                     (2)
        /      \
     [ 3 ]    [ 3 ]          ┆[ 6 ]┆ (Tách khỏi heap)
      (3)      (4)            - (5) -

Index:    0    1    2    3    4  │  5    6    7    8    9 (Đã sắp xếp)
        ┌────┬────┬────┬────┬────┼────┬────┬────┬────┬────┐
a:      │  2 │  4 │  4 │  3 │  3 │  6 │  7 │  8 │  9 │ 12 │
        └────┴────┴────┴────┴────┼────┴────┴────┴────┴────┘
          ▲                        ▲
          └───────────┬────────────┘
                 Hoán vị a[0] & a[5]
```

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 5, 0)    │ ◄─── push
  └──────────────────────┘
```

- **Thao tác `heapify(a, 5, 0)`:**

  - **Bước 1: `heapify(a, 5, 0)`**
    - $\text{left} = 1$, $\text{right} = 2$, $\text{largest} = 0$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[1] > a[0]$ ($4 > 2$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 1$.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[2] > a[1]$ ($4 > 4$) $\Rightarrow$ **False**.
    - $\text{Check } \text{largest} = 1 \ne i = 0$ nên:
      - $\text{swap}(a[0], a[1])$ (đổi chỗ $2$ và $4$).
      - Gọi đệ quy: `heapify(a, 5, 1)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 5, 1)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 5, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 1:
                         [ 4 ]
                          (0)
                     /           \
                 /                   \
             [ 2 ]                   [ 4 ]
              (1)                     (2)
            /      \
         [ 3 ]    [ 3 ]          ┆[ 6 ]┆ (Đã tách)
          (3)      (4)            - (5) -

    Index:    0    1    2    3    4  │  5    6    7    8    9 (Đã sắp xếp)
            ┌────┬────┬────┬────┬────┼────┬────┬────┬────┬────┐
    a:      │  4 │  2 │  4 │  3 │  3 │  6 │  7 │  8 │  9 │ 12 │
            └────┴────┴────┴────┴────┼────┴────┴────┴────┴────┘
              ▲    ▲
              └──┬─┘
            Hoán vị a[0] & a[1]
    ```

  - **Bước 2: `heapify(a, 5, 1)`**
    - $\text{left} = 3$, $\text{right} = 4$, $\text{largest} = 1$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[3] > a[1]$ ($3 > 2$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 3$.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[4] > a[3]$ ($3 > 3$) $\Rightarrow$ **False**.
    - $\text{Check } \text{largest} = 3 \ne i = 1$ nên:
      - $\text{swap}(a[1], a[3])$ (đổi chỗ $2$ và $3$).
      - Gọi đệ quy: `heapify(a, 5, 3)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 5, 3)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 5, 1)    │
      ├──────────────────────┤
      │  heapify(a, 5, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 2:
                         [ 4 ]
                          (0)
                     /           \
                 /                   \
             [ 3 ]                   [ 4 ]
              (1)                     (2)
            /      \
         [ 2 ]    [ 3 ]          ┆[ 6 ]┆ (Đã tách)
          (3)      (4)            - (5) -

    Index:    0    1    2    3    4  │  5    6    7    8    9 (Đã sắp xếp)
            ┌────┬────┬────┬────┬────┼────┬────┬────┬────┬────┐
    a:      │  4 │  3 │  4 │  2 │  3 │  6 │  7 │  8 │  9 │ 12 │
            └────┴────┴────┴────┴────┼────┴────┴────┴────┴────┘
                   ▲         ▲
                   └────┬────┘
                 Hoán vị a[1] & a[3]
    ```

  - **Bước 3: `heapify(a, 5, 3)`**
    - $\text{left} = 2 \times 3 + 1 = 7 \ge 5$, $\text{right} = 8 \ge 5$.
    - $\Rightarrow$ **Return** (kết thúc đệ quy do nốt $a[3]$ không có con trong heap $n = 5$).
    - Lần lượt `pop` sạch các hàm khỏi Call Stack:
      - `pop` `heapify(a, 5, 3)`.
      - `pop` `heapify(a, 5, 1)`.
      - `pop` `heapify(a, 5, 0)`.

    ```text
    Mô hình Call Stack (Pop toàn bộ):
      ┌──────────────────────┐
      │  heapify(a, 5, 3)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 5, 1)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 5, 0)    │ ───► pop
      └──────────────────────┘
    ```
    - Cây và mảng giữ nguyên: `[4, 3, 4, 2, 3, 6, 7, 8, 9, 12]`.

---

##### ◈ Xét $i = 4$

- **Thao tác hoán vị:** `swap(a[0], a[4]) = swap(4, 3)`
- **Đẩy vào Call Stack:** `heapify(a, 4, 0)`

```text
       Cây sau khi hoán vị a[0] và a[4]
                     [ 3 ]
                      (0)
                 /           \
             /                   \
         [ 3 ]                   [ 4 ]
          (1)                     (2)
        /
     [ 2 ]                   ┆[ 4 ]┆ (Tách khỏi heap)
      (3)                     - (4) -

Index:    0    1    2    3  │  4    5    6    7    8    9 (Đã sắp xếp)
        ┌────┬────┬────┬────┼────┬────┬────┬────┬────┬────┐
a:      │  3 │  3 │  4 │  2 │  4 │  6 │  7 │  8 │  9 │ 12 │
        └────┴────┴────┴────┼────┴────┴────┴────┴────┴────┘
          ▲                   ▲
          └─────────┬─────────┘
               Hoán vị a[0] & a[4]
```

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 4, 0)    │ ◄─── push
  └──────────────────────┘
```

- **Thao tác `heapify(a, 4, 0)`:**

  - **Bước 1: `heapify(a, 4, 0)`**
    - $\text{left} = 1$, $\text{right} = 2$, $\text{largest} = 0$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[1] > a[0]$ ($3 > 3$) $\Rightarrow$ **False**.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[2] > a[0]$ ($4 > 3$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 2$.
    - $\text{Check } \text{largest} = 2 \ne i = 0$ nên:
      - $\text{swap}(a[0], a[2])$ (đổi chỗ $3$ và $4$).
      - Gọi đệ quy: `heapify(a, 4, 2)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 4, 2)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 4, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 1:
                         [ 4 ]
                          (0)
                     /           \
                 /                   \
             [ 3 ]                   [ 3 ]
              (1)                     (2)
            /
         [ 2 ]                   ┆[ 4 ]┆ (Đã tách)
          (3)                     - (4) -

    Index:    0    1    2    3  │  4    5    6    7    8    9 (Đã sắp xếp)
            ┌────┬────┬────┬────┼────┬────┬────┬────┬────┬────┐
    a:      │  4 │  3 │  3 │  2 │  4 │  6 │  7 │  8 │  9 │ 12 │
            └────┴────┴────┴────┼────┴────┴────┴────┴────┴────┘
              ▲         ▲
              └────┬────┘
            Hoán vị a[0] & a[2]
    ```

  - **Bước 2: `heapify(a, 4, 2)`**
    - $\text{left} = 2 \times 2 + 1 = 5 \ge 4$, $\text{right} = 6 \ge 4$.
    - $\Rightarrow$ **Return** (kết thúc đệ quy do nốt $a[2]$ không có con trong heap $n = 4$).
    - Lần lượt `pop` sạch các hàm khỏi Call Stack:
      - `pop` `heapify(a, 4, 2)`.
      - `pop` `heapify(a, 4, 0)`.

    ```text
    Mô hình Call Stack (Pop toàn bộ):
      ┌──────────────────────┐
      │  heapify(a, 4, 2)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 4, 0)    │ ───► pop
      └──────────────────────┘
    ```
    - Cây và mảng giữ nguyên: `[4, 3, 3, 2, 4, 6, 7, 8, 9, 12]`.

---

##### ◈ Xét $i = 3$

- **Thao tác hoán vị:** `swap(a[0], a[3]) = swap(4, 2)`
- **Đẩy vào Call Stack:** `heapify(a, 3, 0)`

```text
       Cây sau khi hoán vị a[0] và a[3]
                     [ 2 ]
                      (0)
                 /           \
             [ 3 ]           [ 3 ]   ┆[ 4 ]┆ (Tách khỏi heap)
              (1)             (2)     - (3) -

Index:    0    1    2  │  3    4    5    6    7    8    9 (Đã sắp xếp)
        ┌────┬────┬────┼────┬────┬────┬────┬────┬────┬────┐
a:      │  2 │  3 │  3 │  4 │  4 │  6 │  7 │  8 │  9 │ 12 │
        └────┴────┴────┼────┴────┴────┴────┴────┴────┴────┘
          ▲              ▲
          └──────┬───────┘
        Hoán vị a[0] & a[3]
```

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 3, 0)    │ ◄─── push
  └──────────────────────┘
```

- **Thao tác `heapify(a, 3, 0)`:**

  - **Bước 1: `heapify(a, 3, 0)`**
    - $\text{left} = 1$, $\text{right} = 2$, $\text{largest} = 0$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[1] > a[0]$ ($3 > 2$) $\Rightarrow$ **True** $\Rightarrow \text{largest} = 1$.
    - $\text{Check } a[\text{right}] > a[\text{largest}] \Leftrightarrow a[2] > a[1]$ ($3 > 3$) $\Rightarrow$ **False**.
    - $\text{Check } \text{largest} = 1 \ne i = 0$ nên:
      - $\text{swap}(a[0], a[1])$ (đổi chỗ $2$ và $3$).
      - Gọi đệ quy: `heapify(a, 3, 1)`.

    ```text
    Mô hình Call Stack:
      ┌──────────────────────┐
      │  heapify(a, 3, 1)    │ ◄─── push
      ├──────────────────────┤
      │  heapify(a, 3, 0)    │
      └──────────────────────┘

    Trạng thái sau Bước 1:
                         [ 3 ]
                          (0)
                     /           \
                 [ 2 ]           [ 3 ]   ┆[ 4 ]┆ (Đã tách)
                  (1)             (2)     - (3) -

    Index:    0    1    2  │  3    4    5    6    7    8    9 (Đã sắp xếp)
            ┌────┬────┬────┼────┬────┬────┬────┬────┬────┬────┐
    a:      │  3 │  2 │  3 │  4 │  4 │  6 │  7 │  8 │  9 │ 12 │
            └────┴────┴────┼────┴────┴────┴────┴────┴────┴────┘
              ▲    ▲
              └──┬─┘
            Hoán vị a[0] & a[1]
    ```

  - **Bước 2: `heapify(a, 3, 1)`**
    - $\text{left} = 2 \times 1 + 1 = 3 \ge 3$, $\text{right} = 4 \ge 3$.
    - $\Rightarrow$ **Return** (kết thúc đệ quy do nốt $a[1]$ không có con trong heap $n = 3$).
    - Lần lượt `pop` sạch các hàm khỏi Call Stack:
      - `pop` `heapify(a, 3, 1)`.
      - `pop` `heapify(a, 3, 0)`.

    ```text
    Mô hình Call Stack (Pop toàn bộ):
      ┌──────────────────────┐
      │  heapify(a, 3, 1)    │ ───► pop
      ├──────────────────────┤
      │  heapify(a, 3, 0)    │ ───► pop
      └──────────────────────┘
    ```
    - Cây và mảng giữ nguyên: `[3, 2, 3, 4, 4, 6, 7, 8, 9, 12]`.

---

##### ◈ Xét $i = 2$

- **Thao tác hoán vị:** `swap(a[0], a[2]) = swap(3, 3)`
- **Đẩy vào Call Stack:** `heapify(a, 2, 0)`

```text
       Cây sau khi hoán vị a[0] và a[2]
                     [ 3 ]
                      (0)
                 /           \
             [ 2 ]         ┆[ 3 ]┆ (Tách khỏi heap)
              (1)           - (2) -

Index:    0    1  │  2    3    4    5    6    7    8    9 (Đã sắp xếp)
        ┌────┬────┼────┬────┬────┬────┬────┬────┬────┬────┐
a:      │  3 │  2 │  3 │  4 │  4 │  6 │  7 │  8 │  9 │ 12 │
        └────┴────┼────┴────┴────┴────┴────┴────┴────┴────┘
          ▲         ▲
          └────┬────┘
        Hoán vị a[0] & a[2]
```

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 2, 0)    │ ◄─── push
  └──────────────────────┘
```

- **Thao tác `heapify(a, 2, 0)`:**

  - **Bước 1: `heapify(a, 2, 0)`**
    - $\text{left} = 1$, $\text{right} = 2 \ge 2$, $\text{largest} = 0$.
    - $\text{Check } a[\text{left}] > a[\text{largest}] \Leftrightarrow a[1] > a[0]$ ($2 > 3$) $\Rightarrow$ **False**.
    - $\text{Check } \text{largest} \ne i$ ($0 \ne 0$) $\Rightarrow$ **False**.
    - $\Rightarrow$ **Return** (kết thúc đệ quy).
    - `pop` `heapify(a, 2, 0)` khỏi Call Stack.

    ```text
    Mô hình Call Stack (Pop kết thúc):
      ┌──────────────────────┐
      │  heapify(a, 2, 0)    │ ───► pop
      └──────────────────────┘
    ```
    - Cây và mảng giữ nguyên: `[3, 2, 3, 4, 4, 6, 7, 8, 9, 12]`.

---

##### ◈ Xét $i = 1$

- **Thao tác hoán vị:** `swap(a[0], a[1]) = swap(3, 2)`
- **Đẩy vào Call Stack:** `heapify(a, 1, 0)`

```text
       Cây sau khi hoán vị a[0] và a[1]
                     [ 2 ]
                      (0)
                 /
             ┆[ 3 ]┆ (Tách khỏi heap)
              - (1) -

Index:    0  │  1    2    3    4    5    6    7    8    9 (Đã sắp xếp)
        ┌────┼────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │  2 │  3 │  3 │  4 │  4 │  6 │  7 │  8 │  9 │ 12 │
        └────┼────┴────┴────┴────┴────┴────┴────┴────┴────┘
          ▲    ▲
          └──┬─┘
        Hoán vị a[0] & a[1]
```

- **Mô hình Call Stack:**
```text
  ┌──────────────────────┐
  │  heapify(a, 1, 0)    │ ◄─── push
  └──────────────────────┘
```

- **Thao tác `heapify(a, 1, 0)`:**
  - $\text{left} = 1 \ge 1$, $\text{right} = 2 \ge 1$.
  - $\Rightarrow$ **Return** (kết thúc đệ quy do kích thước heap chỉ còn $1$ phần tử tại gốc).
  - `pop` `heapify(a, 1, 0)` khỏi Call Stack.

```text
    Mô hình Call Stack (Pop kết thúc):
      ┌──────────────────────┐
      │  heapify(a, 1, 0)    │ ───► pop
      └──────────────────────┘
```

---

##### ◈ Xét $i = 0$

- Kích thước heap lúc này chỉ còn phần tử gốc $a[0] = 2$.
- Thuật toán sắp xếp vun đống (Heap Sort) hoàn tất toàn bộ chu trình sắp xếp!

---

#### 6. Kết quả mảng sau khi sắp xếp hoàn chỉnh

Toàn bộ mảng $a$ sau khi kết thúc **Heap Sort** đã được sắp xếp tăng dần hoàn chỉnh:

```text
Index:    0    1    2    3    4    5    6    7    8    9
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
a:      │  2 │  3 │  3 │  4 │  4 │  6 │  7 │  8 │  9 │ 12 │
        └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
```