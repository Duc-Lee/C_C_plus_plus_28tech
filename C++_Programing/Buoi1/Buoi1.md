# Input & Output in C++

- Chương trình C++ đầu tiên
```c++
        // Khai báo thư viện chính
        #include <iostream>

        // Sử dụng namespace std
        using namespace std;
        // Các hàm từ khoá có sẵn nằm trong namespace 
        // Hàm main - Điểm bắt đầu của chương trình
        int main(){
            // In ra màn hình dòng chữ "Hello World"
            cout << "Hello World";
            // Trả về 0 để báo hiệu chương trình kết thúc thành công
            return 0;
        }
        // lưu ý mỗi câu lệnh trong C++ đều kết thúc bằng dấu chấm phẩy ";"
        // các câu lệnh nằm trong khối lệnh được bao quanh bởi cặp dấu ngoặc nhọn "{}"

```
------
## 1. Hàm in ra màn hình `cout`
- `cout` là viết tắt của "console output"
- `<<` là toán tử luồng, dùng để đẩy dữ liệu vào luồng output
- Muốn sử dụng hàm `cout` phải khai báo thư viện `<iostream>` và namespace `std`
```c++
    #include <iostream>
    using namespace std;
    int main(){
        // In ra màn hình dòng chữ "Hello World"
        cout << "Hello World";
        // Trả về 0 để báo hiệu chương trình kết thúc thành công
        return 0;
    }
```
- Nếu không sử dụng `namespace` thì phải khai báo `std` trước mỗi lần sử dụng hàm `cout`
```c++
    #include <iostream>
    int main(){
        // In ra màn hình dòng chữ "Hello World"
        // :: là toán tử phạm vi, dùng để truy cập các thành phần của một namespace
        std::cout << "Hello World \n";
        // Trả về 0 để báo hiệu chương trình kết thúc thành công
        return 0;
    }
```
- `endl` là xuống dòng và đẩy dữ liệu vào luồng output
- `\n` cũng là xuống dòng nhưng không đẩy dữ liệu vào luồng output
------
## 2. Kiểu dữ liệu ( Data Type)
- Kiểu dữ liệu là để phân loại dữ liệu

### a. Kiểu số nguyên ( Integers)

- Các số nguyên có thể là số âm hoặc số dương
- Thông thường một số nguyên có n bit thì biểu diễn được $2^n$ giá trị
- Với số nguyên có dấu, nó sẽ biểu diễn được từ $-2^{n-1}$ đến $2^{n-1}-1$ do mất 1 bit để lưu trữ dấu
- Các loại số nguyên trong C++:
    - `int`: số nguyên (mặc định) có kích thước 4 byte
    - `short`: số nguyên ngắn (nhỏ hơn int) có kích thước 2 byte
    - `long`: số nguyên dài (lớn hơn int) có kích thước 4 byte
    - `long long`: số nguyên rất dài (lớn hơn long) có kích thước 8 byte

- Ví dụ biểu diễn số `int` có thể biểu diễn được 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                // Giới hạn của số nguyên có kích thước 4 byte
                // << có thể nối nhiều dữ liệu vào nhau
                cout << INT_MIN << " " << INT_MAX << endl;
                return 0;
            }
```
- Ngoài ra còn có biểu diễn số nguyên không dấu, biểu diễn giá trị từ 0 đến $2^n-1$
    - `unsigned int`: số nguyên không dấu có kích thước 4 byte
    - `unsigned short`: số nguyên không dấu có kích thước 2 byte
    - `unsigned long`: số nguyên không dấu có kích thước 4 byte
    - `unsigned long long`: số nguyên không dấu có kích thước 8 byte
    

### b. Kiểu số thực (Floating-point numbers)

- Biểu diễn các số thực, các số có dấu phẩy động
    - `float`: số thực có kích thước 4 byte
    - `double`: số thực có kích thước 8 byte
    - `long double`: số thực có kích thước 16 byte

### c. Kiểu số ký tự (Character)
- `char`: ký tự có kích thước 1 byte
    - `char` có 256 giá trị từ 0 đến 255, tương ứng với 256 ký tự trong bảng mã ASCII
    - Ví dụ:
    ```c++
                #include <iostream>
                using namespace std;
                int main(){
                    char c = 'a';
                    cout << c << endl;
                    return 0;
                }
    ```
    - Mặc dù có kích thước 1 byte nhưng `char` có thể biểu diễn được 256 giá trị, lớn hơn 

### d. Kiểu logic ( Boolean)
- `bool`: logic có kích thước 1 byte
- Có 2 giá trị: `true` và `false`
- `bool` có thể biểu diễn số nguyên từ -128 đến 127
- Ví dụ : 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                bool b = true;
                cout << b << endl;
                return 0;
            }
```
------
## 3. Biến ( Variables)

- Biến là một vùng nhớ dùng để lưu trữ dữ liệu
- Cú pháp : 
    - `Kieu_du_lieu Ten_bien = value;`
- Ví dụ:
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                cout << a << endl;
                return 0;
            }
```
### a. Quy tắc đặt tên biến 

- Chỉ bắt đầu bằng chữ cái hoặc dấu gạch dưới
- Chỉ chứa chữ cái, dấu gạch dưới và số
- Không được sử dụng các từ khóa của C++
- Phân biệt chữ hoa chữ thường
- Không đặt tên biến bắt đầu bằng số

### b. Khai báo biến

- Khai báo biến là để dành ra một vùng nhớ để lưu trữ dữ liệu
- Ví dụ:
```c++
            #include <iostream>
            using namespace std;
            int main(){
                // Khai báo 3 biến 
                int a;
                int b;
                int c;
                // Khai báo 3 biến cùng kiểu
                // int a, b, c; // phân cách bằng dấu , là được
                // Khi chưa gán giá trị thì biến sẽ có giá trị rác
                cout << a << " " << b << " " << c << endl;
                // Gán lại giá trị 
                a = 10;
                b = 20;
                c = 30;
                // In lại giá trị
                cout << a << " " << b << " " << c << endl;
                // Vừa khai báo vừa khởi tạo 
                int x = 10, y = 20;
                cout << x << " " << y << endl;
                return 0;
            }
```
------
## 4. Comment

- Comment là những dòng ghi chú trong code, không được thực thi bởi trình biên dịch
- Comment giúp cho người đọc dễ hiểu code
- Cú pháp : 
    - `// Comment` : Comment 1 dòng
    - `/* Comment */` : Comment nhiều dòng
- Ví dụ:
```c++
            #include <iostream>
            using namespace std;
            int main(){
                // Đây là comment
                /* Đây là comment
                   nhiều dòng */
                return 0;
            }
``` 
------
## 5. Input (Nhập liệu)

### a. Cú pháp cơ bản của `cin`
- `cin` (console input) là hàm/luồng dùng để nhập dữ liệu từ bàn phím.
- Cú pháp: 
    - `cin >> Ten_bien;`
- Ví dụ:
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a;
                cin >> a;
                cout << a << endl;
                return 0;
            }
```

### b. Nhập nhiều biến cùng lúc
- `>>` là toán tử trích xuất luồng (extraction operator), dùng để đẩy dữ liệu từ luồng input vào biến.
- Bạn có thể viết nối tiếp các toán tử `>>` để nhập nhiều biến trên cùng một câu lệnh.
- Ví dụ:
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a, b, c;
                // Nhập cả 3 biến trên một dòng (cách nhau bởi khoảng trắng/tab/xuống dòng)
                cin >> a >> b >> c;
                cout << a << " " << b << " " << c << endl;
                return 0;
            }
```

### c. Hiện tượng tràn số (Overflow) khi nhập dữ liệu
- Hiện tượng `tràn số` (`overflow`) xảy ra khi giá trị nhập vào từ bàn phím vượt quá giới hạn lưu trữ tối đa của kiểu dữ liệu được khai báo cho biến.
- Ví dụ:
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int b;
                // Nếu nhập 1234556776577744 (số quá lớn so với giới hạn của kiểu int 4 byte)
                // Kết quả hiển thị ra màn hình sẽ bị sai lệch (hoặc ra số âm) do tràn số
                // Để lưu trữ số lớn hơn, ta cần dùng kiểu dữ liệu lớn hơn như long long
                cin >> b;
                cout << b << endl;
                return 0;
            }
```

### d. Nhập và định dạng hiển thị số thực (Sử dụng `fixed` và `setprecision`)
- Để khống chế số lượng chữ số phần thập phân sau dấu phẩy khi in số thực, ta sử dụng tổ hợp `fixed` và `setprecision()`.
- Hai bộ định dạng này nằm trong thư viện `<iomanip>`, vì vậy cần `#include <iomanip>`.
- Cú pháp:
    - `cout << fixed << setprecision(N) << a << endl;` : In ra chính xác `N` chữ số sau dấu thập phân.
- Ví dụ:
```c++
            #include <iostream>
            #include <iomanip>
            using namespace std;
            int main(){
                double a;
                cin >> a;
                // In ra chính xác 2 chữ số sau dấu thập phân
                cout << fixed << setprecision(2) << a << endl;
                return 0;
            }
```

### e. Nhập kiểu ký tự (`char`)
- Sử dụng `cin` để nhập một ký tự duy nhất từ bàn phím.
- Ví dụ:
```c++
            #include <iostream>
            using namespace std;
            int main(){
                char a;
                cin >> a;
                cout << a << endl;
                return 0;
            }
```

### f. Nhập kiểu logic (`bool`)
- Khi nhập kiểu `bool` từ bàn phím:
    - Nhập `1` (hoặc khác 0) đại diện cho `true` (in ra màn hình sẽ là `1`).
    - Nhập `0` đại diện cho `false` (in ra màn hình sẽ là `0`).
- Ví dụ:
```c++
            #include <iostream>
            using namespace std;
            int main(){
                bool a = true;
                // Khi nhập 1 từ bàn phím -> in ra 1 (true)
                // Khi nhập 0 từ bàn phím -> in ra 0 (false)
                cin >> a;
                cout << a << endl;
                return 0;
            }
```
-------
## 6. Từ khoá `typedef`
- Từ khoá `typedef` dùng để định nghĩa lại kiểu dữ liệu
- Cú pháp : `typedef <kiểu dữ liệu cũ> <kiểu dữ liệu mới>;`
- Ví dụ :
```c++
            #include <iostream>
            using namespace std;
            // Định nghĩa lại kiểu dữ liệu int
            typedef long long ll;
            int main(){
                ll b = 10000000000;
                cout << b << endl;
                return 0;
            }
```
- Phân biệt `typedef` và `#define`
```c++
            #include <iostream>
            using namespace std;
            // Sử dụng #define
            #define ll long long
            int main(){
                ll a = 10000000000;
                cout << a << endl;
                return 0;
            }
```
- Điểm khác biệt:
    - `typedef` được định nghĩa tại thời điểm biên dịch
    - `#define` được định nghĩa tại thời điểm tiền xử lý
    - `typedef` có thể định nghĩa lại kiểu dữ liệu
    - `#define` không thể định nghĩa lại kiểu dữ liệu

-------
## 7. Thư viện của C++

### a. Thư viện chuẩn `iostream`
- Thư viện chuẩn `iostream` là thư viện chuẩn của C++, dùng để nhập xuất dữ liệu.
- Cú pháp: `#include <iostream>`
- Thư viện chứa các hàm : 
    - `cin`: Nhập dữ liệu từ bàn phím
    - `cout`: In dữ liệu ra màn hình
    - `endl`: Xuống dòng

### b. Thư viện `bits/stdc++.h`
- Thư viện chuẩn `bits/stdc++.h` là thư viện chuẩn của C++, dùng để bao gồm tất cả các thư viện chuẩn của C++.
- Cú pháp: `#include <bits/stdc++.h>`
- Lưu ý : Khi dùng thư viện này thì không cần include các thư viện khác
- Thư viện chứa tất cả các thư viện chuẩn của C++

### c. Thư viện Math `cmath`
- Thư viện chuẩn `cmath` là thư viện chuẩn của C++, dùng để tính toán các hàm toán học.
- Cú pháp: `#include <cmath>`
- Thư viện chứa các hàm :
    - `sqrt()`: Tính căn bậc hai
    - `pow()`: Tính lũy thừa
    - `abs()`: Tính giá trị tuyệt đối
    - `ceil()`: Làm tròn lên
    - `floor()`: Làm tròn xuống
    - `round()`: Làm tròn gần nhất
    - `sin()`: Tính sin
    - `cos()`: Tính cos
    - `tan()`: Tính tan
    - `asin()`: Tính arcsin
    - `acos()`: Tính arccos
    - `atan()`: Tính arctan
    - `sinh()`: Tính sinh
    - `cosh()`: Tính cosh
    - `tanh()`: Tính tanh
    - `asinh()`: Tính arcsinh
    - `acosh()`: Tính arccosh
    - `atanh()`: Tính arctanh

### d. Thư viện `iomanip`
- Thư viện chuẩn `iomanip` là thư viện chuẩn của C++, dùng để định dạng hiển thị dữ liệu.
- Cú pháp: `#include <iomanip>`
- Thư viện chứa các hàm :
    - `setw()`: Set độ rộng của dữ liệu
    - `setprecision()`: Set độ chính xác của dữ liệu
    - `fixed`: Set định dạng hiển thị số thực
    - `setfill()`: Set ký tự lấp đầy
    
- Lưu ý : Khi dùng định dạng của `iomanip` thì phải ép kiểu dữ liệu của biến về `double` hoặc `float` để định dạng hiển thị

### e. Thư viện `string`
- Thư viện chuẩn `string` là thư viện chuẩn của C++, dùng để thao tác với chuỗi ký tự.
- Cú pháp: `#include <string>`
- Thư viện chứa các lớp :
    - `string`: Lớp để thao tác với chuỗi ký tự
    - `getline()`: Hàm để nhập chuỗi ký tự
    - `length()`: Hàm để lấy độ dài của chuỗi ký tự
    - `substr()`: Hàm để lấy chuỗi con
    - `find()`: Hàm để tìm chuỗi con
    - `replace()`: Hàm để thay thế chuỗi con
    - `insert()`: Hàm để chèn chuỗi con
    - `erase()`: Hàm để xóa chuỗi con
    - `append()`: Hàm để nối chuỗi con
    
### f. Thư viện `cctype`
- Thư viện chuẩn `cctype` là thư viện chuẩn của C++, dùng để thao tác với ký tự.
- Cú pháp: `#include <cctype>`
- Thư viện chứa các hàm :
    - `isalpha()`: Kiểm tra ký tự có phải là chữ cái không
    - `isdigit()`: Kiểm tra ký tự có phải là số không
    - `isalnum()`: Kiểm tra ký tự có phải là chữ cái hoặc số không
    - `islower()`: Kiểm tra ký tự có phải là chữ cái viết thường không
    - `isupper()`: Kiểm tra ký tự có phải là chữ cái viết hoa không
    - `tolower()`: Chuyển ký tự sang chữ cái viết thường
    - `toupper()`: Chuyển ký tự sang chữ cái viết hoa
    - `isspace()`: Kiểm tra ký tự có phải là khoảng trắng không
    
### g. Thư viện `vector`
- Thư viện chuẩn `vector` là thư viện chuẩn của C++, dùng để thao tác với vector.
- Cú pháp: `#include <vector>`
- Thư viện chứa các lớp :
    - `vector`: Lớp để thao tác với vector
    - `push_back()`: Hàm để thêm phần tử vào cuối vector
    - `pop_back()`: Hàm để xóa phần tử ở cuối vector
    - `insert()`: Hàm để chèn phần tử vào vector
    - `erase()`: Hàm để xóa phần tử trong vector
    - `clear()`: Hàm để xóa tất cả các phần tử trong vector
    - `size()`: Hàm để lấy số lượng phần tử trong vector
    - `empty()`: Hàm để kiểm tra vector có rỗng không

### h. Thư viện `algorithm`
- Thư viện chuẩn `algorithm` là thư viện chuẩn của C++, dùng để thao tác với thuật toán.
- Cú pháp: `#include <algorithm>`
- Thư viện chứa các hàm :
    - `sort()`: Hàm để sắp xếp vector
    - `reverse()`: Hàm để đảo ngược vector
    - `find()`: Hàm để tìm phần tử trong vector
    - `lower_bound()`: Hàm để tìm phần tử trong vector
    - `upper_bound()`: Hàm để tìm phần tử trong vector
    - `binary_search()`: Hàm để tìm phần tử trong vector
    - `min()`: Hàm để tìm giá trị nhỏ nhất
    - `max()`: Hàm để tìm giá trị lớn nhất
    - `swap()`: Hàm để hoán đổi giá trị
    
### i. Thư viện `set`
- Thư viện chuẩn `set` là thư viện chuẩn của C++, dùng để thao tác với set.
- Cú pháp: `#include <set>`
- Thư viện chứa các lớp :
    - `set`: Lớp để thao tác với set
    - `insert()`: Hàm để chèn phần tử vào set
    - `erase()`: Hàm để xóa phần tử trong set
    - `clear()`: Hàm để xóa tất cả các phần tử trong set
    - `size()`: Hàm để lấy số lượng phần tử trong set
    - `empty()`: Hàm để kiểm tra set có rỗng không

### j. Thư viện `map`
- Thư viện chuẩn `map` là thư viện chuẩn của C++, dùng để thao tác với map.
- Cú pháp: `#include <map>`
- Thư viện chứa các lớp :
    - `map`: Lớp để thao tác với map
    - `insert()`: Hàm để chèn phần tử vào map
    - `erase()`: Hàm để xóa phần tử trong map
    - `clear()`: Hàm để xóa tất cả các phần tử trong map
    - `size()`: Hàm để lấy số lượng phần tử trong map
    - `empty()`: Hàm để kiểm tra map có rỗng không

### k. Các thư viện Cấu Trúc Dữ Liệu
- Thư viện `stack`:
- Thư viện `queue`:
- Thư viện `deque`:
- Thư viện `priority_queue`:
- Thư viện `list`:
- Thư viện `set`:
- Thư viện `map`:
