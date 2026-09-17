# Bài 10. T-prime

Cho số tự nhiên N. Nhiệm vụ của bạn là hãy liệt kê tất cả các số có đúng ba ước số.
Ví dụ n=100, ta có các số 4, 9, 25, 49.

## Input

Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N.

T, N thỏa mãn rang buộc 1≤T≤100; 1≤N ≤10^6.

## Output

Đưa ra kết quả mỗi test theo từng dòng.

## Ví dụ

| Input: | Output: |
| --- | --- |
| 2<br><br>50<br><br>200 | 4 9 25 49<br><br>4 9 25 49 121 169 |

## Code
```cpp
            #include <stdio.h>
            #include <math.h>

            int prime[1000001];
            int p;

            void sieve(){
                for(int i=2;i<=1000000;i++) prime[i]=1;
                for(int i=2;i<=sqrt(1000000);i++){
                    if(prime[i]==1){
                        for(int j=i*i;j<=1000000;j+=i) prime[j]=0;
                    }
                }
            }

            int main(){
                int t;
                scanf("%d",&t);
                sieve();
                while(t--){
                    int n;
                    scanf("%d",&n);
                    // mot so co dung 3 uoc thi so do la binh phuong cua mot so nguyen to
                    // duyet tu 1 den sqrt(n)
                    for(int i = 1; i <= sqrt(n); i++){
                        if(prime[i]){
                            printf("%d ",i*i);
                        }
                    }
                    printf("\n");
                }
            }
```
- Giải thích : 
    - Dựa vào công thức tính số lượng ước, mọi số $N$ phân tích thừa số nguyên tố được thành $N = p_1^{l_1} \cdot p_2^{l_2} \cdots p_k^{l_k}$ (với $p$ là số nguyên tố) thì sẽ có tổng số ước là $d(N) = (l_1 + 1)(l_2 + 1) \cdots (l_k + 1)$ ( với $l_1, l_2, \cdots, l_k \ge 1$, lũy thừa của các số nguyên tố).
    - Bài toán yêu cầu tìm số có đúng 3 ước, tức là $d(N) = 3$. Vì 3 là số nguyên tố, nó không thể tách thành tích của 2 hay nhiều số lớn hơn 1 được (ví dụ không thể tách giống như $4 = 2 \times 2$). 
    - Do đó, công thức tính số ước $d(N)$ bắt buộc phải rút gọn lại chỉ có một ngoặc đơn duy nhất: $(l_1 + 1) = 3 \Rightarrow l_1 = 2$.
    - Từ đó suy ra dạng của số $N$ phải là: $N = p_1^2$ (trong đó $p_1$ là một số nguyên tố). **Kết luận: Số có đúng 3 ước số chính là bình phương của một số nguyên tố.**
    - Vì mặc định số đó đã chia hết cho 1 và chính nó nên chúng ta chỉ cần tìm số nguyên tố $p$ sao cho $p^2 \le N$ là được ( vì nếu $p^2 > N$ thì $p^2$ chắc chắn sẽ có nhiều hơn 3 ước số).
    - **Ý tưởng code:** Thay vì duyệt từng số từ $1$ đến $N$ rồi đếm số lượng ước của nó (rất chậm), ta chỉ cần duyệt biến $i$ từ $1$ đến $\sqrt{N}$. Ở mỗi bước, nếu $i$ là số nguyên tố (kiểm tra bằng mảng sàng `prime[i]`) thì in ra $i \times i$. Cách này đảm bảo $i \times i \le N$ và có đúng 3 ước số.

# Bài 10 - Mở rộng 
