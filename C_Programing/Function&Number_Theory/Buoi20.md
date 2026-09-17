**Bài 7. Số Smith.**

Cho số tự nhiên N. Nhiệm vụ của bạn là hãy kiểm tra N có phải là số Smith hay không. Một số được gọi là số Smith nếu N không phải là số nguyên tố và có tổng các chữ số của N bằng tổng các chữ số của các ước số nguyên tố của N. Ví dụ N = 666 có các ước số nguyên tố là 2, 3, 3, 37 có tổng các chữ số là 18.

**Input:**

Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên N.

T, N thỏa mãn ràng buộc 1≤T≤100; 1≤N≤100000.

**Output**

Đưa ra kết quả mỗi test theo từng dòng.

**Ví dụ**

**Input:**
```text
2
4
666
```

**Output:**
```text
YES
YES
```

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                // ham tinh tong cac chu so cua mot so 
                int sum(int n){
                    int cnt = 0;
                    while(n){
                        cnt += n % 10;
                        n /= 10;
                    }
                    return cnt;
                }

                //
                int smith(int n){
                    // tong cac chu so cua n
                    int sum1 = sum(n); 
                    // khoi tao bien tong thua so cua n
                    int sum2 = 0;
                    int tmp = n; 
                    // tim cac so nguyen to la uoc cua n
                    for(int i = 2; i <= sqrt(n);i++){
                        // tinh tong cac chu so nguyen to cua n
                        while(n % i == 0){
                            sum2 += sum(i);
                            n /= i;
                        }
                    }
                    // neu tmp == n thi n la so nguyen to nen khong phai la so Smith 
                    if(tmp == n)
                        return 0;
                    // tinh tong cac chu so nguyen to con lai
                    if(n != 1)
                        sum2 += sum(n);
                    // kiem tra xem tong cac chu so cua n co bang tong cac chu so nguyen to cua n hay khong
                    return sum1 == sum2;
                } 
                int main(){
                    int t;
                    scanf("%d", &t);
                    while(t--){
                        int n;
                        scanf("%d", &n);
                        if(smith(n))
                            printf("YES\n");
                        else
                            printf("NO\n");
                    }
                    return 0;
                }
```
