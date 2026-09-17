# Hàm trong C++

## 1. Hàm là gì ?
- Hàm là một khối mã độc lập, có thể tái sử dụng, được thiết kế để thực hiện một nhiệm vụ cụ thể. Trong C++, hàm giúp tổ chức mã, giảm sự lặp lại và cải thiện khả năng bảo trì của chương trình
- Lợi ích : 
    - **Tái sử dụng mã**: Hàm cho phép gọi lại cùng một khối mã nhiều lần mà không cần viết lại.
    - **Tổ chức chương trình**: Giúp chia chương trình lớn thành các module nhỏ, dễ quản lý và gỡ lỗi.
    - **Dễ bảo trì**: Khi có lỗi hoặc cần cập nhật, chỉ cần sửa ở một nơi duy nhất là hàm đó.

-------
## 2. Cấu Trúc của một hàm
- Cú pháp : 
```cpp 
                    return_type function_name(parameters1, parameters2, ...)
                    {
                        // code
                        return expression;
                    }
```
- Giải thích : 
    - `return_type`: Kiểu dữ liệu trả về của hàm, có thể là `int`, `float`, `double`, `string`, `void`, ... Nếu hàm không trả về giá trị nào thì sử dụng `void`
    - `function_name`: Tên của hàm
    - `parameters`: Danh sách các tham số của hàm, có thể có hoặc không, nếu có thì mỗi tham số gồm kiểu dữ liệu và tên tham số
    - `function body`: Thân hàm, chứa các câu lệnh để thực hiện công việc của hàm
    - `return expression`: Giá trị trả về của hàm

- Ví dụ 1 : Xây dựng hàm `hello`
```cpp
                    #include <bits/stdc++.h>
                    using namespace std;
                    // Xây dựng hàm 
                    void hello(){
                        cout << "Hello C++" << endl;
                    }
                    int main(){
                        hello(); // Gọi hàm hello
                        return 0;
                    }
```

- Ví dụ 2 : Câu lệnh `return`
```cpp
                    #include <bits/stdc++.h>
                    using namespace std;
                    // Hàm tính tổng 2 số
                    int add(int a, int b){
                        // Sẽ trả về ngay lập tức khi gặp câu lệnh return
                        // Các câu lệnh sau return sẽ không được thực thi
                        return a + b;
                        cout << "Hello C++" << endl;
                    }
                    int main(){
                        int a = 1;
                        int b = 2;
                        cout << add(a, b) << endl; 
                        return 0;
                        // Kết quả sẽ chỉ là 3
                        // Sẽ không in ra "Hello C++"
                    }
```

- Ví dụ 3 : Trả về giá trị lớn hơn
    - Cách 1 : Dùng if else
    ```cpp
                        #include <bits/stdc++.h>
                        using namespace std;
                        // Hàm trả về giá trị lớn hơn
                        int max(int a, int b){
                            if (a > b){
                                return a;
                            }
                            else{
                                return b;
                            }
                        }
                        int main(){
                            int a = 1;
                            int b = 2;
                            cout << max(a, b) << endl; 
                            return 0;
                        }
    ```
    - Cách 2 : Dùng toán tử 3 ngôi
    ```cpp
                        #include <bits/stdc++.h>
                        using namespace std;
                        // Hàm trả về giá trị lớn hơn
                        int max(int a, int b){
                            return a > b ? a : b;
                        }
                        int main(){
                            int a = 1;
                            int b = 2;
                            cout << max(a, b) << endl; 
                            return 0;
                        }
    ```
    - Ý nghĩa ` a > b ? a : b ` : Nếu ` a > b` đúng thì trả về ` a` ngược lại trả về ` b `, `?:` được gọi là toán tử 3 ngôi (Conditional operator), `a : b` là giá trị trả về khi ` a > b` đúng và ngược lại

- Ý nghĩa : Câu lệnh `return` sẽ trả về giá trị của biểu thức và kết thúc hàm ngay lập tức, các câu lệnh sau `return` sẽ không được thực thi

- Ví dụ 4 : Hàm tính giai thừa 
    - Cách 1 : Dùng đệ quy 
    ```cpp
                            #include <bits/stdc++.h>
                            using namespace std;
                            // Hàm tính giai thừa
                            // n! = n * (n-1) * (n-2) * ... * 1
                            // 0! = 1
                            // 1! = 1
                            // 2! = 2 * 1 = 2
                            // 3! = 3 * 2 * 1 = 6
                            // 4! = 4 * 3 * 2 * 1 = 24
                            // 5! = 5 * 4 * 3 * 2 * 1 = 120
                            int factorial(int n){
                                if (n == 0){
                                    return 1;
                                }
                                else{
                                    return n * factorial(n - 1);
                                }
                            }
                            int main(){
                                int n = 5;
                                cout << factorial(n) << endl; 
                                return 0;
                            }
    ```
    - Cách 2 :  Dùng `for`
    ```cpp
                            #include<bits/stdc++.h>
                            using namespace std;
                            int factorial(int n){
                                int result = 1;
                                for (int i = 2; i <= n; i++){
                                    result *= i;
                                }
                                return result;
                            }
                            int main(){
                                int n = 5;
                                cout << factorial(n) << endl; 
                                return 0;
                            }
    ```

- Ví dụ 5 : Hàm tổng chữ số của số nguyên n 
    - n % 10 : Lấy chữ số cuối cùng của số nguyên n 
    - n / 10 : Loại bỏ chữ số cuối cùng của số nguyên n 
    ```cpp
                            #include <bits/stdc++.h>
                            using namespace std;
                            int sum_digit(int n){
                                int sum = 0;
                                // n != 0 tương đương while(true) : đúng 
                                // n == 0 tương đương while(false) : sai
                                while (n){
                                    sum += n % 10;
                                    n /= 10;
                                }   
                                return sum;
                            }
                            int main(){
                                int n = 123;
                                cout << sum_digit(n) << endl; 
                                return 0;
                            }
    ```

- Ví dụ 6 : Kiểm tra số nguyên tố 
```cpp
                        #include <bits/stdc++.h>
                        using namespace std;
                        // Hàm kiểm tra số nguyên tố
                        // Số nguyên tố là số tự nhiên lớn hơn 1 và không có ước số khác ngoài 1 và chính nó
                        bool is_prime(int n){
                            if (n < 2){
                                return false;
                            }
                            for (int i = 2; i < n; i++){
                                if (n % i == 0){
                                    return false;
                                }
                            }
                            return true;
                        }
                        int main(){
                            int n = 123;
                            if (is_prime(n)){
                                cout << n << " la so nguyen to" << endl; 
                            }
                            else{
                                cout << n << " khong la so nguyen to" << endl; 
                            }
                            return 0;
                        }
```

- Ví dụ 7 : Viết hàm kiểm tra xem 1 số có thỏa mãn tính chất : **Tổng các chữ số của nó là số có tận cùng = 8**. Ví dụ số 666 thỏa mãn vì có tổng bằng 18 và có chữ số tận cùng của tổng là 8. Nếu thỏa mãn bạn hãy in "FIL", ngược lại in ra "KTPM". Bạn cần triển khai theo mã nguồn sau :
```cpp
                        #include <bits/stdc++.h>
                        using namespace std;

                        int sum_digit(int n){
                            int sum = 0;
                            sum += n%10;
                            n /= 10;
                            return sum;
                        }
                        // hàm check 
                        bool check(int n){
                            if(sum_digit(n) %10 == 8){
                                return true;
                            }
                            return false;
                        }
                        int main(){
                            int n = 666;
                            if(check(n)){
                                cout << "FIL" << endl;
                            }
                            else{
                                cout << "KTPM" << endl;
                            }
                            return 0;
                        }
```

- Ví dụ 8 : Tính tổng chẵn của n 
```cpp
                        #include <bits/stdc++.h>
                        using namespace std;
                        int sum_even(int n){
                            int sum = 0;
                            for (int i = 2; i <= n; i += 2){
                                sum += i;
                            }
                            return sum;
                        }
                        int main(){
                            int n = 10;
                            cout << sum_even(n) << endl; 
                            return 0;
                        }
```

------
## 3. Truyền tham số của hàm
- Tham số là cách để truyền dữ liệu vào hàm. Trong C++, có 2 cách truyền tham số : 
### 3.1 Truyền tham số theo giá trị
- Truyền tham số theo giá trị là cách truyền tham số bằng cách gán giá trị của biến cho tham số của hàm. Khi đó, hàm sẽ làm việc với một bản sao của biến, không ảnh hưởng đến biến gốc
- Ví dụ 1 : 
```cpp
                    #include <bits/stdc++.h>
                    using namespace std;
                    // Hàm cộng 2 số
                    int add(int a, int b){
                        return a + b;
                    }
                    int main(){
                        int a = 1;
                        int b = 2;
                        cout << add(a, b) << endl;
                        cout << a << " " << b << endl;
                        return 0;
                    }
```
- Lưu ý : Khi truyền tham số theo giá trị, hàm sẽ làm việc với một bản sao của biến, không ảnh hưởng đến biến gốc

- Ví dụ 2 : 
```cpp 
                    #include <iostream>
                    using namespace std;
                    // Hàm trừ 2 số
                    int sub(int a, int b){
                        return a - b;
                    }
                    int main(){
                        // Truyền tham số theo giá trị
                        // Lấy 5 gán cho a, 3 gán cho b
                        cout << sub(5, 3) << endl;
                        return 0;
                    }
```

- Ví dụ 3 : Lưu ý về ép kiểu khi truyền tham số theo giá trị
```cpp
                    #include <iostream>
                    using namespace std;
                    // Hàm hiển thị 2 số
                    void display(int a, int b){
                        cout << a << " " << b << endl;
                    }
                    int main(){
                        display(10, 20);
                        // Lấy 10.5 gán cho a, 3.8 gán cho b
                        // Vì a và b là kiểu int nên sẽ làm tròn 10.5 thành 10 và 3.8 thành 3
                        display(10.5,3.8);
                        // Lấy "Hello" gán cho a, "C++" gán cho b
                        // Vì a và b là kiểu int nên sẽ không thể gán cho a và b
                        display("Hello", "C++");
                        // Sẽ bị lỗi 
                        display(1,2,3);
                        // Sẽ bị lỗi 
                        display('a','B');
                        // Sẽ bị lỗi 
                        return 0;
                    }
```
- Lưu ý : Phải xác định rõ kiểu dữ liệu của tham số của hàm trước khi truyền tham số, nếu không sẽ bị lỗi hoặc kết quả không mong muốn

### 3.2 Truyền tham số theo tham chiếu
- Truyền tham số theo tham chiếu là cách truyền tham số bằng cách gán địa chỉ của biến cho tham số của hàm. Khi đó, hàm sẽ làm việc với biến gốc, ảnh hưởng đến biến gốc
- Cú pháp : 
```cpp
                    #include <bits/stdc++.h>
                    using namespace std;
                    // Hàm cộng 2 số
                    int add(int &a, int &b){
                        return a + b;
                    }
                    int main(){
                        int a = 1;
                        int b = 2;
                        cout << add(a, b) << endl;
                        return 0;
                    }
```

------
## 4. Xếp chồng toán tử
- Xếp chồng toán tử là việc sử dụng lại toán tử cho các kiểu dữ liệu khác nhau
- Cú pháp : 
```cpp
                    #include <bits/stdc++.h>
                    using namespace std;
                    // Hàm cộng 2 số
                    int add(int a, int b){
                        return a + b; // toán tử + được sử dụng cho kiểu int
                    }
                    int main(){
                        int a = 1;
                        int b = 2;
                        cout << add(a, b) << endl;
                        return 0;
                    }
```
- Ví dụ 2 : 
```cpp
                        #include <bits/stdc++.h>
                        using namespace std;
                        // Hàm cộng 2 số
                        int add(int a, int b){
                            return a + b; // toán tử + được sử dụng cho kiểu int
                        }
                        int main(){
                            int a = 1;
                            int b = 2;
                            cout << add(a, b) << endl;
                            return 0;
                        }
```

------
## 5. Đệ quy
- Đệ quy là việc hàm gọi lại chính nó 
- Cú pháp : 
```cpp
                    #include <bits/stdc++.h>
                    using namespace std;
                    // Hàm đệ quy
                    int recursive(int n){
                        if (n == 0){
                            return 0;
                        }
                        return recursive(n - 1);
                    }
                    int main(){
                        int n = 10;
                        cout << recursive(n) << endl;
                        return 0;
                    }
```
- Ví dụ 2 : Hàm đệ quy tính giai thừa
```cpp
                        #include <bits/stdc++.h>
                        using namespace std;
                        // Hàm đệ quy tính giai thừa
                        int factorial(int n){
                            if (n == 0){
                                return 1;
                            }
                            return n * factorial(n - 1);
                        }
                        int main(){
                            int n = 10;
                            cout << factorial(n) << endl;
                            return 0;
                        }
```

------
## 6. Hàm `main`
- Hàm `main` là hàm chính của chương trình, được gọi đầu tiên khi chương trình được thực thi
- Cú pháp : 
```cpp
                    #include <bits/stdc++.h>
                    using namespace std;
                    int main(){
                        return 0;
                    }
```
- Lưu ý : 
    - Hàm `main` có thể có nhiều cách viết 
    - Hàm `main` có thể có tham số 
    - Hàm `main` có thể trả về giá trị

- Ví dụ : sử dụng `void` 
```cpp
                        #include <bits/stdc++.h>
                        using namespace std;
                        void main(){
                            cout << "Hello World" << endl;
                        }
```
- Tuy nhiên hiện nay cách viết `void main` ít được sử dụng vì nó không tuân theo chuẩn C++

- Ví dụ : sử dụng `int main` với tham số
```cpp
                        #include <bits/stdc++.h>
                        using namespace std;
                        int main(int argc, char* argv[]){
                            cout << "Hello World" << endl;
                            return 0;
                        }
```
- Ý nghĩa : `argc` là số lượng tham số, `argv` là mảng các tham số 
- Ví dụ : 
```cpp
                        #include <bits/stdc++.h>
                        using namespace std;
                        int main(int argc, char* argv[]){
                            cout << "So luong tham so: " << argc << endl;
                            for (int i = 0; i < argc; i++){
                                cout << "Tham so thu " << i << ": " << argv[i] << endl;
                            }
                            return 0;
                        }
```
- Chạy chương trình với các tham số khác nhau
```bash
                        ./a.exe 
                        ./a.exe Hello
                        ./a.exe Hello C++
```

