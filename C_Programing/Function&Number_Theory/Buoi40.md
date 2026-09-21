**Bài 28. Số nguyên dương nhỏ nhất.**

Cho 4 số nguyên dương x, y, z, n.
Tìm số nguyên dương nhỏ nhất có n chữ số chia hết cho cả x, y, và z.

**Input**

4 số nguyên dương x, y, z, n. (1 ≤ x, y, z ≤ 10^4). n ≤ 16.

**Output**

Kết quả của bài toán, trường hợp không tìm được số thỏa mãn in -1.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2 3 5 4 | 1020 |
| 3 5 7 2 | -1 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                long long solve(int n, int x, int y, int z){
                    // duyet tu 10^(n-1) den 10^n
                    for(int i = pow(10,n-1); i<= pow(10,n);i++){
                        if(i % x == 0 && i % y == 0 && i % z == 0){
                            return i;
                        }
                    }
                    return -1;
                }
                int main(){
                    int n, x, y, z;
                    scanf("%d %d %d %d", &x, &y, &z, &n);
                    printf("%lld", solve(n, x, y, z));
                    return 0;
                }
```
- Thực tế nếu dùng cách này cho các test case có n lớn thì sẽ rất chậm, dễ bị tràn số khi dùng pow với n lớn.
- Cách tối ưu:
    - Tìm BCNN của x, y, z
    - Tìm số nhỏ nhất có n chữ số chia hết cho BCNN.
    - Sử dụng công thức xấp xỉ tính số nhỏ nhất lớn hơn hoặc bằng l và chia hết cho bcnn: (l + bcnn - 1) / bcnn * bcnn
    - Nếu không tìm được số thỏa mãn thì in -1.
    ```cpp
                #include <stdio.h>
                #include <math.h>
                
                long long gcd(long long a, long long b){
                    while(b){
                        a %= b;
                        long long temp = a;
                        a = b;
                        b = temp;
                    }
                    return a;
                }
                long long lcm(long long a, long long b){
                    return (a * b) / gcd(a, b);
                }
                long long solve(int n, int x, int y, int z){
                    // tim boi chung nho nhat 
                    long long bcnn = lcm(lcm(x,y),z);
                    // tim so nho nhat >= 10^(n-1) va chia het cho bcnn
                    long long l = pow(10,n-1);
                    // phep toan xap xi so nho nhat = (l + bcnn - 1) / bcnn * bcnn
                    // (l + bcnn - 1)/bcnn là số lần chia,
                    // nhân với bcnn để ra số chia hết cho bcnn
                    // nếu kết quả nhỏ hơn 10^n thì trả về, nếu không thì -1
                    long long ans = (l + bcnn - 1) / bcnn * bcnn;
                    if(ans < pow(10,n)){
                        return ans;
                    }
                    return -1;
                }
                int main(){
                    int n, x, y, z;
                    scanf("%d %d %d %d", &x, &y, &z, &n);
                    printf("%lld", solve(n, x, y, z));
                    return 0;
                }
    ```

