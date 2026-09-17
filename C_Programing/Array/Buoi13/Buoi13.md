# Bài tập Mảng 1 Chiều - Buổi 13

## Bài 21. Tìm hợp và giao của 2 mảng 1

Cho 2 mảng đã được sắp xếp tăng dần, thực hiện tìm hợp và giao của 2 mảng. Các phần tử trong mỗi mảng khác nhau đôi một.

### Input
- Dòng đầu tiên là số lượng phần tử của 2 dãy $n$ và $m$. ($1 \le n, m \le 10^6$).
- Dòng thứ 2 là $n$ phần tử trong dãy số 1. ($-10^6 \le a_i \le 10^6$).
- Dòng thứ 3 là $m$ phần tử trong dãy thứ 2. ($-10^6 \le a_i \le 10^6$).

### Output
- Dòng thứ 1 là hợp của 2 mảng
- Dòng thứ 2 là giao của 2 mảng

### Ví dụ
| Input | Output |
| :--- | :--- |
| 4 5<br>1 2 7 8<br>1 2 3 5 9 | 1 2 3 5 9<br>1 2 3 |

### Code 
- Cách 1: Dùng 2 con trỏ, Độ phức tạp $O(n+m)$
```cpp
            #include <stdio.h>

            int min(int a, int b) {
                return a < b ? a : b;
            }

            int main() {
                int n, m;
                scanf("%d %d", &n, &m);
                int a[n], b[m];
                
                // Khai báo 2 mảng 
                for (int i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                for (int i = 0; i < m; i++) {
                    scanf("%d", &b[i]);
                }
                
                int hop[n + m], giao[min(n, m)];
                int i = 0, j = 0, h = 0, g = 0;
                
                while (i < n && j < m) {
                    if (a[i] == b[j]) {
                        giao[g++] = a[i];
                        hop[h++] = a[i];
                        i++;
                        j++;
                    } else if (a[i] < b[j]) {
                        hop[h++] = a[i++];
                    } else {
                        hop[h++] = b[j++];
                    }
                }
                
                // Điền nốt các phần tử còn lại 
                while (i < n) {
                    hop[h++] = a[i++];
                }
                while (j < m) {
                    hop[h++] = b[j++];
                }
                
                // In ra hợp và giao 
                for (int k = 0; k < h; k++) {
                    printf("%d ", hop[k]);
                }
                printf("\n");
                for (int k = 0; k < g; k++) {
                    printf("%d ", giao[k]);
                }
                return 0;
            }
```

- Cách 2: Dùng phương pháp đếm tần suất
```cpp
                #include <stdio.h>

                int min(int a, int b) {
                    return a < b ? a : b;
                }

                int max(int a, int b) {
                    return a > b ? a : b;
                }

                // Khai báo mảng tần suất.
                // Phần tử trong khoảng [-10^6, 10^6], cần offset thêm 10^6
                // Kích thước mảng đánh dấu cần lớn hơn 2 * 10^6 + 1
                int cnt[2000005] = {0};

                int main() {
                    int n, m;
                    scanf("%d %d", &n, &m);
                    int a[n], b[m];
                    int max_val = -1e9, min_val = 1e9;
                    
                    // Khai báo 2 mảng 
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &a[i]);
                        cnt[a[i]]++;
                        min_val = min(min_val, a[i]);
                        max_val = max(max_val, a[i]);
                    }
                    for (int i = 0; i < m; i++) {
                        scanf("%d", &b[i]);
                        cnt[b[i]]++;
                        min_val = min(min_val, b[i]);
                        max_val = max(max_val, b[i]);
                    }
                    
                    // In mảng hợp (xuất hiện ở ít nhất 1 trong 2 mảng, tần suất >= 1)
                    for (int i = min_val; i <= max_val; i++) {
                        if (cnt[i]) {
                            printf("%d ", i);
                        }
                    }
                    printf("\n");
                    
                    // In mảng giao (các phần tử xuất hiện ở cả 2 mảng)
                    // Do trong mỗi mảng, các phần tử khác nhau đôi một
                    // Nên phần tử chung xuất hiện ở cả 2 mảng sẽ có tần suất bằng 2
                    for (int i = min_val; i <= max_val; i++) {
                        if (cnt[i] == 2) {
                            printf("%d ", i);
                        }
                    }
                    return 0;
                }
``` 

## Bài 22. Tìm hợp và giao của 2 mảng (Trường hợp mảng có các phần tử giống nhau)

Cho 2 mảng đã được sắp xếp tăng dần, thực hiện tìm hợp và giao của 2 mảng. Các phần tử trong mỗi mảng có thể trùng nhau, kết quả của hợp và giao chỉ chứa các giá trị độc nhất (unique) sắp xếp tăng dần.

### Input
- Dòng đầu tiên là số lượng phần tử của 2 dãy $n$ và $m$. ($1 \le n, m \le 10^6$).
- Dòng thứ 2 là $n$ phần tử trong dãy số 1. ($-10^6 \le a_i \le 10^6$).
- Dòng thứ 3 là $m$ phần tử trong dãy thứ 2. ($-10^6 \le a_i \le 10^6$).

### Output
- Dòng thứ 1 là hợp của 2 mảng (chỉ in giá trị độc nhất)
- Dòng thứ 2 là giao của 2 mảng (chỉ in giá trị độc nhất)

### Ví dụ 
| Input | Output |
| :--- | :--- |
| 4 8<br>1 2 8 8<br>1 2 3 5 9 9 9 9 | 1 2 3 5 8 9 <br> 1 2 |

### Code 
- Cách 1: Dùng phương pháp đếm tần suất (Sử dụng mảng đánh dấu/định danh)
```cpp
                #include <stdio.h>

                int min(int a, int b) {
                    return a < b ? a : b;
                }

                int max(int a, int b) {
                    return a > b ? a : b;
                }

                // Khai báo mảng tần suất.
                // Phần tử trong khoảng [-10^6, 10^6], cần offset thêm 10^6
                // Kích thước mảng đánh dấu cần lớn hơn 2 * 10^6 + 1
                int cnt[2000005] = {0};

                int main() {
                    int n, m;
                    scanf("%d %d", &n, &m);
                    int a[n], b[m];
                    int max_val = -1e9, min_val = 1e9;
                    
                    // Khai báo 2 mảng 
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &a[i]);
                        // gán các số xuất hiện ở mảng a[i] = -1
                        cnt[a[i]] = -1;
                        min_val = min(min_val, a[i]);
                        max_val = max(max_val, a[i]);
                    }
                    for (int i = 0; i < m; i++) {
                        scanf("%d", &b[i]);
                        // Nếu mảng b gặp lại thì gán 2 để làm mốc cho mảng giao
                        if( cnt[b[i]] == -1) cnt[b[i]] = 2;
                        // Nếu không thì thêm các phẩn tử mảng a không có
                        else cnt[b[i]] == 1;
                        min_val = min(min_val, b[i]);
                        max_val = max(max_val, b[i]);
                    }
                    
                    // In mảng hợp (xuất hiện ở ít nhất 1 trong 2 mảng
                    for (int i = min_val; i <= max_val; i++) {
                        if (cnt[i] != 0) {
                            printf("%d ", i);
                        }
                    }
                    printf("\n");
                    // In mảng giao (các phần tử xuất hiện ở cả 2 mảng)
                    // Do trong mỗi mảng, các phần tử khác nhau đôi một
                    // Nên phần tử chung xuất hiện ở cả 2 mảng sẽ có tần suất bằng 2
                    for (int i = min_val; i <= max_val; i++) {
                        if (cnt[i] == 2) {
                            printf("%d ", i);
                        }
                    }
                    return 0;
                }
``` 