**Bài 35. 486A.**

Đối với số nguyên dương n hãy xác định hàm f:

$f(n) = -1 + 2 - 3 + .. + (-1)^n n$

Nhiệm vụ của bạn là tính f(n) cho một số nguyên n đã cho.

**Input**

Dòng đơn chứa số nguyên dương n ($1 \le n \le 10^{15}$).

**Output**

In f(n) trong một dòng duy nhất.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 4 | 2 |
| 5 | -3 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                #include <stdlib.h>
                #include <string.h>
                
                long long solve(long long n){
                    // neu n chan thi
                    if(n%2 == 0) return n/2;
                    // neu n le thi
                    else return -((n-1)/2+1);
                }   
                int main(){
                    int t;
                    scanf("%d", &t);
                    while(t--){
                        long long n;
                        scanf("%lld", &n);
                        printf("%lld\n", solve(n));
                    }
                    return 0;
                }
```
- Giải thích : 
    - Khi $n$ chẵn thì : $f(n) = -1 + 2 - 3 + 4 - 5 + 6 - \dots - (n-1) + n = (2-1) + (4-3) + \dots + (n-(n-1)) = 1 + 1 + \dots + 1 = n/2$ do cứ 2 số hạng ghép lại thì bằng 1 và có $n/2$ cặp số hạng 1
    - Khi $n$ lẻ thì : $f(n) = -1 + 2 - 3 + 4 - 5 + 6 - \dots + (n-1) - n = (2-1) + (4-3) + \dots + ((n-1)-n) = 1 + 1 + \dots + 1 - n = (n-1)/2 - n = -(n-1)/2 - 1 = -((n-1)/2 + 1)$ do cứ 2 số hạng ghép lại thì bằng 1 và có $(n-1)/2$ cặp số hạng 1 và còn lại số $-n$ ở cuối thành (n-1)/2 - n = -((n-1)/2 + 1)
----

**Bài 36. 1350A.**

Orac đang nghiên cứu lý thuyết số, và ông quan tâm đến các tính chất của ước số.

Đối với hai số nguyên dương $a$ và $b$, $a$ là ước của $b$ khi và chỉ khi tồn tại số nguyên $c$, sao cho $a \cdot c = b$.

Với $n \ge 2$, chúng ta sẽ biểu thị $f(n)$ là ước số dương nhỏ nhất của $n$, ngoại trừ $1$.

Ví dụ: $f(7) = 7, f(10) = 2, f(35) = 5$.

Đối với số nguyên $n$ cố định, Orac quyết định thêm $f(n)$ vào $n$.

Ví dụ: nếu anh ta có số nguyên $n = 5$, giá trị mới của $n$ sẽ bằng $10$. Và nếu anh ta có số nguyên $n = 6$, $n$ sẽ được thay đổi thành $8$.

Orac yêu nó rất nhiều, vì vậy anh quyết định lặp lại thao tác này nhiều lần.

Bây giờ, với hai số nguyên dương $n$ và $k$, Orac đã yêu cầu bạn thêm $f(n)$ vào $n$ chính xác $k$ lần (lưu ý rằng $n$ sẽ thay đổi sau mỗi thao tác, vì vậy $f(n)$ cũng có thể thay đổi) và cho anh ta biết giá trị cuối cùng của $n$.

Ví dụ: nếu Orac cho bạn $n = 5$ và $k = 2$, lúc đầu, bạn nên thêm $f(5) = 5$ thành $n = 5$, vì vậy giá trị mới của $n$ sẽ bằng $n = 10$, sau đó, bạn nên thêm $f(10) = 2$ đến $10$, vì vậy giá trị mới (và cuối cùng!) của bạn sẽ bằng $12$.

Orac có thể hỏi bạn những truy vấn này nhiều lần.

**Input**

Dòng đầu tiên của đầu vào là một số nguyên $t$ ($1 \le t \le 100$): số lần mà Orac sẽ hỏi bạn.

Mỗi dòng trong $t$ dòng tiếp theo chứa hai số nguyên dương $n, k$ ($2 \le n \le 10^6, 1 \le k \le 10^9$), tương ứng với truy vấn của Orac.

Được đảm bảo rằng tổng số của $n$ tối đa là $10^6$.

**Output**

In ra $t$ dòng, dòng thứ $i$ chứa giá trị cuối cùng của $n$ trong truy vấn thứ $i$ của Orac.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 3<br>5 1<br>8 2<br>3 4 | <br>10<br>12<br>12 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                // tim uoc chung nho nhat cua n 
                int find(int n){
                    for(int i = 2; i <= n; ++i){
                        if(n%i == 0) return i;
                    }
                }
                
                int solve(int n, int k){
                    // ham find(n) chinh la f(n)
                    for(int i = 1; i <= k; i++){
                        n += find(n);
                    }
                    return n;
                }
                int main(){
                    int t;
                    scanf("%d", &t);
                    while(t--){
                        int n, k;
                        scanf("%d %d", &n, &k);
                        printf("%d\n", solve(n, k));
                    }
                    return 0;
                }
```

- Cách 2 : 
```cpp
                #include <stdio.h>
                #include <math.h>

                // ham tim uoc chung nho nhat cua n 
                int find(int n){
                    // neu n chan thi uoc chung nho nhat cua no la 2 
                    if(n%2 == 0) return 2;
                    // neu n le thi
                    for(int i = 3; i <= n; i += 2){
                        if(n%i == 0) return i;
                    }
                }

                int main(){
                    int t;
                    scanf("%d", &t);
                    while(t--){
                        int n, k;
                        scanf("%d %d", &n, &k);
                        // neu n chan thi f(n) = 2
                        // suy ra n sau khi cong f(n) thi n = n + 2
                        // va sau khi cong f(n) thi n luon luon chan nen suy ra 
                        // n sau khi cong f(n) thi f(n) = 2 luon
                        // suy ra n sau khi cong f(n) thi n = n + 2*k
                        if(n%2 == 0){
                            printf("%d\n", n + 2*k);
                        }
                        // neu n le thi f(n) la so le nho nhat khac 1
                        // thi n + f(n) la so chan
                        //  bay gio (n + f(n)) la so chan
                        // ta con lai k - 1 lan cong nen f((n + f(n)) = 2 luon
                        // suy ra (n + f(n)) sau khi cong f(n) thi n = (n + f(n)) + 2*(k-1)
                        // suy ra n sau khi cong f(n) thi n = n + f(n) + 2*(k-1)
                        else{
                            int f = find(n);
                            printf("%d\n", n + f + 2*(k-1));
                        }
                    }
                    return 0;
                }
```

----

**Bài 37. 1238A : Prime substraction**

Bạn được cung cấp hai số nguyên $x$ và $y$ (đảm bảo rằng $x > y$). Bạn có thể chọn bất kỳ số nguyên tố $p$ nào và trừ nó bất kỳ số lần nào từ $x$. Có thể làm $x$ bằng $y$?

Hãy nhớ rằng một số nguyên tố là một số nguyên dương có chính xác hai ước số dương: 1 và chính nó. Chuỗi các số nguyên tố bắt đầu bằng 2, 3, 5, 7, 11.

Chương trình của bạn nên giải quyết các trường hợp kiểm tra độc lập.

**Input**

Dòng đầu tiên chứa một số nguyên $t$ ($1 \le t \le 1000$) - số lượng trường hợp kiểm tra.

Sau đó $t$ dòng tiếp theo, mỗi dòng mô tả một trường hợp thử nghiệm. Mỗi dòng chứa hai số nguyên $x$ và $y$ ($1 \le y < x \le 10^{18}$).

**Output**

Đối với mỗi trường hợp kiểm tra, hãy in YES nếu có thể chọn số nguyên tố $p$ và trừ nó bất kỳ số lần nào từ $x$ để $x$ trở thành bằng $y$. Nếu không, in NO.

Bạn có thể in mọi chữ cái trong mọi trường hợp bạn muốn (ví dụ: các chuỗi yEs, yes, Yes, và YES đều sẽ được công nhận là câu trả lời hợp lệ).

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 4<br>100 98<br>42 32<br>1000000000000000000 1<br>41 40 | <br>YES<br>YES<br>YES<br>NO |

**Code**
```cpp
                    #include <stdio.h>
                    #include <math.h>

                    int main(){
                        int t;
                        scanf("%d", &t);
                        while(t--){
                            long long x, y;
                            scanf("%lld", &x);
                            scanf("%lld", &y);
                            // khi x - y = 1 thi khong the lam duoc vi 1 khong la so nguyen to
                            if(x - y == 1) printf("NO\n");
                            // khi x - y > 1 thi luon lam duoc vi
                            else printf("YES\n");
                        }
                        return 0;
                    }
```