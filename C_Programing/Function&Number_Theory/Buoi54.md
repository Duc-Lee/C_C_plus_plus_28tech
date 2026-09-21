## **Bài 8. Tìm Chữ Số Cuối Cùng Của 1378^n**

Cho n, in ra chữ số cuối cùng của $1378^n$.

**Input**
- Dòng đầu vào chứa một số nguyên n ($0 \le n \le 10^9$).

**Output**
- In số nguyên đơn - chữ số cuối cùng của $1378^n$.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2 | 4 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                int main(){
                    int n;
                    scanf("%d",&n);
                    if(n % 4 == 0) printf("6");
                    else if(n % 4 == 1) printf("8");
                    else if(n % 4 == 2) printf("4");
                    else printf("2");
                }
```

Do đó, bài toán yêu cầu tìm:
$$C = 1378^n \pmod{10}$$

### 1. Rút gọn cơ số
Theo tính chất đồng dư của phép nhân:
$$(a \cdot b) \pmod{10} = \big((a \pmod{10}) \cdot (b \pmod{10})\big) \pmod{10}$$
Vì $1378 \equiv 8 \pmod{10}$, nên chữ số tận cùng của $1378^n$ chỉ phụ thuộc duy nhất vào chữ số tận cùng của cơ số (số 8):
$$1378^n \equiv 8^n \pmod{10}$$

### 2. Tính tuần hoàn của lũy thừa số 8 theo $\pmod{10}$
Xét dãy các lũy thừa của $8$ với số mũ $n \ge 1$:
- $8^1 = 8 \equiv \mathbf{8} \pmod{10}$
- $8^2 = 64 \equiv \mathbf{4} \pmod{10}$
- $8^3 = 512 \equiv \mathbf{2} \pmod{10}$
- $8^4 = 4096 \equiv \mathbf{6} \pmod{10}$
- $8^5 = 32768 \equiv \mathbf{8} \pmod{10}$ (lặp lại)
- $8^6 = 262144 \equiv \mathbf{4} \pmod{10}$
- ...

Dãy chữ số tận cùng lặp lại theo một chu kỳ có độ dài bằng 4:
$$\mathbf{8} \longrightarrow \mathbf{4} \longrightarrow \mathbf{2} \longrightarrow \mathbf{6} \longrightarrow \mathbf{8} \longrightarrow \dots$$

### 3. Công thức tính theo số dư của $n$ chia cho 4
Vì chu kỳ lặp lại mỗi 4 bước, ta chỉ cần xét số dư của $n$ khi chia cho 4 ($n \pmod 4$):
- **Nếu $n = 0$:** Quy ước toán học $1378^0 = 1 \implies$ chữ số tận cùng là $\mathbf{1}$.
- **Với $n > 0$:**
  - Nếu $n \equiv 1 \pmod 4 \implies$ tận cùng là $\mathbf{8}$
  - Nếu $n \equiv 2 \pmod 4 \implies$ tận cùng là $\mathbf{4}$
  - Nếu $n \equiv 3 \pmod 4 \implies$ tận cùng là $\mathbf{2}$
  - Nếu $n \equiv 0 \pmod 4 \implies$ tận cùng là $\mathbf{6}$ (vị trí cuối của chu kỳ)

---

## **Bài 9. Tìm (1^n+2^n+3^n+4^n)%5**

Fedya học trong một phòng tập thể dục. Quê hương toán học của Fedya là để tính biểu thức sau:

$$(1^n + 2^n + 3^n + 4^n) \pmod 5$$

cho giá trị đã cho của n. Fedya quản lý để hoàn thành nhiệm vụ. Bạn có thể? Lưu ý rằng số n đã cho có thể cực kỳ lớn (ví dụ: nó có thể vượt quá mọi loại số nguyên của ngôn ngữ lập trình của bạn).

**Input**
- Dòng đơn chứa một số nguyên n ($0 \le n \le 10^{10^5}$). Số này không chứa bất kỳ số 0 hàng đầu nào.

**Output**
- In giá trị của biểu thức mà không có số 0 đứng đầu.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 4 | 4 |
| 124356983594583453458888889 | 0 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>

                int main(){
                    char c[10001];
                    scanf("%s",&c);
                    int r;
                    // neu chi co 1 so 
                    if(strlen(c) == 1){
                        // kiem tra xem so do co chia het cho 4 hay khong
                        r = (c[0]-'0')%4;
                    }
                    else{
                        // tinh hai so cuoi cung cua n chia cho 4 
                        // vi de chia het cho 4 chi can hai so cuoi cung chia het cho 4
                        r = ((c[strlen(c)-2]-'0')*10 + (c[strlen(c)-1]-'0'))%4;
                    }
                    // in ra ket qua
                    if(r == 0){
                        printf("4");
                    }
                    else{
                        printf("0");
                    }
                }
```

Bài toán yêu cầu tính giá trị biểu thức:
$$S_n = (1^n + 2^n + 3^n + 4^n) \pmod 5$$
với $n$ có thể lên tới $10^{10^5}$ chữ số.

### 1. Phân tích toán học: Tính tuần hoàn theo modulo 5
Xét từng số hạng theo $\pmod 5$:
- $1^n \equiv 1 \pmod 5$ với mọi $n \ge 0$.
- Với số $4$:
  $$4 \equiv -1 \pmod 5 \implies 4^n \equiv (-1)^n \pmod 5$$
- Với số $3$:
  $$3 \equiv -2 \pmod 5 \implies 3^n \equiv (-2)^n \equiv (-1)^n \cdot 2^n \pmod 5$$

Gộp các cặp lại:
$$S_n \equiv \big(1 + (-1)^n\big) + 2^n \big(1 + (-1)^n\big) \equiv \big(1 + (-1)^n\big)(1 + 2^n) \pmod 5$$

### 2. Biện luận theo tính chất của $n$
Từ biểu thức $S_n \equiv \big(1 + (-1)^n\big)(1 + 2^n) \pmod 5$:

**Trường hợp 1: $n$ là số lẻ**
- $(-1)^n = -1$
  $\implies 1 + (-1)^n = 1 - 1 = 0$
- Do đó:
  $$S_n \equiv 0 \cdot (1 + 2^n) \equiv \mathbf{0} \pmod 5$$

**Trường hợp 2: $n$ là số chẵn ($n = 2k$)**
- $(-1)^n = 1 \implies 1 + (-1)^n = 2$
- Ta có:
  $$S_n \equiv 2 \cdot (1 + 2^n) \equiv 2 + 2 \cdot 4^k \equiv 2 + 2 \cdot (-1)^k \pmod 5$$

Xét tiếp hai trường hợp con của $k$ (tương ứng với việc $n$ chia hết cho 4 hay không):
- **Nếu $n$ không chia hết cho 4** ($k$ lẻ $\implies n \equiv 2 \pmod 4$):
  $(-1)^k = -1$
  $$S_n \equiv 2 + 2(-1) = 0 \pmod 5$$
- **Nếu $n$ chia hết cho 4** ($k$ chẵn $\implies n \equiv 0 \pmod 4$, bao gồm cả $n = 0$):
  $(-1)^k = 1$
  $$S_n \equiv 2 + 2(1) = 4 \pmod 5$$

### 3. Kết luận quy luật toán học
Giá trị của $(1^n + 2^n + 3^n + 4^n) \pmod 5$ chỉ nhận duy nhất 2 kết quả:
$$S_n = \begin{cases} 4 & \text{nếu } n \ \vdots \ 4 \\ 0 & \text{nếu } n \not\vdots \ 4 \end{cases}$$