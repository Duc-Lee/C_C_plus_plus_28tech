# Các toán tử ( Operater) trong C++

--------
## 1. Toán tử gán ( Assignment operator)

- Toán tử gán dùng để gán giá trị cho biến
- Cú pháp : `bien = value;`
- Ví dụ :
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10; // gán giá trị 10 cho biến a
                int b = a; // gán giá trị của a cho b
                cout << a << endl;
                cout << b << endl;
                return 0;
            }
```
--------
## 2. Toán tử số học ( Arithmetic operator)

- Toán tử số học dùng để thực hiện các phép toán số học
- Toán tử số học : `+`, `-`, `*`, `/`, `%`
- Toán tử `+` : cộng
- Toán tử `-` : trừ
- Toán tử `*` : nhân
- Toán tử `/` : chia
- Toán tử `%` : chia lấy dư
- Ví dụ :
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 500;
                int b = 200;
                cout << a + b << endl; // 500 + 200 = 700
                cout << a - b << endl; // 500 - 200 = 300
                cout << a * b << endl; // 500 * 200 = 100000
                cout << a / b << endl; // 500 / 200 = 2
                cout << a % b << endl; // 500 % 200 = 100
                return 0;
            }
```
- Lưu ý : Phép chia `/` của hai số nguyên sẽ cho kết quả là một số nguyên ( loại bỏ phần thập phân)

- Khi khai báo biến `a` và `b` là `int` mà muốn kết quả phép chia là số thực thì phải ép kiểu sang `double` 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 500;
                int b = 200;
                double c = (double)a / b; // ép kiểu a sang double
                cout << c << endl; // 2.5
                return 0;
            }
```
- Hoặc có cách khác là sử dụng 1 trong 2 biến là double 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 500;
                double c = a / 200.0; // số 200.0 có dấu chấm là double
                cout << c << endl; // 2.5
                return 0;
            }
```
- Hoặc cũng có cách khác là dùng `1.0` nhân với 1 trong 2 số
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 500;
                int b = 200;
                double c = a * 1.0 / b; // số 1.0 có dấu chấm là double
                cout << c << endl; // 2.5
                return 0;
            }
```
- Cần phải cẩn thận phép chia cho 0
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                int b = 0;
                cout << a / b << endl; // báo lỗi runtime
                return 0;
            }
```
- Chú ý phép chia lấy dư `%` chỉ dùng được cho số nguyên
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                double b = 20.0;
                cout << a % b << endl; // báo lỗi
                return 0;
            }
```
- Nếu ta có phép tính `a = a + 1` thì có thể viết là `a += 1`
- Tương tự với các phép toán khác: `a -= 1`, `a *= 1`, `a /= 1`, `a %= 1`
- Ví dụ :
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                a += 1;
                cout << a << endl; // 11
                a -= 1;
                cout << a << endl; // 10
                a *= 1;
                cout << a << endl; // 10
                a /= 1;
                cout << a << endl; // 10
                a %= 1;
                cout << a << endl; // 10
                return 0;
            }
``` 

--------
## 3. Toán tử tăng giảm ( Increment/ Decrement operator)

- Toán tử tăng giảm dùng để tăng hoặc giảm giá trị của biến đi 1
- Toán tử tăng giảm : `++`, `--`
- Toán tử `++` : tăng giá trị của biến lên 1
- Toán tử `--` : giảm giá trị của biến đi 1
- Ví dụ :
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                a++;
                cout << a << endl; // 11
                a--;
                cout << a << endl; // 10
                return 0;
            }
```
### a. Tiền tăng giảm ( Pre-increment/ Pre-decrement)
- Cú pháp : `++bien` hoặc `--bien`
- Ý nghĩa : Tăng hoặc giảm giá trị của biến đi 1 và trả về giá trị mới trước khi thực hiện phép toán
- Ví dụ 1 : 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                // Tăng a trước khi gán a cho b
                int b = ++a; // b = 11 , a = 11
                cout << b << " " << a << endl; // 11 11
                return 0;
            }
```
- Ví dụ 2 : 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                int b = 20;
                cout << ++a + b << endl; // 11 + 20 = 31
                cout << a << endl; // 11
                cout << --a + b << endl; // 10 + 20 = 30
                return 0;
            }
```
### b. Hậu tăng giảm ( Post-increment/ Post-decrement)
- Cú pháp : `bien++` hoặc `bien--`
- Ý nghĩa : Tăng hoặc giảm giá trị của biến đi 1 và trả về giá trị cũ sau khi thực hiện phép toán
- Ví dụ 1: 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                // Gán a cho b trước khi tăng a
                int b = a++; // b = 10 , a = 11
                cout << b << " " << a << endl; // 10 11
                return 0;
            }
```
- Ví dụ 2: 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                int b = 20;
                cout << a++ + b << endl; // 10 + 20 = 30
                cout << a << endl; // 11
                cout << a-- + b << endl; // 11 + 20 = 31
                cout << a << endl; // 10
                return 0;
            }
```

------
## 4. Toán tử so sánh ( Comparison operator)

- Toán tử so sánh dùng để so sánh giá trị của hai biến, kết quả trả về là `true` hoặc `false`
- Toán tử so sánh : `==`, `!=`, `>`, `<`, `>=`, `<=`
- Toán tử `==` : bằng
- Toán tử `!=` : không bằng
- Toán tử `>` : lớn hơn
- Toán tử `<` : nhỏ hơn
- Toán tử `>=` : lớn hơn hoặc bằng
- Toán tử `<=` : nhỏ hơn hoặc bằng
- Ví dụ :
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                int b = 20;
                cout << (a == b) << endl; // 0 ( false)
                cout << (a != b) << endl; // 1 ( true)
                cout << (a > b) << endl; // 0 ( false)
                cout << (a < b) << endl; // 1 ( true)
                cout << (a >= b) << endl; // 0 ( false)
                cout << (a <= b) << endl; // 1 ( true)
                return 0;
            }
```
- Lưu ý : `==` khác `=`
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                int b = 20;
                bool ok = a == b; // ok = false
                cout << (ok == 1) << endl; // true
                return 0;
            }
```
------
## 5. Toán tử logic ( Logical operator)

- Toán tử logic dùng để kết hợp các điều kiện
- Toán tử logic : `&&`, `||`, `!`
- Toán tử `&&` : và
- Toán tử `||` : hoặc
- Toán tử `!` : phủ định
- Ví dụ :
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                int b = 20;
                cout << (a == b && a > b) << endl; // 0 ( false)
                cout << (a == b || a > b) << endl; // 1 ( true)
                cout << !(a == b) << endl; // 1 ( true)
                return 0;
            }
```
------
## 6. Toán tử bitwise ( Bitwise operator)

- Toán tử bitwise dùng để thao tác trên các bit của số nguyên
- Toán tử bitwise : `&`, `|`, `^`, `~`, `<<`, `>>`
- Toán tử `&` : và bitwise
- Toán tử `|` : hoặc bitwise
- Toán tử `^` : xor bitwise
- Toán tử `~` : phủ định bitwise
- Toán tử `<<` : dịch trái
- Toán tử `>>` : dịch phải
- Ví dụ :
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                int b = 20;
                cout << (a & b) << endl; // 0 ( false)
                cout << (a | b) << endl; // 1 ( true)
                cout << (a ^ b) << endl; // 1 ( true)
                cout << (~a) << endl; // 1 ( true)
                cout << (a << b) << endl; // 1 ( true)
                cout << (a >> b) << endl; // 1 ( true)
                return 0;
            }
```

------
## 7. Các hàm toán học trong thư viện `math.h`
- Các hàm toán học trong thư viện `math.h` :
    - `sqrt(x)` : căn bậc hai của x, `sqrt` trả về số `double`
    - `pow(x, y)` : x mũ y, `pow` trả về số `double`
    - `abs(x)` : giá trị tuyệt đối của x, `abs` trả về số `double`
    - `ceil(x)` : làm tròn lên, `ceil` trả về số `double`
    - `floor(x)` : làm tròn xuống, `floor` trả về số `double`
    - `round(x)` : làm tròn gần nhất, `round` trả về số `double`
    - `fmod(x, y)` : phép chia lấy dư của x và y, `fmod` trả về số `double`
    - `sin(x)` : sin của x radian, `sin` trả về số `double`
    - `cos(x)` : cos của x radian, `cos` trả về số `double`
    - `tan(x)` : tan của x radian, `tan` trả về số `double`
    - `asin(x)` : arcsin của x radian, `asin` trả về số `double`
    - `acos(x)` : arccos của x radian, `acos` trả về số `double`
    - `atan(x)` : arctan của x radian, `atan` trả về số `double`
- Ví dụ :
```c++
            #include <iostream>
            using namespace std;
            #include <math.h>
            int main(){
                cout << sqrt(16) << endl; // 4
                cout << pow(2, 3) << endl; // 8
                cout << abs(-16) << endl; // 16
                cout << ceil(16.1) << endl; // 17
                cout << floor(16.9) << endl; // 16
                cout << round(16.5) << endl; // 17
                cout << fmod(16, 3) << endl; // 1
                cout << sin(0) << endl; // 0
                cout << cos(0) << endl; // 1
                cout << tan(0) << endl; // 0
                cout << asin(0) << endl; // 0
                cout << acos(1) << endl; // 0
                cout << atan(0) << endl; // 0
                return 0;
            }
```