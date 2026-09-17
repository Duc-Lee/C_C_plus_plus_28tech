**Bài 17. Số Lộc phát.**

Một số được gọi là “lộc phát” nếu chỉ có các chữ số 0,6,8. Nhập vào một số nguyên dương không quá 9 chữ số, hãy kiểm tra xem đó có phải số lộc phát hay không. Nếu đúng in ra 1, sai in ra 0.

**Input**

Một số nguyên dương không quá 9 chữ số.

**Output**

Nếu đúng in ra 1, sai in ra 0.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 6808 | 1 |
| 16808 | 0 |

**Code**
```cpp
                #include <stdio.h>

                // so loc phat la so chi co 0,6,8
                int check(int n){
                    int rev = 0;
                    while( n != 0){
                        rev = n % 10;
                        // neu n khong phai so loc phat
                        if(rev != 0 && rev != 6 && rev != 8){
                            return 0;
                        }
                        n /= 10;
                    }
                    return 1;
                }

                int main(){
                    int n;
                    scanf("%d", &n);
                    if(check(n)){
                        printf("1\n");
                    }else{
                        printf("0\n");
                    }
                    return 0;   
                }
```

---

# **Bài 18. Thuận nghịch và lộc phát.**

Một số được coi là số đẹp nếu nó là số thuận nghịch, có chứa ít nhất một chữ số 6, và tổng các chữ số của nó có chữ số cuối cùng là 8. Viết chương trình liệt kê trong một đoạn giữa hai số nguyên cho trước các số đẹp như vậy.

**Input**

2 số nguyên dương a, b.

**Output**

In ra các số đẹp trong đoạn [a, b], mỗi số cách nhau một dấu cách.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 1 500 | 161 |

**Code**
```cpp
                #include <stdio.h>

                int sodep(int n){
                    int rev = 0, m = n;
                    // khoi tao bien tong va bien dem
                    int sum = 0, cnt = 0;
                    while( n != 0){
                        // tach chu so 
                        int r = n % 10;
                        if( r == 6) ++cnt;
                        // tinh so dao nguoc
                        rev = rev * 10 + n % 10;
                        // tinh tong chu so 
                        sum += n % 10;
                        n /= 10;
                    }
                    // kiem tra xem tong chu so so cuoi la 8 ko
                    return rev == m && sum % 10 == 8 && cnt >= 1;
                }

                int main(){
                    int a, b;
                    scanf("%d %d", &a, &b);
                    // lap tu a den b
                    for(int i = a; i <= b; ++i){
                        if(sodep(i)){
                            printf("%d ", i);
                        }
                    }
                    return 0;  
                }
```
