**Bài 1. Kiểm tra số nguyên tố**

**Input**

Số nguyên n (0≤n≤10^9).

**Output**

In YES nếu n là số nguyên tố, ngược lại in NO.

**Ví dụ**

| Input | Output |
|---|---|
| 4 | NO |
| 13 | YES |

**Code**
```cpp
                    #include <stdio.h>
                    #include <math.h>
                    
                    // Kiem tra so nguyen to
                    // Do phuc tap O(n)
                    int prime(int n){
                        int cnt = 0;
                        for(int i = 1; i <= n;i++){
                            if(n % i == 0) ++cnt;
                        }
                        // neu so uoc cua n == 2 thi la so nguyen to
                        if( cnt == 2)
                            return 1;
                        return 0;
                    }
                    // Do phuc tap O(log(n))
                    int nt(int n){
                        // so nguyen to la so >= 2
                        // la so chia het cho 1 va chinh no
                        for(int i = 2;i<= sqrt(n);i++){
                            // tinh uoc cua so 
                            // neu uoc cua n co 1 so nao do nua
                            // thi khong phai so nguyen to 
                            if(n % i == 0){
                                return 0;
                            }
                        }
                        // ko 
                        return n>1;
                    }
                    int main(){
                        int n;
                        scanf("%d",&n);
                        if(nt(n)){
                            printf("Day la so nguyen to\n");
                        }else{
                            printf("Day khong phai so nguyen to\n");
                        }
                    }

```
- Giải thích tại sao vòng lặp chạy đến `sqrt(n)` là tối ưu t:
    - Giả sử `n` không phải là số nguyên tố (tức `n` là hợp số). Khi đó `n` có thể được biểu diễn dưới dạng tích của 2 thừa số `a` và `b` (với $a, b \ge 2$), tức là $n = a \times b$.
    - Nếu cả `a` và `b` đều lớn hơn $\sqrt{n}$, thì tích của chúng $a \times b > \sqrt{n} \times \sqrt{n} = n$. Điều này mâu thuẫn với giả thiết ban đầu là $n = a \times b$.
    - Do đó, bắt buộc phải có ít nhất một trong hai thừa số (`a` hoặc `b`) **nhỏ hơn hoặc bằng $\sqrt{n}$**.
    - Vì vậy, nếu ta duyệt các số `i` từ $2$ đến $\sqrt{n}$ mà không tìm thấy bất kỳ ước số nào của `n`, thì chắc chắn cũng sẽ không có ước số nào lớn hơn $\sqrt{n}$. Ta có thể kết luận `n` là số nguyên tố.
    - **Kết luận:** Tối ưu hóa này giúp giảm số lần lặp từ $n$ xuống $\sqrt{n}$, tức là giảm độ phức tạp thời gian từ $O(n)$ xuống $O(\sqrt{n})$. Ví dụ với $n = 10^9$, thay vì phải lặp 1 tỷ lần, chương trình chỉ cần lặp tối đa khoảng 31,622 lần.