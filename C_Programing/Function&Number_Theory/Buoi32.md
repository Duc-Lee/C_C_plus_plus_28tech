**Bài 14. Thuận nghịch và có 3 ước số nguyên tố.**

Một số được coi là đẹp nếu nó là số thuận nghịch và có ít nhất 3 ước số nguyên tố khác nhau. Viết chương trình in ra các số đẹp như vậy trong một đoạn giữa hai số nguyên cho trước.

**Input**

Dòng duy nhất là 2 số nguyên dương a, b (1≤a≤b≤10⁹).

**Output**

In ra các số đẹp trong đoạn từ a tới b. Trong trường hợp không tồn tại số đẹp trong đoạn từ a tới b thì in ra -1.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 1 1000 | 66 222 252 282 414 434 444 474 494<br>525 555 585 595 606 616 636 646 666<br>696 777 828 858 868 888 969 |

**Code**
```cpp
                #include <stdio.h>

                int thuan_nghich(int n){
                    int rev = 0, m = n;
                    while( n != 0){
                        rev = rev*10 + n%10;
                        n /= 10;
                    }
                    return rev == m;
                }

                // ham kiem tra 3 uoc so nguyen to
                int prime_check(int n){
                    // bien dem uoc so nguyen to khac nhau 
                    int cnt = 0;
                    for(int i = 2; i <= sqrt(n); i++){
                        // dem so lan xuat hien cua i trong n
                        int ans = 0;
                        while( n % i == 0){
                            ++ans;
                            // giam het uoc cua i di 
                            n /= i;
                        }
                        if(ans != 0) ++cnt;
                    }
                    // neu sau khi dem ma n van lon hon 1 => la 1 so nguyen to 
                    if( n > 1) ++cnt;
                    // tra ve uoc lon hon 3
                    return cnt >= 3;
                }
                int main(){
                    int a, b;
                    scanf("%d %d", &a, &b);
                    for(int i = a; i <= b; i++){
                        if(thuan_nghich(i) && prime_check(i)){
                            printf("%d ", i);
                        }
                    }
                    return 0;
                }
```
