**Bài 21. Thuận nghịch và không chứa số 9.**

Viết chương trình C cho phép nhập vào số N, thực hiện liệt kê các số thuận nghịch lớn hơn 1 và nhỏ hơn N thỏa mãn không chứa chữ số 9. Có bao nhiêu số như vậy.

**Input**

Số nguyên dương N.

**Output**

- Dòng 1: In ra các số thỏa mãn, mỗi số cách nhau một khoảng trắng.
- Dòng 2: In ra số lượng các số thỏa mãn.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 100 | 2 3 4 5 6 7 8 11 22 33 44 55 66 77 88<br>15 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                int thuan_nghich(int n){
                    int rev = 0, m = n;
                    while(n != 0){
                        int r = n % 10;
                        if(r == 9) return 0;
                        // dao nguoc lai so n 
                        rev = rev*10 + r;
                        n /= 10;
                    }
                    return (rev == m);
                }
                
                int main(){
                    int n;
                    scanf("%d", &n);
                    // khoi tao bien count de dem so luong
                    int count = 0;
                    // duyet tu 2 den so nho hon n
                    for(int i = 2; i < n; i++){
                        // neu la so thuan nghich thoa man
                        if(thuan_nghich(i)){
                            printf("%d ", i);
                            count++;
                        }
                    }
                    printf("\n%d", count);
                    return 0;
                }
```

---

# **Bài 22. Chữ số cuối cùng lớn nhất.**

Viết chương trình C cho phép nhập vào n và liệt kê các số nguyên tố thỏa mãn nhỏ hơn n và có chữ số cuối cùng lớn nhất. Có bao nhiêu số như vậy.

**Input**

Số nguyên dương n.

**Output**

- Dòng 1: In ra các số nguyên tố thỏa mãn, mỗi số cách nhau một khoảng trắng.
- Dòng 2: In ra số lượng các số tìm được.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 200 | 2 3 5 7 11 13 17 19 23 29 37 47 59 67 79 89 101 103 107 109 113 127 137 139 149 157 167 179 199<br>29 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                // khoi tao ham check so nguyen to 
                int prime(int n){
                    for(int i  = 2; i <= sqrt(n);i++){
                        if( n % i == 0) return 0;
                    }
                    return n > 1;
                }
                // khoi tao ham check so lon nhat cuoi cung
                int check(int n){
                    int r = n % 10;
                    while( n != 0){
                        // so sau lon hon so cuoi cung
                        if( n%10 > r) return 0;
                        n /=10;
                    }
                    return 1;
                }
                int main(){
                    int n;
                    scanf("%d",&n);
                    int cnt = 0;
                    for(int i = 2; i < n;i++){
                        if(check(i) && prime(i)){
                            ++cnt;
                            prinf("%d ",i);
                        }
                    }
                    printf("\n%d",cnt);
                }
```
