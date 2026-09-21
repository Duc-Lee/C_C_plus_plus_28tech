**Bài 10. Tính a^b%10**

**Input**
- 1 dòng duy nhất gồm cơ số và số mũ a, b ($0 \le a, b \le 10^9$).

**Output**
- In ra chữ số cuối cùng của $a^b$

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2 10 | 4 |
| 5 1000000000 | 5 |

**Code**
```cpp
            #include <stdio.h>
            #include <string.h>
            #include <math.h>

            // ban chat la bai toan tinh luy thua nhi phan 
            // muc tieu la lam sao moi buoc la chia doi duoc so mu b
            // tinh a^b%10
            int powmod(int a, int b){
                int res = 1;
                while(b){
                    // neu b le thi khong the chia doi b duoc
                    // ta tinh bang cach nhan a vao res
                    // a mod 10 luon, de giam b di 1 don vi 
                    // tu do ma no khong bi tinh luoi
                    if(b&1){
                        res *= a;
                        res %= 10;
                    }
                    // bien doi a
                    // chia b/2 ta duoc a^b = a^(b/2) * a^(b/2) = (a^2)^(b) * (a^2)^(b)
                    // a^2 chia cho mod 10 
                    // khong luu gia tri res o day 
                    // vi doi voi truong hop chan thi modulo = 0 nen chi can nhan 
                    a *= a;
                    a %= 10;
                    // loai bo bit tan cung
                    // no tuong duong voi chia cho 2
                    b >>= 1;
                }
                return res;
            }
            int main(){
                int a,b;
                scanf("%d%d",&a,&b);
                printf("%d",powmod(a,b));
            }
```
**Mô phỏng từng bước chạy lấy ví dụ a=3, b=5**

- Bắt đầu: res = 1, a = 3, b = 5

**Vòng lặp 1:** (`b = 5`)
- Kiểm tra `if (5 & 1)`: Đúng (5 là số lẻ)
  $\implies$ `res = (res * a) % 10 = (1 * 3) % 10 = 3`
- Cập nhật `a = (a * a) % 10 = (3 * 3) % 10 = 9`
- Cập nhật `b >>= 1` (chia b cho 2) $\implies b = 2$
$\implies$ **Kết thúc vòng 1:** `res = 3`, `a = 9`, `b = 2`

**Vòng lặp 2:** (`b = 2`)
- Kiểm tra `if (2 & 1)`: Sai (2 là số chẵn) $\implies$ Bỏ qua không nhân vào `res`.
- Cập nhật `a = (a * a) % 10 = (9 * 9) % 10 = 81 % 10 = 1`
- Cập nhật `b >>= 1` $\implies b = 1$
$\implies$ **Kết thúc vòng 2:** `res = 3`, `a = 1`, `b = 1`

**Vòng lặp 3:** (`b = 1`)
- Kiểm tra `if (1 & 1)`: Đúng (1 là số lẻ)
  $\implies$ `res = (res * a) % 10 = (3 * 1) % 10 = 3`
- Cập nhật `a = (a * a) % 10 = (1 * 1) % 10 = 1`
- Cập nhật `b >>= 1` $\implies b = 0$
$\implies$ **Kết thúc vòng 3:** `res = 3`, `a = 1`, `b = 0`

**Vòng lặp 4:** (`b = 0`)
- Vòng lặp `while(b)` kết thúc vì `b = 0`.
- Hàm trả về `res = 3`.

**Kết quả kiểm chứng:** $3^5 = 243$. Chữ số tận cùng là 3 (Đúng!).

---
## **Bài 11. Tìm Chữ Số Cuối Cùng Của Một Lũy Thừa**

Tìm chữ số tận cùng của $a^n$. Trong đó $a, N$ có giá trị từ 1 trở lên và nhỏ hơn $10^{10.000.000}$.

**Input**
- Dòng đầu tiên là a
- Dòng thứ 2 là n.

**Output**
- Số tận cùng của $a^n$.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2 5 | 2 |
| 2 10 | 4 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                
                char a[10000001];
                char n[10000001];
                
                int main(){
                    scanf("%s%s", a, n);
                    // chu so cuoi cung cua a
                    int tmp = a[strlen(a)-1] - '0'; 
                    // Cac chu so co chu ky vong lap la 1 (chinh no)
                    if(tmp == 0 || tmp == 1 || tmp == 5 || tmp == 6){
                        printf("%d", tmp);
                        return 0;
                    }
                    int r;
                    // chu so cuoi cung neu n co 1 chu so
                    if(strlen(n) == 1) 
                        r = n[0] - '0'; 
                    // neu n co nhieu hon 1 chu so, chi can lay 2 chu so cuoi cung de xet chia het cho 4
                    else 
                        r = (n[strlen(n)-2] - '0') * 10 + n[strlen(n)-1] - '0';
                    // Khai bao cac mang luu chu ky (vi tri 0 la khi chia het cho 4)
                    int r2[4] = {6, 2, 4, 8};
                    int r3[4] = {1, 3, 9, 7};
                    int r4[4] = {6, 4, 6, 4};
                    int r7[4] = {1, 7, 9, 3};
                    int r8[4] = {6, 8, 4, 2};
                    int r9[4] = {1, 9, 1, 9};
                    r %= 4;
                    if(tmp == 2) printf("%d", r2[r]);
                    else if(tmp == 3) printf("%d", r3[r]);
                    else if(tmp == 4) printf("%d", r4[r]);
                    else if(tmp == 7) printf("%d", r7[r]);
                    else if(tmp == 8) printf("%d", r8[r]);
                    else if(tmp == 9) printf("%d", r9[r]);
                    return 0;
                }
```

- Khi xét dãy số dư của $d^n \pmod{10}$ với $n = 1, 2, 3, \dots$:

**Nhóm chu kỳ 1:**
- $0^n \equiv 0$
- $1^n \equiv 1$
- $5^n \equiv 5$
- $6^n \equiv 6$

*(Với mọi $n \ge 1$, lũy thừa lên luôn giữ nguyên tận cùng $\rightarrow$ nhánh `if(tmp == 0 || ...)` in ra luôn).*

**Nhóm chu kỳ 2 và 4:**
Tất cả các chữ số còn lại đều tuần hoàn với chu kỳ là ước của 4 (hoặc 2, hoặc 4):
- $2^1 = 2, \ 2^2 = 4, \ 2^3 = 8, \ 2^4 = 16 \equiv 6, \ 2^5 = 32 \equiv 2 \dots$ (Chu kỳ: 2, 4, 8, 6)
- $3^1 = 3, \ 3^2 = 9, \ 3^3 = 27 \equiv 7, \ 3^4 = 81 \equiv 1 \dots$ (Chu kỳ: 3, 9, 7, 1)
- $4^1 = 4, \ 4^2 = 16 \equiv 6, \ 4^3 \equiv 4 \dots$ (Chu kỳ: 4, 6, 4, 6)
- $7^1 = 7, \ 7^2 \equiv 9, \ 7^3 \equiv 3, \ 7^4 \equiv 1 \dots$ (Chu kỳ: 7, 9, 3, 1)
- $8^1 = 8, \ 8^2 \equiv 4, \ 8^3 \equiv 2, \ 8^4 \equiv 6 \dots$ (Chu kỳ: 8, 4, 2, 6)
- $9^1 = 9, \ 9^2 \equiv 1, \ 9^3 \equiv 9 \dots$ (Chu kỳ: 9, 1, 9, 1)

Vì bội chung của các chu kỳ này đều chia hết cho 4, ta có thể quy chuẩn tất cả về chu kỳ độ dài 4.

-----
## **Bài 12. Số lượng chuỗi nhị phân**

Nhiệm vụ của bạn là tính số lượng các chuỗi bit (chuỗi nhị phân) có độ dài $n$.

Ví dụ, nếu $n = 3$, câu trả lời đúng là $8$, bởi vì các chuỗi bit có thể tạo ra là: 000, 001, 010, 011, 100, 101, 110, và 111.

**Input**
- Chỉ có một dòng đầu vào chứa một số nguyên $n$ ($1 \le n \le 10^6$).

**Output**
- In ra kết quả modulo $10^9 + 7$.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 3 | 8 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                // ham tinh a^b % mod
                long long powmod(long long a, long long b, int mod){
                    long long res = 1;
                    // bien doi a theo mod
                    a %= mod;
                    // neu a = 0 thi ket qua luon la 0
                    if (a == 0) return 0;
                    // lap khi b > 0
                    while(b > 0){
                        // neu b la so le
                        // nhan a vao res
                        if(b & 1){
                            res = (res * a) % mod;
                        }
                        // a^2 mod mod
                        a = (a * a) % mod;
                        // chia doi b
                        b >>= 1;
                    }
                    return res;
                }
                int main(){
                    int n;
                    scanf("%d",&n);
                    int mod = 1000000007;
                    // ket qua la 2^n mod mod
                    long long res = powmod(2, n, mod);
                    printf("%lld\n", res);
                    return 0;
                }
```

**1. Đề bài cho gì?**

Cho một số nguyên $n$ (độ dài của chuỗi, $1 \le n \le 10^6$).

**2. Đề bài bắt làm gì?**

Đếm xem có bao nhiêu chuỗi gồm $n$ ký tự mà mỗi ký tự chỉ được phép chọn là 0 hoặc 1.Vì kết quả quá lớn, hãy lấy đáp số chia lấy dư cho $10^9 + 7$ (tức tính $2^n \pmod{10^9 + 7}$).

**3. Ví dụ:**

Nhập $n = 3$: Có 8 chuỗi ghép được là 000, 001, 010, 011, 100, 101, 110, 111 $\rightarrow$ In ra 8.