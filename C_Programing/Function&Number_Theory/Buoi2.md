**Bài 2. Sàng số nguyên tố.**

**Input**

Số nguyên n (0≤n≤10^6).

**Output**

In ra trên một dòng các số nguyên tố không vượt quá n, mỗi số cách nhau một khoảng trắng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 4 | 2 3 |
| 13 | 2 3 5 7 11 13 |

**Code**
```cpp
        #include <stdio.h>
        #include <math.h>

        // Thuat toan sang so nguyen to Sieve of Eratosthenes
        // O(nlog(log(n)))
        // Neu ban muon sang cac so nguyen to khong qua n
        // phai tao duoc 1 mang có kich thuoc la n + 1 phan tu
        int prime[1000001];

        void sieve(){
            // Coi tat ca cac so tu 0 cho toi n la so nguyen to
            for(int i = 0;i<=1000000;i++){
                // coi tat ca la so nguyen to
                prime[i] = 1;
            }
            // loại 0 va 1 vi 2 so nay khong phai so nguyen to
            prime[0] = prime[1] = 0;
            for(int i = 2;i<= sqrt(1000000);i++){
                // neu i la so nguyen to 
                if(prime[i]){
                    // nhay vao day khi i la so nguyen to
                    // bat dau xoa cac boi cua no 
                    // i nhan voi 2 -> i*2, i*3, -> i * k
                    // vi i * 1 da duoc xet 
                    // Duyet tat ca cac boi so cua i va cho no khong la so nguyen to 
                    for(int j = i*i;j <= 1000000;j += i){
                        // j khong con la so nguyen to nua
                        prime[j] = 0;
                    }
                    // i*i de toi uu
                    // vi i*2,i*3...i*(i-1) da duoc xet boi cac so nho hon i
                }
            }
        }
        
        int main(){
            int n;
            scanf("%d",&n);
            // In ra so nguyen to tu 0 den n 
            for(int i =0;i<=n;i++){
                if(prime[i]){
                    printf("%d ",i);
                }
            }
        }

```
- Giải thích thuật toán Sàng số nguyên tố (Sieve of Eratosthenes):
    - **Ý tưởng cốt lõi**: Thay vì đi kiểm tra từng số xem có phải là số nguyên tố hay không (rất chậm), ta sẽ làm ngược lại: giả định tất cả các số đều là số nguyên tố. Sau đó, ta đi tìm các số nguyên tố và "gạch bỏ" (loại trừ) tất cả các bội số của nó (vì bội số thì chia hết cho số đó, nên không thể là số nguyên tố). Những số cuối cùng không bị gạch bỏ chính là các số nguyên tố.
    - **Minh họa trực quan từng bước**: Giả sử cần tìm các số nguyên tố đến $N$:
        1. **Bắt đầu (Khởi tạo mảng)**: Tạo một mảng `prime` với tất cả giá trị ban đầu là `1` (mang ý nghĩa: tạm coi tất cả là số nguyên tố). Mặc định số 0 và 1 không phải là số nguyên tố nên ta cập nhật `prime[0] = prime[1] = 0`.
        2. **Bước 1 ($i = 2$)**: Số 2 có giá trị `prime[2] == 1` $\rightarrow$ 2 là số nguyên tố. Ta bắt đầu vòng lặp con để **gạch bỏ tất cả các bội của 2**: $4, 6, 8, 10, 12...$ (gán `prime[j] = 0`).
        3. **Bước 2 ($i = 3$)**: Số 3 chưa bị gạch (`prime[3] == 1`) $\rightarrow$ 3 là số nguyên tố. Tiếp tục **gạch bỏ các bội của 3**: $9, 12, 15, 18...$ (Chú ý: ta bắt đầu gạch từ $3 \times 3 = 9$, vì số $3 \times 2 = 6$ đã bị gạch ở vòng của số 2 trước đó rồi).
        4. **Bước 3 ($i = 4$)**: Số 4 đã bị gạch ở bước $i = 2$ (`prime[4] == 0`), chứng tỏ nó không phải số nguyên tố $\rightarrow$ Bỏ qua, đi tiếp.
        5. **Bước 4 ($i = 5$)**: Số 5 chưa bị gạch $\rightarrow$ 5 là số nguyên tố. Bắt đầu gạch từ $5 \times 5 = 25$ (các bội trước đó như $10, 15, 20$ đều đã bị gạch bởi 2 và 3).
        6. **Điều kiện dừng tối ưu vòng lặp ngoài**: Ta chỉ cần duyệt $i$ chạy đến $\sqrt{N}$. Tại sao? Vì nếu một hợp số $K$ ($K \le N$) không phải số nguyên tố, nó luôn có thể tách thành 2 nhân tử $a \times b = K$. Trong 2 nhân tử này, chắc chắn có ít nhất 1 số $\le \sqrt{K} \le \sqrt{N}$. Do đó, mọi hợp số đều sẽ bị gạch bỏ bởi một ước số nào đó $\le \sqrt{N}$, vòng lặp ngoài chạy đến $\sqrt{N}$ là hoàn toàn đủ và tối ưu.

