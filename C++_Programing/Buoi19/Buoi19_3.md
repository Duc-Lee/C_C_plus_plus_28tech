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
