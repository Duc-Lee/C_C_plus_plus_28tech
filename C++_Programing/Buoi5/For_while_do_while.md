# Vòng lặp For, While và Do - While

-------
## 1. Cú pháp For

```cpp
for (khởi tạo biến đếm ; điều kiện ; bước nhảy) {
    // Các lệnh được thực thi
}
```

- Trong đó : 
    - **Khởi tạo biến đếm**: Khởi tạo biến đếm, thường là số nguyên, trước khi vòng lặp bắt đầu
    - **Điều kiện**: Điều kiện để vòng lặp tiếp tục thực thi, nếu điều kiện sai thì vòng lặp sẽ dừng
    - **Bước nhảy**: Bước nhảy của biến đếm, thường là tăng hoặc giảm biến đếm

- Ví dụ : In ra các số từ 0 đến n
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n;
                    cin >> n;
                    for (int i = 0; i<= n;i++){
                        cout << "i = " << i << endl;
                    }
                    return 0;
                }
```

- Luồng hoạt động : 
    - Bước 1 :  **i = 0**
        - Kiểm tra điều kiện **i <= n**
        - Thực hiện các lệnh trong vòng lặp
        - Bước nhảy của biến đếm **i++**
    - Bước 2 :  **i = 1**
        - Kiểm tra điều kiện **i <= n**
        - Thực hiện các lệnh trong vòng lặp
        - Bước nhảy của biến đếm **i++**
    - ...
    - Bước n :  **i = n**
        - Kiểm tra điều kiện **i <= n**, nếu đúng thì thực hiện các lệnh trong vòng lặp
        - Thực hiện các lệnh trong vòng lặp
        - Bước nhảy của biến đếm **i++**
    - ...
    - Bước n+1 :  **i = n+1**
        - Kiểm tra điều kiện **i <= n**, nếu sai thì dừng vòng lặp

- Ví dụ : In ra số từ 1 đến 100 chia hết cho 5 
    - Cách 1 : 
    ```c++ 
                #include <iostream>
                using namespace std;
                int main(){
                    for (int i = 1; i <= 100;i++){
                        // Thêm điều kiện i có chia hết cho 5 không 
                        if (i % 5 == 0){
                            cout << i << endl;
                        }
                    }
                    return 0;
                }
    ```
    - Cách 2 : 
    ```c++ 
                #include <iostream>
                using namespace std;
                int main(){
                    // Thay vì thêm điều kiện và tăng 1 đơn vị thì ta tăng 5 đơn vị
                    for (int i = 5; i <= 100;i+=5){
                        cout << i << endl;
                    }
                    return 0;
                }
    ```

- Ví dụ 3 : In ngược từ 100 về 0 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    // sử dụng i-- để giảm giá trị i
                    for (int i = 100; i >= 0;i--){
                        cout << i << endl;
                    }
                    return 0;
                }
```
- Lưu ý : Nếu ngoài vòng `for` thêm câu lệnh `cout << i << endl` thì sẽ báo lỗi `Error i` vì biến `i` được khai báo bên trong vòng lặp `for` nên phạm vi hoạt động (scope) của nó chỉ nằm trong vòng lặp đó. Khi ra ngoài vòng lặp, biến `i` không còn tồn tại.
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    // sử dụng i-- để giảm giá trị i
                    for (int i = 100; i >= 0;i--){
                        cout << i << endl;
                    }
                    // Báo lỗi biến i 
                    cout << i << endl;
                    return 0;
                }
```

- Ví dụ 4 : Câu lệnh `break` trong vòng lặp `for`
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    for (int i =0;i<=10;i++){
                        // Nếu i == 5 thì vòng lặp sẽ dừng
                        // break có nghĩa là dừng vòng lặp ngay lập tức
                        if (i == 5){
                            break;
                        }
                        cout << i << " ";
                    }
                    // Không in ra 5
                    return 0;
                }
                // Kết quả : 0 1 2 3 4 
```

- Ví dụ 5 : Câu lệnh `continue` trong vòng lặp `for`
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    for (int i = 0;i<=10;i++){
                        // Nếu i == 5 thì vòng lặp sẽ dừng
                        // continue có nghĩa là bỏ qua vòng lặp hiện tại và chuyển sang vòng lặp tiếp theo
                        if (i == 5){
                            continue;
                        }
                        cout << i << " ";
                    }
                    return 0;
                }
                // Kết quả : 0 1 2 3 4 6 7 8 9 10
```

- **Bài tập**
  - **Bài 1:** Nhập vào giá trị của `n` nguyên dương, tính tổng sau và in kết quả ra màn hình:
    $$S = 1 + 2 + 3 + \dots + n$$
    
    ```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n;
                    cin >> n;
                    // Khởi tạo biến tổng 
                    int sum = 0;
                    for (int i = 1;i <=n;i++){
                        // Cộng thêm i vô biến sum sau mỗi lần lặp
                        sum += i;
                    }
                    cout << "S = " << sum << endl;
                    return 0;
                }
                // Có thể dùng cách khác
                // sum = ( n * (n + 1) / 2)
    ```


  - **Bài 2:** Nhập vào giá trị của `n` nguyên dương, tính tổng sau và in kết quả ra màn hình:
    $$S = 1^2 + 2^2 + 3^2 + 4^2 + \dots + n^2$$

    ```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n;
                    cin >> n;
                    // Khởi tạo biến tổng 
                    int sum = 0;
                    for (int i = 1; i<=n ;i++){
                        // Cộng thêm i^2 vô biến sum sau mỗi lần lặp
                        sum += i * i;
                    }
                    cout << "S = " << sum << endl;
                    return 0;
                }
                // Có thể dùng cách khác
                // sum = ( n * (n + 1) * (2 * n + 1)) / 6
    ```

  - **Bài 3:** Nhập vào giá trị của `n`, tính tổng các số nguyên dương không vượt quá `n`, chia hết cho `3`:
    - Cách 1 : 
    ```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n;
                    cin >> n;
                    int sum = 0;
                    for (int i = 1; i<= n;i++){
                        if (i % 3 == 0){
                            sum += i;
                        }
                    }
                    cout << "S = " << sum << endl;
                    return 0;
                }
    ```

    - Cách 2 : 
    ```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n;
                    cin >> n;
                    int sum = 0;
                    for (int i = 3; i<=n;i+=3){
                        sum += i;
                    }
                    cout << "S = " << sum << endl;
                    return 0;
                }
    ```

--------
## 2. Vòng lặp `while`

- Cú pháp : 
```c++
                while ( điều kiện )
                {
                    // Các câu lệnh 
                    bien = biến + ...;
                }
```
- Trong đó : 
    - `điều kiện` là điều kiện để vòng lặp tiếp tục chạy 
    - `bien = biến + ...` là các câu lệnh được thực hiện trong vòng lặp

- Ví dụ 1 : In ra từ 1 đến 3 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n = 3;
                    int i = 1;
                    while(i<=3){
                        cout << i << " ";
                        i += 1;
                    }
                }
                // Kết quả : 1 2 3 
```
- Luồng hoạt động :
    - Bước 1 : `i` = 1
        - Kiểm tra điều kiện : i <=3 (1<=3)
        - true -> vào vòng lặp
        - In ra `i`
        - `i` tăng 1 đơn vị (`i` = 2)
    - Bước 2 : `i` = 2
        - Kiểm tra điều kiện : i <=3 (2<=3)
        - true -> vào vòng lặp
        - In ra `i`
        - `i` tăng 1 đơn vị (`i` = 3)
    - Bước 3 : `i` = 3
        - Kiểm tra điều kiện : i <=3 (3<=3)
        - true -> vào vòng lặp
        - In ra `i`
        - `i` tăng 1 đơn vị (`i` = 4)
    - Bước 4 : `i` = 4
        - Kiểm tra điều kiện : i <=3 (4<=3)
        - false -> dừng vòng lặp

- Lưu ý : Trong vòng lặp `while` nếu không có câu lệnh `i += ..` để tăng biến `i` thì vòng lặp sẽ lặp vô tận
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n = 3;
                    int i = 1;
                    while(i<=3){
                        cout << i << " ";
                        // i += 1; 
                    }
                }
                // Lặp vô tận 
```

- Ví dụ 2 : Có thể không cần dùng biến `i` 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    // Số khác 0 sẽ được coi là true 
                    // Số 0 sẽ được coi là false 
                    // 10 > 0 cũng tương tự 
                    while(10){
                        cout << "Hello " << endl;
                    }
                    return 0;
                }
                // Lặp vô tận 
```
- Nếu `while(0)` thì dừng ngay lập tức
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    while(0){
                        cout << "Hello " << endl;
                    }
                    return 0;
                }
```

- Ví dụ 3 : Vòng lặp `while` kết hợp với `break` 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int i = 1;
                    while(i<=10){
                        // Nếu i == 5 thì vòng lặp sẽ dừng
                        // break có nghĩa là dừng vòng lặp ngay lập tức
                        if (i == 5){
                            break;
                        }
                        cout << i << " ";
                        i += 1;
                    }
                    // Không in ra 5
                    return 0;
                }
```

- Ví dụ 4 : Vòng lặp `while` kết hợp với `continue` 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int i = 1;
                    while(i<=10){
                        // Nếu i == 5 thì vòng lặp sẽ dừng
                        // continue có nghĩa là bỏ qua vòng lặp hiện tại và chuyển sang vòng lặp tiếp theo
                        if (i == 5){
                            continue;
                        }
                        cout << i << " ";
                        i += 1;
                    }
                    // Không in ra 5
                    return 0;
                }
```

- Ví dụ 5 : Đếm số lượng chữ số của số n 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n;
                    cin >> n;
                    int cnt = 0;
                    while (n != 0){
                        ++cnt;
                        n /= 10;
                    }
                    cout << cnt;
                    return 0;
                }
                // Ví dụ : n = 12345 
                // C1 : cnt = 1 , n = 1234
                // C2 : cnt = 2 , n = 123
                // C3 : cnt = 3 , n = 12
                // C4 : cnt = 4 , n = 1
                // C5 : cnt = 5 , n = 0 
                // Dừng 
                // Kết quả : 5 
```

- Ví dụ 6 : Tính tổng chữ số n 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n;
                    cin >> n;
                    int sum = 0;
                    while(n!=0){
                        // Lấy chữ số cuối cùng của n bằng phép chia lấy dư cho 10 
                        sum += n%10;
                        // Xóa chữ số cuối cùng của n bằng phép chia lấy nguyên cho 10
                        n /=10;
                    }
                    cout << sum;
                    return 0;
                }
                // Ví dụ : n = 12345 
                // C1 : sum = 12345 % 10 = 5 , n = 12345 / 10 = 1234
                // C2 : sum = 5 + 1234 % 10 = 5 + 4 = 9 , n = 1234 / 10 = 123
                // C3 : sum = 9 + 123 % 10 = 9 + 3 = 12 , n = 123 / 10 = 12
                // C4 : sum = 12 + 12 % 10 = 12 + 2 = 14 , n = 12 / 10 = 1
                // C5 : sum = 14 + 1 % 10 = 14 + 1 = 15 , n = 1 / 10 = 0 
                // Dừng 
                // Kết quả : 15 
```

- Ví dụ 7 :  Đảo ngược số n 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n;
                    cin >> n;
                    int rev = 0;
                    while ( n != 0){
                        // Lấy chữ số cuối cùng của n bằng phép chia lấy dư cho 10
                        rev = rev *10 + n%10;
                        // Xóa chữ số cuối cùng của n bằng phép chia lấy nguyên cho 10
                        n /= 10;
                    }
                    cout << rev;
                    return 0;
                }
                // Ví dụ : n = 12345 
                // C1 : rev = 0 * 10 + 12345 % 10 = 5 , n = 12345 / 10 = 1234
                // C2 : rev = 5 * 10 + 1234 % 10 = 50 + 4 = 54 , n = 1234 / 10 = 123
                // C3 : rev = 54 * 10 + 123 % 10 = 540 + 3 = 543 , n = 123 / 10 = 12
                // C4 : rev = 543 * 10 + 12 % 10 = 5430 + 2 = 5432 , n = 12 / 10 = 1
                // C5 : rev = 5432 * 10 + 1 % 10 = 54320 + 1 = 54321 , n = 1 / 10 = 0 
                // Dừng 
                // Kết quả : 54321 
```

--------
## 3. Vòng lặp `Do` - `While`

- Cú pháp : 
```c++
                do {
                    // Các câu lệnh
                     bien = bien + ...;
                }while(điều kiện);
```

- Sự khác biệt giữa `while` và `do-while` :
    - `while` : Nếu điều kiện sai thì không vào vòng lặp 
    - `do-while` : Vào vòng lặp ít nhất 1 lần, do kiểm tra điều kiện sau khi thực hiện câu lệnh trong vòng lặp

- Ví dụ 1 :  
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int i = 1;
                    do{
                        cout << i << " ";
                        i += 1;
                    }while(i<=3);
                    return 0;
                }
                // Kết quả : 1 2 3 
```
- Luồng hoạt động : 
    - Bước 1 : `i` = 1
        - Thực hiện câu lệnh trong `do-while`
        - In ra `i`
        - `i` tăng 1 đơn vị (`i` = 2)
    - Bước 2 : Kiểm tra điều kiện : i <= 3 (2 <= 3)
        - true -> vào vòng lặp
        - In ra `i`
        - `i` tăng 1 đơn vị (`i` = 3)
    - Bước 3 : Kiểm tra điều kiện : i <= 3 (3 <= 3)
        - true -> vào vòng lặp
        - In ra `i`
        - `i` tăng 1 đơn vị (`i` = 4)
    - Bước 4 : Kiểm tra điều kiện : i <= 3 (4 <= 3)
        - false -> dừng vòng lặp

- Ví dụ 2 : Chạy ít nhất 1 lần (do kiểm tra điều kiện sau)
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int i = 0;
                    do{
                        cout << i << " ";
                        ++i;
                    }while(0);
                    return 0;
                }
                // Kết quả : 0 
                // Do i = 0 nên in ra 0 
                // sau đó i = 1 , điều kiện i == 0 (1 == 0 ) là false -> dừng
```

- Ví dụ 3 : Kiểm tra điều kiện nhập vào số n là số chẵn
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    int n;
                    do{
                        // Nhập vào cho đến khi n chẵn 
                        cin >> n;
                    }while( n%2 != 0);
                    cout << n << endl;
                    return 0;
                }
```