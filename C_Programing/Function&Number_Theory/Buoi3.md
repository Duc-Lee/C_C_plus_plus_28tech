**Bài 3. Sàng số nguyên tố trên đoạn.**

**Input**

2 số nguyên không âm a, b(0≤a≤b≤10^9, b-a≤10^5).

**Output**

In ra các số nguyên tố trong đoạn từ a tới b (Chú ý lấy cả 2 cận).

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 4 20 | 5 7 11 13 17 19 |

**Code**
```cpp
            #include <stdio.h>
            #include <math.h>

            int max(int a, int b){
                return a < b ? b : a;
            }
            // Sang so nguyen to tren doan 
            void sang(int l, int r){
                // khoi tao mang sang 
                int prime[r-l+1];
                // danh dau tat ca deu la so nguyen to 
                for(int i = 0; i <= r - l + 1; i++){
                    prime[i] = 1;
                }
                // duyet tu 2 cho đến can r
                for(int i = 2; i <= sqrt(r);i++){
                    // max(i*i, (l+i-1)/i*i)
                    // i*i la so nguyen to nho nhat cua i
                    // (l+i-1)/i*i la so nguyen to nho nhat cua i trong doan [l,r]
                    // noi cach khac (l+i-1)/i la boi so nho nhat cua i lon hon hoac bang l
                    // đây là công thức làm tròn i*i để nó làm tròn lên >= l
                    // vi khi i * i < l 
                    // => i * (số nào đó) < l 
                    // => i * (số nào đó) < r 
                    // => j < r 
                    for(int j = max(i*i, (l+i-1)/i*i); j <= r; j += i){
                        // xoa boi so cua i 
                        prime[j-l] = 0;
                        // j - l giup anh xa sang chi so 0 - (r-l) tuong ung voi cac gia tri l - r
                        // cho tiet kiem bo nho
                    }
                }
                // In ket qua 
                for(int i = max(2,l);i<=r;i++){
                    if(prime[i-l]){
                        printf("%d ",i);
                    }
                }
            }
            int main(){
                int l,r;
                scanf("%d %d",&l,&r);
                sang(l,r);
            }
```
