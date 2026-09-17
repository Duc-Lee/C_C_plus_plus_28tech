**Bài 6. Số Sphenic.**

Số nguyên dương N được gọi là số Sphenic nếu N được phân tích duy nhất dưới dạng tích của ba số khác nhau. Ví dụ N=30 là số Sphenic vì 30 = 2×3×5; N = 60 không phải số Sphenic vì 60 = 2×2×3×5. Cho số tự nhiên N, nhiệm vụ của bạn là kiểm tra xem N có phải số Sphenic hay không?

Một số số Sphenic đầu tiên : 30, 42, 66, 70, 78, 102

**Input**

Dòng đầu tiên đưa vào số lượng bộ test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên dương N.

T, N thỏa mãn ràng buộc : 1≤T≤100; 1≤N≤10000.

**Output**

Đưa ra 1 hoặc 0 tương ứng với N là số Sphenic hoặc không của mỗi test theo từng dòng.

**Ví dụ**

**Input:**
```text
2
30
60
```

**Output:**
```text
1
0
```

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                // ham kiem tra so Sphenic 
                // tra ve 1 neu N la so Sphenic, nguoc lai tra ve 0 
                int isSphenic(int n){
                    // dem so luong nguyen to khac nhau cua n 
                    int res = 0;
                    // phan tich thua so nguyen to
                    for(int i = 2; i <= sqrt(n); i++){
                        // dem so luong thua so nguyen to i
                        int cnt = 0;
                        // tinh so luong thua so nguyen to i
                        while(n % i == 0){
                            ++cnt;
                            n /= i;
                        }
                        // neu so luong thua so nguyen to i lon hon 1 thi n khong phai la so Sphenic
                        if(cnt >= 2) return 0;
                        else ++res;
                    }
                    // neu n khac 1 thi n la so nguyen to 
                    if(n!=1)
                        ++res;
                    // neu n la so Sphenic thi n co 3 thua so nguyen to khac nhau
                    return res == 3;
                }
                int main(){
                    int t;
                    scanf("%d", &t); // doc du lieu test case
                    while(t--){
                        int n; // khai bao bien n
                        scanf("%d", &n); // doc du lieu n 
                        printf("%d\n", isSphenic(n));
                    }
                    return 0;
                }
```
