# Cấu trúc rẽ nhánh trong C++

## 1. Câu lệnh điều kiện `if`
- Cú pháp : 
```c++
            if (điều kiện){
                // code
            }
```
-  Nếu điều kiện đúng thì code trong ngoặc sẽ được thực thi ( trả về giá trị true), ngược lại thì code sẽ không được thực thi
- Ví dụ 1: 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 10;
                if (a > 5){
                    cout << "a lon hon 5" << endl;
                }
                return 0;
            }
```
- Ví dụ 2 : Kiểm tra số đó có phải số chẵn không 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int n = 20;
                // n % 2 == 0 là kiểm tra xem n có chia hết cho 2 không
                // Nếu n chia hết cho 2 thì n%2 sẽ bằng 0
                if (n%2) == 0{
                    cout << " n la so chan" << endl;
                }
                return 0;
            }
```
- Lưu ý : `0` là `false` còn một số khác `0` thì là `true`
- Ví dụ 3 : 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int a = 100;
                // 100 khác 0 nên là true
                if (a){
                    cout << " a la true" << endl;
                }
                return 0;
            }
```

--------
## 2. Câu lệnh điều kiện `if-else`
- Cú pháp : 
```c++
            if (điều kiện){
                // code
            }
            else{
                // code
            }
```
-  Nếu điều kiện đúng thì code trong ngoặc sẽ được thực thi ( trả về giá trị true), ngược lại thì code sẽ không được thực thi
- Ví dụ 1: nhập n và kiểm tra n có phải số chẵn không 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int n;
                cin >> n;
                if (n%2 == 0){
                    cout << " n la so chan" << endl;
                }
                else{
                    cout << " n la so le" << endl;
                }
                return 0;
            }
```

-------
## 3. Câu lệnh điều kiện `if-else if-else`
- Cú pháp :
```c++
            if (điều kiện){
                // code
            }
            else if (điều kiện){
                // code
            }
            else{
                // code
            }
```
-  Nếu điều kiện thứ 1 đúng thì code trong ngoặc sẽ được thực thi ( trả về giá trị true), ngược lại thì code sẽ không được thực thi 
- Nếu điều kiện thứ 1 sai thì sẽ kiểm tra điều kiện thứ 2 , nếu đúng thì code trong ngoặc sẽ được thực thi ( trả về giá trị true), ngược lại thì code sẽ không được thực thi
- Nếu tất cả các điều kiện đều sai thì code trong ngoặc của `else` sẽ được thực thi ( trả về giá trị true)
- Ví dụ 1:  nếu nhập số 1 thì chủ nhật, 2 thì thứ hai, 3 thì thứ ba, ngược lại thì in ra "khong xac dinh"
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int n;
                cin >> n;
                if (n == 1){
                    cout << "chu nhat" << endl;
                }
                else if (n == 2){
                    cout << "thu hai" << endl;
                }
                else if (n == 3){
                    cout << "thu ba" << endl;
                }
                else{
                    cout << "khong xac dinh" << endl;
                }
                return 0;
            }
```

---------
## 4. Câu lệnh điều kiện `if-else if-else` lồng nhau
- Cú pháp : 
```c++ 
            #include <iostream>
            using namespace std;
            int main(){
                int a,b,c;
                cin >> a >> b >> c;
                if (a > b){
                    if (a > c){
                        cout << "a la so lon nhat" << endl;
                    }
                }
                else{
                    if (b > c){
                        cout << "b la so lon nhat" << endl;
                    }
                    else{
                        cout << "c la so lon nhat" << endl;
                    }
                }
                return 0;
            }
```

-------
## 5. Cấu trúc `switch-case`
- Cú pháp :
```c++
            switch (bien){
                case 1:
                    // code
                    break;
                case 2:
                    // code
                    break;
                case 3:
                    // code
                    break;
                default:
                    // code
                    break;
            }
```
- Giải thích : Nếu `bien` bằng 1 thì `case 1` sẽ được thực thi ( trả về giá trị true), ngược lại thì code sẽ không được thực thi

- Ví dụ 1 : so sanh biến day
```c++
            #include <iostream>
            using namespace std;
            int main(){
                int day = 4;
                switch(day){
                    case 1:
                        cout << "chunhat" << endl;
                        break;
                    case 2:
                        cout << "thu hai" << endl;
                        break;
                    case 3:
                        cout << "thu ba" << endl;
                        break;
                    case 4:
                        cout << "thu tu" << endl;
                        break;
                    case 5:
                        cout << "thu nam" << endl;
                        break;
                    case 6:
                        cout << "thu sau" << endl;
                        break;
                    case 7:
                        cout << "thu bay" << endl;
                        break;
                    default:
                        cout << "khong xac dinh" << endl;
                        break;
                }
                return 0;
            }
```
- Lưu ý : Sau mỗi câu lệnh phải có `break` nếu không có `break` thì code sẽ chạy tiếp sang câu lệnh tiếp theo
- Ví dụ 2 : có thể gộp nhiều `case` 
```c++
            #include <iostream>
            using namespace std;
            int main(){
                // Nhập một số n 
                // Nếu tháng 1,3,5,7,8,10,12 thì 31 ngày
                // Nếu tháng 4,6,9,11 thì 30 ngày
                // Nếu tháng 2 thì 28 ngày ( năm nhuận) hoặc 29 ngày ( năm không nhuận)
                int n ;
                cin >> n;
                switch (n){
                    case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
                        cout << "31 ngay" << endl;
                        break;
                    case 4 : case 6 : case 9 : case 11 :
                        cout << "30 ngay" << endl;
                        break;
                    case 2 :
                        // nếu n là năm nhuận thì 29 ngày, ngược lại 28 ngày
                        // n chia hết cho 4 là năm nhuận
                        if (n%4 == 0){
                            cout << "29 ngay" << endl;
                        }
                        else{
                            cout << "28 ngay" << endl;
                        }
                        break;
                    default:
                        cout << "khong xac dinh" << endl;
                        break;
                }
                return 0;
            }
```
