## **Bài 6. Số nguyên dương thứ k không chia hết cho N**

Bạn được cho hai số nguyên dương a và b. Trong một lần di chuyển, bạn có thể tăng a thêm 1 (thay thế bằng a + 1). Nhiệm vụ của bạn là tìm ra số lần di chuyển tối thiểu bạn cần thực hiện để a chia hết cho b. Có thể, bạn phải thực hiện 0 di chuyển, vì a đã chia hết cho b. Bạn phải trả lời t trường hợp kiểm tra độc lập.

**Input:**
- Dòng đầu tiên của đầu vào chứa một số nguyên t ($1 \le t \le 10^4$) - số lượng trường hợp kiểm tra. Sau đó t trường hợp kiểm tra đi kèm.
- Dòng duy nhất của mỗi trường hợp kiểm tra chứa hai số nguyên a và b ($1 \le a, b \le 10^9$).

**Output:**
- Đối với mỗi trường hợp kiểm tra, hãy in ra câu trả lời - số lần di chuyển tối thiểu bạn cần thực hiện để a chia hết cho b.

**Ví dụ:**

| Input | Output |
| :--- | :--- |
| 5<br>10 4<br>13 9<br>100 13<br>123 456<br>92 46 | 2<br>5<br>4<br>333<br>0 |

**Code**
```cpp
            #include <stdio.h>
            #include <math.h>

            #define ll long long
            #define MOD 1e9 + 7
            
            int check(int a, int b){
                int cnt = 0;
                // khi a chua chia het cho b
                while( a % b != 0){
                    // moi lan di chuyen la 1 lan tang a
                    ++a;
                    // tang gia tri bien dem len 
                    ++cnt;
                }
                return cnt;
            }

            int solve(int a, int b){
                int r = a % b;
                // neu du bang = 0 thi a chia het cho b (vi du: 8 % 4 == 0)
                // => khong can di chuyen
                if(r == 0) return 0;
                // neu khac 0 thi can di chuyen
                // vi du: a = 10, b = 4 => r = 10 % 4 = 2
                // => can di chuyen 2 lan => (4 - 2) lan
                // a = k*b + r, a dang du ra 1 luong r
                // ma de chi cho phep tang a len
                // => can di chuyen (b-r) lan de a tro thanh (k+1)*b
                return b - r;
            }
            int main(){
                int t;
                scanf("%d",&t);
                while(t--){
                    ll a,b;
                    scanf("%lld %lld",&a,&b);
                    // 
                    
                }
                return 0;
            }
```

-------
## **Bài 7. Số nguyên dương thứ k không chia hết cho n**

Bạn được cho hai số nguyên dương n và k. In ra số nguyên dương thứ k không chia hết cho n.

Ví dụ: nếu n = 3 và k = 7, thì tất cả các số không chia hết cho 3 là: 1, 2, 4, 5, 7, 8, 10, 11, 13. Số thứ 7 trong số đó là 10.

**Input**
- Dòng đầu tiên chứa số nguyên t ($1 \le t \le 1000$) - số lượng trường hợp kiểm tra trong đầu vào. Tiếp theo, t trường hợp thử nghiệm được đưa ra, một trường hợp trên mỗi dòng.
- Mỗi trường hợp thử nghiệm là hai số nguyên dương n ($2 \le n \le 10^9$) và k ($1 \le k \le 10^9$).

**Output**
- Đối với mỗi trường hợp thử nghiệm, in số nguyên dương thứ k không chia hết cho n.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 6<br>3 7<br>4 12<br>2 1000000000<br>7 97<br>1000000000 1000000000<br>2 1 | 10<br>15<br>1999999999<br>113<br>1000000001<br>1 

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                // cach 1: Duyet trau (co the bi Time Limit Exceeded)
                int solve(int n, int k){
                    int cnt = 0; // bien dem 
                    int i = 1; 
                    while(1){
                        // Kiem tra i co chia het cho n khong (thay vi k)
                        if(i % n != 0){
                            ++cnt;
                            // Tim duoc so THU K thi tra ve ket qua (thay vi n)
                            if(cnt == k) return i;
                        }
                        ++i;
                    }
                }
                
                // cach 2: O(1) dung toan hoc
                long long solve2(long long n, long long k){
                    // Cu moi n so nguyen thi se co (n-1) so KHONG chia het cho n
                    // => Ta phan cac so thanh tung nhom, moi nhom co (n-1) so hop le
                    // x la so luong nhom hoan chinh (so chu ky)
                    // vi du : n = 3, k = 7 => 7 / (3-1) = 3 nhom
                    long long x = k / (n - 1);
                    
                    // r la phan le ra (so thu k nam o vi tri thu r trong nhom tiep theo)
                    long long r = k % (n - 1);
                    
                    // Neu r == 0, tuc la so can tim nam o CUOI CUNG cua nhom thu x.
                    // Cuoi nhom thu x la so ngay truoc boi so thu x cua n (tuc la x*n)
                    // => Ket qua = x*n - 1
                    if(r == 0) return x * n - 1;
                    
                    // Neu r != 0, so do da buoc sang nhom thu (x + 1).
                    // Boi so cua n o ngay truoc nhom nay la x*n.
                    // Ta phai di tiep r buoc nua (bo qua boi so x*n do vi no chia het cho n)
                    // => Ket qua = x*n + r
                    return x * n + r;
                }

                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        long long n, k;
                        scanf("%lld %lld", &n, &k);
                        printf("%lld\n", solve2(n, k));
                    }
                    return 0;
                }
```

### Bước 1: Quy luật đóng gói
**Đề bài:** Bỏ đi các số chia hết cho $n$.

Bây giờ, ta xếp các số tự nhiên liên tiếp vào từng hộp, mỗi hộp chứa đúng $n$ số:
- **Hộp 1:** gồm các số $\{1, 2, \dots, n-1, \mathbf{n}\}$
  $\rightarrow$ Số cuối cùng là $\mathbf{n}$ bị vứt đi. Trong hộp này chỉ còn lại $n - 1$ số dùng được.
- **Hộp 2:** gồm các số $\{n+1, n+2, \dots, 2n-1, \mathbf{2n}\}$
  $\rightarrow$ Số cuối cùng là $\mathbf{2n}$ bị vứt đi. Trong hộp này cũng chỉ còn lại $n - 1$ số dùng được.
- **Hộp 3:** tương tự, chỉ giữ lại được $n - 1$ số.

**Quy luật cốt lõi:**
Mỗi hộp có kích thước $n$, nhưng chỉ lấy được đúng $n - 1$ số hợp lệ.

### Bước 2: Ta cần bao nhiêu cái hộp để nhặt đủ $k$ số?
Mỗi hộp chỉ cho ta $n - 1$ số, mà ta cần gom đủ $k$ số. Ta làm phép chia:
$$k = x \cdot (n - 1) + r$$
- $x = k / (n - 1)$: Số hộp ta ăn trọn vẹn.
- $r = k \% (n - 1)$: Số lượng số còn thiếu mà ta phải mở thêm hộp tiếp theo để lấy.

### Bước 3: Tìm con số thực tế

**Trường hợp 1: Còn dư lẻ ($r > 0$)**
Ta đã dùng hết $x$ hộp đầu tiên.
Hộp thứ $x$ kết thúc bằng số: $x \cdot n$.
Bây giờ ta thò tay vào hộp thứ $(x + 1)$ để lấy thêm $r$ số nữa.
Vì $r < n - 1$, $r$ số đầu tiên trong hộp mới này chắc chắn không chạm vào số bị cấm (số bị cấm nằm tít ở cuối hộp).
Vậy con số ta chạm tới là:
$$\text{Kết quả} = x \cdot n + r$$

**Trường hợp 2: Chia hết ($r = 0$)**
Nghĩa là ta vừa nhặt đủ $k$ số ngay khi vét sạch các số hợp lệ của hộp thứ $x$. Ta không cần sang hộp thứ $x+1$.
Hộp thứ $x$ kết thúc bằng số $x \cdot n$ (số này chia hết cho $n$ nên bị vứt).
Vậy số hợp lệ cuối cùng ta vừa nhặt chính là số đứng ngay trước nó:
$$\text{Kết quả} = x \cdot n - 1$$