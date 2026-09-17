# Bài tập Mảng 1 Chiều - Buổi 18

## Bài 29. Liệt kê và đếm

Cho một dãy các số nguyên dương không quá 9 chữ số, mỗi số cách nhau vài khoảng trống, có thể xuống dòng. Hãy tìm các số không giảm (các chữ số theo thứ tự từ trái qua phải tạo thành dãy không giảm) và đếm số lần xuất hiện của các số đó.

### Input
- Gồm các số nguyên dương không quá 9 chữ số. Không quá 100000 số.

### Output
- Ghi ra các số không giảm kèm theo số lần xuất hiện. Các số được liệt kê theo thứ tự sắp xếp số lần xuất hiện giảm dần.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 123 321 23456 123 123 23456 3523 123 321<br>8988 7654 9899 3456 123 999 3456<br>987654321 4546 6354 4656 13432 4563<br>123471 659837 454945 34355 9087 9977<br>98534 3456 23134 | 123 5<br>3456 3<br>23456 2<br>999 1 |

### Code
```cpp
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Khởi tạo cấu trúc lưu giá trị và tần số
typedef struct {
    int val;
    int fre;
} number;

// Hàm kiểm tra xem số đó có tăng dần không
int check(int n){
    // Điều kiện dừng khi n >= 10 
    while(n >= 10){
        int r = n % 10;
        // nếu số trước lớn hơn số sau thì trả về 0 luôn
        if(r < (n/10)%10) return 0;
        n /= 10;
    }
    return 1;
}

// Hàm tìm kiếm vị trí của số x trong mảng cấu trúc a
int find(number a[], int n, int x){
    for(int i = 0; i < n; i++){
        // nếu tìm thấy thì trả về idx của nó
        if(a[i].val == x)
            return i;
    }
    return -1;
}

// Hàm so sánh dùng cho qsort
int cmp(const void *a, const void *b){
    number *x = (number*)a;
    number *y = (number*)b;
    return y->fre - x->fre;
}

int main(){
    number a[100001];
    int n = 0;
    int x;
    while((scanf("%d", &x)) != -1){
        if(check(x)){
            int idx = find(a, n, x);
            if(idx != -1){
                a[idx].fre += 1;
            }
            else{
                a[n].val = x;
                a[n].fre = 1;
                ++n;
            }
        }
    }
    qsort(a, n, sizeof(number), cmp);
    for(int i = 0; i < n; i++){
        printf("%d %d\n", a[i].val, a[i].fre);
    }
    return 0;
}
```