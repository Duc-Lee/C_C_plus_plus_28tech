**Bài 4. Lũy thừa và giai thừa.**

Cho số tự nhiên N và số nguyên tố P. Nhiệm vụ của bạn là tìm số x lớn nhất để N! chia hết cho p^x. Ví dụ với N=7, p=3 thì x=2 là số lớn nhất để 7! Chia hết cho 3^2.

**Input**

Dòng đầu tiên đưa vào số lượng bộ test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là cặp số N, p được viết cách nhau một vài khoảng trống.

T, N, p thỏa mãn ràng buộc : 1≤T≤100; 1≤N≤10^5; 2≤p≤5000;

**Output**

Đưa ra kết quả mỗi test theo từng dòng.

**Ví dụ**

**Input:**
```text
3
62 7
76 2
3 5
```

**Output:**
```text
9
73
0
```

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                int count(int n, int p){
                    // khoi tao bien dem mu
                    // tim x max
                    int x = 0;
                    // duyet tu p^1 đến p^m
                    // buoc nhay p
                    for(int i = p; i <= n; i += p){
                        // khi n van chia het cho i 
                        int tmp = i; // khoi tao bien tam
                        // dem so luy thua 
                        while(tmp % p == 0){
                            ++x;
                            tmp /= p; 
                        }
                    }
                    return x;
                }

                // p^1 + p^2 + p^3...
                int count2(int n, int p){
                    int x = 0; 
                    // lay p^1, p^2, p^3...
                    for(int i = p; i <= n; i *= p){
                        // dem so luong boi so
                        // n / i la phan nguyen 
                        // VD N=7, p=3
                        // i = 3: 7 / 3 = 2 (co 2 so la 3, 6)
                        // i = 9: 7 / 9 = 0 (ko co so)
                        x += n / i;
                    } 
                    return x; 
                }
                
                int main(){
                    int t;
                    scanf("%d", &t); // doc du lieu test case
                    while(t--){
                        int n, p; // khai bao bien n, p
                        scanf("%d %d", &n, &p); // doc du lieu n, p 
                        printf("%d\n", count(n,p));
                    }
                    return 0;
                }

```