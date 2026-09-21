**Bài 33. Đếm ước của n!**

Đếm số lượng ước của n!.

**Input**

Dòng đầu tiên là số lượng test case T (1≤T≤100).

Mỗi test case là một số nguyên không âm n (1≤T≤100).

**Output**

In ra kết quả mỗi test case trên 1 dòng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>10<br>97 | <br>270<br>26494182162432000 |


**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                // ham kiem tra so nguyen to 
                int nt(int n){
                    for(int i = 2; i<= sqrt(n);i++){
                        if(n%i == 0){
                            return 0;
                        }
                    }
                    return 1;
                }

                // tinh so mu cua p trong n!
                int mu(int n, int p){
                    int ans = 0;
                    // i nhay buoc theo luy thua cua p
                    // vi du 10! tinh so mu 2
                    // i = 2; 10/2 = 5 -> ans = 5
                    // i = 4; 10/4 = 2 -> ans = 5 + 2 = 7
                    // i = 8; 10/8 = 1 -> ans 8
                    // 10! = 2^8 ...
                    for(int i = p; i <= n;i*=p){
                        // tinh so mu 
                        ans+= n/i;
                    }
                    return ans;
                }

                // ham dem so luy thua
                int count(int n){
                    int res = 0;
                    for(int i = 2; i<= n;i++){
                        if(nt(i)){
                            // tinh so mu cua i trong n!
                            int e = mu(n,i);
                            // tinh so uoc theo cung thuc (a1+1)(a2+1)...(ak+1)
                            res = res*(e+1);
                        }
                    }
                    return res;
                }

                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        printf("%d\n",count(n));
                    }
                    return 0;
                }
```

### 1. Số lượng ước của một số $M$

Giả sử bạn phân tích một số $M$ ra thừa số nguyên tố:
$$M = p_1^{a_1} \cdot p_2^{a_2} \cdot \dots \cdot p_k^{a_k}$$

Mọi ước số $d$ của $M$ bắt buộc phải có dạng:
$$d = p_1^{x_1} \cdot p_2^{x_2} \cdot \dots \cdot p_k^{x_k}$$
Trong đó mỗi số mũ $x_i$ chỉ có thể chọn từ $0$ đến $a_i$ (tổng cộng có $a_i + 1$ cách chọn).

Theo quy tắc nhân tổ hợp, tổng số lượng ước nguyên dương của $M$ là:
$$d(M) = (a_1 + 1)(a_2 + 1)\dots(a_k + 1)$$

**Ví dụ:** Số $12 = 2^2 \cdot 3^1$.
Số ước của $12$ là: $(2 + 1) \times (1 + 1) = 3 \times 2 = 6$ ước (gồm: $1, 2, 3, 4, 6, 12$).

### 2. Áp dụng cho $n!$

Do đó, bản chất toán học của bài toán là: Không tính giá trị của $n!$, mà đi tìm số mũ của từng số nguyên tố trong $n!$.
Nếu viết:
$$n! = 2^{e_2} \cdot 3^{e_3} \cdot 5^{e_5} \dots p^{e_p}$$
Thì số lượng ước của $n!$ sẽ là:
$$(e_2 + 1)(e_3 + 1)(e_5 + 1)\dots(e_p + 1)$$

### 3. Công thức Legendre (Tìm số mũ của $p$ trong $n!$)

Làm sao biết số nguyên tố $p$ xuất hiện bao nhiêu lần trong tích $1 \times 2 \times 3 \times \dots \times n$?
Hãy lấy ví dụ cụ thể với $n = 10$, tìm số mũ của $p = 2$ trong $10!$:

Dãy số: $1, \mathbf{2}, 3, \mathbf{4}, 5, \mathbf{6}, 7, \mathbf{8}, 9, \mathbf{10}$
- Các số chia hết cho $2$: có $\lfloor 10 / 2 \rfloor = 5$ số ($2, 4, 6, 8, 10$). Mỗi số đóng góp ít nhất một thừa số $2$.
- Các số chia hết cho $2^2 = 4$: có $\lfloor 10 / 4 \rfloor = 2$ số ($4, 8$). Những số này đóng góp thêm một thừa số $2$ nữa mà bước trên chưa tính hết.
- Các số chia hết cho $2^3 = 8$: có $\lfloor 10 / 8 \rfloor = 1$ số ($8$). Đóng góp thêm một thừa số $2$ nữa.
- Các số chia hết cho $2^4 = 16$: không có ($\lfloor 10 / 16 \rfloor = 0$).

Tổng số mũ của $2$ trong $10!$ là:
$$e_2 = 5 + 2 + 1 = 8 \implies 2^8$$

**Tổng quát thành Công thức Legendre:**
$$e_p = \left\lfloor \frac{n}{p} \right\rfloor + \left\lfloor \frac{n}{p^2} \right\rfloor + \left\lfloor \frac{n}{p^3} \right\rfloor + \dots$$