# Lập trình C++ Cơ Bản & Nâng Cao (C++_Programing)

## Mục Lục Chuyên Đề

### 1. C++ Cơ Bản & Cú Pháp Nhập Môn
Nền tảng cú pháp, kiểu dữ liệu, toán tử, rẽ nhánh và vòng lặp.
* **[Buổi 1: Input & Output trong C++](./Buoi1/Buoi1.md)** — Nhập xuất `cin`, `cout`, các kiểu dữ liệu nguyên thủy, ép kiểu và định dạng.
* **[Buổi 2: Toán Tử (Operators)](./Buoi2/Buoi2.md)** — Toán tử gán, số học, so sánh, logic và thao tác bitwise.
* **[Buổi 3: Cấu Trúc Rẽ Nhánh](./Buoi3/Buoi3.md)** — Câu lệnh điều kiện `if`, `if-else`, toán tử 3 ngôi và `switch-case`.
* **[Buổi 4: Bài Tập Tổng Hợp (Buổi 1 - 3)](./Buoi4/Buoi4.md)** — Hệ thống bài tập rèn luyện tư duy rẽ nhánh và tính toán cơ bản.
* **[Buổi 5: Vòng Lặp (Loops)](./Buoi5/Buoi5.md)** — Vòng lặp `for`, `while`, `do-while`, điều khiển luồng với `break`, `continue`.
* **[Buổi 6: Hàm (Functions)](./Buoi6/Buoi6.md)** — Khái niệm hàm, phạm vi biến, nạp chồng hàm (overloading), tham trị và tham chiếu (`&`).

---

### 2. Con Trỏ, Mảng 1 Chiều & Ma Trận (2D Array)
Quản lý bộ nhớ, thao tác trên danh sách và các kỹ thuật tối ưu mảng.
* **[Buổi 7: Con Trỏ (Pointer) & Mảng 1 Chiều](./Buoi7/Buoi7.md)** — Bản chất con trỏ, toán tử `*` và `&`, con trỏ với mảng, cấp phát động (`new`/`delete`).
* **[Buổi 8: Mảng 1 Chiều (Array 1D)](./Buoi8/)**:
  * [Buổi 8: Lý thuyết mảng 1 chiều](./Buoi8/Buoi8.md)
  * [Buổi 8.1: Bài tập rèn luyện mảng 1 chiều (Phần 1)](./Buoi8/Buoi8_1.md)
  * [Buổi 8.2: Bài tập rèn luyện mảng 1 chiều (Phần 2)](./Buoi8/Buoi8_2.md)
* **[Buổi 9: Mảng 2 Chiều & Ma Trận](./Buoi9/Buoi9.md)** — Khai báo ma trận, duyệt hàng/cột, các bài toán đường chéo và ma trận xoắn ốc.
* **[Buổi 10: Mảng Cộng Dồn (Prefix Sum)](./Buoi10/Buoi10.md)** — Kỹ thuật mảng cộng dồn 1D & 2D, tối ưu truy vấn tổng đoạn con trong $O(1)$.
* **[Buổi 11: Bài Tập Mảng 2 Chiều](./Buoi11/)**:
  * [Buổi 11.1: Bài tập ma trận & số nguyên tố](./Buoi11/Buoi11_1.md)

---

### 3. Xâu Ký Tự (String)
Xử lý văn bản, chuỗi và các phương thức có sẵn trong C++.
* **[Buổi 12: Xâu Ký Tự (`std::string`)](./Buoi12/)**:
  * [Buổi 12.0: Lý thuyết `std::string` & các hàm xử lý xâu](./Buoi12/Buoi12_0.md) — Nhập xuất `getline`, các hàm `length`, `substr`, `find`, `stringstream`.

---

### 4. Thư Viện Chuẩn STL (Standard Template Library)
Các cấu trúc dữ liệu container quan trọng bậc nhất trong lập trình thi đấu và phỏng vấn.
* **[Buổi 13: Vector (`std::vector`)](./Buoi13/Buoi13.md)** — Mảng động linh hoạt, quản lý dung lượng, các thao tác `push_back`, `pop_back`, duyệt iterator.
* **[Buổi 14: Pair (`std::pair`)](./Buoi14/Buoi14.md)** — Kiểu dữ liệu ghép đôi, hàm `make_pair`, sắp xếp mảng các cặp giá trị.
* **[Buổi 15: Set (`std::set`, `multiset`, `unordered_set`)](./Buoi15/Buoi15.md)** — Tập hợp tự sắp xếp, không trùng lặp, các thao tác tìm kiếm, chèn, xóa $O(\log n)$.
* **[Buổi 16: Map (`std::map`, `multimap`, `unordered_map`)](./Buoi16/Buoi16.md)** — Cặp Key-Value, ứng dụng đếm tần suất xuất hiện và truy vấn ánh xạ.
* **[Buổi 17: Bài Tập Ứng Dụng Set & Map](./Buoi17/Buoi17.md)** — Hướng dẫn giải chi tiết các bài toán tối ưu với Set và Map.

---

### 5. Thuật Toán Tìm Kiếm & Sắp Xếp (Search & Sort)
* **[Buổi 18: Tìm Kiếm Tuyến Tính & Nhị Phân (Binary Search)](./Buoi18/Buoi18.md)**:
  * Linear Search $O(n)$ và Binary Search $O(\log n)$.
  * Nguyên lý chia để trị (Divide & Conquer) và mô phỏng từng bước.
  * Hàm `std::lower_bound()` ($\ge x$) và `std::upper_bound()` ($> x$).
* **[Buổi 19: Các Thuật Toán Sắp Xếp & Comparator](./Buoi19/)**:
  * [Buổi 19.0: Hàm `std::sort()` & Xây dựng hàm so sánh tùy biến (Comparator)](./Buoi19/Buoi19_0.md) — Sử dụng hàm `sort` trong STL, viết Comparator tùy biến cho mảng, vector, pair, struct.
  * [Buổi 19.1: Thuật toán sắp xếp cơ bản: Selection Sort, Insertion Sort, Bubble Sort, Counting Sort](./Buoi19/Buoi19_1.md) — Tư tưởng, mã giả, phân tích độ phức tạp và mô phỏng từng bước chạy.
  * [Buổi 19.2: Thuật toán sắp xếp trộn (Merge Sort) & Đếm số cặp nghịch thế](./Buoi19/Buoi19_2.md) — Tư tưởng chia và trị, mô phỏng Stack Memory, kỹ thuật trộn 2 mảng con và ứng dụng đếm số cặp nghịch thế $O(n \log n)$.
  * [Buổi 19.3: Thuật toán sắp xếp vun đống (Heap Sort)](./Buoi19/Buoi19_3.md) — Cây nhị phân hoàn chỉnh, cấu trúc Max/Min Heap, thao tác Heapify và thuật toán Heap Sort.
  * [Buổi 19.4: Thuật toán sắp xếp nhanh (Quick Sort)](./Buoi19/Buoi19_4.md) — Kỹ thuật phân hoạch Lomuto và phân hoạch Hoare, minh họa từng bước và cài đặt chi tiết.
  * [Buổi 19.5: Các hàm thuật toán thông dụng trong thư viện `<algorithm>`](./Buoi19/Buoi19_5.md) — Tổng hợp các hàm thuật toán tiện ích phổ biến trong C++ STL.