# Bài tập Tổng Hợp Buổi 1,2,3
------
## Bài 1 : Tính tổng, hiệu, tích, thương
Nhập vào 2 số nguyên, in ra tổng, hiệu, tích, thương ( lấy độ chính xác với 2 chữ số).

### Input
- 2 số nguyên $a, b$ ( $-10^9 \le a, b \le 10^9$ )

### Output
- Tổng, hiệu, tích, thương của 2 số

### Ví dụ
| Input | Output |
| :--- | :--- |
| `10 2` | `12 8 20 5.00` |
| `1000000 1000000` | `2000000 0 1000000000000 1.00` |

### Code 
```c++
            #include <iostream>
            // Khai báo thư viện iomanip để sử dụng setprecision
            #include <iomanip>
            using namespace std;
            int main(){
                long long a, b;
                cin >> a >> b;
                // fixed là 
                // setprecision là 
                cout << a + b << " " << a - b << " " << a * b << " " << fixed << setprecision(2) << (double)a / b << endl;
                return 0;
            }
```
------
## Bài 2 : Tính chu vi, diện tích hình tròn

### Input
- Bán kính $r$ của hình tròn là một số nguyên ($1 \le r \le 10^6$)

### Output
- Chu vi và diện tích của hình tròn lấy độ chính xác với 2 chữ số (sử dụng số $\pi = 3.14$)

### Ví dụ
| Input | Output |
| :--- | :--- |
| `10` | `62.80 314.00` |

### Code
```c++
            #include <iostream>
            #include <iomanip>
            using namespace std;
            int main(){
                long long r;
                cin >> r;
                // Tính chu vi hình tròn
                cout << fixed << setprecision(2) << 2 * 3.14 * r;
                // Tính diện tích hình tròn
                cout << fixed << setprecision(2) << " " << 3.14 * r * r << endl;
                return 0;
            }
```
------

## Bài 3 : Tính khoảng cách
Tính khoảng cách Euclid giữa 2 điểm trong hệ tọa độ Oxy

### Input
- Tọa độ của 2 điểm $(x_1, y_1)$ và $(x_2, y_2)$ là các số nguyên ( $-10^6 \le x_i, y_i \le 10^6$ )

### Output
- Khoảng cách giữa 2 điểm lấy độ chính xác với 2 chữ số

### Ví dụ
| Input | Output |
| :--- | :--- |
| `1 4 4 8` | `5.00` |

### Code 
```c++
            #include <iostream>
            #include <iomanip>
            #include <math.h>
            using namespace std;
            int main(){
                long long x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                // Tính khoảng cách giữa 2 điểm
                cout << fixed << setprecision(2) << sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) << endl;
                return 0;
            }
```

------

## Bài 4 : Chuyển đơn vị đo C và F
Công thức chuyển đơn vị đo nhiệt độ từ C sang F như sau:
$$F = (C \times 9 / 5) + 32$$

Viết chương trình cho phép nhập vào nhiệt độ đo theo độ C là số nguyên dương không quá $10^6$, thực hiện chuyển sang đơn vị đo độ F và in ra màn hình. (Lưu ý luôn lấy 2 chữ số thập phân sau dấu chấm phẩy)

### Input
- Nhiệt độ đo theo độ C là số nguyên dương không quá $10^6$.

### Output
- Nhiệt độ đo theo độ F lấy độ chính xác với 2 chữ số.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `24` | `75.20` |

### Code 
```c++
            #include <iostream>
            #include <iomanip>
            using namespace std;
            int main (){
                long long c;
                cin >> c;
                double F = (c * (9/5)) + 32;
                cout << fixed << setprecision(2) << F << endl;
            }
```

------

## Bài 5 : Tìm trị tuyệt đối của số nguyên (Hàm abs)

### Input
- Số nguyên $n$ ( $-10^9 \le n \le 10^9$ )

### Output
- In ra trị tuyệt đối của $n$

### Ví dụ
| Input | Output |
| :--- | :--- |
| `-25` | `25` |
| `20` | `20` |

### Code 
```c++
            #include <iostream>
            #include <math.h>
            using namespace std;
            int main(){
                long long n;
                cin >> n;
                cout << abs(n) << endl;
            }
```

------

## Bài 6 : Tính tổng 1
$$S_n = 1 + 2 + 3 + 4 + ... + n$$

### Input
- Số nguyên không âm $n$ ( $0 \le n \le 10^9$ )

### Output
- Kết quả của bài toán

### Ví dụ
| Input | Output |
| :--- | :--- |
| `1000000000` | `500000000500000000` |

### Code 
- Lưu ý: Tổng các số từ $1$ đến $n$ có công thức tính là: $S = 1 + 2 + \dots + n = \frac{n(n + 1)}{2}$
```c++
            #include <iostream>
            #include <math.h>
            using namespace std;
            int main(){
                long long n;
                cin >> n;
                // dùng 1ll để tránh tràn số 
                cout << 1ll* n * (n + 1) / 2 << endl;
            }
```

------

## Bài 7 : Tính tổng 2
$$S_n = 1^2 + 2^2 + 3^2 + 4^2 + 5^2 + ... + n^2$$

### Input
- Số nguyên không âm $n$ ( $0 \le n \le 10^5$ )

### Output
- Kết quả của bài toán

### Ví dụ
| Input | Output |
| :--- | :--- |
| `100000` | `333338333350000` |

### Code 
- Lưu ý: Công thức tính tổng bình phương từ $1^2$ đến $n^2$ là: $S_n = \frac{n(n + 1)(2n + 1)}{6}$
```c++
            #include <iostream>
            #include <math.h>
            using namespace std; 
            int main(){
                long long n;
                cin >> n;
                cout << 1ll * n * (n +1)*(2*n +1)/6 << endl;
            }
```
------

## Bài 8 : Tính tổng 3
$$S_n = \frac{1}{1 \times 2} + \frac{1}{2 \times 3} + \frac{1}{3 \times 4} + \dots + \frac{1}{n \times (n+1)}$$

### Input
- Số nguyên dương $n$ ( $1 \le n \le 10^9$ )

### Output
- Kết quả của bài toán lấy độ chính xác 2 chữ số

### Ví dụ
| Input | Output |
| :--- | :--- |
| `99` | `0.99` |

### Code 
- Lưu ý: Công thức biến đổi chi tiết của tổng này như sau:
$$S_n = \frac{1}{1 \cdot 2} + \frac{1}{2 \cdot 3} + \frac{1}{3 \cdot 4} + \dots + \frac{1}{n(n+1)}$$
$$= \frac{1}{1} - \frac{1}{2} + \frac{1}{2} - \frac{1}{3} + \frac{1}{3} - \frac{1}{4} + \dots + \frac{1}{n} - \frac{1}{n+1}$$
$$= 1 - \frac{1}{n+1} = \frac{n}{n+1}$$
```c++
            #include <iostream>
            #include <iomanip>
            using namespace std;
            int main(){
                long long n;
                cin >> n;
                cout << fixed << setprecision(2) << 1.0 * n / (n+1) << endl;
            }
```

------

## Bài 9 : Tính tổng 4
$$S_n = 2 + 4 + 6 + 8 + \dots + 2n$$

### Input
- Số nguyên dương $n$ ( $1 \le n \le 10^9$ )

### Output
- Kết quả của bài toán

### Ví dụ
| Input | Output |
| :--- | :--- |
| `1000000` | `1000001000000` |
| `3` | `12` |

### Code 
- Lưu ý: Công thức tính tổng chẵn từ $2$ đến $2n$ là: $S_n = 2(1 + 2 + 3 + \dots + n) = 2\frac{n(n + 1)}{2} = n(n + 1)$
```c++
            #include <iostream>
            #include <math.h>
            using namespace std;
            int main(){
                long long n;
                cin >> n;
                cout << n*(n+1) << endl;
                return 0;
            }
```

------

## Bài 10 : Tính tổng 5
$$S_n = -1 + 2 - 3 + 4 - 5 + 6 + \dots + (-1)^n n$$

### Input
- Số nguyên dương $n$ ( $1 \le n \le 10^{16}$ )

### Output
- Kết quả của bài toán

### Ví dụ
| Input | Output |
| :--- | :--- |
| `1000000000000000` | `500000000000000` |

### Code 
- Lưu ý: Công thức tính tổng đan dấu này là:
  - Nếu $n$ chẵn: $S_n = \frac{n}{2}$
  - Nếu $n$ lẻ: $S_n = \frac{-n - 1}{2}$
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    long long n;
                    cin  >> n;
                    if (n%2) == 0{
                        cout << 1.0 * n /2 << endl;
                    } else{
                        cout << 1.0 * (-n-1)/2 << endl;
                    }
                }
```

------

## Bài 11 : Số chia hết lớn nhất
Cho 2 số nguyên dương $a$ và $b$. Tìm số chia hết cho $b$ lớn nhất và không vượt quá $a$.
*Chú ý: Không dùng vòng lặp và các hàm có sẵn.*

### Input
- 2 số nguyên dương $a, b$ ($1 \le b \le a \le 10^8$)

### Output
- Kết quả của bài toán

### Ví dụ
| Input | Output |
| :--- | :--- |
| `19 5` | `15` |
| `20 5` | `20` |

### Code 
- Gợi ý: Số chia hết cho $b$ lớn nhất không vượt quá $a$ có công thức là `(a / b) * b`
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    long long a,b;
                    cin >> a >> b;
                    cout << ( a/ b)* b << endl;
                }
```

------

## Bài 12 : Số chia hết nhỏ nhất
Cho 2 số nguyên dương $a$ và $b$. Tìm số chia hết cho $b$ nhỏ nhất và lớn hơn hoặc bằng $a$.
*Chú ý: Không dùng vòng lặp và các hàm có sẵn.*

### Input
- 2 số nguyên dương $a, b$ ($1 \le b \le a \le 10^8$)

### Output
- Kết quả của bài toán

### Ví dụ
| Input | Output |
| :--- | :--- |
| `19 5` | `20` |
| `20 5` | `20` |
| `21 5` | `25` |

### Code 
- Gợi ý: Số chia hết cho $b$ nhỏ nhất lớn hơn hoặc bằng $a$ có công thức là `((a + b - 1) / b) * b`
- `b-1` giúp làm tròn lên và không bao giờ nảy sang số tiếp theo khi a chia hết cho b. Vi dụ `20` và `5` thì `20` chia hết cho b sẵn rồi, nếu không trừ đi `1` thì nó sẽ nhảy sang số tiếp theo là `25`
- `a+b-1` có ý nghĩa là tìm số lớn hơn a nhưng nhỏ nhất chia hết cho b.
```c++
            #include <iostream>
            using namespace std;
            int main(){
                long long a,b;
                cin >> a >> b;
                cout << ((a+b-1)/b)*b<< endl;
            }   
```

------

## Bài 13 : Kiểm tra số chia hết cho 3 và 5

### Input
- Số nguyên $n$ ( $-10^{18} \le n \le 10^{18}$ )

### Output
- In ra `1` nếu $n$ chia hết cho cả 3 và 5, ngược lại in ra `0`

### Ví dụ
| Input | Output |
| :--- | :--- |
| `30` | `1` |
| `25` | `0` |

### Code 
- Gợi ý: Số chia hết cho cả 3 và 5 tức là chia hết cho 15 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    long long n;
                    cin >> n;
                    // hoặc có thể (n % 3 == 0) && (n % 5 == 0)
                    if (n%15)==0{
                        cout << 1 << endl;
                    } else{
                        cout << 0 << endl;
                    }
                }
```

------

## Bài 14 : Kiểm tra năm nhuận
Năm nhuận là năm chia hết cho 400 hoặc (chia hết cho 4 và không chia hết cho 100).

### Input
- Năm là một số nguyên $n$ ( $-10^6 \le n \le 10^6$ )

### Output
- In ra `INVALID` nếu $n$ là một số nguyên âm hoặc số 0.
- Nếu $n$ là năm nhuận, in ra `YES`, ngược lại in ra `NO`

### Ví dụ
| Input | Output |
| :--- | :--- |
| `2021` | `NO` |
| `2020` | `YES` |
| `-1982` | `INVALID` |

### Code 
- Gợi ý: Điều kiện để năm $n$ là năm nhuận: `(n % 400 == 0) || (n % 4 == 0 && n % 100 != 0)`. Nhớ kiểm tra điều kiện $n \le 0$ trước tiên để in ra `INVALID`.
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    long long n;
                    cin >> n;
                    if ( n <= 0){
                        cout << "INVALID" << endl;
                        return 0;
                    } else {
                        if ((n % 400 == 0) || ((n % 4 == 0) && (n % 100 != 0))){
                            cout << "YES" << endl;
                        } else{
                            cout << "NO" << endl;
                        }
                    }
                }
```

------

## Bài 15 : In ra số ngày của tháng

### Input
- 2 số nguyên $t$ và $n$ lần lượt là tháng và năm ( $-10^6 \le t, n \le 10^6$ )

### Output
- Nếu tháng và năm nhập vào không hợp lệ (tháng không nằm trong đoạn $[1, 12]$, hoặc năm không phải số dương), in ra `INVALID`.
- Ngược lại, in ra số ngày của tháng đó.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `2 2021` | `28` |
| `1 2021` | `31` |
| `14 2020` | `INVALID` |
| `-1 2019` | `INVALID` |
| `2 2020` | `29` |

### Code 
- Gợi ý: 
  - Điều kiện hợp lệ: `1 <= t && t <= 12 && n > 0`. Nếu không thỏa mãn thì in ra `INVALID`.
  - Các tháng `1, 3, 5, 7, 8, 10, 12` có `31` ngày.
  - Các tháng `4, 6, 9, 11` có `30` ngày.
  - Tháng `2`: Nếu là năm nhuận có `29` ngày, ngược lại có `28` ngày.
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    long long t,n;
                    cin >> t >> n;
                    if ( 1 <= t && t <= 12 && n>0>){
                        if (t == 1 || t == 3 || t == 5 || t == 7 || t == 8 || t == 10 || t == 12){
                            cout << 31 << endl
                    } else if (t == 4 || t == 6 || t == 9 || t == 11){
                            cout << 30 << endl
                    }else {
                        // Kiểm tra xem năm nhuận không để tháng 2 năm ấy có số ngày
                        if ((n % 400 == 0) || ((n % 4 == 0) && (n % 100 != 0))){
                            cout << 29 << endl;
                        } else{
                            cout << 28 << endl;
                        }
                    }
                } else{
                    cout << "INVALID" << endl;
                    }
                }
```

------
## Lưu ý : Các kí tự có trong bảng ASCII
    - A -> Z  (65->90)
    - a -> z  (97->122)
    - 0 -> 9  (48->57)

## Bài 16 : Kiểm tra chữ in thường

### Input
- Kí tự cần kiểm tra.

### Output
- In ra `YES` nếu kí tự nhập vào là chữ cái in thường, `NO` trong trường hợp ngược lại.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `A` | `NO` |
| `a` | `YES` |
| `%` | `NO` |

### Code 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    char c;
                    cin >> c;
                    // Có thể cách khác 
                    // c >= '97' && c <= '122'
                    if ( c >= 'a' && c <= "z"){
                        cout << "YES" << endl;
                    } else{
                        cout << "NO" << endl;
                    }
                }
```

------

## Bài 17 : Kiểm tra in hoa

### Input
- Kí tự cần kiểm tra.

### Output
- In ra `YES` nếu kí tự nhập vào là chữ cái in hoa, `NO` trong trường hợp ngược lại.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `A` | `YES` |
| `a` | `NO` |
| `%` | `NO` |

### Code 
- Gợi ý: Ký tự $c$ là chữ cái in hoa nếu thỏa mãn điều kiện `c >= 'A' && c <= 'Z'`.
```c++
                    #include <iostream>
                    using namespace std;
                    int main(){
                        char c;
                        cin >> c;
                        // c >= 65 && c <= 90
                        if ( c >= 'A' && c <= 'Z'){
                            cout << "YES" << endl;
                        } else{
                            cout << "NO" << endl;
                        }
                    }
```

------

## Bài 18 : Kiểm tra chữ cái

### Input
- Kí tự cần kiểm tra.

### Output
- In ra `YES` nếu kí tự nhập vào là chữ cái (in hoa hoặc in thường), `NO` trong trường hợp ngược lại.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `A` | `YES` |
| `a` | `YES` |
| `%` | `NO` |
| `1` | `NO` |

### Code 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    char c;
                    cin >> c;
                    // c >= 97 && c <= 122 || c >= 65 && c <= 90
                    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                        cout << "YES" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                    return 0;
                }
```

------

## Bài 19 : Kiểm tra chữ số

### Input
- Kí tự cần kiểm tra.

### Output
- In ra `YES` nếu kí tự nhập vào là chữ số, `NO` trong trường hợp ngược lại.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `A` | `NO` |
| `a` | `NO` |
| `5` | `YES` |

### Code 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    char c;
                    cin >> c;
                    // c >= 48 && c <= 57
                    if (c >= '0' && c <= '9'){
                        cout << "YES" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                    return 0;
                }
```

------

## Bài 20 : Chuyển ký tự hoa thành thường

### Input
- Kí tự cần chuyển.

### Output
- Nếu kí tự nhập vào là chữ in hoa, in ra dạng in thường tương ứng của nó.
- Nếu không phải chữ in hoa thì giữ nguyên kí tự ban đầu.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `A` | `a` |
| `a` | `a` |
| `%` | `%` |

### Code 
- Gợi ý: Nếu kí tự $c$ là chữ in hoa (trong khoảng từ `'A'` đến `'Z'`), ta chuyển thành in thường bằng cách cộng thêm `32` (tức là `c = c + 32`), hoặc có thể sử dụng hàm `tolower(c)` từ thư viện `<cctype>`.
```c++
                    #include <iostream>
                    using namespace std;
                    int main(){
                        char c;
                        cin >> c;
                        if (c >= 'A' && c <= "Z"){
                            cout << c+32 << endl;
                        } else {
                            cout << c << endl;
                        }
                    }
```
- Cách 2 : 
```c++
                    #include <iostream>
                    #include <cctype>
                    using namespace std;
                    int main(){
                        char c;
                        cin >> c;
                        cout << tolower(c) << endl;
                    }
```
------

## Bài 21 : Chuyển ký tự thường thành ký tự hoa

### Input
- Kí tự cần chuyển.

### Output
- Nếu kí tự nhập vào là chữ in thường, in ra dạng in hoa tương ứng của nó.
- Nếu không phải chữ in thường thì giữ nguyên kí tự ban đầu.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `A` | `A` |
| `a` | `A` |
| `%` | `%` |

### Code
- Gợi ý: Nếu kí tự $c$ là chữ in thường (trong khoảng từ `'a'` đến `'z'`), ta chuyển thành in hoa bằng cách trừ đi `32` (tức là `c = c - 32`), hoặc có thể sử dụng hàm `toupper(c)` từ thư viện `<cctype>`.

- **Cách 1: Sử dụng bảng mã ASCII**
```c++
                    #include <iostream>
                    using namespace std;
                    int main(){
                        char c;
                        cin >> c;
                        if (c >= 'a' && c <= 'z'){
                            cout << c - 32 << endl;
                        } else {
                            cout << c << endl;
                        }
                    }
```
- **Cách 2: Sử dụng thư viện `<cctype>`**
```c++
                    #include <iostream>
                    #include <cctype>
                    using namespace std;
                    int main(){
                        char c;
                        cin >> c;
                        cout << (char)toupper(c) << endl;
                    }
```

------

## Bài 22 : Chữ cái kế tiếp

### Input
- Một kí tự duy nhất.

### Output
- Nếu kí tự nhập vào là chữ cái, in ra chữ cái kế tiếp của nó trong bảng chữ cái ở dạng in thường (ta coi chữ cái kế tiếp của `z` (hoặc `Z`) là `a`).
- Nếu kí tự nhập vào không phải là chữ cái, in ra `INVALID`.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `A` | `b` |
| `Z` | `a` |
| `l` | `m` |
| `$` | `INVALID` |

### Code 
```c++
                    #include <iostream>
                    #include <cctype>
                    using namespace std;
                    int main () {
                        char c;
                        cin >> c;
                        // chuyển về chữ thường 
                        c = tolower(c);
                        if ( c >= 'a' && c <= 'y'){
                            cout << ++c << endl;
                        } else if (c == 'z'){
                            cout << "a" << endl;
                        } else {
                            cout << "INVALID" << endl;
                        }
                    }
```

------

## Bài 23 : Số lớn, số nhỏ

### Input
- 3 số nguyên $a, b, c$ ( $-10^6 \le a, b, c \le 10^6$ )

### Output
- In ra số lớn nhất và số nhỏ nhất trong 3 số, cách nhau bởi một khoảng trắng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `1 2 3` | `3 1` |
| `1 1 1` | `1 1` |

### Code 
- Gợi ý:
  - Cách 1: Sử dụng cấu trúc `if-else` lồng nhau để so sánh các cặp số tìm `max` và `min`.
  - Cách 2: Sử dụng thư viện `#include <algorithm>` và sử dụng hàm `max({a, b, c})` và `min({a, b, c})` (hoặc `max(a, max(b, c))` và `min(a, min(b, c))`).

- Cách 1 : 
```c++
                    #include <iostream>
                    using namespace std;
                    int main(){
                        long long a,b,c;
                        cin >> a >> b >> c;
                        if ( a > b){
                            if (b > c){
                                cout << a << " " << c << endl;
                            } else {
                                cout << a << " " << b << endl;
                            }
                        } else if ( b > c){
                            if (a > c){
                                cout << b << " " << c << endl;
                            } else {
                                cout << b << " " << a << endl;
                            }
                        } else {
                            if (a > b){
                                cout << c << " " << b << endl;
                            } else {
                                cout << c << " " << a << endl;
                            }
                        }
                    }
```
- Cách 2 : Sử dụng thư viện `algorithm`
```c++ 
                    #include <iostream>
                    #include <algorithm>
                    using namespace std;
                    int main(){
                        long long a,b,c;
                        cin >> a >> b >> c;
                        long long min_val = min({a, b, c});
                        long long max_val = max({a, b, c});
                        cout << max_val << " " << min_val << endl;
                    }
```

------

## Bài 24 : Tam giác hợp lệ

### Input
- 3 số nguyên $a, b, c$ lần lượt là độ dài 3 cạnh ( $-10^6 \le a, b, c \le 10^6$ )

### Output
- In ra `YES` nếu 3 cạnh nhập vào tạo thành một tam giác hợp lệ, ngược lại in ra `NO`

### Ví dụ
| Input | Output |
| :--- | :--- |
| `3 4 5` | `YES` |
| `1 1 5` | `NO` |
| `-1 2 3` | `NO` |
| `0 4 5` | `NO` |

### Code 
- Gợi ý: Điều kiện để $a, b, c$ là 3 cạnh của một tam giác hợp lệ:
  1. Cả 3 cạnh phải dương: $a > 0, b > 0, c > 0$.
  2. Tổng của 2 cạnh bất kỳ luôn lớn hơn cạnh còn lại: $a + b > c$ và $a + c > b$ và $b + c > a$.
```c++
                #include <iostream>
                using namespace std;
                int main() {
                    long long a,b,c;
                    cin >> a >> b >> c;
                    if ( a > 0 && b > 0 && c > 0) {
                        if ( a + b > c && a + c > b && b + c > a){
                        cout << "YES" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                    }
                }
```

------

## Bài 25 : Kiểm tra tam giác

### Input
- 3 số nguyên $a, b, c$ lần lượt là độ dài 3 cạnh ( $-10^6 \le a, b, c \le 10^6$ )

### Output
- In ra `INVALID` nếu tam giác đã cho không hợp lệ.
- In ra `1` nếu tam giác là tam giác đều.
- In ra `2` nếu tam giác là tam giác cân.
- In ra `3` nếu tam giác là tam giác vuông.
- In ra `4` nếu tam giác là tam giác vuông cân.
- In ra `5` nếu tam giác là tam giác thường.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `3 4 5` | `3` |
| `3 3 3` | `1` |
| `1 1 8` | `INVALID` |
| `4 4 6` | `2` |

### Code 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    long long a,b,c;
                    cin >> a >> b >> c;
                    // Kiểm tra xem có phải tam giác không ? 
                    if ( a > 0 && b > 0 && c > 0){
                        // Kiểm tra tam giác ? 
                        if ( a + b > c && a + c > b && b + c > a){
                            cout << "5" << endl;
                        } 
                        // Kiểm tra tam giác đều ?
                        else if ( a == b && b == c){
                            cout << "1" << endl;
                        }
                        // Kiểm tra tam giác cân ?
                        else if ( a == b || a == c || b == c){
                            cout << "2" << endl;
                        }
                        // Định lý pytago
                        else if ( a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b){
                            // cân vuông
                            if ( a == b || a == c || b == c){
                                cout << "4" << endl;
                            } else {
                                cout << "3" << endl;
                            }
                        }
                    } else {
                        cout << "INVALID" << endl;
                    }
                }
```

------

## Bài 26 : Chuyển đổi ngày sang năm, tuần, ngày
Viết chương trình cho phép nhập vào số ngày, thực hiện chuyển số ngày sang năm, tuần, ngày (Bỏ qua trường hợp năm nhuận, coi 1 năm luôn có 365 ngày, 1 tuần có 7 ngày).

### Input
- Số nguyên không âm $n$ ( $0 \le n \le 10^6$ )

### Output
- In ra số năm, số tuần, số ngày tương ứng, cách nhau bởi một khoảng trắng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `373` | `1 1 1` |

### Code 
- Gợi ý:
  - Số năm: `n / 365`
  - Số tuần: `(n % 365) / 7`
  - Số ngày: `(n % 365) % 7`
```c++
                    #include <iostream>
                    using namespace std;
                    int main(){
                        long long n;
                        cin >> n;
                        long long year = n / 365;
                        long long week = (n % 365) / 7;
                        long long day = (n % 365) % 7;
                        cout << year << " " << week << " " << day << endl;
                    }
```

------

## Bài 27 : Phương trình bậc 2
Phương trình bậc 2 là phương trình dạng $ax^2 + bx + c = 0$. Viết chương trình giải phương trình bậc 2.

### Input
- 3 số nguyên $a, b, c$ ( $-10^3 \le a, b, c \le 10^3$ )

### Output
- Nếu phương trình vô nghiệm, in ra `NO`.
- Nếu phương trình có vô số nghiệm, in ra `INF`.
- Nếu phương trình có nghiệm, in ra các nghiệm (luôn lấy 2 chữ số thập phân sau dấu chấm thập phân), cách nhau bởi một khoảng trắng. Trường hợp có 2 nghiệm phân biệt thì in ra nghiệm lớn hơn trước.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `8 -4 -2` | `0.81 -0.31` |

### Code 
```c++
                #include <iostream>
                #include <iomanip>
                #include <math.h>
                #include <algorithm>
                using namespace std;
                int main (){
                    double a, b, c;
                    cin >> a >> b >> c;
                    if (a != 0){
                        double delta =  b*b - 4*a*c;
                        // Phuong trinh vo nghiem
                        if (delta < 0){
                            cout << "NO" << endl;
                        }
                        // Phuong trinh co 1 nghiem
                        else if (delta == 0){
                            cout << fixed << setprecision(2) << -b/(2*a) << endl;
                        }
                        // Phuong trinh co 2 nghiem
                        else {
                            double x1 = (-b + sqrt(delta))/(2*a);
                            double x2 = (-b - sqrt(delta))/(2*a);
                            cout << fixed << setprecision(2) << max(x1, x2) << " " << min(x1, x2) << endl;
                        }
                    } else {
                        // Trường hợp a = 0
                        if (b != 0){
                            cout << fixed << setprecision(2) << -c/b << endl;
                        } else {
                            if (c == 0){
                                cout << "INF" << endl;
                            } else {
                                cout << "NO" << endl;
                            }
                        }
                    }
                    return 0;
                }
```

------

## Bài 28 : Số thuộc đoạn

### Yêu cầu
Cho một đoạn đại số $[a, b]$. Tính số lượng số nguyên trong đoạn $[a, b]$ đó.

### Input
- Một dòng ghi 2 số thực $a, b$ (giả sử $a \le b$).

### Output
- Số lượng các số nguyên trong đoạn $[a, b]$.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `1.1 5.2` | `4` |

### Code 
- Gợi ý:
  - Một số nguyên $x$ thuộc $[a, b]$ nếu $\lceil a \rceil \le x \le \lfloor b \rfloor$.
  - Số lượng số nguyên sẽ là: $\lfloor b \rfloor - \lceil a \rceil + 1$.
  - Sử dụng thư viện `#include <math.h>` với hàm `ceil(a)` và `floor(b)`.
```c++
                #include <iostream>
                #include <math.h>
                using namespace std;
                int main(){
                    double a,b;
                    cin >> a >> b;
                    cout << floor(b) - ceil(a) + 1 << endl;
                    return 0;
                }
```
------

## Bài 29 : Phép chia

### Yêu cầu
Cho 3 số nguyên 64-bit $a, b, c$. In ra dấu `/` nếu $a/b = c$ hoặc $b/c = a$ hoặc $c/a = b$ (phép chia hết), và in ra `NOSOL` nếu không thỏa mãn.

### Input
- Một dòng gồm 3 số nguyên $a, b, c$.

### Output
- Ghi ra `/` nếu thỏa mãn chia hết hoặc in ra `NOSOL` nếu không thỏa mãn.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `3 1 3` | `/` |
| `3 4 5` | `NOSOL` |

### Code 
```c++
                #include <iostream>
                using namespace std;
                int main(){
                    long long a,b,c;
                    cin >> a >> b >> c;
                    if (b != 0 && a % b == 0 && a / b == c){
                        cout << "/" << endl;
                    } else if (c != 0 && b % c == 0 && b / c == a){
                        cout << "/" << endl;
                    } else if (a != 0 && c % a == 0 && c / a == b){
                        cout << "/" << endl;
                    } else {
                        cout << "NOSOL" << endl;
                    }
                    return 0;
                }
```

------

## Bài 30 : Kết quả học tập

### Yêu cầu
Cho biết điểm kiểm tra Tin học của 1 em học sinh (2 con điểm hệ số 1, 1 con điểm hệ số 2, 1 con điểm hệ số 3). In ra Kết quả học tập môn Tin học của học sinh đó theo thang đánh giá sau:
- Điểm tổng kết $\ge 8$: xếp loại Giỏi (`GIOI`)
- $6.5 \le$ Điểm tổng kết $< 8$: xếp loại Khá (`KHA`)
- $5 \le$ Điểm tổng kết $< 6.5$: xếp loại Trung bình (`TRUNG BINH`)
- Điểm tổng kết $< 5$: xếp loại Yếu (`YEU`)

### Input
- Một dòng chứa 4 số điểm của học sinh (đều là số thực).

### Output
- Kết quả học tập môn Tin học dưới dạng chữ in hoa không dấu (`GIOI`, `KHA`, `TRUNG BINH`, `YEU`).

### Ví dụ
| Input | Output |
| :--- | :--- |
| `9 8 7 8.5` | `GIOI` |
| `5 7 6.5 5` | `TRUNG BINH` |

### Code 
```c++
                #include <iostream>
                #include <iomanip>
                using namespace std;
                int main(){
                    double d1, d2, d3, d4;
                    cin >> d1 >> d2 >> d3 >> d4;
                    double gpa = (d1 + d2 + 2 * d3 + 3 * d4) / 7;
                    if (gpa >= 8){
                        cout << "GIOI" << endl;
                    } else if (gpa >= 6.5){
                        cout << "KHA" << endl;
                    } else if (gpa >= 5){
                        cout << "TRUNG BINH" << endl;
                    } else {
                        cout << "YEU" << endl;
                    }
                    return 0;
                }
```

------

## Bài 31 : Số nhỏ thứ 2

### Yêu cầu
Cho 5 số nguyên $a, b, c, d, e$ 64-bit đôi một khác nhau. In ra số nhỏ thứ nhì.

### Input
- Một dòng gồm 5 số nguyên $a, b, c, d, e$.

### Output
- In ra số nhỏ thứ nhì.

### Ví dụ
| Input | Output |
| :--- | :--- |
| `1 2 3 4 5` | `2` |

### Code 
```c++
                #include <iostream>
                #include <algorithm>
                #include <vector>
                using namespace std;
                int main(){
                    vector<long long> a(5);
                    for (int i = 0; i < 5; i++){
                        cin >> a[i];
                    }
                    sort(a.begin(), a.end());
                    cout << a[1] << endl;
                    return 0;
                }
```
